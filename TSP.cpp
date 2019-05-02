#include <stdio.h>
#define MAX 16 

int N,M;
int c[MAX][MAX];
bool m[MAX];
int x[MAX];
int f;
int count;

void input(){
	scanf("%d %d",&N,&M);
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			scanf("%d",&c[i][j]);
		}
	}
}
void solution(){
	if(f+c[x[N]][x[1]]<=M){
		count++;
}}

void TRY(int k){
	for(int v=2;v<=N;v++){
		if(!m[v]){
			x[k]=v;
			m[v]=true;
			f=f+c[x[k-1]][x[k]];
			if(k==N){
				solution();
			}else{
			    if(f<=M) TRY(k+1);
			}
			f=f-c[x[k-1]][x[k]];
			m[v]=false;
		}
	}
}

void solve(){
	for (int v=1;v<=N;v++) m[v]=false;
	f=0;
	x[1]=1;m[1]=true;
	TRY(2);
	printf("%d",count);
}

int main(){
	count=0;
	input();
	solve();
}