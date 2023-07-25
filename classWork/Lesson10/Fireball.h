#ifndef FIREBALL_H
#define FIREBALL_H

#include "Explosion.h"
#include "Skill.h"
#include "DamageOverTime.h"

class Fireball : public Skill, public DamageOverTime, public Explosion
{
public:
    Fireball();

protected:
    void privateCast(Unit &unit);

};

#endif // FIREBALL_H
