#ifndef RANDOMPAINTER_H
#define RANDOMPAINTER_H

#include <QWidget>
#include <QMap>

/*!
 * \brief The RandomPainter class - класс для применения массива фукций
 */
class RandomPainter
{
public:
    RandomPainter();

    /*!
     * \brief draw - запусть рисование
     */
    void draw();

    /*!
     * \brief appendPainter - добавить метод отрисовки
     * \param id - идентификатор метода
     * \param painter - метод
     */
    void appendPainter(int id, std::function<void ()> painter);

    /*!
     * \brief removePainter - удалить заданный метод отрисовки
     * \param id - идентиикатор метода
     */
    void removePainter(int id);

private:
    QMap<int, std::function<void ()>> mm_painterMap;    //!< список методов отрисовки с доступом по идентификаору

};

#endif // RANDOMPAINTER_H
