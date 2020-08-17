#ifndef EgretFont_Header
#define EgretFont_Header

#include "EgretHeader.h"
#include "EgretLayer.h"
#include "EgretWindow.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef TTF_Font EgretFont;

#define EgretCloseFont(font) TTF_CloseFont((font))
#define EgretOpenFont(filepath, ptsize)                                        \
  TTF_OpenFontIndex((filepath), (ptsize), 0)
#define EgretOpenFontIndex(filepath, ptsize, index)                            \
  TTF_OpenFontIndex((filepath), (ptsize), (index))
#define EgretDrawText(text, font, window, mode, color...)                      \
  EgretDrawTextIn##mode##Mode((text), (font), (window), color)

EgretLayer *EgretDrawTextInBlendMode(const char *text, EgretFont *font,
                                     EgretWindow *window,
                                     EgretColor foreground_color) {
  SDL_Surface *sdlsurface =
      TTF_RenderUTF8_Blended(font, text, foreground_color);
  if (!sdlsurface)
    return NULL;
  SDL_Texture *sdltexture =
      SDL_CreateTextureFromSurface(window->sdlrenderer, sdlsurface);
  if (!sdltexture)
    return NULL;
  EgretLayer *layer = (EgretLayer *)SDL_calloc(1, sizeof(*layer));
  layer->sdltexture = sdltexture;
  layer->w = sdlsurface->w;
  layer->h = sdlsurface->h;
  SDL_FreeSurface(sdlsurface);
  return layer;
}

EgretLayer *EgretDrawTextInShadeMode(const char *text, EgretFont *font,
                                     EgretWindow *window,
                                     EgretColor foreground_color,
                                     EgretColor background_color) {
  SDL_Surface *sdlsurface =
      TTF_RenderUTF8_Shaded(font, text, foreground_color, background_color);
  if (!sdlsurface)
    return NULL;
  SDL_Texture *sdltexture =
      SDL_CreateTextureFromSurface(window->sdlrenderer, sdlsurface);
  if (!sdltexture)
    return NULL;
  EgretLayer *layer = (EgretLayer *)SDL_calloc(1, sizeof(*layer));
  layer->sdltexture = sdltexture;
  layer->w = sdlsurface->w;
  layer->h = sdlsurface->h;
  SDL_FreeSurface(sdlsurface);
  return layer;
}

EgretLayer *EgretDrawTextInSolidMode(const char *text, EgretFont *font,
                                     EgretWindow *window,
                                     EgretColor foreground_color) {
  SDL_Surface *sdlsurface = TTF_RenderUTF8_Solid(font, text, foreground_color);
  if (!sdlsurface)
    return NULL;
  SDL_Texture *sdltexture =
      SDL_CreateTextureFromSurface(window->sdlrenderer, sdlsurface);
  if (!sdltexture)
    return NULL;
  EgretLayer *layer = (EgretLayer *)SDL_calloc(1, sizeof(*layer));
  layer->sdltexture = sdltexture;
  layer->w = sdlsurface->w;
  layer->h = sdlsurface->h;
  SDL_FreeSurface(sdlsurface);
  return layer;
}

#ifdef __cplusplus
} // EXTERN C
#endif

#endif
