#include<iostream>
#include<fstream>

int main() {
	
	std::ifstream f;
	std::string line;
	f.open("data1.txt");
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
