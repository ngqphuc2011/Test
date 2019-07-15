#include<iostream>
#include<fstream>
using namespace std;

int a[50][50], chuaxet[50];
int t, n, k;
int T[50][2];
int M[50][2];

struct Node{
	Node *next;
	int data;
};

struct Queue{
	Node *head;
	Node *tail;
};

void Init( Queue &q ){
	q.head = q.tail = NULL;
}

Node *createNode( int x ){
	Node *p = new Node;
	if(!p) return NULL;
	p->data = x;
	p->next = NULL;
	return p;
}

void Push( Queue &q, Node *p ){
	if(!q.head) q.head = q.tail = p;
	else{
		q.tail->next = p;
		q.tail = p;
	}
}

int Pop( Queue &q ){
	if( q.head ){
		int x = q.head->data;
		Node *p = q.head;
		q.head = q.head->next;
		delete p;
		return x;
	}
	return 0;
}

void ReInit(){
	for( int i = 1; i<= n; i++ ) chuaxet[i] = 1;
}

void nhap(){
	ifstream ifs("DOTHI.INP");
	ifs >> n >> k;
	for( int j = 1; j<= k; j++ )
			for( int i = 1; i<= 2; i++ )
				ifs >> M[j][i];
	for( int j = 1; j<= k; j++ )
				a[M[j][1]][M[j][2]] = 	a[M[j][2]][M[j][1]]  = 1;
			
	ReInit();
	ifs.close();
}

void BFS( int u ){
	Queue q;
	Init(q);
	Node *p = createNode(u);
	Push(q, p);
	chuaxet[u] = 0;
	while(q.head){
		int s = Pop(q);
		for( int i = 1; i<= n; i++ )
			if( chuaxet[i] && a[s][i] ) {
				Node *p = createNode( i );
				Push( q, p );
				T[t][1] = s;
				T[t][2] = i;
				chuaxet[i] = 0;
				t++;
			}
	}
	t--;
}

void xuat() {
	int u;
	cout << "Nhap so u tu ban phim: ";
	cin >>u;
	BFS(u);

	if (t != n - 1) cout << -1;
	else {
		cout << 1 << endl;
		for (int i = 1; i <= t; i++)
			cout << T[i][1] << " " << T[i][2] << endl;
	}

}

int main(){
	t = 1;
	nhap();
	xuat();
	return 0;
}
