#include <conio.h>
#include <stdio.h>
#include <iostream>
using namespace std;
FILE *f;
int n, b, a[100], dem = 0, x[100], ok = 1;

void docfile(){
	f = fopen("data.in", "r");
	fscanf(f, "%d%d", &n, &b);
	for(int i = 1; i<=n; i++)
		fscanf(f, "%d", &a[i]);
	fclose(f);
}

void init(){
	for(int i = 1; i <= n; i++) 
		x[i]=0;
}

void sinhnhiphan(){
	int i = n,j;
	while(i > 0 && x[i] == 1){ 
		x[i] = 0;
		i--;
	}
	if(i > 0)
		x[i] = 1;
	else ok = 0;
}

void result(){
	int i;
	f = fopen("ketqua.out","w");
	fprintf(f,"\n\n");
	init();
	while(ok){
		int s = 0;
		for(i = 1; i <= n; i++) 
			if(x[i] == 1) 
				s += a[i];
		if(s == b){
			dem++;
			for(i = 1; i <= n; i++)
				fprintf(f,"%d ", x[i]);
				fprintf(f,"\n");
		}
		sinhnhiphan();
	}
	fseek(f, SEEK_SET, 0);
	fprintf(f,"%d ", dem);
	fclose(f);
}

main(){
	docfile();
	result();
	cout<<"Ket qua da ghi vao file ketqua.out.";
}
