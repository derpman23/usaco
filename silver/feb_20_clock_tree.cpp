#include<fstream>
#include<vector>

using namespace std;

ifstream in("clocktree.in");
ofstream out("clocktree.out");

int n, clocks[2500], depth[2500], s0 = 0, s1 = 0, even = 0, odd = 0;

vector<int> adj[2500];

void dfs(int r, int p, int d) {
	depth[r] = d;

	for (int i : adj[r])
		if (i != p)
			dfs(i, r, d + 1);
}

int main() {
	in >> n;

	for (int i = 0; i < n; i++)
		in >> clocks[i];

	for (int i = 0; i < n - 1; i++) {
		int a, b;
		in >> a >> b;
		a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(0, -1, 0);

	for (int i = 0; i < n; i++) {
		if (depth[i] % 2) s1 += clocks[i], odd++;
		else s0 += clocks[i], even++;
	}

	if (s0 % 12 == s1 % 12) out << n << "\n";
	else if ((s0 + 1) % 12 == s1 % 12) out << odd << "\n";
	else if (s0 % 12 == (s1 + 1) % 12) out << even << "\n";
	else out << "0\n";
}
