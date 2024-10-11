CC := g++

all: src/main.cpp src/atomic_record.hpp src/atomic_change.hpp src/record.hpp
	${CC} -O3 src/main.cpp -o atomic

.PHONY: clean
clean:
	rm -rf atomic atomic.s
