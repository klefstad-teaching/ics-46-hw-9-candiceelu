CXX := g++
CXXFLAGS := -std=c++20 -Wall -Wextra -Werror

ladder: src/ladder_main.cpp lib/ladder.o
	$(CXX) $(CXXFLAGS) src/ladder_main.cpp lib/ladder.o -o ladder

dijkstra: src/dijkstras_main.cpp lib/dijkstras.o
	$(CXX) $(CXXFLAGS) src/dijkstras_main.cpp lib/dijkstras.o -o dijkstra

lib/dijkstras.o: src/dijkstras.cpp src/dijkstras.h
	$(CXX) $(CXXFLAGS) -c src/dijkstras.cpp -o lib/dijkstras.o

lib/ladder.o: src/ladder.cpp src/ladder.h
	$(CXX) $(CXXFLAGS) -c src/ladder.cpp -o lib/ladder.o

clean:
	rm -rf src/*.o dijkstra