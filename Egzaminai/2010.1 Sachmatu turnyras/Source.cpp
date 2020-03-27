#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int calculate(int figuros[]) {
	figuros[0] = trunc(figuros[0] / 8);
	figuros[1] = trunc(figuros[1] / 2);
	figuros[2] = trunc(figuros[2] / 2);
	figuros[3] = trunc(figuros[3] / 2);
	figuros[4] = trunc(figuros[4] / 1);
	figuros[5] = trunc(figuros[5] / 1);

	sort(figuros, figuros + 6);
	return figuros[0];
}

int main() {
	int figuros[6] = { 0 };
	int n;
	ifstream fd("U1.txt");

	fd >> n;

	for (int i = 0; i < n; i++)
	{
		int a, b, c, d, e, f;
		fd >> a >> b >> c >> d >> e >> f;
		figuros[0] += a;
		figuros[1] += b;
		figuros[2] += c;
		figuros[3] += d;
		figuros[4] += e;
		figuros[5] += f;
	}
	fd.close();

	ofstream fr("U1rez.txt");
	fr << calculate(figuros);
	fr.close();

	return 0;
}