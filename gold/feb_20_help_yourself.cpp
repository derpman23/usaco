#include<fstream>

using namespace std;

typedef pair<int, int> pii;

ifstream in("help.in");
ofstream out("help.out");

const int MOD = (int)1e9 + 7;

int n, pref[200001], pw[100000], ans = 0;

pii intervals[100000];

int main() {
	in >> n;

	pw[0] = 1;
	for (int i = 1; i < n; i++)
		pw[i] = pw[i - 1] * 2 % MOD;

	for (int i = 0; i < n; i++) {
		in >> intervals[i].first >> intervals[i].second;
		pref[intervals[i].first]++, pref[intervals[i].second]--;
	}

	for (int i = 2; i <= n * 2; i++)
		pref[i] += pref[i - 1];

	for (int i = 0; i < n; i++)
		ans = (ans + pw[n - 1 - pref[intervals[i].first - 1]]) % MOD;

	out << ans << "\n";
}
