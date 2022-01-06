#include<algorithm>
#include<fstream>

using namespace std;

typedef pair<int, int> pii;

ifstream in("pairup.in");
ofstream out("pairup.out");

int n, ans = 0;

pii p[100000];

int main() {
	in >> n;

	for (int i = 0; i < n; i++)
		in >> p[i].second >> p[i].first;

	sort(p, p + n);

	int i1 = 0, i2 = n - 1;

	while (i1 < i2) {
		int cows = min(p[i1].second, p[i2].second);
		ans = max(ans, p[i1].first + p[i2].first);

		p[i1].second -= cows;
		p[i2].second -= cows;
		if (!p[i1].second) i1++;
		if (!p[i2].second) i2--;
	}

	if (i1 == i2) ans = max(ans, p[i1].first * 2);

	out << ans << "\n";
}
