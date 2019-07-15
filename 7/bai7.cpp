#include<conio.h>
#include<stdio.h>
#include<iostream>
using namespace std;
FILE *f;
int a[100], c[100], n, b, x[100], kq[100], ok=1;

void docfile(){
	int i;
	f = fopen("data.in","r");
	fscanf(f,"%d%d", &n, &b);
	for(i = 1; i <=n; i++)
        fscanf(f,"%d",&c[i]);
	for(i = 1; i <= n; i++)
        fscanf(f,"%d", &a[i]);
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
		x[i] = 0;
		i--;
	}
	if(i > 0)
       x[i] = 1;
    else ok = 0;
}

int test(){
	int i, tong = 0;
	for(i = 1; i <= n; i++)
         if(x[i])
            tong += a[i];
	if(tong <= b) return(1);
    return(0);
}

void result(){
	int i, tong, min = 0;
	f = fopen("ketqua.out","w");
	fprintf(f,"\n\n");
	init();
	while(ok){
		if(test()){
			tong = 0;
			for(i = 1; i <= n; i++)
                if(x[i])
                    tong+=c[i];
			if(tong <= min){
				min = tong;
                for(i = 1; i <= n; i++)
                    kq[i] = x[i];
			}
		}
        sinhnhiphan();
	}
	fprintf(f, "%d", min);
	fprintf(f,"\n");
	cout<<"\n Gia tri nhieu nhat: "<<min<<"\n";
	
	for(i = 1; i <= n; i++){
		fprintf(f,"%d ",kq[i]);    	
		cout<<" "<<kq[i]<<" ";
    }
    fclose(f);
}

main(){
	docfile();
	result();
	getch();
}
