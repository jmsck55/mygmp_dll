call setup_vars.bat
pause
gcc -o version.exe ..\version.c -lmpfr -lgmp
pause
version.exe