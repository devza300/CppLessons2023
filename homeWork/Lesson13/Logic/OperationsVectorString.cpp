#include "OperationsVectorString.h"

#include <QRegularExpression>
#include <QDebug>

OperationsVectorString::OperationsVectorString(std::vector<std::string> data) :
    HeavyOperationsVectorTemplate(data)
{

}

int OperationsVectorString::findByAngryPattern(std::string pattern, std::vector<std::string> &resultVector)
{
    QRegularExpression re(QString::fromStdString(pattern));

    if (!re.isValid())
    {
        qWarning() << "called on an invalid pattern";
        return -1;
    }

    /*!
     * NOTE: лямбда-выраженеие, котророе возвращает количество строк в вектрое std::vector<std::string>,
     * по заданному пользователем паттерну
     */
    auto lambda = [&](auto item) {
        QRegularExpressionMatch match = re.match(QString::fromStdString(item));

        if (!match.hasMatch())
            return;

        resultVector.push_back(item);
    };

    std::for_each(mm_data.begin(), mm_data.end(), lambda);
    return resultVector.capacity();
}
