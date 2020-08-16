#ifndef EgretManager_Header
#define EgretManager_Header

#include "EgretHeader.h"
#include <SDL2/SDL.h>

#define EgretInitializeBase()                                                  \
  SDL_InitSubSystem(SDL_INIT_VIDEO | SDL_INIT_EVENTS)
#define EgretQuitBase() SDL_QuitSubSystem(SDL_INIT_VIDEO | SDL_INIT_EVENTS)
#define EgretInitializeText TTF_Init
#define EgretQuitText TTF_Quit

#endif
