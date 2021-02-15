#ifndef EgretFont_Header
#define EgretFont_Header

#include "EgretHeader.h"
#include _EgretSDL2_render
#include _EgretSDL2_surface
#include _EgretSDL2_ttf

#include "EgretLayer.h"
#include "EgretType.h"
#include "EgretWindow.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef TTF_Font EgretFont;

#define EgretCloseFont(font) TTF_CloseFont((font))
#define EgretOpenFont(filepath, ptsize) \
  TTF_OpenFontIndex((filepath), (ptsize), 0)
#define EgretOpenFontIndex(filepath, ptsize, index) \
  TTF_OpenFontIndex((filepath), (ptsize), (index))
#define EgretDrawText(text, x, y, font, window, mode, color...)            \
  EgretDrawTextIn##mode##Mode((text), (x), (y), (layer), (font), (window), \
                              color)
#define EgretPRIVATEchange_layer(func)                               \
  EgretRect rect;                                                    \
  SDL_Surface *SDLSurface;                                           \
  SDLSurface = func;                                                 \
  rect = {.x = x, .y = y, .w = SDLSurface->w, .h = SDLSurface->h};   \
  layer->SDLTexture =                                                \
      SDL_CreateTextureFromSurface(window->SDLRenderer, SDLSurface); \
  SDL_UpdateTexture(layer->SDLTexture, &rect, SDLSurface->pixels,    \
                    SDLSurface->pitch);                              \
  {                                                                  \
    EgretInt8 r, g, b, a;                                            \
    SDL_BlendMode blendMode;                                         \
    SDL_GetSurfaceColorMod(SDLSurface, &r, &g, &b);                  \
    SDL_SetTextureColorMod(layer->SDLTexture, r, g, b);              \
    SDL_GetSurfaceAlphaMod(SDLSurface, &a);                          \
    SDL_SetTextureAlphaMod(layer->SDLTexture, a);                    \
    SDL_SetTextureBlendMode(layer->SDLTexture, SDL_BLENDMODE_BLEND); \
  }                                                                  \
  SDL_FreeSurface(SDLSurface);                                       \
  layer->rect = rect
inline void EgretDrawTextInBlendMode(const char *text, int x, int y,
                                     EgretLayer *layer, EgretFont *font,
                                     EgretWindow *window,
                                     EgretColor foreground_color) {
  EgretPRIVATEchange_layer(
      TTF_RenderUTF8_Blended(font, text, foreground_color));
}
inline void EgretDrawTextInShadeMode(const char *text, int x, int y,
                                     EgretLayer *layer, EgretFont *font,
                                     EgretWindow *window,
                                     EgretColor foreground_color,
                                     EgretColor background_color) {
  EgretPRIVATEchange_layer(
      TTF_RenderUTF8_Shaded(font, text, foreground_color, background_color));
}

inline void EgretDrawTextInSolidMode(const char *text, int x, int y,
                                     EgretLayer *layer, EgretFont *font,
                                     EgretWindow *window,
                                     EgretColor foreground_color) {
  EgretPRIVATEchange_layer(TTF_RenderUTF8_Solid(font, text, foreground_color));
}

#undef EgretPRIVATEchange_layer

#ifdef __cplusplus
}  // EXTERN C
#endif

#endif
