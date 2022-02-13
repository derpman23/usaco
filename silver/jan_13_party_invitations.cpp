#include<fstream>
#include<queue>
#include<set>
#include<vector>

using namespace std;

ifstream in("invite.in");
ofstream out("invite.out");

set<int> groups[125000], v;

vector<int> adj[1000000];

queue<int> q;

int n, g, ans = 0;

int main() {
	in >> n >> g;

	for (int i = 0; i < g; i++) {
		int sz; in >> sz;
		while (sz--) {
			int a; in >> a;
			groups[i].insert(a);
			adj[a].push_back(i);
		}
	}

	q.push(1);
	while (!q.empty()) {
		int i = q.front();
		q.pop();

		if (v.find(i) != v.end()) continue;
		v.insert(i);
		ans++;

		for (int j : adj[i]) {
			groups[j].erase(i);
			if (groups[j].size() == 1)
				q.push(*groups[j].begin());
		}
	}

	out << ans << "\n";
}
