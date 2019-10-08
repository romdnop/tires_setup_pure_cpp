"C:\MinGW\bin\windres.exe" my.rc my.o
"C:\MinGW\bin\g++.exe" -m32 -static -lgcc -s -g3 -c main.cpp
"C:\MinGW\bin\g++.exe" -m32 -static -lgcc -s -g3 -o TiresCalibrate main.o my.o