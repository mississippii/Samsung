#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define RESET(a, b) memset(a, b, sizeof(a))

int a[55][55], vis[55][55] = {0}, dis[55][55];
int n, m;
int ax[] = {0, 0, 1, -1}, bx[] = {-1, 1, 0, 0};

struct tanvir
{
    int left, right, up, down;
};
tanvir pip[8] = {0};

void link()
{
    pip[1].left = 1, pip[1].right = 1, pip[1].up = 1, pip[1].down = 1;
    pip[2].up = 1, pip[2].down = 1;
    pip[3].left = 1, pip[3].right = 1;
    pip[4].up = 1, pip[4].right = 1;
    pip[5].right = 1, pip[5].down = 1;
    pip[6].left = 1, pip[6].down = 1;
    pip[7].left = 1, pip[7].up = 1;
}
bool validation(int x, int y)
{
    return (x >= 0 && x < n && y >= 0 && y < m);
}

bool fun(int pipe1, int pipe2, int type)
{

    if (pipe1 == 0 || pipe2 == 0)
        return 0;
    else if (type == 0)
    {
        if (pip[pipe1].left == 1 && pip[pipe2].right == 1)
            return 1;
        return 0;
    }
    else if (type == 1)
    {
        if (pip[pipe1].right == 1 && pip[pipe2].left == 1)
            return 1;
        return 0;
    }
    else if (type == 2)
    {
        if (pip[pipe1].down == 1 && pip[pipe2].up == 1)
            return 1;
        return 0;
    }
    else
    {
        if (pip[pipe1].up == 1 && pip[pipe2].down == 1)
            return 1;
        return 0;
    }
}

void bfs(int sx, int sy)
{
    queue<pii> Q;
    Q.push({sx, sy});
    vis[sx][sy] = 1;
    while (!Q.empty())
    {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
        for (int i = 0; i < 4; i++)
        {
            int rx = ax[i] + x;
            int ry = bx[i] + y;

            if (validation(rx, ry) && vis[rx][ry] == 0 && fun(a[x][y], a[rx][ry], i))
            {
                dis[rx][ry] = min(dis[rx][ry], dis[x][y] + 1);
                vis[rx][ry] = 1;
                Q.push({rx, ry});
            }
        }
    }
}

int main()
{
    link();
    int t;
    cin >> t;
    while (t--)
    {
        int sx, sy, len;
        cin >> n >> m >> sx >> sy >> len;

        RESET(dis, 10);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                vis[i][j] = 0;
                cin >> a[i][j];
            }
        }
        dis[sx][sy] = 0;

        bfs(sx, sy);

        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (dis[i][j] < len)
                    cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}