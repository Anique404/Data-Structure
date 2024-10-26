#include<iostream>
using namespace std;
int main(){
	
	int arr[5]={4,1,2,8,9};
	
	int key;
	
	for(int i=1;i<5;i++){
		key=arr[i];
		int j=i-1;
	 while(j>=0 && arr[j]>key){
	 	arr[j+1]=arr[j];
	 	j=j-1;
	 	

	 }
	 arr[j+1]=key;
	}
	
	for(int i=0;i<5;i++){
		cout<<arr[i]<<"  ";
	}
	
}
