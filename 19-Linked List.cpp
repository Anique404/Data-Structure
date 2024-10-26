#include <iostream>
#include<stack>

struct node {
    int value;
    node *next;
};
int main(){
	
	node *p1,*p2;
	
	p1=new node;
	p2=new node;
	
	p1->value=2;
    p2->value=13;
    p1->next=p2;
    p2->next=NULL;
    
    std::cout << "Value stored in p1: " << p1->value <<" "<<p1->next->value<< std::endl;
	
}
