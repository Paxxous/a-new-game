default:
	g++ -I include -L lib -o src/main src/*.cpp -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer
	./src/main

noconsole:
	g++ -I include -L lib -o src/main src/*.cpp -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -mwindows