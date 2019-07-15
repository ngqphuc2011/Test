#include <iostream>
#include <fstream>
#include <queue>
#define MAX 50

using namespace std;
//bfs xac dinh tru do thi

int doThi[MAX][MAX], n, nlKet, dangXet = -1;
int chuaXet[MAX];
int demLKet();

void init(){
    ifstream filein( "Dothi.txt", ios::in);
    filein >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            filein >> doThi[i][j];
        }
    }
    nlKet = demLKet();
}

void BFS(int v){
    queue<int> q;
    q.push(v);
    chuaXet[v] = false;

    do{
        int u = q.front();
        q.pop();

        for(int i=1; i<=n; i++){
            if(doThi[u][i] && chuaXet[i] && i!=dangXet){
                q.push(i);
                chuaXet[i] = false;
            }
        }
    }while (!q.empty());
}

int demLKet(){
    int i, dem = 0;
    for(i = 1; i<=n; i++){
        chuaXet[i] = 1;
    }
    for(i = 1; i<=n; i++){
        if(chuaXet[i] && dangXet!=i ){
            dem++;
            BFS( i );
        }
    }
    return dem;
}
void duyet(){
	int dem=0;

    for(dangXet = 0; dangXet<=n; dangXet++){
        if(demLKet()>nlKet){
            dem++;
        }
    }
    
    cout<<dem<<endl;
    for(dangXet = 0; dangXet<=n; dangXet++){
		if(demLKet()>nlKet){
            cout<< dangXet << " ";
        }
    }
}

int main(){
    init();
    duyet();
    return 0;
}
/*CHU TU HOANG - B14DCPT072*/
