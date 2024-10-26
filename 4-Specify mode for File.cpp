#include<iostream>
#include<fstream>

int main() {
	
	std::fstream f;     
	std::string line;
	f.open("data1.txt",std::ios::in|std::ios::out);
	//if you want to open a file in read or output form from fstream  than specify the it
	if(f.is_open()){
		while(!f.eof()){
		getline(f,line);
		std::cout<<line;
       }
   }
   
    else{
	std::cout<<"file is not open";
  }

	f.close();
	
}
