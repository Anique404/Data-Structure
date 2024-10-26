#include<iostream>
#include<fstream>
int main() {
	std::ifstream f;
	std::string line;
	f.open("data1.txt");
	f>>line;
	std::cout<<line;
	f.close();
}
