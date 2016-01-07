CXX = clang++
CXXFLAGS = -std=c++11 -stdlib=libc++ -Wall
LD = clang++
LDFLAGS = -std=c++1y -stdlib=libc++ -lc++abi
all: $(patsubst %.cpp,%.out,$(wildcard *.cpp))

%.out: %.cpp Makefile
	$(CXX) $< -o $@ $(CXXFLAGS)

clean:
	rm -f *.out
