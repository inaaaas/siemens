#ifndef FILESYSTEM_HPP
#define FILESYSTEM_HPP
#include <iostream>
#include <vector>
#include <memory>
#include <string>

class FileSystemNode {
  
    public:
        virtual void display(int indent = 0) const = 0;
        virtual int getSize() const = 0;
        virtual std::string getName() const = 0;    
        virtual void rename(const std::string& newName) = 0;
        virtual ~FileSystemNode() = default;
};

class File : public FileSystemNode {
    int size;
    std::string name;
    public:
        File(const std::string& n, int s);
        void display(int indent = 0) const override;
        int getSize() const override;
        std::string getName() const override;
        void rename(const std::string& newName) override;
};

class Directory : public FileSystemNode {
    std::string name;
    std::vector<std::shared_ptr<FileSystemNode>> children;

  public:
    Directory(const std::string& n);
   
    void add(const std::shared_ptr<FileSystemNode>& obj);
    void remove(const std::string& n);

    std::shared_ptr<FileSystemNode> find(const std::string& n) const;

    void clear();
    
    int getChildCount();
    void display(int indent = 0) const;
    
    int getSize() const;

    std::string getName() const;
     
    void rename(const std::string& newName);
};


#endif