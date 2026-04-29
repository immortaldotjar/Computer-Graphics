#include <stdio.h>
#include <graphics.h>
#include <conio.h>

int xmin, ymin, xmax, ymax;

void clip(int x1, int y1, int x2, int y2) {
    if(x1 < xmin) x1 = xmin;
    if(x1 > xmax) x1 = xmax;
    if(y1 < ymin) y1 = ymin;
    if(y1 > ymax) y1 = ymax;

    if(x2 < xmin) x2 = xmin;
    if(x2 > xmax) x2 = xmax;
    if(y2 < ymin) y2 = ymin;
    if(y2 > ymax) y2 = ymax;

    line(x1, y1, x2, y2);
}

void main() {
    int gd = DETECT, gm;
    int n, i, poly[20];

    printf("Enter window coordinates of xmin & ymin: ");
    scanf("%d %d", &xmin, &ymin);
    printf("Enter window coordinates of xmax & ymax: ");
    scanf("%d %d", &xmax, &ymax);
    printf("Enter number of vertices of polygon: ");
    scanf("%d", &n);

    printf("Enter coordinates x & y: ");
    for (i = 0; i < 2 * n; i++) {
        scanf("%d", &poly[i]);
    }
    poly[2 * n] = poly[0];
    poly[2 * n + 1] = poly[1];

    initgraph(&gd, &gm, "C:\\turboc3\\bgi");

    rectangle(xmin, ymin, xmax, ymax);
    drawpoly(n + 1, poly);
    getch();

    cleardevice();
    rectangle(xmin, ymin, xmax, ymax);
    
    for (i = 0; i < 2 * n; i += 2) {
        clip(poly[i], poly[i+1], poly[i+2], poly[i+3]);
    }

    getch();
    closegraph();
}