#ifndef ARGSPARSER_H
#define ARGSPARSER_H

#include <iostream>
#include <vector>

/*!
 * \brief getCmdOption - получение значения параметра агрумента запуска программы
 * \param argc - количество аргументов
 * \param argv - аргументы запуска
 * \param option - параметр, за которым считывается значение
 * \return - значение параметра
 */
char *getCmdOption(int argc, char *argv[], const std::string &option);

/*!
 * \brief cmdOptionExists - проверка наличия ключа запуска
 * \param argc - количество аргументов
 * \param argv - аргументы запуска
 * \param options - ключи запуска
 * \return - результат поиска ключа
 */
bool cmdOptionExists(int argc, char *argv[], const std::vector<std::string> &options);

/*!
 * \brief getField - значение поля аргумента
 * \param argc - количество аргументов
 * \param argv - аргументы запуска
 * \param options - ключи для поиска значения
 * \return - значение
 */
char *getField(int argc, char *argv[], const std::vector<std::string> &options);

#endif // ARGSPARSER_H
