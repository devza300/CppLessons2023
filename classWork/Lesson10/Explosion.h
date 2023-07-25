#ifndef EXPLOSION_H
#define EXPLOSION_H

#include "Unit.h"

class Explosion
{
public:
    Explosion(int damage);

    void exploit(Unit &unit);

private:
    int m_damage;

};

#endif // EXPLOSION_H
