#include <bits/stdc++.h>

using namespace std;

const int N = 1e5;

vector<int> gr[N];

int vis[N], disc[N], low[N], tme = 1;

vector<pair<int, int>> bridges;

set<int> arti_points;

void dfs(int cur, int par)
{
	vis[cur] = 1;
	disc[cur] = low[cur] = tme++;
	int child = 0;
	for (auto x : gr[cur])
	{

		if (!vis[x])
		{
			dfs(x, cur);
			child++;
			// we know low and disc of x
			low[cur] = min(low[cur], low[x]);

			// bridges
			if (low[x] > disc[cur])
			{
				bridges.push_back({cur, x});
			}

			// articulation points
			if (par != 0 && low[x] >= disc[cur])
			{
				arti_points.insert(cur);
			}
		}
		else if (x != par)
		{
			// backedge
			low[cur] = min(low[cur], disc[x]);
		}
	}

	return;
}

int main()
{
	int n;
	cin >> n;

	unordered_map<int, int> mp;
	unordered_map<int, int> mp2;

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		mp[x] = i;
		mp2[i] = x;
	}

	int m;
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		gr[mp[x]].push_back(mp[y]);
	}

	int start;
	int end;

	cin >> start >> end;

	dfs(mp[start], -1);

	for (int i = 0; i < n; i++)
	{
		cout << mp2[i] << " " << disc[i] << " " << low[i] << "\n";
	}

	for (int i = 0; i < n; i++)
	{
		if (disc[i] >= disc[mp[start]] && disc[i] < disc[mp[end]] && low[i] == low[mp[end]])
		{
			cout << mp2[i] << " ";
		}
	}

	return 0;
}