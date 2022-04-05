#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

typedef long long ll;
typedef tuple<ll, int, int> tup;

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

int n, m, cnt = 0;

ll ans = 0;

vector<tup> edges;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b; ll w; cin >> a >> b >> w;
		edges.push_back({ w, --a, --b });
	}

	sort(edges.begin(), edges.end());

	DSU dsu(n);
	for (auto [w, a, b] : edges)
		if (dsu.unite(a, b))
			ans += w, cnt++;

	if (cnt == n - 1) cout << ans << "\n";
	else cout << "-1\n";
}
