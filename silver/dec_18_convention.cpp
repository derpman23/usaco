#include<algorithm>
#include<fstream>

using namespace std;

ifstream in("convention.in");
ofstream out("convention.out");

int n, m, c, t[100000];

int works(int w) {
	int cnt = 1, idx = 0;

	for (int i = 1; i < n; i++) {
		if (t[i] - t[idx] > w || i - idx >= c) {
			cnt++;
			idx = i;
		}
	}

	return cnt <= m;
}

int main() {
	in >> n >> m >> c;

	for (int i = 0; i < n; i++)
		in >> t[i];

	sort(t, t + n);

	int low = 0, high = 1000000000;

	while (1) {
		if (low == high) {
			out << low << "\n";
			break;
		}
		if (low == high - 1) {
			if (works(low)) out << low << "\n";
			else out << high << "\n";
			break;
		}

		int mid = (low + high) / 2;

		if (works(mid)) high = mid;
		else low = mid + 1;
	}
}
