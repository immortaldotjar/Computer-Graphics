#include <stdio.h>
#include <graphics.h>
#include <conio.h>

void main() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2, x3, y3, midx, midy;

    printf("Enter coordinates of triangle: ");
    scanf("%d %d", &x1, &y1);
    printf("Enter coordinates of triangle: ");
    scanf("%d %d", &x2, &y2);
    printf("Enter coordinates of triangle: ");
    scanf("%d %d", &x3, &y3);

    initgraph(&gd, &gm, "C:\\turboc3\\bgi");
    midx = getmaxx() / 2;
    midy = getmaxy() / 2;

    line(midx, 0, midx, getmaxy());
    line(0, midy, getmaxx(), midy);

    line(midx + x1, midy - y1, midx + x2, midy - y2);
    line(midx + x2, midy - y2, midx + x3, midy - y3);
    line(midx + x3, midy - y3, midx + x1, midy - y1);
    //REFLECTION
    line(midx + x1, midy + y1, midx + x2, midy + y2);
    line(midx + x2, midy + y2, midx + x3, midy + y3);
    line(midx + x3, midy + y3, midx + x1, midy + y1);

    getch();
    closegraph();
}