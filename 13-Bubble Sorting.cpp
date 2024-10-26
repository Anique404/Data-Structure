 #include<iostream>
using namespace std;
int main(){
	
	int arr[5]={4,1,2,8,9};
	
	int j=0;
	bool swaped=true;
	while(swaped){
		
		for(int i=4;i>j;i--){
			swaped=false;
			if(arr[i]<arr[i-1]){
				swap(arr[i],arr[i-1]);
				swaped=true;
			}
			
		}
		j++;
	}
	
	for(int i=0;i<5;i++){
		cout<<arr[i]<<"  ";
	}
}
