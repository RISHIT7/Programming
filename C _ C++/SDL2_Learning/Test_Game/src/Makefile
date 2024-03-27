all:
	@g++ main.cpp Game.cpp TextureManager.cpp GameObject.cpp -o main `sdl2-config --cflags --libs` -lstdc++
	@./main

clean:
	@rm -f main