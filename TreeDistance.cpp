#include <iostream>
#include <vector>

using namespace std;

const int N = 1E6 + 10;
const int L = 25;

int n, h[N], par[N][L];
vector <int> g[N];

void inputGraph();								// inputs the Graph
int LCA(int, int);								// returns the LCA of two vertex
int distance(int, int);							// returns the distance of two vertexes
void preProccess(int = 0, int = 0, int = 0);	// resolves parents and heights

int main() {
	inputGraph();
	preProccess();

	int q;
	cin >> q;
	while(q--) {
		int v, u;
		cin >> v >> u;
		v--; u--;
		cout << distance(v, u) + 1 << endl;
	}
}

void inputGraph() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int v, u;
		cin >> v >> u;
		v--; u--;
		g[v].push_back(u);
		g[u].push_back(v);
	}
}

void preProccess(int v, int pv, int cur_h) {
	h[v] = cur_h;
	par[v][0] = pv;
	for (int l = 1; l < L; l++)
		par[v][l] = par[par[v][l - 1]][l - 1];

	for (int u: g[v])
		if (u != pv)
			preProccess(u, v, cur_h + 1);
}

int distance(int v, int u) {
	return h[v] + h[u] - 2 * h[LCA(v, u)];
}

int LCA(int v, int u) {
	if (h[v] < h[u])
		swap(v, u);

	for (int l = L - 1; l >= 0; l--)
		if (h[par[v][l]] >= h[u])
			v = par[v][l];
	if (v == u)
		return v;

	for (int l = L - 1; l >= 0; l--)
		if (par[v][l] != par[u][l]) {
			v = par[v][l];
			u = par[u][l];
		}
	return par[v][0];
}
