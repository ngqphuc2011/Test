#include <iostream>
using namespace std;
int a[100][100];
int n;
int start = 0;
int ce[100] = {0};
int dce = 0;
void init(){
	cin >> n;
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=n; j++){
			cin >> a[i][j];
		}
	}
}
bool kiemtra(){
	int degd, dega;
	int dinhle = 0;
	for(int i = 1; i<=n; i++){
		degd = 0;
		dega = 0;
		for(int j = 1; j<=n; j++){
			if(a[i][j] == 1) degd++;
			if(a[j][i] == 1) dega++;	
		}
		
			if(degd-dega == 1){
			dinhle++;
			if(start == 0) start = i;
		}
	}
	if(dinhle > 2){
		return false;
	}
	return true;
}
void duongdi(){
	int stack[100];
	int pos = 0;
	int v;
	stack[pos] = start;
	do{
		v = stack[pos];
		pos--;
		int x = 1;
		while(x <= n && a[v][x] !=1){
			x++;
		}
		if(x > n){
			dce++;
			ce[dce] = v;
		}else{
			pos++;
			stack[pos] = v;
			pos++;
			stack[pos] = x;
			a[v][x] = 0;
			a[x][v] = 0;
		}
	}while(pos >=0);
}
int main(){
	freopen("dothi.inp", "r", stdin);
	init();
	if(kiemtra()){
		duongdi();
		for(int i = dce; i>0; i--){
			cout << ce[i] << " ";
		}
	}else{
		cout << "G khong la do thi nua euler";
	}
	fclose(stdin);
	return 0;
}
