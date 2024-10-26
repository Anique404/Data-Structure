#include <iostream>

template<typename T>
struct tnode {
    T val;
    tnode* left;
    tnode* right;
    tnode* parent;
    bool is_nil;
};

template<typename T>
class set {
private:
    tnode<T>* H;
    int n;

    tnode<T>* insert_r(tnode<T>* ptr, const T& v) {
        if (ptr == this->H) {
            n++;

            tnode<T>* temp = new tnode<T>;
            temp->val = v;

            temp->left = H;
            temp->right = H;

            if (temp->val < this->H->left->val) {
                this->H->left = temp;
            }

            if (temp->val > this->H->right->val) {
                this->H->right = temp;
            }

            n++;
            return temp;
        }
        
        else if (ptr->val > v) {
            ptr->left = insert_r(ptr->left, v);
            ptr->left->parent = ptr;
            return ptr;
        }
        
        else if (ptr->val < v) {
            ptr->right = insert_r(ptr->right, v);
            ptr->right->parent = ptr;
            return ptr;
        }
        
        else {
            return ptr;
        }
    }

    tnode<T>* smallest_node(tnode<T>* ptr) const {
        if (this->H->parent == this->H) {
            return H;
        }
        if (ptr == H) {
            ptr = this->H->parent;
        }
        while (ptr->left != this->H) {
            ptr = ptr->left;
        }
        return ptr;
    }

    tnode<T>* largest_node(tnode<T>* ptr) const {
        if (this->H->parent == this->H) {
            return H;
        }
        if (ptr == H) {
            ptr = this->H->parent;
        }
        while (ptr->right != this->H) {
            ptr = ptr->right;
        }
        return ptr;
    }

    bool erase_r(tnode<T>* ptr, const T& v) {
        if (ptr == this->H) {
            return false;
        }
        else if (v > ptr->val) {
            return erase_r(ptr->right, v);
        }
        else if (v < ptr->val) {
            return erase_r(ptr->left, v);
        }
        else if (ptr->val == v) {
            if (ptr->left == this->H && ptr->right == this->H) {
                if (ptr->parent == this->H) {
                    this->H->parent = this->H->left = this->H->right = this->H;
                }
                else if (ptr == ptr->parent->left) {
                    ptr->parent->left = this->H;
                }
                else if (ptr == ptr->parent->right) {
                    ptr->parent->right = this->H;
                }
                delete ptr;
            }
            else if (ptr->left != this->H && ptr->right == this->H) {
                ptr->left->parent = ptr->parent;
                if (ptr->parent == this->H) {
                    this->H->parent = ptr->left;
                }
                else if (ptr == ptr->parent->right) {
                    ptr->parent->right = ptr->left;
                }
                else if (ptr == ptr->parent->left) {
                    ptr->parent->left = ptr->left;
                }
                delete ptr;
            }
            else if (ptr->right != this->H && ptr->left == this->H) {
                ptr->right->parent = ptr->parent;
                if (ptr->parent == this->H) {
                    this->H->parent = ptr->right;
                }
                else if (ptr == ptr->parent->right) {
                    ptr->parent->right = ptr->right;
                }
                else if (ptr == ptr->parent->left) {
                    ptr->parent->left = ptr->right;
                }
                delete ptr;
            }
            else {
                tnode<T>* pred;
                pred = largest_node(ptr->left);
                if (ptr->parent == this->H)
                    this->H->parent = pred;
                else if (ptr == ptr->parent->left)
                    ptr->parent->left = pred;
                else
                    ptr->parent->right = pred;
                ptr->right->parent = pred;
                pred->right = ptr->right;
                if (pred != ptr->left) {
                    pred->parent->right = pred->left;
                    if (pred->left != this->H)
                        pred->left->parent = pred->parent;
                    pred->left = ptr->left;
                    pred->left->parent = pred;
                    pred->parent = ptr->parent;
                }
                delete ptr;
            }
            --this->n;
            return true;
        }
    }

public:
    set() {
        n = 0;
        H = new tnode<T>;
        H->left = H;
        H->right = H;
        H->parent = H;
        H->is_nil = true;
    }

    void insert(const T& v) {
        if (H->parent == H) {
            tnode<T>* temp = new tnode<T>;
            temp->val = v;

            temp->parent = H;
            temp->left = H;
            temp->right = H;

            H->parent = temp;
            H->left = temp;
            H->right = temp;

            n++;
        }
        else {
            insert_r(H->parent, v);
        }
    }

    bool erase(const T& v) {
        return erase_r(H->parent, v);
    }

    class iterator {
        tnode<T>* ptr;
        friend class set;

    public:


        T& operator*() const {
            return ptr->val;
        }

        T* operator->() const {
            return &ptr->val;
        }

        iterator& operator++() {
            tnode<T>* temp = this->ptr;

            if (temp->right->right == temp) {
                temp = temp->right;
            }
            else if (temp->right->is_nil != true) {
                temp = temp->right;
                while (temp->left->is_nil != true) {
                    temp = temp->left;
                }
            }
            else {
                while (temp == temp->parent->right) {
                    temp = temp->parent;
                    if (temp->parent->is_nil == true)
                        break;
                }
                temp = temp->parent;
            }
            this->ptr = temp;
            return *this;
        }

        iterator operator++(int) {
            iterator temp = *this;
            ++(*this);
            return temp;
        }

        bool operator==(const iterator& other) const {
            return ptr == other.ptr;
        }

        bool operator!=(const iterator& other) const {
            return !(*this == other);
        }
    };

    iterator begin() const {
        iterator it;
        it.ptr = H->left;
        return it;
    }

    iterator end() const {
        iterator it;
        it.ptr = H;
        return it;
    }
    
    iterator find(const T& v) const {
        iterator it ;
        for (it = begin(); it != end(); ++it) {
            if (*it == v) {
                return it;
            }
        }
        return end(); 
    }
    
};

int main() {
	
    set<int> s;
    s.insert(4);
    s.insert(7);
    s.insert(9);

    set<int>::iterator it_begin = s.begin();
    set<int>::iterator it_end = s.end();

    std::cout << "First element of the set: " << *it_begin << std::endl;
    ++it_begin;
    std::cout << "Second element of the set: " << *it_begin << std::endl;
    ++it_begin;
    std::cout << "Third element of the set: " << *it_begin << std::endl;

    set<int>::iterator it_find = s.find(4);
    if (it_find != s.end()) {
        std::cout << "Value 4 found in the set." << std::endl;
    } else {
        std::cout << "Value 4 not found in the set." << std::endl;
    }
    
    return 0;
    
}

