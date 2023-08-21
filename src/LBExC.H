#ifndef LBExC__H
#define LBExC__H
#include "LBExC_Version.H"
#include "LBExC_Config.H"
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

    /** the LBExC "git describe" version */
    [[nodiscard]] std::string Version ();

    // The returned LBExC* is non-owning! To delete it, call Finalize(LBExC*).
    LBExC* Initialize (MPI_Comm mpi_comm,
                       std::ostream& a_osout = std::cout,
                       std::ostream& a_oserr = std::cerr,
                       ErrorHandler a_errhandler = nullptr);

    // The returned LBExC* is non-owning! To delete it, call Finalize(LBExC*).
    // LBExC* Initialize (int& argc, char**& argv, bool build_parm_parse=true,
    //                    MPI_Comm mpi_comm = MPI_COMM_WORLD,
    //                    const std::function<void()>& func_parm_parse = {},
    //                    std::ostream& a_osout = std::cout,
    //                    std::ostream& a_oserr = std::cerr,
    //                    ErrorHandler a_errhandler = nullptr);

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
        static bool empty () noexcept { return m_instance.empty(); }
    };
    
}

#endif