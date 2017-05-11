#ifndef PHILOSOPHERMONITOR_H
#define PHILOSOPHERMONITOR_H

#include <QObject>
#include <QWaitCondition>
#include <QMutex>
#include <memory>
#include <vector>

using std::unique_ptr;

class PhilosopherMonitor : public QObject
{
    Q_OBJECT
public:
    explicit PhilosopherMonitor(unsigned numberOfPhilosophers, QObject* parent = nullptr);
    void getTwoForks(unsigned philosopherId);
    void putTwoForks(unsigned philosopherId);
    void setForkStatus(unsigned forkId, bool newForkStatus);
signals:
    void forkStatusChanged(unsigned forkId, bool forkStatus);
private:
    const unsigned numberOfPhilosophers_;
    std::vector<unique_ptr<QWaitCondition>> philosophersCondition;

    QMutex forksMutex;
    std::vector<bool> forks;
};

#endif // PHILOSOPHERMONITOR_H
