
#include <iostream>

struct denode {
    int value;
    denode* next,*pre;
};
class list{
	
	denode *h;
	int n;
	
	public:
		list(){
			n=0;
			h=new denode;
			h->next=h;
			h->pre=h;
			
		}
		~list(){
			clear();
			delete h;
			
		}
		
		 void clear() {
        denode* current = h->next;
        while (current != h) {
            denode* temp = current;
            current = current->next;
            delete temp;
        }
        h->next = h;
        h->pre = h;
        n = 0;
    }
    bool empty()const{
        return n==0;
    }
	
	int front() {
    if (n == 0) {
        std::cerr << "Error: List is empty!" << std::endl;
        return -1; // or throw an exception
    }
    return h->next->value;
}

   int back() {
    if (n == 0) {
        std::cerr << "Error: List is empty!" << std::endl;
        return -1; // or throw an exception
    }
    return h->pre->value;
}

void push_back(const int& v) {
    denode* temp = new denode;
    temp->value = v;
    
    temp->next = h;
    temp->pre = h->pre;
    temp->pre->next = temp;
    h->pre = temp;
    
    n++;
}

void push_front(const int& v) {
    denode* temp = new denode;
    temp->value = v;
    
    temp->pre = h;
    temp->next = h->next;
    temp->next->pre = temp;
    h->next = temp;
    
    n++;
}

void pop_front(){
	
	denode *temp=new denode;
	temp =h->next;
	temp->next->pre=h;
	h->next=temp->next;
	
	delete temp;
}

void pop_back(){
	
	denode *temp=new denode;
	temp=h->pre;
	h->pre=temp->pre;
	temp->pre->next=h;
	
	delete temp;
	
}
 void display() {
        denode* ptr = h->next;
        while (ptr != h) {
            std::cout << ptr->value << " ";
            ptr = ptr->next;
        }
        std::cout << std::endl;
    }

      
class iterator {
    denode* ptr;

    // Declare forward_list as a friend
    friend class list;
    
public:
    // Constructor
    iterator() {
    ptr = NULL;
}

    // Dereference operator
    int& operator*() const {
        return ptr->value;
    }
    
    int* operator->() const {
        return &ptr->value;
    }


    // Increment operator (prefix)
    iterator& operator++() {
        ptr = ptr->next;
        return *this;
    }

    // Increment operator (postfix)
    iterator operator++(int) {
        iterator temp ;
		temp= *this;
        ptr = ptr->next;
        return temp;
    }
    // Decrement operator (prefix)
        iterator& operator--() {
            ptr = ptr->pre;
            return *this;
        }

    // Decrement operator (postfix)
        iterator operator--(int) {
            iterator temp = *this;
            ptr = ptr->pre;
            return temp;
        }
    

    // Equality operator
    bool operator==(const iterator& other) const {
        return ptr == other.ptr;
    }

    // Inequality operator
    bool operator!=(const iterator& other) const {
        return !(*this == other);
    }
};
    
    // Begin function
    iterator begin()const {
         iterator it;
         it.ptr=this->h->next;
         return it;
    };

    // End function
    iterator end() const{
       iterator it;
         it.ptr=h;
         return it;
    }
    
