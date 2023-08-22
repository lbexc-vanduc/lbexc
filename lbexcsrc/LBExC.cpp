#include "LBExC_CCSE-MPI.H"
#include "LBExC_CCSE-MPI.H"
#include "LBExC.H"
// lbexc::LBExC*
// lbexc::Initialize (MPI_Comm mpi_comm,
//                    std::ostream& a_osout, std::ostream& a_oserr,
//                    ErrorHandler a_errhandler)
// {
//     int argc = 0;
//     char** argv = nullptr;
//     // return Initialize(argc, argv, false, mpi_comm, {}, a_osout, a_oserr, a_errhandler);
    
//     // for MPI
//     std::cout << "MPI initialized with "
//             // << ParallelDescriptor::NProcs()
//             << " MPI processes\n";
//     int provided = -1;
//     MPI_Query_thread(&provided);
//     std::cout << "MPI initialized with thread support level " << provided << std::endl;

//     // for OMP
// //    static_assert(_OPENMP >= 201107, "OpenMP >= 3.1 is required.");
//     std::cout << "OMP initialized with "
//                 << omp_get_max_threads()
//                 << " OMP threads\n";
// }

bool
lbexc::Initialized ()
{
    return true;
}