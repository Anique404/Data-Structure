#include<iostream>
#include<fstream>

int main(int argc,char **argv){
	
	std::cout<<"You have entered "<<argc<<" Arguments"<<std::endl;
	
	for(int i=0;i<argc;i++){
		std::cout<<i+1<<"  "<<argv[i]<<std::endl;
	}
	
}
