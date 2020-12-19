#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include "CreateStructures.h"
#include "Includes.h"
#include "Window.h"

#define MAGE_MOUSE_STATE_COUNT    3
#define MAGE_KEYBOARD_STATE_COUNT 128

typedef enum MageKeyboardKey
{
    MAGE_KEYBOARD_KEY_A = 0,
    MAGE_KEYBOARD_KEY_C,
    MAGE_KEYBOARD_KEY_D,
    MAGE_KEYBOARD_KEY_E,
    MAGE_KEYBOARD_KEY_F,
    MAGE_KEYBOARD_KEY_G,
    MAGE_KEYBOARD_KEY_H,
    MAGE_KEYBOARD_KEY_I,
    MAGE_KEYBOARD_KEY_J,
    MAGE_KEYBOARD_KEY_K,
    MAGE_KEYBOARD_KEY_L,
    MAGE_KEYBOARD_KEY_M,
    MAGE_KEYBOARD_KEY_N,
    MAGE_KEYBOARD_KEY_O,
    MAGE_KEYBOARD_KEY_P,
    MAGE_KEYBOARD_KEY_Q,
    MAGE_KEYBOARD_KEY_R,
    MAGE_KEYBOARD_KEY_S,
    MAGE_KEYBOARD_KEY_T,
    MAGE_KEYBOARD_KEY_U,
    MAGE_KEYBOARD_KEY_W,
    MAGE_KEYBOARD_KEY_X,
    MAGE_KEYBOARD_KEY_Y,
    MAGE_KEYBOARD_KEY_Z,

    MAGE_KEYBOARD_KEY_SPACE,
	MAGE_KEYBOARD_KEY_APOSTROPHE,
	MAGE_KEYBOARD_KEY_COMMA,
	MAGE_KEYBOARD_KEY_MINUS,
	MAGE_KEYBOARD_KEY_PERIOD,
	MAGE_KEYBOARD_KEY_SLASH,
	MAGE_KEYBOARD_KEY_EQUAL,
	MAGE_KEYBOARD_KEY_SEMI_COLON,

    MAGE_KEYBOARD_KEY_LEFT_BRACKET,
	MAGE_KEYBOARD_KEY_BACKSLASH,
	MAGE_KEYBOARD_KEY_RIGHT_BRACKET,
	MAGE_KEYBOARD_KEY_GRAVE_ACCENT,
	MAGE_KEYBOARD_KEY_ESCAPE,
	MAGE_KEYBOARD_KEY_ENTER,
	MAGE_KEYBOARD_KEY_TAB,
	MAGE_KEYBOARD_KEY_BACKSPACE,
	MAGE_KEYBOARD_KEY_INSERT,
	MAGE_KEYBOARD_KEY_DELETE,
	MAGE_KEYBOARD_KEY_DIRECTIONAL_RIGHT,
	MAGE_KEYBOARD_KEY_DIRECTIONAL_LEFT,
	MAGE_KEYBOARD_KEY_DIRECTIONAL_DOWN,
	MAGE_KEYBOARD_KEY_DIRECTIONAL_UP,
	MAGE_KEYBOARD_KEY_PAGE_UP,
	MAGE_KEYBOARD_KEY_PAGE_DOWN,
	MAGE_KEYBOARD_KEY_HOME,
	MAGE_KEYBOARD_KEY_END,
	MAGE_KEYBOARD_KEY_CAPS_LOCK,
	MAGE_KEYBOARD_KEY_SCROLL_LOCK,
	MAGE_KEYBOARD_KEY_NUM_LOCK,
	MAGE_KEYBOARD_KEY_PRINT_SCREEN,
	MAGE_KEYBOARD_KEY_PAUSE,

    MAGE_KEYBOARD_KEY_1,
    MAGE_KEYBOARD_KEY_2,
    MAGE_KEYBOARD_KEY_3,
    MAGE_KEYBOARD_KEY_4,
    MAGE_KEYBOARD_KEY_5,
    MAGE_KEYBOARD_KEY_6,
    MAGE_KEYBOARD_KEY_7,
    MAGE_KEYBOARD_KEY_8,
    MAGE_KEYBOARD_KEY_9,
    MAGE_KEYBOARD_KEY_0,

    MAGE_KEYBOARD_KEY_KEYPAD_0,
	MAGE_KEYBOARD_KEY_KEYPAD_1,
	MAGE_KEYBOARD_KEY_KEYPAD_2,
	MAGE_KEYBOARD_KEY_KEYPAD_3,
	MAGE_KEYBOARD_KEY_KEYPAD_4,
	MAGE_KEYBOARD_KEY_KEYPAD_5,
	MAGE_KEYBOARD_KEY_KEYPAD_6,
	MAGE_KEYBOARD_KEY_KEYPAD_7,
	MAGE_KEYBOARD_KEY_KEYPAD_8,
	MAGE_KEYBOARD_KEY_KEYPAD_9,

    MAGE_KEYBOARD_KEY_KEYPAD_DECIMAL,
	MAGE_KEYBOARD_KEY_KEYPAD_DIVIDE,
	MAGE_KEYBOARD_KEY_KEYPAD_MULTIPLY,
	MAGE_KEYBOARD_KEY_KEYPAD_SUBTRACT,
	MAGE_KEYBOARD_KEY_KEYPAD_ADD,
	MAGE_KEYBOARD_KEY_KEYPAD_ENTER,
	MAGE_KEYBOARD_KEY_KEYPAD_EQUAL,

    MAGE_KEYBOARD_KEY_F1,
	MAGE_KEYBOARD_KEY_F2,
	MAGE_KEYBOARD_KEY_F3,
	MAGE_KEYBOARD_KEY_F4,
	MAGE_KEYBOARD_KEY_F5,
	MAGE_KEYBOARD_KEY_F6,
	MAGE_KEYBOARD_KEY_F7,
	MAGE_KEYBOARD_KEY_F8,
	MAGE_KEYBOARD_KEY_F9,
	MAGE_KEYBOARD_KEY_F10,
	MAGE_KEYBOARD_KEY_F11,
	MAGE_KEYBOARD_KEY_F12,

    MAGE_KEYBOARD_KEY_LEFT_SHIFT,
	MAGE_KEYBOARD_KEY_LEFT_CONTROL,
	MAGE_KEYBOARD_KEY_LEFT_ALT,
	MAGE_KEYBOARD_KEY_LEFT_SUPER,
	MAGE_KEYBOARD_KEY_RIGHT_SHIFT,
	MAGE_KEYBOARD_KEY_RIGHT_CONTROL,
	MAGE_KEYBOARD_KEY_RIGHT_ALT,
	MAGE_KEYBOARD_KEY_RIGHT_SUPER
} MageKeyboardKey;

