#include "Fireball.h"

Fireball::Fireball() :
    DamageOverTime(50, 10),
    Explosion(99)
{

}

void Fireball::privateCast(Unit &unit)
{
//    unit.applyEffect("explosion");
    exploit(unit);

//    unit.applyEffect("burning");
    applyDot(unit);
}
