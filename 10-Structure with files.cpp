#include <iostream>
#include <fstream>
#include <string>

struct Person {
    int id;
    std::string name;
};

int main() {
    std::ifstream f;
    Person p;
    f.open("lie.txt", std::ios::in);
    if (f.is_open()) {
        std::cout << "File is open" << std::endl;
        while (f.read((char*)&p, sizeof(Person))) {
            std::cout << p.id << "  " << p.name << std::endl;
        }
        f.close();
    }
    else {
        std::cout << "File is not open" << std::endl;
        std::ofstream of;
        of.open("line.bin", std::ios::binary);
        for (int i = 0; i < 3; i++) {
            std::cout << "input id and name  " << i + 1 << ": ";
            std::cin >> p.id >> p.name;
            of.write((const char*)&p, sizeof(Person));
        }
        of.close();
    }

    return 0;
}
