#include<algorithm>
#include<iostream>
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

int n, ans[1000], stopped[1000];

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

	for (cow nc : north) {
		for (cow ec : east) {
			if (stopped[ec.i] || nc.x < ec.x || nc.y > ec.y) continue;
			int dx = nc.x - ec.x, dy = ec.y - nc.y;

			if (dx > dy) {
				stopped[ec.i] = 1;
				ans[nc.i] += ans[ec.i] + 1;
			}
			else if (dx < dy) {
				stopped[nc.i] = 1;
				ans[ec.i] += ans[nc.i] + 1;
				break;
			}
		}
	}

	for (int i = 0; i < n; i++)
		cout << ans[i] << "\n";
}
