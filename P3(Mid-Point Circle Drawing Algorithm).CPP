#include <stdio.h>
#include <graphics.h>
#include <conio.h>
void plotPoints(int x2, int y2, int x, int y);
void drawCircle(int x1, int y1, int r) {
    int x = 0, y = r;
    int p = 1 - r;

    plotPoints(x1, y1, x, y);

    while (x < y) {
        x++;
        if (p < 0) {
            p = p + 2 * x + 1;
        } else {
            y--;
            p = p + 2 * (x - y) + 1;
        }
        plotPoints(x1, y1, x, y);
    }
}
void plotPoints(int x2, int y2, int x, int y) {
    putpixel(x2 + x, y2 + y, WHITE);
    putpixel(x2 - x, y2 + y, WHITE);
    putpixel(x2 + x, y2 - y, WHITE);
    putpixel(x2 - x, y2 - y, WHITE);
    putpixel(x2 + y, y2 + x, WHITE);
    putpixel(x2 - y, y2 + x, WHITE);
    putpixel(x2 + y, y2 - x, WHITE);
    putpixel(x2 - y, y2 - x, WHITE);
}
int main() {
    int gd = DETECT, gm, x, y, r;

    printf("Enter Midpoints: ");
    scanf("%d %d", &x, &y);
    printf("Enter Radius: ");
    scanf("%d", &r);

    initgraph(&gd, &gm, "C:\\turboc3\\bgi");
    drawCircle(x, y, r);

    getch();
    closegraph();
    return 0;
}