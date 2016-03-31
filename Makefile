all: pomiar hanoi

pomiar: main.cpp timer/src/Timer.cpp kolejka_lab02.cpp
	g++ -Wall -o pomiar main.cpp timer/src/Timer.cpp kolejka_lab02.cpp

hanoi: hanoi.cpp lista.cpp
	g++ -Wall -o hanoi hanoi.cpp lista.cpp
