#include <iostream>
#include<fstream>
#define MAX 50

//CHU TRINH EULER;
//DO THI VO HUONG;

using namespace std;

int A[MAX][MAX], n, m;


int demCanh(){
	int i, j, dem=0;
	for(i = 0; i<n; i++){
		for( j = i; j<n; j++){
			if(A[i][j])
			dem += A[i][j];
		}
	}
	return dem;
}
//nhap kich thuoc va toa do cua do thi;

void init(){
    ifstream filein( "dothi.txt", ios::in);
    filein >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            filein >> A[i][j];
        }
    }
    m=demCanh();
}
bool kTra(){
    int Canh, d;
    for(int i=0; i<n; i++){
        Canh = 0;
        for(int j=0; j<n; j++){
            Canh += A[i][j];
        }
        if(Canh%2) return 0;
    }
    return 1;
}

void CTEuler(int start = 0){
    int E[MAX], dE = 0;
    int stack[MAX], top = 0;

    stack[top++] = start;
    do {
        int v = stack[top-1];
        int x = 0;
        while(x<n && A[v][x]==0)
            x++;
        if(x == n) {
            E[dE++] = v;
            top--;
        }
        else {
            stack[top++] = x;
            A[v][x]--;
            A[x][v]--;
        }
    } while(top!=0);

    if(dE != m+1 ) {
        cout << "\nG khong la do thi Euler!";
        return;
    }
    cout << "\nChu trinh Euler di qua " << m << " canh:\n\n";
    for(int x = dE-1; x>=0; x--)
        cout << E[x] << " ";
}

int main(){
    init();
    if(kTra())
        CTEuler();
    else cout << "\nKhong co chu trinh Euler!";
    return 0;
}

