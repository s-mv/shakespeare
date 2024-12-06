#ifndef smv_shakespeare_entity_hpp
#define smv_shakespeare_entity_hpp

// temporary includes
#include <iostream>
#include <math.h>

#define DNA_SIZE (1024)

class Entity {
  float dna[DNA_SIZE]; // "parameters"

public:
  Entity();
  Entity(float dna_[DNA_SIZE]);
  float chromosome(int i);
  float fitness();

  // temporary function
  void dna_description() {
    float sum;
    float variance;
    float mean;
    for (int i = 0; i < DNA_SIZE; i++)
      sum += chromosome(i);
    mean = sum / DNA_SIZE;

    for (int i = 0; i < DNA_SIZE; i++) {
      float factor = chromosome(i) - mean;
      variance += factor * factor;
    }

    variance /= DNA_SIZE;

    std::cout << std::endl;
    std::cout << "Sum:      " << sum << std::endl;
    std::cout << "Mean:     " << mean << std::endl;
    std::cout << "Variance: " << variance << std::endl;
    std::cout << "Std. dev: " << powf(variance, 0.5) << std::endl;
  }
};

#endif
