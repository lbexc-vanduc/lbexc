#include "../../lbexcsrc/LBExC_Version.H"
#include "../../lbexcsrc/LBExC.H"
using namespace lbexc;
int
main (int   argc,
      char* argv[])
{
      // lbexc::Initialize(MPI_COMM_WORLD, std::cout, std::cerr, [](const char* msg) { throw std::runtime_error(msg); });

      std::cout << lbexc::Version() << std::endl;

      // lbexc::Finalize();
      return 0;
}