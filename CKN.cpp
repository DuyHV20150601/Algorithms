#include <iostream>
using namespace std;
#define P 1000000007

int m[1000][1000];

void init()
{
    for(int i = 0; i < 1000; i++)
        for(int j = 0; j < 1000; j++)
            m[i][j] = -1;
}
int C(int k, int n)
{
    if(k ==  0 || k == n) m[k][n] = 1;
    else
    {
        if (m[k][n] == -1)
        {
//             m[k][n] = C(k-1, n-1) + C(k, n-1);
             int a = C(k-1, n-1) % P;
             int b = C(k, n-1) % P;
             int tmp = P - a;
             if (tmp < b) m[k][n] = b - tmp;
             else m[k][n] = a + b;
        }
    }
    return m[k][n];
}

int main()
{
    init();
    int k, n;
    cin >> k >> n;
    cout << C(k, n) << endl;
}