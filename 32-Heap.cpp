#include <iostream>


template <typename T>

/*
  void ReHeapUp_r(const int i) {
        int p = (i - 1) / 2;
        if (i > 0 && this->data[i] > this->data[p]) {
            std::swap(this->data[i], this->data[p]);
            ReHeapUp(p);
        }
    }
    
    
    void ReHeapDown_r(const int i) {
        int left_child, right_child, max_child;
        left_child = (i * 2) + 1;
        right_child = (i * 2) + 2;
        max_child = left_child;
        if (left_child < n) {
            if (right_child < n && this->data[left_child] < this->data[right_child]) {
                max_child = right_child;
            }
            if (this->data[i] < this->data[max_child]) {
                std::swap(this->data[i], this->data[max_child]);
                ReHeapDown(max_child);
            }
        }
    }
	
*/
    
void Reheapdown(T* data, int f, int l) {
	int lc, rc, mc;

	while (true) {
		lc = (f * 2) + 1;
		rc = (f * 2) + 2;
		mc = f;

		if (lc < l) {
			if (rc < l && data[rc] > data[lc]) {
				mc = rc;
			}
			else {
				mc = lc;
			}

			if (data[f] < data[mc]) {
				std::swap(data[f], data[mc]);
				f = mc; 
			}
			else {
				break; 
			}
		}
		else {
			break; 
		}
	}
}

template<typename T>
void Reheapup(T& data, int f, int l)
{
	int p = (l - 1) / 2;

	while (p >= f && l > p)
	{
		if (data[l] > data[p])
		{
			std::swap(data[l], data[p]);
		}

		p = (l - 1) / 2;
		l = p;
		p = (p - 1) / 2;
	}

}


template <typename T>
class priorityqueue {
	T* data;
	int n, Size;

public:

	priorityqueue(int s = 100) {

		this->n = 0;
		this->Size = s;
		this->data = new T[s];

	}

	~priorityqueue() {
	delete[]this->data;
	}


	void push(int v) {
		data[n] = v;
		Reheapup(data, 0, n);
		n++;
	}

	void pop() {
		data[0]=data[n-1];
		n--;
		Reheapdown(data, 0, n - 1);

	}
	T top() {
		return data[0];
	}

	void empty() {
		return n == 0;

	}
	void size() {
		return n+1;

	}
	void display() {

		for (int i = 0; i < n; i++) {
			std::cout << data[i] <<"  ";
		}
	}
	
	
	priorityqueue(const priorityqueue& rhs)   {
		data = NULL; 
		n=0; 
		Size = 0;
		*this = rhs;  
	}

	
	priorityqueue& operator=(const priorityqueue& rhs) {
		if (this != &rhs) {
			delete[] data; 
			n = rhs.n;
			Size = rhs.Size;
			data = new T[Size];
			for (int i = 0; i < n; ++i) {
				data[i] = rhs.data[i];
			}
		}
		return *this;
	}

};

int main()
{
	priorityqueue<int> p;
	p.push(5);
	p.push(51);
	p.push(3);
	p.push(6);
	p.push(87);

	std::cout << p.top() << std::endl;
	p.display();
	std::cout<< std::endl;
	priorityqueue<int> p1=p;
	p1.display();
	std::cout << std::endl;

	p1.pop();
	p1.display();
	std::cout << std::endl;

	p1.pop();
	p1.display();
	std::cout << std::endl;

	p1.pop();
	p1.display();
	std::cout << std::endl;
}

