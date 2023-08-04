#include "Wheel.h"

Wheel::Wheel() :
    AbstractMechanism(MechanismType::Wheel)
{

}

std::vector<RoboTask::TaskType> Wheel::getSkills()
{
    return {RoboTask::MoveTo};
}
