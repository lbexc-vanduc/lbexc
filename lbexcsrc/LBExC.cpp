#include "LBExC_CCSE-MPI.H"
#include "LBExC_CCSE-MPI.H"
#include "LBExC.H"
lbexc::LBExC*
lbexc::Initialize (lbexc::Comm mpi_comm,
                   std::ostream& a_osout, std::ostream& a_oserr)
{
    // generate MPI
    // generate lbexc data
    // start parallel

    // for MPI
    std::cout << "MPI initialized with "
            // << ParallelDescriptor::NProcs()
            << " MPI processes\n";
    int provided = -1;
    MPI_Query_thread(&provided);
    std::cout << "MPI initialized with thread support level " 
            << provided << std::endl;

    // for OMP
//    static_assert(_OPENMP >= 201107, "OpenMP >= 3.1 is required.");
    std::cout << "OMP initialized with "
            << omp_get_max_threads()
            << " OMP threads\n";

    
}

bool
lbexc::Initialized ()
{
    return true;
}