#ifndef EgretType_Header
#define EgretType_Header

#include <stdint.h> //Fuck SDL,what is the difference between stdint.h and inttypes.h?

#ifdef __cplusplus
extern "C" {
#endif

typedef int EgretBool;
#define EgretFalse 0
#define EgretTrue 1

typedef uint32_t EgretInt32;

#ifdef __cplusplus
} // EXTERN C
#endif

#endif
