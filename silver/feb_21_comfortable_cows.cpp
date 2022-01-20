#include<iostream>
#include<queue>

using namespace std;

typedef pair<int, int> pii;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int n, g[2001][2001];

queue<pii> q;

void add(int x, int y) {
	if (!g[x][y]) return;

	int cnt = 0;
	pii empty;
	for (int i = 0; i < 4; i++) {
		if (g[x + dx[i]][y + dy[i]])
			cnt++;
		else
			empty = { x + dx[i], y + dy[i] };
	}

	if (cnt == 3) q.push(empty);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;

	int cnt = 0;

	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		x += 500, y += 500;
		q.push({ x, y });
		while (!q.empty()) {
			pii p = q.front();
			q.pop();

			if (g[p.first][p.second]) continue;
			g[p.first][p.second] = 1;
			cnt++;
			add(p.first, p.second);

			for (int i = 0; i < 4; i++)
				add(p.first + dx[i], p.second + dy[i]);
		}

		cout << cnt - i - 1 << "\n";
	}
}
