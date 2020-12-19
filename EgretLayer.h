#ifndef EgretLayer_Header
#define EgretLayer_Header

#include "EgretHeader.h"
#include _EgretSDL2_pixels
#include _EgretSDL2_rect
#include _EgretSDL2_render

#ifdef __cplusplus
extern "C" {
#endif

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

#ifdef __cplusplus
} // EXTERN C
#endif

#endif
