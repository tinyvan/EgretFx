#ifndef EgretError_Header
#define EgretError_Header

#include "EgretHeader.h"

#ifdef __cplusplus
extern "C" {
#endif

#define EgretGetError SDL_GetError
#define EgretSetError SDL_SetError

#ifdef __cplusplus
} // EXTERN C
#endif

#endif
