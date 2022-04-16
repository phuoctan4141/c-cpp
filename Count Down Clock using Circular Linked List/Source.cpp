#include <iostream>
#include <string>
#include <time.h>
#include <iomanip>
#include <stdlib.h>
#include <dos.h>
#include "graphics.h"

#pragma comment(lib, "graphics.lib")
using namespace std;

#define PI 3.14

struct Node
{
	int data;
	Node* Next;
	Node* Prev;
};

typedef Node *pNode, *List;

struct sClock
{
	List h; // gio
	List m; //phut
	List s; //giay
};

char* Itoa(char *s, int x)
{
	if (x >= 0 && x <= 9)
	{
		s[0] = 48;
		s[1] = 48 + x;
	}
	else
	{
		s[0] = 48 + x / 10;
		s[1] = 48 + x % 10;
	}

	s[2] = NULL;

	return s;
}

void CreateList(sClock &c)
{
	c.h = c.m = c.s = NULL;
}

pNode CreateNode(int x)
{
	pNode p = new Node;

	if (p == NULL)
		exit(1);

	p->data = x;  // tao node co gia tri x
	p->Next = NULL; //con tro toi node khac la NULL
	p->Prev = NULL;

	return p;
}

void Insend(List &l, pNode p)
{

	if (l == NULL)
	{
		l = p;
		p->Next = p;
		p->Prev = p;
	}
	else
	{
		p->Next = l->Next;
		p->Prev = l;
		l->Next->Prev = p;
		l->Next = p;
	}
	  
	l = p;
};

void AddTail(List &l, int x)
{
	pNode p = CreateNode(x);

	Insend(l, p);
}

pNode GetNode(pNode p, int x)
{

	while (p != NULL)
	{
		if (x == p->data)
			return p;
		p = p->Next;
	}

	return NULL;
}

// Cac ham thiet lap dong ho analog
int calculatehrs(int h)
{
	int x;
	switch (h)
	{
	case 0: x = 90;
		break;
	case 1:
	case 13: x = 60;
		break;
	case 2:
	case 14: x = 30;
		break;
	case 3:
	case 15: x = 0;
		break;
	case 4:
	case 16: x = 330;
		break;
	case 5:
	case 17: x = 300;
		break;
	case 6:
	case 18: x = 270;
		break;
	case 7:
	case 19: x = 240;
		break;
	case 8:
	case 20: x = 210;
		break;
	case 9:
	case 21: x = 180;
		break;
	case 10:
	case 22: x = 150;
		break;
	case 11:
	case 23: x = 120;
		break;
	case 12:
	case 24: x = 90;
		break;
	}
	return(x);
}

int calculatemin(int m)
{
	int x;
	if (m % 5 == 0)
	{
		switch (m)
		{
		case 0: x = 90;
			break;
		case 5: x = 60;
			break;
		case 10: x = 30;
			break;
		case 15: x = 360;
			break;
		case 20: x = 330;
			break;
		case 25: x = 300;
			break;
		case 30: x = 270;
			break;
		case 35: x = 240;
			break;
		case 40: x = 210;
			break;
		case 45: x = 180;
			break;
		case 50: x = 150;
			break;
		case 55: x = 120;
			break;
		case 60: x = 90;
			break;
		}
	}
	else
	{
		if (m>0 && m<15)
		{
			switch (m)
			{
			case 1: x = 84;
				break;
			case 2: x = 78;
				break;
			case 3: x = 72;
				break;
			case 4: x = 66;
				break;
			case 6: x = 54;
				break;
			case 7: x = 48;
				break;
			case 8: x = 42;
				break;
			case 9: x = 36;
				break;
			case 11: x = 24;
				break;
			case 12: x = 18;
				break;
			case 13: x = 12;
				break;
			case 14: x = 6;
				break;
			}
		}

		if (m>15 && m<30)
		{
			switch (m)
			{
			case 16: x = 354;
				break;
			case 17: x = 348;
				break;
			case 18: x = 342;
				break;
			case 19: x = 336;
				break;
			case 21: x = 324;
				break;
			case 22: x = 318;
				break;
			case 23: x = 312;
				break;
			case 24: x = 306;
				break;
			case 26: x = 294;
				break;
			case 27: x = 288;
				break;
			case 28: x = 282;
				break;
			case 29: x = 276;
				break;
			}
		}

		if (m>30 && m<45)
		{
			switch (m)
			{
			case 31: x = 264;
				break;
			case 32: x = 258;
				break;
			case 33: x = 252;
				break;
			case 34: x = 246;
				break;
			case 36: x = 234;
				break;
			case 37: x = 228;
				break;
			case 38: x = 222;
				break;
			case 39: x = 216;
				break;
			case 41: x = 204;
				break;
			case 42: x = 198;
				break;
			case 43: x = 192;
				break;
			case 44: x = 186;
				break;
			}
		}

		if (m>45 && m<60)
		{
			switch (m)
			{
			case 46: x = 174;
				break;
			case 47: x = 168;
				break;
			case 48: x = 162;
				break;
			case 49: x = 156;
				break;
			case 51: x = 144;
				break;
			case 52: x = 138;
				break;
			case 53: x = 132;
				break;
			case 54: x = 126;
				break;
			case 56: x = 114;
				break;
			case 57: x = 108;
				break;
			case 58: x = 102;
				break;
			case 59: x = 96;
				break;

			}
		}

	}
	return(x);
}

