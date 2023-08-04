#include "RoboTaskMoveTo.h"

RoboTaskMoveTo::RoboTaskMoveTo(Coordinate coordinate) :
    RoboTask(TaskType::MoveTo),
    mm_coordinate(coordinate)
{

}

Coordinate RoboTaskMoveTo::getCoordinate() const
{
    return mm_coordinate;
}
