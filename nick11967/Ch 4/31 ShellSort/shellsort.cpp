#include <bits/stdc++.h>

using namespace std;

int main()
{
    int k;
    scanf("%d", &k);
    int n;
    vector<string> turtles, new_turtles;
    vector<int> ans;

    while (k--)
    {
        scanf("%d", &n);
        turtles.clear();
        new_turtles.clear();
        ans.clear();
        string turtle;
        cout << "Get original\n";
        for (int i = 0; i < n; i++)
        {
            getline(cin, turtle);
            turtles.push_back(turtle);
        }
        cout << "Get changed\n";
        for (int i = 0; i < n; i++)
        {
            getline(cin, turtle);
            new_turtles.push_back(turtle);
        }
        cout << "Check\n";
        int p = n - 1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (p < 0)
                break;
            while (new_turtles[i] != turtles[p])
            {
                ans.push_back(p);
                p--;
                if (p < 0)
                    break;
            }
        }
        cout << "Print\n";
        int len = ans.size();
        cout << "Size: " << len << "\n";
        for (int i = 0; i < len; i++)
        {
            cout << turtles[ans[i]] << '\n';
        }
        cout << '\n';
    }
    return 0;
}
