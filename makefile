all:
	clang++ -std=c++14 time.cpp comm.cpp -o timer

install:
	@echo "you will have to sudo"
	cp timer /usr/bin