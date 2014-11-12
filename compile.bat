@echo off

echo gcc imgtogba.c lookup.c -L.\\lib -llibgd2 -lfreetype6 -ljpeg62 -llibpng13 -llibiconv2 -lxpm4 -lzlib1 -s -O3 -m32 -o imgtogba.exe
echo.
echo Compiling...

gcc imgtogba.c lookup.c -L.\\lib -llibgd2 -lfreetype6 -ljpeg62 -llibpng13 -llibiconv2 -lxpm4 -lzlib1 -s -O3 -m32 -o imgtogba.exe

if %errorlevel% equ 0 (
    echo Compile success!
    echo.
    echo Making prog dir...
    mkdir prog
    echo.
    echo Moving necessary files to prog directory...
    move imgtogba.exe prog
    copy lib\*.dll prog >nul
    echo.
    echo Job complete!
) else (
    echo Compile failed!
)
