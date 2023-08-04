#ifndef EMULATOR_H
#define EMULATOR_H

#include "Config/AbstractConfigLoader.h"
#include "Workshop/Robot.h"

/*!
 * \brief The Emulator class - эмулятор запуска выполнения задач роботом
 */
class Emulator
{
public:
    /*!
     * \brief Emulator - конструктор класса
     * \param config - объект конфига
     */
    Emulator(AbstractConfigLoader *config);

    /// запуск
    void run();

private:
    /*!
     * \brief ptr_config - объект, предоставяюий конфигурацию запуска
     */
    AbstractConfigLoader *ptr_config;

    /*!
     * \brief ptr_robot - робот
     */
    std::shared_ptr<Robot> ptr_robot;

};

#endif // EMULATOR_H
