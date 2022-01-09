#include<algorithm>
#include<fstream>
#include<vector>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

ifstream in("reststops.in");
ofstream out("reststops.out");

int l, n, rf, rb;

ll ans = 0;

pii stops[100000];

vector<int> good;

int main() {
	in >> l >> n >> rf >> rb;

	for (int i = 0; i < n; i++)
		in >> stops[i].first >> stops[i].second;

	int high = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (stops[i].second > high) {
			good.push_back(i);
			high = stops[i].second;
		}
	}

	reverse(good.begin(), good.end());

	int prev = 0;

	for (int i : good) {
		ll dist = stops[i].first - prev;
		ll f = dist * rf, b = dist * rb;
		ans += (f - b) * stops[i].second;
		prev = stops[i].first;
	}

	out << ans << "\n";
}
