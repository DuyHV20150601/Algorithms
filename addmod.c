#include <stdio.h>
int main(){
    int a, b, c, z;
    int p= 1000000007;
    scanf("%d%d",&a, &b);
    a= a%p;
    b= b%p;

    z= p-a;
    if(z> b){
        c= a+ b;
    }
    else
    {
        c= b- z;
    }
    
    printf("%d", c);
}