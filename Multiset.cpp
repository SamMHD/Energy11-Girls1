#include <iostream>
#include <set>

using namespace std;

int main() {
	multiset<int> s;
	
	s.insert(1);
	s.insert(2);
	s.insert(3);

	for (int v: s)
		cout << v << ' ';
	cout << endl;
	// output: 1 2 3

	s.insert(2);
	for (int v: s)
		cout << v << ' ';
	cout << endl;
	// output: 1 2 2 3

	// Be aware that erase by value will
	// erase all the matching values
	s.erase(2);
	for (int v: s)
		cout << v << ' ';
	cout << endl;
	// output: 1 3

	// insert 2 (3 times)
	for (int i = 0; i < 3; i++)
		s.insert(2);
	// to erase exactly one member
	// you should use it's iterator
	s.erase(s.find(2));
	for (int v: s)
		cout << v << ' ';
	cout << endl;
	// output: 1 2 2 3

	cout << s.count(2) << endl;
	// output: 2
	cout << s.count(3) << endl;
	// output: 1
	cout << s.count(4) << endl;
	// output: 0

	// alternate form for count -> O(lg(size) + count)
	cout << (s.upper_bound(2) - s.lower_bound(2)) << endl
	// output: 2

	// You can use all other methods on SET like:
	s.empty();
	s.size();
	s.begin();
	s.end();
	s.clear();
	//...
}