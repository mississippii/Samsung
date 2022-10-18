//T@nvir - 1604090

//Advance Conding Contest in Samsung R &D Bangladesh
//Solved by Recursion complexity(O(2 ^ n))

#include <iostream>
#include <algorithm>
    using namespace std;

int n;
int a[13][13], vis[13];

int solve(int src, int cnt)
{
    if (cnt == n)
        return a[src][0];

    int ans = 2e9;
    for (int i = 1; i < n; i++)
    {
        if (!vis[i])
        {
            vis[i] = 1;
            ans = min(ans, solve(i, cnt + 1) + a[src][i]);
            vis[i] = 0;
        }
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
            for (int j = 0; j < n; j++)
                cin >> a[i][j];
        cout << solve(0, 1) << endl;
    }

    return 0;