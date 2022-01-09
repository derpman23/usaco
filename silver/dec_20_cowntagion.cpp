#include<cmath>
#include<iostream>

using namespace std;

int n, cnt[100000], ans = 0;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		cnt[a]++, cnt[b]++;
	}

	cnt[0]++;

	for (int i = 0; i < n; i++)
		if (!i || cnt[i] > 1)
			ans += ceil(log2(cnt[i]));

	cout << ans + n - 1 << "\n";
}
