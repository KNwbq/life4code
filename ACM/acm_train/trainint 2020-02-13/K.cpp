#include<iostream>
using namespace std;

int main()
{
	int cap, cases, now = 0, lef, ent, wait;
	bool peg = true;
	cin >> cap >> cases;
	for (int i = 1; i <= cases; ++i)
	{
		cin >> lef >> ent >> wait;
		if ((i == 1 && lef > 0) || (i == cases && (ent > 0 || wait > 0))) peg = false;
		now -= lef;
		if (now < 0)peg = false;
		now += ent;
		if (now > cap || now < 0 || (0 < cap - now && wait > 0) || (i == cases && now != 0)) peg = false;
	}
	if (peg) cout << "possible";
	else cout << "impossible";
	return 0;
}
