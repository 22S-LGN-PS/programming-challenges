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
        // cout << "Get original\n";
        for (int i = 0; i <= n; i++)
        {
            getline(cin, turtle);
            turtles.push_back(turtle);
        }
        /*cout << "Inputs\n";
        for (int i = 0; i <= n; i++)
        {
            cout << i << "th: " << turtles[i] << "\n";
        }
        cout << "Get changed\n";*/
        for (int i = 0; i < n; i++)
        {
            getline(cin, turtle);
            new_turtles.push_back(turtle);
        }
        /*cout << "Inputs\n";
        for (int i = 0; i < n; i++)
        {
            cout << i << "th: " << new_turtles[i] << "\n";
        }
        cout << "Check\n";*/
        int p = n;
        for (int i = n - 1; i >= 0; i--)
        {
            if (p <= 0)
            {
                for (int j = i; j >= 0; j--)
                {
                    cout << new_turtles[j] << '\n';
                }
                cout << '\n';
                break;
            }
            while (new_turtles[i] != turtles[p])
            {
                ans.push_back(p);
                // cout << "i = " << i << ", p = " << p << "\n";
                p--;
                if (p <= 0)
                {
                    for (int j = i; j >= 0; j--)
                    {
                        cout << new_turtles[j] << '\n';
                    }
                    cout << '\n';
                    break;
                }
            }
            if (p <= 0)
                break;
            p--;
        }
        /*cout << "Print\n";
        int len = ans.size();
        cout << "Size: " << len << "\n";
        for (int i = 0; i < len; i++)
        {
            cout << turtles[ans[i]] << '\n';
        }
        cout << '\n';*/
    }
    return 0;
}
