#include<algorithm>
#include<fstream>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ifstream in("walk.in");
ofstream out("walk.out");

const ll MOD = 2019201997LL;

int n, k;

int main() {
	in >> n >> k;
	out << MOD - 48 * n - 84 * (k - 1) << "\n";
}
