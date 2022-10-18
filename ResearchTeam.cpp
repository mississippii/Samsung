// T@nvir - 1604090

#include <iostream>
using namespace std;

int n, m;
int a[50][50];
int vis[50][50];
int dis[50][50][10];

struct tanvir
{
    int x, y;
};

void init()
{
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            a[i][j] = 0;
            vis[i][j] = 0;
            for (int k = 0; k < 10; k++)
            {
                dis[i][j][k] = -1;
            }
        }
    }
}

bool validation(int x, int y)
{
    return (x >= 0 && y >= 0 && x < n && y < n && a[x][y]);
}

void solve(int x, int y, int cost, int ith)
{
    if (!validation(x, y))
        return;

    if (dis[x][y][ith] < cost && vis[x][y])
        return;

    vis[x][y] = 1;
    dis[x][y][ith] = cost;
    solve(x + 1, y, cost + 1, ith);
    solve(x - 1, y, cost + 1, ith);
    solve(x, y + 1, cost + 1, ith);
    solve(x, y - 1, cost + 1, ith);
}

int main()
{
    int tc;
    cin >> tc;
    for (int i = 0; i < tc; i++)
    {
        init();
        cin >> n >> m;
        tanvir rear[m];
        for (int i = 0; i < m; i++)
        {
            cin >> rear[i].x;
            cin >> rear[i].y;
            rear[i].x--;
            rear[i].y--;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> a[i][j];
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    vis[j][k] = 0;
                }
            }
            solve(rear[i].x, rear[i].y, 0, i);
        }
        int mn = 2e9;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (a[i][j] == 0)
                    continue;
                int z = -1;
                for (int k = 0; k < m; k++)
                {
                    if (dis[i][j][k] > z)
                    {
                        z = dis[i][j][k];
                    }
                }
                if (mn > z)
                    mn = z;
            }
        }
        cout << mn << endl;
    }
    return 0;
}
