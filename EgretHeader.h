#ifndef EgretFX_Header
#define EgretFX_Header

#define _EgretSDL2 <SDL2/SDL.h>
#define _EgretSDL2_error <SDL2/SDL_error.h>
#define _EgretSDL2_events <SDL2/SDL_events.h>
#define _EgretSDL2_pixels <SDL2/SDL_pixels.h>
#define _EgretSDL2_rect <SDL2/SDL_rect.h>
#define _EgretSDL2_render <SDL2/SDL_render.h>
#define _EgretSDL2_stdinc <SDL2/SDL_stdinc.h>
#define _EgretSDL2_surface <SDL2/SDL_surface.h>
#define _EgretSDL2_ttf <SDL2/SDL_ttf.h>
#define _EgretSDL2_video <SDL2/SDL_video.h>

#define EgretPRIVATEreturn_if_null(ptr) \
  if (!ptr) return NULL

#endif
