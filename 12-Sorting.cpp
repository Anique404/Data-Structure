#include <iostream>
using namespace std;
const int size = 100;

void getdata(int[], int);
void display(int[], int);
void sort(int[],int);
void reverse(int [], int );

int main() {
    int marks[size];
    int count, givenvalue;
    
    cout << "enter no of elements=";
    cin >> count;
    
    while (count < 1 || count > 50) {
        cout << "You entered an invalid value" << endl;
        cout << "enter no of elements=";
        cin >> count;
    }
    getdata(marks, count);
    sort(marks,count);
     display(marks,count);
    reverse(marks,count);
     display(marks,count);
}

void getdata(int marks[100], int n) {
    for (int i = 0; i < n; i++) {
        cout << "enter marks=";
        cin >> marks[i];
    }
}
void sort(int marks[100],int n)
{
	int i,j,min,minindex;
	for(int i=0;i<n-1;i++){
		min=marks[i];
		minindex=i;
		for(int j=i+1;j<n;j++){
			if(min>marks[j]){
				min=marks[j];
				minindex=j;
			}	
      	}
    	marks[minindex]=marks[i];
		marks[i]=min;
      	}
}
void display(int marks[100],int n){
	     cout << "After sorting"<<endl;
    for (int i = 0; i <n; i++) {
        cout<< marks[i]<<"  ";
    }
        cout<<endl;
}

void reverse(int marks[100], int n){
	 cout << "After reverse sorting:" << endl;
	 int j=n-1;
    for (int i = 0; i <n/2; i++) {
       int temp=marks[i];
       marks[i]=marks[j];
       marks[j]=temp;
       j--;
    }
}
