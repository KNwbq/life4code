#include<iostream>
using namespace std;
#include<strstream>

int main() {
	char a[160];
	while (cin.getline(a, 160)) {
		istrstream instr(a);
		char a[17];
		char c;
		int b[16];
		int j = 1;
		while (instr.get(c)) {
			b[0] = c;
			a[0] = c;
			for (int i = 1;i < 16;i++) {
				instr.get(c);
				b[i] = c;
				a[i] = c;
			}
			a[16] = '\0';
			cout.width(7);
			cout.fill('0');
			cout << hex <<j <<0<<"  ";
			for (int i = 0;i < 16;i++) {
				cout << hex << b[i] << " ";
			}
			cout <<" "<< a<<endl;
			j++;
		}
	}
	return 0;
}