#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

int n, v[100000], idx[100000];

vector<int> adj[100000], ts;

void dfs(int i) {
	v[i] = 1;
	for (int j : adj[i])
		if (!v[j])
			dfs(j);
	ts.push_back(i);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		adj[a - 1].push_back(b - 1);
	}

	for (int i = 0; i < n; i++)
		if (!v[i])
			dfs(i);

	reverse(ts.begin(), ts.end());

	for (int i = 0; i < n; i++)
		idx[ts[i]] = i;

	for (int i = 0; i < n; i++) {
		for (int j : adj[i]) {
			if (idx[j] <= idx[i]) {
				cout << "-1\n";
				return 0;
			}
		}
	}
	
	for (int i : ts)
		cout << i + 1 << "\n";
}