    // insert the value
    void insert(iterator it,int value) {
    	 if (it.ptr == NULL) {
           return;
    }
    
        denode* newNode = new denode;
        newNode->value = value;
        newNode->pre = it.ptr->pre;
        it.ptr->pre->next = newNode;
        newNode->next=it.ptr;
        it.ptr->pre=newNode;
        n++;
        
    }
    
// Erase the values
    void erase(iterator it) {
        if (it.ptr == NULL || it.ptr->next == NULL) {
            return;
        }
        denode* temp = it.ptr;
        temp->next->pre = temp->pre;
        temp->pre->next=temp->next;
        delete temp;
    }
//    
//    // Reverse iterator
//class reverse_iterator {
//    denode* ptr;
//
//    // Declare list as a friend
//    friend class list;
//
//public:
//    // Constructor
//    reverse_iterator() {
//        ptr = NULL;
//    }
//
//    // Dereference operator
//    int& operator*() const {
//        return ptr->value;
//    }
//
//    int* operator->() const {
//        return &ptr->value;
//    }
//    
//    // Increment operator (prefix)
//    reverse_iterator& operator++() {
//    ptr = ptr->pre;
//    return *this;
//    }
//
//    // Increment operator (postfix)
//    reverse_iterator operator++(int) {
//    reverse_iterator temp = *this;
//    ptr = ptr->pre;
//    return temp;
//    }
//
//
//    // Decrement operator (prefix)
//    reverse_iterator& operator--() {
//        ptr = ptr->next;
//        return *this;
//    }
//
//    // Decrement operator (postfix)
//    reverse_iterator operator--(int) {
//        reverse_iterator temp = *this;
//        ptr = ptr->next;
//        return temp;
//    }
//
//    // Equality operator
//    bool operator==(const reverse_iterator& other) const {
//        return ptr == other.ptr;
//    }
//
//    // Inequality operator
//    bool operator!=(const reverse_iterator& other) const {
//        return !(*this == other);
//    }
//    
//    
//};
//
//       // Begin function for reverse iterator
//    reverse_iterator rbegin() const {
//        reverse_iterator it;
//        it.ptr = h->pre;
//        return it;
//    }
//
//    // End function for reverse iterator
//    reverse_iterator rend() const {
//        reverse_iterator it;
//        it.ptr = h;
//        return it;
//    }
//    
};
int main(){
	
    list l;
    l.push_front(32);
    l.push_front(68);
    l.push_front(2);
    l.push_front(3);

    std::cout << "Front: " << l.front() << std::endl;
    std::cout << "Back: " << l.back() << std::endl;

    l.push_back(100);
    std::cout << "Front after push_back: " << l.front() << std::endl;
    std::cout << "Back after push_back: " << l.back() << std::endl;

    l.display();
    
    list::iterator it = l.begin();
    ++it;
    l.insert(it, 10); // Insert 10 after the second element

    // Display the list after insertion using iterator
    std::cout << "List after insertion using iterator:" << std::endl;
    l.display();
    
    // Use iterators to erase elements
    list::iterator itt = l.begin();
    ++itt; // Move to the second element
    l.erase(itt); // Erase the second element

    // Display the list after erasing an element
    std::cout << "List after erasing an element:" << std::endl;
    l.display();

    

    std::cout<<std::endl<<std::endl;
    std::cout<<"****************** Iterator Function  *****************"<<std::endl<<std::endl;
    
    list l3;
    
    
    l3.push_front(4);
    l3.push_front(1);
    l3.push_front(3);
    l3.push_front(23);
    l3.push_front(2);
    
    
    // Test begin and end
    list ::iterator it_begin = l3.begin();
    list ::iterator it_end = l3.end();
    std::cout << "Iterator Begin: " << *it_begin << std::endl;

    // Test increment operator (prefix)
    ++it_begin;
    std::cout << "After prefix increment: " << *it_begin << std::endl;

    // Test increment operator (postfix)
    list ::iterator it_postfix = it_begin++;
    std::cout << "After postfix increment: " << *it_postfix << std::endl;

    // Test dereference operator
    std::cout << "Dereferencing it_begin: " << *it_begin << std::endl;


    l3.display();
    
     std::cout<<std::endl<<std::endl;
    std::cout<<"****************** Reverse Iterator Function  *****************"<<std::endl<<std::endl;
    
    list l2;

    l2.push_front(14);
    l2.push_front(12);
    l2.push_front(34);
    l2.push_front(3);
    l2.push_front(12);

    // Test begin and end
    list::reverse_iterator itt_begin = l2.rbegin();
    list::reverse_iterator itt_end = l2.rend();
    std::cout << "Iterator Begin: " << *itt_begin << std::endl;

    // Test increment operator (prefix)
    --itt_begin;
    std::cout << "After prefix increment: " << *itt_begin << std::endl;

    // Test increment operator (postfix)
    list::reverse_iterator itt_postfix = itt_begin--;
    std::cout << "After postfix increment: " << *itt_postfix << std::endl;

    // Test dereference operator
    std::cout << "Dereferencing it_begin: " << *itt_begin << std::endl;

    l2.display();
    
    
	
	
}
