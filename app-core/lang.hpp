#pragma once
#include <filesystem>
#include <fstream>
#include <string>

//-----------------------------

class Config {
 private:
  std::string _lang;
  std::string _dir;

 public:
  Config();
  Config(std::string lang);
  ~Config();
  void set_lang(std::string);
  const std::string get_lang();
};
