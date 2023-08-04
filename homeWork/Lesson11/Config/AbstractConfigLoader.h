#ifndef ABSTRACTCONFIGLOADER_H
#define ABSTRACTCONFIGLOADER_H

#include <string>
#include <vector>
#include <math.h>
#include <memory>

#include "Tasks/RoboTask.h"
#include "Workshop/AbstractMechanism.h"

/*!
 * \brief The AbstractConfigLoader class - чтение конфигурации запуска прграммы:
 * 1. имя робота
 * 2. начальные координаты робота
 * 3. состав робота
 * 4. скорость движения
 * 5. список выполняемых задач
 */
class AbstractConfigLoader
{
public:
    AbstractConfigLoader();
    virtual ~AbstractConfigLoader() = default;

    /*!
     * \brief loadConfig - загрузить конфигурацию
     */
    virtual void loadConfig() = 0;

    /*!
     * \brief getName - имя робота
     * \return - строка имени
     */
    std::string getName() const;

    /*!
     * \brief getCoordinate - начальные кординаты
     * \return - координата
     */
    std::pair<int, int> getCoordinate() const;

    /*!
     * \brief getSpeed - скорость движения
     * \return - скорость
     */
    int getSpeed() const;

    /*!
     * \brief getMechanisms - список механизмов робота
     * \return - механизмы
     */
    std::vector<std::shared_ptr<AbstractMechanism>> getMechanisms() const;

    /*!
     * \brief getTasks - список задач для исполнения
     * \return - список задач
     */
    std::vector<std::shared_ptr<RoboTask>> getTasks() const;

protected:
    std::string mm_name;                //!< имя робота
    std::pair<int, int> mm_coordinate;  //!< начальные кординаты
    int mm_speed;                       //!< скорость движения

    /*!
     * \brief mm_mechanisms - список доступных для робота механизмов
     */
    std::vector<std::shared_ptr<AbstractMechanism>> mm_mechanisms;

    /*!
     * \brief mm_tasks - список задач для исполнения
     */
    std::vector<std::shared_ptr<RoboTask>> mm_tasks;

};

#endif // ABSTRACTCONFIGLOADER_H
