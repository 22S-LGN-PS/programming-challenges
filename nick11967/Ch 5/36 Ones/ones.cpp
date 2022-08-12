// UVa ID: 10127

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, x, t, sum;

    while (scanf("%d", &n) == 1)
    {
        sum = 0;
        x = 0;
        t = 1;
        do
        {
            sum = (sum + t) % n;
            x++;
            t = (t * 10) % n;
        } while (sum != 0);
        printf("%d\n", x);
    }

    return 0;
}