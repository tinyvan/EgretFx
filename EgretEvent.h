#ifndef EgretEvent_Header
#define EgretEvent_Header

#include "EgretHeader.h"
#include _EgretSDL2_events

#include "EgretType.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef SDL_AudioDeviceEvent EgretAudioDeviceEvent;
typedef SDL_DropEvent EgretDropEvent;
typedef SDL_KeyboardEvent EgretKeyboardEvent;
typedef SDL_MouseButtonEvent EgretMouseButtonEvent;
typedef SDL_MouseMotionEvent EgretMouseMotionEvent;
typedef SDL_MouseWheelEvent EgretMouseWheelEvent;
typedef SDL_QuitEvent EgretQuitEvent;
typedef SDL_TextEditingEvent EgretTextEditingEvent;
typedef SDL_TextInputEvent EgretTextInputEvent;
typedef SDL_CommonEvent EgretUnknownEvent;
typedef SDL_WindowEvent EgretWindowEvent;

typedef union EgretEvent {
  EgretInt32 type;
  EgretAudioDeviceEvent audiodevice;
  EgretDropEvent drop;
  EgretKeyboardEvent keyboard;
  EgretMouseButtonEvent mousebutton;
  EgretMouseMotionEvent mousemotion;
  EgretMouseWheelEvent mousewheel;
  EgretQuitEvent quit;
  EgretTextEditingEvent textediting;
  EgretTextInputEvent textinput;
  EgretUnknownEvent unknown;
  EgretWindowEvent window;
} EgretEvent;

#ifdef __cplusplus
}
#endif

#endif
