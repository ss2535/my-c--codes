#include<iostream>
using namespace std;
void bsort(int *arr, int n){
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
			if(arr[i]> arr[j])
				swap(arr[i] , arr[j]);
}

int binarySearch(int *arr, int n , int key){
	int left=0,right=n-1;
	while(left<=right){
		int mid=(left+right)/2;
		if(key<arr[mid]) right=mid-1;
		else if(key> arr[mid]) left=mid+1;
		else return mid;
	}
	return -1;
}

main(){
	int arr[]={9,81,4,22,65,12,25,2,49};
	int n=sizeof(arr)/sizeof(arr[0]);
	for(int i=0;i<n;i++)
		cout<<arr[i]<<"  ";
	bsort(arr,n);
	cout<<endl;
	for(int i=0;i<n;i++)
		cout<<arr[i]<<"  ";
	int key=9;
	cout<<endl<<binarySearch(arr,n,key);
}