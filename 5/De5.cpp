#include<iostream>
#include<cstring>
#include<stack>
#include<cmath>
#include <fstream>

using namespace std;

string str;

void docTep() {
	ifstream doc;
	doc.open("HAUTO.INP");
	getline(doc, str);
	doc.close();
}
void tinh( string str, stack<int> st ){
	int s = str.size();
	for( int  i= 0; i< s; i++ ){
		if( str.at(i) -'0' >= 0 && str.at(i) - '0' <= 9 ) st.push( str.at(i) - '0' );
		else if( str.at(i) != ' ' && st.top() != st.empty() ){
			int a, b;
			b = st.top(); st.pop();
			a = st.top(); st.pop();
			if( str.at(i) == '+' ) st.push( a + b );
			if( str.at(i) == '-' ) st.push( a - b );
			if( str.at(i) == '*' ) st.push( a * b );
			if( str.at(i) == '/' ) st.push( a / b );
			if( str.at(i) == '^' ) st.push( pow( a, b ) );
			if( str.at(i) == '%' ) st.push( a % b ); 
		}
	} if( !st.empty() ) cout<< st.top();
}

int main(){
	stack<int> st;
	docTep();
	tinh(str, st);
	return 0;
}

