#include<algorithm>
#include<iostream>
#include<set>
#include<vector>

using namespace std;

int n, k;

set<int> s;

vector<int> v;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		s.insert(a / 12 + 1);
	}

	int ans = *s.rbegin(), prev = 0;

	for (int i : s) {
		v.push_back(i - prev - 1);
		prev = i;
	}

	sort(v.rbegin(), v.rend());

	for (int i = 0; i < k - 1 && i < v.size(); i++)
		ans -= v[i];

	cout << ans * 12 << "\n";
}
