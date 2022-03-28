#include<cmath>
#include<fstream>

using namespace std;

ifstream in("billboard.in");
ofstream out("billboard.out");

struct rect {
	int x1, y1, x2, y2;

	int area() { return (x2 - x1) * (y2 - y1); }
} rects[3];

int intersection(int a, int b) {
	int x = max(0, min(rects[a].x2, rects[b].x2) - max(rects[a].x1, rects[b].x1));
	int y = max(0, min(rects[a].y2, rects[b].y2) - max(rects[a].y1, rects[b].y1));
	return x * y;
}

int main() {
	for (int i = 0; i < 3; i++)
		in >> rects[i].x1 >> rects[i].y1 >> rects[i].x2 >> rects[i].y2;

	out << rects[0].area() + rects[1].area() - intersection(0, 2) - intersection(1, 2) << "\n";
}
