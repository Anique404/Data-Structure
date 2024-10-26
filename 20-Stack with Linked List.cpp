#include <iostream>
#include<stack>

struct node {
    int value;
    node *next;
};

class stack {

private:

    node* Top;
    int n;

public:

    stack() {
        this->n = 0;
        this->Top = NULL;
    }

    void Push(const int& v) {
        node* ptr;
        ptr = new node;
        ptr->value = v;
        if (this->n > 0) {
            ptr->next = Top;
        }
        else
        {
            ptr->next = NULL;
        }
        this->Top = ptr;
        this->n++;

    }

    void Pop() {
        if (this->Top == NULL) {
            std::cout << "Error: Stack is empty, cannot pop.\n";
            return;
        }

        node* ptr = this->Top;
        this->Top = ptr->next;
        delete ptr;
        this->n--;
    }



    int top() {
        return this->Top->value;
    }
    int size() const {
        return this->n;
    }
    bool empty() {
        if (this->n == 0) {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    void clear() {
        while (!empty()) {
            Pop();
        }
    }
    ~stack() {

        while (!this->empty()) {
            this->Pop();
        }
    }
    
    // Copy constructor
    stack(const stack& other) : Top(NULL), n(0) {
        node* ptr = other.Top;
        while (ptr != NULL) {
            Push(ptr->value);
            ptr = ptr->next;
        }
    }

     // Asignment operator
   stack& operator=(const stack & rhs) {
    if (this == &rhs)
        return *this;

    // Clear the current stack
    clear();

    // Copy elements from rhs stack to this stack
    node* rhsPtr = rhs.Top;
    while (rhsPtr != NULL) {
        Push(rhsPtr->value);
        rhsPtr = rhsPtr->next;
    }

    return *this;
}

    
    // Equal operator
     bool operator==(const stack& rhs) const {
        if (size() != rhs.size()) {
            return false;
        }
        node* leftPtr = Top;
        node* rightPtr = rhs.Top;
        while (leftPtr != NULL && rightPtr != NULL) {
            if (leftPtr->value != rightPtr->value) {
                return false;
            }
            leftPtr = leftPtr->next;
            rightPtr = rightPtr->next;
        }
        return true;
    }

    // NOT Equal operator
    bool operator!=(const stack& rhs) const {
        return !(*this == rhs);
    }

    // Less than operator
    bool operator<(const stack& rhs) const {
        node* leftPtr = Top;
        node* rightPtr = rhs.Top;
        while (leftPtr != NULL && rightPtr != NULL) {
            if (leftPtr->value < rightPtr->value) {
                return true;
            } else if (leftPtr->value > rightPtr->value) {
                return false;
            }
            leftPtr = leftPtr->next;
            rightPtr = rightPtr->next;
        }
        return size() < rhs.size();
    }

    // Greater than operator
    bool operator>(const stack& rhs) const {
        return  !(*this<rhs);
    }

    // Less than or equal to operator
    bool operator<=(const stack& rhs) const {
        return !(*this > rhs);
    }

    // Greater than or equal to operator
    bool operator>=(const stack& rhs) const {
        return !(*this < rhs);
    }
};

int main()
{
    stack n;

    n.Push(5);
    n.Push(10);
    n.Push(15);

    std::cout << "Top element: " << n.top() << std::endl;
    std::cout << "Stack size: " << n.size() << std::endl;

    n.Pop();
    std::cout << "Top element: " << n.top() << std::endl;
    std::cout << "Stack size: " << n.size() << std::endl;

    bool is_empty = n.empty();
    std::cout << "Is stack empty? " << (is_empty ? "Yes" : "No") << std::endl;


    stack n2;
    n2 = n;

    std::cout << "Elements of n2 after assignment:\n";
    while (!n2.empty()) {
        std::cout << n2.top() << " ";
        n2.Pop();
    }
    std::cout << std::endl;
    
    
    stack n3;
    n3.Push(1);
    n3.Push(23);
    n3.Push(31);

    if (n3 < n) {
        std::cout << "n3 is less than n"<<std::endl;
    }
    else
    {
        std::cout << "n3 is not less than n" << std::endl;
    }
    
    if (n3 > n) {
        std::cout << "n3 is greater than n"<<std::endl;
    }
    else
    {
        std::cout << "n3 is not greater than n" << std::endl;
    }
    
    if (n3 == n) {
        std::cout << "n3 is equal than n"<<std::endl;
    }
    else
    {
        std::cout << "n3 is not equal than n" << std::endl;
    }



}
