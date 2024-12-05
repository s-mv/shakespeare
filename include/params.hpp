#ifndef smv_shakespeare_params_hpp
#define smv_shakespeare_params_hpp
#include <string>

struct Params {
  std::string inputFile;     // .pear file
  std::string trainingText;  // .txt file
  std::string outputFile;    // .pear file
};

#endif