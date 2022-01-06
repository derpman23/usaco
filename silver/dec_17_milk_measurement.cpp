#include<algorithm>
#include<fstream>
#include<map>

using namespace std;

ifstream in("measurement.in");
ofstream out("measurement.out");

struct entry {
	int day, i, change;

	int operator<(entry e) {
		return day < e.day;
	}
} e[100000];

int n, g, ans = 0;

map<int, int> output;
map<int, int, greater<int>> cnt;

int main() {
	in >> n >> g;

	for (int i = 0; i < n; i++)
		in >> e[i].day >> e[i].i >> e[i].change;

	sort(e, e + n);

	cnt[0] = n + 1;

	for (int i = 0; i < n; i++) {
		int& cur = output[e[i].i];
		int top = cur == cnt.begin()->first, prev = cnt[cur]--;

		if (prev == 1) cnt.erase(cur);

		cur += e[i].change;
		cnt[cur]++;

		if (top) {
			if (cur != cnt.begin()->first || cnt[cur] != 1 || prev != 1) ans++;
		}
		else if (cur == cnt.begin()->first) ans++;
	}

	out << ans << "\n";
}
