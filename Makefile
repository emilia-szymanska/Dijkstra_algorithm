lista: src/main.cpp
	g++ -g -Wall src/main.cpp -o lista

#Dijkstra: obj/list.o obj/main.o
#	g++ -Wall -pedantic -o Dijkstra obj/list.o obj/main.o

#obj/Dijkstra.o: obj/list.o 
#	g++ -c -o obj/Dijkstra.o obj/list.o

#obj/main.o: main.cpp
#	g++ -c -o obj/main.o src/main.cpp

#obj/list.o: src/list.cpp inc/list.hh
#	g++ -c -o obj/list.o inc/list.hh



