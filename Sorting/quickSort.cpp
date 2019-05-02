#include "iostream"

using namespace std;
#define max 100000
int a[max];
int n;
void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

void swap(int i, int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int partition(int L, int R, int indexPivot)
{
    int pivot = a[indexPivot];
    swap(indexPivot, R);
    int storeIndex = L;
    for (int i = L; i <= R - 1; i++)
    {
        /* code */
        if (a[i] < pivot)
        {
            swap(storeIndex, i);
            storeIndex++;
        }
    }
    swap(storeIndex, R);
    return storeIndex;
}

void quickSort(int L, int R)
{
    if (L < R)
    {
        int index = (L + R) / 2;
        index = partition(L, R, index);
        if (index > L)
        {
            quickSort(L, index - 1);
        }
        if (index < R)
        {
            /* code */
            quickSort(index + 1, R);
        }
    }
}
void printResult()
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
void biggerSizeArray()
{

    for (int i = 0; i < max; i++)
    {
        cout << a[i] << " ";
        a[i] = rand() % 1000000 + 1;
    }
    cout << endl;
}
int main(int argc, char const *argv[])
{
    /* code */
    // input();
    n = max;
    biggerSizeArray();
    quickSort(0, n - 1);
    printResult();
    return 0;
}
