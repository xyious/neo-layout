@echo off

if "%1"=="" (
    echo Bitte das entsprechende Layout angeben, so benannt wie das Quellverzeichnis ^(ohne "kbd"^).
    exit /b
)

IF NOT EXIST ..\source\kbd%1 (
    echo Das Layoutverzeichnis kbd%1 existiert nicht.
    exit /b
)

set buildtools=2022

pushd ..\source\kbd%1

IF NOT EXIST x64 mkdir x64
IF NOT EXIST x86 mkdir x86
IF NOT EXIST x86-wow64 mkdir x86-wow64

pushd "C:\Program Files (x86)\Microsoft Visual Studio\%buildtools%\BuildTools\"
call "C:\Program Files (x86)\Microsoft Visual Studio\%buildtools%\BuildTools\VC\Auxiliary\Build\vcvarsx86_amd64.bat"
popd
call ..\..\build\build_variant_x64.cmd %1

pushd "C:\Program Files (x86)\Microsoft Visual Studio\%buildtools%\BuildTools\"
call "C:\Program Files (x86)\Microsoft Visual Studio\%buildtools%\BuildTools\VC\Auxiliary\Build\vcvars32.bat"
popd
call ..\..\build\build_variant_x86.cmd %1
call ..\..\build\build_variant_x86_wow64.cmd %1

popd
