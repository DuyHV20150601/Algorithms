/*
write c program that reads an integer value N, S and a set of positive integer {a1,a2, a3,.. ,an}
from stdin, prints to stdout the number Q of subsets of{a1, a2,... , an}
such that the sum of the all elements of  these subsets equal to S
*/

#include "iostream"

using namespace std;

int arr2[100];
void init(int n, int s, int arr[1000], int count){
    cout<< "nhap vao n: "<< endl;
    cin>> n;
    cout<< "nhap vao s: "<< endl;
    cin>> s;
    count= 0;
    // arr= new(int*)[n*sizeof(int)];
    for(int i = 0; i <n; i++)
    {
        /* code */
        arr[i]= i+ 1;
    }
    for(int i = 0; i < n; i++)
    {
        cout<< arr[i];
    }

}

// arr[]= [1,2,3,4,5], s= 10
bool check(int v, int k){
    return true;
}
void TRY(int v,int n, int arr[1000] ){
    for(v = 1; v <= n; v++)
    {

    }
    
}
int main(int argc, char const *argv[])
{
    int n, s, count;
    int arr[1000];
    /* code */
    init(n, s, arr, count);
    return 0;
}
