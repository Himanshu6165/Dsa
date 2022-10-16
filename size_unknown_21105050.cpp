#include <iostream>                    
using namespace std;         

/*
QUESTION:How would you search for an element in an array/list whose size is unknown?
SOLUTION:
  :Take inital value of i as 0 and j as 1.
  :Now increase j to j*2 until arr[j] exceed the key to be searched.
  :Now search the key using binary search between i and j.
*/

//Simple Binary Search Function
int binary_search(int arr[],int i,int j,int key){
    int m=(i+j)/2; //m=middle element
    while(i<=j){   //i=starting index j=ending index
    if(arr[m]==key){
        return m;
        }  
    else{
        if(arr[m]<key){
            i=m+1;
            }
        else{
            j=m-1;
            }
    }
    m=(i+j)/2;
    }
    return -1;  // when element is not present we will return -1
}
//Modified binary search function for array with unknown lenght
int binary_search_unknown(int arr[],int key){
    int i=0;
    int j=1;
    //We will increase j until arr[j] exceeds key to be searched.
    while(arr[j]<key){
        i=j;
        j=2*j;
    }
    //Now calling Simple Binary Search on range i to j.
    return binary_search(arr,i,j,key);
}
int main(){
  int n;
  cin>>n;
  int array[n];
  for(int i=0;i<n;i++){
    cin>>array[i];
  }
  int key;
  cin>>key;
  //calling function without giving size
  int ans=binary_search_unknown(array,key);
  cout<<ans;
  return 0;
}
