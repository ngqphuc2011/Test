#include<conio.h>
#include<stdio.h>
#include<iostream>
using namespace std;

FILE *f;
int a[100], n, k, dem=0, x[100], ok=1;

void docfile(){
	f = fopen("dayso.in", "r");
	fscanf(f, "%d", &n);
	fscanf(f, "%d", &k);
	for(int i=1; i<=n; i++)
		fscanf(f, "%d", &a[i]);
	fclose(f);
}

void init(){
	int i;
	for(i = 1; i <= n; i++)
		x[i] = 0;
}

void sinhnhiphan(){
	int i;
	i = n;
	while(i > 0 && x[i] == 1){
		x[i]=0;
		i--;
	}
	if(i > 0)
		x[i] = 1;
	else ok = 0;
}

void result(){
	int i, tong;
	f = fopen("ketqua.out", "w");
	fprintf(f, "\n\n");
	init();
	while(ok){
		tong = 0;
		sinhnhiphan();
		for(i = 1; i <= n; i++)
            if(x[i])
                tong += a[i];
		if(tong == k){
			for(i = 1; i <= n; i++)
                if(x[i]){ 	
					cout<<a[i]<<" ";
	                fprintf(f, "%d ", a[i]);
				}
		    cout<<"\n";
			fprintf(f,"\n");
	        dem++;
        }
    }
	fseek(f, SEEK_SET, 0);
	fprintf(f, "%d ", dem);
	fclose(f);
}

main(){
	docfile();
	result();
	cout<<"\n So nghiem cua bai toan: "<<dem;
}
