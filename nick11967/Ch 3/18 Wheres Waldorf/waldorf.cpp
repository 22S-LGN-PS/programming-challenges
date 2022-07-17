#include <bits/stdc++.h>

using namespace std;

int t;
int m, n;
int k;
int len;
char word[51]; // cuz can be found at least once
char grid[51][51];
int move_one[8][2] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};

bool check_word(int x, int y, int dir)
{
    if (x + 1 < len && (dir == 0 || dir == 1 || dir == 7))
        return false;
    else if (n - y < len && (dir == 1 || dir == 2 || dir == 3))
        return false;
    else if (m - x < len && (dir == 3 || dir == 4 || dir == 5))
        return false;
    else if (y + 1 < len && (dir == 5 || dir == 6 || dir == 7))
        return false;

    for (int i = 0; i < len; i++)
    {
        if (grid[x][y] != word[i])
        {
            return false;
        }
        else
        {
            x += move_one[dir][0];
            y += move_one[dir][1];
        }
    }
    return true;
}

void find_word()
{
    bool valid = false;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == word[0])
            {
                for (int dir = 0; dir < 8; dir++)
                {
                    if (check_word(i, j, dir))
                    {
                        valid = true;
                        break;
                    }
                }
                if (valid)
                {
                    printf("%d %d\n", i + 1, j + 1);
                    break;
                }
            }
            if (valid)
                break;
        }
        if (valid)
            break;
    }
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d %d", &m, &n); // grid input
        for (int i = 0; i < m; i++)
        {
            scanf("%s", grid[i]);
            for (int j = 0; j < n; j++)
            {
                if ('a' <= grid[i][j] && grid[i][j] <= 'z') // change lower to upper
                {
                    grid[i][j] -= 'a' - 'A';
                }
            }
        }

        scanf("%d", &k); // words input
        for (int i = 0; i < k; i++)
        {
            scanf("%s", word);
            len = strlen(word);
            for (int i = 0; i < len; i++)
            {
                if ('a' <= word[i] && word[i] <= 'z') // change lower to upper
                {
                    word[i] -= 'a' - 'A';
                }
            }
            find_word();
        }
    }
    return 0;
}