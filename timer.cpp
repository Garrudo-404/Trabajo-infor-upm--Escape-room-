#include <stdio.h>
#include <stdlib.h> //system()
#include <windows.h> //Sleep() & Beep()
void timer(int, int, int);
int main()
{
    int h, m, s;
    h = 1;
    m = 0;
    s = 0;
    timer(h, m, s);
    for (int i = 100; ; i = i + 50)
        Beep(i, 1000);
}
//funcion timer
void timer(int h, int m, int s)
{
    while (1)
    {
        if (h == 0 && m == 0 && s == 0)
        {
            break;
        }
        if (s == 0 && m == 0)
        {
            m = 60;
            h--;
        }
        if (s == 0)
        {
            s = 60;
            m--;
        }
        system("cls");
        printf("%d:%d:%d", h, m, s--);
        Sleep(1000);
    }
}