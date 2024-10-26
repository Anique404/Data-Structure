2#include <iostream>

template<typename T>
struct Node {
    T value;
    Node<T>* next;
};

template<typename T>
class Queue {
private:
    Node<T>* Front;
    Node<T>* Back;
    int n;

public:
    Queue() : Front(NULL), Back(NULL), n(0) {}

    void Push(const T& v) {
        Node<T>* ptr = new Node<T>;
        ptr->value = v;
        ptr->next = NULL;
        if (n == 0) {
            Front = Back = ptr;
        } else {
            Back->next = ptr;
            Back = ptr;
        }
        n++;
    }

    void POP() {
        if (n == 0) {
            throw "Queue is empty";
        }

        Node<T>* ptr = Front;
        Front = ptr->next;
        delete ptr;
        if (Front == NULL) {
            Back = NULL; // Queue becomes empty
        }
        n--;
    }

    T front() const {
        if (n == 0) {
            throw "Queue is empty";
        }
        return Front->value;
    }

    T back() const {
        if (n == 0) {
            throw "Queue is empty";
        }
        return Back->value;
    }

    int size() const {
        return n;
    }

    bool empty() const {
        return n == 0;
    }

    void clear() {
        while (!empty()) {
            POP();
        }
    }

    ~Queue() {
        clear();
    }

    // Copy constructor
    Queue(const Queue& other) : Front(NULL), Back(NULL), n(0) {
        Node<T>* ptr = other.Front;
        while (ptr != NULL) {
            Push(ptr->value);
            ptr = ptr->next;
        }
    }

    // Assignment operator
    Queue& operator=(const Queue& rhs) {
        if (this == &rhs)
            return *this;

        // Clear the current queue
        clear();

        // Copy elements from rhs queue to this queue
        Node<T>* rhsPtr = rhs.Front;
        while (rhsPtr != NULL) {
            Push(rhsPtr->value);
            rhsPtr = rhsPtr->next;
        }
        return *this;
    }

    // Equal operator
    bool operator==(const Queue& rhs) const {
        if (size() != rhs.size()) {
            return false;
        }
        Node<T>* leftPtr = Front;
        Node<T>* rightPtr = rhs.Front;
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
    bool operator!=(const Queue& rhs) const {
        return !(*this == rhs);
    }

    // Less than operator
    bool operator<(const Queue& rhs) const {
        if (size() != rhs.size()) {
            return size() < rhs.size();
        }
        Node<T>* leftPtr = Front;
        Node<T>* rightPtr = rhs.Front;
        while (leftPtr != NULL && rightPtr != NULL) {
            if (leftPtr->value != rightPtr->value) {
                return leftPtr->value < rightPtr->value;
            }
            leftPtr = leftPtr->next;
            rightPtr = rightPtr->next;
        }
        return false;
    }

    // Greater than operator
    bool operator>(const Queue& rhs) const {
        return rhs < *this;
    }

    // Less than or equal to operator
    bool operator<=(const Queue& rhs) const {
        return !(*this > rhs);
    }

    // Greater than or equal to operator
    bool operator>=(const Queue& rhs) const {
        return !(*this < rhs);
    }
};

int main() {
    Queue<int> q;
    q.Push(10);
    q.Push(20);
    q.Push(30);
    try {
        std::cout << "Queue Front: " << q.front() << std::endl;
        std::cout << "Queue Back: " << q.back() << std::endl;
        std::cout << "Queue Size: " << q.size() << std::endl;

        q.POP();

        std::cout << "Queue Front: " << q.front() << std::endl;
        std::cout << "Queue Back: " << q.back() << std::endl;
        std::cout << "Queue Size: " << q.size() << std::endl;

        Queue<int> q2 = q;
        std::cout << "Copied Queue Front: " << q2.front() << std::endl;
        std::cout << "Copied Queue Back: " << q2.back() << std::endl;
        std::cout << "Copied Queue Size: " << q2.size() << std::endl;
    }
    catch (const char* mess) {
        std::cout << mess << std::endl; 
    }

    Queue<int> q2;
    q2.Push(1);
    q2.Push(23);
    q2.Push(31);

    if (q2 < q) {
        std::cout << "Q2 is less than Q1"<<std::endl;
    }
    else
    {
        std::cout << "Q2 is not less than Q1" << std::endl;
   
}
}
