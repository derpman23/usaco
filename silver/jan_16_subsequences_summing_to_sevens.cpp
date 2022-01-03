#include<cstring>
#include<fstream>

using namespace std;

ifstream in("div7.in");
ofstream out("div7.out");

int n, l[7], r[7], dp = 0, ans = 0;

int main() {
	in >> n;
	memset(l, -1, sizeof(l));
	l[0] = 0;
	
	for (int i = 1; i <= n; i++) {
		long long a;
		in >> a;
		dp = (dp + a) % 7;

		if (l[dp] == -1) l[dp] = i;
		r[dp] = i;
	}

	for (int i = 0; i < 7; i++)
		if (l[i] != -1)
			ans = max(ans, r[i] - l[i]);

	out << ans << "\n";
}
