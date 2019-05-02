#include <iostream>
#define max 10000000 
using namespace std;
int n;
int count;
int m[max];
char c[2]= {'+', '-'};
void input(){
    cin>> n;
    if (n<2 || n> 30) {
        cout<< "Enter n again: "<< endl;
        cin>> n;
    }
    for(int i = 0; i < n; i++)
    {
        cin>> m[i];
    }
    count= 0;
}
int main(int argc, char const *argv[])
{
    
    return 0;
}
