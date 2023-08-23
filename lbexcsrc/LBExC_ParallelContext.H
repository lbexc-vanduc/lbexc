#ifndef LBExC_PARALLELCONTEXT_H
#define LBExC_PARALLELCONTEXT_H
#include "LBExC_Config.H"
#include "LBExC_CCSE-MPI.H"
#include <vector>
namespace lbexc::ParallelContext {

class Frame
{
public:
    [[nodiscard]] int MyID   () const noexcept { return m_id; }
    [[nodiscard]] int MyProc () const noexcept { return m_rank_me; }
    [[nodiscard]] int NProcs () const noexcept { return m_nranks; }
    [[nodiscard]] int IOProc () const noexcept { return m_io_rank; }

    //! sub-communicator associated with frame
    MPI_Comm comm = MPI_COMM_NULL;
    MPI_Group group = MPI_GROUP_NULL; //!< to avoid repeatedly creating groups in rank translation
private:
    int m_id      = -1; //!< frame ID
    int m_rank_me =  0; //!< local rank
    int m_nranks  =  1; //!< local # of ranks
    int m_mpi_tag = -1;
    int m_io_rank = -1;
};

extern std::vector<Frame> frames; //!< stack of communicator frames

//! number of ranks in world communicator
inline int NProcsAll () noexcept { return frames[0].NProcs(); }
//! my rank in world communicator
inline int MyProcAll () noexcept { return frames[0].MyProc(); }
//! IO rank in world communicator
inline int IOProcessorNumberAll () noexcept { return frames[0].IOProc(); }
//! Am IO processor for world communicator?
inline bool IOProcessorAll () noexcept { return MyProcAll() == IOProcessorNumberAll(); }


//! sub-communicator for current frame
inline MPI_Comm CommunicatorSub () noexcept { return frames.back().comm; }
//! sub-group for current frame
inline MPI_Group GroupSub () noexcept { return frames.back().group; }
//! number of ranks in current frame
inline int NProcsSub () noexcept { return frames.back().NProcs(); }
//! my sub-rank in current frame
inline int MyProcSub () noexcept { return frames.back().MyProc(); }
//! IO sub-rank in current frame
inline int IOProcessorNumberSub () noexcept { return frames.back().IOProc(); }
//! Am IO processor for current frame?
inline bool IOProcessorSub () noexcept { return MyProcSub() == IOProcessorNumberSub(); }

}
#endif