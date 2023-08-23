#ifndef LBExC_Version_H
#define LBExC_Version_H
#include "LBExC_Config.H"
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