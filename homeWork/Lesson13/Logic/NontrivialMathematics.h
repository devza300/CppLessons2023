#ifndef NONTRIVIALMATHEMATICS_H
#define NONTRIVIALMATHEMATICS_H

#include <QString>
#include <exception>
#include <stdexcept>

/*!
 * \brief The NontrivialMathematics class - класс предоставляющий доступ к сложным математическим операциям
 */
class NontrivialMathematics
{
public:
    NontrivialMathematics();

    /*!
     * \brief evaluate - вычислить значение выражения
     * \param expression - выражение
     * \return - результат
     */
    QString evaluate(const QString &expression);

    /*!
     * \brief The logic_error class - логическая ошибка
     */
    class logic_error : public std::logic_error {
    public:
        logic_error() : std::logic_error("NontrivialMathematics logic_error") { }
    };

    /*!
     * \brief The runtime_error class - ошибка выполнения
     */
    class runtime_error : public std::runtime_error {
    public:
        runtime_error() : std::runtime_error("NontrivialMathematics runtime_error") { }
    };

};

#endif // NONTRIVIALMATHEMATICS_H
