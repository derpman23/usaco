#include<algorithm>
#include<fstream>

using namespace std;

ifstream in("angry.in");
ofstream out("angry.out");

int n, k, x[50000];

int works(int r) {
	int used = 0, prev = 0;

	while (prev < n) {
		used++;
		int cur = prev + 1;

		while (cur < n && x[cur] - x[prev] <= 2 * r)
			cur++;

		prev = cur;
	}

	return used <= k;
}

int main() {
	in >> n >> k;

	for (int i = 0; i < n; i++)
		in >> x[i];

	sort(x, x + n);

	int low = 0, high = 500000000;

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
