#include "Leverage.h"

Leverage::Leverage() :
    AbstractMechanism(MechanismType::Leverage)
{

}

std::vector<RoboTask::TaskType> Leverage::getSkills()
{
    return {RoboTask::DropItem};
}

