#ifndef PHILOSOPHER_H
#define PHILOSOPHER_H
#include <QObject>
#include "fork.h"

class Philosopher : public QObject
{
    Q_OBJECT
public:
    Philosopher(QObject* parent = nullptr);
};

#endif // PHILOSOPHER_H
