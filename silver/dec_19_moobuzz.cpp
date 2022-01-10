#include<fstream>

using namespace std;

ifstream in("moobuzz.in");
ofstream out("moobuzz.out");

int n, arr[9] = { 1, 2, 4, 7, 8, 11, 13, 14 };

int main() {
	in >> n;
	out << --n / 8 * 15 + arr[n % 8] << "\n";
}
