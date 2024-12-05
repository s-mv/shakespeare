#include <cstdlib>
#include <iostream>
#include <map>
#include <string>

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

  std::map<std::string, std::string> params;

  for (int i = 1; i < argc; i++) {
    std::string arg = argv[i];

    // Check if the argument is one of the expected options
    if (arg == "-i" || arg == "-t" || arg == "-o") {
      if (i + 1 < argc) {
        params[arg] = argv[i + 1];
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

  if (params.find("-i") != params.end()) {
    std::cout << "Input File: " << params["-i"] << std::endl;
  } else {
    std::cout << "No input file provided." << std::endl;
  }

  if (params.find("-t") != params.end()) {
    std::cout << "Training File: " << params["-t"] << std::endl;
  } else {
    std::cout << "No training file provided." << std::endl;
  }

  if (params.find("-o") != params.end()) {
    std::cout << "Output File: " << params["-o"] << std::endl;
  } else {
    std::cout << "No output file provided." << std::endl;
  }

  return 0;
}
