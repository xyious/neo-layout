/****************************************************************************\
* Module Name: KBDBONE.C
* Bone-Layout, basierend auf Neo2
\****************************************************************************/

#include <windows.h>
#include "kbd.h"
#include "../kbd_mod.h"
#include "../keysym4utf16.h"
#include "kbdbone.h"
#include "../kbd_base.c"


/* **************************************************************************\
* Spezielle Werte f�r den VK (Spalte 1)
*     0xff          - Tote Zeichen f�r obige Zeile
*     0             - Beendet die gesamte Liste
*
* Spezielle Werte f�r Attributes (Spalte 2)
*     CAPLOK    - CAPS-LOCK wirkt auf diese Taste wie SHIFT
*     KANALOK   - Mod4-LOCK wirkt auf diese Taste wie Mod4
*
* Spezielle Werte f�r wch[*]
*     WCH_NONE      - Keine Belegung
*     WCH_DEAD      - Totes Zeichen
*     WCH_LGTR      - Ligatur
\************************************************************************** */

static ALLOC_SECTION_LDATA VK_TO_WCHARS6 aVkToWch6[] = {
// Reihenfolge der Ebene wie oben ( ALLOC_SECTION_LDATA MODIFIERS CharModifiers = {    &aVkToBits[0],)� festgelegt
//				| CapsLock			|			| SHIFT					| NEU					| KANA			| NEU+Shift			| KANA+NEU			|
//				|===================|===========|=======================|=======================|===============|===================|===================|
// Zeile 1
{VK_OEM_1		,0					,WCH_DEAD	,WCH_DEAD				,WCH_DEAD				,WCH_DEAD		,WCH_DEAD			,WCH_DEAD			},	//Tote Taste 1
{0xff			,0					,'^'		,caron					,totdreh				,abovedot		,rhotichook			,'.'				}, 
{'1'			,KANALOK			,'1'		,degree					,onesuperior			,ordfeminine	,onesubscript		,notsign			},
{'3'			,KANALOK			,'3'		,litersign				,threesuperior			,numerosign		,threesubscript		,logicaland			},
{'4'			,KANALOK			,'4'		,guillemotright			,guillemotright2		,WCH_NONE		,femalesymbol		,uptack				},	
{'5'			,KANALOK			,'5'		,guillemotleft			,guillemotleft2			,periodcentered	,malesymbol			,measuredangle		},
{'7'			,KANALOK			,'7'		,EuroSign				,yen					,currency		,scriptkappa		,rightarrow			},
{'8'			,KANALOK			,'8'		,doublelowquotemark		,singlelowquotemark		,WCH_NONE		,leftanglebracket	,infinity			},
{'9'			,KANALOK			,'9'		,leftdoublequotemark	,leftsinglequotemark	,'/'			,rightanglebracket	,variation			},
{'0'			,KANALOK			,'0'		,rightdoublequotemark	,rightsinglequotemark	,'*'			,zerosubscript		,emptyset			},
{VK_OEM_MINUS	,KANALOK			,'-'		,emdash					,WCH_NONE				,'-'			,nobreakhyphen		,hyphen				},
{VK_OEM_2		,0					,WCH_DEAD	,WCH_DEAD				,WCH_DEAD				,WCH_DEAD		,WCH_DEAD			,WCH_DEAD			},	//Tote Taste 2
{0xff			,0					,grave		,cedilla				,ringabove				,diaeresis		,greek_dasia		,macron				},
{VK_TAB			,0					,'\t'		,'\t'					,WCH_DEAD				,'\t'			,'\t'				,'\t'				},
{0xff			,0					,WCH_NONE	,WCH_NONE				,Multi_key				,WCH_NONE		,WCH_NONE			,WCH_NONE			},
{'D'			,CAPLOK | KANALOK	,'d'		,'D'					,'_'					,WCH_NONE		,Greek_delta		,Greek_DELTA		},
{'U'			,CAPLOK | KANALOK	,'u'		,'U'					,'['					,WCH_NONE		,WCH_NONE			,includedin			},
{'A'			,CAPLOK | KANALOK	,'a'		,'A'					,']'					,WCH_NONE		,Greek_alpha		,forall				},
{'X'			,CAPLOK | KANALOK	,'x'		,'X'					,asciicircum			,WCH_NONE		,Greek_xi			,Greek_XI			},
{'P'			,CAPLOK | KANALOK	,'p'		,'P'					,'!'					,exclamdown		,Greek_pi			,Greek_PI			},
{'H'			,CAPLOK | KANALOK	,'h'		,'H'					,'<'					,'7'			,Greek_psi			,Greek_PSI			},
{'L'			,CAPLOK | KANALOK	,'l'		,'L'					,'>'					,'8'			,Greek_lamda		,Greek_LAMDA		},
{'M'			,CAPLOK | KANALOK	,'m'		,'M'					,'='					,'9'			,Greek_mu			,ifonlyif			},
{'W'			,CAPLOK | KANALOK	,'w'		,'W'					,'&'					,'+'			,Greek_omega		,Greek_OMEGA		},
{'C'			,CAPLOK | KANALOK	,'c'		,'C'					,backslash				,WCH_NONE		,Greek_chi			,doublestruck_c		},
{'T'			,CAPLOK | KANALOK	,'t'		,'T'					,'/'					,WCH_NONE		,Greek_tau			,partialderivative	},
{'I'			,CAPLOK | KANALOK	,'i'		,'I'					,'{'					,WCH_NONE		,Greek_iota			,integral			},
{'E'			,CAPLOK | KANALOK	,'e'		,'E'					,'}'					,WCH_NONE		,Greek_epsilon		,thereexists		},
{'O'			,CAPLOK | KANALOK	,'o'		,'O'					,'*'					,WCH_NONE		,Greek_omicron		,elementof			},
{'B'			,CAPLOK | KANALOK	,'b'		,'B'					,'?'					,questiondown	,Greek_beta			,doublearrowleft	},
{'N'			,CAPLOK | KANALOK	,'n'		,'N'					,'('					,'4'			,Greek_nu			,doublestruck_n		},
{'R'			,CAPLOK | KANALOK	,'r'		,'R'					,')'					,'5'			,Greek_rho			,doublestruck_r		},
{'S'			,CAPLOK | KANALOK	,'s'		,'S'					,'-'					,'6'			,Greek_sigma		,Greek_SIGMA		},
{'G'			,CAPLOK | KANALOK	,'g'		,'G'					,':'					,','			,Greek_gamma		,Greek_GAMMA		},
{'Q'			,CAPLOK | KANALOK	,'q'		,'Q'					,'@'					,'.'			,scriptphi			,doublestruck_q		},
{'F'			,CAPLOK | KANALOK	,'f'		,'F'					,'#'					,WCH_NONE		,Greek_phi			,Greek_PHI			},
{'V'			,CAPLOK | KANALOK	,'v'		,'V'					,'$'					,WCH_NONE		,WCH_NONE			,radical			},
{VK_OEM_5 /*�*/	,CAPLOK | KANALOK	,udiaeresis	,Udiaeresis				,'|'					,WCH_NONE		,WCH_NONE			,union				},
{VK_OEM_7 /*�*/	,CAPLOK | KANALOK	,adiaeresis	,Adiaeresis				,'~'					,WCH_NONE		,Greek_eta			,alefsymbol			},
{VK_OEM_6 /*�*/	,CAPLOK | KANALOK	,odiaeresis	,Odiaeresis				,'`'					,WCH_NONE		,straightepsilon	,intersection		},
{'Z'			,CAPLOK | KANALOK	,'z'		,'Z'					,'%'					,'1'			,Greek_zeta			,doublestruck_z		},
{VK_OEM_COMMA	,KANALOK			,','		,endash					,quotedbl				,'2'			,scriptrho			,implies			},
{VK_OEM_PERIOD	,KANALOK			,'.'		,enfilledcircbullet		,apostrophe				,'3'			,scripttheta		,arrowfrombarright	},
{'K'			,CAPLOK | KANALOK	,'k'		,'K'					,';'					,';'			,Greek_kappa		,multiply			},
{0				,0					,0			,0						,0						,0				,0					,0					}
};	

