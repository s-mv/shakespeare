#ifndef smv_shakespeare_pool_hpp
#define smv_shakespeare_pool_hpp
#include <vector>

#include "entity.hpp"

#define POOL_SIZE (2 << 10)

class Pool {
  std::vector<Entity> entities;

public:
  bool push_entity(Entity e);
  void fill_randomly();
  Entity fittest_entity();
};

#endif