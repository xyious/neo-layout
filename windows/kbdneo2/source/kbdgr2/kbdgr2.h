/****************************** Module Header ******************************\
* Module Name: KBDGR2.H
* Header f�r das deutsche unergonomische Layout 2.0
\***************************************************************************/
// basiert auf den in der kbd.h definierten KBD-Type 4
#define KBD_TYPE 4

// kbd.h einschlie�en
#include "kbd.h"
#include <dontuse.h>

// Aktivieren f�r Vertauschung Strichtaste und �-Taste
// #define LOW_ESZETT


/* **************************************************************************************************************\
* 
*       +---+ +---------------+ +---------------+ +---------------+   +--------------+                       
*       |T01| |F1 �F2 �F3 �F4 | |F5 �F6 �F7 �F8 | |F9 �F10�F11�F12|   |Druk�Roll�Paus|                       
*       +---+ +---------------+ +---------------+ +---------------+   +--------------+                       
*       +---------------------------------------------------------+   +--------------+   +---------------+   
*       |T29�T02�T03�T04�T05�T06�T07�T08�T09�T0A�T0B�T0C�T0D� T0E |   |Einf�Pos1�PgUp|   �Num� / � * � - �   
*       |---------------------------------------------------------|   |--------------|   +---+---+---+---�   
*       |T0F�T10�T11�T12�T13�T14�T15�T16�T17�T18�T19�T1A�T1B� Ret |   |Entf�Ende�PgDn|   � 7 � 8 � 9 �   �   
*       |-----------------------------------------------------+   |   +--------------+   +---+---+---�   �   
*       | T3A �T1E�T1F�T20�T21�T22�T23�T24�T25�T26�T27�T28�T2B�   |                      � 4 � 5 � 6 � + �   
*       |---------------------------------------------------------|        +----+        +---+---+---+---�   
*       |T2A �T56�T2C�T2D�T2E�T2F�T30�T31�T32�T33�T34�T35� T36    |        | Up |        � 1 � 2 � 3 �   �   
*       |---------------------------------------------------------|   +----+----+----+   +-------+---�   �   
*       | Str � Fe � Al �     Leerzeichen    �X38 � Fe � Me � Str |   |Left�Down� Re.�   � 0     � , �Ent�   
*       +---------------------------------------------------------+   +--------------+   +---------------+   
* 
* 
*       +---+ +---------------+ +---------------+ +---------------+   +--------------+                       
*       |Esc| |F1 �F2 �F3 �F4 | |F5 �F6 �F7 �F8 | |F9 �F10�F11�F12|   |Druk�Roll�Paus|                       
*       +---+ +---------------+ +---------------+ +---------------+   +--------------+                       
*       +---------------------------------------------------------+   +--------------+   +---------------+   
*       |T1 �1  �2  �3  �4  �5  �6  �7  �8  �9  �0  �-  �T2 �Back |   |Einf�Pos1�PgUp|   �Num� / � * � - �   
*       |---------------------------------------------------------|   |--------------|   +---+---+---+---�   
*       |Tab�x  �v  �l  �c  �w  �k  �h  �g  �f  �q  ��  �T3 � Ret |   |Entf�Ende�PgDn|   � 7 � 8 � 9 �   �   
*       |-----------------------------------------------------+   |   +--------------+   +---+---+---�   �   
*       | M3  �u  �i  �a  �e  �o  �s  �n  �r  �t  �d  �y  �M3 �   |                      � 4 � 5 � 6 � + �   
*       |---------------------------------------------------------|        +----+        +---+---+---+---�   
*       |Ums �M4 ��  ��  ��  �p  �z  �b  �m  �,  �.  �j  � Umsch  |        | Up |        � 1 � 2 � 3 �   �   
*       |---------------------------------------------------------|   +----+----+----+   +-------+---�   �   
*       | Str � Fe � Al �     Leerzeichen    � M4 � Fe � Me � Str |   |Left�Down� Re.�   � 0     � , �Ent�   
*       +---------------------------------------------------------+   +--------------+   +---------------+  
* 
\************************************************************************************************************** */

//qwertz
#undef  T15
#define T15 _EQ(                                        'Z'                      )
#undef  T2C
#define T2C _EQ(                                        'Y'                      )

//OEM-Tasten:
#undef  T29//T1
#define T29 _EQ(                                       OEM_1                      )
#undef  T0D//T2
#define T0D _EQ(                                       OEM_2                      )
#undef  T1B//T3
#define T1B _EQ(                                       OEM_4                      )

#ifdef LOW_ESZETT
// T0C ist bereits als OEM_MINUS in kbd.h definiert
#undef  T35//qwertz-_
#define T35 _EQ(                                       OEM_3                      )
#else
#undef  T0C//qwertz-�
#define T0C _EQ(                                       OEM_3                      )
#undef  T35//qwertz-_
#define T35 _EQ(                                       OEM_MINUS                  )
#endif

#undef  T1A//qwertz-�
#define T1A _EQ(                                       OEM_5                      )
#undef  T27//qwertz-�
#define T27 _EQ(                                       OEM_6                      )
#undef  T28//qwertz-�
#define T28 _EQ(                                       OEM_7                      )
// Tastenumbelegung f�r Neo 2.0 ; sonstige Tastenzuordnung siehe kbd.h
#undef  T2B
#define T2B _EQ(		 OEM_102	)	// Mod 3
#undef  T3A
#define T3A _EQ(		 OEM_102	)	// Mod 3
#undef  X38
#define X38 _EQ(		 OEM_8		)	// Mod 4
#undef  T56
#define T56 _EQ(		 OEM_8		)	// Mod 4