// solved by Dynamic Programming(Bitmask) complexity(O(2 ^ n)));

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define RESET(a, b) memset(a, b, sizeof(a))

int n;
int a[15];
int dp[(1 << 12)];

bool checkbit(int mask, int bit)
{
    return (mask & (1 << bit));
}

int solve(int mask)
{
    if (mask + 1 == (1 << n))
        return 0;
    int &res = dp[mask];
    if (res != -1)
        return res;

    res = 0;
    for (int i = 0; i < n; i++)
    {
        if (!checkbit(mask, i))
        {

            int ans = -1;
            for (int j = i - 1; j >= 0; j--)
            {
                if (!checkbit(mask, j))
                {
                    if (ans == -1)
                        ans = a[j];
                    else
                        ans *= a[j];
                    break;
                }
            }

            for (int j = i + 1; j < n; j++)
            {
                if (!checkbit(mask, j))
                {
                    if (ans == -1)
                        ans = a[j];
                    else
                        ans *= a[j];
                    break;
                }
            }
            if (ans == -1)
                ans = a[i];
            // cout<<ans<<endl;
            res = max(res, ans + solve(mask | (1 << i)));
        }
    }
    return res;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    RESET(dp, -1);
    int result = solve(0);
    cout << result << endl;
    return 0;
}