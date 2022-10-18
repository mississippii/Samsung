// solved by Next Permutation(Time Complexity n !)

#include <bits/stdc++.h>
using namespace std;

int main()
{
    for (int tc = 1; tc <= 10; tc++)
    {
        int n;
        cin >> n;
        int ofx, ofy, hmx, hmy;
        cin >> ofx >> ofy >> hmx >> hmy;
        vector<int> v;
        vector<pair<int, int>> p;
        for (int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            v.push_back(i + 1);
            p.push_back({x, y});
        }
        long long ans = INT_MAX;
        do
        {
            int a = ofx, b = ofy;
            long long sum = 0;
            for (int i = 0; i < v.size(); i++)
            {
                sum += abs(p[v[i] - 1].first - a) + abs(p[v[i] - 1].second - b);
                a = p[v[i] - 1].first;
                b = p[v[i] - 1].second;
            }
            sum += abs(a - hmx) + abs(b - hmy);

            ans = min(ans, sum);

        } while (next_permutation(v.begin(), v.end()));
        cout << "# " << tc << " " << ans << endl;
    }
    return 0;
}