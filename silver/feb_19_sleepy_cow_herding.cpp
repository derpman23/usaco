#include<algorithm>
#include<fstream>

using namespace std;

ifstream in("herding.in");
ofstream out("herding.out");

int n, cows[100000], ans = 100000;

int main() {
	in >> n;

	for (int i = 0; i < n; i++)
		in >> cows[i];

	sort(cows, cows + n);

	if (cows[n - 1] - cows[1] == n - 2 && cows[1] - cows[0] > 2 || cows[n - 2] - cows[0] == n - 2 && cows[n - 1] - cows[n - 2] > 2) ans = 2;
	else {
		for (int i = 0, j = 0; i < n; i++) {
			while (j < n - 1 && cows[j + 1] - cows[i] <= n - 1) j++;
			ans = min(ans, n + i - j - 1);
		}
	}

	out << ans << "\n" << max(cows[n - 1] - cows[1], cows[n - 2] - cows[0]) - n + 2 << "\n";
}
