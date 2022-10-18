#include <iostream>
#include <vector>
#include <utility>
#include <cstring>
#include <algorithm>

using namespace std;

vector<int> graph[51];
int vis[51];
vector<int> v;
vector<vector<int>> vec;

void dfs(int src)
{

    vis[src] = 1;
    v.push_back(src);
    for (auto x : graph[src])
    {
        if (!vis[x])
            dfs(x);
        else
        {
            int indx = -1;
            for (int i = 0; i < v.size(); i++)
            {
                if (v[i] == x)
                {
                    indx = i;
                    break;
                }
            }
            if (indx != -1)
            {
                vector<int> a;
                for (int i = indx; i < v.size(); i++)
                    a.push_back(v[i]);
                vec.push_back(a);
            }
        }
    }
    v.pop_back();
    vis[src] = 0;
}

int main()
{
    int node, edge;
    cin >> node >> edge;
    for (int i = 0; i < edge; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
    for (int i = 0; i <= node; i++)
        dfs(i);

    int ans = INT_MAX;
    vector<int> res;
    for (int i = 0; i < vec.size(); i++)
    {
        int sum = 0;
        ;
        for (int j = 0; j < vec[i].size(); j++)
            sum += vec[i][j];

        if (sum < ans)
        {
            res = vec[i];
            ans = sum;
        }
    }
    sort(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;
    return 0;
}