#include<iostream>
#include<stack>

using namespace std;

int n, pos[200001], p[200001], ans[200001];

stack<int> stk;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		pos[a] = i;
	}

	for (int i = n; i > 0; i--) {
		while (!stk.empty() && stk.top() > pos[i])
			stk.pop();
		if (!stk.empty()) p[pos[i]] = stk.top();
		stk.push(pos[i]);
	}

	while (!stk.empty())
		stk.pop();

	int cnt = 0;
	cout << "0\n";
	for (int i = 1; i <= n; i++) {
		while (!stk.empty() && stk.top() > pos[i]) {
			cnt -= ans[stk.top()];
			stk.pop();
		}
		ans[pos[i]] = (stk.empty() || p[pos[i]] != p[stk.top()]) && p[pos[i]];
		stk.push(pos[i]);
		cnt += ans[pos[i]];
		cout << cnt << "\n";
	}
}
