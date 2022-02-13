#include<algorithm>
#include<fstream>
#include<map>

using namespace std;

ifstream in("auto.in");
ofstream out("auto.out");

int w, n;

string s[100000];

map<string, int> mp;

int main() {
	in >> w >> n;

	for (int i = 0; i < w; i++) {
		in >> s[i];
		mp[s[i]] = i + 1;
	}

	sort(s, s + w);

	while (n--) {
		int k;
		string word;
		in >> k >> word;

		int idx = lower_bound(s, s + w, word) - s + k - 1;

		if (idx > w || word.length() > s[idx].length() || s[idx].substr(0, word.length()) != word) out << "-1\n";
		else out << mp.find(s[idx])->second << "\n";
	}
}
