#include <stdio.h>
#define MAX 1000

int n;
int q[MAX];
int p[MAX];
int count;

void input(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %d",&q[i],&p[i]);
	}
}

void solve(){
	count =0;
	int test=1;
	for (int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(q[i]>=q[j]||p[i]>=p[j]){
				test=1;
			}
			else{
				test=0;
				break;
			}
		}	
		if(test==1) count++;
	}
	printf("%d",count);
}

int main(){
	input();
	solve();
}