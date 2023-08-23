#ifndef LBExC_Print_H
#define LBExC_Print_H
#include "LBExC.H"
namespace lbexc
{
    //! This class provides the user with a few print options
    class Print
    {
    public:
        static constexpr int AllProcs = -1;

        /**
        * \brief Print on I/O Processor of the default communicator
        * Example: Print() << " x = " << x << std::endl;
        */
        explicit Print (std::ostream& os_ = lbexc::OutStream())
            : rank(ParallelContext::IOProcessorNumberSub())
            , comm(ParallelContext::CommunicatorSub())
            , os(os_)
            { ss.precision(os.precision()); }

    private:
        int rank;
        Comm comm;
        std::ostream &os;
        std::ostringstream ss;
    };
}


#endif