static ALLOC_SECTION_LDATA VK_TO_WCHARS7 aVkToWch7[] = {
//				| CapsLock			|			| SHIFT		| NEU		| KANA		|	 NEU+Shift			| KANA+NEU		| Control		|
//				|===================|===========|===========|===========|===========|=======================|===============|===============|
{VK_OEM_3 /*�*/ ,CAPLOK | KANALOK	,ssharp		,Ssharp		,slong		,minussign	,Greek_finalsmallsigma	,jot			,escape			},
{VK_OEM_4		,0					,WCH_DEAD	,WCH_DEAD	,WCH_DEAD	,WCH_DEAD	,WCH_DEAD				,WCH_DEAD		,infoseparator3	},	//Tote Taste 3
{0xff			,0					,acute		,'~'		,'-'		,doubleacute,greek_psili			,breve			,WCH_NONE		},
{'Y'			,CAPLOK | KANALOK	,'y'		,'Y'		,'+'		,':'		,Greek_upsilon			,nabla			,infoseparator4	},
{VK_SPACE		,KANALOK			,space		,space		,space		,'0'		,nobreakspace			,nnobreakspace	,space			},
{VK_BACK		,0					,'\b'		,'\b'		,'\b'		,'\b'		,'\b'					,'\b'			,delete			},
{VK_ESCAPE		,0					,escape		,escape		,escape		,escape		,escape					,escape			,escape			},
{VK_RETURN		,0					,'\r'		,'\r'		,'\r'		,'\r'		,'\r'					,'\r'			,'\n'			},
{VK_CANCEL		,0					,endoftext	,endoftext	,WCH_NONE	,WCH_NONE	,WCH_NONE				,WCH_NONE		,endoftext		},
{0				,0					,0			,0			,0			,0			,0						,0				,0				}
};

