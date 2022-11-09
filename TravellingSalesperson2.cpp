//T@nvir-1604090

#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
#define RESET(a, b) memset(a, b, sizeof(a))

int n, a[20][20], dp[(1 << 20)][20];

int BitmaskDp(int mask, int cnt)
{
    if ((mask + 1) == (1 << n))
        return a[cnt][0];

    int &ans = dp[mask][cnt];
    if (ans != -1)
        return dp[mask][cnt];

    ans = 2e9;
    for (int i = 1; i < n; i++)
    {
        ans = min(ans, BitmaskDp((mask | (1 << i)), i) + a[cnt][i]);
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> a[i][j];
            }
        }
        RESET(dp, -1);
        cout << BitmaskDp(1, 0) << endl;
    }
    return 0;
}
