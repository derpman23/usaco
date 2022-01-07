#include<fstream>

using namespace std;

ifstream in("perimeter.in");
ofstream out("perimeter.out");

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int n, g[1000][1000], v[1000][1000], area, perimeter, maxa = 0, maxp = 0;

void dfs(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= n || !g[x][y]) {
		perimeter++;
		return;
	}
	if (v[x][y]) return;
	v[x][y] = 1;

	area++;
	for (int i = 0; i < 4; i++)
		dfs(x + dx[i], y + dy[i]);
}

int main() {
	in >> n;

	for (int i = 0; i < n; i++) {
		string s;
		in >> s;

		for (int j = 0; j < n; j++)
			g[i][j] = s[j] == '#';
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!v[i][j] && g[i][j]) {
				area = 0, perimeter = 0;
				dfs(i, j);
				if (area > maxa) {
					maxa = area;
					maxp = perimeter;
				}
				else if (area == maxa) maxp = min(maxp, perimeter);
			}
		}
	}

	out << maxa << " " << maxp << "\n";
}
