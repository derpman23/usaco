#include<algorithm>
#include<cstring>
#include<iostream>
#include<string>
#include<vector>

using namespace std;

struct cow {
	int x, y, i;
};

int xcpr(cow c1, cow c2) {
	return c1.x < c2.x;
}

int ycpr(cow c1, cow c2) {
	return c1.y < c2.y;
}

int n, ans[50];

vector<cow> north, east;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		char ch; int x, y; cin >> ch >> x >> y;
		cow c = { x, y, i };
		if (ch == 'N') north.push_back(c);
		else east.push_back(c);
	}

	sort(north.begin(), north.end(), xcpr);
	sort(east.begin(), east.end(), ycpr);

	memset(ans, -1, sizeof(int) * n);

	for (cow nc : north) {
		for (cow ec : east) {
			if (ans[ec.i] != -1 || nc.x < ec.x || nc.y > ec.y) continue;
			int dx = nc.x - ec.x, dy = ec.y - nc.y;
			
			if (dx > dy) ans[ec.i] = dx;
			else if (dx < dy) {
				ans[nc.i] = dy;
				break;
			}
		}
	}

	for (int i = 0; i < n; i++)
		cout << (ans[i] == -1 ? "Infinity" : to_string(ans[i])) << "\n";
}
