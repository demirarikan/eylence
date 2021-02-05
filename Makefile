# ADD MORE FLAGS HERE
FLAGS=
CPP=g++

main: src/circle.cpp main
	$(CPP) src/circle.cpp -o main

.PHONY: clean

clean:
	rm main

