// UVa ID: 10127

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, x, t, sum;

    while (scanf("%d", &a) == 1)
    {
        sum = 0;
        x = 0;
        t = 1;
        do
        {
            sum = (sum + t) % a;
            x++;
            t = (t + 10) % a;
        } while (sum != 0);
        printf("%d\n", x);
    }

    return 0;
}