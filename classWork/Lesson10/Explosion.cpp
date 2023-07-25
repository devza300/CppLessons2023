#include "Explosion.h"

Explosion::Explosion(int damage) :
    m_damage(damage)
{

}

void Explosion::exploit(Unit &unit)
{
    unit.applyEffect("exploit " + std::to_string(m_damage));
}
