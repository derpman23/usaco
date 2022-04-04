#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

#include<vector>

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

	friend int operator<(edge e1, edge e2) {
		if (e1.w != e2.w) return e1.w > e2.w;
		if (e1.a != e2.a) return e1.a > e2.a;
		return e1.b > e2.b;
	}
} edges[100000];

int n;

long long ans = 0;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	DSU dsu(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> edges[i].b >> edges[i].w, edges[i].a = i;

	sort(edges + 1, edges + n + 1);

	for (int i = 1; i <= n; i++)
		if (dsu.unite(edges[i].a, edges[i].b))
			ans += edges[i].w;

	cout << ans << "\n";
}
