#include "DartPoison.h"

DartPoison::DartPoison() :
    DamageOverTime(25, 30),
    Piercing(150)
{

}

void DartPoison::privateCast(Unit &unit)
{
//    unit.applyEffect("poison");
    applyDot(unit);

//    unit.applyEffect("piercing damage");
    pierce(unit);
}
