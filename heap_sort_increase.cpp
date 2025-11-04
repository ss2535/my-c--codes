#include<iostream>
using namespace std;
void heapify(int arr[] ,int n , int i){
	int large = i;
	int left = 2*i+1;
	int right = 2*i+2;
	if(right <n && arr[right] >arr[large])
		large = right;
	if(left<n && arr[left]> arr[large])
		large = left;
	if(large !=i){
		swap(arr[i] , arr[large]);
		heapify(arr,n,large);
	}
}
void heapsort(int arr[] , int n){
	for(int i = n/2-1 ;i>=0;i--)
		heapify(arr,n,i);
	for(int i= n-1;i>0;i--){
		swap(arr[0] , arr[i]);
		heapify(arr,i,0);
	}
}

main(){
	int l[]={2,3,66,21,8,1,12};
	int n=sizeof(l) / sizeof(l[0]);
	heapsort(l,n);
	for(int i=0;i<n ;i++)
		cout<<l[i]<<"   ";
}