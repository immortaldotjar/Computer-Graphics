#include <stdio.h>
#include <graphics.h>
#include <conio.h>

// Regional codes
const int LEFT = 1, RIGHT = 2, BOTTOM = 4, TOP = 8;
int xmin, ymin, xmax, ymax;

int getCode(int x, int y)
{
	int code = 0;
	if (x < xmin)
		code |= LEFT;
	if (x > xmax)
		code |= RIGHT;
	if (y < ymin)
		code |= BOTTOM;
	if (y > ymax)
		code |= TOP;
	return code;
}

void main()
{
	int gd = DETECT, gm;
	int x1, y1, x2, y2;

	printf("Enter window coordinates xmin & ymin: ");
	scanf("%d %d", &xmin, &ymin);
	printf("Enter window coordinates xmax & ymax: ");
	scanf("%d %d", &xmax, &ymax);
	printf("Enter line coordinates x1 & y1: ");
	scanf("%d %d", &x1, &y1);
	printf("Enter line coordinates x2 & y2: ");
	scanf("%d %d", &x2, &y2);

	initgraph(&gd, &gm, "C:\\turboc3\\bgi");
	rectangle(xmin, ymin, xmax, ymax);
	line(x1, y1, x2, y2);
	getch();

	int c1 = getCode(x1, y1);
	int c2 = getCode(x2, y2);
	int accept = 0;

	while (1)
	{
		if (!(c1 | c2))
		{
			accept = 1;
			break;
		}
		else if (c1 & c2)
		{
			break;
		}
		else
		{
			int x, y, cOut;
			cOut = c1 ? c1 : c2;
			if (cOut & TOP)
			{
				x = x1 + (x2 - x1) * (ymax - y1) / (y2 - y1);
				y = ymax;
			}
			else if (cOut & BOTTOM)
			{
				x = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1);
				y = ymin;
			}
			else if (cOut & RIGHT)
			{
				y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1);
				x = xmax;
			}
			else
			{
				y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1);
				x = xmin;
			}
			if (cOut == c1)
			{
				x1 = x;
				y1 = y;
				c1 = getCode(x1, y1);
			}
			else
			{
				x2 = x;
				y2 = y;
				c2 = getCode(x2, y2);
			}
		}
	}

	cleardevice();
	rectangle(xmin, ymin, xmax, ymax);
	if (accept)
	{
		line(x1, y1, x2, y2);
	}
	getch();
	closegraph();
}