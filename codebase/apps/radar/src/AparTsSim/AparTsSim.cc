// *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=* 
// ** Copyright UCAR (c) 1990 - 2016                                         
// ** University Corporation for Atmospheric Research (UCAR)                 
// ** National Center for Atmospheric Research (NCAR)                        
// ** Boulder, Colorado, USA                                                 
// ** BSD licence applies - redistribution and use in source and binary      
// ** forms, with or without modification, are permitted provided that       
// ** the following conditions are met:                                      
// ** 1) If the software is modified to produce derivative works,            
// ** such modified software should be clearly marked, so as not             
// ** to confuse it with the version available from UCAR.                    
// ** 2) Redistributions of source code must retain the above copyright      
// ** notice, this list of conditions and the following disclaimer.          
// ** 3) Redistributions in binary form must reproduce the above copyright   
// ** notice, this list of conditions and the following disclaimer in the    
// ** documentation and/or other materials provided with the distribution.   
// ** 4) Neither the name of UCAR nor the names of its contributors,         
// ** if any, may be used to endorse or promote products derived from        
// ** this software without specific prior written permission.               
// ** DISCLAIMER: THIS SOFTWARE IS PROVIDED "AS IS" AND WITHOUT ANY EXPRESS  
// ** OR IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED      
// ** WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.    
// *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=* 
///////////////////////////////////////////////////////////////
// AparTsSim.cc
//
// Mike Dixon, EOL, NCAR, P.O.Box 3000, Boulder, CO, 80307-3000, USA
//
// Aug 2019
//
///////////////////////////////////////////////////////////////
//
// AparTsSim reads IWRF data from specified files, converts
// the data to APAR TS format, and writes the
// converted files to a specified location
//
////////////////////////////////////////////////////////////////

#include <iostream>
#include <cerrno>
#include <cstdio>
#include <unistd.h>

#include "AparTsSim.hh"
#include "ConvertToApar.hh"
#include "WriteToUdp.hh"

using namespace std;

// Constructor

AparTsSim::AparTsSim(int argc, char **argv)
  
{

  isOK = true;
  
  // set programe name
  
  _progName = "AparTsSim";
  
  // get command line args

  if (_args.parse(argc, argv, _progName)) {
    cerr << "ERROR: " << _progName << endl;
    cerr << "Problem with command line args" << endl;
    isOK = false;
    return;
  }

  // get TDRP params
  
  _paramsPath = (char *) "unknown";
  if (_params.loadFromArgs(argc, argv, _args.override.list,
			   &_paramsPath)) {
    cerr << "ERROR: " << _progName << endl;
    cerr << "Problem with TDRP parameters" << endl;
    isOK = false;
    return;
  }
  
}

// destructor

AparTsSim::~AparTsSim()

{
  
}

//////////////////////////////////////////////////
// Run

int AparTsSim::Run ()
{
  
  PMU_auto_register("Run");
  
  if (_params.debug >= Params::DEBUG_EXTRA) {
    cerr << "Running AparTsSim - extra verbose debug mode" << endl;
  } else if (_params.debug >= Params::DEBUG_VERBOSE) {
    cerr << "Running AparTsSim - verbose debug mode" << endl;
  } else if (_params.debug) {
    cerr << "Running AparTsSim - debug mode" << endl;
  }

  if (_params.output_mode == Params::OUTPUT_FILES) {
    return _runFileMode();
  } else {
    return _runUdpMode();
  }

}

//////////////////////////////////////////////////
// Run in file mode

int AparTsSim::_runFileMode()
{
  
  PMU_auto_register("_runFileMode");
  
  ConvertToApar convertToApar(_progName,
                              _params,
                              _args.inputFileList);
  
  return convertToApar.Run();

}

//////////////////////////////////////////////////
// Run in UDP mode

int AparTsSim::_runUdpMode()
{
  
  PMU_auto_register("_runUdpMode");
 
  WriteToUdp writeToUdp(_progName,
                        _params,
                        _args.inputFileList);

  return writeToUdp.Run();

}

