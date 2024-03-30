all:
	@g++ main.cpp Game.cpp TextureManager.cpp GameObject.cpp Map.cpp Vector2D.cpp -o main `sdl2-config --cflags --libs` -lstdc++
	@./main

clean:
	@rm -f main