#include <bits/stdc++.h>

using namespace std;

int alpha_first[26], alpha_second[26];

void clear()
{
    for (int i = 0; i < 26; i++)
    {
        alpha_first[i] = 0;
        alpha_second[i] = 0;
    }
}

int main()
{
    int alpha = 0;
    string first_word, second_word;
    while (cin >> first_word)
    {
        cin >> second_word;
        alpha = 0;
        clear();

        int len_first = first_word.length();
        int len_second = second_word.length();

        for (int i = 0; i < len_first; i++)
        {
            alpha_first[first_word[i] - 'a']++;
        }
        for (int i = 0; i < len_second; i++)
        {
            alpha_second[second_word[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++)
        {
            alpha = min(alpha_first[i], alpha_second[i]);
            while (alpha--)
            {
                printf("%c", i + 'a');
            }
        }
        printf("\n");
    }
    return 0;
}