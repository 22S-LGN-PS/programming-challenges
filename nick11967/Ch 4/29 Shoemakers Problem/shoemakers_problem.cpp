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
            for (int j = i + 1; j < n; j++)
            {
                if (get<1>(work[i]) * get<0>(work[j]) < get<1>(work[j]) * get<0>(work[i]))
                {
                    swap(work[i], work[j]);
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            printf("%d", get<2>(work[i]));
            if (i != n - 1)
                printf(" ");
        }
        if (c != 0)
            printf("\n");
    }
    return 0;
}