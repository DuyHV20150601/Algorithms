#include <iostream>
using namespace std;
#define MAX 100000

int N,M,S;
int a[MAX];
int count;

void solve(){
	for(int i=1;i<=N;i++){
		S=a[i];
		if(S>M) continue;		
		count++;
		for(int j=i+1;j<=N;j++){
				S=S+a[j];
				if(S>M) break;
				count++;
		}
	}
    cout<< count;
}
int main(){
	// scanf("%d %d",&N,&M);
    cin>> N>> M;
	for(int i=1;i<=N;i++){
		// scanf("%d",&a[i]);
        cin>> a[i];
	}
	S=0;
	count=0;
	solve();
}