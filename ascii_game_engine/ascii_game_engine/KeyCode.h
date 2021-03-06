// Virtual codes for Windows OS keyboard
#ifndef KEYCODE_H
#define KEYCODE_H

struct KeyCode
{
public:
	// Others
	static const int LMB = 0x01, RMB = 0x02, Cancle = 0x03, MMB = 0x04, X1MB = 0x05, X2MB = 0x06, Backspace = 0x08, Tab = 0x09, Clear = 0x0C, Enter = 0x0D, Shift = 0x10, Control = 0x11, Alt = 0x12, Pause = 0x13, Caps = 0x14, Escape = 0x1B, Space = 0x20, PageUp = 0x21, PageDown = 0x22, End = 0x23, Home = 0x24, LeftArrow = 0x25, UpArrow = 0x26, RightArrow = 0x27, DownArrow = 0x28, Select = 0x29, Print = 0x2A, Execute = 0x2B, PrintScreen = 0x2C, Insert = 0x2D, Delete = 0x2E, Help = 0x2F;

	// Letters
	static const int A = 0x41, B = 0x42, C = 0x43, D = 0x44, E = 0x45, F = 0x46, G = 0x47, H = 0x48, I = 0x49, J = 0x4A, K = 0x4B, L = 0x4C, M = 0x4D, N = 0x4E, O = 0x4F, P = 0x50, Q = 0x51, R = 0x52, S = 0x53, T = 0x54, U = 0x55, V = 0x56, W = 0x57, X = 0x58, Y = 0x59, Z = 0x5A;

	// Numbers
	static const int Zero = 0x30, One = 0x31, Two = 0x32, Three = 0x33, Four = 0x34, Five = 0x35, Six = 0x36, Seven = 0x37, Eight = 0x38, Nine = 0x39, NumPad0 = 0x60, NumPad1 = 0x61, NumPad2 = 0x62, NumPad3 = 0x63, NumPad4 = 0x64, NumPad5 = 0x65, NumPad6 = 0x66, NumPad7 = 0x67, NumPad8 = 0x68, NumPad9 = 0x69;

	// Math functions
	static const int Multiply = 0x6A, Add = 0x6B, Separator = 0x6C, Subtract = 0x6D, Decimal = 0x6E, Divide = 0x6F;

	// Function number
	static const int F1 = 0x70, F2 = 0x71, F3 = 0x72, F4 = 0x73, F5 = 0x74, F6 = 0x75, F7 = 0x76, F8 = 0x77, F9 = 0x78, F10 = 0x79, F11 = 0x7A, F12 = 0x7B, F13 = 0x7C, F14 = 0x7D, F15 = 0x7E, F16 = 0x7F, F17 = 0x80, F18 = 0x81, F19 = 0x82, F20 = 0x83, F21 = 0x84, F22 = 0x85, F23 = 0x86, F24 = 0x87;

	/*
		SemiColon -> :
		Period -> . (fullstop)
		Tilde -> ~
		Stroke -> |
		Bracket -> []
		Quote -> ' "
	*/
	static const int NumLock = 0x90, ScrollLock = 0x91, LShift = 0xA0, RShift = 0xA1, LControl = 0xA2, RControl = 0xA3, LAlt = 0xA4, RAlt = 0xA5, SemiColon = 0xBA, Plus = 0xBB, Comma = 0xBC, Minus = 0xBD, Period = 0xBE, QuestionMark = 0xBF, Tilde = 0xC0, LBracket = 0xDB, Stroke = 0xDC, RBracket = 0xDD, Quote = 0xDE;
};

#endif