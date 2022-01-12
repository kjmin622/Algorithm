#include<iostream>
#include<vector>
using namespace std;

int n, m, office[8][8], blindspot;
int visited[8][8];
vector<vector<vector<pair<int,int> > > > cctvDic; // n번째 - cctv방향 - 감시가능방향 - xy방향(pair)
vector<pair<int,int> > tmpdic = {make_pair(-1,0),make_pair(0,1),make_pair(1,0),make_pair(0,-1)};
vector<pair<int,int> > cctvLoc;

void cctvSetting(){
	for(int i=0; i<=5; i++){
		vector<vector<pair<int,int> > > tmp;
		cctvDic.push_back(tmp);
	}
	//1
	for(int i=0; i<4; i++){
		vector<pair<int,int> > tmp;
		tmp.push_back(tmpdic[i]);
		cctvDic[1].push_back(tmp);
	}
	//2
	for(int i=0; i<2; i++){
		vector<pair<int,int> > tmp;
		tmp.push_back(tmpdic[i]);
		tmp.push_back(tmpdic[i+2]);
		cctvDic[2].push_back(tmp);
	}
	//3
	for(int i=0; i<4; i++){
		vector<pair<int,int> > tmp;
		tmp.push_back(tmpdic[i]);
		tmp.push_back(tmpdic[(i+1)%4]);
		cctvDic[3].push_back(tmp);
	}
	//4
	for(int i=0; i<4; i++){
		vector<pair<int,int> > tmp;
		for(int j=0; j<4; j++){
			if(i==j) continue;
			tmp.push_back(tmpdic[j]);
		}
		cctvDic[4].push_back(tmp);
	}
	//5
	vector<pair<int,int> > tmp;
	tmp = tmpdic;
	cctvDic[5].push_back(tmp);
}

int paintWatch(int x, int y, pair<int,int> dic, bool paint){
	int increas = paint ? 1 : -1;
	int painter = 0;
	while(x>=0 && y>=0 && x<n && y<m && office[x][y]!=6){
		if(paint && visited[x][y]==0) painter++;
		if(!paint && visited[x][y]==1) painter++;
		visited[x][y]+=increas;
		x+=dic.first;
		y+=dic.second;
	}
	return painter;
}

int searchAns(int cctvcnt, int currentblind){
	if(cctvcnt == cctvLoc.size()){
		return currentblind;
	}
	int x = cctvLoc[cctvcnt].first;
	int y = cctvLoc[cctvcnt].second;
	int cctvKinds = office[x][y];
	int ans = 0;
	for(vector<pair<int,int> > cctv : cctvDic[cctvKinds]){ // cctv 방향 순환
		for(pair<int,int> ndic : cctv){
			currentblind += paintWatch(x,y,ndic,true);
		}
		ans = max(ans,searchAns(cctvcnt+1,currentblind));
		for(pair<int,int> ndic : cctv){
			currentblind -= paintWatch(x,y,ndic,false);
		}
	}
	return ans;
	
}

int main(){
	cctvSetting();
	cin>>n>>m;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin>>office[i][j];
			if(office[i][j]==0) blindspot++;
			else if(office[i][j]<6) {cctvLoc.push_back(make_pair(i,j)); blindspot++;}
			else visited[i][j]=-1;
		}
	}
	cout<<blindspot-searchAns(0,0)<<endl;
}

