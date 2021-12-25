#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

pii a[400000];

int k, m, n, f[200000], idx = 0;

int cpr(pii p1, pii p2) {
	return p1.first < p2.first;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> k >> m >> n;

	for (int i = 0; i < k; i++)
		cin >> a[i].first >> a[i].second;

	for (int i = k; i < k + m; i++) {
		cin >> a[i].first;
		a[i].second = -1;
	}

	sort(a, a + k + m, cpr);

	int prev = -1;
	ll sum = 0;
	vector<ll> tastiness;

	for (int i = 0; i < k + m; i++) {
		if (a[i].second != -1) sum += a[i].second;
		else {
			if (prev == -1) tastiness.push_back(sum);
			else {
				ll cur = 0, best = 0;

				for (int j = prev + 1, idx = prev + 1; j < i; j++) {
					while (idx < i && 2 * (a[idx].first - a[j].first) < a[i].first - a[prev].first)
						cur += a[idx++].second;

					best = max(best, cur);
					cur -= a[j].second;
				}

				tastiness.push_back(best);
				tastiness.push_back(sum - best);
			}

			prev = i;
			sum = 0;
		}
	}

	tastiness.push_back(sum);

	sort(tastiness.begin(), tastiness.end(), greater<int>());

	ll ans = 0;

	for (int i = 0; i < n; i++)
		ans += tastiness[i];

	cout << ans << "\n";
}
