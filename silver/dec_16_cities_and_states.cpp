#include<fstream>
#include<map>

using namespace std;

ifstream in("citystate.in");
ofstream out("citystate.out");

int n;

long long ans = 0;

map<string, int> mp;

int main() {
	in >> n;

	for (int i = 0; i < n; i++) {
		string city, state;
		in >> city >> state;
		city = city.substr(0, 2);
		if (city != state) ans += mp[state + city];
		mp[city + state]++;
	}

	out << ans << "\n";
}
