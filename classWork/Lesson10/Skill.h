#ifndef SKILL_H
#define SKILL_H

#include "Unit.h"

class Skill
{
public:
    Skill();

    void cast(Unit &unit);

protected:
    virtual void privateCast(Unit &unit) {};

private:
    int m_manaCoast;
    int m_castTime;
    int m_cooldown;

};

#endif // SKILL_H
