@echo off

set buildtools=2022

echo Baue alle Layouts (Neo, NeoQwertz, Bone, Mine, Koy, Noted) ...
echo.

pushd ..\source

REM Zuerst die x64-Varianten bauen

pushd "C:\Program Files (x86)\Microsoft Visual Studio\%buildtools%\BuildTools\"
call "C:\Program Files (x86)\Microsoft Visual Studio\%buildtools%\BuildTools\VC\Auxiliary\Build\vcvarsx86_amd64.bat"
popd

cd kbdbone
IF NOT EXIST x64 mkdir x64
call ..\..\build\build_variant_x64.cmd bone
cd ..

cd kbdneo2
IF NOT EXIST x64 mkdir x64
call ..\..\build\build_variant_x64.cmd neo2
cd ..

cd kbdgr2
IF NOT EXIST x64 mkdir x64
call ..\..\build\build_variant_x64.cmd gr2
cd ..

cd kbdmine
IF NOT EXIST x64 mkdir x64
call ..\..\build\build_variant_x64.cmd mine
cd ..

cd kbdkoy
IF NOT EXIST x64 mkdir x64
call ..\..\build\build_variant_x64.cmd koy
cd ..

cd kbdnoted
IF NOT EXIST x64 mkdir x64
call ..\..\build\build_variant_x64.cmd noted
cd ..


REM x86 und x86_wow64 bauen

pushd "C:\Program Files (x86)\Microsoft Visual Studio\%buildtools%\BuildTools\"
call "C:\Program Files (x86)\Microsoft Visual Studio\%buildtools%\BuildTools\VC\Auxiliary\Build\vcvars32.bat"
popd

cd kbdbone
IF NOT EXIST x86 mkdir x86
IF NOT EXIST x86-wow64 mkdir x86-wow64
call ..\..\build\build_variant_x86.cmd bone
call ..\..\build\build_variant_x86_wow64.cmd bone
cd ..

cd kbdneo2
IF NOT EXIST x86 mkdir x86
IF NOT EXIST x86-wow64 mkdir x86-wow64
call ..\..\build\build_variant_x86.cmd neo2
call ..\..\build\build_variant_x86_wow64.cmd neo2
cd ..

cd kbdgr2
IF NOT EXIST x86 mkdir x86
IF NOT EXIST x86-wow64 mkdir x86-wow64
call ..\..\build\build_variant_x86.cmd gr2
call ..\..\build\build_variant_x86_wow64.cmd gr2
cd ..

cd kbdmine
IF NOT EXIST x86 mkdir x86
IF NOT EXIST x86-wow64 mkdir x86-wow64
call ..\..\build\build_variant_x86.cmd mine
call ..\..\build\build_variant_x86_wow64.cmd mine
cd ..

cd kbdkoy
IF NOT EXIST x86 mkdir x86
IF NOT EXIST x86-wow64 mkdir x86-wow64
call ..\..\build\build_variant_x86.cmd koy
call ..\..\build\build_variant_x86_wow64.cmd koy
cd ..

cd kbdnoted
IF NOT EXIST x86 mkdir x86
IF NOT EXIST x86-wow64 mkdir x86-wow64
call ..\..\build\build_variant_x86.cmd noted
call ..\..\build\build_variant_x86_wow64.cmd noted
cd ..

popd
