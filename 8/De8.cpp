#include<iostream>
#include<cstdio>
#include<fstream>

using namespace std;    

#define MAX 100
int n, k;
int a[MAX];
int s[MAX];
int count = 0;

void docTep() {
	ifstream doc;
	doc.open("DAYSO.INP");
	doc >> n;
	doc >> k;
	for(int i = 0; i < n; i++) {
		doc >> a[i];
	}
	doc.close();
}

int kiemTraTangDan(int s[], int k) {
	for(int i = 0; i < k-1; i++) {
		if(s[i] > s[i+1])
			return 0;
	}
	return 1;
}

bool kiemTrakhacRong(int s[], int k) {
	for (int i = 0; i< k; i ++) {
		if(s[i] == 0)
			return false;
	}
	return true;
}

void KSubset(int *a,int n,int *s,int sIndex,int index,int k, int &count){

    if (index>n)
        return;

    if (k==0 && kiemTraTangDan(s,sIndex) == 1 && kiemTrakhacRong(s,k)){
        for(int i=0;i<sIndex;i++)
            cout << s[i] << " ";
        cout << endl;
        count ++;
        return ;
    }

    s[sIndex]=a[index];
    KSubset(a,n,s,sIndex+1,index+1,k-1,count);
    KSubset(a,n,s,sIndex,index+1,k,count);
}

int main(){
	docTep();
    KSubset(a,n,s,0,0,k,count);
    cout << count;
    return 0;
}

