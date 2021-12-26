#include<iostream>
#include<set>

using namespace std;

int t, n, x[7];

int check(int a, int b, int c) {
	set<int> s{a, b, c, a + b, b + c, c + a, a + b + c};

	for (int i = 0; i < n; i++)
		if (s.find(x[i]) == s.end())
			return 0;

	return 1;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> t;

	while (t--) {
		cin >> n;

		set<int> s;

		for (int i = 0; i < n; i++) {
			cin >> x[i];
			s.insert(x[i]);
		}

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (x[i] < x[j])
					s.insert(x[j] - x[i]);

		int ans = 0;

		for (int a : s)
			for (int b : s)
				for (int c : s)
					if (a <= b && b <= c && check(a, b, c))
						ans++;

		cout << ans << "\n";
	}
}
