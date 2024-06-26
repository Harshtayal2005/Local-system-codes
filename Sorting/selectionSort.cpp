#include <iostream>
#include <vector>
#include <string>
using namespace std;

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int mini = arr[i];
        int idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < mini)
            {
                mini = arr[j];
                idx = j;
            }
        }
        swap(arr[i], arr[idx]);
    }
}
int main()
{
    int arr[] = {5, 3, 4, 6, 7, 1, 0};
    int n = 7;
    selectionSort(arr, n);
    for (int ele : arr)
    {
        cout << ele << " ";
    }
    cout << endl;
    return 0;
}