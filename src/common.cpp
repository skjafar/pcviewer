#include "common.h"

#include <QtGlobal>
#include <QTime>

QColor getRandomColor()
{
    int h = qrand() % 360;
    int s = qrand() % 56 + 200;
    int l = qrand() % 56 + 100;
    return QColor::fromHsl(h, s, l);
}

QColor getSequentialColor(uint8_t index)
{
    const uint map[] = {0, 4, 2, 1, 7, 5, 3, 6};
    uint degree = map[index % 8] * (360 / 8);

    int h = degree;
    int s = 255 * 3 / (index / 8 + 3);
    int l = 120 * 3 / (index / 8 + 3);
    return QColor::fromHsl(h, s, l);
}
