#include "iostream"
using namespace std;
int X[7], xh[10];
int ans, N;
void solution(){
    int T= X[0]*100+ X[1]*10+ X[2] -X[3]*100
-62+ X[4]*1000+ X[5]*100+ X[6]*10 + X[2];
    if (T== N) {
        ans++;
        cout<< X[0]<< X[1]<< X[2]<< X[3]<< X[4] <<X[5] <<X[6]<< endl;
    }
    
}
void init(){
    for(int v = 1; v <= 9; v++)
    {
        /* code */
        xh[v]= 0;
    }
    
}
void TRY(int k){
    for(int v = 1; v <= 9; v++)
    {
        /* code */
        if (xh[v]== 0) {
            /* code */
            X[k]= v;
            xh[v]= 1;
            if (k== 6) {
                solution();
                /* code */
            }
            else
            {
                TRY(k+1);
            }
            xh[v]= 0;    
        }  
    }  
}
void solve(){
    cin>> N;
    init();
    ans= 0;
    TRY(0);
    cout<< ans;
}

int main(int argc, char const *argv[])
{
    solve();
    return 0;
}
