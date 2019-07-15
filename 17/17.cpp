#include <iostream>
#include <iomanip>
#include <fstream>
#include <queue>
#define MAX 50
using namespace std;


int doThi[MAX][MAX], n, dem;
int chuaxet[MAX];

void init(){
    ifstream filein( "MTKe.txt", ios::in);
    filein >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            filein >> doThi[i][j];
        }
    }
}

void BFS(int v){
    queue<int> q;
    q.push(v);
    chuaxet[v] = false;
    dem++;
    do{
        int u = q.front();
        q.pop();

        for(int i=0; i<n; i++){
            if(doThi[u][i] && chuaxet[i]){
                q.push(i);
                chuaxet[i] = false;
                dem++;
            }
        }
    }while (!q.empty());
}

bool lienThongManh(){
    for( int i = 0; i<n; i++){
        for( int j = 0; j<n; j++){
            chuaxet[j] = 1;
            dem = 0;
        }
        BFS(i);
        if(dem<n) return false;
    }
    return true;
}

bool lienThongYeu(){
	for( int i = 0; i<n; i++){
        if(chuaxet[i]){
           BFS( i );
           if(dem<n) return false;
        }
    }
    
    return true;
}


int main(){
    int dem = 0;
    init();
    if(lienThongManh())
        cout << "\nDo thi lien thong manh!";
    else if(lienThongYeu()) 
		cout << "\nDo thi lien thong yeu!";
    else 
		cout<< "\nDo thi khong lien thong manh, khong lien thong yeu!";

    return 0;
}
/*CHU TU HOANG - B14DCPT072*/
