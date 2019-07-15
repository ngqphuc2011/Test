#include<iostream>
#include<cstring>
#include<stack>
#include<cmath>
using namespace std;
	int a[100][100],b[10][10];
	int n,m;
	FILE *f;
void docfile(){
	int i;
	f = fopen("De10.txt", "r");
	fscanf(f, "%d%d", &m, &n);
	for(int i =0; i<n;i++){
		for(int j =0 ;j<3;j++){
			fscanf(f, "%d", &a[i][j]);
		}
	}
	fclose(f);
}

int main(){
	docfile();
	for(int i=0;i<n;i++){
		b[a[i][0]-1][a[i][1]-1] = a[i][2];
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			cout<<b[i][j]<<" ";
		}
		cout<<endl;
	}
	
}
