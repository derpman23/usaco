#include<cstring>
#include<deque>
#include<iostream>
#include<stack>

using namespace std;

int t, n, m, k, emails[100000], cnt[10000], filed[100000];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> t;
	while (t--) {
		cin >> n >> m >> k;

		for (int i = 0; i < n; i++) {
			cin >> emails[i];
			cnt[--emails[i]]++;
		}

		memset(filed, 0, sizeof filed);

		stack<int> stk;
		deque<int> dq;

		int first = 0;
		for (int i = 0; i < n; i++) {
			if (emails[i] < first + k) {
				filed[i] = 1;
				cnt[emails[i]]--;

				if (!cnt[first]) {
					while (first < m && !cnt[first])
						first++;

					deque<int> tmp;
					while (!dq.empty()) {
						int j = dq.front();
						dq.pop_front();

						if (emails[j] < first + k) {
							filed[j] = 1;
							cnt[emails[j]]--;
						}
						else tmp.push_back(j);
					}

					dq = tmp;
				}
			}
			else {
				if (dq.size() == k) {
					int j = dq.front();
					dq.pop_front();
					stk.push(j);
				}
				dq.push_back(i);
			}
		}

		while (first < m && !cnt[first])
			first++;

		while (!stk.empty() && dq.size() < k) {
			int i = stk.top();
			stk.pop();

			if (emails[i] < first + k) {
				filed[i] = 1;
				cnt[emails[i]]--;

				if (!cnt[first]) {
					while (first < m && !cnt[first])
						first++;

					deque<int> tmp;
					while (!dq.empty()) {
						int j = dq.front();
						dq.pop_front();

						if (emails[j] < first + k) {
							filed[j] = 1;
							cnt[emails[j]]--;
						}
						else tmp.push_back(j);
					}
				}
			}
			else dq.push_front(i);
		}

		if (dq.empty() && stk.empty()) cout << "YES\n";
		else cout << "NO\n";
	}
}
