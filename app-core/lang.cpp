#include <lang.hpp>
//-----------------------------
namespace fs = std::filesystem;
//-----------------------------

Config::Config() : _lang{"EN"}, _dir{"lang/lang.cfig"} { set_lang(_lang); }

Config::Config(std::string lang = "EN") : _lang{lang}, _dir{"lang/lang.cfig"} {
  set_lang(lang);
}

Config::~Config() {}

void Config::set_lang(std::string lang) {
  if (!fs::exists("lang")) {
    fs::create_directory("lang");
  }

  if (!fs::exists(_dir)) {
    std::ofstream lang_config(_dir);
    lang_config << lang;
    lang_config.close();
  }

  std::ifstream lang_get(_dir);
  lang_get >> _lang;
  lang_get.close();

  if (_lang != lang) {
    _lang = lang;
    std::ofstream lang_set(_dir);
    lang_set << lang;
    lang_set.close();
  }
}

const std::string Config::get_lang() {
  if (fs::exists(_dir)) {
    std::string temp;
    std::ifstream lang_config(_dir);
    lang_config >> _lang;
    lang_config.close();
    return _lang;
  }
  return "";
}
