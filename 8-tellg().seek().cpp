#include<iostream>
#include<fstream>

int main() {
	
	std::fstream f;   
	
	// tellg(), seekg()  file to program
	
	f.open("file.txt",std::ios::out);
	
	std::cout<<f.tellg()<<std::endl; 
	f<<"hello world" ;
	
	std::cout<<f.tellg()<<std::endl;
	f.seekg(-5,std::ios::end);
	std::cout<<f.tellg()<<std::endl;
	f<<"Anique" ;
	
	std::cout<<f.tellg()<<std::endl;
	f.seekg(0,std::ios::beg);
    std::cout<<f.tellg()<<std::endl;
	f<<"Hii" ;
	std::cout<<f.tellg()<<std::endl;
	
	std::ifstream input;
	input.open("file.txt");
	std:: string ch;
	while(input.good()){
		getline(input,ch);
		std::cout<<ch<<std::endl;
		
	}
	
}
