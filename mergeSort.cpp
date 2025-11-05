#include<iostream>
using namespace std;

void merge(int *arr, int l , int m,int r){
	int n1=m-l+1;
	int n2=r-m;
	int L[n1], R[n2];
	for(int i=0;i<n1;i++)
		L[i]= arr[i+l];
	for(int j=0;j<n2;j++)
		R[j] = arr[m+j+1];
	int i=0,j=0,k=l;
	while(i<n1 && j<n2){
		if(L[i]<=R[j]){
			arr[k]=L[i];
			i++;
		}
		else{
			arr[k]=R[j];
			j++;
		}
		k++;
	}
	while(i<n1){
		arr[k]=L[i];
		i++;
		k++;
	}
	while(j<n2){
		arr[k]=R[j];
		k++;
		j++;
	}
}

void mergesort(int *arr , int l, int r){
	if(l<r){
		int m=(r+l)/2;
		mergesort(arr,l,m);
		mergesort(arr,m+1,r);
		merge(arr,l,m,r);	
	}
}

main(){
	
	int a[]={2,4,11,34,80,5};
	int n=sizeof(a)/sizeof(a[0]);
	mergesort(a,0,n-1);
	for(int i=0;i<n;i++)
		cout<<a[i]<<"  ";
	
}