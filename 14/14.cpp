#include <iostream>
#include<fstream>
#define max 50

//CHU TRINH EULER;
//DO THI CO HUONG;

using namespace std;

int a[max][max], n, m;

int demCanh(){
	int dem=0;
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			if(a[i][j])
			dem += a[i][j];
		}
	}
	return dem;
}
//nhap kich thuoc va toa do do thi
//dang nhi phan 0 1;

void init(){
    ifstream filein( "dothi.txt", ios::in);
    filein >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            filein >> a[i][j];
        }
    }
    m=demCanh();
}

bool kTra(){
    int canh;
    for(int i=0; i<n; i++){
        canh = 0;
        for(int j=0; j<n; j++){
            canh += a[i][j];
        }
        for(int j=0; j<n; j++){
            canh -= a[j][i];
        }
        if(canh) return 0;
    }
    return 1;
}

void CTCoHuong(int start = 0){
    int E[max], dE = 0;
    int stack[max], top = 0;

    stack[top++] = start;
    do {
        int y = stack[top-1];
        int x = 0;
        while(x<n && a[y][x]==0)
            x++;
        if(x == n) {
            E[dE++] = y;
            top--;
        }
        else {
            stack[top++] = x;
            a[y][x]--;
        }
    } while(top!=0);

    if(dE != m+1 ) {
        cout << "\nKhong co chu trinh Euler!";
        return;
    }

    cout << "\nChu trinh Euler di qua " << m << " canh:\n\n";
    for(int x = dE-1; x>=0; x--)
        cout << E[x] << " ";
}

int main(){
    init();
    if(kTra())
        CTCoHuong();
    else cout << "\nKhong co chu trinh Euler!";
    
    return 0;
}
/*CHU TU HOANG - B14DCPT072*/
