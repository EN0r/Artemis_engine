#pragma once
#include <cstdlib>
#include <iomanip>
#include <sstream>
#include "windows.h"
#include <iostream>
#include <vector>

class Keyboard
{

	
public:
	void initHook();
	void releaseHook();
};

std::string keyDown;

std::vector<std::string> map;

HHOOK KeyboardHook;
KBDLLHOOKSTRUCT kbdStruct;

template< typename T >

std::string int_to_hex(T i)
{
	std::stringstream stream;
	stream << "0x"
		<< std::setfill('0') << std::setw(sizeof(T) * 2)
		<< std::hex << i;
	return stream.str();
}




DWORD VK_NUM0 = 0x30;
DWORD VK_NUM1 = 0x31;
DWORD VK_NUM2 = 0x32;
DWORD VK_NUM3 = 0x33;
DWORD VK_NUM4 = 0x34;
DWORD VK_NUM5 = 0x35;
DWORD VK_NUM6 = 0x36;
DWORD VK_NUM7 = 0x37;
DWORD VK_NUM8 = 0x38;
DWORD VK_NUM9 = 0x39;

DWORD VK_A = 0x41;
DWORD VK_B = 0x42;
DWORD VK_C = 0x43;
DWORD VK_D = 0x44;
DWORD VK_E = 0x45;
DWORD VK_F = 0x46;
DWORD VK_G = 0x47;
DWORD VK_H = 0x48;
DWORD VK_I = 0x49;
DWORD VK_J = 0x4A;
DWORD VK_K = 0x4B;
DWORD VK_L = 0x4C;
DWORD VK_M = 0x4D;
DWORD VK_N = 0X4E;
DWORD VK_O = 0x4F;
DWORD VK_P = 0x50;
DWORD VK_Q = 0x51;
DWORD VK_R = 0x52;
DWORD VK_S = 0x53;
DWORD VK_T = 0x54;
DWORD VK_U = 0x55;
DWORD VK_V = 0x56;
DWORD VK_W = 0x57;
DWORD VK_X = 0x58;
DWORD VK_Y = 0x59;
DWORD VK_z = 0x5A;


std::string Keycodes(DWORD KC)
{
	if (KC == VK_A)
	{
		return "a";
	}

	if (kbdStruct.vkCode == VK_B)
	{
		return "b";
	}

	if (kbdStruct.vkCode == VK_C)
	{
		return "c";
	}

	if (kbdStruct.vkCode == VK_D)
	{
		return "d";
	}

	if (kbdStruct.vkCode == VK_E)
	{
		return "e";
	}

	if (kbdStruct.vkCode == VK_F)
	{
		return "f";
	}

	if (kbdStruct.vkCode == VK_G)
	{
		return "g";
	}

	if (kbdStruct.vkCode == VK_H)
	{
		return "h";
	}

	if (kbdStruct.vkCode == VK_I)
	{
		return "i";
	}

	if (kbdStruct.vkCode == VK_J)
	{
		return "j";
	}
	if (kbdStruct.vkCode == VK_K)
	{
		return "k";
	}
	if (kbdStruct.vkCode == VK_M)
	{
		return "m";
	}
	if (kbdStruct.vkCode == VK_N)
	{
		return "n";
	}
	if (kbdStruct.vkCode == VK_O)
	{
		return "o";
	}
	if (kbdStruct.vkCode == VK_P)
	{
		return "p";
	}
	if (kbdStruct.vkCode == VK_Q)
	{
		return "q";
	}
	if (kbdStruct.vkCode == VK_R)
	{
		return "r";
	}
	if (kbdStruct.vkCode == VK_S)
	{
		return "s";
	}
	if (kbdStruct.vkCode == VK_T)
	{
		return "t";
	}
	if (kbdStruct.vkCode == VK_U)
	{
		return "u";
	}
	if (kbdStruct.vkCode == VK_V)
	{
		return "v";
	}
	if (kbdStruct.vkCode == VK_W)
	{
		return "w";
	}
	if (kbdStruct.vkCode == VK_X)
	{
		return "x";
	}
	if (kbdStruct.vkCode == VK_Y)
	{
		return "y";
	}
	if (kbdStruct.vkCode == VK_z)
	{
		return "z";
	}

	if (kbdStruct.vkCode == VK_L)
	{
		return "l";
	}

	//Symbols

	if (kbdStruct.vkCode == VK_SPACE)
	{
		return "space";
	}


	if (kbdStruct.vkCode == VK_CAPITAL)
	{
		return " *CAPSLOCK* ";
	}

	if (kbdStruct.vkCode == VK_LSHIFT || kbdStruct.vkCode == VK_RSHIFT)
	{
		return " Shift + ";
	}

	if (kbdStruct.vkCode == VK_RETURN)
	{
		return " *RETURN* ";
	}
	if (kbdStruct.vkCode == VK_BACK)
	{
		return " *BACKSPACE* ";
	}

	// numbers

	if (kbdStruct.vkCode == VK_NUM0)
	{
		return "0";
	}

	if (kbdStruct.vkCode == VK_NUM1)
	{
		return "1";
	}
	if (kbdStruct.vkCode == VK_NUM2)
	{
		return "2";
	}
	if (kbdStruct.vkCode == VK_NUM3)
	{
		return "3";
	}
	if (kbdStruct.vkCode == VK_NUM4)
	{
		return "4";
	}
	if (kbdStruct.vkCode == VK_NUM5)
	{
		return "5";
	}
	if (kbdStruct.vkCode == VK_NUM6)
	{
		return "6";
	}
	if (kbdStruct.vkCode == VK_NUM7)
	{
		return "7";
	}
	if (kbdStruct.vkCode == VK_NUM8)
	{
		return "8";
	}
	if (kbdStruct.vkCode == VK_NUM9)
	{
		return "9";
	}
	else
	{
		return "Null";
	}

} // Keycodes(DWORD VK_Keycode). Returns String of keypressed.

bool keyUp = false;
bool keyDown1 = false;

// dont question my overuse of spaces.

LRESULT __stdcall KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam)
{

	if (nCode >= 0)
	{
		
		if (wParam == WM_KEYDOWN)
		{
			keyDown1 = true;
			keyUp = false;
			BYTE lpBuf[256];
			WCHAR lpChar[5] = {};
			kbdStruct = *((KBDLLHOOKSTRUCT*)lParam);
			if (keyUp == false)
			{
				keyDown = Keycodes(kbdStruct.vkCode);

				map.push_back(Keycodes(kbdStruct.vkCode));
				// This adds a key to the map
			}
			
		}
		if (wParam == WM_KEYUP)
		{
			keyDown1 = false;
			keyUp = true;

			if (keyDown1 == false)
			{
				keyDown = " ";

				std::vector<std::string>::iterator it = std::find(map.begin(), map.end(), Keycodes(kbdStruct.vkCode));
				int iIndex = map.size() + 1;

				//map.erase(it);

				map.clear(); // this does cause *some bugs* as in alot. I can't erase without bugs so this is tempfix

			}
			
		}
	}



	return CallNextHookEx(KeyboardHook, nCode, wParam, lParam);

}



void Keyboard::initHook()
{

	if (!(KeyboardHook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardProc, NULL, 0)))
	{
		// error handler
	}


}

void Keyboard::releaseHook()
{
	UnhookWindowsHookEx(KeyboardHook);
}


bool findInMap(std::string key) // returns true if found
{
	std::vector < std::string > ::iterator it;
	it = find(map.begin(), map.end(), key);
	if (it != map.end())
		return true;
	else
		return false;
}