#include<algorithm>
#include<fstream>
#include<vector>

using namespace std;

ifstream in("measurement.in");
ofstream out("measurement.out");

struct state {
	int day, cow, change;
	
	friend int operator<(state a, state b) {
		return a.day < b.day;
	}
};

int n, milk[3], top[3] = { 1, 1, 1 }, ans = 0;

vector<state> v;

int main() {
	in >> n;

	for (int i = 0; i < n; i++) {
		int d, c; string name; in >> d >> name >> c;
		if (name == "Bessie") v.push_back({ d, 0, c });
		else if (name == "Elsie") v.push_back({ d, 1, c });
		else v.push_back({ d, 2, c });
	}

	sort(v.begin(), v.end());

	for (auto s : v) {
		milk[s.cow] += s.change;
		int mx = max({ milk[0], milk[1], milk[2] });
		int a = milk[0] == mx, b = milk[1] == mx, c = milk[2] == mx;
		if (a ^ top[0] | b ^ top[1] | c ^ top[2]) ans++;
		
		top[0] = a;
		top[1] = b;
		top[2] = c;
	}

	out << ans << "\n";
}
