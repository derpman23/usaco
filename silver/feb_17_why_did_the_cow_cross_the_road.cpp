#include<algorithm>
#include<fstream>
#include<set>

using namespace std;

typedef pair<int, int> pii;

int c, n, ans = 0;

multiset<int> t;

pii cows[20000];

int cpr(pii a, pii b) {
	if (a.second == b.second) return a.first < b.first;

	return a.second < b.second;
}

int main() {
	ifstream in("helpcross.in");
	ofstream out("helpcross.out");

	in >> c >> n;

	for (int i = 0; i < c; i++) {
		int a;
		in >> a;
		t.insert(a);
	}

	for (int i = 0; i < n; i++)
		in >> cows[i].first >> cows[i].second;

	sort(cows, cows + n, cpr);

	for (int i = 0; i < n; i++) {
		auto it = t.lower_bound(cows[i].first);

		if (it != t.end() && *it <= cows[i].second) {
			ans++;
			t.erase(it);
		}
	}

	out << ans << "\n";
}
