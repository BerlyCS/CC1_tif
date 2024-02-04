test:
	g++ -c main.cpp -I/usr/include/ -o obj.o
	g++ obj.o -o test.exe -lsfml-graphics -lsfml-window -lsfml-system

windows:
	g++ -c main.cpp -I D:\Libs\SFML-2.5.1\include -o obj.o
	g++ -I D:\libs\SFML-2.5.1\lib -lsfml-graphics -lsfml-window -lsfml-system

better_windows:
	g++ main.cpp -I D:\Libs\SFML-2.5.1\include -o main.exe -L D:\libs\SFML-2.5.1\lib -lsfml-graphics -lsfml-window -lsfml-system
