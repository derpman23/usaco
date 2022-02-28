#include<fstream>
#include<queue>
#include<vector>

using namespace std;

typedef pair<int, int> pii;

ifstream in("timeline.in");
ofstream out("timeline.out");

int n, m, c, ans[100000], cnt[100000];

vector<pii> adj[100000];

queue<int> q;

int main() {
	in >> n >> m >> c;

	for (int i = 0; i < n; i++)
		in >> ans[i];

	for (int i = 0; i < c; i++) {
		int a, b, x; in >> a >> b >> x;
		adj[--a].push_back({ --b, x });
		cnt[b]++;
	}

	for (int i = 0; i < n; i++)
		if (!cnt[i])
			q.push(i);

	while (!q.empty()) {
		int i = q.front();
		q.pop();

		for (pii p : adj[i]) {
			ans[p.first] = max(ans[p.first], ans[i] + p.second);
			if (!--cnt[p.first]) q.push(p.first);
		}
	}

	for (int i = 0; i < n; i++)
		out << ans[i] << "\n";
}
