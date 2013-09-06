#ifndef _OJ_JUDEGER_H_
#define _OJ_JUDEGER_H_

#include <fstream>
#include <string>
// #include <vector>
#include <boost/format.hpp>

#include "../../log.hpp"
#include "../protocol.h"

namespace oj{

class Judger
{
 public:
  Judger(utils::Log& log, uint32_t run_id) :
      log_(log)
      {
        results_.run_id = run_id;
        source_file_path_.reserve(15);
        execute_file_path_.reserve(15);
        compile_error_file_.reserve(15);
        vec_cmd_.reserve(15);
      }
  virtual ~Judger() { }

  virtual void storeSourceFile(const std::string& source_code,
                       // uint32_t code_type,
                       const char* work_dir_path) { }
  virtual bool compile() {
    return true;
  }
  bool execute(const ExecuteCondtion& execute_condtion,
               const IOFileno& ioFileno);

  Results getResults() {
    return results_;
  }

 protected:
  virtual bool getCmdArgs(CmdArgs& cmd_args);
  virtual bool getCallLimit(CallLimit& call_limit) {
    return false;
  }
  virtual bool expressCompile() {
    return false;
  }
  void readFromFile(const char *filepath, std::vector<char> &data) {
    std::ifstream input(filepath);
    input.seekg(0, std::ios::end);
    int length = input.tellg();
    data.resize(length);
    input.seekg(0, std::ios::beg);
    input.read(&data[0], length);
  }
  void writeToFile(const std::string &source_code) {
    std::ofstream output(&source_file_path_[0]);
    output.write(source_code.c_str(), source_code.size());
  }

  bool hasData(const char* filepath) {
    std::ifstream input(filepath);
    input.seekg(0, std::ios::end);

    if (input.tellg() > 0)
      return true;
    return false;
  }


  std::string source_file_path_;

  std::string execute_file_path_;
  std::string compile_error_file_;
  std::string vec_cmd_;
  std::string user_output_file_;
  std::string right_output_file_;
  Results results_;
  utils::Log &log_;
};
}
#endif
