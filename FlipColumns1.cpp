// solvd by recursion

#include <bits/stdc++.h>
using namespace std;

int a[15][15];
int n, m, k, ans = 0;

void flip(int x)
{
    for (int i = 0; i < n; i++)
    {
        a[i][x] ^= 1;
    }
}

void solve(int len)
{

    if (len == k)
    {
        int row = 0;
        for (int i = 0; i < n; i++)
        {
            int cnt = 0;
            for (int j = 0; j < m; j++)
            {
                if (a[i][j] == 1)
                {
                    cnt++;
                }
            }
            if (cnt == m)
                row++;
        }
        ans = max(ans, row);
        return;
    }
    for (int w = 0; w < m; w++)
    {
        flip(w);
        solve(len + 1);
        flip(w);
    }
}

int main()
{
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    solve(0);
    cout << ans << endl;
    return 0;
}