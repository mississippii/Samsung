// T@nvir -1604090

#include <iostream>
#include <vector>
#include <utility>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

#define RESET(a, b) memset(a, b, sizeof(a))

int node, edge;
vector<int> graph[100];
int vis[101], color[101];

bool bfs(int src)
{
    queue<int> Q;
    Q.push(src);
    vis[src] = 1;
    color[src] = 1;

    while (!Q.empty())
    {
        int temp = Q.front();
        Q.pop();
        for (auto x : graph[temp])
        {
            if (!vis[x])
            {
                Q.push(x);
                vis[x] = 1;
                color[x] = !color[temp];
            }
            else
            {
                if (color[x] == color[temp])
                    return false;
            }
        }
    }
    return true;
}

int main()
{
    cin >> node >> edge;
    RESET(color, -1);
    RESET(vis, 0);

    for (int i = 1; i <= edge; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    cout << bfs(1) << endl;

// If the graph is bipartite and they want to print those node which are same color then print the  index of "color array" which value is "0" or "1";

//    for (int i = 1; i <= node;i++){
//        if(color[i])
//            cout << i << " ";
//      }
//    cout << endl;
    return 0;
}