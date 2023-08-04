#ifndef CLICONFIGLOADER_H
#define CLICONFIGLOADER_H

#include "AbstractConfigLoader.h"

/*!
 * \brief The CliConfigLoader class - получение конфигурации запуска из диалога с пользователем
 */
class CliConfigLoader : public AbstractConfigLoader
{
public:
    /*!
     * \brief CliConfigLoader - конструктор класса
     */
    CliConfigLoader();

    /*!
     * \brief loadConfig - загрузить конфигурацию
     */
    virtual void loadConfig() override;

private:
    bool setName();
    bool setCoordinate();
    bool setSpeed();
    bool setMechanisms();
    bool setTasks();

};

#endif // CLICONFIGLOADER_H
