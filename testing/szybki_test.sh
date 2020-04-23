#!/bin/bash

gestosc=25
implementacja=lista

for ((i = 0; i < 1; i++ )) do

        ./dijkstra $i $gestosc 10  > plik.txt
done

