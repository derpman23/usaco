#include<fstream>
#include<queue>

using namespace std;

ifstream in("shuffle.in");
ofstream out("shuffle.out");

int n, a[100000], p[100000];

queue<int> q;

int main() {
	in >> n;

	for (int i = 0; i < n; i++) {
		in >> a[i];
		a[i]--;
		p[a[i]]++;
	}

	for (int i = 0; i < n; i++)
		if (!p[i])
			q.push(i);

	int ans = n;
	while (!q.empty()) {
		int first = q.front();
		q.pop();
		ans--;

		if (!--p[a[first]]) q.push(a[first]);
	}

	out << ans << "\n";
}
