#include <cstdio>
#include <iostream>
using namespace std; 
bool is_leap(int n)
{
    return n % 100 != 0 && n % 4 == 0 || n % 100 == 0 && n % 400 == 0;
}
 
int mon[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
char weekday[7][10] = { "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" };
 
int main()
{
    int n, year, month, day, widx; 
    while (scanf("%d", &n) && n != -1)
    {
        year = 2000; widx = n % 7;
        bool end = false;
        while (!end)
        {
            month = 1, day = 1;
            while (n >= 365 + is_leap(year)) { n -= (365 + is_leap(year)), ++year; };
            mon[1] = 28 + is_leap(year);
            for (int i = 0; i < 12; ++i)
            {
                if (n >= mon[i]) { n -= mon[i]; ++month; }
                else { end = true;  day = n + 1; break; }
            }
            if (!end) ++year;
            else printf("%d-%02d-%02d %s\n", year, month, day, weekday[widx]);
        }
    }
    return 0;
}