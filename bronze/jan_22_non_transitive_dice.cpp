#include<iostream>

using namespace std;

struct die {
	int sides[4];

	int operator>(die d) {
		int win = 0, loss = 0;
		for (int i : sides) {
			for (int j : d.sides) {
				if (i > j) win++;
				if (i < j) loss++;
			}
		}
		return win > loss;
	}
};

int t;

die a, b;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> t;
	while (t--) {
		for (int i = 0; i < 4; i++)
			cin >> a.sides[i];
		for (int i = 0; i < 4; i++)
			cin >> b.sides[i];

		for (int s1 = 1; s1 <= 10; s1++) {
			for (int s2 = 1; s2 <= 10; s2++) {
				for (int s3 = 1; s3 <= 10; s3++) {
					for (int s4 = 1; s4 <= 10; s4++) {
						die c = { s1, s2, s3, s4 };

						if (a > b && b > c && c > a) goto ok;
						if (b > a && c > b && a > c) goto ok;
					}
				}
			}
		}

		cout << "no\n"; continue;
		ok: cout << "yes\n";
	}
}
