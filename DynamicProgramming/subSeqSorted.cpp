/*
    assume that we have an array {a1, a2, a3,...., an}
    find the number of the sub array's elements that has elements that are not necessary nearby each other but being increase
*/

#include <iostream>
using namespace std;
#include <stdlib.h> /* srand, rand */
#define max 10000000

int array[max];
int n;
void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        array[i] = rand() % 100;
        if (i % (4) == 0)
        {
            array[i] = -rand() % 100;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
}

void solve()
{
    int s[max];
    int ans = 1;
    s[1] = 1;
    for (int i = 2; i < n; i++)
    {
        s[i] = 1;
        for (int j = 1; j <= i - 1; j++)
        {
            if (array[j] < array[i])
            {
                if (s[j] < s[j + 1])
                {
                    /* code */
                    s[i] = s[j] + 1;
                }
            }
        }
        if (ans < s[i])
        {
            ans = s[i];
        }
    }
    cout << ans;
}
int main(int argc, char const *argv[])
{
    /* code */
    input();
    solve();
    return 0;
}
