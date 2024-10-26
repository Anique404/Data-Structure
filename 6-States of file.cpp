#include<iostream>
#include<fstream>

int main() {
	
	std::fstream f;     
	std::string line;
	f.open("data1.txt",std::ios::in|std::ios::out);
	
	if(f.is_open()){
		while(f.good()){   // states of files
		getline(f,line);
		std::cout<<line;
       }
   }
   
    else{
	std::cout<<"file is not open";
  }

	f.close();
	
}
