#include "LBExC_CCSE-MPI.H"
#include "LBExC.H"
#include "LBExC_ParallelDescriptor.H"
namespace lbexc {

// std::vector<std::unique_ptr<LBExC> > LBExC::m_instance;

// namespace system
// {
//     std::string exename;
//     std::ostream* osout = &std::cout;
//     std::ostream* oserr = &std::cerr;
//     ErrorHandler error_handler = nullptr;
// }
}

// namespace {
//     std::streamsize  prev_out_precision;
//     std::streamsize  prev_err_precision;
//     std::new_handler prev_new_handler;
//     using SignalHandler = void (*)(int);
// }

lbexc::LBExC*
lbexc::Initialize (int   &argc, char* argv[])
{
//     system::exename.clear();
//     system::osout = &a_osout;
//     system::oserr = &a_oserr;
//     system::error_handler = a_errhandler;
    // generate MPI
    MPI_Init(&argc,&argv);

    // generate lbexc data
    // start parallel

//     prev_out_precision = system::osout->precision(10);
//     prev_err_precision = system::oserr->precision(10);

//     // for MPI
    std::cout << "MPI initialized with "
            << ParallelDescriptor::NProcs()
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







    LBExC::push(new LBExC()); // NOLINT(clang-analyzer-cplusplus.NewDeleteLeaks)
    return LBExC::top(); // NOLINT
}
