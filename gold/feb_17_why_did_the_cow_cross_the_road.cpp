#include<cstring>
#include<fstream>
#include<queue>
#include<vector>

using namespace std;

ifstream in("visitfj.in");
ofstream out("visitfj.out");

struct edge {
	int a, b, w;

	friend int operator>(edge e1, edge e2) {
		return e1.w > e2.w;
	}
};

const int dx[16] = { 0, 1, 2, 3, 0, 1, 2, -1, -2, -3, -1, -2, 1, -1, 0, 0 };
const int dy[16] = { 3, 2, 1, 0, -3, -2, -1, 2, 1, 0, -2, -1, 0, 0, 1, -1 };

int n, t, g[100][100], len[100][100];

priority_queue<edge, vector<edge>, greater<edge>> q;

int main() {
	in >> n >> t;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			in >> g[i][j];

	memset(len, 127, sizeof len);

	q.push({ 0, 0, 0 });
	while (!q.empty()) {
		edge e = q.top();
		q.pop();

		int d = n * 2 - 2 - e.a - e.b;
		if (d > 0 && d < 3) len[n - 1][n - 1] = min(len[n - 1][n - 1], e.w + t * d);

		for (int i = 0; i < 16; i++) {
			int x = e.a + dx[i];
			int y = e.b + dy[i];
			if (x < 0 || x >= n || y < 0 || y >= n) continue;

			int w = e.w + g[x][y] + t * 3;
			if (w > len[x][y]) continue;

			len[x][y] = w;

			q.push({ x, y, w });
		}
	}

	out << len[n - 1][n - 1] << "\n";
}
