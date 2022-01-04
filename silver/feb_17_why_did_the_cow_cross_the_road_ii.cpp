#include<fstream>

using namespace std;

ifstream in("maxcross.in");
ofstream out("maxcross.out");

int n, k, b, s[100001], dp[100001], ans = 100000;

int main() {
	in >> n >> k >> b;

	for (int i = 0; i < n; i++) {
		int a;
		in >> a;
		s[a] = 1;
	}

	for (int i = 1; i <= n; i++)
		dp[i] = dp[i - 1] + s[i];

	for (int i = k; i <= n; i++)
		ans = min(ans, dp[i] - dp[i - k]);

	out << ans << "\n";
}
