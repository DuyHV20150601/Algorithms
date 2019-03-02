#include <stdio.h>
// SERIAL
// lexical Order = Thu tu tu dien
int sum, a[100], s[100];
void init(){
	int i;
	for(i=0;i<100;i++){
		s[i]= 1;
	}
}
void input(){
	scanf("%d",&sum);
}
void solution(int pos){
	int i;
	for(i=0;i<pos;i++){
	   printf("%d ",a[i]);
	}
	printf("\n");
}
void back(int pos){
	int i;
	for(i=1;i<=sum;i++){
		if(i>=a[pos-1]){
		a[pos] = i;
		sum = sum - i;
		if(sum==0){
			solution(pos+1);
		}
		else back(pos+1);
		sum = sum + i;

		}
	}
	
}
int main(void){
	init();
	input();
	back(0);




	return 0;
}