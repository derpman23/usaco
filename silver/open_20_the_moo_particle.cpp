#include<algorithm>
#include<fstream>

using namespace std;

ifstream in("moop.in");
ofstream out("moop.out");

struct particle {
	int x, y, i;

	int operator<(particle p) {
		return x == p.x ? y < p.y : x < p.x;
	}
} p[100000];

int n, dpl[100000], dpr[100000], ans = 1;

int main() {
	in >> n;

	for (int i = 0; i < n; i++) {
		in >> p[i].x >> p[i].y;
		p[i].i = i;
	}

	sort(p, p + n);

	dpl[0] = p[0].y;
	for (int i = 1; i < n; i++)
		dpl[i] = min(dpl[i - 1], p[i].y);

	dpr[n - 1] = p[n - 1].y;
	for (int i = n - 2; i >= 0; i--)
		dpr[i] = max(dpr[i + 1], p[i].y);

	for (int i = 0; i < n - 1; i++)
		ans += dpl[i] > dpr[i + 1];

	out << ans << "\n";
}
