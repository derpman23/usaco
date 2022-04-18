#include<iostream>
#include<set>

using namespace std;

int n;

set<string> works;

string s[4], a;

void add(int mask, string x) {
	works.insert(x);
	for (int i = 0; i < 4; i++)
		if (!(mask & (1 << i)))
			for (char c : s[i])
				add(mask | (1 << i), x + c);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 0; i < 4; i++)
		cin >> s[i];

	add(0, "");

	while (n--) {
		cin >> a;
		if (works.find(a) == works.end()) cout << "NO\n";
		else cout << "YES\n";
	}
}
