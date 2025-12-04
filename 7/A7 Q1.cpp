#include<iostream>
using namespace std;
void Swap(int& x, int& y){
    int temp=x;
    x=y;
    y=temp;
}
void SelectionSort(int a[], int n){
    for(int i = 0; i < n - 1; i++){ 
        int min= i;
        for(int j= i+1;j<n;j++){ 
            if(a[j] < a[min]){
                min= j;
            }
        }
        if(min!= i){
          Swap(a[i],a[min]);
        }
    }
}
void InsertionSort(int a[],int n){
    for(int i=1;i<n;i++){
         int temp=a[i];
         int j=i;
         while(j>0 && a[j-1]>temp){
             a[j]=a[j-1];
             j=j-1;
         }
         a[j]=temp;
    }
}
void BubbleSort(int a[], int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                Swap(a[j],a[j+1]);
            }
        }
    }
}
void Merge(int a[],int l,int m,int r){
    int n1=m-l+1;
    int n2=r-m;
    int L[100]; 
    int R[100];
    for (int i=0;i<n1;i++)
        L[i]=a[l+i];
    for (int j=0;j<n2;j++)
        R[j]=a[m+1+j];
    int i=0; 
    int j=0; 
    int k=l;
    while (i<n1 && j<n2){
        if (L[i]<=R[j]){
            a[k]=L[i];
            i++;
        }
        else{
            a[k]=R[j];
            j++;
        }
        k++;
    }
    while (i<n1){
        a[k]=L[i];
        i++;
        k++;
    }
    while (j<n2){
        a[k]=R[j];
        j++;
        k++;
    }
}
void MergeSort(int a[],int l,int r){
    if(l>=r){
        return;
    }
    int m=l+(r-l)/2;
    MergeSort(a,l,m);
    MergeSort(a,m+1,r);
    Merge(a,l,m,r);
}
int Partition(int a[], int low, int high) {
    int pivot=a[high];
    int i=(low-1); 
    for(int j=low;j<=high-1;j++){
        if (a[j]<pivot){
            i++;
            Swap(a[i], a[j]); 
        }
    }
    Swap(a[i+1],a[high]);
    return (i+1);
}
void QuickSort(int a[], int low, int high) {
    if (low < high) {
        int p=Partition(a,low,high);
        QuickSort(a,low,p-1);
        QuickSort(a,p+1,high);
    }
}
int main(){
    int n,l;
    cout <<"Enter number of elements: ";
    cin >> n;
    int b[100];
    for(int i = 0; i < n; i++){
        cout<<"Enter element " << i + 1 << ": ";
      cin>>b[i];  
    }
    cout<<"Unsorted array is:"<<endl;
    for(int i=0;i<n;i++){
        cout<<b[i]<<" ";
    }
    cout<<endl;
    cout<<"what sorting method would you like to use?\n1.Selection sort\n2.Insertion sort\n3.Bubble Sort\n4.Merge Sort\m5.Quick Sort\n";
    cin>>l;
    switch(l){
        case 1:
        SelectionSort(b, n);
        break;
        case 2:
        InsertionSort(b,n);
        break;
        case 3:
        BubbleSort(b,n);
        break;
        case 4:
        MergeSort(b,0,n-1);
        break;
        case 5:
        QuickSort(b,0,n-1);
        break;
        default:
        cout<<"incorrect option selected";
        break;
    }
    cout<<"Sorted array is:"<< endl;
    for(int i=0;i<n;i++){
        cout<<b[i]<<" ";
    }
    cout<<endl;
    return 0;
}
