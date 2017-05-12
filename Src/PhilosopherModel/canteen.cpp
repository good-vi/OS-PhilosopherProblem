#include "canteen.h"

Canteen::Canteen(unsigned numOfPhilosophers, unsigned long eatingTime_sec, unsigned long thinkingTime_sec, QObject *parent) :
    QObject(parent), numOfPhilosophers_(numOfPhilosophers)
{
    waiter = std::make_shared<PhilosopherMonitor>(numOfPhilosophers_, this);
    connect(waiter.get(), SIGNAL(forkStatusChanged(uint,bool)), this, SIGNAL(forkStatusChanged(uint,bool)));

    for (unsigned i = 0; i < numOfPhilosophers_; ++i){
        philosophers.push_back(std::make_unique<Philosopher>(waiter, i, eatingTime_sec, thinkingTime_sec, this));

        unique_ptr<Philosopher> lol;

        connect(philosophers[i].get(), SIGNAL(eating(unsigned /* id */)), this, SIGNAL(philosopherEating(unsigned /* id */)));
        connect(philosophers[i].get(), SIGNAL(thinking(unsigned /* id */)), this, SIGNAL(philosopherThinking(unsigned /* id */)));
    }
}

Canteen::~Canteen()
{
}

void Canteen::setForkStatus(unsigned forkId, bool newForkStatus)
{
    waiter->setForkStatus(forkId, newForkStatus);
}

void Canteen::stopAllPhilosophers()
{
    for (unsigned i = 0; i < numOfPhilosophers_; ++i){
        philosophers[i]->quit();
    }
}

void Canteen::startAllPhilosophers()
{
    for (unsigned i = 0; i < numOfPhilosophers_; ++i){
        philosophers[i]->start();
    }
}
