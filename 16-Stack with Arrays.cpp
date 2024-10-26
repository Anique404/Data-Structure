#include<iostream>
//#include<stack>

class stack{
	
	private:
		int *data;
		int Size;
		int TOP;
	
	public:
	
	stack(const int s=100){
		Size=s;
		data=new int [Size];
	    TOP=-1;
	}	
	~stack(){
	   delete []data;
     
	}
	int top()const{
		return data[TOP];
		
	}
	
	void push(const int &v){
		
		TOP++;
		data[TOP]=v;
	}
	
	void pop(){
		TOP--;
	}
	
	int size() {

	return TOP;

}

bool empty() {

	if (TOP==-1) {
		return true;
	}
	else {
		return false;
	}

}
};

int main(){
	
	stack s;
	
	s.push(2);
	s.push(3);
	s.push(90);
	s.push(23);
	
    std::cout << "Top element of stack: " << s.top() << std::endl;

    s.pop();

    std::cout << "Top element of stack after pop: " << s.top() << std::endl;
    
    int r=s.size();
    
   std::cout <<"Size of data is = " << r;
    std::cout<<s.empty();


	
}
