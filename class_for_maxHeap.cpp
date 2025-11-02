#include<iostream>
using namespace std;

class maxheap{
	private:
		int *arr;
		int size;
		int currentsize;
	public:
		maxheap(int n){
			currentsize = n;
			size=0;
			arr=new int[n];
		}
		int parent(int x){return (x-1)/2;}
		int left(int x){return x*2+1;}
		int right(int x){return x*2+2;}
		void insert(int k){
			if(size== currentsize){
				cout<<endl<<"overflow.";
				return;
			}
			size++;
			int i=size-1;
			arr[i] =k;
			while(i && arr[i]> arr[parent(i)]){
				swap(arr[i] ,arr[ parent(i)]);
				i=parent(i);
			}
		}
		int remove(){
			if(size<=0){
				cout<<endl<<"no element.";
				return INT_MAX;
			}
			else if(size==1){
				size--;
				return arr[0];
			}
			else{
				int root = arr[0];
				arr[0]=arr[size-1];
				size--;
				maxheapii(0);
				return root;
			}
		}
		void maxheapii(int i){
			int l=left(i);
			int r=right(i);
			int largest=i;
			if(l<size && l>largest)
				largest=l;
			else if(r<size && r>largest)
				largest=r;
			if(largest !=i){
				swap(arr[i] , arr[largest]);
				maxheapii(largest);
			}
		}
		void print(){
			if(size==0){
				cout<<endl<<"no element.";
				return;
			}
			cout<<endl<<"print: ";
			for(int i=0;i<size;i++){
				cout<<arr[i]<<"  ";
			}
		}
};

main(){
	
	maxheap m(10);
	m.insert(99);
	m.insert(2);
	m.insert(4);
	m.insert(6);
	m.print();
	cout<<endl<<m.remove();
	cout<<endl<<m.remove();
	m.print();
	cout<<endl<<m.remove();
	//
	cout<<endl<<m.remove();
	m.print();
}