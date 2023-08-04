#include "Joint.h"

Joint::Joint() :
    AbstractMechanism(MechanismType::Joint)
{

}

std::vector<RoboTask::TaskType> Joint::getSkills()
{
    return {RoboTask::GetSmth, RoboTask::PutSmth};
}
