#include<algorithm>
#include<fstream>

using namespace std;

struct particle {
	int a, b;

	int operator <(particle c) {
		if (a == c.a) return b < c.b;

		return a < c.a;
	}
} particles[100000];

int n, p1[100000], p2[100000], ans = 1;

int main() {
	ifstream in("moop.in");
	ofstream out("moop.out");

	in >> n;

	for (int i = 0; i < n; i++)
		in >> particles[i].a >> particles[i].b;

	sort(particles, particles + n);

	p1[0] = particles[0].b;
	for (int i = 1; i < n; i++)
		p1[i] = min(p1[i - 1], particles[i].b);

	p2[n - 1] = particles[n - 1].b;
	for (int i = n - 2; i >= 0; i--)
		p2[i] = max(p2[i + 1], particles[i].b);

	for (int i = 0; i < n - 1; i++)
		if (p1[i] > p2[i + 1])
			ans++;

	out << ans << "\n";
}
