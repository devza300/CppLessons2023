#ifndef HEAVYOPERATIONSVECTORTEMPLATE_H
#define HEAVYOPERATIONSVECTORTEMPLATE_H

#include <functional>
#include <vector>

/*!
 * \brief The HeavyOperationsVectorTemplate class - шаблонный класс, демонстрирующий
 * работу с пользовательскими паттернами
 */
template <typename Object>
class HeavyOperationsVectorTemplate
{
public:
    /*!
     * \brief HeavyOperationsVectorTemplate - контсруктор класса
     * \param data - массив данных для инициализации
     */
    HeavyOperationsVectorTemplate(std::vector<Object> data) :
        mm_data(data)
    {

    };

    /*!
     * \brief transform - метод, анализирующий вектор поэлементно
     * \param xform - функция анализа
     * \return - список измененных данных
     */
    std::vector<Object> transform(std::function<Object (Object)> &xform)
    {
        return std::transform(mm_data.begin(), mm_data.end(), mm_data.begin(), xform);
    }

    /*!
     * \brief adjacent_find - метод, анализирующий вектор попарно
     * \param find - функция анаиза
     * \return - найденный элемент
     */
    Object adjacent_find(std::function<bool (Object, Object)> &find)
    {
        auto it = std::adjacent_find(mm_data.begin(), mm_data.end(), find);

        if (it == mm_data.end)
            return Object();

        return *it;
    }

protected:
    std::vector<Object> mm_data;    //!< массив данных

};

#endif // HEAVYOPERATIONSVECTORTEMPLATE_H
