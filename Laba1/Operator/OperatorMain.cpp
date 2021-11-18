#include "Operator.h"
#include <iostream>
using namespace std;

int main() {
	Map map;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		Field field(a, b, c);
		map.Add(field);
	}



	int t1 = map[0];
	int t2 = map[1];
	int t3 = map[2];
	
	cout << t1 << endl;
	cout << t2 << endl;
	cout << t3 << endl;
}
