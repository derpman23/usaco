#include<fstream>
#include<vector>

using namespace std;

typedef pair<int, int> pii;

ifstream in("revegetate.in");
ofstream out("revegetate.out");

struct DSU {
	vector<int> v;

	DSU(int n) { v = vector<int>(n, -1); }
	int get(int x) { return v[x] < 0 ? x : v[x] = get(v[x]); }
	int same(int a, int b) { return get(a) == get(b); }
	int unite(int x, int y) {
		x = get(x), y = get(y);
		if (x == y) { return 0; }
		if (v[x] > v[y]) swap(x, y);
		v[x] += v[y];
		v[y] = x;
		return 1;
	}
};

int n, m, impossible = 0, v[100000];

vector<pii> d;

vector<int> adj[100000];

int main() {
	in >> n >> m;
	DSU dsu(n);

	for (int i = 0; i < m; i++) {
		char c;
		int a, b;
		in >> c >> a >> b;
		a--, b--;

		if (c == 'S') dsu.unite(a, b);
		else {
			d.push_back({ a, b });
			if (!adj[a].empty()) dsu.unite(adj[a][0], b);
			if (!adj[b].empty()) dsu.unite(adj[b][0], a);
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
	}

	for (pii p : d) {
		if (dsu.same(p.first, p.second)) {
			impossible = 1;
			break;
		}
	}

	if (impossible) out << "0\n";
	else {
		for (pii p : d)
			dsu.unite(p.first, p.second);

		out << 1;
		for (int i = 0; i < n; i++) {
			int parent = dsu.get(i);
			if (parent >= 0 && !v[parent]) {
				v[parent] = 1;
				out << 0;
			}
		}
		out << "\n";
	}
}
