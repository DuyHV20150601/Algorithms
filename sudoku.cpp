#include <iostream>
using namespace std;

bool mr[9][10], mc[9][10], m[3][3][10];
int x[9][9];
bool found;
void init(){
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            mr[i][j]= false;
            mc[i][j]= false;
        }
        
    }
    for(int  i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            for(int k = 0; k < 9; k++)
            {
            m[i][j][k]= false;
            }
            
        }
        
    }
    
    
}
void solution(){
    for(int i = 0; i < 9; i++)
    {
        /* code */
        for(int j = 0; j < 9; j++)
        {
            /* code */
            cout<< x[i][j];
        }
        cout<< endl;
        
    }
    
}
void TRY(int r, int c){
    for(int v = 0; v <= 9; v++)
    {
        if (!mr[r][v]&& !mc[v][c] && !m[r/3][c/3][v]) {
            x[r][c]= v;
            mr[r][v]= true;
            mc[c][v]= true;
            m[r/3][c/3][v]= true;
            if (r==8 && c== 8) {
                solution();
                /* code */
            }
            else
            {
                if (c== 8) {
                    TRY(r+1, 0);
                    /* code */
                }
                else
                {
                    TRY(r, c+1);
                }
                mr[r][v]= false;
                mc[c][v]= false;
                m[r/3][c/3][v]= false;   
            }
            
            

            /* code */
        }
        
       /* code */
    }
    
}
int main(){
init();
TRY(0, 0);

}