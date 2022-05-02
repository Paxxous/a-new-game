default:
	g++ -I include -L lib -o src/main src/*.cpp -lmingw32 -lSDL2main -lSDL2 -lSDL2_image
	./src/main

noconsole:
	g++ -I include -L lib -o src/main src/*.cpp -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -mwindows