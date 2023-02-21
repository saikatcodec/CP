#include <bits/stdc++.h>
using namespace std;
#define nl "\n"

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, w;
    cin >> n >> w;
    cin.ignore();

    map<char, int> mp;
    vector<char> v;
    string str;
    for (int i = 0; i < n; i++)
    {
        getline(cin, str);
        for (int j = 6; j < 11; j++)
        {
            if (str[j] == 'G')
            {
                mp[str[j - 6]] = (j - 6);
            }
            else if (str[j] == 'Y')
            {
                v.push_back(str[j - 6]);
            }
        }
    }

    string word[w];
    set<string> wd;
    for (int i = 0; i < w; i++)
    {
        cin >> word[i];
    }

    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j < word[i].size(); j++)
        {
            if (j == mp[word[i][j]])
            {
                wd.insert(word[i]);
                break;
            }
        }
    }
    

    return 0;
}