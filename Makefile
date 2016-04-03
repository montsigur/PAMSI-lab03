all: pomiar hanoi

pomiar: main.cpp timer/src/Timer.cpp kolejka_lab02.cpp
	g++ -Wall -std=c++11 -o pomiar main.cpp timer/src/Timer.cpp kolejka_lab02.cpp

hanoi: hanoi.cpp lista.cpp
	g++ -Wall -std=c++11 -o hanoi hanoi.cpp lista.cpp

clean:
	rm -f pomiar hanoi
