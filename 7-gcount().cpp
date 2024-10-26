#include <iostream>
#include <fstream>

int main() {
    std::ifstream file("example_output.txt");
    if (!file.is_open()) {
        std::cerr << "Failed to open file." << std::endl;
        return 1;
    }

    char buffer[100];
    file.read(buffer, 20); // Read up to 10 characters from the file
    std::streamsize bytesRead = file.gcount(); // Get the number of characters read
    std::cout << "Read " << bytesRead << " characters from the file." << std::endl;

    file.close();
    return 0;
}

