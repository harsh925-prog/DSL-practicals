//Harsh Gangadhar Chakote
//SE-II (Q)
//Roll No.: 31
//PRN: F23112034

// Write a program to implement merge sort in C++ language.

#include <iostream>
using namespace std;
/* Function to merge the subarrays of a[] */
void merge(int a[], int beg, int mid, int end)
{
    int i, j, k;
    int n1 = mid - beg + 1;
    int n2 = end - mid;
    int LeftArray[n1], RightArray[n2]; // temporary arrays
    /* copy data to temp arrays */
    for (int i = 0; i < n1; i++)
        LeftArray[i] = a[beg + i];
    for (int j = 0; j < n2; j++)
        RightArray[j] = a[mid + 1 + j];
    i = 0;   /* initial index of first sub-array */
    j = 0;   /* initial index of second sub-array */
    k = beg; /* initial index of merged sub-array */
    while (i < n1 && j < n2)
    {
        if (LeftArray[i] <= RightArray[j])
        {
            a[k] = LeftArray[i];
            i++;
        }
        else
        {
            a[k] = RightArray[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        a[k] = LeftArray[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        a[k] = RightArray[j];
        j++;
        k++;
    }
}
void mergeSort(int a[], int beg, int end)
{
    if (beg < end)
    {
        int mid = (beg + end) / 2;
        mergeSort(a, beg, mid);
        mergeSort(a, mid + 1, end);
        merge(a, beg, mid, end);
    }
}
/* Function to print the array */
void printArray(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << a[i] << " ";
}
int main()
{
    int n;
    cout<<"Enter size of array:";
    cin>>n;
    int a[n];
    cout<<"Enter array elements to be sorted:"<<endl;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<endl;
    cout << "Before sorting array elements are - \n";
    printArray(a, n);
    mergeSort(a, 0, n - 1);
    cout << "\nAfter sorting array elements are - \n";
    printArray(a, n);
    return 0;
}

//Output:
/*
Enter size of array:6
Enter array elements to be sorted:
2
8
4
6 
10
3

Before sorting array elements are - 
2 8 4 6 10 3 
After sorting array elements are - 
2 3 4 6 8 10
*/