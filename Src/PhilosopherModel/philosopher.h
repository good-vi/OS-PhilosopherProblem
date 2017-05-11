#ifndef PHILOSOPHER_H
#define PHILOSOPHER_H
#include <QThread>
#include <memory>
#include "philosopherMonitor.h"

using std::shared_ptr;
class Philosopher : public QThread
{
    Q_OBJECT
public:
    explicit Philosopher(shared_ptr<PhilosopherMonitor> waiter, unsigned id,
                         unsigned long eatingTime_sec, unsigned long thinkingTime_sec,
                         QObject* parent = nullptr);
    virtual void run() override;
signals:
    void eating(unsigned /* id */);
    void thinking(unsigned /* id */);
private:
    const unsigned id_;
    unsigned long eatingTime_sec_;
    unsigned long thinkingTime_sec_;
    shared_ptr<PhilosopherMonitor> waiter_;
};

#endif // PHILOSOPHER_H
