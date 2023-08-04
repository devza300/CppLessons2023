#ifndef ROBOT_H
#define ROBOT_H

#include <memory>
#include <string>
#include <math.h>
#include "AbstractMechanism.h"

/*!
 * \brief The Robot class - робот, содержит механизмы, может выполнять задачи
 */
class Robot
{
public:
    /*!
     * \brief Robot - конструктор класса
     * \param name - имя робота
     * \param coordinate - начальные координаты
     * \param speed - скорость движения
     * \param mechanismVector - механизмы
     */
    Robot(std::string name,
          std::pair<int, int> coordinate,
          int speed,
          std::vector<std::shared_ptr<AbstractMechanism>> mechanismVector);

    /*!
     * \brief execute - выполнить задачу
     * \param task - задача
     */
    void execute(std::shared_ptr<RoboTask> task);

private:
    std::string mm_name;                    //!< имя робота
    std::pair<int, int> mm_coordinate;      //!< текущие кординаты
    int mm_speed;                           //!< скорость движения
    int mm_smthCount;                       //!< число пдобранных штук

    /*!
     * \brief mm_mechanismVector - установленные механизмы
     */
    std::vector<std::shared_ptr<AbstractMechanism>> mm_mechanismVector;

};

#endif // ROBOT_H
