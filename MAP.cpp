#include <iostream>
#include <map>
#include <set>

using namespace std;

map<int, string> m;
set< pair<int, string> > maps;

void add_map(int, string);
void erase_map(int);
string get_map(int);

// (int) ---> (string)

int main() {
	// Mapping using SET
	add_map(12, "salam");
	add_map(13, "khodafez");
	add_map(12, "hi");
	erase_map(13);
	cout << get_map(12) << endl;

	// Mapping using Array
	string s[1000 * 1000] = {};
	s[12] = "salam";
	s[13] = "khodafez";
	s[12] = "hi";
	s[13] = "";
	cout << s[12] << endl;

	// Mapping using std::map
	m[12] = "salam";
	m[13] = "khodafez";
	m[12] = "hi";
	m.erase(13);
	cout << m[12] << endl;

	// Also about std::map
	m.empty();
	m.size();
	m.clear();

	map<string, int> score;
	t["bahar"] = 10;
	t["roshan"] = 9;
	t["armita"] = 11;

	map<long long, int> compressor; // !!
	compressor[12345678912345LL] = 12;
	compressor[98765432198765LL] = 11;
}

void add_map(int v, string s) {
	erase_map(v);
	maps.insert({v, s});
}

void erase_map(int v) {
	auto it = maps.lower_bound({v, ""});
	if (it == maps.end() || (*it).first != v)
		return;
	maps.erase(it);
}

string get_map(int v) {
	auto it = maps.lower_bound({v, ""});
	if (it == maps.end() || (*it).first != v)
		return "";
	return (*it).second;
}