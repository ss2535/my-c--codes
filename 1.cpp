#include<iostream>
#include<fstream>

using namespace std;

class node{
	public:
		char name;
		int frequency;
		node *left , *right;
		node (char n , int f){
			name = n;
			frequency= f;
			left= right = NULL;
		}
};

class maxheap{
	private:
		node **arr;
		int size;
		int currentsize;
	public:
		maxheap(int n){
			currentsize = n;
			size=0;
			arr=new node*[n];
		}
		int parent(int x){return (x-1)/2;}
		int left(int x){return x*2+1;}
		int right(int x){return x*2+2;}
		void swap(node *&x , node *&y){
			node *t=x;
			x=y;
			y=t;
		}
		void insert(node *k){
			if(size== currentsize){
				cout<<endl<<"overflow.";
				return;
			}
			size++;
			int i=size-1;
			arr[i] =k;//new node('\0' , frequency);//moshkel bood
			while(i && arr[i]->frequency> arr[parent(i)]->frequency){
				swap(arr[i] ,arr[ parent(i)]);
				i=parent(i);
			}
		}
		node* remove(){
			if(size<=0){
				cout<<endl<<"no element.";
				return nullptr;
			}
			else if(size==1){
				size--;
				return arr[0];
			}
			else{
				node* root = arr[0];
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
			if(l<size && arr[l]->frequency>arr[largest]->frequency)
				largest=l;
			if(r<size && arr[r]->frequency>arr[largest]->frequency)
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
				cout<<arr[i]->name<<"  ";
			}
		}
		~maxheap(){
			for(int i=0;i<size;++i){
				delete arr[i];
			}
			delete []arr;
		}
};

node* hafman(char *a , int *frequency , int size){
	maxheap ph(size);
	//node *n;
	for(int i=0;i<size;i++){
		node *n = new node(a[i] , frequency[i]);
		ph.insert(n);
	}
	for(int i=0;i<size-1; i++){
		node *p=ph.remove();
		node *q= ph.remove();
		node *r= new node('\0',p->frequency + q->frequency);
		r->left=p;
		r->right=q;
		//r->frequency= p->frequency + q->frequency;
		ph.insert(r);
	}
	//return r;
	return  ph.remove();
}

void printHafman(node *root , string code = ""){
	if(root==nullptr)
		return ;
	if(!root->left  && !root->right){
		cout<<"character: "<<root->name<<" , frequency: "<<root->frequency<<" hafman code: "<<code<<endl;
	}
	printHafman(root->left, code +'0');
	printHafman(root->right, code+ '1');
}

main(){
	//open file
	ifstream file;
	file.open("D:/programing1401/algoritm/1.txt");
	if(file.fail()) 
	    cout<<"error...";
    char a[400]; 
    file.get(a,sizeof(a) , '\0');
    cout<<a<<endl;
	file.close();
	
	//find frequency
	int frequency[100]={0} , i;
	for(i=0; a[i]!='\0' ;i++){
		if(a[i]!=' '){
			frequency[a[i]]++;
		}
	}
	//print array , frequency
	int size =sizeof(frequency)/sizeof(frequency[0]);
	for(i=0; i<size ;i++){
		if(frequency[i]!=0){
			cout<<char(i)<<"   "<<frequency[i];
			cout<<endl;
		}
	}
	//max-heap
	node* hafmanroot = hafman(a,frequency, size);
	//print hafman code
	cout<<endl<<"-------------------------------------------------";
	cout<<endl<<"hafman code : "<<endl;
	printHafman(hafmanroot);
	
	
	return 0;
}