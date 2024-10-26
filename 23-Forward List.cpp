#include <iostream>

struct node {
    int value;
    node* next;
};

class forward_list {
    node* F;
    int n;

public:
    //constructor
    forward_list() {
        F = NULL;
        n = 0;
    }

    // Push value in Front
    void push_front(const int &v) {
        node* newNode = new node;
        newNode->value = v;
        newNode->next = F;
        F = newNode;
        n++;
    }

    // POP value in front
    void pop_front() {
        if (F != NULL) {
            node* temp = F;
            F = F->next;
            delete temp;
            n--;
        }
    }

    // Return value of Front
    int front() const {
        if (F != NULL) {
            return F->value;
        } else {
            std::cerr << "Error: List is empty!" << std::endl;
            return -1;
        }
    }

    // Clear the forward list
    void clear() {
        while (F != NULL) {
            pop_front();
        }
    }

    // it tell Forward list is empty or not
    bool empty()const{
        return n==0;
    }

    // Destructor 
    ~forward_list() {
        clear();
    }

    // Copy Constructor
    forward_list(const forward_list& other) {
        F = NULL;
        n = 0;
        node* temp = other.F;
        n = other.n;
        while (temp != NULL) {
            push_front(temp->value);
            temp = temp->next;
        }
    }

    // Assignment Operator
    forward_list& operator=(const forward_list& other) {
        if (this != &other) {
            clear();
            n = 0;
            node* temp = other.F;
            n = other.n;
            while (temp != NULL) {
                push_front(temp->value);
                temp = temp->next;
            }
        }
        return *this;
    }

    // Display all the forward List
    void display() const {
        node* current = F;
        while (current != NULL) {
            std::cout << current->value << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    // Swap the nodes
void swap_nodes(node* pre_node1, node* node1, node* pre_node2, node* node2) {
    if (pre_node1 != NULL) {
        pre_node1->next = node2;
    } else {
        F = node2; // Update F if node1 is the first node
    }

    if (pre_node2 != NULL) {
        pre_node2->next = node1;
    } else {
        F = node1; // Update F if node2 is the first node
    }

    // Swap the next pointers of the nodes
    node* temp = node1->next;
    node1->next = node2->next;
    node2->next = temp;
}

    // Sort the Forward List
    void sort() {
        node *i, *j, *max, *pre_i, *pre_j, *pre_max;
        for (pre_i = NULL, i = F; i != NULL && i->next != NULL; pre_i = i, i = i->next) {
        	max = i;
            for (pre_j = i, j = i->next ; j != NULL; pre_j = j, j = j->next) {
                if (j->value > max->value) {
                    pre_max = pre_j;
                    max = j;
                }
            }
            if (i != max) {
                swap_nodes(pre_i, i, pre_max, max);
                if (pre_i == NULL) {
                F = max;
            }
            std::swap(i, max);
            }
        }
    }

    // Remove the Duplicate values in a sequence
    void unique() {
        if (F == NULL || F->next == NULL) {
            return;
        }

        node* current = F;
        while (current != NULL && current->next != NULL) {
            if (current->value == current->next->value) {
                node* temp = current->next;
                current->next = temp->next;
                delete temp;
                n--; // Decrease the count when removing duplicates
            }
            else {
                current = current->next;
            }
        }
    }

    // Reverse the Forward List
    void reverse() {
        if (F == NULL || F->next == NULL) {
            return;
        }

        node* prev = NULL;
        node* current = F;
        node* next = NULL;

        while (current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        F = prev;
    }
};

int main() {
    // Create an instance of forward_list
    forward_list list1;

    // Test push_front
    list1.push_front(3);
    list1.push_front(2);
    list1.push_front(1);

    // Test display function
    std::cout << "List after pushing values: ";
    list1.display();

    // Test front
    std::cout << "Front value of list1: " << list1.front() << std::endl;

    // Test pop_front
    list1.pop_front();
    std::cout << "Front value after popping: " << list1.front() << std::endl;

    // Test clear and empty
    list1.clear();
    std::cout << "Is list1 empty after clear? " << (list1.empty() ? "Yes" : "No") << std::endl;

    // Test copy constructor
    forward_list list2(list1);
    std::cout << "List2 after copy constructor: ";
    list2.display();

    // Test assignment operator
    forward_list list3 = list2;
    std::cout << "List3 after assignment operator: ";
    list3.display();


    list3.push_front(4);
    list3.push_front(1);
    list3.push_front(3);
    list3.push_front(3);
    list3.push_front(2);
    
    
    
    // Test reverse
    std::cout << "List3 before reversing: ";
    list3.display();
    list3.reverse();
    std::cout << "List3 after reversing: ";
    list3.display();
    
    
    // Test unique
    std::cout << "List3 before removing duplicates: ";
    list3.display();
    list3.unique();
    std::cout << "List3 after removing duplicates: ";
    list3.display();
    
    
     // Test sort
    
    std::cout << "List3 before sorting: ";
    list3.display();
    list3.sort();
    std::cout << "List3 after sorting: ";
    list3.display();


    return 0;
}

