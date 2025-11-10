#include<iostream>
using namespace std;
void qsort(int *a,int left,int right){
	int i= left,j=right , pivot= a[(left+right)/2];
	while(i<=j){
		while(a[i] <pivot) i++;
		while(a[j]> pivot) j--;
		if(i<=j){
			swap(a[i] , a[j]);
			i++;
			j--;
		}
	}
	if(left<j) qsort(a,left,j);
	if(i<right) qsort(a,i,right);
}

main(){
	
	int a[]= {1,5,22,4,9,11};
	qsort(a,0,6-1);
	for(int i=0;i<6;i++)
		cout<<a[i]<<"  ";
	
}