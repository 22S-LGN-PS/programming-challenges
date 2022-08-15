#include <bits/stdc++.h>
using namespace std;

int get_min_digits_of_ones_multiple_of(int n)
{
    int digit = 1, ones = 1;

    while (ones % n)
    {
        ones = (ones * 10 + 1) % n;
        digit++;
    }
    return digit;
}

int main()
{
    int n;
    while (cin >> n)
        cout << get_min_digits_of_ones_multiple_of(n) << endl;

    return 0;
}