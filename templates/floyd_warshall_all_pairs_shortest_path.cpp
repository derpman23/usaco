#include<cstring>
#include<iostream>

using namespace std;

int n, m, len[500][500];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;

	memset(len, 127, sizeof len);

	for (int i = 0; i < m; i++) {
		int a, b, w; cin >> a >> b >> w;
		len[--a][--b] = w;
	}

	for (int i = 0; i < n; i++)
		len[i][i] = 0;
	
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				len[i][j] = min(len[i][j], len[i][k] + len[k][j]);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << j;
			if (j != n - 1) cout << " ";
		}
		cout << "\n";
	}
}
