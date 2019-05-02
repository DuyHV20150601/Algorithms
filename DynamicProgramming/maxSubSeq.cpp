/*
assume that we have an array {a1, a2,.... an}, Find the sub array that has the biggest sum {ai, ai+1,..... aj}
*/
#include <stdio.h>

#define MAX 10000

int a[MAX];
int n;

// void solve(){
// 	int S[MAX];// for remembering the result of sub problems
// 	S[0]=a[0];
// 	int ans=S[0];
// 	for(int i=1;i<n;i++){
// 		if(S[i-1]>0){
// 			S[i]=S[i-1]+a[i];			
// 		}else{
// 			S[i]=a[i];
// 		}
// 		if(ans<S[i]){
// 			ans=S[i];
// 		}
// 	}
// 	printf("%d",ans);
// }
void solve(){
	int S;// for remembering the result of sub problems
	S=a[0];
	int ans=S;
	for(int i=1;i<n;i++){
		if(S>0){
			S=S+a[i];			
		}else{
			S=a[i];
		}
		if(ans<S){
			ans=S;
		}
	}
	printf("%d",ans);
}
void input(){
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
}

int main(){
	input();
	solve();
}