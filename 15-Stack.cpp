#include<iostream>
#include<stack>

int main() {
    std::stack<int> s;
    s.push(2);
    s.push(3);
    s.push(5);
    s.push(1);

    std::cout << "Size of s before swap = " << s.size() << std::endl;

    while (!s.empty()) {
        std::cout << s.top() << std::endl;
        s.pop();
    }

    std::stack<int> s2;
    s2.push(4);
    s2.push(9);
    s2.push(2);

    std::cout << "Size of s2 before swap = " << s2.size() << std::endl;

    s.swap(s2);

    std::cout << "Size of s after swap = " << s.size() << std::endl;
    std::cout << "Size of s2 after swap = " << s2.size() << std::endl;

    std::cout << "Contents of s after swap:" << std::endl;
    while (!s.empty()) {
        std::cout << s.top() << std::endl;
        s.pop();
    }

    std::cout << "Contents of s2 after swap:" << std::endl;
    while (!s2.empty()) {
        std::cout << s2.top() << std::endl;
        s2.pop();
    }

    return 0;
}

