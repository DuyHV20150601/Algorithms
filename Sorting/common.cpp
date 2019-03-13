/*
    assume that we are given 2 array with different length, find the number of common number of 2 these arays
*/

#include <stdio.h>
#define MAX 1000000
#include "iostream"
using namespace std;
// HEap sort
// int a[MAX];
int n;
void input(int *a)
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        // scanf("%d", &a[i]);
        cin>> a[i];
}


void swap(int i, int j, int * a)
{
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}
void heapify(int i, int N, int* a)
{
    int L = 2 * i;
    int R = 2 * i + 1;
    int max = i;
    if (L <= N && a[L] > a[i])
        max = L;
    if (R <= N && a[R] > a[max])
        max = R;
    if (max != i)
    {
        swap(i, max, a);
        heapify(max, N, a);
    }
}
void buildHeap(int* a)
{
    for (int i = n / 2; i >= 1; i--)
        heapify(i, n, a);
}

void heapSort(int* a)
{
    buildHeap(a);
    for (int i = n; i > 1; i--)
    {
        swap(1, i, a);
        heapify(1, i - 1, a);
    }
}
void printResult(int* a)
{
    for (int i = 1; i <= n; i++)
        // printf("%d  ", a[i]);
        cout<< a[i]<< " ";
    cout<< endl;
}

int binarySearch(int *a, int *b, int number, int L, int R)
{
    
    int midValue = (sizeof(a) / sizeof(int)) / 2 + 1;
    int lengthb = (sizeof(b) / sizeof(int));
    int lengtha = (sizeof(a) / sizeof(int));
    int count= 0;
    if (lengtha > lengthb)
    {
        int temp = lengtha;
        lengtha = lengthb;
        lengthb = temp;
    }
    for(int i = 0; i < lengtha; i++)
    {
        /* code */
        if (a[i]== b[lengthb/2]) {
            /* code */
            count++;
        }
        if (a[i]< b[lengthb/2]) {
            /* code */
            binarySearch(a, b, a[i], L, lengthb/2-1);
        }
        else
        {
            binarySearch(a, b, a[i], lengthb/2, lengthb);
        }
        
        
        return count;
    }
    
}
int main()
{
    int* a;
    input(a);
    heapSort(a);
    printResult(a);
}