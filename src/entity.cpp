#include "entity.hpp"

#include <random>
#include <time.h>

Entity::Entity() {
  std::srand(time(0));
  for (int i = 0; i < DNA_SIZE; i++) {
    float num = (float)std::rand() / RAND_MAX - (float)RAND_MAX / 2;
    dna[i] = num;
  }
}

Entity::Entity(float dna_[DNA_SIZE]) {
  for (int i = 0; i < DNA_SIZE; i++) {
    dna[i] = dna_[i];
  }
}

float Entity::chromosome(int i) { return dna[i]; }

float Entity::fitness() {
  // TODO
  // for now just return the mean fitness
  float sum = 0;
  for (int i = 0; i < DNA_SIZE; i++)
    sum += dna[i];

  return sum / DNA_SIZE;
}
