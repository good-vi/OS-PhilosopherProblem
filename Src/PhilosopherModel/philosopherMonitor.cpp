#include "philosopherMonitor.h"

#define EUCMOD(a, b)  (a < 0 ? (((a % b) + b) % b) : (a % b)) //cuse (-1 mod 5) = 4

PhilosopherMonitor::PhilosopherMonitor(unsigned numberOfPhilosophers, QObject *parent):
    QObject(parent), numberOfPhilosophers_(numberOfPhilosophers)
{
    for (unsigned i = 0; i < numberOfPhilosophers_; ++i){
        forks.push_back(0);
        philosophersCondition.push_back(std::make_unique<QWaitCondition>());
    }
}

void PhilosopherMonitor::getTwoForks(unsigned philosopherId)
{
    forksMutex.lock();

    unsigned leftForkId  = EUCMOD(int(philosopherId) - 1, numberOfPhilosophers_);
    unsigned rightForkId = philosopherId;

    while((forks.at(leftForkId) == 1) || (forks.at(rightForkId) == 1)){
        philosophersCondition[philosopherId]->wait(&forksMutex);
    }

    forks[leftForkId]  = 1;
    emit forkStatusChanged(leftForkId, 1);
    forks[rightForkId] = 1;
    emit forkStatusChanged(rightForkId, 1);
    forksMutex.unlock();
}

void PhilosopherMonitor::putTwoForks(unsigned philosopherId)
{
    unsigned leftPhilosopherId  = EUCMOD(int(philosopherId) - 1, numberOfPhilosophers_);
    unsigned rightPhilosopherId = (philosopherId + 1) % numberOfPhilosophers_;

    unsigned leftForkIdLeftPhilosopher = EUCMOD(int(philosopherId) - 1, numberOfPhilosophers_);
    unsigned leftForkId  = EUCMOD(int(philosopherId) - 1, numberOfPhilosophers_);
    unsigned rightForkId = philosopherId;
    unsigned rightForkIdRightPhilosopher = (philosopherId + 1) % numberOfPhilosophers_;

    forksMutex.lock();
    forks[leftForkId]  = 0;
    emit forkStatusChanged(leftForkId, 0);
    forks[rightForkId] = 0;
    emit forkStatusChanged(rightForkId, 0);

    //Try to unlock left neighbor
    if (forks[leftForkIdLeftPhilosopher] == 0){
        philosophersCondition[leftPhilosopherId]->wakeOne();
    }
    //Try to unlock right neighbor
    if (forks[rightForkIdRightPhilosopher] == 0){
        philosophersCondition[rightPhilosopherId]->wakeOne();
    }
    forksMutex.unlock();
}

void PhilosopherMonitor::setForkStatus(unsigned forkId, bool newForkStatus)
{
    forksMutex.lock();
    forks[forkId] = newForkStatus;
    emit forkStatusChanged(forkId, newForkStatus);
    forksMutex.unlock();
}
