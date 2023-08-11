#include "RandomPainter.h"

RandomPainter::RandomPainter()
{

}

void RandomPainter::draw()
{
    foreach (auto painter, mm_painterMap.values())
        painter();
}

void RandomPainter::appendPainter(int id, std::function<void ()> painter)
{
    mm_painterMap.insert(id, painter);
}

void RandomPainter::removePainter(int id)
{
    mm_painterMap.remove(id);
}
