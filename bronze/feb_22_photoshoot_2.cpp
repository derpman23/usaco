#include<iostream>

using namespace std;

int n, a[100000], b[100000], ans = 0, j = 0, moved[100001];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];

	for (int i = 0; i < n; i++) {
		while (moved[a[j]]) j++;
		if (a[j] == b[i]) j++;
		else ans++, moved[b[i]] = 1;
	}

	cout << ans << '\n';
}
