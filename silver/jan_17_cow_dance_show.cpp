#include<fstream>
#include<queue>

using namespace std;

ifstream in("cowdance.in");
ofstream out("cowdance.out");

int n, tmax, d[10000];

int works(int k) {
	priority_queue<int, vector<int>, greater<int>> q;

	for (int i = 0; i < k; i++)
		q.push(d[i]);

	int idx = k, time = 0;

	while (!q.empty()) {
		time += max(0, q.top() - time);
		q.pop();

		if (idx < n) {
			q.push(time + d[idx]);
			idx++;
		}
	}

	return time <= tmax;
}

int main() {
	in >> n >> tmax;

	for (int i = 0; i < n; i++)
		in >> d[i];

	int low = 0, high = 10000;

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
