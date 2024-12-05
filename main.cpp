#include <cstdlib>
#include <iostream>
#include <string>

#include "params.hpp"

void print_usage() {
  std::cout
      << "Usage: ./a.out [-i <input_file>] [-t <train_file>] [-o <output_file>]"
      << std::endl;
  std::cout << "Example: ./a.out -i data.g -t train.txt -o output.g"
            << std::endl;
}

int main(int argc, char* argv[]) {
  if (argc % 2 != 1) {
    print_usage();
    return 1;
  }

  Params params;

  for (int i = 1; i < argc; i++) {
    std::string arg = argv[i];

    if (arg == "-i") {
      if (i + 1 < argc) {
        params.inputFile = argv[i + 1];
        i++;
      } else {
        std::cerr << "Error: Missing value for " << arg << std::endl;
        return 1;
      }
    } else if (arg == "-t") {
      if (i + 1 < argc) {
        params.trainingText = argv[i + 1];
        i++;
      } else {
        std::cerr << "Error: Missing value for " << arg << std::endl;
        return 1;
      }
    } else if (arg == "-o") {
      if (i + 1 < argc) {
        params.outputFile = argv[i + 1];
        i++;
      } else {
        std::cerr << "Error: Missing value for " << arg << std::endl;
        return 1;
      }
    } else {
      std::cerr << "Error: Unknown option " << arg << std::endl;
      print_usage();
      return 1;
    }
  }

  if (!params.inputFile.empty()) {
    std::cout << "Input File: " << params.inputFile << std::endl;
  } else {
    std::cout << "No input file provided." << std::endl;
  }

  if (!params.trainingText.empty()) {
    std::cout << "Training File: " << params.trainingText << std::endl;
  } else {
    std::cout << "No training file provided." << std::endl;
  }

  if (!params.outputFile.empty()) {
    std::cout << "Output File: " << params.outputFile << std::endl;
  } else {
    std::cout << "No output file provided." << std::endl;
  }

  return 0;
}
