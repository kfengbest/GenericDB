#ifndef GLOBAL_H
#define GLOBAL_H

#include <string>
#include <sstream>

template <class T>
std::string ConvertToString(T value) {
 std::stringstream ss;
 ss << value;
 return ss.str();
}

template <class T>
void convertFromString(T &value, const std::string &s) {
  std::stringstream ss(s);
  ss >> value;
}

#endif // GLOBAL_H
