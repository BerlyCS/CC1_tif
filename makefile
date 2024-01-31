test:
	g++ -c main.cpp -I/usr/include/ -o obj.o
	g++ obj.o -o test.exe -lsfml-graphics -lsfml-window -lsfml-system
