// solved by Dijkstra

#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, pair<int, int>>
#define RESET(a, b) memset(a, b, sizeof(a))

int cost[10][10];
int a[10][10];
int n, m;
const int inf = 1e9 + 2;

bool validation(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}

void dijkstra(int row, int col)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    RESET(cost, inf);

    cost[row][col] = 0;
    pq.push({cost[row][col], {row, col}});
    while (!pq.empty())
    {
        int dis = pq.top().first;
        int xpos = pq.top().second.first;
        int ypos = pq.top().second.second;
        pq.pop();

        if (validation(xpos, ypos - 1) && a[xpos][ypos - 1] && cost[xpos][ypos] < cost[xpos][ypos - 1])
        {
            cost[xpos][ypos - 1] = dis;
            pq.push({cost[xpos][ypos - 1], {xpos, ypos - 1}});
        }
        if (validation(xpos, ypos + 1) && a[xpos][ypos + 1] && cost[xpos][ypos] < cost[xpos][ypos + 1])
        {
            cost[xpos][ypos + 1] = dis;
            pq.push({cost[xpos][ypos + 1], {xpos, ypos + 1}});
        }
        for (int i = 0; i < n; i++)
        {
            int distance = max(dis, abs(i - xpos));
            if (a[i][ypos] && distance < cost[i][ypos])
            {
                cost[i][ypos] = distance;
                pq.push({cost[i][ypos], {i, ypos}});
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    dijkstra(n - 1, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 3)
            {
                cout << cost[i][j] << endl;
                return 0;
            }
        }
    }
    return 0;
}