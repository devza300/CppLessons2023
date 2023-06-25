#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>

/*!
 * \brief isFileExist - проверка существования файла
 * \param path - путь к файлу
 * \return  - результат проверки
 */
bool isFileExist(const std::string &path);

/*!
 * \brief generateImage - создать файл изображения
 * \param path - путь к файлу
 */
void generateImage(const std::string &path);

/*!
 * \brief generateMask - создать маску
 * \param path - путь к файлу
 * \param pro_mode - признак работы с упрощенной записью маски
 */
void generateMask(const std::string &path, bool pro_mode);

/*!
 * \brief calculateOutFile - произвести обработку изображения
 * \param image - путь к файлу изображения
 * \param mask - путь к файлу маски
 * \param out - путь для сохранения результата обработки
 * \param pro_mode - признак работы с упрощенной записью маски
 */
void calculateOutFile(const std::string &image, const std::string &mask, const std::string &out, bool pro_mode);

/*!
 * \brief printFile - отобразить содержимое файла
 * \param section - название секции (изображение, маска или резуьтат) - заголовок вывода
 * \param path - путь к файлу
 */
void printFile(const std::string &section, const std::string &path);

#endif // FILEMANAGER_H
