## 재귀호출
###### 수행할 작업을 유사한 형태의 여러 조각으로 쪼갠 뒤 한 조각을 실행하고, 나머지를 자기 자신을 호출해 실행하는 함수


> ex1) n까지의 합을 계산하는 재귀 함수
```C++
int recursiveSum(int n){
	if(n==1) return 1;
	return n+recursiveSum(n-1);
}
```

> ex2) n개의 원소 중 m개를 고르는 모든 조합
```C++
// m: toPick
void pick(int n, vector<int>& picked, int toPick){
	if(toPick==0){
		printPicked(picked); 
		return;
	}
	int smallest = picked.empty() ? 0 : picked.back()+1;
	for(int next=smallest; next<n; next++){
		picked.push_back(next);
		pick(n,picked,toPick-1);
		picked.pop_back();	
	}
}
```