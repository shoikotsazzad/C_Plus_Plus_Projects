#include <iostream>
using namespace std;

int main(){
    int arr[] = {1, 5, 50,-6,43};
    int size =5;

    int smallest = INT_MAX;
    int largest = INT_MIN;

     for(int i=0; i<size; i++){
        smallest = min(arr[i], smallest);
        largest = max(arr[i], smallest);
     }
    
    cout<<"smallest = " << smallest << endl;
    cout << "largest = " << largest << endl;
}