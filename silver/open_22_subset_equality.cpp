#include<iostream>

using namespace std;

string s, t;

int fs[26], ft[26], works[26][26], q;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> s >> t >> q;

	for (int i = 0; i < s.size(); i++) {
		fs[s[i] - 'a']++;
		ft[t[i] - 'a']++;
	}

	for (int i = 'a'; i <= 'z'; i++) {
		for (int j = 'a'; j < i; j++) {
			string a = "", b = "";

			for (char c : s)
				if (c == i || c == j)
					a += c;
			for (char c : t)
				if (c == i || c == j)
					b += c;

			works[i - 'a'][j - 'a'] = a == b;
		}
	}

	while (q--) {
		string sub; cin >> sub;

		int ss = 0, st = 0;
		for (char c : sub)
			ss += fs[c - 'a'], st += ft[c - 'a'];

		if (ss != st) goto ok;

		for (int i = 0; i < sub.length(); i++)
			for (int j = 0; j < i; j++)
				if (!works[sub[i] - 'a'][sub[j] - 'a'])
					goto ok;
		cout << 'Y'; continue;
		ok:cout << 'N';
	}

	cout << "\n";
}
