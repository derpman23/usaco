#include<cstring>
#include<fstream>
#include<vector>

using namespace std;

typedef pair<int, int> pii;

ifstream in("mootube.in");
ofstream out("mootube.out");

int n, q, k, v[5000], ans = 0;

vector<pii> adj[5000];

void dfs(int vid) {
	v[vid] = 1;

	for (pii p : adj[vid]) {
		if (!v[p.first] && p.second >= k) {
			ans++;
			dfs(p.first);
		}
	}
}

int main() {
	in >> n >> q;

	for (int i = 0; i < n - 1; i++) {
		int p, q, r;
		in >> p >> q >> r;
		p--, q--;
		adj[p].push_back({ q, r });
		adj[q].push_back({ p, r });
	}

	while (q--) {
		memset(v, 0, sizeof(int) * n);
		ans = 0;

		int vid;
		in >> k >> vid;
		vid--;

		dfs(vid);

		out << ans << "\n";
	}
}
