#ifndef EgretError_Header
#define EgretError_Header

#include "EgretHeader.h"

extern "C" {

#define EgretGetError SDL_GetError
#define EgretSetError SDL_SetError

} // EXTERN C

#endif
