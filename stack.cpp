#include<iostream>
using namespace std;

template <class type>
class stack{
	private:
		int top;
		int maxsize;
		type *array;
		void full(){cout<<endl<<"data structure is full.";}
		void empty(){cout<<endl<<"data structure is empty.";}
	public:
		stack(int );
		bool isempty();
		bool isfull();
		void add(const type &);
		type* Delete(type &);
};

template <class type>
stack<type>::stack(int n){
	maxsize = n;
	array = new type[maxsize];
	top=-1;
}
template <class type>
bool stack<type>::isfull(){
	if(top== maxsize -1) return true;
	else return false;
}
template <class type>
bool stack<type>::isempty(){
	if (top == -1) return true;
	else return false;
}
template <class type>
void stack<type>::add(const type &x){
	if(isfull()) full();
	else array[++top] = x;
}
template <class type>
type* stack<type>::Delete(type &x){
	if(isempty()){
		empty(); //return 0;
	} 
	else x = array[top--];
	return &x;
}

main(){
	
	stack<int> s(5);
	s.add(1);
	s.add(2);
	s.add(6);
	s.add(9);
	s.add(4);
	//extra
	s.add(10);
	
	int x;
	s.Delete(x);
	cout<<endl<<x;
	s.Delete(x);
	cout<<endl<<x;
	
}



