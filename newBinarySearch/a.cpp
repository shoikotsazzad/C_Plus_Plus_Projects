// Online C compiler to run C program online
#include <stdio.h>
void bubble_sort(int arr[],int n){
    int count =0;
    for (int i=n;i>=1;i--){
        for(int j=0;j<i;j++){
           // printf("Before swap %d",arr[j]);
            if(arr[j]>arr[i]){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
            count++;
            
            
        }
        
    }
    
    
    
    printf("Total Number of swap = %d\n ",count);
    
}
void printarray(int arr[],int n){
    printf("Given Array =");
    for (int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main() {
   int n=5;
   int arr[]={5,1,4,2,8};
   printarray(arr,n);
   
   bubble_sort(arr,n);
      printarray(arr,n);


    return 0;
}