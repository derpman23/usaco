#include<cstring>
#include<iostream>

using namespace std;

int n, m, dist[500][500];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;

	memset(dist, 127, sizeof dist);

	for (int i = 0; i < m; i++) {
		int a, b, w; cin >> a >> b >> w;
		dist[--a][--b] = w;
	}

	for (int i = 0; i < n; i++)
		dist[i][i] = 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << j;
			if (j != n - 1) cout << " ";
		}
		cout << "\n";
	}
}
