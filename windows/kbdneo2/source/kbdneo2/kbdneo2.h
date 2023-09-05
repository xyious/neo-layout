/****************************** Module Header ******************************\
* Module Name: KBDNEO2.H
* Header für das deutsche ergonomische Layout Neo 2.0
\***************************************************************************/
// basiert auf den in der kbd.h definierten KBD-Type 4
#define KBD_TYPE 4

// kbd.h einschließen
#include "kbd.h"
#include <dontuse.h>


/* **************************************************************************************************************\
* 
*       +---+ +---------------+ +---------------+ +---------------+   +--------------+                       
*       |T01| |F1 ¦F2 ¦F3 ¦F4 | |F5 ¦F6 ¦F7 ¦F8 | |F9 ¦F10¦F11¦F12|   |Druk¦Roll¦Paus|                       
*       +---+ +---------------+ +---------------+ +---------------+   +--------------+                       
*       +---------------------------------------------------------+   +--------------+   +---------------+   
*       |T29¦T02¦T03¦T04¦T05¦T06¦T07¦T08¦T09¦T0A¦T0B¦T0C¦T0D¦ T0E |   |Einf¦Pos1¦PgUp|   ¦Num¦ / ¦ * ¦ - ¦   
*       |---------------------------------------------------------|   |--------------|   +---+---+---+---¦   
*       |T0F¦T10¦T11¦T12¦T13¦T14¦T15¦T16¦T17¦T18¦T19¦T1A¦T1B¦ Ret |   |Entf¦Ende¦PgDn|   ¦ 7 ¦ 8 ¦ 9 ¦   ¦   
*       |-----------------------------------------------------+   |   +--------------+   +---+---+---¦   ¦   
*       | T3A ¦T1E¦T1F¦T20¦T21¦T22¦T23¦T24¦T25¦T26¦T27¦T28¦T2B¦   |                      ¦ 4 ¦ 5 ¦ 6 ¦ + ¦   
*       |---------------------------------------------------------|        +----+        +---+---+---+---¦   
*       |T2A ¦T56¦T2C¦T2D¦T2E¦T2F¦T30¦T31¦T32¦T33¦T34¦T35¦ T36    |        | Up |        ¦ 1 ¦ 2 ¦ 3 ¦   ¦   
*       |---------------------------------------------------------|   +----+----+----+   +-------+---¦   ¦   
*       | Str ¦ Fe ¦ Al ¦     Leerzeichen    ¦X38 ¦ Fe ¦ Me ¦ Str |   |Left¦Down¦ Re.¦   ¦ 0     ¦ , ¦Ent¦   
*       +---------------------------------------------------------+   +--------------+   +---------------+   
* 
* 
*       +---+ +---------------+ +---------------+ +---------------+   +--------------+                       
*       |Esc| |F1 ¦F2 ¦F3 ¦F4 | |F5 ¦F6 ¦F7 ¦F8 | |F9 ¦F10¦F11¦F12|   |Druk¦Roll¦Paus|                       
*       +---+ +---------------+ +---------------+ +---------------+   +--------------+                       
*       +---------------------------------------------------------+   +--------------+   +---------------+   
*       |T1 ¦1  ¦2  ¦3  ¦4  ¦5  ¦6  ¦7  ¦8  ¦9  ¦0  ¦-  ¦T2 ¦Back |   |Einf¦Pos1¦PgUp|   ¦Num¦ / ¦ * ¦ - ¦   
*       |---------------------------------------------------------|   |--------------|   +---+---+---+---¦   
*       |Tab¦x  ¦v  ¦l  ¦c  ¦w  ¦k  ¦h  ¦g  ¦f  ¦q  ¦ß  ¦T3 ¦ Ret |   |Entf¦Ende¦PgDn|   ¦ 7 ¦ 8 ¦ 9 ¦   ¦   
*       |-----------------------------------------------------+   |   +--------------+   +---+---+---¦   ¦   
*       | M3  ¦u  ¦i  ¦a  ¦e  ¦o  ¦s  ¦n  ¦r  ¦t  ¦d  ¦y  ¦M3 ¦   |                      ¦ 4 ¦ 5 ¦ 6 ¦ + ¦   
*       |---------------------------------------------------------|        +----+        +---+---+---+---¦   
*       |Ums ¦M4 ¦ü  ¦ö  ¦ä  ¦p  ¦z  ¦b  ¦m  ¦,  ¦.  ¦j  ¦ Umsch  |        | Up |        ¦ 1 ¦ 2 ¦ 3 ¦   ¦   
*       |---------------------------------------------------------|   +----+----+----+   +-------+---¦   ¦   
*       | Str ¦ Fe ¦ Al ¦     Leerzeichen    ¦ M4 ¦ Fe ¦ Me ¦ Str |   |Left¦Down¦ Re.¦   ¦ 0     ¦ , ¦Ent¦   
*       +---------------------------------------------------------+   +--------------+   +---------------+  
* 
\************************************************************************************************************** */

// Tastenumbelegung für Neo 2.0 ; sonstige Tastenzuordnung siehe kbd.h
#undef  T0D
#define T0D _EQ(		 OEM_2		)
#undef  T10
#define T10 _EQ(		 'X'		)
#undef  T11
#define T11 _EQ(		 'V'		)
#undef  T12
#define T12 _EQ(		 'L'		)
#undef  T13
#define T13 _EQ(		 'C'		)
#undef  T14
#define T14 _EQ(		 'W'		)
#undef  T15
#define T15 _EQ(		 'K'		)
#undef  T16
#define T16 _EQ(		 'H'		)
#undef  T17
#define T17 _EQ(		 'G'		)
#undef  T18
#define T18 _EQ(		 'F'		)
#undef  T19
#define T19 _EQ(		 'Q'		)
#undef  T1A
#define T1A _EQ(		 OEM_3		)
#undef  T1B
#define T1B _EQ(		 OEM_4		)
#undef  T1E
#define T1E _EQ(		 'U'		)
#undef  T1F
#define T1F _EQ(		 'I'		)
#undef  T20
#define T20 _EQ(		 'A'		)
#undef  T21
#define T21 _EQ(		 'E'		)
#undef  T22
#define T22 _EQ(		 'O'		)
#undef  T23
#define T23 _EQ(		 'S'		)
#undef  T24
#define T24 _EQ(		 'N'		)
#undef  T25
#define T25 _EQ(		 'R'		)
#undef  T26
#define T26 _EQ(		 'T'		)
#undef  T27
#define T27 _EQ(		 'D'		)
#undef  T28
#define T28 _EQ(		 'Y'		)
#undef  T29
#define T29 _EQ(		 OEM_1		)
#undef  T2B
#define T2B _EQ(		 OEM_102	)	// Mod 3
#undef  T2C
#define T2C _EQ(		 OEM_5		)
#undef  T2D
#define T2D _EQ(		 OEM_6		)
#undef  T2E
#define T2E _EQ(		 OEM_7		)
#undef  T2F
#define T2F _EQ(		 'P'		)
#undef  T30
#define T30 _EQ(		 'Z'		)
#undef  T31
#define T31 _EQ(		 'B'		)
#undef  T35
#define T35 _EQ(		 'J'		)
#undef  T3A
#define T3A _EQ(		 OEM_102	)	// Mod 3
#undef  X38
#define X38 _EQ(		 OEM_8		)	// Mod 4
#undef  T56
#define T56 _EQ(		 OEM_8		)	// Mod 4
