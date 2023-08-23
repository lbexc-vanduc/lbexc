#ifndef LBExC__H
#define LBExC__H
#include "LBExC_CCSE-MPI.H"

#include <omp.h>
#include <iostream>
#include <vector>
#include <functional>
namespace lbexc
{
    class LBExC;

    using PTR_TO_VOID_FUNC = void (*)();
    using ErrorHandler = void (*)(const char*);

    namespace system
    {
        extern AMREX_EXPORT std::string exename;

        extern AMREX_EXPORT std::ostream* osout;
        extern AMREX_EXPORT std::ostream* oserr;

        extern AMREX_EXPORT ErrorHandler error_handler;
        extern AMREX_EXPORT int abort_on_unused_inputs;
    }

    // The returned LBExC* is non-owning! To delete it, call Finalize(LBExC*).
    LBExC* Initialize (MPI_Comm mpi_comm,
                       std::ostream& a_osout = std::cout,
                       std::ostream& a_oserr = std::cerr);

    

    /**
       \brief Returns true if there are any currently-active and initialized
       LBExC instances (i.e. one for which lbexc::Initialize has been called,
       and lbexc::Finalize has not). Otherwise false.
     */
    [[nodiscard]] bool Initialized ();







    class LBExC
    {
    public:
        LBExC(/* args */);
        ~LBExC();
        static bool empty () noexcept { return true; }
    };
    
}

#endif