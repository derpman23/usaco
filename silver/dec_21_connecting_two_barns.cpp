#include<cstring>
#include<iostream>
#include<numeric>
#include<vector>

using namespace std;

typedef long long ll;

struct DSU {
	int v[100000];

	void init(int n) { memset(v, -1, sizeof(int) * n); }
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

int t, n, m, l, r;

DSU dsu;

vector<int> cmp[100000];

ll cl[100000], cr[100000], ans;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> t;
	while (t--) {
		cin >> n >> m;
		dsu.init(n);

		for (int i = 0; i < m; i++) {
			int a, b; cin >> a >> b;
			dsu.unite(--a, --b);
		}

		if (dsu.get(0) == dsu.get(n - 1)) { cout << "0\n"; continue; }

		for (int i = 0; i < n; i++) {
			cmp[i].clear();
			cl[i] = 100000;
			cr[i] = 100000;
		}

		for (int i = 0; i < n; i++)
			cmp[dsu.get(i)].push_back(i);

		l = 0, r = 0;

		for (int i = 0; i < n; i++) {
			while (l < cmp[dsu.get(0)].size()) {
				cl[dsu.get(i)] = min(cl[dsu.get(i)], (ll)abs(i - cmp[dsu.get(0)][l]));
				if (cmp[dsu.get(0)][l] >= i) break;
				l++;
			}
			if (l) l--;

			while (r < cmp[dsu.get(n - 1)].size()) {
				cr[dsu.get(i)] = min(cr[dsu.get(i)], (ll)abs(i - cmp[dsu.get(n - 1)][r]));
				if (cmp[dsu.get(n - 1)][r] >= i) break;
				r++;
			}
			if (r) r--;
		}

		ans = 5000000000;

		for (int i = 0; i < n; i++)
			ans = min(ans, cl[i] * cl[i] + cr[i] * cr[i]);

		cout << ans << "\n";
	}
}
