#include<iostream>
#include<stack>

using namespace std;

int n, q, l[100001], r[100001];

string s;

stack<char> stk;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> q >> s;

	for (int i = 0; i < n; i++) {
		l[i + 1] = l[i];
		while (!stk.empty() && stk.top() > s[i])
			stk.pop();
		if (stk.empty() || stk.top() < s[i]) {
			stk.push(s[i]);
			l[i + 1]++;
		}
	}

	while (!stk.empty())
		stk.pop();

	for (int i = 0; i < n; i++) {
		r[i + 1] = r[i];
		while (!stk.empty() && stk.top() > s[n - i - 1])
			stk.pop();
		if (stk.empty() || stk.top() < s[n - i - 1]) {
			stk.push(s[n - i - 1]);
			r[i + 1]++;
		}
	}

	while (q--) {
		int x, y; cin >> x >> y;
		cout << l[x - 1] + r[n - y] << "\n";
	}
}
