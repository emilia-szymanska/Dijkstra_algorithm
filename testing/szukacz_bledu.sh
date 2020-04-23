#!/bin/bash
for ((i = 0; i < 2000; i++ )) do
	./generator $i 100 100 > plik.txt 
        ./dijkstra < plik.txt
	
	if (($? == 0)); 
	then
		echo " OK : $i "
	else
		echo " ZLE : $i "
		break
	fi	
		
done	
