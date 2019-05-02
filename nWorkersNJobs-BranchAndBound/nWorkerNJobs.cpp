#include "iostream"
#include "stdlib.h"
using namespace std;
#define max 100

int c[max][max], x[max], xMin[max], f, fMin, n, cMin;
bool arrJobsSigned[max];
void genData(char* fn, int n){
    FILE* f = fopen(fn, "w");
    fprintf(f, "%d\n", n);
    for(int i = 1; i <= n; i++){
        for(int j=1; j <= n; j++){
            int x = rand()%20 + 1;
            if(i==j) x = 0;
            fprintf(f, "%d ", x);
        }
        fprintf(f, "\n");
    }
    fclose(f);
}
void input(char *fn)
{
    FILE *f = fopen(fn, "r");
    cMin = 99999;
    fscanf(f, "%d", &n);
    for (int i = 1; i <= n; i++)
    {
        /* code */
        for (int j = 1; j <= n; j++)
        {
            /* code */
            fscanf(f, "%d", &c[i][j]);
            if (cMin > c[i][j])
            {
                /* code */
                cMin = c[i][j];
            }
        }
    }
    for (int i = 1; i <=n; ++i) {
        for (int j = 1; j <=n; ++j) {
            cout<< c[i][j]<< " ";
        }
        cout<< endl;
    }
    fclose(f);
}
void updateBest()
{
    if (f < fMin)
    {
        /* code */
        fMin = f ;
        for (int i = 1; i <= n; i++)
        {
            /* code */
            xMin[i] = x[i];
        }
        printf("best: %d\n", fMin);
    }
}
void printSolution()
{

    for (int i = 1; i <= n; i++)
    {
        printf("%d: %d ", xMin[i], i);
    }
}

void TRY(int k) {

    for (int v = 1; v <= n; v++) {
        /* code */
        if (!arrJobsSigned[v]) {
            /* code */
            x[k] = v;
            arrJobsSigned[v] = true;
            f = f + c[v][k];

            if (k == n) {
                updateBest();
            } else {
                int g = f + cMin * (n - k);
                if (g < fMin) {
                    /* code */
                    TRY(k + 1);
                }
            }
            f = f - c[v][k];
            arrJobsSigned[v] = false;
        }
    }
}
void solve()
{ // start at 1st element
    for (int v = 1; v <= n; v++)
    {
        arrJobsSigned[v] = false;
    }

    /* code */
    fMin = 99999;
    f = 0;
    TRY(1);
}

int main(int argc, char const *argv[])
{
    /* code */
    // genData("INPUT20.INP", 20);
    input("INPUT.INP");
    solve();
    printSolution();
    return 0;
}
