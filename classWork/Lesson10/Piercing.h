#ifndef PIERCING_H
#define PIERCING_H

#include "Unit.h"

class Piercing
{
public:
    Piercing(int damage);

    void pierce(Unit &unit);

private:
    int m_damage;

};

#endif // PIERCING_H
