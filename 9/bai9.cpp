#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
#define max 30
using namespace std;
FILE *f;
int a[max][max], set[max][max], n, k, dem, kq[max], ok=1;

void docfile(){
	int i, j;
	f = fopen("MTKE.IN","r");
	fscanf(f, "%d", &n);
	cout<<"Ma tran ke la:\n";
	for(i = 1; i <= n; i++){
		for(j = 1; j <= n; j++){
			fscanf(f,"%d", &a[i][j]);
				cout<<a[i][j]<<" ";
		}
		cout<<"\n";
	}
	fclose(f);
}

typedef struct{
	int in;
	int node[max];
}stack;

void init(stack *s){
	s->in = -1;
}

int empty(stack *s){
	if(s->in == -1)return(1);
	return(0);
}

int full(stack *s){
	if(s->in == max-1)return(1);
	return(0);
}

int laydau(stack *s){
	if(empty(s))return(-32000);
	else return(s->node[s-> in]);
}

void push(stack *s,int x){
	if(!full(s)){
		s->in = (s->in) +1;
		s->node[s->in] = x;
	}
}

int pop(stack *s){
	if(empty(s))return(-32000);
	int x = s->node[s->in];
	s->in = (s->in) -1;
	return(x);
}

void DFS(int u, int b[max][max]){
	stack s;
	int i, h, chuaxet[max]; 
	dem = 1;
	for(i = 1; i <= n; i++)
		chuaxet[i] = 1;
	init(&s);
	push(&s, u);
	chuaxet[u] = 0;
	kq[dem] = u;
	while(!empty(&s)){
		h = pop(&s);
		i = 1;
		while(i <= n){
			if(b[h][i] > 0 && chuaxet[i]){
				dem++;
				kq[dem] = i;
				push(&s, h);
				push(&s, i);
				chuaxet[i] = 0;
				break;
			}
			i++;
		}
	}
}

int demsotplt(int b[max][max]){
	int x = 0, i, chuaxet1[max];
	for(i = 1; i <= n; i++)	
		chuaxet1[i]=1;
	for(i=1;i<=n;i++)
		if(chuaxet1[i]){
			DFS(i,b);
			for(int j = 1; j <=dem;j++)
				chuaxet1[kq[j]] = 0;
				x++;
	}return(x);
}

void setvalue(int u,int v){
	int i,j;
	for(i = 1; i <= n; i++)
		for(j = 1; j <= n; j++){
			if(i == u && j == v){
				set[i][j] = 0;
				set[j][i] = 0;
			}else set[i][j] = a[i][j];
		}
}

void testcanhcau(){
	int i, j, value, socanhcau = 0, canhcau[max][2];
	value=demsotplt(a);
	f = fopen("DSCANH.OUT","w");
	for(i = 1; i < n; i++)
		for(j = i+1; j <= n; j++)
			if(a[i][j] > 0){
				setvalue(i, j);
				if(demsotplt(set) > value){
					socanhcau++; 
					canhcau[socanhcau][1] = i;
					canhcau[socanhcau][2] = j;
				}
			}
	if(socanhcau == 0) fprintf(f,"%d\n",socanhcau);
	else {
		fprintf(f,"%d\n",socanhcau);
		for(i = 1; i <= socanhcau; i++){
			fprintf(f,"%d ", canhcau[i][1]);
			fprintf(f,"%d\n", canhcau[i][2]);
		}
	}
	fclose(f);
}

main(){
	docfile();
	testcanhcau();
	cout<<"Da ghi ket qua vao file DSCANH.OUT";
}
