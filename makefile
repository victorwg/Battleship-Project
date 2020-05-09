flag = -pedantic-errors -std=c++11

placeShip.o: placeShip.cpp placeShip.h
	g++ $(flag) -c $<

printBoard.o: printBoard.cpp printBoard.h
	g++ $(flag) -c $<

checkShip.o: checkShip.cpp checkShip.h
	g++ $(flag) -c $<

save_gameStatus.o: save_gameStatus.cpp save_gameStatus.h
	g++ $(flag) -c $<

load_gameStatus.o: load_gameStatus.cpp printBoard.h load_gameStatus.h
	g++ $(flag) -c $<

input.o: input.cpp save_gameStatus.h input.h
	g++ $(flag) -c $<

play.o: play.cpp input.h printBoard.h checkShip.h play.h
	g++ $(flag) -c $<

game.o: game.cpp placeShip.h printBoard.h load_gameStatus.h play.h
	g++ $(flag) -c $<

game: placeShip.o printBoard.o checkShip.o save_gameStatus.o load_gameStatus.o input.o play.o game.o
	g++ $(flag) $^ -o $@

clean:
	rm -f game *.o

.PHONY: clean
