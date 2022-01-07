#include<algorithm>
#include<fstream>
#include<queue>

using namespace std;

ifstream in("convention2.in");
ofstream out("convention2.out");

struct cow {
	int a, t, s;

	friend int operator<(cow c1, cow c2) {
		return c1.s < c2.s;
	}
} c[100000];

int cpr(cow c1, cow c2) {
	return c1.a < c2.a;
}

int n, ans = 0;

priority_queue<cow> q;

int main() {
	in >> n;

	for (int i = 0; i < n; i++) {
		in >> c[i].a >> c[i].t;
		c[i].s = n - i;
	}

	sort(c, c + n, cpr);

	int idx = 0, t = 0;

	while (idx < n || !q.empty()) {
		if (idx < n && t >= c[idx].a) {
			q.push(c[idx]);
			idx++;
		}
		else if (q.empty()) {
			t = c[idx].a + c[idx].t;
			idx++;
		}
		else {
			cow cur = q.top();
			q.pop();

			ans = max(ans, t - cur.a);
			t += cur.t;
		}
	}

	out << ans << "\n";
}
