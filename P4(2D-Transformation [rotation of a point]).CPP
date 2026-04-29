#include <stdio.h>
#include <math.h>
#include <graphics.h>
#include <conio.h>
void rotate(int *x, int *y, float angle) {
    float rad = angle * (M_PI / 180.0);
    int xOld = *x;
    int yOld = *y;
    *x = xOld * cos(rad) - yOld * sin(rad);
    *y = xOld * sin(rad) + yOld * cos(rad);
}

void main() {
    int gd = DETECT, gm;
    int x = 100, y = 0;
    initgraph(&gd, &gm, "C:\\turboc3\\bgi");
    int centerX = getmaxx() / 2;
    int centerY = getmaxy() / 2;
    putpixel(centerX + x, centerY - y,7);
    getch();
    rotate(&x, &y, 45);
    putpixel(centerX + x,centerY - y,7);
    getch();
    closegraph();
}