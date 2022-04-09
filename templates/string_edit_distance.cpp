#include<cstring>
#include<iostream>

using namespace std;

string s1, s2;

int dp[1002][1002];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> s1 >> s2;

	memset(dp, 127, sizeof dp);
	dp[0][0] = 0;

	for (int i = 0; i <= s1.length(); i++) {
		for (int j = 0; j <= s2.length(); j++) {
			dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
			dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + 1);
			dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + (s1[i] != s2[j]));
		}
	}

	cout << dp[s1.length()][s2.length()] << '\n';
}
