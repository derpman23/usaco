#include<algorithm>
#include<fstream>

using namespace std;

ifstream cin("nocross.in");
ofstream cout("nocross.out");

int n, a[1000], b[1000], dp[1000][1000];

int main() {
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];

	dp[0][0] = abs(a[0] - b[0]) <= 4;
	for (int i = 1; i < n; i++)
    		dp[i][0] = dp[i - 1][0] || abs(a[i] - b[0]) <= 4;
	for (int i = 1; i < n; i++)
    		dp[0][i] = dp[0][i - 1] || abs(a[0] - b[i]) <= 4;
	for (int i = 1; i < n; i++)
		for (int j = 1; j < n; j++)
			dp[i][j] = max({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] + (abs(a[i] - b[j]) <= 4) });

	cout << dp[n - 1][n - 1];
}
