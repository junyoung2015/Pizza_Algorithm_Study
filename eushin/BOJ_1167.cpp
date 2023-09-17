#include <iostream>
#include <vector>
using namespace std;

int V, snode, tnode, tdist, node, ans;
bool visited[100001];
vector <pair<int, int>> graph[100001];

void dfs(int x, int dist)
{
	visited[x] = true;
	if (dist > ans)
	{
		ans = dist;
		node = x;
	}
	for (int i = 0; i < graph[x].size(); i++)
	{
		int next_node = graph[x][i].first;
		int next_dist = graph[x][i].second + dist;
		if (!visited[next_node])
		{
			visited[next_node] = true;
			dfs(next_node, next_dist);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> V;
	for (int i = 1; i <= V; i++)
	{
		cin >> snode;
		while (true)
		{
			cin >> tnode;
			if (tnode == -1)
				break;
			cin >> tdist;
			graph[snode].push_back({tnode, tdist});
		}
	}

	dfs(1, 0);
	for(int i = 1; i <= V; i++)
		visited[i] = false;
	dfs(node, 0);
	cout << ans;
}

