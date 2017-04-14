#ifndef PHILOSOPHER_H
#define PHILOSOPHER_H
#include <QThread>

class Philosopher : public QThread
{
public:
    Philosopher();
};

#endif // PHILOSOPHER_H
