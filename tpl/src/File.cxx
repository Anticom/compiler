#include "File.hxx"

#include <fstream>

anticom::File::File(std::string filename)
    : filename(filename) {

};

anticom::File::~File() {
    this->close();
};

bool anticom::File::isOpen() const {
    return this->filecontents != nullptr;
};

std::string anticom::File::read() {
    std::ifstream t(this->filename);
    return std::string((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());
    /*
    if(!this->isOpen()) {
      std::ifstream t(this->filename);
      this->filecontents = new std::string((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());
    }
    return *this->filecontents;
    */
};

void anticom::File::close() {
    /*
    if(this->isOpen()) {
      delete this->filecontents;
    }
    */
};

