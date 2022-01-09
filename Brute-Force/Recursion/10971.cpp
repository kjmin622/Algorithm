#include<iostream>
#include<vector>
using namespace std;
#define CANTMOVE 2e7

int n,dist[10][10];

int smallestPath(int currentloc, vector<int>& visited, int visitcnt, int currentCost){
	if(visitcnt==n){
		return currentCost+dist[currentloc][0];
	}
	int ret = 2e9;
	for(int next=0; next<n; next++){
		if(visited[next] || dist[currentloc][next]==CANTMOVE) continue;
		visited[next]=true;
		ret = min(ret,smallestPath(next,visited,visitcnt+1,currentCost+dist[currentloc][next]));
		visited[next]=false;
	}
	return ret;
}

int main(){
	cin>>n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>dist[i][j];
			if(dist[i][j]==0) dist[i][j]=CANTMOVE;
		}
	}
	vector<int> visited(10);
	visited[0]=true;
	cout<<smallestPath(0,visited,1,0)<<endl;
	
}