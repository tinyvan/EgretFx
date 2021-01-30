#ifndef EgretWindow_Header
#define EgretWindow_Header

#include "EgretHeader.h"
#include _EgretSDL2_render
#include _EgretSDL2_video

#ifdef __cplusplus
extern "C" {
#endif

typedef struct EgretWindow {
  SDL_Window *sdlwindow;
  SDL_Renderer *sdlrenderer;
} EgretWindow;

#define EgretWindowAllowHighDPI (1 << 13)
#define EgretWindowBorderless (1 << 4)
#define EgretWindowFullScreen (1)
#define EgretWindowFullScreenOnDesktop (EgretWindowFullScreen | 1 << 12)
#define EgretWindowInputGrabbed (1 << 8)
#define EgretWindowHidden (1 << 3)
#define EgretWindowMaximized (1 << 7)
#define EgretWindowMinimized (1 << 6)
#define EgretWindowOpengl (1 << 1)
#define EgretWindowResizable (1 << 5)
#define EgretWindowShown (1 << 2)
#define EgretWindowVulkan (1 << 28)
typedef Uint32 EgretWindowFlags;

#define EgretRendererHardwareAccelerated SDL_RENDERER_ACCELERATED
#define EgretRendererSoftwareFallback SDL_RENDERER_SOFTWARE
#define EgretRendererTargetTexture SDL_RENDERER_TARGETTEXTURE
#define EgretRendererVsync SDL_RENDERER_PRESENTVSYNC
typedef Uint32 EgretRendererFlags;

#define EgretClearWindow(window) SDL_RenderClear((window)->sdlrenderer)
inline EgretWindow *EgretCreateWindow(const char *title, int x, int y, int w,
                                      int h, EgretWindowFlags windowflags,
                                      EgretRendererFlags rendererflags) {
  EgretWindow *window = (EgretWindow *)SDL_calloc(1, sizeof(*window));
  window->sdlwindow = SDL_CreateWindow(title, x, y, w, h, windowflags);
  if (!window->sdlwindow) return NULL;
  window->sdlrenderer =
      SDL_CreateRenderer(window->sdlwindow, -1, rendererflags);
  if (!window->sdlrenderer) return NULL;
  return window;
}

inline void EgretDestroyWindow(EgretWindow *window) {
  SDL_DestroyWindow(window->sdlwindow);
  SDL_DestroyRenderer(window->sdlrenderer);
  SDL_free(window);
}

#define EgretDrawWindow(window) SDL_RenderPresent((window)->sdlrenderer)
#define EgretSetWindowResizable(window, resizable) \
  SDL_SetWindowResizable((window)->sdlwindow, (resizable))
#define EgretSetWindowSize(window, w, h) \
  SDL_SetWindowSize((window)->sdlwindow, (w), (h))
#define EgretSetWindowTitle(window, title) \
  SDL_SetWindowTitle((window)->sdlwindow, (title))
#define EgretShowWindow(window) SDL_ShowWindow((window)->sdlwindow)

#ifdef __cplusplus
}  // EXTERN C
#endif

#endif
