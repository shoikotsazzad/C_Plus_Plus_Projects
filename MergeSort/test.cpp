#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid,int right){
   int n1 = mid -left +1;
   int n2 = right -mid;

   int L[100], R[100]; // temporary arrays

   for(int i=0; i<n1; i++){
         L[i] = arr[left + i];
   }
   for(int j=0; j<n2; j++){
         R[j] = arr[mid + 1 + j];
   }

   int i=0, j=0, k=left;

   while (i<n1 && j<n2){
       if( L[i] <= R[j]){
        arr[k] = L[i];
        i++;
       }else{
        arr[k] = R[j];
        j++;
       }
       k++;
   }


   while(i<n1){
       arr[k] = L[i];
       i++;
       k++;
   }    

    while(j<n2){
         arr[k] = R[j];
         j++;
         k++;
    }
}

void mergeSort(int arr[], int left, int right){
    if(left < right){
        int mid = left + (right - left) / 2; // find the mid point
        mergeSort(arr, left, mid); // sort the left half
        mergeSort(arr, mid + 1, right); // sort the right half
        merge(arr, left, mid, right); // merge the sorted halves    
    }
}

int main(){
    int arr[6] = {38, 27, 1, 3, 9, 82}; // fixed array of 6 numbers
    
    mergeSort(arr, 0, 5);
    cout << "Sorted array: ";
    for(int i=0; i<6; i++){
        cout << arr[i] << " ";
        
    }

}