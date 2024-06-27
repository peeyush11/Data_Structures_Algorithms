#include <bits/stdc++.h>

int BinarySearch(int arr[], int low, int high, int target){

    while(low <= high){
        int mid = low + (high-low)/2;

        if(arr[mid] == target){
            return mid;
        }

        if(arr[mid] < target){
            low = mid + 1;
        }

        if(arr[mid] > target){
            high = mid - 1;
        }
    }

    return -1;
}

int BinarySearchRecursive(int arr[], int low, int high, int target){

    if(low <= high){

        int mid = low + (high - low)/2;

        if(arr[mid] == target)
            return mid;

        if(arr[mid] < target)
            return BinarySearchRecursive(arr, mid+1, high, target);

        if(arr[mid] > target)
            return BinarySearchRecursive(arr, low, mid-1, target);
    }

    return -1;
}
int main(){

    int arr[] = {5,8,10,13,15,17,20,22,25};
    int n = sizeof(arr)/sizeof(arr[0]);
    int target;

    std::cout<<"Enter a number to search ";
    std::cin>>target;
    
    // int result = BinarySearch(arr, 0, n-1, target);
    int result = BinarySearchRecursive(arr, 0, n-1, target);

    if(result == -1)
        std::cout<<"Element not found in array\n";
    else
        std::cout<<"Element found at index: "<<result<<"\n";

    return 0;
}