typedef enum MageMouseButton
{
    MAGE_MOUSE_BUTTON_LEFT = 0,
    MAGE_MOUSE_BUTTON_RIGHT,
    MAGE_MOUSE_BUTTON_MIDDLE /* Clicking down on mouse wheel */
} MageMouseButton;

typedef enum MageButtonState
{
    MAGE_BUTTON_STATE_PRESS = 0x01,
    MAGE_BUTTON_STATE_REPEAT = 0x02,
    MAGE_BUTTON_STATE_RELEASE = 0x04
} MageButtonState;

typedef struct MageInputHandler
{
    U8              MouseStates[MAGE_MOUSE_STATE_COUNT];
    U8              KeyboardStates[MAGE_KEYBOARD_STATE_COUNT];
	U8				MouseFocused;
    I32             MouseWheelPosition;
    U32             MousePositionX;
    U32             MousePositionY;
} MageInputHandler;

/* Following implimented by native window frameworks */

extern U8 MageInputHandlerCreate(MageInputHandlerCreateInfo* info, MageInputHandler* handler);
extern U8 MageInputHandlerPollEvents(MageInputHandler* handler, MageApplicationWindow* window);
extern U8 MageInputHandlerDestroy(MageInputHandler* handler);

extern MageKeyboardKey MageInputHandlerTranslateKeyCodes(MageInputHandler *handler, const U64 code);

#if MAGE_BUILD_PLATFORM_WINDOWS
	extern LRESULT CALLBACK MageInputHandlerWindowsEventListener(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
#endif

/* Common to all frameworks */

extern U8  MageInputHandlerUpdateKeyStatus(MageInputHandler* handler, const MageKeyboardKey key, const MageButtonState state);
extern U8  MageInputHandlerUpdateMouseButtonStatus(MageInputHandler* handler, const MageKeyboardKey key, const MageButtonState state);
extern U8  MageInputHandlerInterrogateKeyState(MageInputHandler* handler, const MageKeyboardKey key, const MageButtonState state);
extern U8  MageInputHandlerInterrogateMouseButtonState(MageInputHandler* handler, const MageMouseButton button, const MageButtonState state);
extern F32 MageInputHandlerInterrogateMousePositionX(MageInputHandler* handler);
extern F32 MageInputHandlerInterrogateMousePositionY(MageInputHandler* handler);

#endif