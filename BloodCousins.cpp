// author: Saman Mahdanian
#include <iostream>

using namespace std;
const int N = 1E5 + 10;
const int L = 23;

struct Vertex {
	vector<int> nei;
	int heigh, par[L];
	int starting_time, finishing_time;
} vertexes[N];

int dfs_order[N];
vector<int> v_in_h[N];

void read_graph();				// reads from input
void dfs(int, int);				// resolves height, parents and timers
int blood_cousins(int, int);	// get blood_cousin count
int get_par(int, int); 			// get h-th parent of a vertex

int main() {
	read_graph();
	dfs();

	// You can use these two commands instead of "dfs_order[timer] = v;" in dfs
	// iota(dfs_order, dfs_order + n, 0);
	// sort(dfs_order, dfs_order + n, [&](int v, int u) {
	// 	return vertex[v].starting_time < vertex[u].starting_time;
	// });

	int q;
	cin >> q;
	while(q--) {
		int v, h;
		cin >> v >> h;
		v--;
		cout << blood_cousins(v, h) << endl;
	}
}

void read_graph() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int v, u;
		cin >> v >> u;
		v--; u--;
		vertexes[v].nei.push_back(u);
		vertexes[u].nei.push_back(v);
	}
}

void dfs(int v, int pv) {
	static int timer = 0;
	dfs_order[timer] = v;
	vertexes[v].starting_time = timer++;

	if (v != pv)
		vertexes[v].heigh = vertexes[pv].heigh + 1;
	par[v][0] = pv;
	for (int l = 0; l < L; l++)
		vertexes[v].par[l] = vertexes[vertexes[v].par[l - 1]].par[l - 1];
	v_in_h[h[v]].push_back(vertexes[v].starting_time);

	for (int u: vertexes[v].nei)
		if (u != pv)
			dfs(u, v);

	vertexes[v].finishing_time = timer;
}

int blood_cousins(int v, int h) {
	v = get_par(v, h);

	int target_h = vertexes[v].heigh + h;
	auto lb = lower_bound(v_in_h[target_h].begin(), v_in_h[target_h].end(), vertexes[v].starting_time);
	auto ub = lower_bound(v_in_h[target_h].begin(), v_in_h[target_h].end(), vertexes[v].finishing_time);
	int cnt = ub - lb;

	return cnt;
}

int get_par(int v, int h) {
	if (vertexes[v].heigh < h)
		return -1;
	for (int l = L - 1; l >= 0; l--)
		if ((1 << l) & h)
			v = vertexes[v].par[l];
	return v;
}