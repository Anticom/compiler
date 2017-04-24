#ifndef COMPILER_FILE_
#define COMPILER_FILE_

#include <string>

namespace anticom {

class File {
public:
  File(std::string filename);
  virtual ~File();

  bool isOpen() const;
  std::string read();
  void close();

private:
  const std::string filename;
  std::string* filecontents;
};

}

#endif//COMPILER_FILE_
