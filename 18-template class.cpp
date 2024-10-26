#include<iostream>
using namespace std;

template <class F, class G, class H>
class Tripplet {
    F a;
    G b;
    H c;

public:
    
    Tripplet(F q = F(), G w = G(), H e = H()) : a(q), b(w), c(e) {}

    template <class w, class x, class y>
    friend ostream& operator<<(ostream& output, const Tripplet<w, x, y>& t) {
        output << "(" << t.a << ", " << t.b << ", " << t.c << ")";
        return output;
    }

   template <class w, class x, class y>
    friend istream& operator>>(istream& input, Tripplet<w , x , y>& t) {
        input >> t.a >> t.b >> t.c;
        return input;
    }
};

int main() {
    
    Tripplet<int, double, string> t(1, 2.5, "Hello");
    cout<<t;
    
    

    return 0;
}

