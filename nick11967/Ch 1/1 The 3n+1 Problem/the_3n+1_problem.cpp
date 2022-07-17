#include <bits/stdc++.h>

using namespace std;

int f(int n)
{
    int num = 0;
    while (n != 1)
    {
        num++;
        if (n % 2 == 0)
        {
            n /= 2;
        }
        else
        {
            n = 3 * n + 1;
        }
    }
    return num + 1;
}

int main()
{
    int a, b;
    int max_cycle, cycle;
    while (cin >> a >> b)
    {
        if (a > b)
        {
            int temp = a;
            a = b;
            b = temp;
        }
        max_cycle = 0;
        for (int i = a; i <= b; i++)
        {
            cycle = f(i);
            (max_cycle < cycle) ? max_cycle = cycle : max_cycle = max_cycle;
        }
        cout << a << ' ' << b << ' ' << max_cycle << '\n';
    }
    return 0;
}