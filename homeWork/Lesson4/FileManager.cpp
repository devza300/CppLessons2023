#include "FileManager.h"

#include <bitset>
#include <fstream>
#include <climits>
#include <iostream>
#include <random>
#include <sstream>

#define ROW_COUNT 8

bool isFileExist(const std::string &path)
{
    std::ifstream stream(path);
    return stream.good();
}

void generateImage(const std::string &path)
{
    std::ofstream stream(path);

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(0, 9);

    for (int i = 0; i < ROW_COUNT; ++i)
    {
        for (int b = 0; b < CHAR_BIT; b++)
            stream << dist(mt) << " ";

        stream << std::endl;
    }
}

void generateMask(const std::string &path, bool pro_mode)
{
    std::ofstream stream(path);

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(0, pro_mode ? 255 : 1);

    for (int i = 0; i < ROW_COUNT; ++i)
    {
        if (pro_mode)
        {
            stream << dist(mt) << std::endl;
            continue;
        }

        for (int b = 0; b < CHAR_BIT; b++)
            stream << dist(mt) << " ";

        stream << std::endl;
    }
}

void printFile(const std::string &section, const std::string &path)
{
    std::cout << section << std::endl;

    std::ifstream stream(path);
    std::cout << stream.rdbuf();

    std::cout << std::endl;
}

void calculateOutFile(const std::string &image, const std::string &mask, const std::string &out, bool pro_mode)
{
    std::ifstream stream_image(image);
    std::ifstream stream_mask(mask);

    // вывод результата
    std::ofstream stream_out(out);

    // чтение осуществляется на основании файла-маски, т.к. она в теории может быть меньше изображения
    for (std::string mask_string; std::getline(stream_mask, mask_string);)
    {
        // строка маски
        std::stringstream mask_stringstream;
        mask_stringstream << mask_string;

        // строка изображения
        std::string image_string;
        std::getline(stream_image, image_string);
        std::stringstream image_stringstream;
        image_stringstream << image_string;

        if (pro_mode)
        {
            int mask_value;
            mask_stringstream >> mask_value;

            for (int i = 1; i <= CHAR_BIT; ++i)
            {
                int image_value;
                image_stringstream >> image_value;

                std::bitset<CHAR_BIT> mask_as_set(mask_value);
                int offset = CHAR_BIT - i;
                std::bitset<CHAR_BIT> mask_by_offset(mask_value >> offset);

                // младший бит
                int mask_value_in_position = mask_by_offset[0];

                int out_value = image_value & (mask_value_in_position ? image_value : 0);
                stream_out << out_value << " ";
            }

            stream_out << std::endl;
            continue;
        }

        for (int i = 0; i < CHAR_BIT; ++i)
        {
            int mask_value;
            int image_value;
            mask_stringstream >> mask_value;
            image_stringstream >> image_value;

            // реализация напоминает ребят котрые изобретают вечный двигатель:
            // надо все делать максимально запутанно и непонятно,
            // чтобы физика не разобралась в чем подвох
            int out_value = image_value & (mask_value ? image_value : 0);

            // NOTE так красивее, но противоречит ТЗ
            // int out_value = image_value * mask_value;

            stream_out << out_value << " ";
        }

        stream_out << std::endl;
    }
}
