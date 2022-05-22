#include<fstream>
#include<vector>

using namespace std;

ifstream in("dishes.in");
ofstream out("dishes.out");

int n, b[100000];

vector<int> s[100000];

int main() {
	in >> n;

	int placed = 0;
	for (int i = 0; i < n; i++) {
		int x; in >> x;

		if (x < placed) { out << i << "\n"; return 0; }

		for (int j = x; j && !b[j]; j--)
			b[j] = x;

		while (!s[b[x]].empty() && s[b[x]].back() < x) {
			placed = s[b[x]].back();
			s[b[x]].pop_back();
		}

		s[b[x]].push_back(x);
	}

	out << n << '\n';
}
