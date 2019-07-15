#include <iostream>
#include <vector>
#include <algorithm> // Hàm sort
#include<fstream>
using namespace std;

int  n, k;

struct edge {
    int u, v, w;
};

bool cmp(const edge &a, const edge &b) {
    return a.w < b.w;
}

#define N 10005

int cha[N], hang[N];

int find(int u) {
    if (cha[u] != u) cha[u] = find(cha[u]);
    return cha[u];
}


bool join(int u, int v) {
	bool tmp;
    u = find(u); v = find(v);
    if (u == v) return false;
    if (hang[u] == hang[v]) hang[u]++;
    if (hang[u] < hang[v]) cha[u] = v;
    else cha[v]=u;
    return true;
}

int main() {


	ifstream ifs("DOTHI.INP");
	ifs >> n >> k;
	vector<edge> edges;
	for (int i = 0; i < k; i ++)
	{
		struct edge e;
		int a1,a2,a3;
		ifs >> a1 >> a2 >> a3;
		e.u = a1;
		e.v = a2;
		e.w = a3;
		edges.push_back(e);
	
	}

	ifs.close();
    


    sort(edges.begin(), edges.end(), cmp);


    for (int i=1; i<=n; i++) {
        cha[i] = i;
        hang[i] = 0;
    }
	int mst_weight = 0;
    for (int i = 0; i < k; i++ ) {

        if (join(edges[i].u, edges[i].v)) {
	
            	mst_weight += edges[i].w;
        }
    }
    cout << mst_weight<<endl;
    for (int i=1; i<=n; i++) {
        cha[i] = i;
        hang[i] = 0;
    }
    for (int i = 0; i < k; i++ ) {

        if (join(edges[i].u, edges[i].v)) {
	
            	cout << edges[i].u << " " << edges[i].v<< " " << edges[i].w <<endl;
     
        }
    }



    return 0;
}
