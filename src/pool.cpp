#include "pool.hpp"

#include <random>
#include <time.h>

bool Pool::push_entity(Entity e) {
  if (entities.size() == POOL_SIZE)
    return false;

  // TODO arrange by priority (fitness)
  entities.push_back(e);
  return true;
}

void Pool::fill_randomly() {
  for (int i = 0; i < POOL_SIZE; i++)
    push_entity(Entity());
}

Entity Pool::fittest_entity() {
  int fittest_i = 0;
  float fittest_fitness = entities.at(fittest_i).fitness();
  for (int i = 1; i < POOL_SIZE; i++) {
    float fitness = entities.at(i).fitness();
    if (fitness > fittest_fitness) {
      fittest_i = i;
      fittest_fitness = fitness;
    }
  }

  return entities.at(fittest_i);
}
