#include<iostream>

using namespace std;

int n, cows[500][500], works[500][500];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = n; j > 0; j--) {
			int g; cin >> g;
			cows[i][--g] = j;
		}
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (cows[i][j] >= cows[i][i])
				works[j][i] = 1;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				works[j][k] |= works[j][i] & works[i][k];

	for (int i = 0; i < n; i++) {
		int ans = -1;
		for (int j = 0; j < n; j++)
			if (works[i][j] && (ans == -1 || cows[i][j] > cows[i][ans]))
				ans = j;
		cout << ans + 1 << "\n";
	}
}
