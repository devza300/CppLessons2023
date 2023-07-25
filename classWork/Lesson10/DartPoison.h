#ifndef DARTPOISON_H
#define DARTPOISON_H

#include "DamageOverTime.h"
#include "Piercing.h"
#include "Skill.h"

class DartPoison : public Skill, public DamageOverTime, public Piercing
{
public:
    DartPoison();

protected:
    void privateCast(Unit &unit);

};

#endif // DARTPOISON_H
