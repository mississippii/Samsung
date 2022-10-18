// T@nvir - 1604090
#include <iostream>
#include <stack>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int k;
    cin >> k;
    string s;
    cin >> s;
    stack<pair<char, int>> stak;
    int cnt = 0, ans = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != ')')
        {
            if (s[i] == '(')
                stak.push({s[i], cnt++});
            else
                stak.push({s[i], 0});
        }
        else
        {
            string str = "";
            while (stak.top().first != '(')
            {
                if ((stak.top().first - '0') >= 0 && (stak.top().first - '0') < 10)
                    str += stak.top().first;
                stak.pop();
            }
            reverse(str.begin(), str.end());
            int res = 0;
            for (int j = 0; j < str.size(); j++)
                res = res * 10 + (str[j] - '0');
            cnt = stak.top().second;
            stak.pop();
            if (cnt == k)
                ans += res;
        }
    }
    cout << ans << endl;
    return 0;
}