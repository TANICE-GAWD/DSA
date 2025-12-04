#include<iostream>
using namespace std;
void maxHeapify(int arr[],int n,int i){
    int largest=i;
    int l=2*i+1,r=2*i+2;
    if(l<n && arr[l]>arr[largest])largest=l;
    if(r<n && arr[r]>arr[largest])largest=r;
    if(largest!=i){
        int temp=arr[i];arr[i]=arr[largest];arr[largest]=temp;
        maxHeapify(arr,n,largest);
    }
}
void minHeapify(int arr[],int n,int i){
    int smallest=i;
    int l=2*i+1,r=2*i+2;
    if(l<n && arr[l]<arr[smallest])smallest=l;
    if(r<n && arr[r]<arr[smallest])smallest=r;
    if(smallest!=i){
        int temp=arr[i];arr[i]=arr[smallest];arr[smallest]=temp;
        minHeapify(arr,n,smallest);
    }
}
void heapSortInc(int arr[],int n){
    for(int i=n/2-1;i>=0;i--){maxHeapify(arr,n,i);}
    for(int i=n-1;i>0;i--){
        int temp=arr[0];arr[0]=arr[i];arr[i]=temp;
        maxHeapify(arr,i,0);
    }
}
void heapSortDec(int arr[],int n){
    for(int i=n/2-1;i>=0;i--){minHeapify(arr,n,i);}
    for(int i=n-1;i>0;i--){
        int temp=arr[0];arr[0]=arr[i];arr[i]=temp;
        minHeapify(arr,i,0);
    }
}
int main(){
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;
    int a[100],b[100];
    cout<<"Enter "<<n<<" elements:\n";
    for(int i=0;i<n;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    heapSortInc(a,n);
    cout<<"Sorted in increasing order: ";
    for(int i=0;i<n;i++){cout<<a[i]<<" ";}
    cout<<endl;
    heapSortDec(b,n);
    cout<<"Sorted in decreasing order: ";
    for(int i=0;i<n;i++){cout<<b[i]<<" ";}
    cout<<endl;
    return 0;
}
