#include "NewRace.h"

#include <vector>

using namespace std;

/*!
 * \brief getName - получение названия гонки
 * \param isNeedGoMenu - признак необходимости вернуться к главному меню
 * \return - название гонки
 */
string getName(bool &isNeedGoMenu)
{
    // CSI[2J clears screen, CSI[H moves the cursor to top-left corner
    std::cout << "\x1B[2J\x1B[H";

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

bool getLoop(vector<string> &loopVector)
{
    cout << "Put the loop time: ";

    float time;
    cin >> time;

    if (cin.fail())
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Input time is fail! Rrepeate, pls" << endl;

        return getLoop(loopVector);
    }

    cout << "Put the loop comment: ";

    string comment;
    cin >> comment;

    string result = to_string(time) + " " + comment;
    cout << "Check record: <" << result << "> is correct? (Y/N)" << endl;
    cout << "Is correct: ";

    string correct;
    cin >> correct;

    if (correct == "Y")
    {
        loopVector.push_back(result);
        return true;
    }

    return false;
}

std::string newRace(bool &isNeedSave)
{
    bool isNeedGoMenu = false;
    string name = getName(isNeedGoMenu);

    if (isNeedGoMenu)
    {
        isNeedSave = false;
        return "";
    }

    vector<string> loopVector;

    for (bool needContinue = getLoop(loopVector);
         needContinue;
         needContinue = getLoop(loopVector))
    {
        cout << "If all loops are completed, write <C>" << endl;
        cout << "To append second loop, write <A>" << endl;
        cout << "To return to start menu, write <B> (all loops will be lost)" << endl;

        string action;
        cin >> action;

        if (action == "C")
            break;

        if (action == "B")
        {
            isNeedSave = false;
            return "";
        }
    }

    isNeedSave = true;
    for (const auto &loop : loopVector)
        name += "\n\t" + loop;

    return name + "\n\n";
}
