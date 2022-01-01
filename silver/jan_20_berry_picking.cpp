#include<algorithm>
#include<fstream>

using namespace std;

ifstream in("berries.in");
ofstream out("berries.out");

int n, k, b[1000], i, ans = 0, most = 0;

int cpr(int a, int b) {
	return a % i > b % i;
}

int main() {
	in >> n >> k;

	for (i = 0; i < n; i++) {
		in >> b[i];
		most = max(most, b[i]);
	}

	for (i = 1; i <= most; i++) {
		int sum = 0;

		for (int j = 0; j < n; j++)
			sum += b[j] / i;

		if (sum < k / 2) break;
		else if (sum >= k) {
			ans = max(ans, k / 2 * i);
			continue;
		}

		sort(b, b + n, cpr);

		int cur = i * (sum - k / 2);

		for (int j = 0; j < n; j++) {
			if (j + sum >= k) break;
			else cur += b[j] % i;
		}

		ans = max(ans, cur);
	}

	out << ans << "\n";
}
