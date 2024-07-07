# tairmazriv@gmail.com
# id: 209188382

CXX=clang++
CXXFLAGS=-std=c++11 -Werror -Wsign-conversion -v
LDFLAGS=-lstdc++

# List of common source files
COMMON_SOURCES=Graph.cpp Algorithms.cpp
COMMON_OBJECTS=$(COMMON_SOURCES:.cpp=.o)

# Default target
all: demo test

# Rule to create the demo executable
demo: Demo.o $(COMMON_OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o demo $(LDFLAGS)

# Rule to create the test executable
test: Test.o TestCounter.o $(COMMON_OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o test $(LDFLAGS)

# Rule to clean up the build
clean:
	rm -f *.o demo test

# Generic rule to compile .cpp files to .o files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Tidy and Valgrind rules
tidy:
	clang-tidy $(COMMON_SOURCES) TestCounter.cpp Demo.cpp Test.cpp -checks=bugprone-*,clang-analyzer-*,cppcoreguidelines-*,performance-*,portability-*,readability-*,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-cppcoreguidelines-owning-memory --warnings-as-errors=-* --

valgrind: demo test
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./demo 2>&1 | { egrep "lost| at " || true; }
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./test 2>&1 | { egrep "lost| at " || true; }