static ALLOC_SECTION_LDATA VK_TO_WCHARS8 aVkToWch8[] = {
//				| CapsLock			|			| SHIFT		| NEU		| KANA		| NEU+Shift			| KANA+NEU		| Control	| Control+Shift	|
//				|===================|===========|===========|===========|===========|===================|===============|===========|===============|
{'2'			,KANALOK			,'2'		,section	,twosuperior,masculine	,twosubscript		,logicalor	,WCH_NONE	,0x0000			},
{'6'			,KANALOK			,'6'		,dollar		,cent		,sterling	,maleandfemalesign	,parallelto	,WCH_NONE	,infoseparator2	},
{'J'			,CAPLOK | KANALOK	,'j'		,'J'		,ellipsis	,WCH_NONE	,Greek_theta		,Greek_THETA,WCH_NONE	,infoseparator1	},
{0				,0					,0			,0			,0			,0			,0					,0			,0			,0}
};


// Hier m�ssen die verwendeten WChar_Tables vorkommen; Numpad MUSS letzte Zeile sein.
// Die Funktion VkKeyScan() versucht, zu einem Zeichen den zugeh�rigen Virtual Key
// und Modifier zu finden. Die Numpad-Definition muss zum Schluss kommen, damit Zeichen
// wie '0' als vom Hauptfeld kommend interpretiert werden, falls dort vorhanden.
static ALLOC_SECTION_LDATA VK_TO_WCHAR_TABLE aVkToWcharTable[] = {
    {  (PVK_TO_WCHARS1)aVkToWch6, 6, sizeof(aVkToWch6[0]) },
    {  (PVK_TO_WCHARS1)aVkToWch7, 7, sizeof(aVkToWch7[0]) },
    {  (PVK_TO_WCHARS1)aVkToWch8, 8, sizeof(aVkToWch8[0]) },
    {  (PVK_TO_WCHARS1)aVkToWch4, 4, sizeof(aVkToWch4[0]) },
    {                       NULL, 0, 0                    },
};


/* **************************************************************************\
* aKeyNames[], aKeyNamesExt[]  - Virtual Scancode to Key Name tables
*
* Table attributes: Ordered Scan (by scancode), null-terminated
*
* Nur f�r Tasten, die keine Zeichen erzeugen, Tasten die Zeichen erzeugen
* werden danach benannt
\************************************************************************** */

