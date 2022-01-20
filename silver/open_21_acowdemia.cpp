#include<algorithm>
#include<iostream>

using namespace std;

typedef long long ll;

int n, k, l, c[100000];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> k >> l;

	for (int i = 0; i < n; i++)
		cin >> c[i];

	sort(c, c + n, greater<int>());

	int low = 0, high = n;
	while (low < high) {
		int mid = (low + high + 1) / 2;

		ll cnt = 0;
		for (int i = 0; i < mid; i++)
			cnt += max(0, mid - c[i]);

		if (cnt <= (ll)k * l && c[mid - 1] + k >= mid) low = mid;
		else high = mid - 1;
	}

	cout << low << "\n";
}
