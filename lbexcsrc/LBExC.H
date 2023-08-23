#ifndef LBExC__H
#define LBExC__H
#include "LBExC_CCSE-MPI.H"

#include <omp.h>
#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <functional>
namespace lbexc
{
    class LBExC;

    

    namespace system
    {
        extern std::string exename;

        extern std::ostream* osout;
        extern std::ostream* oserr;
    }

    // The returned LBExC* is non-owning! To delete it, call Finalize(LBExC*).
    LBExC* Initialize (int  &argc, char* argv[]);

    

    /**
       \brief Returns true if there are any currently-active and initialized
       LBExC instances (i.e. one for which lbexc::Initialize has been called,
       and lbexc::Finalize has not). Otherwise false.
     */
    // [[nodiscard]] bool Initialized ();

    // void Finalize (LBExC* pamrex);
    // void Finalize (); // Finalize the current top





    class LBExC
    {
    public:
        LBExC(/* args */);
        ~LBExC();
        static bool empty () noexcept { return m_instance.empty(); }
        static int size () noexcept { return static_cast<int>(m_instance.size()); }
        static LBExC* top () noexcept { return m_instance.back().get(); }

        // Thisfunction will take the ownership of the AMReX pointer,
        // and put it on the top of the stack (i.e., back of the
        // vector).  If the pointer is already in the stack, it will
        // be moved to the top.
        static void push (LBExC* pamrex);

        // This erases `pamrex` from the stack.
        static void erase (LBExC* pamrex);
    private:

        static std::vector<std::unique_ptr<LBExC> > m_instance;

        // Geometry* m_geom = nullptr;
    };
}

#endif