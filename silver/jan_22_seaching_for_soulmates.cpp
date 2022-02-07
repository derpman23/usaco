#include<iostream>

using namespace std;

typedef long long ll;

int t;
ll x, y;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> t;
	while (t--) {
		cin >> x >> y;

		ll ans = 0x3fffffffffffff, cnt = 0;
		while (x != y) {
			if (x > y) {
				if (x % 2) x++;
				else x /= 2;
			}
			else {
				ans = min(ans, cnt + y - x);
				if (y % 2) y--;
				else y /= 2;
			}
			cnt++;
		}
		ans = min(ans, cnt);

		cout << ans << "\n";
	}
}
