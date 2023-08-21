#ifndef LBExC_Version_H
#define LBExC_Version_H
#define LBExC_VERSION "23.08"
#include <string>
namespace lbexc
{
    std::string Version ()
    {
#ifdef LBExC_VERSION
        return std::string(LBExC_VERSION);
#else
        return std::string("Unknown");
#endif
    }
}

#endif