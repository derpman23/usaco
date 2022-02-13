#include<cstring>
#include<fstream>
#include<map>
#include<queue>
#include<vector>

using namespace std;

typedef pair<int, int> pii;

ifstream in("lasers.in");
ofstream out("lasers.out");

int n, len[100002];

pii mirrors[100002];

map<pii, vector<int>> mp;

queue<pii> q;

int main() {
	in >> n;

	for (int i = 0; i < n + 2; i++) {
		in >> mirrors[i].first >> mirrors[i].second;
		mp[{ mirrors[i].first, 0 }].push_back(i);
		mp[{ mirrors[i].second, 1 }].push_back(i);
	}

	q.push({ 0, 0 });
	q.push({ 0, 1 });

	memset(len, 127, sizeof(len));
	len[0] = 0;

	while (!q.empty()) {
		int point = q.front().first, dir = q.front().second;
		q.pop();
		int coord = dir ? mirrors[point].second : mirrors[point].first;

		for (int i : mp[{ coord, dir }]) {
			if (len[i] == 0x7f7f7f7f) {
				q.push({ i, !dir });
				len[i] = len[point] + 1;
			}
		}
	}

	if (len[1] == 0x7f7f7f7f) out << "-1\n";
	else out << len[1] - 1 << "\n";
}
