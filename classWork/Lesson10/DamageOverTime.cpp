#include "DamageOverTime.h"

DamageOverTime::DamageOverTime(int damage, int ttl) :
    m_damage(damage),
    m_timeToLive(ttl)
{

}

void DamageOverTime::applyDot(Unit &unit)
{
    std::string effect = "dot " + std::to_string(m_damage) +
                         " for " + std::to_string(m_timeToLive) + " sec";
    unit.applyEffect(effect);
}
