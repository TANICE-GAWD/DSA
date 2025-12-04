#include<iostream>
using namespace std;
void Swap(int& x, int& y){
    int temp=x;
    x=y;
    y=temp;
}
int main(){
    int arr[]={9, 1, 4, 7, 3, 8, 2, 6, 5};
    int n=sizeof(arr)/sizeof(arr[0]);
    int left=0, right=n-1;
    while(left<right){
        int min=left, max=left;
        for(int i=left; i<=right;i++){
            if(arr[i]<arr[min]){ 
                min=i;}
            if(arr[i] > arr[max]){
                max=i;}
        }
        swap(arr[left], arr[min]);
        if(max==left)
            max=min;
        swap(arr[right], arr[max]);
        left++;
        right--;
    }
    cout<<"Sorted Array: ";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    return 0;
}
