#include<algorithm>
#include<fstream>

using namespace std;

ifstream in("stacking.in");
ofstream out("stacking.out");

int n, k, dp[1000001];

int main() {
	in >> n >> k;

	for (int i = 0; i < k; i++) {
		int a, b;
		in >> a >> b;
		dp[a - 1]++;
		dp[b]--;
	}

	for (int i = 0; i < n; i++)
		dp[i + 1] += dp[i];

	sort(dp, dp + n);

	out << dp[n / 2] << "\n";
}
