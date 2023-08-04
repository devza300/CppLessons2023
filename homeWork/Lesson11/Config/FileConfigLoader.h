#ifndef FILECONFIGLOADER_H
#define FILECONFIGLOADER_H

#include "AbstractConfigLoader.h"

/*!
 * \brief The FileConfigLoader class - загрузка конфигурации запуска из файла
 */
class FileConfigLoader : public AbstractConfigLoader
{
public:
    /*!
     * \brief FileConfigLoader - конструктор класса
     * \param path - файл конфигурации
     */
    FileConfigLoader(std::string path);

    /*!
     * \brief loadConfig - загрузить конфигурацию
     */
    virtual void loadConfig() override;

private:
    std::string mm_path;        //!< путь к файлу с конфигурацией запуска

};

#endif // FILECONFIGLOADER_H
