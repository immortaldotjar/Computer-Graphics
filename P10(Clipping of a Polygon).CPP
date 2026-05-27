#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

int i, j = 0, n;
int rx1, rx2, ry1, ry2;
float x1[32], y1[32];

void clip(float e, float f, float m) {
    int safety_counter = 0;
    while ((e < rx1 || e > rx2 || f < ry1 || f > ry2) && safety_counter < 2) {
        if (e < rx1) {
            f += m * (rx1 - e);
            e = rx1;
        } else if (e > rx2) {
            f += m * (rx2 - e);
            e = rx2;
        }
        if (f < ry1) {
            e += (ry1 - f) / m;
            f = ry1;
        } else if (f > ry2) {
            e += (ry2 - f) / m;
            f = ry2;
        }
        safety_counter++;
    }
    
    if (e >= rx1 && e <= rx2 && f >= ry1 && f <= ry2) {
        if (j > 0 && (x1[j - 1] == e && y1[j - 1] == f)) {
            return;
        }
        x1[j] = e;
        y1[j] = f;
        j++;
    }
}

void main() {
    int gd = DETECT, gm;
    float x[8], y[8], m;
    
    printf("Enter Coordinates for window: ");
    scanf("%d %d %d %d", &rx1, &ry1, &rx2, &ry2);

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter Coordinates for polygon :\n");
    for (i = 0; i < n; i++) {
        scanf("%f %f", &x[i], &y[i]);
    }
    
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI"); 
    
    rectangle(rx1, ry1, rx2, ry2);
    for (i = 0; i < n - 1; i++) {
        line(x[i], y[i], x[i + 1], y[i + 1]);
    }
    line(x[i], y[i], x[0], y[0]);
    getch();
    
    cleardevice();
    for (i = 0; i < n - 1; i++) {
        m = (x[i + 1] - x[i] != 0) ? (y[i + 1] - y[i]) / (x[i + 1] - x[i]) : 9999; 
        clip(x[i], y[i], m);
        clip(x[i + 1], y[i + 1], m);
    }
    m = (x[0] - x[i] != 0) ? (y[0] - y[i]) / (x[0] - x[i]) : 9999;
    clip(x[i], y[i], m);
    clip(x[0], y[0], m);
    
    rectangle(rx1, ry1, rx2, ry2);
    for (i = 0; i < j - 1; i++) {
        line(x1[i], y1[i], x1[i + 1], y1[i + 1]); 
    }
    if (j > 0) {
        line(x1[j - 1], y1[j - 1], x1[0], y1[0]);
    }
    
    getch();
    closegraph();
}
