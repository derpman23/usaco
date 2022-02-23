#include<cstring>
#include<iostream>
#include<queue>
#include<vector>

using namespace std;

typedef pair<int, int> pii;

int n, e, len[50000], v[50000], ans = 0;

vector<pii> adj[50000];

priority_queue<pii, vector<pii>, greater<pii>> q;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> e;

	for (int i = 0; i < e; i++) {
		int a, b, w; cin >> a >> b >> w;
		adj[--a].push_back({ --b, w });
		adj[b].push_back({ a, w });
	}

	memset(len, 127, sizeof len);
	len[0] = 0;

	q.push({ 0, 0 });
	while (!q.empty()) {
		int dist = q.top().first;
		int cur = q.top().second;
		q.pop();

		if (v[cur]) continue;
		if (dist > len[cur]) continue;

		for (pii p : adj[cur]) {
			if (p.second < len[p.first] && !v[p.first]) {
				len[p.first] = p.second;
				q.push({ len[p.first], p.first });
			}
		}

		v[cur] = 1;
	}

	for (int i = 0; i < n; i++)
		ans += len[i];

	cout << ans << "\n";
}