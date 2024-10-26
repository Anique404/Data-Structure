#include <iostream>

struct Tnode {
    int val;
    Tnode* left;
    Tnode* right;
    Tnode* parent;
    bool is_nil;
};

class set {
private:
    Tnode* H;
    int n;

    bool find_rec(Tnode* ptr, const int& v) {
        if (ptr == H) {
            return false;
        } else if (ptr->val == v) {
            return true;
        } else if (v < ptr->val) {
            return find_rec(ptr->left, v);
        } else {
            return find_rec(ptr->right, v);
        }
    }

    Tnode* insert_rec(Tnode* ptr, const int& v) {
        if (ptr == H) {
            n++;

            Tnode* temp = new Tnode;
            temp->val = v;
            temp->is_nil = false;

            temp->left = H;
            temp->right = H;
            
            if (temp->val < H->left->val) {
                H->left = temp;
            }
            if (temp->val > H->right->val) {
                H->right = temp;
            }

            return temp;
        } else if (v < ptr->val) {
            ptr->left = insert_rec(ptr->left, v);
            ptr->left->parent = ptr;
            return ptr;
        } else if (v > ptr->val) {
            ptr->right = insert_rec(ptr->right, v);
            ptr->right->parent = ptr;
            return ptr;
        } else {
            return ptr;
        }
    }

    Tnode* smallest_node(Tnode* ptr) const {
        if (H->parent == H) {
            return H;
        }
        if (ptr == H) {
            ptr = H->parent;
        }
        while (ptr->left != H) {
            ptr = ptr->left;
        }
        return ptr;
    }

    Tnode* largest_node(Tnode* ptr) const {
        if (H->parent == H) {
            return H;
        }
        if (ptr == H) {
            ptr = H->parent;
        }
        while (ptr->right != H) {
            ptr = ptr->right;
        }
        return ptr;
    }

    bool erase_r(Tnode* ptr, const int& v) {
        if (ptr == H) {
            return false;
        } else if (v > ptr->val) {
            return erase_r(ptr->right, v);
        } else if (v < ptr->val) {
            return erase_r(ptr->left, v);
        } else if (ptr->val == v) {
            if (ptr->left == H && ptr->right == H) {
                if (ptr->parent == H) {
                    H->parent = H->left = H->right = H;
                } else if (ptr == ptr->parent->left) {
                    ptr->parent->left = H;
                } else if (ptr == ptr->parent->right) {
                    ptr->parent->right = H;
                }
                delete ptr;
            } else if (ptr->left != H && ptr->right == H) {
                ptr->left->parent = ptr->parent;
                if (ptr->parent == H) {
                    H->parent = ptr->left;
                } else if (ptr == ptr->parent->right) {
                    ptr->parent->right = ptr->left;
                } else if (ptr == ptr->parent->left) {
                    ptr->parent->left = ptr->left;
                }
                delete ptr;
            } else if (ptr->right != H && ptr->left == H) {
                ptr->right->parent = ptr->parent;
                if (ptr->parent == H) {
                    H->parent = ptr->right;
                } else if (ptr == ptr->parent->right) {
                    ptr->parent->right = ptr->right;
                } else if (ptr == ptr->parent->left) {
                    ptr->parent->left = ptr->right;
                }
                delete ptr;
            } else {
                Tnode* pred;
                pred = largest_node(ptr->left);
                if (ptr->parent == H)
                    H->parent = pred;
                else if (ptr == ptr->parent->left)
                    ptr->parent->left = pred;
                else
                    ptr->parent->right = pred;
                ptr->right->parent = pred;
                pred->right = ptr->right;
                if (pred != ptr->left) {
                    pred->parent->right = pred->left;
                    if (pred->left != H)
                        pred->left->parent = pred->parent;
                    pred->left = ptr->left;
                    pred->left->parent = pred;
                    pred->parent = ptr->parent;
                }
                delete ptr;
            }
            --n;
            return true;
        }
    }
    
    Tnode* copy_r(Tnode* ptr) {
        if (ptr == H || ptr->is_nil) {
            return H;
        }
        Tnode* temp = new Tnode;
        temp->val = ptr->val;
        temp->is_nil = false;
        temp->left = copy_r(ptr->left);
        temp->right = copy_r(ptr->right);
        if (temp->left != H) {
            temp->left->parent = temp;
        }
        if (temp->right != H) {
            temp->right->parent = temp;
        }
        return temp;
    }
    
    void clear_r(Tnode* ptr) {
        if ( ptr != H && !ptr->is_nil) {
            clear_r(ptr->left);
            clear_r(ptr->right);
            delete ptr;
        }
    }

public:
    // Constructor
    set() {
        n = 0;
        H = new Tnode;
        H->left = H;
        H->right = H;
        H->parent = H;
        H->is_nil = true;
    }

    

    // Copy Constructor
    set(const set& rhs) {
        H = new Tnode;
        H->left = H;
        H->right = H;
        H->parent = H;
        H->is_nil = true;
        operator=(rhs);
    }

    // Assignment Operator
    set& operator=(const set& rhs) {
        if (this != &rhs) {
            clear();
            H->parent = copy_r(rhs.H->parent);
            if (H->parent != H) {
                H->parent->parent = H;
                H->right = largest_node(H->parent);
                H->left = smallest_node(H->parent);
            }
            n = rhs.n;
        }
        return *this;
    }

    bool find(const int& val) {
        return find_rec(H->parent, val);
    }

    void insert(const int& v) {
        if (H->parent == H) {
            Tnode* temp = new Tnode;
            temp->val = v;
            temp->parent = H;
            temp->left = H;
            temp->right = H;
            temp->is_nil = false;
            H->parent = temp;
            H->left = temp;
            H->right = temp;
            n++;
        } else {
            insert_rec(H->parent, v);
        }
    }

    bool erase(const int& v) {
        return erase_r(H->parent, v);
    }

    void clear() {
        clear_r(H->parent);
        H->parent = H;
        H->left = H;
        H->right = H;
        n = 0;
    }
    
    // Destructor
    ~set() {
        clear();
    }
};
int main() {
    set s1;

    // Insert elements into s1
    s1.insert(4);
    s1.insert(45);
    s1.insert(7);

    // Test find function
    bool findval = s1.find(4);
    std::cout << "Element 4 found in s1 before erasing: " << findval << std::endl;

    // Test erase function
    s1.erase(4);
    findval = s1.find(4);
    std::cout << "Element 4 found after erasing: " << findval << std::endl;

    // Test copy constructor
    set s2 = s1;
    std::cout << "Elements in copied set s2: ";
    std::cout << std::endl;
    
    findval = s2.find(45);
    std::cout << "Element 45 found in s2: " << findval << std::endl;


    // Test assignment operator
    set s3;
    s3.insert(10);
    s3 = s1;
    std::cout << "Elements in assigned set s3: ";
    std::cout << std::endl;
    
    findval = s3.find(7);
    std::cout << "Element 7 found in s3: " << findval << std::endl;


    // Test clear function
    s1.clear();
    std::cout << "Elements in set s1 after clearing:";
    std::cout << std::endl;
    
    findval = s1.find(45);
    std::cout << "Element 45 found in s1: " << findval << std::endl;



    return 0;
}




