#include <iostream>

struct Tnode {
    int val;
    Tnode* left,* right;
};

class BinaryTree{
	private:
		Tnode *root;
	
	bool find_rec(Tnode *ptr,const int &v){
		
		if(ptr==NULL){
			return false;
		}
		else if(ptr->val==v){
			return true;
		}
		else if(v<ptr->val){
			return find_rec(ptr->left,v);
		}
		else{
			return find_rec(ptr->right,v);
		}
		
	}
	int sum_rec(Tnode* ptr){
		
		int sum=0;
		
		if(ptr==NULL){
			return 0;
		}
		else{
			return ptr->val+sum_rec(ptr->left)+sum_rec(ptr->right);
		}
		
	}
	int factorial_rec(int n) {
    if (n < 0) {
        return -1;
    } 
	else if (n == 0 || n == 1) {
        return 1;
    }
	 else {
        return n * factorial(n - 1);
    }
}

	public:
		
	 BinaryTree() {
        root = NULL; // Initialize root to nullptr
    }
    
	bool find(const int&val){
		return find_rec(root,val);
	}
	int sum(){
		return sum_rec(root);
	}
	int factorial(int n){
		return factorial_rec(n);
	}
	
};
int main() {
    BinaryTree tree;
//
//    tree.insert(10);
//    tree.insert(5);
//    tree.insert(15);
//    tree.insert(7);
//    tree.insert(3);

    int findVal = 7;
    std::cout << "Is " << findVal << " in the tree? " << (tree.find(findVal) ? "Yes" : "No") << std::endl;
    std::cout << "Sum of all elements in the tree: " << tree.sum() << std::endl;

    return 0;
}

