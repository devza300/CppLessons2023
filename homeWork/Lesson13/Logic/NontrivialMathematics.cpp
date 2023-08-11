#include "NontrivialMathematics.h"

#include <QJSEngine>

NontrivialMathematics::NontrivialMathematics()
{

}

QString NontrivialMathematics::evaluate(const QString &expression)
{
    QJSEngine engine;
    QJSValue result = engine.evaluate(expression);

    if (result.isError())
    {
        switch (result.errorType())
        {
        case QJSValue::SyntaxError:
            throw runtime_error();

        case QJSValue::ReferenceError:
            throw logic_error();

        default:
            break;
        }
    }

    // еще много вычислений

    return result.toString();
}
