#include<iostream>
using namespace std;

template <class type>
class queue{
	private:
		int rear , front;
		int maxsize;
		type *array;
		void full(){cout<<endl<<"data structure is full.";	}
		void empty(){cout<<endl<<"data structure is empty.";}
		public:
			bool isfull();
			bool isempty();
			queue(int);
			void add(const type &);
			type* Delete(type &);
};

template <class type>
queue<type>::queue(int n){
	maxsize = n;
	array= new type[maxsize];
	rear = front = -1;
}
template <class type>
bool queue<type>::isfull(){
	if(rear == maxsize -1) return true;
	else return false;
}
template <class type>
bool queue<type>::isempty(){
	if (rear == front) return true;
	else return false;
}
template <class type>
void queue<type>::add(const type &x){
	if(isfull()) full();
	else array[++rear] = x;
}
template <class type>
type* queue<type>::Delete(type &x){
	if(isempty()){
	    empty(); //dar in fagi nadarad.
		return 0;	
	} 
	else x = array[++front];
	return &x;
}

main(){
	
	queue<int> s(3);
	s.add(3);
	s.add(1);
	s.add(8);
	//extra
	s.add(5);
	
	int x;
	s.Delete(x);
	cout<<endl<<x;
	s.Delete(x);
	cout<<endl<<x;
}



