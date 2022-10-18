// T@nvir - 1604090
#include <bits/stdc++.h>
using namespace std;

int n;
int a[10][5];
int vis[10];
int ans = INT_MAX;

int distance(int x1, int y1, int x2, int y2)
{
    return abs(x1 - x2) + abs(y1 - y2);
}

void fun(int srcx, int srcy, int desx, int desy, int cost)
{

    ans = min(ans, distance(srcx, srcy, desx, desy) + cost);
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 0)
        {
            vis[i] = 1;
            int temp = distance(srcx, srcy, a[i][0], a[i][1]) + a[i][4] + cost;

            fun(a[i][2], a[i][3], desx, desy, temp);

            temp = distance(srcx, srcy, a[i][2], a[i][3]) + a[i][4] + cost;
            fun(a[i][0], a[i][1], desx, desy, temp);
            vis[i] = 0;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int sx, sy, dx, dy;
        cin >> sx >> sy >> dx >> dy;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                cin >> a[i][j];
            }
        }
        fun(sx, sy, dx, dy, 0);
        cout << ans << endl;
    }
    return 0;
}
