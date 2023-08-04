#include "AbstractMechanism.h"

AbstractMechanism::AbstractMechanism(MechanismType type) :
    mm_type(type)
{

}

AbstractMechanism::MechanismType AbstractMechanism::getType() const
{
    return mm_type;
}
