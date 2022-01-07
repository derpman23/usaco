#include<algorithm>
#include<fstream>
#include<vector>

using namespace std;

typedef pair<int, int> pii;

ifstream in("moocast.in");
ofstream out("moocast.out");

struct DSU {
	vector<int> v;

	DSU(int n) { v = vector<int>(n, -1); }
	int get(int x) { return v[x] < 0 ? x : v[x] = get(v[x]); }
	int same(int a, int b) { return get(a) == get(b); }
	int unite(int x, int y) {
		x = get(x), y = get(y);
		if (x == y) { cnt++; return 0; }
		if (v[x] > v[y]) swap(x, y);
		v[x] += v[y];
		v[y] = x;
		return 1;
	}
};

struct edge {
	int a, b, d;

	friend int operator<(edge e1, edge e2) {
		return e1.d < e2.d;
	}
};

int n, ans = 0;

pii cows[25000];

vector<edge> v;

int main() {
	in >> n;

	for (int i = 0; i < n; i++)
		in >> cows[i].first >> cows[i].second;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			int d = (cows[i].first - cows[j].first) * (cows[i].first - cows[j].first) + (cows[i].second - cows[j].second) * (cows[i].second - cows[j].second);
			v.push_back({ i, j, d });
		}
	}

	sort(v.begin(), v.end());
	DSU dsu(n);
	int cnt = n;

	for (edge e : v) {
		if (!dsu.same(e.a, e.b)) {
			dsu.unite(e.a, e.b);
			ans = e.d;
			if (--cnt == 1) break;
		}
	}

	out << ans << "\n";
}
