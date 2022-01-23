#include<algorithm>
#include<fstream>
#include<numeric>
#include<vector>

using namespace std;

ifstream in("swap.in");
ofstream out("swap.out");

int n, m, k, cows[100000], a[100000], v[100000], ans[100000];

vector<int> b;

void dfs(int pos) {
	v[pos] = 1;
	b.push_back(pos);
	if (!v[a[pos]])
		dfs(a[pos]);
}

int main() {
	in >> n >> m >> k;
	
	iota(cows, cows + n, 0);

	for (int i = 0; i < m; i++) {
		int x, y; in >> x >> y;
		reverse(cows + x - 1, cows + y);
	}

	for (int i = 0; i < n; i++)
		a[cows[i]] = i;

	for (int i = 0; i < n; i++) {
		if (!v[i]) {
			b.clear();
			dfs(i);

			int idx = 0;
			for (int i : b)
				ans[b[((idx++) + k) % b.size()]] = i + 1;
		}
	}

	for (int i = 0; i < n; i++)
		out << ans[i] << "\n";
}
