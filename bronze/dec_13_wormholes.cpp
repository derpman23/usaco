#include<algorithm>
#include<fstream>

using namespace std;

struct wormhole {
	int x, y, next = -1, dest = -1;

	int operator<(wormhole w) {
		return y == w.y ? x < w.x : y < w.y;
	}
};

int n, ans = 0;

wormhole wormholes[13];

int works() {
	for (int i = 0; i < n; i++) {
		int b = 1;
		auto cur = wormholes[i];

		for (int j = 0; j < n; j++) {
			cur = wormholes[cur.dest];

			if (cur.next != -1) {
				cur = wormholes[cur.next];
				continue;
			}

			b = 0;
			break;
		}

		if (b) return 1;
	}

	return 0;
}

void dfs(int d) {
	if (d == n - 1)
		ans += works();

	if (wormholes[d].dest != -1)
		return dfs(d + 1);

	for (int i = d + 1; i < n; i++) {
		if (wormholes[i].dest != -1)
			continue;

		wormholes[i].dest = d;
		wormholes[d].dest = i;
		dfs(d + 1);
		wormholes[i].dest = -1;
		wormholes[d].dest = -1;
	}
}

int main() {
	ifstream in("wormhole.in");
	ofstream out("wormhole.out");

	in >> n;

	for (int i = 0; i < n; i++)
		in >> wormholes[i].x >> wormholes[i].y;

	sort(wormholes, wormholes + n);

	for (int i = 0; i < n - 1; i++)
		if (wormholes[i].y == wormholes[i + 1].y)
			wormholes[i].next = i + 1;

	dfs(0);

	out << ans << "\n";
}
