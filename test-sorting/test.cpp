#include <iostream>

using namespace std;

int binarySearch(int arr[], int n,int key){
    int low = 0;
    int high = n-1;
    int first =-1;
    

    while( low<= high){
        int mid = (low + high)/2;

        if(key == arr[mid] ){
            first = mid;
            high = mid -1;
        }else if( key> arr[mid]){
             
            low = mid + 1;
        }else if( key < arr[mid]){
            high = mid -1;
        }
    }
    return first;
}

int main(){
    
    int arr[] = {1,2,2,2,3,3,4,5};
    int n = 8;
    int key = 3;

    int result = binarySearch(arr, n, key);
    
    cout << result << endl;
    cout << "Hello" << endl;

    return 0;
}