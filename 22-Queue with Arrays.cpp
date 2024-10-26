#include <iostream>
#include<queue>
template <typename T>

class queue {
private:
    int front, back, size;
    T* data;

public:
    queue(int s = 10) {
        size = s + 1; // Adding 1 to accommodate for circular buffer
        front = back = 0;
        data = new T[size];
    }

    ~queue() {
        delete[] data;
    }

    void push(const T& value) {
        if (full()) {
            throw "Queue overflow";
        }
        back = (back + 1) % size; // Circular increment
        data[back] = value;
    }

    void pop() {
        if (empty()) {
            throw "Queue underflow";
        }
        front = (front + 1) % size; // Circular increment
    }
    
    T Front()  {
         if(empty()) {
             throw "Queue underflow";
      }
             return data[(front + 1) % size];
   }
   
   T Back() {
        if(empty()) {
            throw "Queue underflow";
        }
        return data[back];
    }
   
   bool empty() {
        return back == front;
    }

    bool full() {
        return (back + 1) % size == front;
    }
    
    int Size() {
    	return size;
	}
};

int main() {
    queue<int> s(5);
    try {
        s.push(4);
        s.push(5);
        s.push(75);
        s.push(46);
        s.push(43);
        std::cout << s.Front() << std::endl;
        std::cout << s.Back() << std::endl;
        s.pop();
        std::cout << s.Size() << std::endl;
        std::cout << s.Front() << std::endl;
        
    }
    catch (const char* mess) {
        std::cout << mess << std::endl;
    }
}

