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

    Tnode* largest_node(Tnode* ptr) const {
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

    bool erase_r(Tnode* ptr, const int& v) {
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
                Tnode* pred;
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
    // Constructor
    set() {
        n = 0;
        H = new Tnode;
        H->left = H;
        H->right = H;
        H->parent = H;
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
};
int main() {
    set s;

    s.insert(4);
    s.insert(45);
    s.insert(7);

    bool findval = s.find(4);
    std::cout << "Element 4 found before erasing: " << findval << std::endl;

    s.erase(4);
    findval = s.find(4);
    std::cout << "Element 4 found after erasing: " << findval << std::endl;

    return 0;
}


