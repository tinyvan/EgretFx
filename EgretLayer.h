#ifndef EgretLayer_Header
#define EgretLayer_Header

#include "EgretHeader.h"
#include _EgretSDL2_pixels
#include _EgretSDL2_rect
#include _EgretSDL2_render
#include _EgretSDL2_stdinc
#include _EgretSDL2_surface

#include "EgretWindow.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef SDL_Color EgretColor;
typedef SDL_Rect EgretRect;
typedef struct EgretLayer {
  SDL_Texture *SDLTexture;
  EgretRect rect;
} EgretLayer;

inline EgretLayer *EgretCreateLayer(EgretWindow *window, int w, int h) {
  EgretLayer *layer;
  layer = (EgretLayer *)SDL_calloc(1, sizeof(*layer));
  layer->SDLTexture =
      SDL_CreateTexture(window->SDLRenderer, SDL_PIXELFORMAT_ARGB8888,
                        SDL_TEXTUREACCESS_STATIC, w, h);
  return layer;
}

inline void EgretDestroyLayer(EgretLayer *layer) {
  SDL_DestroyTexture(layer->SDLTexture);
  SDL_free(layer);
}

#define EgretLayerToWindow(layer, window, srcRect, destRect)            \
  SDL_RenderCopy((window)->SDLRenderer, (layer)->SDLTexture, (srcRect), \
                 (destRect))

#ifdef __cplusplus
}  // EXTERN C
#endif

#endif
