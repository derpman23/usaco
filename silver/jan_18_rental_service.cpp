#include<algorithm>
#include<fstream>

using namespace std;

typedef long long ll;

ifstream in("rental.in");
ofstream out("rental.out");

int n, m, r, c[100000], rent[100000];

long long ans = 0;

struct offer {
	int q, p;

	int operator<(offer o) {
		return p > o.p;
	}
} offers[100000];

int main() {
	in >> n >> m >> r;

	for (int i = 0; i < n; i++)
		in >> c[i];

	sort(c, c + n, greater<int>());

	for (int i = 0; i < m; i++)
		in >> offers[i].q >> offers[i].p;

	sort(offers, offers + m);

	for (int i = 0; i < r; i++)
		in >> rent[i];

	sort(rent, rent + r, greater<int>());

	int i = 0, j = 0, k = 0;
	while (i < n) {
		int cur = j, profit = 0, prev = 0, milk = c[i];

		while (cur < m) {
			int left = min(milk, offers[cur].q);
			profit += offers[cur].p * left;
			milk -= left;

			if (milk) cur++;
			else {
				prev = left;
				break;
			}
		}

		if (k >= r || profit > rent[k]) {
			j = cur;
			if (j < m) offers[j].q -= prev;
			ans += profit;
			i++;
		}
		else {
			ans += rent[k];
			k++;
			n--;
		}
	}

	out << ans << "\n";
}
