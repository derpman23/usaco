#include<algorithm>
#include<fstream>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ifstream in("socdist.in");
ofstream out("socdist.out");

int n, m;

pll intervals[100000];

int works(ll d) {
	ll cnt = 0, pos = (ll)-1e18;

	for (int i = 0; i < m; i++) {
		if (pos + d > intervals[i].second) continue;

		pos = max(intervals[i].first, pos + d);
		cnt++;

		ll add = (intervals[i].second - pos) / d;
		cnt += add;
		pos += add * d;
	}

	return cnt >= n;
}

int main() {
	in >> n >> m;

	for (int i = 0; i < m; i++)
		in >> intervals[i].first >> intervals[i].second;

	sort(intervals, intervals + m);

	ll l = 0LL, r = (ll)1e18;

	while (l < r) {
		ll mid = (l + r + 1) / 2;

		if (works(mid)) l = mid;
		else r = mid - 1;
	}

	out << l << "\n";
}
