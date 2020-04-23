#!/bin/bash

vertex_number=10
density=100

for ((i = 0; i < 100; i++ )) do
	./generator $i $density 10 > ./grafy_testowe/grafy$density/rozmiar_10/graf$i.txt 	
done	

for ((i = 0; i < 100; i++ )) do
	./generator $i $density 50 > ./grafy_testowe/grafy$density/rozmiar_50/graf$i.txt 	
done	

for ((i = 0; i < 100; i++ )) do
	./generator $i $density 100 > ./grafy_testowe/grafy$density/rozmiar_100/graf$i.txt 	
done	

for ((i = 0; i < 100; i++ )) do
	./generator $i $density 500 > ./grafy_testowe/grafy$density/rozmiar_500/graf$i.txt 	
done	

for ((i = 0; i < 100; i++ )) do
	./generator $i $density 1000 > ./grafy_testowe/grafy$density/rozmiar_1000/graf$i.txt 	
done	
