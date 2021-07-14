// author: Saman Mahdanian
#include <iostream>

using namespace std;

// NOTES:
// 1) Always use a static number for your SQ
// 2) Always develope a relaxing function
// 3) Use stepping iteration while processing the result

const int MAX_N = 1E5 + 10;
const int SQ = 350;
// In case of using an static number for your SQ parameter
// you can always change caching size in order to optimize
// your program performance

int a[MAX_N], cache[SQ];

void apply_add_query();
void apply_get_query();
void relax(int); // rebuild the bucket

int main() {
	int n, q;
	cin >> n >> q;

	while(q--) {
		int query_type;
		cin >> query_type;
		if (query_type)
			apply_add_query();
		else
			apply_get_query();
	}
}

void apply_add_query() {
	int index, value;
	cin >> index >> value;
	index--;

	a[index] += value;
	relax(index / SQ);
}

void apply_get_query() {
	int l, r;
	cin >> l >> r;
	l--; // ---> [L, R)

	// Stepping Iteration:
	// Always iterate normally on your underlying array
	// and incase of a possible jump (using cached data)
	// feel free and jump and merge the data into the result
	int result = INT_MAX;
	int ptr = l;
	while (ptr < r)
		if (ptr % SQ == 0 && ptr + SQ <= r) {
			result = min(result, cache[ptr / SQ]);
			ptr += SQ;
		} else {
			result = min(result, a[ptr]);
			ptr++;
		}

	return result;
}

// Relaxing Function
// It's good to develope a function called "Relax"
// to rebuild all required information about a bucket
// based on undelying array
void relax(int index) {
	cache[index] = INT_MAX;
	for (int i = index * SQ; i < (index + 1) * SQ; i++)
		cache[index] = min(cache[index], a[i]);
}

// SamMHD