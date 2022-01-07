#include<cstring>
#include<fstream>
#include<vector>

using namespace std;

ifstream in("closing.in");
ofstream out("closing.out");

int n, m, order[3000], visited = 0, v[3000], closed[3000];

vector<int> adj[3000];

void dfs(int pos) {
	if (v[pos] || closed[pos]) return;

	v[pos] = 1;
	visited++;

	for (int i : adj[pos])
		dfs(i);
}

int main() {
	in >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		in >> a >> b;
		a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(1);

	out << (visited == n ? "YES\n" : "NO\n");

	for (int i = 0; i < n; i++) {
		in >> order[i];
		order[i]--;
	}

	for (int i = 0; i < n - 1; i++) {
		memset(v, 0, sizeof(int) * n);
		visited = 0;
		closed[order[i]] = 1;

		dfs(order[n - 1]);

		out << (visited == n - i - 1 ? "YES\n" : "NO\n");
	}
}
