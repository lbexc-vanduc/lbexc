#ifndef LBExC_PARALLELDESCRIPTOR_H
#define LBExC_PARALLELDESCRIPTOR_H
#include <LBExC_Config.H>
namespace lbexc {
    //! Used as default argument to ParallelDescriptor::Barrier().
    const std::string Unnamed("Unnamed");

/**
    * \brief Perform any needed parallel initialization.  This MUST be the
    * first routine in this class called from within a program.
    */
    // void StartParallel (int*    argc = nullptr,
    //                     char*** argv = nullptr,
    //                     MPI_Comm mpi_comm = MPI_COMM_WORLD);

    void Initialize ();
    // void Finalize ();


    //! Split the process pool into teams
    // void StartTeams ();
    // void EndTeams ();


    /**
    * \brief Perform any needed parallel finalization.  This MUST be the
    * last routine in this class called from within a program.
    */
    // void EndParallel ();


    //! return the rank number local to the current Parallel Context
    // inline int
    // MyProc () noexcept
    // {
    //     return ParallelContext::MyProcAll();
    // }
    // inline int
    // MyProc (MPI_Comm comm) noexcept
    // {

    //     int r;
    //     MPI_Comm_rank(comm,&r);
    //     return r;
    // }
}
#endif