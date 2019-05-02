#include <stdio.h>
#include <queue>
#define MAX 1000

using namespace std;
struct State{
	int x;//luong nuoc coc 1
	int y;//luong nuoc coc 2
	State* parent;
};

int a,b,c;
bool m[MAX][MAX];
queue<State*> Q ;
 
int max(int a, int b){
	return a>b?a:b;
}

State* initState(){
	State* s = new State;
	s->x=0;
	s->y=0;
	return s;
}

bool checkTarget(State* s){
	return s->x==c||s->y==c;
}

bool genStateEmpty1(State* s){ 
	if(m[0][s->y]) return false;
	State* news = new State;
	news->x=0; news->y=s->y; news->parent=s;
	m[news->x][news->y]=true;
	Q.push(news);
	return checkTarget(news);
}
bool genStateEmpty2(State* s){
	if(m[s->x][0]) return false;
	State* news = new State;
	news->x=s->x; news->y=0; news->parent=s;
	m[news->x][news->y]=true;
	Q.push(news);
	return checkTarget(news);
}
bool genStateFill1(State* s){
	if(m[a][s->y]) return false;
	State* news = new State;
	news->x=a; news->y=s->y; news->parent=s;
	m[news->x][news->y]=true;
	Q.push(news);
	return checkTarget(news);
}
bool genStateFill2(State* s){
	if(m[s->x][b]) return false;
	State* news = new State;
	news->x=s->x; news->y=b; news->parent=s;
	m[news->x][news->y]=true;
	Q.push(news);
	return checkTarget(news);
}
bool genState1to2(State* s){
	if(s->x+s->y>b){
		if(m[s->x+s->y-b][b]) return false;
		State* news = new State;
		news->x=s->x+s->y-b; news->y=b; news->parent=s;
		m[news->x][news->y]=true;
		Q.push(news);
		return checkTarget(news);
	}else{
		if(m[0][s->x+s->y]) return false;
		State* news = new State;
		news->x=0; news->y=s->x+s->y; news->parent=s;
		m[news->x][news->y]=true;
		Q.push(news);
		return checkTarget(news);
	}
}
bool genState2to1(State* s){
	if(s->x+s->y>a){
		if(m[a][s->x+s->y-a]) return false;
		State* news = new State;
		news->x=a; news->y=s->x+s->y-a; news->parent=s;
		m[news->x][news->y]=true;
		Q.push(news);
		return checkTarget(news);
	}else{
		if(m[s->x+s->y][0]) return false;
		State* news = new State;
		news->x=s->x+s->y; news->y=0; news->parent=s;
		m[news->x][news->y]=true;
		Q.push(news);
		return checkTarget(news);
	}
}

void solve(){
	State* s0=initState();
	Q.push(s0);
	while(!Q.empty()){
		State* s=Q.front();
		Q.pop();
		if(genStateEmpty1(s)) break;
		if(genStateEmpty2(s)) break;
		if(genStateFill1(s)) break;
		if(genStateFill2(s)) break;
		if(genState1to2(s)) break;
		if(genState2to1(s)) break;
	}
	if(Q.empty()) printf("-1");
	else{
		State* e= Q.back();
		int count=0;
		while(e!=s0){
			printf("(%d,%d)\n",e->x,e->y);
			e=e->parent;
			count++;
		} 
		e=s0;
		printf("(%d,%d)\n",e->x,e->y);
		printf("%d",count);
	}
}

int main(){
	scanf("%d %d %d",&a,&b,&c);
	for(int i=0; i<=max(a,b);i++){
		for(int j=0;j<=max(a,b);j++){
			m[i][j]=false;
		}
	}
	m[0][0]=true;
	solve();	
}