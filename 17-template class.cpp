//#pragma once
#include <iostream>
using namespace std;
template <class type> 
class Matrix {
private:
	
    int rows, cols;
    type **matrix;
    
    template <class T>
    friend istream &operator>>(istream &input, Matrix<T> &w);

    template <class T>
    friend ostream &operator<<(ostream &output, const Matrix<T> &w);
public:
	
    Matrix();
    Matrix(int r, int c);
    Matrix(int r, int c,type **array);
    Matrix(const Matrix <type>&w);
    ~Matrix();

    const int& operator()(int row, int col) const;
    int& operator()(int row, int col);
    
    Matrix <type> operator+(const Matrix <type>&r) const;
    Matrix <type> operator-(const Matrix <type> &r) const;
    Matrix <type> operator*(const Matrix <type> &r) const;
    Matrix <type> &  operator=(const Matrix <type>&r);
    Matrix <type> & operator+=(const Matrix  <type> & r);
    Matrix <type> &  operator-=(const Matrix <type> & r);
    Matrix <type> &  operator*=(const Matrix <type> &  r);

    
};

//#include"Matrix.h"
template <class type>
Matrix<type>::Matrix() {
    rows = 0;
    cols = 0;
    matrix = NULL;
    cout << "The Default Constructor is called" << endl;
}
template <class type>
Matrix<type>::Matrix(int r, int c) {
    rows = r;
    cols = c;
    matrix = new type *[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new type[cols];
    }
    cout << "The Parameterized Constructor with 2 parameter is called" << endl;
}
template <class type>
Matrix<type>::Matrix(const Matrix <type>&w) {
    
    rows=0;
    cols=0;
    matrix=NULL;
	
        rows = w.rows;
        cols = w.cols;
        matrix = new type *[rows];
        for (int i = 0; i < rows; ++i) {
            matrix[i] = new type[cols];
            for (int j = 0; j < cols; ++j) {
                matrix[i][j] = w.matrix[i][j];
            }
        }
        cout<<"Copy constructor is called"<<endl;
    }
template <class type>
Matrix<type>::~Matrix() {
if(matrix!=NULL){
	
        for (int i = 0; i < rows; ++i) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }
    cout <<"Destructor is called"<<endl;
    	}

template <class type>
const int& Matrix<type>::operator()(int row, int col) const {
    return matrix[row][col];
    }

template <class type>
int& Matrix<type>::operator()(int row, int col) {
return matrix[row][col];
    }


template <class type>
Matrix<type>::Matrix(int r, int c,type **array){
	rows = r;
    cols = c;
    matrix = new type *[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new type[cols];
    for (int j=0;j<cols;j++){
    	matrix[i][j]=array[i][j];	
	}
    }
    cout << "The Parameterized Constructor with 3 parameter is called" << endl;
}

template <class type>
Matrix <type>Matrix<type>::operator+(const Matrix <type> &r) const {
    if (rows != r.rows || cols != r.cols) {
        cerr << "Matrix addition is not possible." << endl;
        return Matrix();
    }

    Matrix newmatrix(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            newmatrix.matrix[i][j] = matrix[i][j] + r.matrix[i][j];
        }
    }
    return newmatrix;
}

template <class type>
Matrix <type>Matrix<type>::operator-(const Matrix<type> &r) const {
    if (rows != r.rows || cols != r.cols) {
        cerr << "Matrix subtraction is not possible." << endl;
        return Matrix();
    }

    Matrix newmatrix(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            newmatrix.matrix[i][j] = matrix[i][j] - r.matrix[i][j];
        }
    }
    return newmatrix;
}

template <class type>
Matrix <type>Matrix<type>::operator*(const Matrix <type>&r) const {
    if (cols != r.rows) {
        cerr << "Matrix multiplication is not possible." << endl;
        return Matrix();
    }

    Matrix newmatrix(rows, r.cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < r.cols; ++j) {
            newmatrix.matrix[i][j] = 0;
            for (int k = 0; k < cols; ++k) {
                newmatrix.matrix[i][j] += matrix[i][k] * r.matrix[k][j];
            }
        }
    }
    return newmatrix;
}

template <class type>
Matrix <type> & Matrix<type>::operator=(const Matrix<type> &r) {
    if (this != &r) {
        if (matrix != NULL) {
            for (int i = 0; i < rows; ++i) {
                delete[] matrix[i];
            }
            delete[] matrix;
        }

        rows = r.rows;
        cols = r.cols;
        matrix = new int *[rows];
        for (int i = 0; i < rows; ++i) {
            matrix[i] = new int[cols];
            for (int j = 0; j < cols; ++j) {
                matrix[i][j] = r.matrix[i][j];
            }
        }
    }
    return *this;
}

template <class type>
Matrix <type> &  Matrix<type>::operator+=(const Matrix<type>& r) {
    if (rows != r.rows || cols != r.cols) {
        cerr << "Matrix addition is not possible." << endl;
    } else {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                matrix[i][j] += r.matrix[i][j];
            }
        }
    }
    return *this;
}
template <class type>
Matrix <type> & Matrix<type>::operator-=(const Matrix<type> & r) {
    if (rows != r.rows || cols != r.cols) {
        cerr << "Matrix subtraction is not possible." << endl;
    } else {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                matrix[i][j] -= r.matrix[i][j];
            }
        }
    }
    return *this;
}

template <class type>
Matrix <type> & Matrix<type>::operator*=(const Matrix<type> & r) {
    if (cols != r.rows) {
        cerr << "Matrix multiplication is not possible." << endl;
    } else {
        Matrix result(rows, r.cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < r.cols; ++j) {
                result.matrix[i][j] = 0;
                for (int k = 0; k < cols; ++k) {
                    result.matrix[i][j] += matrix[i][k] * r.matrix[k][j];
                }
            }
        }
        *this = result;
    }
    return *this;
}

template <class type>
istream &operator>>(istream &input, Matrix<type> &w) {
 if (w.matrix == NULL) {
        cout << "Enter the number of rows: ";
        input >> w.rows;
        cout << "Enter the number of columns: ";
		input >> w.cols;
		
      }
      
        w.matrix = new type *[w.rows];
        for (int i = 0; i < w.rows; ++i) {
            w.matrix[i] = new type[w.cols];
            for (int j = 0; j < w.cols; ++j) {
            	cout << "Enter elements for row " << i + 1 <<"and cols"<<j+1 <<": ";
                input >> w.matrix[i][j];
            }
        }
    
    return input;
    
}


template <class type>
ostream &operator<<(ostream &output, const Matrix <type>&w) {
   for (int i = 0; i < w.rows; ++i) {
        for (int j = 0; j < w.cols; ++j) {
            output << w.matrix[i][j] << " ";
        }
        output << endl;
    }
    return output;
}



//#include"Matrix.h"

int main() {
	
   Matrix<int> m1(2, 2), m2(2, 2);

    cout << "Enter elements for matrix m1:" << endl;
    cin >> m1;

    cout << "Enter elements for matrix m2:" << endl;
    cin >> m2;

    cout << "Matrix m1:" << endl;
    cout << m1;

    cout << "Matrix m2:" << endl;
    cout << m2;

    cout << "Addition of m1 and m2:" << endl;
    Matrix<int> m3 = m1 + m2;
    cout << m3;

    cout << "Subtraction of m1 and m2:" << endl;
    Matrix<int> m4 = m1 - m2;
    cout << m4;

    cout << "Multiplication of m1 and m2:" << endl;
    Matrix<int> m5 = m1 * m2;
    cout << m5;
    
    
}


