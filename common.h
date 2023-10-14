#ifdef __AVX__
    #include <immintrin.h>
#elif defined(__ARM_NEON)
    #include <arm_neon.h>
#else
#endif

