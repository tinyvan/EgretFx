#ifndef EgretLayer_Header
#define EgretLayer_Header

#include "EgretHeader.h"
#include "EgretWindow.h"
#include <SDL2/SDL_render.h>

#ifdef __cplusplus
extern "C" {

typedef SDL_Color EgretColor;
typedef SDL_Rect EgretRect;
typedef struct EgretLayer {
  SDL_Texture *sdltexture;
  int w;
  int h;
} EgretLayer;

#define EgretLayerToWindow(layer, window, source_rect, destination_rect)       \
  SDL_RenderCopy((window)->sdlrenderer, (layer)->sdltexture, (source_rect),    \
                 (destination_rect))

} // EXTERN C
#endif

#endif
