#include<iostream>
using namespace std;
template<class t>
class BinarySearchTree{
	private:
		class node{
			public:
				t data;
				node *left;
				node *right;
				node(node *r , node *l , t d){ right = r,left = l; data=d;}
		};
		node *root;
		node *insert(node *x , t d){
			if(x==0) return new node(0,0,d);
			if(x->data >d) x->left = insert(x->left , d);
			else if(x->data < d) x->right = insert(x->right , d);
			return x;
		}
		void printInOrder(node *x ){
			if(x==0) return;
			else{
				printInOrder(x->left);
				cout<<x->data<<"  ";
				printInOrder(x->right);
			}
		}
		void DeleteInOrder(node *x){
			if(x==0) return;
			else{
				DeleteInOrder(x->left);
				delete(x);
				DeleteInOrder(x->right);
			}
		}
		bool eqexact(node *x, node *y){
			if(x==0 && y==0) return true;
			if(x== 0 || y==0) return false;
			if(x->data != x->data) return false;
			return eqexact(x->left , y->left ) && eqexact(x->right , y->right);
		}
	public:
		BinarySearchTree(){root =0;}
		void Insert(t d){ root = insert(root , d);}
		void PrintInOrder(){ 
		cout<<endl<<"prt inOrder : ";
		printInOrder(root);
		cout<<endl;
		}
		~BinarySearchTree(){ DeleteInOrder(root);}
		bool EqExact(BinarySearchTree *x){return eqexact(this->root , x->root);}
};

main(){
	
	BinarySearchTree<int> bst;
	bst.Insert(100);
	bst.Insert(50);
	bst.Insert(25);
	bst.Insert(12);
	bst.Insert(200);
	bst.Insert(300);
	bst.Insert(45);
	
	BinarySearchTree <int>bst2;
	bst2.Insert(100);
	bst2.Insert(50);
	bst2.Insert(25);
	bst2.Insert(12);
	bst2.Insert(200);
	bst2.Insert(300);
	bst2.Insert(45);
	
	BinarySearchTree<int> bst3;
	bst3.Insert(100);
	bst3.Insert(50);
	bst3.Insert(25);
	bst3.Insert(12);
	bst3.Insert(200);
	bst3.Insert(300);
	
	bst.PrintInOrder();
	
	cout<<endl<<bst.EqExact(&bst2);
	cout<<endl<<bst.EqExact(&bst3);
	
}