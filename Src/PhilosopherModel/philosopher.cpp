#include "philosopher.h"

Philosopher::Philosopher(shared_ptr<PhilosopherMonitor> waiter, unsigned id,
                         unsigned long eatingTime_sec, unsigned long thinkingTime_sec,
                         QObject *parent) :
    QThread(parent),
    waiter_(waiter),
    id_(id),
    eatingTime_sec_(eatingTime_sec),
    thinkingTime_sec_(thinkingTime_sec)
{}

void Philosopher::run()
{
    while(1){
        emit thinking(id_);
        this->sleep(thinkingTime_sec_);

        //Critical section
        waiter_->getTwoForks(id_);
        emit eating(id_);
        this->sleep(eatingTime_sec_);
        waiter_->putTwoForks(id_);
    }
}
