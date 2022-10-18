// T@nvir - 1604090

//Solved by next permutation

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a, v(n), c;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
        v[i] = i;
    }
    int ans = 0, res = 0;
    do
    {
        c = a;
        ans = 0;
        int l, r;
        for (int i = 0; i < n; i++)
        {
            l = v[i] - 1, r = v[i] + 1;
            // cout<<l<<" "<<r<<endl;
            while (1)
            {
                if (l < 0)
                    break;
                if (c[l] == 0)
                    l--;
                if (c[l])
                    break;
            }

            while (1)
            {
                if (r >= n)
                    break;
                if (c[r] == 0)
                    r++;
                if (c[r])
                    break;
            }

            if (l >= 0 && r < n)
            {
                ans += (c[l] * c[r]);
                c[v[i]] = 0;
            }

            else if (l < 0 && r < n)
            {
                ans += c[r];
                c[v[i]] = 0;
            }

            else if (r >= n && l >= 0)
            {
                ans += c[l];
                c[v[i]] = 0;
            }

            else if (l < 0 && r >= n)
            {
                ans += c[v[i]];
                c[v[i]] = 0;
            }
        }
        res = max(res, ans);
    } while (next_permutation(v.begin(), v.end()));
    cout << res << endl;
    return 0;
}
