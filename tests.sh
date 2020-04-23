#!/bin/bash

gestosc=100
implementacja=macierz

for ((i = 0; i < 100; i++ )) do

        ./dijkstra $i $gestosc 10  >> wyniki/$implementacja/grafy$gestosc/graf_10.txt
done
	

for ((i = 0; i < 100; i++ )) do

        ./dijkstra $i $gestosc 50 >> wyniki/$implementacja/grafy$gestosc/graf_50.txt
done	


for ((i = 0; i < 100; i++ )) do

        ./dijkstra $i $gestosc 100 >> wyniki/$implementacja/grafy$gestosc/graf_100.txt
done	


for ((i = 0; i < 100; i++ )) do

        ./dijkstra $i $gestosc 500 >> wyniki/$implementacja/grafy$gestosc/graf_500.txt
done	


for ((i = 0; i < 100; i++ )) do

        ./dijkstra $i $gestosc 1000 >> wyniki/$implementacja/grafy$gestosc/graf_1000.txt
done	
