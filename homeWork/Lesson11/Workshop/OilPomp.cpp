#include "OilPomp.h"

OilPomp::OilPomp() :
    AbstractMechanism(MechanismType::OilPomp)
{

}

std::vector<RoboTask::TaskType> OilPomp::getSkills()
{
    return {RoboTask::OilShower};
}
