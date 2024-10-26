#include<iostream>
#include<fstream>
int main() {
	std::ofstream f;
	f.open("data1.txt");
	f << "Hello World I am Anique";
	std::cout<<"How are you";
	f.close();

}

