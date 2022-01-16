#include<iostream>

using namespace std;

int n;

string s;

long long ans = 0;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> s;

	for (int i = 0; i < n; i++) {
		int i1 = i - 1, i2 = i + 1;
		long long c1 = 0, c2 = 0;
		while (i1 >= 0 && s[i1--] != s[i])
			c1++;
		while (i2 < n && s[i2++] != s[i])
			c2++;

		ans += c1 * c2 + max(0LL, c1 - 1) + max(0LL, c2 - 1);
	}

	cout << ans << "\n";
}
