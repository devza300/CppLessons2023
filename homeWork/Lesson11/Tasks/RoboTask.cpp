#include "RoboTask.h"

RoboTask::RoboTask(TaskType type) :
    mm_type(type)
{

}

RoboTask::TaskType RoboTask::getType() const
{
    return mm_type;
}
