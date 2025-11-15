#include<iostream>
using namespace std;
void sort(int *a , int n,int i){
	int low=i;
	int l=i*2+1;
	int r=i*2+2;
	if(l<n && a[l]<a[low])  low=l;
	if(r<n && a[r]<a[low])  low=r;
	if(low != i){
		swap(a[i] , a[low]);
		sort(a,n,low);
	}
}
void heapSort(int *a , int n){
	for(int i=(n-1)/2;i>=0;i--)
		sort(a,n,i);
	for(int i=n-1;i>0;i--){
		swap(a[0] , a[i]);
		sort(a,i,0);
	}
}
main(){
	
	int l[]={1,88,43,2,10,21};
	int n=sizeof(l)/sizeof(l[0]);
	heapSort(l,n);
	for(int i=0;i<n;i++)
		cout<<l[i]<<"  ";
	
}