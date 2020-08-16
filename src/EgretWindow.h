#ifndef EgretWindow_Header
#define EgretWindow_Header

#include "EgretHeader.h"
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>

#ifdef __cplusplus
extern "C" {

typedef struct EgretWindow {
  SDL_Window *sdlwindow;
  SDL_Renderer *sdlrenderer;
} EgretWindow;

typedef enum {
  EgretWindowAllowHighDPI = 1 << 13,
  EgretWindowBorderless = 1 << 4,
  EgretWindowFullScreen = 1,
  EgretWindowFullScreenOnDesktop = (EgretWindowFullScreen | 1 << 12),
  EgretWindowInputGrabbed = 1 << 8,
  EgretWindowHidden = 1 << 3,
  EgretWindowMaximized = 1 << 7,
  EgretWindowMinimized = 1 << 6,
  EgretWindowOpengl = 1 << 1,
  EgretWindowResizable = 1 << 5,
  EgretWindowShown = 1 << 2,
  EgretWindowVulkan = 1 << 28
} EgretWindowFlags;

typedef enum {
  EgretRendererHardwareAccelerated = SDL_RENDERER_ACCELERATED,
  EgretRendererSoftwareFallback = SDL_RENDERER_SOFTWARE,
  EgretRendererTargetTexture = SDL_RENDERER_TARGETTEXTURE,
  EgretRendererVsync = SDL_RENDERER_PRESENTVSYNC
} EgretRendererFlags;

#define EgretClearWindow(window) SDL_RenderClear((window)->sdlrenderer)
EgretWindow *EgretCreateWindow(const char *title, int x, int y, int w, int h,
                               EgretWindowFlags windowflags,
                               EgretRendererFlags rendererflags) {
  EgretWindow *window = (EgretWindow *)SDL_calloc(1, sizeof(*window));
  window->sdlwindow =
      SDL_CreateWindow(title, x, y, w, h, (Uint32)(windowflags));
  if (!window->sdlwindow)
    return NULL;
  window->sdlrenderer =
      SDL_CreateRenderer(window->sdlwindow, -1, (Uint32)(rendererflags));
  if (!window->sdlrenderer)
    return NULL;
  return window;
}

void EgretDestroyWindow(EgretWindow *window) {
  SDL_DestroyWindow(window->sdlwindow);
  SDL_DestroyRenderer(window->sdlrenderer);
  SDL_free(window);
}

#define EgretDrawWindow(window) SDL_RenderPresent((window)->sdlrenderer)
#define EgretSetWindowResizable(window, resizable)                             \
  SDL_SetWindowResizable((window)->sdlwindow, (resizable))
#define EgretSetWindowSize(window, w, h)                                       \
  SDL_SetWindowSize((window)->sdlwindow, (w), (h))
#define EgretSetWindowTitle(window, title)                                     \
  SDL_SetWindowTitle((window)->sdlwindow, (title))

} // EXTERN C
#endif

#endif
