#include <stdio.h>
#include <graphics.h>
#include <math.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm, x1 = 200, y1 = 100, x2 = 100, y2 = 273, x3 = 300, y3 = 273;
    double s, c, angle;
    initgraph(&gd, &gm, "C:\\turboc3\\bgi");

    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
    getch();

    printf("Enter Rotation angle: ");
    scanf("%lf", &angle);

    c = cos(angle * M_PI / 180);
    s = sin(angle * M_PI / 180);

    x1 = floor(x1 * c + y1 * s);
    y1 = floor(-x1 * s + y1 * c);
    x2 = floor(x2 * c + y2 * s);
    y2 = floor(-x2 * s + y2 * c);
    x3 = floor(x3 * c + y3 * s);
    y3 = floor(-x3 * s + y3 * c);

    cleardevice();
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);

    getch();
    closegraph();
    return 0;
}