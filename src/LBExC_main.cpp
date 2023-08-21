#include "LBExC.H"
int
main (int   argc,
      char* argv[])
{
      lbexc::Initialize(MPI_COMM_WORLD, std::cout, std::cerr, [](const char* msg) { throw std::runtime_error(msg); });

      std::cout << lbexc::Version();

      // lbexc::Finalize();
}