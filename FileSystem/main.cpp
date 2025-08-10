#include <iostream>
#include <memory>
#include "FileSystem.hpp"

int main() {
    auto root = std::make_shared<Directory>("root");

    auto docs = std::make_shared<Directory>("documents");
    docs->add(std::make_shared<File>("file1.txt", 1024));
    docs->add(std::make_shared<File>("file2.txt", 1024));

    auto pics = std::make_shared<Directory>("pictures");
    pics->add(std::make_shared<File>("img1.png", 1024));
    pics->add(std::make_shared<File>("img2.jpg", 1024));

    root->add(docs);
    root->add(pics);
    root->add(std::make_shared<File>("readme.md", 1024));
    std::cout << (root->find("pictures"))->getName() << std::endl;

    std::cout << "\nBefore clear:\n";
    root->display();

    root->clear();

    std::cout << "\nAfter clear:\n";
    root->display();
    
    return 0;
}

