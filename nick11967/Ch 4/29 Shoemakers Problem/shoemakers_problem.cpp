#include <bits/stdc++.h>

using namespace std;

int main()
{
    int c;
    scanf("%d", &c);
    int n;
    vector<tuple<int, int, int>> work;
    tuple<int, int, int> temp;
    while (c--)
    {
        scanf("%d", &n);
        work.clear();
        int t, s;
        for (int i = 0; i < n; i++)
        {
            scanf("%d %d", &t, &s);
            work.push_back(make_tuple(t, s, i + 1));
        }
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j + i < n - 1; j++)
            {
                if (get<1>(work[j]) * get<0>(work[j + 1]) < get<1>(work[j + 1]) * get<0>(work[j]))
                {
                    swap(work[j], work[j + 1]);
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << get<2>(work[i]) << " ";
        }
        cout << endl;
    }
    return 0;
}