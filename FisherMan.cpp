// T@nvir - 1604090

#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

struct viru
{
    int pos, men;
};
viru gate[4];

int n;
int vis[20];
int mn_cost = 2e9;
int val = 2e9;

int FindLeft(int loc)
{
    for (int i = loc; i > 0; i--)
    {
        if (vis[i] == 0)
            return i;
    }
    return val;
}

int FindRight(int loc)
{
    for (int i = loc + 1; i <= n; i++)
    {
        if (vis[i] == 0)
            return i;
    }
    return val;
}

void solve(int x, int y, int z, int cost, int curr)
{
    if (mn_cost < cost)
        return;

    if (gate[curr].men == 0)
    {
        if (curr == x)
            curr = y;
        else if (curr == y)
            curr = z;
        else
        {
            mn_cost = min(mn_cost, cost);
            return;
        }
    }

    int l = FindLeft(gate[curr].pos);
    int r = FindRight(gate[curr].pos);

    int leftcost = abs(gate[curr].pos - l) + 1;
    int rightcost = abs(gate[curr].pos - r) + 1;

    bool goleft = true, goright = true;

    if (leftcost > rightcost)
        goleft = false;
    if (rightcost > leftcost)
        goright = false;

    if (goleft)
    {
        vis[l] = 1;
        gate[curr].men--;
        solve(x, y, z, cost + leftcost, curr);
        vis[l] = 0;
        gate[curr].men++;
    }
    if (goright)
    {
        vis[r] = 1;
        gate[curr].men--;
        solve(x, y, z, cost + rightcost, curr);
        vis[r] = 0;
        gate[curr].men++;
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= 3; i++)
        cin >> gate[i].pos;
    for (int i = 1; i <= 3; i++)
        cin >> gate[i].men;

    vis[n + 1] = {0};

    solve(1, 2, 3, 0, 1);
    solve(1, 3, 2, 0, 1);
    solve(2, 1, 3, 0, 2);
    solve(2, 3, 1, 0, 2);
    solve(3, 1, 2, 0, 3);
    solve(3, 2, 1, 0, 3);
    cout << mn_cost << endl;

    return 0;
}
