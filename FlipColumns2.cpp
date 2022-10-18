// Bitmask Solution

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    int a[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    int ans = 0;
    for (int mask = 0; mask < (1 << m); mask++)
    {
        int cnt = __builtin_popcount(mask);

        if (cnt < k && (k - cnt) % 2 == 1)
            continue;

        int res = 0;

        for (int i = 0; i < n; i++)
        {
            int c = 0;
            for (int j = 0; j < m; j++)
            {
                bool val = mask & (1 << j);

                int temp;

                if (val == 1)
                    temp = 1 - a[i][j];
                else
                    temp = a[i][j];

                c += temp;
            }
            if (c == m)
                res++;
        }
        ans = max(ans, res);
    }
    cout << ans << endl;
    return 0;
}
