#include "Piercing.h"

Piercing::Piercing(int damage) :
    m_damage(damage)
{

}

void Piercing::pierce(Unit &unit)
{
    unit.applyEffect("pirce " + std::to_string(m_damage));
    unit.applyEffect("IIPOTKHYT");
}
