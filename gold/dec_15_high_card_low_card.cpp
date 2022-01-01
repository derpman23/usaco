#include<algorithm>
#include<fstream>
#include<vector>

using namespace std;

ifstream in("cardgame.in");
ofstream out("cardgame.out");

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

	sort(e.begin(), e.begin() + n / 2);
	sort(e.begin() + n / 2, e.end(), greater<int>());

	for (int i = 0; i < 2 * n; i++)
		if (!cards[i])
			b.push_back(i);

	rotate(b.begin(), b.begin() + n / 2, b.end());
	reverse(b.begin() + n / 2, b.end());

	for (int i = 0; i < n / 2; i++) {
		if (b[i] > e[idx]) {
			idx++;
			ans++;
		}
	}

	idx = n / 2;

	for (int i = n / 2; i < n; i++) {
		if (b[i] < e[idx]) {
			idx++;
			ans++;
		}
	}

	out << ans << "\n";
}
