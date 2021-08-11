#include <iostream>
#include <set>

using namespace std;

void print_set(set<int>&); 	// will print the set

int main() {
	int a;
	cin >> a;

	// delclare a set of integers
	// like declaring an integer
	set<int> s;

	// inserting into set
	s.insert(3);
	s.insert(1);
	s.insert(2);

	// you can iterate over the set
	for (int i: s)
		cout << i << ' '
	cout << endl;
	// output: 1 2 3

	// set won't insert duplicates
	s.insert(2);
	print_set(s);
	// output: 1 2 3

	s.erase(1);
	print_set(s);
	// output: 2 3

	// you can use .size()
	cout << s.size() << endl;
	// output: 2

	// .clear() will erase all elements
	s.clear();

	// you can use .empty()
	cout << (s.empty()? "empty" : "not empty") << endl;
	// output: empty

	for (int i = 0; i < 10; i++)
		s.insert(i);

	// Iterator: an object that points to an element of the set
	set<int>::iterator it;
	it = s.begin();
	// s         =  {0, 1, 2, ..., 8, 9}
	// s.begin() =   ^

	// *it will return value of the iterator
	cout << (*it) << endl;
	// output: 0

	// ++ will move iterator to the right
	it++;
	// s         =  {0, 1, 2, ..., 8, 9}
	// it        =      ^
	cout << (*it) << endl;
	// output: 1
	// NOTE: you can use --

	// you can also use += k  or  -= k
	it += 8;
	// s         =  {0, 1, 2, ..., 8, 9}
	// it        =                    ^
	// WARNING: += and -= will work under O(k)
	//          and they are NOT from O(1)


	// some use full iterators on  s =   {1, 2, 3, ..., 8, 9}
	it = s.begin();           //  it =   {^                 }
	it = s.end();             //  it =   {                  }^
	it = s.find(3);           //  it =   {      ^           }
	it = s.find(-1); //.end() //  it =   {                  }^
	it = s.lower_bound(2);    //  it =   {   ^              }
	it = s.upper_bound(2);    //  it =   {      ^           }

	// there is also something named reverse_iterator
	set<int>::reverse_iterator rit;
	rit = s.rbegin();         // rit =   {                 ^}
	rit = s.rend();           // rit =  ^{                  }

	// ++ and -- and += and -= are working reverse here
	rit = s.rbegin();
	rit = s.rbegin();         // rit =   {                 ^}
	rit++;                    // rit =   {               ^  }
	rit--;                    // rit =   {                 ^}

	// C++98 iteration sample
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
		cout << (*it) << ' ';
	cout << endl;
	// output: 1 2 3 ... 9

	// C++98 reverse iteration sample
	for (set<int>::reverse_iterator rit = s.rbegin(); rit != s.rend(); rit++)
		cout << (*rit) << ' ';
	cout << endl;
	// output: 9 8 7 ... 1

	// Another C++98 reverse iteration sample
	it = s.end();
	it--;
	while(true) {
		cout << (*it) << ' ';
		if (it == s.begin())
			break;
	}
	cout << endl;
	// output: 9 8 7 ... 1

	it = s.find(3);  // O(lg(N))
	s.erase(4);      // O(lg(N)) when passing value
	s.erase(it);     // O(lg(N)) but better performance when passing iterator

	// you can assing sets to each other
	set<int> t;
	t.insert(42);
	print_set(s);
	// output: 1 2 5 6 .. 9
	s = t;
	print_set(s);
	// output: 42

	// There is MORE...

	// You can use set over many types!!!
	set<int> q;
	set<float> w;
	set<long long> e;
	set<double> r;
	set<uint64_t> y;
	// or anything that supports operator "<"
	set< pair<int, int> > u; // we have things to do here!!
	set< vector<int> > p; // because there is "<" over vector!!


	int a[100] = {100, 2452134124, 42342, 34234, 53454352, 23412};
	
	set< pair<int, string> > k;
	for (int i = 0; i < 6; i++)
		k.insert({a[i], i});
	// k = {   
	// 	{100, 0}, 
	// 	{23412, 5}, 
	// 	{34234, 3}, 
	// 	{42342, 2}, 
	// 	{53454352, 4}, 
	// 	{2452134124, 1}   
	// }

	// using K, let us know what is index of a value!!
	int Q;
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		int v;
		cin >> v;

		// Logarithmic, DS, O(lg(N))
		for (int i = 0; i < 6; i++)
			if (a[i] == v)
				cout << i << endl;

		// Logarithmic, DS, O(lg(N))
		it = k.upper_bound({v, -1});
		cout << (*it).second << endl;

		// f(value) --> index
		// value < 10**9
		// index < 10**6
	}

	// lower_bound(x)      --->   >= x
	// upper_bound(x)      --->   >  x
	// lower_bound(x) - 1  --->   <  x
	// upper_bound(x) - 1  --->   <= x

	// Mapping!!!
	// Go Ahaed to MAP.cpp to find more!!
}

void print_set(set<int> &s) {
	for (int i: s)
		cout << i << ' ';
	cout << endl;
}