#include<iostream>
#include<stdlib.h>
#include<ctime>
#include<time.h>
using namespace std;

void sort(int *f , int n){
	int i,j,t;
	for(i=1;i<=n-1;i++)
		for(j=i+1;j<=n;j++)
			if(f[i]>f[j]){
				t=f[i];
				f[i]=f[j];
				f[j]=t;
			}
}

int bsearch(int *f , int n, int key, int left , int right){
	int mid;
	while(left<=right){
		mid = (left + right)/2;
		if(key <f[mid])  return bsearch(f , n,key , left , mid-1);
		else if(key > f[mid])  return (f,n,key , mid+1 , right);
		else return mid;
	}
	return -1;
}

main(){
	int f[101],i,key;
	srand(time(0));
	//...
	clock_t start , end;
	start= clock();
	//...
	for (i=1;i<100;i++){
		f[i]= rand();
		cout<<endl<<f[i];
	}
	cout<<endl<<endl;
	sort(f,101);
	for(i=1;i<=100;i++){
		cout<<f[i]<<"   ";
	}
	cout<<endl<<"enter key: ";
	cin>>key;
	cout<<endl<<"binary search = "<<bsearch(f,101,key,1,100);
	//...
	end= clock()- start;
	cout<<endl<<"time program = "<<(float)end/(float)CLOCKS_PER_SEC<<" second.";
}
