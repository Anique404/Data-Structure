#include <iostream>
#include <fstream>

int main() {
    // Open file in input mode
    std::ifstream inputFile;
	inputFile.open("data1.txt", std::ios::in);
    if (inputFile.is_open()) {
        std::cout << "Opened file in input mode.\n";
        inputFile.close();
    } else {
        std::cerr << "Failed to open file in input mode.\n";
    }

    // Open file in output mode
    std::ofstream outputFile;
	outputFile.open("example_output.txt", std::ios::out);
    if (outputFile.is_open()) {
        std::cout << "Opened file in output mode.\n";
        outputFile << "Hello, World!\n";
        outputFile.close();
    } else {
        std::cerr << "Failed to open file in output mode.\n";
    }

    // Open file in append mode
    std::ofstream appendFile;
	 appendFile.open("example_output.txt", std::ios::out | std::ios::app);
    if (appendFile.is_open()) {
        std::cout << "Opened file in append mode.\n";
        appendFile << "Appending some data.\n";
        appendFile.close();
    } else {
        std::cerr << "Failed to open file in append mode.\n";
    }
    
    // Open file in ate mode
    std::fstream ateFile;
	ateFile.open("example_output.txt", std::ios::out | std::ios::ate);
    if (ateFile.is_open()) {
        std::cout << "Opened file in ate mode.\n";
        ateFile<<"who are you";
        ateFile.close();
    } else {
        std::cerr << "Failed to open file in ate mode.\n";
    }
    
    
    // Open file in trunc mode
    std::ofstream truncFile;
	truncFile.open("example_output.txt", std::ios::out | std::ios::trunc);
    if (truncFile.is_open()) {
        std::cout << "Opened file in trunc mode.\n";
        truncFile<<"how are you";
        truncFile.close();
    } else {
        std::cerr << "Failed to open file in trunc mode.\n";
    }

//
//    // Open file in binary mode
//    std::fstream binaryFile;
//	binaryFile.open("example_binary.bin", std::ios::out | std::ios::binary);
//    if (binaryFile.is_open()) {
//    	
//        std::cout << "Opened file in binary mode.\n";
//        binaryFile<<"how are you";
//        binaryFile.close();
//    } else {
//        std::cerr << "Failed to open file in binary mode.\n";
//    }
//   
//    return 0;

}

