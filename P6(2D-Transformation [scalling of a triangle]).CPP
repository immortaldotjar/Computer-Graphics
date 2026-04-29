#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void draw(int x, int y, int x1, int y1, int x2, int y2) {
    line(x, y, x1, y1);
    line(x1, y1, x2, y2);
    line(x2, y2, x, y);
}

void scale(int x, int y, int x1, int y1, int x2, int y2) {
    float sx, sy;
    int mx, my;
    int a, b, a1, b1, a2, b2;

    printf("Enter scaling factor : ");
    scanf("%f %f", &sx, &sy);
    mx = (x + x1 + x2) / 3;
    my = (y + y1 + y2) / 3;
    cleardevice(); 
    a = mx + (x - mx) * sx;
    b = my + (y - my) * sy;
    a1 = mx + (x1 - mx) * sx;
    b1 = my + (y1 - my) * sy;
    a2 = mx + (x2 - mx) * sx;
    b2 = my + (y2 - my) * sy;
    draw(a, b, a1, b1, a2, b2);
}

void main() {
    int x = 200, y = 100;
    int x1 = 100, y1 = 273;
    int x2 = 300, y2 = 273;
    int gd = DETECT, gm;

    initgraph(&gd, &gm, "C:\\turboc3\\bgi");
    draw(x, y, x1, y1, x2, y2);
    scale(x, y, x1, y1, x2, y2);
    getch();
    closegraph();
}