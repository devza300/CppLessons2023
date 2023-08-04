#include "RoboTaskMoveTo.h"

RoboTaskMoveTo::RoboTaskMoveTo(std::pair<int, int> coordinate) :
    RoboTask(TaskType::MoveTo),
    mm_coordinate(coordinate)
{

}

std::pair<int, int> RoboTaskMoveTo::getCoordinate() const
{
    return mm_coordinate;
}
