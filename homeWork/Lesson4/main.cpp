#include <iostream>

#include "ArgsParser.h"
#include "FileManager.h"

using namespace std;

/*!
 * \brief printHelpPage - вызов инструкции пользования утилитой
 * \param error - сообщение ошибки
 */
void printHelpPage(string error = "")
{
    if (!error.empty())
    {
        cout << error << std::endl;
        cout << std::endl;
    }

    cout << "Hello! You are run the Homework Lesson4 console application!" << endl;
    cout << endl;
    cout << "Usage:" << endl;
    cout << "-h, --help                     print this help page" << endl;
    cout << "-g, --generate                 generate new image and mask files" << endl;
    cout << "-p, --print                    print image, mask set and out file" << endl;
    cout << "-i, --image    [img_file]      image file path" << endl;
    cout << "-m, --mask     [msk_file]      mask file path" << endl;
    cout << "-o, --out      [out_file]      out file path" << endl;
    cout << endl;
    cout << "--pro-mode                     mask file must be written in decimal mode" << endl;
}

int main(int argc, char *argv[])
{
    // вызвана справочная информация
    if (cmdOptionExists(argv, argv + argc, "-h") || cmdOptionExists(argv, argv + argc, "--help"))
    {
        printHelpPage();
        return 0;
    }

    // файл исходного изображения
    char *image = getField(argc, argv, {"-i", "--image"});
    if (!image)
    {
        printHelpPage("Error: image file path is not set!");
        return 1;
    }

    // файл маски
    char *mask = getField(argc, argv, {"-m", "--mask"});
    if (!mask)
    {
        printHelpPage("Error: mask file path is not set!");
        return 1;
    }

    // файл-результат
    char *out = getField(argc, argv, {"-o", "--out"});
    if (!out)
    {
        printHelpPage("Error: out file path is not set!");
        return 1;
    }

    // признак работы с десятичной записью файла-маски
    bool pro_mode = cmdOptionExists(argv, argv + argc, "--pro-mode");

    // исходные файлы изображения и маски должны быть сгенерированны перед использованием
    if (cmdOptionExists(argv, argv + argc, "-g") || cmdOptionExists(argv, argv + argc, "--generate"))
    {
        generateImage(image);
        generateMask(mask, pro_mode);
    }

    // проверка существования файла изображения
    if (!isFileExist(image))
    {
        cout << "Image file <" << image << "> is not exist!" << std::endl;
        return 1;
    }

    // проверка существования файла маски
    if (!isFileExist(mask))
    {
        cout << "Mask file <" << mask << "> is not exist!" << std::endl;
        return 1;
    }

    // выполнение преобразований
    calculateOutFile(image, mask, out, pro_mode);

    // должен осуществляться выводисходных данных и результата на экран
    if (cmdOptionExists(argv, argv + argc, "-p") || cmdOptionExists(argv, argv + argc, "--print"))
    {
        printFile("IMAGE", image);
        printFile("MASK", mask);
        printFile("OUT", out);
    }

    return 0;
}
