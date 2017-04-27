#ifndef CANTEEN_H
#define CANTEEN_H

#include <QObject>
#include "philosopher.h"

class Canteen : public QObject
{
    Q_OBJECT
public:
    Canteen(QObject* parent = nullptr);
};

#endif // CANTEEN_H
