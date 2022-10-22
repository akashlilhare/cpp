#include <bits/stdc++.h>
#define REP(i, n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define INF 1000000000

const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;

using namespace std;

class DSU
{
    int *parent;
    int *rank;

public:
    DSU(int n)
    {
        parent = new int[n];
        rank = new int[n];

        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    int find(int i)
    {
        if (parent[i] == i)
        {
            return i;
        }

        return parent[i] = find(parent[i]);
    }

    void Union(int a, int b)
    {
        int x = find(a);
        int y = find(b);

        if (x != y)
        {
            if (rank[x] < rank[y])
            {
                parent[x] = y;
                rank[y] += rank[x];
            }
            else
            {
                swap(x, y);
                parent[x] = y;
                rank[y] += rank[x];
            }
        }
    }
};

class Graph
{
    // Adjacency List
    vector<pair<int, int>> *l;
    int V;

public:
    Graph(int n)
    {
        V = n;
        l = new vector<pair<int, int>>[n];
    }

    void addEdge(int x, int y, int w)
    {
        l[x].push_back({y, w});
        l[y].push_back({x, w});
    }

    int prim_mst()
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        vector<bool> visited(V, 0);

        int ans = 0;

        q.push({0, 0});

        while (!q.empty())
        {
            auto it = q.top();
            q.pop();

            int node = it.second;
            int weight = it.first;

            if (visited[node])
                continue;

            ans += weight;
            visited[node] = 1;

            for (auto edge : l[node])
            {
                if (!visited[edge.first])
                {
                    q.push({edge.second, edge.first});
                }
            }
        }

        return ans;
    }

    int khrushkal()
    {

        return 0;
    }
};

int main()
{
    Graph g(4);

    g.addEdge(0, 1, 100);
    g.addEdge(0, 2, 1);
    g.addEdge(0, 3, 1);
    g.addEdge(1, 3, 2);
    g.addEdge(2, 3, 3);

    cout << g.prim_mst() << "\n";

    return 0;
}