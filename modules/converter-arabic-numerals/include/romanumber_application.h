// Copyright 2021 Makarychev Sergey

#ifndef MODULES_CONVERTER_ARABIC_NUMERALS_INCLUDE_ROMANUMBER_APPLICATION_H_
#define MODULES_CONVERTER_ARABIC_NUMERALS_INCLUDE_ROMANUMBER_APPLICATION_H_

#include <string>

class RomaNumberApplication {
 private:
  std::string message_;
  void help(const char* appname, const char* message = "");
  bool validateNumberOfArguments(int argc, const char** argv);
  int parseInt(const char* arg);
 public:
  RomaNumberApplication();
  std::string operator()(int argc, const char** argv);
};

#endif  // MODULES_CONVERTER_ARABIC_NUMERALS_INCLUDE_ROMANUMBER_APPLICATION_H_
