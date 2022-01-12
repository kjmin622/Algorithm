#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int n;
string solve(int m){
	if(m==1) return "-";
	string tmp="";
	tmp.resize(m/3,' ');
	return solve(m/3)+tmp+solve(m/3);
}

int main(){
	while(scanf("%d",&n)!=EOF){
		cout<<solve(pow(3,n))<<endl;
	}
}