#include<fstream>

using namespace std;

ifstream in("teamwork.in");
ofstream out("teamwork.out");

int n, k, s[10000], dp[10000];

int main() {
	in >> n >> k;

	for (int i = 0; i < n; i++)
		in >> s[i];

	dp[0] = s[0];

	for (int i = 1; i < n; i++) {
		int best = s[i];
		for (int j = i; j >= 0 && i - j + 1 <= k; j--) {
			best = max(best, s[j]);
			
			if (!j) dp[i] = max(dp[i], (i + 1) * best);
			else dp[i] = max(dp[i], dp[j - 1] + (i - j + 1) * best);
		}
	}

	out << dp[n - 1] << "\n";
}
