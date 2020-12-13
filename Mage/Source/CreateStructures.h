#ifndef CREATE_STRUCTURES_H
#define CREATE_STRUCTURES_H

#include "Includes.h"

typedef struct MageApplicationWindow MageApplicationWindow;

typedef struct MageApplicationWindowCreateInfo
{
    U16         Width;
    U16         Height;
    I16         SpawnOffsetX;
    I16         SpawnOffsetY;
    U8          Resisable;
    const char *Title;
} MageApplicationWindowCreateInfo;

typedef enum MageInputHandlerEventListenFlags
{
    MAGE_INPUT_HANDLER_EVENT_LISTEN_FLAGS_KEYBOARD            = 0x00000001, /* Keyboard key inputs */
    MAGE_INPUT_HANDLER_EVENT_LISTEN_FLAGS_MOUSE               = 0x00000002, /* Mouse clicks and positions */
    MAGE_INPUT_HANDLER_EVENT_LISTEN_FLAGS_WINDOW_EVENTS       = 0x00000002, /* Window focus, refocus, closing, etc */
    MAGE_INPUT_HANDLER_EVENT_LISTEN_FLAGS_ALL_FLAGS           = 0xFFFFFFFF, /* Will allow for all events */
} MageInputHandlerEventListenFlags;

typedef enum MageInputHandlerEventJoystickListenFlags
{
    MAGE_INPUT_HANDLER_EVENT_JOYSTICK_LISTEN_FLAGS_ALL_FLAGS  = 0xFFFFFFFF, /* Will allow for all events */
} MageInputHandlerEventJoystickListenFlags;

typedef struct MageInputHandlerCreateInfo
{
    MageInputHandlerEventListenFlags            InputFlags;
    MageInputHandlerEventJoystickListenFlags    JoystickFlags;
    MageApplicationWindow                       *ApplicationWindow; /* If created with the engine wrapper then it is automatically assigned */
} MageInputHandlerCreateInfo;

typedef struct MageEngineApplicationCreateInfo
{
    MageApplicationWindowCreateInfo             ApplicationWindowCreateInfo;
    MageInputHandlerCreateInfo                  InputEventHandlerCreateInfo;
} MageEngineApplicationCreateInfo;

#endif