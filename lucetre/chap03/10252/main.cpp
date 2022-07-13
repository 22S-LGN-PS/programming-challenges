#include <bits/stdc++.h>
using namespace std;
#define N 26

void CommonPermutation(string a, string b)
{
    int cntA[N + 1] = {0}, cntB[N + 1] = {0};

    for (auto ai : a)
        cntA[ai - 'a']++;

    for (auto bi : b)
        cntB[bi - 'a']++;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < min(cntA[i], cntB[i]); j++)
        {
            cout << (char)(i + 'a');
        }
    }
    cout << endl;
}

int main()
{
    string a, b;
    while (getline(cin, a) && getline(cin, b))
    {
        // cout << "'" << a << "' '" << b << "'" << endl;
        CommonPermutation(a, b);
    }

    return 0;
}