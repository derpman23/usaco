#include<iostream>

using namespace std;

string s;

int q, pref[200001];

int toint(char c) {
	if (c == 'C') return 1;
	if (c == 'O') return 2;
	return 3;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> s >> q;

	for (int i = 1; i <= s.length(); i++)
		pref[i] = pref[i - 1] ^ toint(s[i - 1]);

	while (q--) {
		int l, r; cin >> l >> r;
		cout << ((pref[l - 1] ^ pref[r]) == 1 ? 'Y' : 'N');
	}

	cout << "\n";
}
