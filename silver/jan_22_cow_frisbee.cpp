#include<algorithm>
#include<iostream>
#include<stack>

using namespace std;

int n, h[300000];

long long ans = 0;

void get_distances() {
	stack<int> stk;
	for (int i = n - 1; i >= 0; i--) {
		while (!stk.empty() && h[i] > h[stk.top()])
			stk.pop();
		if (!stk.empty()) ans += stk.top() - i + 1;
		stk.push(i);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> h[i];

	get_distances();
	reverse(h, h + n);
	get_distances();

	cout << ans << "\n";
}
