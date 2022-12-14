// T@nvir - 1604090

//Solved by Dynamic Programming Using memoization

#include <bits/stdc++.h>
using namespace std;

#define RESET(a, b) memset(a, b, sizeof(a))
int n;
int a[100][5], ara[100][5], cost[100][5];

void reset()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cost[i][j] = -1;
            a[i][j] = ara[i][j];
        }
    }
}

int main()
{
    int tc;
    cin >> tc;
    for (int ii = 1; ii <= tc; ii++)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                cin >> ara[i][j];
            }
        }
        reset();

        int ans = 0;

        for (int i = n - 1; i >= 0; i--)
        {

            for (int j = i; j >= max(0, i - 4); j--)
            {
                for (int k = 0; k < 5; k++)
                {
                    if (a[j][k] == 2)
                        a[j][k] = 0;
                }
            }
            if (a[n - 1][1] != 2)
                cost[n - 1][1] = a[n - 1][1];
            if (a[n - 1][2] != 2)
                cost[n - 1][2] = a[n - 1][2];
            if (a[n - 1][3] != 2)
                cost[n - 1][3] = a[n - 1][3];

            for (int j = n - 2; j >= 0; j--)
            {
                for (int k = 0; k < 5; k++)
                {
                    if (a[j][k] == 2)
                        continue;
                    else if (k == 0)
                        cost[j][k] = max(cost[j + 1][k], cost[j + 1][k + 1]) + a[j][k];
                    else if (k == 4)
                        cost[j][k] = max(cost[j + 1][k], cost[j + 1][k - 1]) + a[j][k];
                    else
                        cost[j][k] = max(cost[j + 1][k], max(cost[j + 1][k + 1], cost[j + 1][k - 1])) + a[j][k];
                }
            }

            int res = 0;
            for (int i = 0; i < n; i++)
            {
                int val = 0;
                for (int j = 0; j < 5; j++)
                {
                    if (cost[i][j] > val)
                        val = cost[i][j];
                }
                res = max(res, val);
            }
            if (res > ans)
                ans = res;

            reset();
        }
        cout << "#" << ii << " " << ans << endl;
    }
    return 0;
}
