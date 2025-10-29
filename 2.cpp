#include<iostream>
#include<fstream>
#define maxsize 400
using namespace std;

struct char_freq{
	char character;
	int frequency;
};

class node{
	public:
		char name;
		int frequency;
		node *left , *right;
		node (char_freq a){
			name = a.character;
			frequency= a.frequency;
			left= right = NULL;
		}
};

class minheap{
	private:
		node **arr;
		int size;
		int currentsize;
	public:
		minheap(int n){
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
			arr[i] =k;
			while(i && arr[i]->frequency < arr[parent(i)]->frequency){
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
				minheapii(0);
				return root;
			}
		}
		void minheapii(int i){
			int l=left(i);
			int r=right(i);
			int small=i;
			if(l<size && arr[l]->frequency < arr[small]->frequency)
				small=l;
			if(r<size && arr[r]->frequency < arr[small]->frequency)
				small=r;
			if(small !=i){
				swap(arr[i] , arr[small]);
				minheapii(small);
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
};

void findfrequency(char *a,char_freq *arr , int &size ){
	int count[maxsize]={0},i,sizereact=0;
	for(i=0;a[i]!='\0';i++){
		count[a[i]]++;
	}
	for(i=0;i<maxsize;i++ ){
		if(count[i] > 0){
			arr[i].character=char(i);
			arr[i].frequency=count[i];
			sizereact++;
		}
	}
	size=sizereact;
	for(i=0;i<size-1;i++){
		for(int j=i+1;j<size;j++){
			if(arr[i].frequency > arr[j].frequency){
				char_freq t=arr[i];
				arr[i]=arr[j];
				arr[j]=t;
			}		
		}
	}
}

node* hafman(char_freq *a , int size){
	minheap ph(size);
	for(int i=0;i<size;i++){
			node *n = new node(a[i]);
			ph.insert(n);
	}
	for(int i=0;i<size-1; i++){
		node *p=ph.remove();
		node *q= ph.remove();
		char_freq s;
		s.character='\0';
		s.frequency = p->frequency+ q->frequency;
		node *r= new node(s);
		r->left=p;
		r->right=q;
		ph.insert(r);
	}
	return  ph.remove();
}

void printHafman(node *root ,string code = ""){
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
	file.open("D:/programing1401/algoritm/2.txt");
	if(file.fail()) 
	    cout<<"error...";
    char a[maxsize]; 
    file.get(a,sizeof(a) , '\0');
    cout<<"read file : "<<a<<endl;
	file.close();
	
	char_freq arr[maxsize];
	int size=0;
	findfrequency(a ,arr , size);
	
	node* hafmanroot = hafman(arr, size);
	//print hafman code
	cout<<endl<<"-------------------------------------------------";
	cout<<endl<<"hafman code : "<<endl;
	printHafman(hafmanroot);

}