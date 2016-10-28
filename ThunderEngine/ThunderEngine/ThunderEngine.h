// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the THUNDERENGINE_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// THUNDERENGINE_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef THUNDERENGINE_EXPORTS
#define THUNDERENGINE_API __declspec(dllexport)
#else
#define THUNDERENGINE_API __declspec(dllimport)
#endif

// This class is exported from the ThunderEngine.dll
class THUNDERENGINE_API CThunderEngine {
public:
	CThunderEngine(void);
	// TODO: add your methods here.
};

extern THUNDERENGINE_API int nThunderEngine;

THUNDERENGINE_API int fnThunderEngine(void);
