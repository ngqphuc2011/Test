#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

int V, G[1111][1111], k;
int flag[1111];

void bfs(int k) {
	queue<int> queue;
	queue.push(k);
	flag[k] = 1;
	while (!queue.empty()) {
		int u = queue.front();
		queue.pop();
		for (int i = 1; i <= V; i++) {
			if (G[u][i] == 1 && flag[i] == 0) {
				cout << u << " " << i << endl;
				queue.push(i);
				flag[i] = 1;
			}
		}
	}
}

int main() {
	fstream fin;
	fin.open("bai20.txt", ios::in);
	fin >> V >> k;
	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			fin >> G[i][j];
		}
	}
	cout << V << " " << V - 1 << endl;
	bfs(k);
}
