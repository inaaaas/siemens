#include "FileSystem.hpp"

//file
File::File(const std::string& n, int s) : name(n), size(s) {}
 void File::display(int indent) const{
    std::cout << std::string(indent, ' ') << "- file: " << name << " (" << size << " Byte)\n";
    return;
}

int File::getSize() const{
    return size;
}

 std::string File::getName() const{
    return name;
}

void File::rename(const std::string& newName){
    name = newName;
     return;
 }


//directory

    Directory::Directory(const std::string& n) : name(n) {}
   
    void Directory::add(const std::shared_ptr<FileSystemNode>& obj) {
        children.push_back(obj);
        return;
    }
    
    void Directory::remove(const std::string& n) {
        auto pos = std::remove_if(children.begin(), children.end(),
                        [&](const std::shared_ptr<FileSystemNode> child) {
                            return child->getName() == n;
                        });
        children.erase(pos, children.end());
        return;
    }

    std::shared_ptr<FileSystemNode> Directory::find(const std::string& n) const{
        if (name == n) {
            return nullptr;
        }
        for (const auto& child : children) {
            if (child->getName() == n) {
                return child;
            }

            if (auto dir = std::dynamic_pointer_cast<Directory> (child))  {
                auto found = dir->find(n);
                if (found) return found;
            }
        }
        return nullptr;
    }

    void Directory::clear() {
        for (auto& child : children) {
            if (auto dir = std::dynamic_pointer_cast<Directory>(child)) {
                dir->clear();
            }
        }
        children.clear();
        return;
    }
    
    int Directory::getChildCount() {
        int total = 0;
        for (const auto& child : children) {
            total += 1;
          if (auto dir = std::dynamic_pointer_cast<Directory>(child)) {
            total += dir->getChildCount();
          }
        }
        return total;
    }

    void Directory::display(int indent) const{
        std::cout << std::string(indent, ' ') << "+ directory: " << name 
                  << " (" << getSize() << " Byte)\n";

        for (const auto& child : children) {
            child->display(indent + 4);
        }
        return;
    }
    
    int Directory::getSize() const{
        int total = 0;
        for (const auto& child : children) {
            total += child->getSize();
        }
        return total;
    }

    std::string Directory::getName() const{
        return name;
    }
     
    void Directory::rename(const std::string& newName){
            name = newName;
            return;
    }
