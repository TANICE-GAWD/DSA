#include<iostream>
using namespace std;
class MaxPQ{
    int heap[100];
    int size;
public:
    MaxPQ(){size=0;}
    bool isEmpty(){return size==0;}
    void swapVal(int &a,int &b){int t=a;a=b;b=t;}
    void insert(int x){
        if(size==100){cout<<"Overflow\n";return;}
        heap[size]=x;
        int i=size;
        size++;
        // heapify up
        while(i>0){
            int parent=(i-1)/2;
            if(heap[parent]<heap[i]){swapVal(heap[parent],heap[i]);i=parent;}
            else{break;}
        }
    }
    int getMax(){
        if(isEmpty()){cout<<"PQ empty\n";return -1;}
        return heap[0];
    }
    void heapifyDown(int i){
        while(true){
            int l=2*i+1,r=2*i+2;
            int largest=i;
            if(l<size && heap[l]>heap[largest]){largest=l;}
            if(r<size && heap[r]>heap[largest]){largest=r;}
            if(largest!=i){swapVal(heap[i],heap[largest]);i=largest;}
            else{break;}
        }
    }
    int extractMax(){
        if(isEmpty()){cout<<"PQ empty\n";return -1;}
        int maxVal=heap[0];
        heap[0]=heap[size-1];
        size--;
        heapifyDown(0);
        return maxVal;
    }
    void display(){
        cout<<"Heap array: ";
        for(int i=0;i<size;i++){cout<<heap[i]<<" ";}
        cout<<endl;
    }
};
int main(){
    MaxPQ pq;
    pq.insert(10);
    pq.insert(40);
    pq.insert(5);
    pq.insert(30);
    pq.insert(50);
    pq.display();
    cout<<"Max element: "<<pq.getMax()<<endl;
    cout<<"Extracting elements in priority order: ";
    while(!pq.isEmpty()){
        cout<<pq.extractMax()<<" ";
    }
    cout<<endl;
    return 0;
}
