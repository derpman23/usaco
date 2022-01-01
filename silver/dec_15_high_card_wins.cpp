#include<algorithm>
#include<fstream>
#include<vector>

using namespace std;

ifstream in("highcard.in");
ofstream out("highcard.out");

int n, cards[100000], ans = 0, idx = 0;

vector<int> b, e;

int main() {
	in >> n;

	for (int i = 0; i < n; i++) {
		int a;
		in >> a;
		a--;
		cards[a] = 1;
		e.push_back(a);
	}

	sort(e.begin(), e.end());

	for (int i = 0; i < 2 * n; i++)
		if (!cards[i])
			b.push_back(i);

	for (int i = 0; i < n; i++)
		if (b[i] > e[ans])
			ans++;

	out << ans << "\n";
}
