#include <iostream>

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
    cin >> a >> b;
    while (a != '\n')
    {
        max_cycle = 0;
        for (int i = a; i <= b; i++)
        {
            cycle = f(i);
            (max_cycle < cycle) ? max_cycle = cycle : max_cycle = max_cycle;
        }
        cout << a << ' ' << b << ' ' << max_cycle << '\n';
        cin >> a >> b;
    }
    return 0;
}