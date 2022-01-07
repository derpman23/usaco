#include<fstream>
#include<vector>

using namespace std;

ifstream in("wormsort.in");
ofstream out("wormsort.out");

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

struct edge {
	int a, b, w;
} e[100000];

int n, m, p[100000], ans = -1;

int works(int x) {
	DSU dsu(n);

	for (int i = 0; i < m; i++)
		if (e[i].w >= x)
			dsu.unite(e[i].a, e[i].b);

	for (int i = 0; i < n; i++)
		if (!dsu.same(i, p[i]))
			return 0;

	return 1;
}

int main() {
	in >> n >> m;

	for (int i = 0; i < n; i++) {
		in >> p[i];
		p[i]--;
	}

	for (int i = 0; i < m; i++) {
		in >> e[i].a >> e[i].b >> e[i].w;
		e[i].a--; e[i].b--;
	}

	int l = 0, r = 1000000001;

	while (l <= r) {
		int m = (l + r) / 2;

		if (works(m)) { ans = max(ans, m); l = m + 1; }
		else r = m - 1;
	}

	out << (ans > 1000000000 ? -1 : ans) << "\n";
}
