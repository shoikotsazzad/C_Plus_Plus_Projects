#include <iostream>
using namespace std;
int binarySearch(int arr[],int n, int key){
    int low =0;
    int high = n-1;
    
    while(low<=high){
        int mid = (low + high)/2;
        if(key== arr[mid]){
            return mid;
        }else if(key > arr[mid]){
            low = mid + 1;
        }else{
            high = mid -1;
        }
    }
    return -1;
}

int main(){
    int arr[] = {1,2,3,4,5,6};
    int n = 6;
    int key = 5;
    int result = binarySearch(arr,n, key);
    if(result != -1){
        cout << "index is: " << result << endl;
    }else{
        cout << "not found" << endl;
    }

    return 0;
}