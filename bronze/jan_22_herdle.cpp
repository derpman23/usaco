#include<iostream>

using namespace std;

string a = "", b = "";

int green = 0, yellow = 0, af[26], bf[26];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	for (int i = 0; i < 3; i++) {
		string s; cin >> s;
		a += s;
	}

	for (int i = 0; i < 3; i++) {
		string s; cin >> s;
		b += s;
	}

	for (int i = 0; i < 9; i++) {
		if (a[i] == b[i]) green++;
		else af[a[i] - 'A']++, bf[b[i] - 'A']++;
	}
	for (int i = 0; i < 26; i++)
		yellow += min(af[i], bf[i]);

	cout << green << "\n" << yellow << "\n";
}
