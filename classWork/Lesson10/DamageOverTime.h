#ifndef DAMAGEOVERTIME_H
#define DAMAGEOVERTIME_H

#include "Unit.h"

class DamageOverTime
{
public:
    DamageOverTime(int damage, int ttl);

    void applyDot(Unit &unit);

private:
    int m_damage;
    int m_timeToLive;

};

#endif // DAMAGEOVERTIME_H
