#include<algorithm>
#include<iostream>
#include<unordered_set>
#include<vector>

using namespace std;

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

int n, k, cur[100000];

unordered_set<int> path[100000], cmp[100000];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> k;
	
	DSU dsu(n);

	for (int i = 0; i < n; i++) {
		cur[i] = i;
		path[i].insert(i);
	}

	for (int i = 0; i < k; i++) {
		int x, y; cin >> x >> y;
		path[cur[--x]].insert(--y);
		path[cur[y]].insert(x);
		swap(cur[x], cur[y]);
	}

	for (int i = 0; i < n; i++)
		dsu.unite(i, cur[i]);

	for (int i = 0; i < n; i++)
		for (int j : path[i])
			cmp[dsu.get(i)].insert(j);

	for (int i = 0; i < n; i++)
		cout << cmp[dsu.get(i)].size() << "\n";
}
