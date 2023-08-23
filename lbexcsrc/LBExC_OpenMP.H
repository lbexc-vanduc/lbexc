#ifndef LBExC_OPENMP_H_
#define LBExC_OPENMP_H_
#include <LBExC_Config.H>

#ifdef LBExC_USE_OMP
#include <omp.h>

namespace lbexc::OpenMP {

    inline int get_num_threads () { return omp_get_num_threads(); }
    inline int get_max_threads () { return omp_get_max_threads(); }
    inline int get_thread_num  () { return omp_get_thread_num();  }
    inline int in_parallel     () { return omp_in_parallel();     }

}

#else

namespace lbexc::OpenMP {

    constexpr int get_num_threads () { return 1; }
    constexpr int get_max_threads () { return 1; }
    constexpr int get_thread_num  () { return 0; }
    constexpr int in_parallel     () { return false; }

}

#endif

#endif