int changehrs(int m, int a)
{
	if (m>15 && m <= 30)
		a -= 12;
	if (m>30 && m <= 45)
		a -= 18;
	if (m>45 && m<60)
		a -= 24;
	return (a);
}
// Cac ham thiet lap dong ho analog

void CreateClock(sClock &c)
{

	for (int i = 0; i < 24; i++)
	{
		AddTail(c.h, i);
	}

	for (int i = 0; i < 60; i++)
	{

		AddTail(c.m, i);
		AddTail(c.s, i);
	}
		
}

// Ham tao, gan gia tri thuc cho dong ho
void SetClock(pNode &p, pNode &q, pNode &r) 
{
	time_t hientai = time(0);

	tm *h;
	h = new tm;
	
	localtime_s(h,&hientai);

	p = GetNode(p, h->tm_sec);
	q = GetNode(q, h->tm_min);
	r = GetNode(r, h->tm_hour);
}

//Xuat dong ho co the chay duoc nhu thoi gian thuc
void grClock(sClock c)
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "c:\\tc\\bgi");

	/*rectangle(150, 50, 250, 100);
	rectangle(250, 50, 350, 100);
	rectangle(350, 50, 450, 100);*/

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	pNode p = c.s->Next; // p chi nut dau
	pNode q = c.m->Next; 
	pNode r = c.h->Next;

	SetClock(p, q, r);

	char s[2];

	int x = 300;
	int y = 200;
	int R = 99;

	int h = 0;

	while (p != NULL)
	{
		setbkcolor(WHITE);
		setcolor(BLACK);
		settextstyle(1, HORIZ_DIR, 1);
		circle(x, y, R);
		setcolor(BLACK);
		circle(x, y, R-2);
		outtextxy(376, 185, "3");
		outtextxy(288, 110, "12");
		outtextxy(207, 185, "9");
		outtextxy(295, 275, "6");

		outtextxy(255, 65, ":");
		outtextxy(355, 65, ":");

		setcolor(BLACK);
		circle(345, 123, 2);
		circle(378, 155, 2);
		circle(378, 245, 2);
		circle(345, 280, 2);
		circle(253, 278, 2);
		circle(223, 245, 2);
		circle(223, 155, 2);
		circle(253, 123, 2);

		setcolor(BLACK);
		outtextxy(195, 65, Itoa(s, r->data));
		setcolor(BLACK);
		pieslice(300, 200, changehrs(q->data, calculatehrs(r->data)) - 1, changehrs(q->data, calculatehrs(r->data)), 55);

		setcolor(BLACK);
		outtextxy(295, 65, Itoa(s, q->data));
		setcolor(BLACK);
		pieslice(300, 200, calculatemin(q->data) - 1, calculatemin(q->data),70);
		

		if (p->data == 0)
		{
			if (q->data == 0)
			{
				/*SetTextColor(0, RED);
				outtextxy(195, 65, Itoa(s, r->data));*/
				r = r->Next;
			}

			/*SetTextColor(0, RED);
			outtextxy(295, 65, Itoa(s, q->data));*/
			q = q->Next;
		}

		setcolor(BLACK);
		outtextxy(395, 65, Itoa(s, p->data));
		setcolor(BLACK);
		pieslice(300, 200, calculatemin(p->data) - 1, calculatemin(p->data), 75);
		p = p->Next;
		delay(985);
		clearviewport();
	}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	while (!kbhit())
	{
		delay(1);
	}

	closegraph();
}

//Bo dem nguoc
void grClockprev(sClock c)
{
	int h;
	int m;
	int ss;

	char s[2];

	cout << "_Nhap gio-phut-giay ban nmuon dem nguoc: " << endl;
	cout << "_Nhap Gio: "; cin >> h;
	cout << "_Nhap Phut: "; cin >> m;
	cout << "_Nhap Giay: "; cin >> ss;

	pNode p = c.s->Next;
	pNode q = c.m->Next;
	pNode r = c.h->Next;

	p = GetNode(p, ss);
	q = GetNode(q, m);
	r = GetNode(r, h);

	int gd = DETECT, gm;
	initgraph(&gd, &gm, "c:\\tc\\bgi");

	

	while (p != NULL)
	{
		setcolor(WHITE);
		settextstyle(1, HORIZ_DIR, 1);

		
		outtextxy(195, 80, "Countdown Clock");
			
		
		outtextxy(395, 200, Itoa(s, p->data));
		outtextxy(295, 200, Itoa(s, q->data));
		outtextxy(195, 200, Itoa(s, r->data));
		outtextxy(250, 200, ":");
		outtextxy(350, 200, ":");

		if (p->data == 0 && q->data == 0 && r->data == 0)
		{
			while (!kbhit())
			{
				delay(100);
			}
		}

		if (p->data == 0)
		{
			if (q->data == 0)
			{
				r = r->Prev;
			}
			q = q->Prev;
		}

		p = p->Prev;

		delay(998);

		clearviewport();
	}

	while (!kbhit())
	{
		delay(1);
	}

	closegraph();
}

void main()
{
	sClock c;

	CreateList(c);

	CreateClock(c);

	int switch_on;

	do
	{
		cout << "01->Xem thoi gian hien tai." << endl;
		cout << "02->Dong ho dem nguoc." << endl;
		cout << "Xin moi Nhap lua chon ban muon: ";
		cin >> switch_on;

		switch (switch_on)
		{
		case 1:
		{
				  grClock(c);
				  break;
		}
		case 2:
		{
				  grClockprev(c);
				  break;
		}
		default:
			break;
		}
	} while (switch_on ==1 && switch_on == 2);
}