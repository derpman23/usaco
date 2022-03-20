#include<algorithm>
#include<fstream>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ifstream in("walk.in");
ofstream out("walk.out");

const ll MOD = 2019201997LL;

int n, k, v[7500];

ll len[7500];

int main() {
	in >> n >> k;

	for (int i = 0; i < n; i++)
		len[i] = MOD;

	for (int i = 0; i < n; i++) {
		int idx = -1;
		for (int j = 0; j < n; j++)
			if (!v[j] && (idx == -1 || len[j] < len[idx]))
				idx = j;
		if (idx != -1) v[idx] = 1;

		for (int j = 0; j < n; j++)
			if (!v[j])
				len[j] = min(len[j], (2019201913LL * min(idx, j) + 2019201949LL * max(idx, j)) % MOD);
	}

	sort(len, len + n);
	out << len[n - k] << "\n";
}
