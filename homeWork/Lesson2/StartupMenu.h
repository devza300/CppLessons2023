#ifndef STARTUPMENU_H
#define STARTUPMENU_H

/*!
 * \brief The RunMode enum - режимы запуска программы
 */
enum RunMode : int
{
    /// новая гонка
    NewRace,

    /// просмотр сохраненных гонок
    History,

    /// очистка истории
    Clear,

    /// вызов меню
    PrintMenu,

    /// завершение работы
    Quit
};

/*!
 * \brief printMenu - вызов меню программы
 * \return - выбранный пользователем режим работы
 */
RunMode printMenu();

#endif // STARTUPMENU_H
