//Template
#include <bits/stdc++.h>
#define endl "\n"
typedef long long ll;
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        ll counter[26];
        memset(counter, 0, sizeof(counter));
        string s1, s2;
        string s1_new = s1;
        cin >> s1 >> s2;
        for (int i = 0; i < s1.size(); i++)
        {
            counter[s1[i] - 'a']++;
        }
        if (s1 == s2)
        {
            cout << s1;
        }
        else
        {
            sort(s1_new.begin(), s1_new.end());
            if (s1_new.find(s2) != string::npos)
            {
                cout << s1_new;
            }
            else if (s2.length() == 1)
            {
                for (int i = 0; i < s2.size(); i++)
                {
                    counter[s2[i] - 'a']--;
                }
                char required_character = s2[0];
                for (int i = 0; i < 26; i++)
                {
                    for (int j = 0; j < counter[i]; j++)
                    {
                        cout << char('a' + i);
                    }
                    if (required_character == ('a' + i))
                    {
                        cout << s2;
                    }
                }
            }
            else
            {
                for (int i = 0; i < s2.size(); i++)
                {
                    counter[s2[i] - 'a']--;
                }
                char required_character = s2[0];
                char use;
                for (int i = 1; i < s2.size(); i++)
                {
                    if (s2[0] != s2[i])
                    {
                        use = s2[i];
                        break;
                    }
                }
                for (int i = 0; i < 26; i++)
                {
                    if (required_character == ('a' + i))
                    {
                        if (use < required_character)
                        {
                            cout << s2;
                            for (int j = 0; j < counter[i]; j++)
                            {
                                cout << char('a' + i);
                            }
                        }
                        else
                        {
                            for (int k = 0; k < counter[i]; k++)
                            {
                                cout << char('a' + i);
                            }
                            cout << s2;
                        }
                    }
                    else
                    {
                        for (int k = 0; k < counter[i]; k++)
                        {
                            cout << char('a' + i);
                        }
                    }
                }
            }
        }
        cout << endl;
    }
    return 0;
}