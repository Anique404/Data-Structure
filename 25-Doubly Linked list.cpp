#include <iostream>

struct denode {
    int value;
    denode* next, * pre;
};

class list {
    denode* h;
    int n;

public:
    list() {
        n = 0;
        h = new denode;
        h->next = h;
        h->pre = h;
    }

    ~list() {
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

    bool empty() const {
        return n == 0;
    }

    int front() {
        if (n == 0) {
            std::cout << "Error: List is empty!" << std::endl;
            return -1; // or throw an exception
        }
        return h->next->value;
    }

    int back() {
        if (n == 0) {
            std::cout << "Error: List is empty!" << std::endl;
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

    void pop_front() {
        if (n == 0) {
            std::cout << "Error: List is empty!" << std::endl;
            return;
        }
        denode* temp = h->next;
        temp->next->pre = h;
        h->next = temp->next;

        delete temp;
        n--;
    }

    void pop_back() {
        if (n == 0) {
            std::cout << "Error: List is empty!" << std::endl;
            return;
        }
        denode* temp = h->pre;
        h->pre = temp->pre;
        temp->pre->next = h;

        delete temp;
        n--;
    }

    void display() {
        denode* ptr = h->next;
        while (ptr != h) {
            std::cout << ptr->value << " ";
            ptr = ptr->next;
        }
        std::cout << std::endl;
    }

    void swap(denode* n1, denode* n2) {
        if (n1 == n2) return;

        denode* temp1 = n1->pre;
        denode* temp2 = n2->pre;

        if (temp1 != NULL) {
            temp1->next = n2;
        } else {
            h = n2;
        }
        if (temp2 != NULL) {
            temp2->next = n1;
        } else {
            h = n1;
        }

        if (n1->next != NULL) {
            n1->next->pre = n2;
        }
        if (n2->next != NULL) {
            n2->next->pre = n1;
        }

        denode* temp_next = n1->next;
        n1->next = n2->next;
        n2->next = temp_next;

        denode* temp_prev = n1->pre;
        n1->pre = n2->pre;
        n2->pre = temp_prev;
    }

    void sort() {
        for (denode* i = h->next; i != h && i->next != h; i = i->next) {
            for (denode* j = i->next; j != h; j = j->next) {
                if (j->value < i->value) {
                    std::swap(i->value, j->value);
                }
            }
        }
    }

    void unique() {
        denode* temp1 = h->next;
        while (temp1 != h && temp1->next != h) {
            if (temp1->value == temp1->next->value) {
                denode* toDelete = temp1->next;
                temp1->next = temp1->next->next;
                temp1->next->pre = temp1;
                delete toDelete;
                n--;
            } else {
                temp1 = temp1->next;
            }
        }
    }

    void reverse() {
        denode* current = h->next;
        denode* temp = NULL;
        while (current != h) {
            temp = current->pre;
            current->pre = current->next;
            current->next = temp;
            current = current->pre;
        }
        if (temp != NULL) {
            h->next = temp->pre;
        }
    }
};

int main() {
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

    std::cout << "List before sorting: ";
    l.display();
    l.sort();
    std::cout << "List after sorting: ";
    l.display();

    l.push_back(100);
    l.push_back(68);
    l.push_back(32);
    l.push_back(2);
    l.push_back(3);

    std::cout << "List before unique: ";
    l.display();
    l.unique();
    std::cout << "List after unique: ";
    l.display();

    l.reverse();
    std::cout << "List after reverse: ";
    l.display();

    return 0;
}

