#ifndef DIR2BIN_H
#define DIR2BIN_H

#include <QDir>
#include "Entry.h"
#include "dir2bin_global.h"

namespace DevZA300 {

/*!
 * \brief The dir2bin class - класс для преобразования содержимого каталога
 * к списку структур и наоборот
 */
class DIR2BIN_EXPORT dir2bin : public QObject
{
public:
    dir2bin() = delete;

    /*!
     * \brief toBin - получить содержимое каталога
     * \param dir - базовый каталог
     * \return - список структур объектов фаловой системы
     */
    static QList<Entry> toBin(const QString &dir);

    /*!
     * \brief toBin - сохранить содержимое каталога в файл
     * \param dir - базовый каталог
     * \param bin - файл для сохранения
     */
    static void toBin(const QString &dir, const QString &bin);

    /*!
     * \brief toBin - сохранить список структур объектов фаловой системы в файл
     * \param entries - список структур объектов фаловой системы
     * \param bin - файл для сохранения
     */
    static void toBin(const QList<Entry> &entries, const QString &bin);

    /*!
     * \brief toDir - записать данные в заданный каталог
     * \param entries - список структур объектов фаловой системы
     * \param dir - выходной каталог
     */
    static void toDir(const QList<Entry> &entries, const QString &dir);

    /*!
     * \brief toDir - записать данные в заданный каталог
     * \param bin - бинарный файл
     * \param dir - выходной каталог
     */
    static void toDir(const QString &bin, const QString &dir);

};

} // namespace DevZA300

#endif // DIR2BIN_H
