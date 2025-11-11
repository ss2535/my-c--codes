#include<iostream>
using namespace std;
template<class type>
class queue{
	private:
		class node{
			public:
				type data;
				node *link;
				node(type d , node *l=0)
				{
					data = d;
					link = l;
				}
		};
		node *rear, *front;
	public:
		queue(){rear= front =0;}
		void add(type x){
			if(front==0)
				front = rear= new node(x,0);
			else
				rear = rear->link= new node(x,0);
		}
		type Delete(){
			if(front ==0){
				cout<<endl<<"queue is empty";
				return 0;
			}
			else{
				type k = front->data;
				node *del= front;
				front= front->link;
				delete del;
				return k;
			}
		}
};

main(){
	
	queue<int>n;
	for(int i =0;i<10;i++)
		n.add(i);
	
	for(int i=0;i<12;i++)
		cout<<endl<<n.Delete();
	
}
