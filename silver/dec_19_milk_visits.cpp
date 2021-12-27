#include<fstream>
#include<queue>
#include<vector>

using namespace std;

int n, m, c[100000], cnt = 0;
string s;

vector<int> adj[100000];

queue<int> q;

int main() {
	ifstream in("milkvisits.in");
	ofstream out("milkvisits.out");
	in >> n >> m >> s;

	for (int i = 0; i < n - 1; i++) {
		int a, b;
		in >> a >> b;
		a--; b--;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for (int i = 0; i < n; i++) {
		if (c[i]) continue;

		cnt++;
		q.push(i);
		while (!q.empty()) {
			int a = q.front();
			q.pop();

			if (c[a]) continue;
			c[a] = cnt;

			for (int n : adj[a])
				if (s[n] == s[a])
					q.push(n);
		}
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		char ch;
		in >> a >> b >> ch;
		a--; b--;
		out << (c[a] != c[b] || s[a] == ch);
	}

	out << "\n";
}
