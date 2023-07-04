#include <iostream>
#include <memory>

using namespace std;


/*!
 * \brief getName - получение названия гонки
 * \param isNeedGoMenu - признак необходимости вернуться к главному меню
 * \return - название гонки
 */
string getName(bool &isNeedGoMenu)
{

    unique_ptr<int>;
    cout << "Put the race name: ";

    string name;
    cin >> name;

    cout << "Name <" << name << "> is correct? (Y/N/B)" << endl;
    cout << "To return to start menu, write <B>" << endl;
    cout << "Is correct: ";

    string correct;
    cin >> correct;

    if (correct == "Y")
    {
        isNeedGoMenu = false;
        return name;
    }

    if (correct == "B")
    {
        isNeedGoMenu = true;
        return "";
    }

    return getName(isNeedGoMenu);
}

int main()
{
    cout << "Hello World!" << endl;

    int a = 9;

    bool q;
    getName(q);

    return 0;
}
