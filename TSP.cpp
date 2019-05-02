#include "iostream"
using namespace std;
#define max 100

int n;
int c[max][max];
bool m[max];
int x[max]; // luu tru loi giai trong qua trinh liet ke
int x_min[max];
int f;     // khoang cach tich luy
int f_min; // khoang cac nho nhat   
void input(char *fn)
{
    FILE *f = fopen(fn, "r");
    fscanf(f, "%d", &n);
    for (int i = 1; i <= n; i++)
    {
        /* code */
        for (int j = 1; j <= n; j++)
        {
            /* code */
            fscanf(f, "%d", &c[i][j]);
        }
    }
    fclose(f);
}

void updateBest()
{
    if (f + c[x[n]][x[1]] < f_min)
    {
        /* code */
        f_min = f + c[x[n]][x[1]];
        for (int i = 1; i <= n; i++)
        {
            /* code */
            x_min[i] = x[i];
        }
        printf("best= %d\n", f_min);
    }
}
void TRY(int k)
{
    for (int v = 1; v <= n; v++)
    {
        /* code */
        if (!m[v])
        {
            /* code */
            x[k] = v;
            m[v] = true;
            f = f + c[x[k - 1]][x[k]];
            if (k == n)
            {
                /* code */
                updateBest();
            }
            else
            {
                TRY(k + 1);
            }
            f = f - c[x[k - 1]][x[k]];
            m[v] = false;
        }
    }
}

void printSolution()
{
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", x_min[i]);
    }
}
void solve()
{// start at 1st element
    for (int v = 1; v <= n; v++)
        m[v] = false;
    /* code */
    f_min = 99999999;
    f = 0;
    x[1] = 1;
    m[1] = true;
    TRY(2);
}
int main(int argc, char const *argv[])
{
    input("TSP.INP");
    solve();
    printSolution();
    return 0;
}
