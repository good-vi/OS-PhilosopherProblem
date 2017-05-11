#ifndef CANTEEN_H
#define CANTEEN_H

#include <QObject>
#include <vector>
#include <memory>
#include "philosopher.h"
#include "philosopherMonitor.h"

using std::shared_ptr;
using std::unique_ptr;
using std::vector;

//Simple "Adapter" class
class Canteen : public QObject
{
    Q_OBJECT
public:
    Canteen(unsigned numOfPhilosophers, unsigned long eatingTime_sec,
            unsigned long thinkingTime_sec, QObject* parent = nullptr);
    ~Canteen();
public slots:
    void setForkStatus(unsigned forkId, bool newForkStatus);
    void stopAllPhilosophers ();
    void startAllPhilosophers();
signals:
    void philosopherEating  (unsigned id);
    void philosopherThinking(unsigned id);
    void forkStatusChanged(unsigned forkId, bool forkStatus);
private:
    shared_ptr<PhilosopherMonitor> waiter;
    vector<unique_ptr<Philosopher>> philosophers;
    unsigned numOfPhilosophers_;
};

#endif // CANTEEN_H
