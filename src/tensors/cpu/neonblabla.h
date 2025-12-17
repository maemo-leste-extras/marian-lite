#pragma once

#if defined(__arm__) || defined(__aarch64__)
  #define SIMDE_DISABLE_NATIVE 1
  #include <arm_neon.h>

#if defined(__arm__)
  static inline int32x4_t vcvtnq_s32_f32(float32x4_t v) {
    return vcvtq_s32_f32(v);
  }

  static inline float32x4_t vrndnq_f32(float32x4_t v) {
    return vrndnq_f32(v);
  }
#else
  static inline float32x4_t vrndnq_f32_wrapper(float32x4_t v) {
    return vrndnq_f32(v);
  }
#endif

#else
#define SIMDE_ENABLE_NATIVE_ALIASES
#include <simde/x86/mmx.h>
#include <simde/x86/sse.h>
#include <simde/x86/sse2.h>
#include <simde/x86/sse4.1.h>
#include <simde/x86/avx.h>
#include <simde/x86/avx2.h>
#include <simde/arm/neon/rndn.h>
#include <simde/arm/neon.h>

#include <emmintrin.h>
#include <immintrin.h>
#include <tmmintrin.h>
#include <xmmintrin.h>

#define vrndnq_f32(a) simde_vrndnq_f32(a)
#endif
