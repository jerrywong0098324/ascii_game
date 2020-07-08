// Console Colours
#include <Windows.h>

struct Colours
{
public:
	static const int FG_DARK_BLUE = 0x0001, FG_DARK_GREEN = 0x0002, FG_DARK_RED = 0x0004, FG_GREY = 0x0008, FG_BLUE = 0x0001 | 0x0008, FG_GREEN = 0x0002 | 0x0008, FG_RED = 0x0004 | 0x0008, FG_AQUA = 0x0001 | 0x0002, FG_PURPLE = 0x0001 | 0x0004, FG_MUSTARD = 0x0002 | 0x0004, FG_CYAN = 0x0001 | 0x0002 | 0x0008, FG_PINK = 0x0001 | 0x0004 | 0x0008, FG_YELLOW = 0x0002 | 0x0004 | 0x0008, FG_DARK_WHITE = 0x0001 | 0x0002 | 0x0004, FG_WHITE = 0x0001 | 0x0002 | 0x0004 | 0x0008;

	static const int BG_DARK_BLUE = 0x0010, BG_DARK_GREEN = 0x0020, BG_DARK_RED = 0x0040, BG_GREY = 0x0080, BG_BLUE = 0x0010 | 0x0080, BG_GREEN = 0x0020 | 0x0080, BG_RED = 0x0040 | 0x0080, BG_AQUA = 0x0010 | 0x0020, BG_PURPLE = 0x0010 | 0x0040, BG_MUSTARD = 0x0020 | 0x0040, BG_CYAN = 0x0010 | 0x0020 | 0x0080, BG_PINK = 0x0010 | 0x0040 | 0x0080, BG_YELLOW = 0x0020 | 0x0040 | 0x0080, BG_DARK_WHITE = 0x0010 | 0x0020 | 0x0040, BG_WHITE = 0x0010 | 0x0020 | 0x0040 | 0x0080;

	/* 
		BLACK: Set both Foreground and Background to Black
		DEFAULT: Set text to white and background to black
	*/
	static const int BLACK = 0, DEFAULT = 0 | 0x0001 | 0x0002 | 0x0004 | 0x0008;
};