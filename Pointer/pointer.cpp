#include <iostream>
using namespace std;

void sum_x(int &x, int i);
void sum_p(int *p, int i);

int main()
{
    int x = 5;
    int *p = &x;

    cout << "Dia chi cua x " << &x << endl;
    cout << "Gia tri cua x " << x << endl;

    cout << "Gia tri cua p " << p << endl;
    cout << "Dia chi cua p " << &p << endl;
    cout << "Gia tri cua x ma p tro toi " << *p << endl;

    *p = x + 1;

    cout << "Gia tri cua x ma p tro toi " << *p << endl;
    cout << "Gia tri cua x " << x << endl;

    sum_x(x, 10);

    cout << "Gia tri cua x " << x << endl;

    sum_p(p, 20);

    cout << "Gia tri cua x ma p tro toi " << *p << endl;
    cout << "Gia tri cua x " << x << endl;

    return 0;
}

void sum_x(int &x, int i)
{
    x = x + i;
}

void sum_p(int *p, int i)
{
    *p = *p + i;
}