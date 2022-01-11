#include<iostream>
#include<vector>
#include<string>
#include<cmath>
using namespace std;

int n, ans;
int charcnt[91];
int numbers[10]={0,1,2,3,4,5,6,7,8,9};
vector<char> existChar;
bool charvisited[91];
string word;

void swap(int &a, int &b){
	int tmp = a; a=b; b=tmp;
}

void solve(int depth){
	if(depth==existChar.size()){
		int val = 0;
		for(int i=0; i<existChar.size(); i++){
			val += charcnt[existChar[i]]*numbers[i];
		}
		ans = max(ans,val);
		return;
	}
	int ans=0;
	for(int i=depth; i<10; i++){
		swap(numbers[depth],numbers[i]);
		solve(depth+1);
		swap(numbers[depth],numbers[i]);
	}
}

int main(){
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>word;
		int wsize = word.length()-1;
		for(char c : word){
			charcnt[c]+=pow(10,wsize--);
			if(charvisited[c]) continue;
			charvisited[c]=true;
			existChar.push_back(c);
		}
	}
	solve(0);
	cout<<ans<<endl;
}