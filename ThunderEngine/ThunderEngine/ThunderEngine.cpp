// ThunderEngine.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "ThunderEngine.h"


// This is an example of an exported variable
THUNDERENGINE_API int nThunderEngine=0;

// This is an example of an exported function.
THUNDERENGINE_API int fnThunderEngine(void)
{
    return 42;
}

// This is the constructor of a class that has been exported.
// see ThunderEngine.h for the class definition
CThunderEngine::CThunderEngine()
{
    return;
}
