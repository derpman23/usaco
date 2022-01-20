#include<iostream>
#include<set>
#include<queue>

using namespace std;

struct state {
	int x, y, b;
};

int n, v[25][25][19683], pow3[10] = { 1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683 };

char g[25][25][3];

queue<state> q;

set<int> ans;

int check(int board) {
	int arr[3][3];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			arr[i][j] = board % 3;
			board /= 3;
		}
	}

	for (int i = 0; i < 3; i++) {
		if (arr[i][0] == 2 && arr[i][1] == 1 && arr[i][2] == 1) return 1;
		if (arr[i][0] == 1 && arr[i][1] == 1 && arr[i][2] == 2) return 1;
		if (arr[0][i] == 2 && arr[1][i] == 1 && arr[2][i] == 1) return 1;
		if (arr[0][i] == 1 && arr[1][i] == 1 && arr[2][i] == 2) return 1;
	}

	if (arr[0][0] == 2 && arr[1][1] == 1 && arr[2][2] == 1) return 1;
	if (arr[0][0] == 1 && arr[1][1] == 1 && arr[2][2] == 2) return 1;
	if (arr[2][0] == 2 && arr[1][1] == 1 && arr[0][2] == 1) return 1;
	if (arr[2][0] == 1 && arr[1][1] == 1 && arr[0][2] == 2) return 1;

	return 0;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

#ifdef LOCAL
	FILE* stream;
	freopen_s(&stream, "input.txt", "r", stdin);
	freopen_s(&stream, "output.txt", "w", stdout);
	freopen_s(&stream, "error.txt", "w", stderr);
#endif

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < 3; k++)
				cin >> g[i][j][k];
			if (g[i][j][0] == 'B') q.push({i, j, 0});
		}
	}

	while (!q.empty()) {
		state cur = q.front();
		q.pop();
		int& board = cur.b;
		if (v[cur.x][cur.y][board] || g[cur.x][cur.y][0] == '#') continue;
		v[cur.x][cur.y][board] = 1;

		if (g[cur.x][cur.y][0] == 'M' || g[cur.x][cur.y][0] == 'O') {
			int x = g[cur.x][cur.y][1] - '1', y = g[cur.x][cur.y][2] - '1', idx = x * 3 + y;
			if (!((board / pow3[idx]) % 3)) {
				board += (g[cur.x][cur.y][0] == 'M' ? 2 : 1) * pow3[idx];
				if (!v[cur.x][cur.y][board] && check(board)) { ans.insert(board); continue; }
				v[cur.x][cur.y][board] = 1;
			}
		}

		q.push({ cur.x - 1, cur.y, board });
		q.push({ cur.x + 1, cur.y, board });
		q.push({ cur.x, cur.y - 1, board });
		q.push({ cur.x, cur.y + 1, board });
	}

	cout << ans.size() << "\n";
}
