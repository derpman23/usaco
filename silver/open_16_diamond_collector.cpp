#include<algorithm>
#include<fstream>

using namespace std;

ifstream in("diamond.in");
ofstream out("diamond.out");

int n, k, d[50000], a[50000], b[50001], ans = 0;

int main() {
	in >> n >> k;

	for (int i = 0; i < n; i++)
		in >> d[i];

	sort(d, d + n);

	for (int l = 0, r = 0; l < n; l++) {
		while (r < n && d[r] - d[l] <= k)
			r++;
		a[l] = r - l;
	}

	for (int i = n - 1; i >= 0; i--)
		b[i] = max(b[i + 1], a[i]);

	for (int i = 0; i < n; i++)
		ans = max(ans, a[i] + b[a[i] + i]);

	out << ans << "\n";
}
