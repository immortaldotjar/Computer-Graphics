#include <conio.h>
#include <stdio.h>
#include <graphics.h>

void main()
{
    int gd = DETECT, gm, i;
    float x, y, dx, dy, s;
    int x1 = 100, x2 = 100, y1 = 400, y2 = 400;
    initgraph(&gd, &gm, "C:\\turboc3\\bgi");
    dx = (float)(x2 - x1);
    dy = (float)(y2 - y1);
    if (dx >= dy)
    {
        s = dx;
    }
    else
    {
        s = dy;
    }
    dx = dx / s;
    dy = dy / s;
    x = x1;
    y = y1;
    i = 1;
    while (i <= s)
    {
        putpixel(x, y, WHITE);
        putpixel(x + 1, y, WHITE);
        putpixel(x, y + 1, WHITE);
        putpixel(x + 1, y + 1, WHITE);
        x += dx;
        y += dy;
        i += 1;
    }
    getch();
    closegraph();
}