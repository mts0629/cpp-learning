CXXFLAGS := -Wall -Wextra -Wpedantic

.PHONY: clean

calc: calc.cpp
	mkdir -p ./bin
	$(CXX) $< $(CXXFLAGS) -o ./bin/$@

clean:
	rm -rf ./bin

