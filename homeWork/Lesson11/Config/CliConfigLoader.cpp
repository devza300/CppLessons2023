#include "CliConfigLoader.h"

#include <iostream>

#include "Workshop/Joint.h"
#include "Workshop/Leverage.h"
#include "Workshop/OilPomp.h"
#include "Workshop/Wheel.h"
#include "Tasks/RoboTask.h"
#include "Tasks/RoboTaskMoveTo.h"

using namespace std;

/*!
 * \brief getInt - получение ввода числа
 * \param message - диалог-предложение ко вводу
 * \param value - ссылка на переменную, в которую будет помещено число
 * \return - признак успешного завершения ввода
 */
inline bool getInt(string message, int &value)
{
    cout << message << endl;
    cin >> value;

    if (cin.fail())
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Error, input is not number!" << endl;

        return false;
    }

    return true;
};

CliConfigLoader::CliConfigLoader()
{

}

void CliConfigLoader::loadConfig()
{
    while (!setName());
    while (!setCoordinate());
    while (!setSpeed());
    while (!setMechanisms());
    while (!setTasks());
}

bool CliConfigLoader::setName()
{
    cout << endl;
    cout << "Set robot name:" << endl;

    string name;
    cin >> name;

    mm_name = name;

    return true;
}

bool CliConfigLoader::setCoordinate()
{
    cout << endl;
    cout << "Set initial coordinate:" << endl;

    int x = 0;
    bool result = getInt("Write X value:", x);
    if (!result)
        return false;

    int y = 0;
    result = getInt("Write Y value:", y);
    if (!result)
        return false;

    mm_coordinate = {x, y};
    return true;
}

bool CliConfigLoader::setSpeed()
{
    cout << endl;
    return getInt("Set robot speed:", mm_speed);
}

bool CliConfigLoader::setMechanisms()
{
    cout << endl;
    cout << "Configure mechanisms:" << endl;
    cout << "0" << "\t" << "Append Wheel" << endl;
    cout << "1" << "\t" << "Append Joint" << endl;
    cout << "2" << "\t" << "Append Leverage" << endl;
    cout << "3" << "\t" << "Append OilPomp" << endl;
    cout << endl;
    cout << "4" << "\t" << "Done, next step" << endl;
    cout << endl;

    int mode = 0;
    bool result = getInt("Write number:", mode);

    if (!result || mode < 0 || mode > 4)
        return setMechanisms();

    // done
    if (mode == 4)
        return true;

    std::shared_ptr<AbstractMechanism> mechanism;
    switch ((AbstractMechanism::MechanismType) mode)
    {
    case AbstractMechanism::Wheel:
        mechanism = std::make_shared<Wheel>();
        break;
    case AbstractMechanism::Joint:
        mechanism = std::make_shared<Joint>();
        break;
    case AbstractMechanism::Leverage:
        mechanism = std::make_shared<Leverage>();
        break;
    case AbstractMechanism::OilPomp:
        mechanism = std::make_shared<OilPomp>();
        break;
    }

    mm_mechanisms.push_back(mechanism);
    return setMechanisms();
}

bool CliConfigLoader::setTasks()
{
    cout << endl;
    cout << "Configure tasks:" << endl;
    cout << "0" << "\t" << "Append MoveTo" << endl;
    cout << "1" << "\t" << "Append GetSmth" << endl;
    cout << "2" << "\t" << "Append PutSmth" << endl;
    cout << "3" << "\t" << "Append OilShower" << endl;
    cout << "4" << "\t" << "Append DropItem" << endl;
    cout << endl;
    cout << "5" << "\t" << "Done, emulate" << endl;
    cout << endl;

    int mode = 0;
    bool result = getInt("Write number:", mode);

    if (!result || mode < 0 || mode > 5)
        return setTasks();

    // done
    if (mode == 5)
        return true;

    if (mode == 0)
    {
        int x = 0;
        bool result = getInt("Write destinaion X value:", x);
        if (!result)
            return false;

        int y = 0;
        result = getInt("Write destinaion Y value:", y);
        if (!result)
            return false;

        std::pair<int, int> coordinate = {x, y};
        auto task = std::make_shared<RoboTaskMoveTo>(coordinate);
        mm_tasks.push_back(task);
    }
    else
    {
        auto task = std::make_shared<RoboTask>((RoboTask::TaskType) mode);
        mm_tasks.push_back(task);
    }

    return setTasks();
}
