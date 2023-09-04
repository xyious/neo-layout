# Build-Anleitung für kbdneo / kbdbone / kbdqwertz

Für die weitergehende Entwicklung und Kompilierung der Treiberlayout-DLLs unter Windows 10 wurde eine Solution in Visual Studio 2019 erstellt, die die verschiedenen Varianten (Neo, Bone, Qwertz) zusammenfasst. Die Treiber-DLLs können somit auf zwei Arten gebaut werden:
1. Über Visual Studio
2. Über ein manuelles Buildskript

Die erste Variante ist der kanonische Weg. Die zweite Variante benötigt kein Visual Studio und insbesondere kein umfangreiches Windows Driver Kit. Sie kann für eigene Anpassungen an den Layoutdateien verwendet werden.


## Regulärer Build mit Visual Studio


### Voraussetzungen

Zum Bauen notwendig sind folgende Programme:
* Visual Studio (2017 oder neuer)
  * Desktop-Entwicklung mit C++ installiert
* Windows 10 SDK (10.0.18362 oder neuer)
* Windows Driver Kit (Version 2004 oder neuer)
  * siehe Anleitung: https://docs.microsoft.com/en-us/windows-hardware/drivers/download-the-wdk

### Build

1. `kbd.sln` aus `source` in Visual Studio öffnen
1. Release-Build einstellen und Konfiguration x64 auswählen
1. Build solution
1. Konfiguration x86 auswählen
1. Build solution

Für jedes der enthaltenen Tastaturlayouts sind nun je zwei .dll-Dateien (Name = Projektname) gebaut worden. Diese müssen mit einem 64-Bit-fähigen Dateimanager (z.B. Windows Explorer) in die entsprechenden Verzeichnisse kopiert werden:
* x64\release\kbd*.dll → C:\Windows\System32
* release\kbd*.dll → C:\Windows\SysWOW64


## Manueller Build

### Voraussetzungen

* Visual Studio Build Tools: Auf https://visualstudio.microsoft.com/de/downloads/ nach unten scrollen, unter „Alle Downloads“ den Reiter „Tools für Visual Studio“ aufklappen und „Buildtools für Visual Studio 2022“ auswählen.
* Im Installer unter „Workloads“ die C++-Buildtools auswählen – oder alternativ unter „Einzelne Komponenten“ die aktuellen x64/x86-Buildtools sowie das aktuelle Windows 10 SDK auswählen.

Ältere, bereits installierte Buildtools funktionieren gleichermaßen. Dazu muss man vor dem Build einmalig die Variable `buildtools` in den Skripten umstellen auf die entsprechende Version (Jahreszahl).

### Build

Nach der Installation können einzelne oder alle Layouts über die im `build`-Verzeichnis verfügbaren Skripte gebaut werden.

* ins `build`-Verzeichnis unterhalb von `windows\kbdneo2` wechseln
* `build_all` ausführen, oder alternativ `build_layout [Layoutname]`, wobei hier der Layoutname ohne "kbd" angegeben wird (z.B. neo2 oder bone), wie er im `source`-Verzeichnis verwendet wird.

Die erzeugten DLLs sind anschließend in den Unterverzeichnissen `x64`, `x86` und `x86-wow64` der jeweiligen Layoutvarianten zu finden.


## kbdqwertz mit „ß“ unten

Von kbdqwertz (aus historischen Gründen im Verzeichnis `kbdgr2` platziert) gibt es zwei Varianten, einmal mit dem regulären QWERTZ-Layout mit ß oben und dem Bindestrich unten. Die zweite Variante tauscht beides, sodass der Bindestrich gemeinsam mit anderen Strichen auf weiteren Ebenen auf der Strichtaste landet. Das „ß“ verschiebt sich dafür ins Hauptfeld.

Um kbdqwertz mit „ß“ unten zu kompilieren, muss in `kbdgr2.h` folgende Zeile einkommentiert werden:
```
// #define LOW_ESZETT
```
Anschließend kann nach obiger Anleitung weiter verfahren werden.
