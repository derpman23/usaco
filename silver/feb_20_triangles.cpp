#include<algorithm>
#include<fstream>
#include<vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ifstream in("triangles.in");
ofstream out("triangles.out");

const int MOD = (int)1e9 + 7;

int n;

pii posts[100000];

vector<pii> x[20001], y[20001];

ll base[100000], height[100000];

int main() {
	in >> n;

	for (int i = 0; i < n; i++) {
		in >> posts[i].first >> posts[i].second;
		x[posts[i].first + 10000].push_back({ posts[i].second, i });
		y[posts[i].second + 10000].push_back({ posts[i].first, i });
	}

	for (int i = 0; i <= 20000; i++) {
		if (!x[i].empty()) {
			sort(x[i].begin(), x[i].end());

			ll sum = 0;

			for (int j = 1; j < x[i].size(); j++)
				sum += x[i][j].first - x[i][0].first;

			height[x[i][0].second] = sum;

			for (int j = 1; j < x[i].size(); j++) {
				sum += (2 * j - x[i].size()) * (x[i][j].first - x[i][j - 1].first);
				height[x[i][j].second] = sum;
			}
		}

		if (!y[i].empty()) {
			sort(y[i].begin(), y[i].end());

			ll sum = 0;

			for (int j = 1; j < y[i].size(); j++)
				sum += y[i][j].first - y[i][0].first;

			base[y[i][0].second] = sum;

			for (int j = 1; j < y[i].size(); j++) {
				sum += (2 * j - y[i].size()) * (y[i][j].first - y[i][j - 1].first);
				base[y[i][j].second] = sum;
			}
		}
	}

	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ans += (base[i] * height[i]) % MOD;
		ans %= MOD;
	}

	out << ans << "\n";
}
