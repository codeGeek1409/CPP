#include<iostream>
#include<fstream>
#include<iomanip>
#include<cctype>
using namespace std;

int main(int argc, char* argv[]) {
	if (argc != 2) { cout << "usage: <prog> <file>.\n"; return 1; }
	fstream in(argv[1], ios::in | ios::out | ios::binary);
	if (!in.is_open()) { cout << "Readme open error." << endl; return 1; }

	char dat[16]; // for holding 16bytes of file
	int i, j; // indices

	cout.setf(ios::uppercase); // looks good
	while (!in.eof()) { // iterate until eof
		for (i = 0;i < 16 && !in.eof();i++) in.get(dat[i]);
		if (i < 16) i--; // in case eof reached

		for (j = 0;j < i;j++) cout << setw(3) << hex << (int)dat[j]; // space padding
		for (;j < 16;j++) cout << "   "; // in case eof in middle

		cout << '\t';
		for (j = 0;j < i;j++) if (isprint(dat[j])) cout << dat[j]; else cout << '.';
		// ASCII print
		cout << endl;
	}
	in.close();
	return 0;
}