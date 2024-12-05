title = shakespeare
objects = build/entity.o
flags = -std=c++11

all: $(objects)
	g++ main.cpp $(objects) -I ./include -o $(title) $(flags)

build/%.o: src/%.cpp
	g++ $< -I ./include -o $@ $(flags) -c

name = test
# helper to make new source-header pairs
new:
	@printf "#ifndef smv_$(title)_$(name)_hpp\n#define smv_$(title)_$(name)_h\n\n\n#endif" > include/$(name).hpp
	@printf "#include \"$(name).hpp\"" > src/$(name).cpp