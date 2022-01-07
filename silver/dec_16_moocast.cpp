#include<cstring>
#include<fstream>
#include<vector>

using namespace std;

ifstream in("moocast.in");
ofstream out("moocast.out");

struct cow {
	int x, y, p;
} cows[200];

int n, v[200], ans = 0;

vector<int> adj[200];

int dfs(int pos) {
	if (v[pos]) return 0;
	v[pos] = 1;
	int res = 0;

	for (int i : adj[pos])
		if (!v[i])
			res += dfs(i) + 1;

	return res;
}

int main() {
	in >> n;

	for (int i = 0; i < n; i++)
		in >> cows[i].x >> cows[i].y >> cows[i].p;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			int dist = (cows[i].x - cows[j].x) * (cows[i].x - cows[j].x) + (cows[i].y - cows[j].y) * (cows[i].y - cows[j].y);
			if (dist <= cows[i].p * cows[i].p) adj[i].push_back(j);
		}
	}

	for (int i = 0; i < n; i++) {
		memset(v, 0, sizeof(int) * n);
		ans = max(ans, dfs(i) + 1);
	}

	out << ans << "\n";
}
