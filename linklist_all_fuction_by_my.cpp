#include<iostream>
using namespace std;
template<class type>
class linklist{
	private:
		class node{
			public:
				type data;
				node *next, *prev;
		};
		node *first=0;
		node *last=0;
	public:
		void add(type d){
			node *n= new node;
			n->data=d;
			n->next=0;
			n->prev =last;
			if(last==0){
				last = first=n;
				return;
			}
			last->next = n;
			last = n;
		}
	private:
		bool Delete(node *x){
			if(x==0)
				return false;
			if(first == 0)
				return false;
			if(x != first)
				x->prev->next= x->next;
			if(x !=last)
				x->next->prev = x->prev;
			if(x== first)
				first = x->next;
			if(x == last)
				last = x->prev;
			return true;
		}
	public:
		class myiterator{
			private:
				node *current;
				linklist *l; 
				bool ok2delete = false;
			public:
				myiterator(linklist *list){
					l = list;
					current = l->first;
				}
				bool hasnext(){
					if(current ==0) return false;
					else return true;
				}
				type Next(){
					if(!hasnext())
						throw std::out_of_range("blah");
					else{
						type k = current->data;
						current = current->next;
						ok2delete = true;
						return k;
					}
				}
				void reset(){
					ok2delete = false;
					current = l->first;
				}
				bool DDelete(){
					if(! ok2delete) return false;
					ok2delete = false;
					return l->Delete(current->prev);
				}
		};
		myiterator *getmyiterator(){return new linklist::myiterator(this);}
		
		void print_all_first(){
			node *k = first;
			while(k){
				cout<<k->data<<"  ";
				k=k->next;
			}
			delete k;
		}	
		
		void print_all_last(){
			node *k=last;
			while(k){
				cout<<k->data<<"  ";
				k=k->prev;
			}
			delete k;
		}

		void print_number_first(int n){
			node *k=first;
			//{
			for(int i=0;i<n && k;i++){
					cout<<k->data<<" ";
					k=k->next;
			}
			//}
			//delete k; //in car ro gharab mi kard.
		}

		void Delete_number_first(int n){
			node *k=first;
			for(int i=0;i<n && k;i++){
				Delete(k);
				k=k->next;
			}
		}

		void Delete_number2last(int n){
			node *k=first;
			for(int i=0;i<n && k;i++)
				k=k->next;
			
			for(int i=n;k!= nullptr ;i++){
				Delete(k);
				k=k->next;
			}
		}

		void add_number(int number , int n){
			node *s= first;
			for(int i=0;i<n &&s ;i++){
				s= s->next;
			}
			node *d=s;
			d->data = number;
			d->next= s->next;
			d->prev = s->prev;
		}
		
		void remove_greater_than(int x){
			node *n=first;
			while(n){
				if(x<= n->data){
					//node *b = n;
					Delete(n);
				}
				n=n->next;
			}
		}
};

main(){
	
	linklist<int>mylist;
	for(int i=0;i<20;i++)
		mylist.add(i);
		
	mylist.print_all_first();
	cout<<endl<<endl;
	

//	mylist.Delete_number_first(5);
//	mylist.Delete_number2last(9);
	
	mylist.add_number(99 , 5);
	mylist.add_number(50 , 10);
	
	mylist.remove_greater_than(99);
	mylist.remove_greater_than(50);
	
	mylist.print_all_first();
	cout<<endl<<endl;
	
	mylist.print_all_last();
	cout<<endl<<endl;
	
//	mylist.print_number_first(10);
//	cout<<endl<<endl;
	
	linklist<int>::myiterator *itr = mylist.getmyiterator();
	while(itr->hasnext())
		cout<<itr->Next()<<"  ";
	cout<<endl<<endl;
	
	itr->reset();
	/*linklist<int>::myiterator *ss = mylist.getmyiterator();
	while(ss->hasnext())
		if(ss->Next() %2 ==0)
			ss->DDelete();
	*/
	while(itr->hasnext())
		cout<<itr->Next()<<"  ";
	cout<<endl<<endl;
	
	
	
}

