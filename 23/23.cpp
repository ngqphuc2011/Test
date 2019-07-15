#include <iostream>
#include <fstream>
#include <queue>
#define MAX 50

using namespace std;

int doThi[MAX][MAX], n, nlKet;
int chuaxet[MAX];
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
    chuaxet[v] = false;

    do{
        int u = q.front();
        q.pop();

        for(int i=1; i<=n; i++){
            if(doThi[u][i] && chuaxet[i]){
                q.push(i);
                chuaxet[i] = false;
            }
        }
    }while (!q.empty());
}

int demLKet(){
    int i, dem = 0;
    for(i = 1; i<=n; i++){
        chuaxet[i] = 1;
    }
    for(i = 1; i<=n; i++){
        if(chuaxet[i]){
            dem++;
            BFS( i );
        }
    }
    return dem;
}

void duyetCau(){
    int i, j,dem =0;

    for(i = 1; i<=n; i++){
        for(j = 1; j<=n; j++){
            if(doThi[i][j]){
                doThi[i][j] = 0;
                if(demLKet()>nlKet){
                	dem++;
                    
                }
                doThi[i][j] = 1;
            }
        }
    }
    cout<<dem<<endl;
    
	for(i = 1; i<=n; i++){
        for(j = 1; j<=n; j++){
            if(doThi[i][j]){
                doThi[i][j] = 0;
                if(demLKet()>nlKet){
                //	dem++;
                    cout << i << "  "<< j<<endl;
                    
                }
                doThi[i][j] = 1;
            }
        }
    }

}

int main(){
    init();
    demLKet();
    duyetCau();
    return 0;
}
/*CHU TU HOANG - B14DCPT072*/
