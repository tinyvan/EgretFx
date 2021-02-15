#ifndef EgretWindow_Header
#define EgretWindow_Header

#include "EgretHeader.h"
#include _EgretSDL2_render
#include _EgretSDL2_video

#ifdef __cplusplus
extern "C" {
#endif

typedef struct EgretWindow {
  SDL_Window *SDLWindow;
  SDL_Renderer *SDLRenderer;
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

#define EgretClearWindow(window) SDL_RenderClear((window)->SDLRenderer)
inline EgretWindow *EgretCreateWindow(const char *title, int x, int y, int w,
                                      int h, EgretWindowFlags windowflags,
                                      EgretRendererFlags rendererflags) {
  EgretWindow *window;
  window = (EgretWindow *)SDL_calloc(1, sizeof(*window));
  window->SDLWindow = SDL_CreateWindow(title, x, y, w, h, windowflags);
  // EgretPRIVATEreturn_if_null(window->SDLWindow);
  window->SDLRenderer =
      SDL_CreateRenderer(window->SDLWindow, -1, rendererflags);
  // EgretPRIVATEreturn_if_null(window->SDLRenderer);
  return window;
}

inline void EgretDestroyWindow(EgretWindow *window) {
  SDL_DestroyWindow(window->SDLWindow);
  SDL_DestroyRenderer(window->SDLRenderer);
  SDL_free(window);
}

#define EgretRenderWindow(window) SDL_RenderPresent((window)->SDLRenderer)
#define EgretGetWindowFlags(window) SDL_GetWindowFlags((window)->SDLWindow)
#define EgretSetWindowResizable(window, resizable) \
  SDL_SetWindowResizable((window)->SDLWindow, (resizable))
#define EgretSetWindowSize(window, w, h) \
  SDL_SetWindowSize((window)->SDLWindow, (w), (h))
#define EgretSetWindowTitle(window, title) \
  SDL_SetWindowTitle((window)->SDLWindow, (title))
#define EgretShowWindow(window) SDL_ShowWindow((window)->SDLWindow)

#ifdef __cplusplus
}  // EXTERN C
#endif

#endif
