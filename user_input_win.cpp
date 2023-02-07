#include "user_input_win.hpp"

namespace tex
{


void Press::Init()
{
    HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
    DWORD raw_mode = 0;

    // SetConsoleMode(hInput, raw_mode);
}

Press Press::getPress()
{
    HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
    DWORD events = 0;
    DWORD eventsRead = 0;
    Press press = {0};

    while(1)
    {
        WaitForSingleObject(hInput, INFINITE);

        GetNumberOfConsoleInputEvents(hInput, &events);

        if (events != 0)
        {
            INPUT_RECORD eventRecord;
            ReadConsoleInput(hInput, &eventRecord, 1, &eventsRead);

            if (eventRecord.EventType == KEY_EVENT &&
                eventRecord.Event.KeyEvent.bKeyDown)
            {
                switch (eventRecord.Event.KeyEvent.wVirtualKeyCode)
                {
                case VK_BACK:
                case VK_TAB:
                case VK_RETURN:
                case VK_PAUSE:
				case VK_ESCAPE:
				case VK_SPACE:
				case VK_END:
				case VK_HOME:
				case VK_LEFT:
				case VK_UP:
				case VK_RIGHT:
				case VK_DOWN:
				case VK_INSERT:
				case VK_DELETE:
				case VK_MULTIPLY:
				case VK_ADD:
				case VK_SEPARATOR:
				case VK_SUBTRACT:
				case VK_DECIMAL:
				case VK_DIVIDE:
				case VK_NUMLOCK:
				case VK_LSHIFT:
				case VK_RSHIFT:
				case VK_LCONTROL:
				case VK_RCONTROL:
				case VK_LMENU:
				case VK_RMENU:
                    press.ch = eventRecord.Event.KeyEvent.wVirtualKeyCode;
                    break;

				case VK_OEM_1:
				case VK_OEM_2:
				case VK_OEM_3:
				case VK_OEM_4:
				case VK_OEM_5:
				case VK_OEM_6:
				case VK_OEM_7:
				case VK_OEM_8:
					press.ch = eventRecord.Event.KeyEvent.uChar.AsciiChar;
					break;

                case VK_SHIFT:
                case VK_CONTROL:
                case VK_MENU:
                    // std::cout << eventRecord.Event.KeyEvent.wVirtualKeyCode << std::endl;
                    continue;

                case VK_CLEAR:
                case VK_CAPITAL:
				case VK_KANA:
				case VK_JUNJA:
				case VK_FINAL:
				case VK_KANJI:
				case VK_CONVERT:
				case VK_NONCONVERT:
				case VK_ACCEPT:
				case VK_MODECHANGE:
				case VK_PRIOR:
				case VK_NEXT:
				case VK_SELECT:
				case VK_PRINT:
				case VK_EXECUTE:
				case VK_SNAPSHOT:
				case VK_HELP:
				case VK_LWIN:
				case VK_RWIN:
				case VK_APPS:
				case VK_SLEEP:
				case VK_NUMPAD0:
				case VK_NUMPAD1:
				case VK_NUMPAD2:
				case VK_NUMPAD3:
				case VK_NUMPAD4:
				case VK_NUMPAD5:
				case VK_NUMPAD6:
				case VK_NUMPAD7:
				case VK_NUMPAD8:
				case VK_NUMPAD9:
				case VK_F1:
				case VK_F2:
				case VK_F3:
				case VK_F4:
				case VK_F5:
				case VK_F6:
				case VK_F7:
				case VK_F8:
				case VK_F9:
				case VK_F10:
				case VK_F11:
				case VK_F12:
				case VK_F13:
				case VK_F14:
				case VK_F15:
				case VK_F16:
				case VK_F17:
				case VK_F18:
				case VK_F19:
				case VK_F20:
				case VK_F21:
				case VK_F22:
				case VK_F23:
				case VK_F24:
				case VK_SCROLL:
				case VK_PROCESSKEY:
				case VK_ATTN:
				case VK_CRSEL:
				case VK_EXSEL:
				case VK_EREOF:
				case VK_PLAY:
				case VK_ZOOM:
				case VK_NONAME:
				case VK_PA1:
				case VK_OEM_CLEAR:
					std::cout << (int)eventRecord.Event.KeyEvent.wVirtualKeyCode << " | " << (int)eventRecord.Event.KeyEvent.uChar.AsciiChar << std::endl;
                    continue;
                
                default:
                    press.ch = eventRecord.Event.KeyEvent.uChar.AsciiChar;
                    break;
                }

                if (GetAsyncKeyState(VK_SHIFT) & PRESSED_MASK)
                    press.state |= KB_SHIFT;
                if (GetAsyncKeyState(VK_CONTROL) & PRESSED_MASK)
                {
					if (press.ch >= 32)
						press.ch |= 0x40;
                    press.state |= KB_CTRL;
                }
                if (GetAsyncKeyState(VK_MENU) & PRESSED_MASK)
                    press.state |= KB_ALT;
                return press;
            }
        }
    }
}


}