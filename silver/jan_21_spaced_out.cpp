#include<iostream>

using namespace std;

int n, a[1000][1000], cx = 0, cy = 0;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];

	for (int i = 0; i < n; i++) {
		int cnt1 = 0, cnt2 = 0;

		for (int j = 0; j < n; j += 2)
			cnt1 += a[i][j];

		for (int j = 1; j < n; j += 2)
			cnt2 += a[i][j];

		cx += max(cnt1, cnt2);
	}

	for (int i = 0; i < n; i++) {
		int cnt1 = 0, cnt2 = 0;

		for (int j = 0; j < n; j += 2)
			cnt1 += a[j][i];

		for (int j = 1; j < n; j += 2)
			cnt2 += a[j][i];

		cy += max(cnt1, cnt2);
	}

	cout << max(cx, cy) << "\n";
}
