#include<algorithm>
#include<fstream>
#include<set>

using namespace std;

ifstream in("lifeguards.in");
ofstream out("lifeguards.out");

struct state {
	int t, i;

	int operator<(state s) {
		return t < s.t;
	}
} states[200000];

int n, cover[100000], total = 0, cur = 0, ans = 0;

set<int> working;

int main() {
	in >> n;

	for (int i = 0; i < n; i++) {
		int a, b;
		in >> a >> b;
		states[2 * i] = { a, i };
		states[2 * i + 1] = { b, i };
	}

	sort(states, states + 2 * n);

	for (int i = 0; i < n * 2; i++) {
		state s = states[i];

		if (!working.empty()) total += s.t - cur;
		if (working.size() == 1) cover[*working.begin()] += s.t - cur;

		auto it = working.find(s.i);
		if (it == working.end()) working.insert(s.i);
		else working.erase(it);

		cur = s.t;
	}

	for (int i = 0; i < n; i++)
		ans = max(ans, total - cover[i]);

	out << ans << "\n";
}
