#include<cstring>
#include<iostream>
#include<queue>
#include<vector>

using namespace std;

typedef pair<int, int> pii;

priority_queue<pii, vector<pii>, greater<pii>> q;

int v, e, s, len[50000];

vector<pii> adj[50000];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> v >> e >> s;

	for (int i = 0; i < e; i++) {
		int a, b, w; cin >> a >> b >> w;
		adj[--a].push_back({ --b, w });
		adj[b].push_back({ a, w });
	}

	memset(len, 127, sizeof len);
	len[--s] = 0;

	q.push({ 0, s });
	while (!q.empty()) {
		int dist = q.top().first;
		int cur = q.top().second;
		q.pop();

		if (len[cur] < dist) continue;

		for (pii p : adj[cur]) {
			if (len[cur] + p.second < len[p.first]) {
				len[p.first] = len[cur] + p.second;
				q.push({ len[p.first], p.first });
			}
		}
	}

	for (int i = 0; i < v; i++) {
		if (len[i] == 0x7f7f7f7f) cout << "-1\n";
		else cout << len[i] << "\n";
	}
}