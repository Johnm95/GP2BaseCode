//
//  FileSystem.cpp
//  GP2BaseCode
//
//  Created by John McMillan on 24/11/2015.
//
//



#include "FileSystem.h"

#ifndef _WIN32
//#include <Windows.h>
#endif

void ChangeWorkingDirectory()
{
#ifdef _WIN32
    char buffer[MAX_PATH];
    GetModuleFileName(NULL,buffer,MAX_PATH);
    string exeFullFilename(buffer);
    string exeDirectory = exeFullFilename.substr(0,exeFullFilename.find_last_of("\\"));
    SetCurrentDirectory(exeDirectory.c_str());
#endif
}