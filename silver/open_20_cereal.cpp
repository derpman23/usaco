#include<fstream>

using namespace std;

typedef pair<int, int> pii;

ifstream in("cereal.in");
ofstream out("cereal.out");

int n, m, ans[100000], taken[100000];

pii cows[100000];

int main() {
	in >> n >> m;

	for (int i = 0; i < n; i++)
		in >> cows[i].first >> cows[i].second;

	int cnt = 0;
	for (int i = n - 1; i >= 0; i--) {
		int idx = i;
		int first = cows[i].first;
		while (1) {
			if (!taken[first]) {
				taken[first] = idx;
				cnt++;
				break;
			}
			if (taken[first] < idx) break;

			int a = taken[first];
			taken[first] = idx;
			if (first == cows[a].second) break;
			idx = a;
			first = cows[a].second;
		}
		ans[i] = cnt;
	}

	for (int i = 0; i < n; i++)
		out << ans[i] << "\n";
}
