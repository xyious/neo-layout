@echo off

IF [%~1]==[] (
    echo Bitte das entsprechende Layout angeben, so benannt wie das Quellverzeichnis ^(ohne "kbd"^).
    exit /b
)

IF NOT EXIST ..\source\kbd%1 (
    echo Das Layoutverzeichnis kbd%1 existiert nicht.
    exit /b
)

REM Falls notwendig, vollständigen Pfad zur (7z) Executable angeben
SET zipcmd=7z
REM Switches: Ziparchiv, normale Kompression, rekursiv
SET zipswitches=a -tzip -mx5 -r

SET layout=kbd%1
IF NOT [%~2]==[] SET layout=kbd%2

pushd ..\source\kbd%1

IF EXIST %layout%64 rmdir /S /Q %layout%64
IF EXIST %layout%32 rmdir /S /Q %layout%32

echo Kopiere Dateien ...

mkdir %layout%64\System32
mkdir %layout%64\SysWOW64
copy       x64\kbd%1.dll %layout%64\System32\          >NUL
copy x86-wow64\kbd%1.dll %layout%64\SysWOW64\          >NUL
copy ..\..\build\%layout%_win10_install.reg %layout%64\   >NUL
copy ..\..\build\%layout%_win10_uninstall.reg %layout%64\ >NUL

mkdir %layout%32\System32
copy  x86\kbd%1.dll %layout%32\System32\               >NUL
copy ..\..\build\%layout%_win10_install.reg %layout%32\   >NUL
copy ..\..\build\%layout%_win10_uninstall.reg %layout%32\ >NUL

echo Erstelle Zip-Archive ...

%zipcmd% %zipswitches% %layout%64.zip %layout%64\ >NUL
IF %errorlevel% EQU 0 rmdir /S /Q %layout%64
%zipcmd% %zipswitches% %layout%32.zip %layout%32\ >NUL
IF %errorlevel% EQU 0 rmdir /S /Q %layout%32

popd
