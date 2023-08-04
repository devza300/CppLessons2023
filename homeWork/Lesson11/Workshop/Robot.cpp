#include "Robot.h"

#include <algorithm>
#include <iostream>
#include <map>
#include <math.h>
#include <thread>
#include <random>
#include <sstream>

#include "Tasks/RoboTaskMoveTo.h"

#define MSG(string) std::cout << "[" << mm_name << "]: " << string << std::endl

/*!
 * \brief TaskMap - карта типов задач с пояснениями
 */
std::map<RoboTask::TaskType, std::string> TaskMap = {
    {RoboTask::MoveTo, "MoveTo"},
    {RoboTask::GetSmth, "GetSmth"},
    {RoboTask::PutSmth, "PutSmth"},
    {RoboTask::OilShower, "OilShower"},
    {RoboTask::DropItem, "DropItem"}
};

/*!
 * \brief TaskMap - карта типов механизмов с пояснениями
 */
std::map<AbstractMechanism::MechanismType, std::string> MechanismMap = {
    {AbstractMechanism::Wheel, "MoveTo"},
    {AbstractMechanism::Joint, "Joint"},
    {AbstractMechanism::Leverage, "Leverage"},
    {AbstractMechanism::OilPomp, "OilPomp"}
};

/*!
 * \brief calculateDistance - вычисление расстояния между ткоординатами
 * \param point1 - координата 1
 * \param point2 - координата 2
 * \return - расстояние
 */
inline double calculateDistance(const std::pair<int, int> &point1, const std::pair<int, int> &point2)
{
    return sqrt(pow(point1.first - point2.first, 2) +
                pow(point1.second - point2.second, 2));
}

Robot::Robot(std::string name,
             std::pair<int, int> coordinate,
             int speed,
             std::vector<std::shared_ptr<AbstractMechanism>> mechanismVector) :
    mm_name(name),
    mm_coordinate(coordinate),
    mm_speed(speed),
    mm_smthCount(0),
    mm_mechanismVector(mechanismVector)
{
    MSG("Hi!");
}

void Robot::execute(std::shared_ptr<RoboTask> task)
{
    // полный список текущих возможостей робота
    std::vector<RoboTask::TaskType> skills;
    for (auto mechanism : mm_mechanismVector)
        for (auto taskType : mechanism->getSkills())
            skills.push_back(taskType);

    std::cout << std::endl;
    MSG("Start task <" + TaskMap.at(task->getType()) + ">");

    // признак наличия возможности обработать задачу
    bool isExecutable = std::find(skills.begin(), skills.end(), task->getType()) != skills.end();
    if (!isExecutable)
    {
        MSG("I can't complete the task <" + TaskMap.at(task->getType()) + ">");
        MSG("I don't have the necessary mechanism!");
        return;
    }

    switch (task->getType())
    {
    case RoboTask::MoveTo:
    {
        auto moveTo = dynamic_cast<RoboTaskMoveTo*>(task.get());

        MSG("Start. I'm at destination point <" + std::to_string(mm_coordinate.first)
            + ", " + std::to_string(mm_coordinate.second) + ">");

        auto destination = moveTo->getCoordinate();
        double distance = calculateDistance(mm_coordinate, destination);
        for (int a = 0; a < distance; a++)
        {
            MSG("makes a move...");
            std::this_thread::sleep_for(std::chrono::milliseconds(1000 / mm_speed));
        }

        mm_coordinate = destination;
        MSG("Finish. I'm at destination point <" + std::to_string(mm_coordinate.first)
            + ", " + std::to_string(mm_coordinate.second) + ">");
        break;
    }

    case RoboTask::GetSmth:
    {
        mm_smthCount++;
        MSG("Done. Smth count are <" + std::to_string(mm_smthCount) + ">");
        break;
    }

    case RoboTask::PutSmth:
    {
        if (mm_smthCount == 0)
        {
            MSG("Error. Nothing to put");
            break;
        }

        mm_smthCount--;
        MSG("Done. Smth count are <" + std::to_string(mm_smthCount) + ">");
        break;
    }

    case RoboTask::OilShower:
    {
        MSG("Done. Oil makes me stronger");
        break;
    }

    case RoboTask::DropItem:
    {
        std::random_device rd;
        std::mt19937 mt(rd());

        // потеря smth
        std::uniform_int_distribution<int> distDropSmth(0, 1);
        if (distDropSmth(mt) && mm_smthCount != 0)
        {
            mm_smthCount--;
            MSG("Drop smth...");
            MSG("Done. Smth count are <" + std::to_string(mm_smthCount) + ">");
            break;
        }

        // потеря механизма
        std::uniform_int_distribution<int> distDropMechanism(0, mm_mechanismVector.size() - 1);
        int dropIndex = distDropMechanism(mt);
        auto mechanism = mm_mechanismVector.at(dropIndex);

        MSG("Drop mechanism...");
        mm_mechanismVector.erase(std::next(mm_mechanismVector.begin(), dropIndex), std::next(mm_mechanismVector.begin(), dropIndex + 1));
        MSG("Done. Mechanism <" + MechanismMap.at(mechanism->getType()) + "> are dropped");
        break;
    }

    default:
        break;
    }
}
