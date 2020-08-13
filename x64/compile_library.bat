call setup_vars.bat
pause
del libmygmp.dll mygmp.o
pause
gcc -c -Wall -Werror ..\mygmp.c -lmpfr -lgmp
pause
gcc -shared -o libmygmp.dll mygmp.o -lmpfr -lgmp
pause
g++ -L. -Wall -o a.exe ..\main.cpp -lmygmp
pause
a.exe
pause