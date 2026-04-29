#include <stdio.h>
#include <graphics.h>
#include <conio.h>

void main() {
    int x1 = 200, y1 = 100;
    int x2 = 100, y2 = 273;
    int x3 = 300, y3 = 273;
    int gd = DETECT, gm,ty,tx;

    initgraph(&gd, &gm, "C:\\turboc3\\bgi");
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);

    printf("Enter translation factors (tx ty): ");
    scanf("%d %d", &tx, &ty);
    cleardevice();

    // Translated triangle
    line(x1 + tx, y1 + ty, x2 + tx, y2 + ty);
    line(x2 + tx, y2 + ty, x3 + tx, y3 + ty);
    line(x3 + tx, y3 + ty, x1 + tx, y1 + ty);

    getch();
    closegraph();
}