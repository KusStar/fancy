all:
	cmake -Hstandalone -B./build/standalone
	cmake --build ./build/standalone
	./build/standalone/run

