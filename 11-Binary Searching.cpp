#include <iostream>
using namespace std;
const int size = 100;

void getdata(int[], int);

int binarysearch(int[], int,int);


int main() {
    int marks[size];
    int count, givenvalue, find;
    
   cout << "enter no of elements=";
    cin >> count;
    
    while (count < 1 || count > 50) {
        cout << "You entered an invalid value" << endl;
        cout << "enter no of elements=";
        cin >> count;
    }
    
   
    getdata(marks, count);
    
    cout<<"enter a value you find=";
    cin>>givenvalue;
    
    find= binarysearch(marks, count, givenvalue);
    
    
    if (find == -1) {
        cout << "Value not found in the array." << endl;
    }
     else {
	cout<<"the value find at index"<<find<<endl;
    for(int i=find-1;i>=0;i--){
    	if(givenvalue==marks[i]){
    		cout<<"the value find at index"<<i<<endl;
		}
	}
	 for(int i=find+1;i<count;i++){
    	if(givenvalue==marks[i]){
    		cout<<"the value find at index"<<i;
		}
	}
}
}
void getdata(int marks[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "enter marks=";
        cin >> marks[i];
    }
}
int binarysearch(int marks[], int n,int val){
	int first=0;
	int last=n-1;
	int mid;
	while(first<=last){
		mid=(first+last)/2;
		if(val<marks[mid])
			last=mid-1;
	
		else if(val>marks[mid])
			first=mid+1;
		
		else
			return mid;
	}
	return -1;
}
