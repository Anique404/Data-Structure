#include <iostream>

template<class k, class v>
struct pair {
    k first;
    v second;
    pair(k f = k(), v s = v()) {
        first = f;
        second = s;
    }
};

template<class k, class v>
struct mnode {
    pair<k, v> val;
    mnode<k, v>* left, * right, * parent;
    bool is_nill = false;
};

template<class k, class v>
class map {
public:
    class iterator;

private:
    mnode<k, v>* Head;
    int n;

    pair<iterator, bool> insert_r(mnode<k, v>* ptr, const pair<k, v>& val) {
        if (ptr == this->Head) {
            mnode<k, v>* temp = new mnode<k, v>;
            temp->val = val;
            temp->parent = NULL;
            temp->left = temp->right = this->Head;
            if (temp->val.first < this->Head->left->val.first) {
                this->Head->left = temp;
            }
            if (temp->val.first > this->Head->right->val.first) {
                this->Head->right = temp;
            }
            ++this->n;
            iterator it;
            it.ptr = temp;
            return { it, true };
        }
        else if (ptr->val.first == val.first) {
            iterator it;
            it.ptr = ptr;
            return { it, false };
        }
        else if (ptr->val.first > val.first) {
            pair<iterator, bool> r;
            r = insert_r(ptr->left, val);
            mnode<k, v>* temp;
            temp = r.first.ptr;
            if (r.first.ptr->parent == NULL) {
                r.first.ptr->parent = ptr;
                ptr->left = r.first.ptr;
            }
            return r;
        }
        else {
            pair<iterator, bool> r;
            r = insert_r(ptr->right, val);
            mnode<k, v>* temp;
            temp = r.first.ptr;
            if (r.first.ptr->parent == NULL) {
                r.first.ptr->parent = ptr;
                ptr->right = r.first.ptr;
            }
            return r;
        }
    }

    iterator find_r(mnode<k, v>* ptr, k key) {
        if (ptr == this->Head) {
            iterator it;
            it.ptr = this->Head;
            return it;
        }
        else if (ptr->val.first == key) {
            iterator it;
            it.ptr = ptr;
            return it;
        }
        else {
            if (ptr->val.first > key) {
                return find_r(ptr->left, key);
            }
            else {
                return find_r(ptr->right, key);
            }
        }
    }

public:
    map() {
        this->Head = new mnode<k, v>;
        this->Head->left = this->Head->right = this->Head->parent = this->Head;
        this->Head->is_nill = true;
        this->n = 0;
    }

    class iterator {
    private:
        mnode<k, v>* ptr;
        friend class map<k, v>;

    public:
        iterator& operator++() {
            if (this->ptr->right->is_nill != true) {
                this->ptr = this->ptr->right;
                while (this->ptr->left->is_nill != true) {
                    this->ptr = this->ptr->left;
                }
            }
            else {
                if (this->ptr == this->ptr->parent->left) {
                    this->ptr = this->ptr->parent;
                }
                else {
                    while (this->ptr != this->ptr->parent->left && this->ptr->parent->is_nill != true) {
                        this->ptr = this->ptr->parent;
                    }
                    this->ptr = this->ptr->parent;
                }
            }
            return *this;
        }

        iterator operator++(int) {
            iterator temp = *this;
            if (this->ptr->right->is_nill != true) {
                this->ptr = this->ptr->right;
                while (this->ptr->left->is_nill != true) {
                    this->ptr = this->ptr->left;
                }
            }
            else {
                if (this->ptr == this->ptr->parent->left) {
                    this->ptr = this->ptr->parent;
                }
                else {
                    while (this->ptr->parent->is_nill != true && this->ptr != this->ptr->parent->left) {
                        this->ptr = this->ptr->parent;
                    }
                    this->ptr = this->ptr->parent;
                }
            }
            return temp;
        }

        pair<k, v>& operator*() const {
            return this->ptr->val;
        }

        pair<k, v>* operator->() const {
            return &this->ptr->val;
        }

        bool operator==(const iterator& rhs) const {
            return this->ptr == rhs.ptr;
        }

        bool operator!=(const iterator& rhs) const {
            return this->ptr != rhs.ptr;
        }
    };

    iterator begin() const {
        iterator it;
        it.ptr = this->Head->left;
        return it;
    }

    iterator end() const {
        iterator it;
        it.ptr = this->Head;
        return it;
    }

    pair<iterator, bool> insert(const pair<k, v>& val) {
        if (this->Head->parent == this->Head) {
            mnode<k, v>* temp = new mnode<k, v>;
            temp->val = val;
            temp->left = temp->right = temp->parent = this->Head;
            this->Head->parent = this->Head->left = this->Head->right = temp;
            ++this->n;
            iterator it;
            it.ptr = temp;
            return { it, true };
        }
        else {
            pair<iterator, bool> r;
            r = insert_r(this->Head->parent, val);
            return r;
        }
    }

    iterator find(k key) {
        if (this->Head->parent == this->Head) {
            iterator it;
            it.ptr = this->Head;
            return it;
        }
        else {
            return find_r(this->Head->parent, key);
        }
    }

    v& operator[](const k& key) {
        iterator it;
        it = find(key);
        if (it.ptr->val.first == key) {
            return it.ptr->val.second;
        }
        else {
            pair<iterator, bool> p;
            p = insert({ key, v() });
            return p.first.ptr->val.second;
        }
    }
};

int main() {
    map<char, int> m;
    pair<char, int> p({ 'm', 1 });
    m.insert({ p });
    m.insert({ 'n', 1 });
    m.insert({ 'n', 1 });
    m.insert({ 'l', 1 });
    m.insert({ 'n', 1 });
    m.insert({ 'f', 1 });
    m.insert({ 'j', 1 });
    m.insert({ 'n', 1 });
    m.insert({ 'e', 1 });
    m.insert({ 's', 1 });
    m.insert({ 'g', 1 });
    m.insert({ 'c', 1 });
    m.insert({ 'k', 1 });
    m.insert({ 'b', 1 });
    m.insert({ 'y', 1 });
    m.insert({ 'v', 1 });
    m.insert({ 'x', 1 });
    m.insert({ 'j', 1 });
    m.insert({ 'i', 1 });
    m.insert({ 'a', 1 });
    m.insert({ 'z', 1 });
    m.insert({ 'd', 1 });
    m['w'] = 5;
    map<char, int>::iterator it;
    it = m.begin();
    while (it != m.end()) {
        std::cout << it->first << " : " << it->second << std::endl;
        ++it;
    }
    it = m.find('w');
    std::cout << "w in : " << it->second << std::endl;
}

