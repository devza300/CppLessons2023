#include "FileConfigLoader.h"

#include <QSettings>
#include <QPoint>

#include "Tasks/RoboTaskMoveTo.h"
#include "Workshop/Joint.h"
#include "Workshop/Leverage.h"
#include "Workshop/OilPomp.h"
#include "Workshop/Wheel.h"

FileConfigLoader::FileConfigLoader(std::string path) :
    mm_path(path)
{

}

void FileConfigLoader::loadConfig()
{
    QSettings parser(QString::fromStdString(mm_path), QSettings::IniFormat);

    mm_name = parser.value("Name").toString().toStdString();
    mm_speed = parser.value("Speed").toInt();

    parser.beginGroup("Coordinate");
    mm_coordinate = {parser.value("X").toInt(),
                     parser.value("Y").toInt()};
    parser.endGroup();

    parser.beginGroup("Mechanisms");
    foreach (auto key, parser.childKeys())
    {
        int type = parser.value(key).toInt();
        std::shared_ptr<AbstractMechanism> mechanism;

        switch ((AbstractMechanism::MechanismType) type)
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
    }
    parser.endGroup();

    parser.beginGroup("Tasks");
    foreach (auto key, parser.childKeys())
    {
        int type = 0;
        if (parser.value(key).toList().count() == 0)
            type = parser.value(key).toInt();

        if (type == 0)
        {
            std::pair<int, int> coordinate = {parser.value(key).toList().value(1).toInt(),
                                              parser.value(key).toList().value(2).toInt()};
            auto task = std::make_shared<RoboTaskMoveTo>(coordinate);
            mm_tasks.push_back(task);
        }
        else
        {
            auto task = std::make_shared<RoboTask>((RoboTask::TaskType) type);
            mm_tasks.push_back(task);
        }
    }
    parser.endGroup();
}
