#include <bits/stdc++.h>

using namespace std;

unsigned int reverse(unsigned int x)
{
    unsigned int r = 0;
    while (x > 0)
    {
        r = r * 10 + x % 10;
        x /= 10;
    }
    return r;
}

bool palindrome(unsigned int x)
{
    unsigned int rx = reverse(x);
    return rx == x ? true : false;
}

int main()
{
    short n;
    scanf("%hd", &n);
    unsigned int k;
    while (n--)
    {
        short i;
        scanf("%u", &k);
        unsigned int rk;
        for (i = 1;; i++)
        {
            rk = reverse(k);
            k += rk;
            if (palindrome(k))
            {
                break;
            }
        }
        printf("%hd %u\n", i, k);
    }
    return 0;
}