#include <bits/stdc++.h>
#define M 50
using namespace std;
char grid[M + 1][M + 1];
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int m, n;

char ToLower(char c)
{
    if (c >= 'A' && c <= 'Z')
        c -= 'A' - 'a';
    return c;
}

bool Check(string word, int sy, int sx, int dir)
{
    if (grid[sy][sx] != word[0])
        return false;
    for (int i = 1; i < word.length(); i++)
    {
        int y = sy + dy[dir] * i;
        int x = sx + dx[dir] * i;
        if (y < 0 || x < 0 || y >= m || x >= n)
            return false;
        if (grid[y][x] != word[i])
            return false;
    }
    return true;
}

void Waldorf()
{
    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++)
            grid[i][j] = ToLower(s[j]);
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        string word;
        cin >> word;
        for (int j = 0; j < word.length(); j++)
            word[j] = ToLower(word[j]);

        for (int sy = 0; sy < m; sy++)
        {
            for (int sx = 0; sx < n; sx++)
            {
                int flag = false;
                for (int dir = 0; dir < 8; dir++)
                {
                    if (Check(word, sy, sx, dir))
                    {
                        flag = true;
                        break;
                    }
                }
                if (flag)
                {
                    cout << sy + 1 << " " << sx + 1 << endl;
                }
            }
        }
    }
}

int main()
{
    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        Waldorf();
    }
    return 0;
}