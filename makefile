test:
	g++ -c main.cpp -I/usr/include/ -o obj.o
	g++ obj.o -o test.exe -lsfml-graphics -lsfml-window -lsfml-system

windows:
	g++ -c main.cpp -I D:\Downloads\SFML-2.5.1-windows-gcc-7.3.0-mingw-64-bit\SFML-2.5.1\include -o obj.o
	g++ -I D:\Downloads\SFML-2.5.1-windows-gcc-7.3.0-mingw-64-bit\SFML-2.5.1\include obj.o -o test.exe -L D:\Downloads\SFML-2.5.1-windows-gcc-7.3.0-mingw-64-bit\SFML-2.5.1\lib -lsfml-graphics -lsfml-window -lsfml-system