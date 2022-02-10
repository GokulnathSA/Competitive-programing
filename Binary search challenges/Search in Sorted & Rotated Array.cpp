#include<iostream>
#include<algorithm>

using namespace std;


int searchInRotatedarray(int arr[], int key, int left, int right)
{
    if(left>right)
    {
        return -1;
    }

    int mid = (left + right)/2;
    if(arr[mid]==key)
    {
        return mid;
    }

    if(arr[left]<=arr[mid])
    {
        if(key>=arr[left] && key<=arr[mid])
        {
            return searchInRotatedarray(arr, key, left, mid -1);

        }
        return searchInRotatedarray(arr, key, mid+1, right);
    }

    if(key>=arr[mid] && key<=arr[right])
    {
        return searchInRotatedarray(arr, key, mid + 1, right);
    }
    return searchInRotatedarray(arr, key, left, mid -1);
}
int main()
{
    int arr[] = {6,7,8,9,10,1,2,5};
    int n=8, key=8;

    int idx = searchInRotatedarray(arr, key, 0, n-1);
    return 0;
}