static ALLOC_SECTION_LDATA VSC_LPWSTR aKeyNames[] = {
    0x01,    L"ESC",
    0x0e,    L"R\x00DC" L"CKTASTE",
    0x0f,    L"TABULATOR",
    0x1c,    L"EINGABE",
    0x1d,    L"STRG",
    0x2a,    L"UMSCHALT",
    0x2b,    L"MOD 3 RECHTS",
    0x36,    L"UMSCHALT RECHTS",
    0x37,    L"* (ZEHNERTASTATUR)",
    0x38,    L"ALT",
    0x39,    L"LEER",
    0x3a,    L"MOD 3 LINKS",
    0x3b,    L"F1",
    0x3c,    L"F2",
    0x3d,    L"F3",
    0x3e,    L"F4",
    0x3f,    L"F5",
    0x40,    L"F6",
    0x41,    L"F7",
    0x42,    L"F8",
    0x43,    L"F9",
    0x44,    L"F10",
    0x45,    L"PAUSE",
    0x46,    L"ROLLEN-FESTSTELL",
    0x47,    L"7 (ZEHNERTASTATUR)",
    0x48,    L"8 (ZEHNERTASTATUR)",
    0x49,    L"9 (ZEHNERTASTATUR)",
    0x4a,    L"- (ZEHNERTASTATUR)",
    0x4b,    L"4 (ZEHNERTASTATUR)",
    0x4c,    L"5 (ZEHNERTASTATUR)",
    0x4d,    L"6 (ZEHNERTASTATUR)",
    0x4e,    L"+ (ZEHNERTASTATUR)",
    0x4f,    L"1 (ZEHNERTASTATUR)",
    0x50,    L"2 (ZEHNERTASTATUR)",
    0x51,    L"3 (ZEHNERTASTATUR)",
    0x52,    L"0 (ZEHNERTASTATUR)",
    0x53,    L"KOMMA (ZEHNERTASTATUR)",
    0x56,    L"MOD 4 LINKS",
    0x57,    L"F11",
    0x58,    L"F12",
    0   ,    NULL
};


static ALLOC_SECTION_LDATA VSC_LPWSTR aKeyNamesExt[] = {
    0x1c,    L"EINGABE (ZEHNERTASTATUR)",
    0x1d,    L"STRG-RECHTS",
    0x35,    L"/ (ZEHNERTASTATUR)",
    0x37,    L"DRUCK",
    0x38,    L"MOD 4 RECHTS",
    0x45,    L"NUM-FESTSTELL",
    0x46,    L"UNTBR",
    0x47,    L"POS1",
    0x48,    L"NACH-OBEN",
    0x49,    L"BILD-NACH-OBEN",
    0x4b,    L"NACH-LINKS",
    0x4d,    L"NACH-RECHTS",
    0x4f,    L"ENDE",
    0x50,    L"NACH-UNTEN",
    0x51,    L"BILD-NACH-UNTEN",
    0x52,    L"EINFG",
    0x53,    L"ENTF",
    0x54,    L"<00>",
    0x56,    L"HILFE",
    0x5b,    L"LINKE WINDOWS",
    0x5c,    L"RECHTE WINDOWS",
    0x5d,    L"ANWENDUNG",
    0   ,    NULL
};


static ALLOC_SECTION_LDATA DEADKEY_LPWSTR aKeyNamesDead[] = {
//Tottaste 1 (links neben 1)
	L"^"         L"ZIRKUMFLEX",
    L"\x02C7"    L"HATSCHEK",
    L"\x21bb"    L"DREHEN",	
	L"\x02d9"    L"PUNKT_DARUEBER",	
	L"\x02de"    L"RHOTIC_HOOK",	
    L"\x002E"    L"PUNKT_DARUNTER",

//Tottaste 2 (links neben R�cktaste)
    L"\x0060"    L"GRAVIS",
    L"\x00B8"    L"CEDILLE",
    L"\x02DA"    L"RING",
    L"\x00A8"    L"TREMA",
    L"\x1ffe"    L"SPIRITUS_ASPER",
    L"\x00AF"    L"MAKRON",

//Tottaste 3 (rechts neben �ߓ)
    L"\x00B4"    L"AKUT",
    L"\x007E"    L"TILDE",
    L"\x002D"    L"QUERSTRICH",
    L"\x02DD"    L"DOPPEL_AKUT", 
    L"\x1fbf"    L"SPIRITUS_LENIS",
    L"\x02D8"    L"BREVE",	   
    NULL
};


static ALLOC_SECTION_LDATA KBDTABLES KbdTables = {
// Modifier keys
    &CharModifiers,

	
// Characters tables
    aVkToWcharTable,

	
// Diakritika vorhanden
    aDeadKey,

	
// Namen der Keys
    aKeyNames,
    aKeyNamesExt,
    aKeyNamesDead,

	
// Scancodes zu Virtual Keys
    ausVK,
    sizeof(ausVK) / sizeof(ausVK[0]),
    aE0VscToVk,
    aE1VscToVk,

	
// Kein Rechtes Alt daher AltGr auskommentiert
//   MAKELONG(KLLF_ALTGR, KBD_VERSION),
    0,
	
// keine Ligaturen
    0,
    0,
    NULL
};


PKBDTABLES KbdLayerDescriptor(VOID)
{
    return &KbdTables;
}