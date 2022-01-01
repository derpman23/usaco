#include<algorithm>
#include<fstream>

using namespace std;

ifstream in("lemonade.in");
ofstream out("lemonade.out");

int n, w[100000], ans = 0;

int main() {
	in >> n;

	for (int i = 0; i < n; i++)
		in >> w[i];

	sort(w, w + n, greater<int>());

	for (int i = 0; i < n; i++) {
		if (w[i] < i) break;
		else ans++;
	}

	out << ans << "\n";
}
