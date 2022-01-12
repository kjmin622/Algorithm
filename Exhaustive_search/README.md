## 완전탐색
###### 가능한 방법을 전부 만들어 보는 알고리즘


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


#### 문제 리스트
* [BOJ 10971 외판원순회2](https://www.acmicpc.net/problem/10971)
* [BOJ 15683 감시](https://www.acmicpc.net/problem/15683)
* [BOJ 1339 단어 수학](https://www.acmicpc.net/problem/1339)