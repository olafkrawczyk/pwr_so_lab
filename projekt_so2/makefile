game: game.o ball.o brick.o paddle.o wall.o
	g++ -o frac main.o frac.o

ball.o: ball.cpp ball.h
	g++ -c ball.cpp

brick.o: brick.cpp brick.h
	g++ -c brick.cpp

paddle.o: paddle.cpp paddle.h
	g++ -c paddle.cpp

wall.o: wall.cpp wall.h
	g++ -c wall.cpp

game.o: game.cpp
	g++ -c wall.cpp

clean:
	rm *.o frac