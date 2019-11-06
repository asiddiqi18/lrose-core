/* *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=* */
/* ** Copyright UCAR                                                         */
/* ** University Corporation for Atmospheric Research (UCAR)                 */
/* ** National Center for Atmospheric Research (NCAR)                        */
/* ** Boulder, Colorado, USA                                                 */
/* ** BSD licence applies - redistribution and use in source and binary      */
/* ** forms, with or without modification, are permitted provided that       */
/* ** the following conditions are met:                                      */
/* ** 1) If the software is modified to produce derivative works,            */
/* ** such modified software should be clearly marked, so as not             */
/* ** to confuse it with the version available from UCAR.                    */
/* ** 2) Redistributions of source code must retain the above copyright      */
/* ** notice, this list of conditions and the following disclaimer.          */
/* ** 3) Redistributions in binary form must reproduce the above copyright   */
/* ** notice, this list of conditions and the following disclaimer in the    */
/* ** documentation and/or other materials provided with the distribution.   */
/* ** 4) Neither the name of UCAR nor the names of its contributors,         */
/* ** if any, may be used to endorse or promote products derived from        */
/* ** this software without specific prior written permission.               */
/* ** DISCLAIMER: THIS SOFTWARE IS PROVIDED 'AS IS' AND WITHOUT ANY EXPRESS  */
/* ** OR IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED      */
/* ** WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.    */
/* *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=* */
////////////////////////////////////////////
// Params.cc
//
// TDRP C++ code file for class 'Params'.
//
// Code for program Ltg2Symprod
//
// This file has been automatically
// generated by TDRP, do not modify.
//
/////////////////////////////////////////////

/**
 *
 * @file Params.cc
 *
 * @class Params
 *
 * This class is automatically generated by the Table
 * Driven Runtime Parameters (TDRP) system
 *
 * @note Source is automatically generated from
 *       paramdef file at compile time, do not modify
 *       since modifications will be overwritten.
 *
 *
 * @author Automatically generated
 *
 */
#include "Params.hh"
#include <cstring>

  ////////////////////////////////////////////
  // Default constructor
  //

  Params::Params()

  {

    // zero out table

    memset(_table, 0, sizeof(_table));

    // zero out members

    memset(&_start_, 0, &_end_ - &_start_);

    // class name

    _className = "Params";

    // initialize table

    _init();

    // set members

    tdrpTable2User(_table, &_start_);

    _exitDeferred = false;

  }

  ////////////////////////////////////////////
  // Copy constructor
  //

  Params::Params(const Params& source)

  {

    // sync the source object

    source.sync();

    // zero out table

    memset(_table, 0, sizeof(_table));

    // zero out members

    memset(&_start_, 0, &_end_ - &_start_);

    // class name

    _className = "Params";

    // copy table

    tdrpCopyTable((TDRPtable *) source._table, _table);

    // set members

    tdrpTable2User(_table, &_start_);

    _exitDeferred = false;

  }

  ////////////////////////////////////////////
  // Destructor
  //

  Params::~Params()

  {

    // free up

    freeAll();

  }

  ////////////////////////////////////////////
  // Assignment
  //

  void Params::operator=(const Params& other)

  {

    // sync the other object

    other.sync();

    // free up any existing memory

    freeAll();

    // zero out table

    memset(_table, 0, sizeof(_table));

    // zero out members

    memset(&_start_, 0, &_end_ - &_start_);

    // copy table

    tdrpCopyTable((TDRPtable *) other._table, _table);

    // set members

    tdrpTable2User(_table, &_start_);

    _exitDeferred = other._exitDeferred;

  }

  ////////////////////////////////////////////
  // loadFromArgs()
  //
  // Loads up TDRP using the command line args.
  //
  // Check usage() for command line actions associated with
  // this function.
  //
  //   argc, argv: command line args
  //
  //   char **override_list: A null-terminated list of overrides
  //     to the parameter file.
  //     An override string has exactly the format of an entry
  //     in the parameter file itself.
  //
  //   char **params_path_p:
  //     If this is non-NULL, it is set to point to the path
  //     of the params file used.
  //
  //   bool defer_exit: normally, if the command args contain a 
  //      print or check request, this function will call exit().
  //      If defer_exit is set, such an exit is deferred and the
  //      private member _exitDeferred is set.
  //      Use exidDeferred() to test this flag.
  //
  //  Returns 0 on success, -1 on failure.
  //

  int Params::loadFromArgs(int argc, char **argv,
                           char **override_list,
                           char **params_path_p,
                           bool defer_exit)
  {
    int exit_deferred;
    if (_tdrpLoadFromArgs(argc, argv,
                          _table, &_start_,
                          override_list, params_path_p,
                          _className,
                          defer_exit, &exit_deferred)) {
      return (-1);
    } else {
      if (exit_deferred) {
        _exitDeferred = true;
      }
      return (0);
    }
  }

  ////////////////////////////////////////////
  // loadApplyArgs()
  //
  // Loads up TDRP using the params path passed in, and applies
  // the command line args for printing and checking.
  //
  // Check usage() for command line actions associated with
  // this function.
  //
  //   const char *param_file_path: the parameter file to be read in
  //
  //   argc, argv: command line args
  //
  //   char **override_list: A null-terminated list of overrides
  //     to the parameter file.
  //     An override string has exactly the format of an entry
  //     in the parameter file itself.
  //
  //   bool defer_exit: normally, if the command args contain a 
  //      print or check request, this function will call exit().
  //      If defer_exit is set, such an exit is deferred and the
  //      private member _exitDeferred is set.
  //      Use exidDeferred() to test this flag.
  //
  //  Returns 0 on success, -1 on failure.
  //

  int Params::loadApplyArgs(const char *params_path,
                            int argc, char **argv,
                            char **override_list,
                            bool defer_exit)
  {
    int exit_deferred;
    if (tdrpLoadApplyArgs(params_path, argc, argv,
                          _table, &_start_,
                          override_list,
                          _className,
                          defer_exit, &exit_deferred)) {
      return (-1);
    } else {
      if (exit_deferred) {
        _exitDeferred = true;
      }
      return (0);
    }
  }

  ////////////////////////////////////////////
  // isArgValid()
  // 
  // Check if a command line arg is a valid TDRP arg.
  //

  bool Params::isArgValid(const char *arg)
  {
    return (tdrpIsArgValid(arg));
  }

  ////////////////////////////////////////////
  // isArgValid()
  // 
  // Check if a command line arg is a valid TDRP arg.
  // return number of args consumed.
  //

  int Params::isArgValidN(const char *arg)
  {
    return (tdrpIsArgValidN(arg));
  }

  ////////////////////////////////////////////
  // load()
  //
  // Loads up TDRP for a given class.
  //
  // This version of load gives the programmer the option to load
  // up more than one class for a single application. It is a
  // lower-level routine than loadFromArgs, and hence more
  // flexible, but the programmer must do more work.
  //
  //   const char *param_file_path: the parameter file to be read in.
  //
  //   char **override_list: A null-terminated list of overrides
  //     to the parameter file.
  //     An override string has exactly the format of an entry
  //     in the parameter file itself.
  //
  //   expand_env: flag to control environment variable
  //               expansion during tokenization.
  //               If TRUE, environment expansion is set on.
  //               If FALSE, environment expansion is set off.
  //
  //  Returns 0 on success, -1 on failure.
  //

  int Params::load(const char *param_file_path,
                   char **override_list,
                   int expand_env, int debug)
  {
    if (tdrpLoad(param_file_path,
                 _table, &_start_,
                 override_list,
                 expand_env, debug)) {
      return (-1);
    } else {
      return (0);
    }
  }

  ////////////////////////////////////////////
  // loadFromBuf()
  //
  // Loads up TDRP for a given class.
  //
  // This version of load gives the programmer the option to
  // load up more than one module for a single application,
  // using buffers which have been read from a specified source.
  //
  //   const char *param_source_str: a string which describes the
  //     source of the parameter information. It is used for
  //     error reporting only.
  //
  //   char **override_list: A null-terminated list of overrides
  //     to the parameter file.
  //     An override string has exactly the format of an entry
  //     in the parameter file itself.
  //
  //   const char *inbuf: the input buffer
  //
  //   int inlen: length of the input buffer
  //
  //   int start_line_num: the line number in the source which
  //     corresponds to the start of the buffer.
  //
  //   expand_env: flag to control environment variable
  //               expansion during tokenization.
  //               If TRUE, environment expansion is set on.
  //               If FALSE, environment expansion is set off.
  //
  //  Returns 0 on success, -1 on failure.
  //

  int Params::loadFromBuf(const char *param_source_str,
                          char **override_list,
                          const char *inbuf, int inlen,
                          int start_line_num,
                          int expand_env, int debug)
  {
    if (tdrpLoadFromBuf(param_source_str,
                        _table, &_start_,
                        override_list,
                        inbuf, inlen, start_line_num,
                        expand_env, debug)) {
      return (-1);
    } else {
      return (0);
    }
  }

  ////////////////////////////////////////////
  // loadDefaults()
  //
  // Loads up default params for a given class.
  //
  // See load() for more detailed info.
  //
  //  Returns 0 on success, -1 on failure.
  //

  int Params::loadDefaults(int expand_env)
  {
    if (tdrpLoad(NULL,
                 _table, &_start_,
                 NULL, expand_env, FALSE)) {
      return (-1);
    } else {
      return (0);
    }
  }

  ////////////////////////////////////////////
  // sync()
  //
  // Syncs the user struct data back into the parameter table,
  // in preparation for printing.
  //
  // This function alters the table in a consistent manner.
  // Therefore it can be regarded as const.
  //

  void Params::sync(void) const
  {
    tdrpUser2Table(_table, (char *) &_start_);
  }

  ////////////////////////////////////////////
  // print()
  // 
  // Print params file
  //
  // The modes supported are:
  //
  //   PRINT_SHORT:   main comments only, no help or descriptions
  //                  structs and arrays on a single line
  //   PRINT_NORM:    short + descriptions and help
  //   PRINT_LONG:    norm  + arrays and structs expanded
  //   PRINT_VERBOSE: long  + private params included
  //

  void Params::print(FILE *out, tdrp_print_mode_t mode)
  {
    tdrpPrint(out, _table, _className, mode);
  }

  ////////////////////////////////////////////
  // checkAllSet()
  //
  // Return TRUE if all set, FALSE if not.
  //
  // If out is non-NULL, prints out warning messages for those
  // parameters which are not set.
  //

  int Params::checkAllSet(FILE *out)
  {
    return (tdrpCheckAllSet(out, _table, &_start_));
  }

  //////////////////////////////////////////////////////////////
  // checkIsSet()
  //
  // Return TRUE if parameter is set, FALSE if not.
  //
  //

  int Params::checkIsSet(const char *paramName)
  {
    return (tdrpCheckIsSet(paramName, _table, &_start_));
  }

  ////////////////////////////////////////////
  // freeAll()
  //
  // Frees up all TDRP dynamic memory.
  //

  void Params::freeAll(void)
  {
    tdrpFreeAll(_table, &_start_);
  }

  ////////////////////////////////////////////
  // usage()
  //
  // Prints out usage message for TDRP args as passed
  // in to loadFromArgs().
  //

  void Params::usage(ostream &out)
  {
    out << "TDRP args: [options as below]\n"
        << "   [ -params/--params path ] specify params file path\n"
        << "   [ -check_params/--check_params] check which params are not set\n"
        << "   [ -print_params/--print_params [mode]] print parameters\n"
        << "     using following modes, default mode is 'norm'\n"
        << "       short:   main comments only, no help or descr\n"
        << "                structs and arrays on a single line\n"
        << "       norm:    short + descriptions and help\n"
        << "       long:    norm  + arrays and structs expanded\n"
        << "       verbose: long  + private params included\n"
        << "       short_expand:   short with env vars expanded\n"
        << "       norm_expand:    norm with env vars expanded\n"
        << "       long_expand:    long with env vars expanded\n"
        << "       verbose_expand: verbose with env vars expanded\n"
        << "   [ -tdrp_debug] debugging prints for tdrp\n"
        << "   [ -tdrp_usage] print this usage\n";
  }

  ////////////////////////////////////////////
  // arrayRealloc()
  //
  // Realloc 1D array.
  //
  // If size is increased, the values from the last array 
  // entry is copied into the new space.
  //
  // Returns 0 on success, -1 on error.
  //

  int Params::arrayRealloc(const char *param_name, int new_array_n)
  {
    if (tdrpArrayRealloc(_table, &_start_,
                         param_name, new_array_n)) {
      return (-1);
    } else {
      return (0);
    }
  }

  ////////////////////////////////////////////
  // array2DRealloc()
  //
  // Realloc 2D array.
  //
  // If size is increased, the values from the last array 
  // entry is copied into the new space.
  //
  // Returns 0 on success, -1 on error.
  //

  int Params::array2DRealloc(const char *param_name,
                             int new_array_n1,
                             int new_array_n2)
  {
    if (tdrpArray2DRealloc(_table, &_start_, param_name,
                           new_array_n1, new_array_n2)) {
      return (-1);
    } else {
      return (0);
    }
  }

  ////////////////////////////////////////////
  // _init()
  //
  // Class table initialization function.
  //
  //

  void Params::_init()

  {

    TDRPtable *tt = _table;

    // Parameter 'Comment 0'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 0");
    tt->comment_hdr = tdrpStrDup("DEBUGGING");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'debug'
    // ctype is '_debug_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = ENUM_TYPE;
    tt->param_name = tdrpStrDup("debug");
    tt->descr = tdrpStrDup("Debug option");
    tt->help = tdrpStrDup("If set, debug messages will be printed appropriately");
    tt->val_offset = (char *) &debug - &_start_;
    tt->enum_def.name = tdrpStrDup("debug_t");
    tt->enum_def.nfields = 3;
    tt->enum_def.fields = (enum_field_t *)
        tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
      tt->enum_def.fields[0].name = tdrpStrDup("DEBUG_OFF");
      tt->enum_def.fields[0].val = DEBUG_OFF;
      tt->enum_def.fields[1].name = tdrpStrDup("DEBUG_NORM");
      tt->enum_def.fields[1].val = DEBUG_NORM;
      tt->enum_def.fields[2].name = tdrpStrDup("DEBUG_VERBOSE");
      tt->enum_def.fields[2].val = DEBUG_VERBOSE;
    tt->single_val.e = DEBUG_OFF;
    tt++;
    
    // Parameter 'Comment 1'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 1");
    tt->comment_hdr = tdrpStrDup("PROCESS CONTROL");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'instance'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("instance");
    tt->descr = tdrpStrDup("Process instance.");
    tt->help = tdrpStrDup("Used for procmap registration and auto restarting.");
    tt->val_offset = (char *) &instance - &_start_;
    tt->single_val.s = tdrpStrDup("");
    tt++;
    
    // Parameter 'no_threads'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("no_threads");
    tt->descr = tdrpStrDup("Option to prevent server from using a thread per client.");
    tt->help = tdrpStrDup("For debugging purposes it it sometimes useful to suppress the use of threads. Set no_threads to TRUE for this type of debugging.");
    tt->val_offset = (char *) &no_threads - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'Comment 2'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 2");
    tt->comment_hdr = tdrpStrDup("Server details for support from ServerMgr");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'port'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("port");
    tt->descr = tdrpStrDup("Port number.");
    tt->help = tdrpStrDup("The server listens on this port for client requests.");
    tt->val_offset = (char *) &port - &_start_;
    tt->single_val.i = 5450;
    tt++;
    
    // Parameter 'qmax'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("qmax");
    tt->descr = tdrpStrDup("Max quiescent period (secs).");
    tt->help = tdrpStrDup("If the server does not receive requests for this time period, it will die gracefully. If set to -1, the server never exits.");
    tt->val_offset = (char *) &qmax - &_start_;
    tt->single_val.i = -1;
    tt++;
    
    // Parameter 'max_clients'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("max_clients");
    tt->descr = tdrpStrDup("Maximum number of clients");
    tt->help = tdrpStrDup("This is the maximum number of threads the application will produce to handle client requests.  If the maximum is reached, new clients will receive a SERVICE_DENIED error message and will have to request the data again.  If set to -1, no maximum is enforced.");
    tt->val_offset = (char *) &max_clients - &_start_;
    tt->single_val.i = 64;
    tt++;
    
    // Parameter 'Comment 3'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 3");
    tt->comment_hdr = tdrpStrDup("RENDERING PARAMETERS");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'display_color'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("display_color");
    tt->descr = tdrpStrDup("display color");
    tt->help = tdrpStrDup("Name of color suggested for using on the display.");
    tt->val_offset = (char *) &display_color - &_start_;
    tt->single_val.s = tdrpStrDup("yellow");
    tt++;
    
    // Parameter 'line_width'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("line_width");
    tt->descr = tdrpStrDup("Line thickness of icon lines");
    tt->help = tdrpStrDup("Thickness in pixels.");
    tt->val_offset = (char *) &line_width - &_start_;
    tt->single_val.i = 1;
    tt++;
    
    // Parameter 'icon_size'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("icon_size");
    tt->descr = tdrpStrDup("Size of icon in pixels");
    tt->help = tdrpStrDup("Ltg is represented by a cross. This is the length of each arm of the cross in pixels.");
    tt->val_offset = (char *) &icon_size - &_start_;
    tt->single_val.i = 4;
    tt++;
    
    // Parameter 'render_polarity'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("render_polarity");
    tt->descr = tdrpStrDup("Option to use a different icon for strikes depending on polarity.");
    tt->help = tdrpStrDup("If set, negative strikes are rendered with\na '-', , positive with '+'");
    tt->val_offset = (char *) &render_polarity - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'use_cc_icons'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("use_cc_icons");
    tt->descr = tdrpStrDup("Option to use a different icon depending on if it is could-cloud or cloud-ground.");
    tt->help = tdrpStrDup("If set, for cloud-cloud strikes the icons are tilted on their side so that '+' becomes, roughly, 'X'");
    tt->val_offset = (char *) &use_cc_icons - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'different_color_for_recent_strikes'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("different_color_for_recent_strikes");
    tt->descr = tdrpStrDup("Option to use a different color for the most recent strikes.");
    tt->help = tdrpStrDup("If set, strikes more recent than recent_strike_age are colored with the recent_strike_color.");
    tt->val_offset = (char *) &different_color_for_recent_strikes - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'recent_strike_age'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("recent_strike_age");
    tt->descr = tdrpStrDup("Max age of recent strikes - secs.");
    tt->help = tdrpStrDup("See different_color_for_recent_strikes.");
    tt->val_offset = (char *) &recent_strike_age - &_start_;
    tt->single_val.i = 1800;
    tt++;
    
    // Parameter 'recent_strike_color'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("recent_strike_color");
    tt->descr = tdrpStrDup("Color for recent strikes.");
    tt->help = tdrpStrDup("See different_color_for_recent_strikes.");
    tt->val_offset = (char *) &recent_strike_color - &_start_;
    tt->single_val.s = tdrpStrDup("gray");
    tt++;
    
    // Parameter 'useWallClockForAge'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("useWallClockForAge");
    tt->descr = tdrpStrDup("If we are coloring recent strikes differently, this\ndetermines how the strike age is calculated.");
    tt->help = tdrpStrDup("If this is set to TRUE (default) then the age of the strikes\nis calculated by taking the current (wall clock) time and\nsubtracting the valid time of the strike. This is intuitively\nobvious, however, it does mean that if archive data are being\nviewed, then none of them will be considered recent since\nall strikes will likely be old relative to the current time.\n\nSetting this parameter to FALSE means that instead of caluculating\nage relative to the wall clock time, age will be calculated\nrelative to the end of the period for which data was requested.\n\nIf you are working with CIDD, setting short_requests=TRUE; in\nthe CIDD param file means that the ages will be relative to\nthe time of the end of the current frame plus minutes_allow_after.\nSetting short_requests=FALSE; in the CIDD param file (the\ndefault) means that ages will be relative to the end of\nall the current frames (ie. the end of the movie loop)\nplus minutes_allow_after.  Niles Oien.");
    tt->val_offset = (char *) &useWallClockForAge - &_start_;
    tt->single_val.b = pTRUE;
    tt++;
    
    // Parameter 'Comment 4'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 4");
    tt->comment_hdr = tdrpStrDup("TIME LABELLING PARAMETERS");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'do_time_labelling'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("do_time_labelling");
    tt->descr = tdrpStrDup("Option to add a text label representing the time\nof each strike to the display.");
    tt->help = tdrpStrDup("Useful for WSMR ltg data.");
    tt->val_offset = (char *) &do_time_labelling - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'time_format'
    // ctype is '_time_format_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = ENUM_TYPE;
    tt->param_name = tdrpStrDup("time_format");
    tt->descr = tdrpStrDup("Time label format");
    tt->help = tdrpStrDup("Only relevant if do_time_labelling is TRUE");
    tt->val_offset = (char *) &time_format - &_start_;
    tt->enum_def.name = tdrpStrDup("time_format_t");
    tt->enum_def.nfields = 3;
    tt->enum_def.fields = (enum_field_t *)
        tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
      tt->enum_def.fields[0].name = tdrpStrDup("TIME_LABEL_HHMM");
      tt->enum_def.fields[0].val = TIME_LABEL_HHMM;
      tt->enum_def.fields[1].name = tdrpStrDup("TIME_LABEL_HHMMSS");
      tt->enum_def.fields[1].val = TIME_LABEL_HHMMSS;
      tt->enum_def.fields[2].name = tdrpStrDup("TIME_LABEL_YYYYMMDDHHMMSS");
      tt->enum_def.fields[2].val = TIME_LABEL_YYYYMMDDHHMMSS;
    tt->single_val.e = TIME_LABEL_HHMM;
    tt++;
    
    // Parameter 'time_text_offset'
    // ctype is '_text_offset_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRUCT_TYPE;
    tt->param_name = tdrpStrDup("time_text_offset");
    tt->descr = tdrpStrDup("Pixel offset values for starting the time labelling text");
    tt->help = tdrpStrDup("Only relevant if do_time_labelling is TRUE");
    tt->val_offset = (char *) &time_text_offset - &_start_;
    tt->struct_def.name = tdrpStrDup("text_offset_t");
    tt->struct_def.nfields = 2;
    tt->struct_def.fields = (struct_field_t *)
        tdrpMalloc(tt->struct_def.nfields * sizeof(struct_field_t));
      tt->struct_def.fields[0].ftype = tdrpStrDup("long");
      tt->struct_def.fields[0].fname = tdrpStrDup("x");
      tt->struct_def.fields[0].ptype = LONG_TYPE;
      tt->struct_def.fields[0].rel_offset = 
        (char *) &time_text_offset.x - (char *) &time_text_offset;
      tt->struct_def.fields[1].ftype = tdrpStrDup("long");
      tt->struct_def.fields[1].fname = tdrpStrDup("y");
      tt->struct_def.fields[1].ptype = LONG_TYPE;
      tt->struct_def.fields[1].rel_offset = 
        (char *) &time_text_offset.y - (char *) &time_text_offset;
    tt->n_struct_vals = 2;
    tt->struct_vals = (tdrpVal_t *)
        tdrpMalloc(tt->n_struct_vals * sizeof(tdrpVal_t));
      tt->struct_vals[0].l = 0;
      tt->struct_vals[1].l = 0;
    tt++;
    
    // Parameter 'time_label_color'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("time_label_color");
    tt->descr = tdrpStrDup("Color for time labels.");
    tt->help = tdrpStrDup("Only relevant if do_time_labelling is TRUE");
    tt->val_offset = (char *) &time_label_color - &_start_;
    tt->single_val.s = tdrpStrDup("gray");
    tt++;
    
    // Parameter 'Comment 5'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 5");
    tt->comment_hdr = tdrpStrDup("STRIKE TYPE (CLOUD/CLOUD vs. CLOUD/GROUND) PARAMETERS");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'do_type_labelling'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("do_type_labelling");
    tt->descr = tdrpStrDup("Option to add a text label representing\ncloud/cloud strikes. Cloud/ground strikes go unlabelled.");
    tt->help = tdrpStrDup("Useful at ATEC ranges.");
    tt->val_offset = (char *) &do_type_labelling - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'type_cloud_cloud_label'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("type_cloud_cloud_label");
    tt->descr = tdrpStrDup("Cloud/cloud label");
    tt->help = tdrpStrDup("Only relevant if do_type_labelling is TRUE");
    tt->val_offset = (char *) &type_cloud_cloud_label - &_start_;
    tt->single_val.s = tdrpStrDup("C");
    tt++;
    
    // Parameter 'type_text_offset'
    // ctype is '_text_offset_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRUCT_TYPE;
    tt->param_name = tdrpStrDup("type_text_offset");
    tt->descr = tdrpStrDup("Pixel offset values for starting cloud/cloud label");
    tt->help = tdrpStrDup("Only relevant if do_type_labelling is TRUE");
    tt->val_offset = (char *) &type_text_offset - &_start_;
    tt->struct_def.name = tdrpStrDup("text_offset_t");
    tt->struct_def.nfields = 2;
    tt->struct_def.fields = (struct_field_t *)
        tdrpMalloc(tt->struct_def.nfields * sizeof(struct_field_t));
      tt->struct_def.fields[0].ftype = tdrpStrDup("long");
      tt->struct_def.fields[0].fname = tdrpStrDup("x");
      tt->struct_def.fields[0].ptype = LONG_TYPE;
      tt->struct_def.fields[0].rel_offset = 
        (char *) &type_text_offset.x - (char *) &type_text_offset;
      tt->struct_def.fields[1].ftype = tdrpStrDup("long");
      tt->struct_def.fields[1].fname = tdrpStrDup("y");
      tt->struct_def.fields[1].ptype = LONG_TYPE;
      tt->struct_def.fields[1].rel_offset = 
        (char *) &type_text_offset.y - (char *) &type_text_offset;
    tt->n_struct_vals = 2;
    tt->struct_vals = (tdrpVal_t *)
        tdrpMalloc(tt->n_struct_vals * sizeof(tdrpVal_t));
      tt->struct_vals[0].l = 0;
      tt->struct_vals[1].l = 0;
    tt++;
    
    // Parameter 'type_label_color'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("type_label_color");
    tt->descr = tdrpStrDup("Color for type labels.");
    tt->help = tdrpStrDup("Only relevant if do_type_labelling is TRUE");
    tt->val_offset = (char *) &type_label_color - &_start_;
    tt->single_val.s = tdrpStrDup("yellow");
    tt++;
    
    // Parameter 'Comment 6'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 6");
    tt->comment_hdr = tdrpStrDup("FONT OPTIONS");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'text_vert_align'
    // ctype is '_vert_align_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = ENUM_TYPE;
    tt->param_name = tdrpStrDup("text_vert_align");
    tt->descr = tdrpStrDup("Vertical alignment for the text");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &text_vert_align - &_start_;
    tt->enum_def.name = tdrpStrDup("vert_align_t");
    tt->enum_def.nfields = 3;
    tt->enum_def.fields = (enum_field_t *)
        tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
      tt->enum_def.fields[0].name = tdrpStrDup("VERT_ALIGN_TOP");
      tt->enum_def.fields[0].val = VERT_ALIGN_TOP;
      tt->enum_def.fields[1].name = tdrpStrDup("VERT_ALIGN_CENTER");
      tt->enum_def.fields[1].val = VERT_ALIGN_CENTER;
      tt->enum_def.fields[2].name = tdrpStrDup("VERT_ALIGN_BOTTOM");
      tt->enum_def.fields[2].val = VERT_ALIGN_BOTTOM;
    tt->single_val.e = VERT_ALIGN_CENTER;
    tt++;
    
    // Parameter 'text_horiz_align'
    // ctype is '_horiz_align_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = ENUM_TYPE;
    tt->param_name = tdrpStrDup("text_horiz_align");
    tt->descr = tdrpStrDup("Horizontal alignment for the text");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &text_horiz_align - &_start_;
    tt->enum_def.name = tdrpStrDup("horiz_align_t");
    tt->enum_def.nfields = 3;
    tt->enum_def.fields = (enum_field_t *)
        tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
      tt->enum_def.fields[0].name = tdrpStrDup("HORIZ_ALIGN_LEFT");
      tt->enum_def.fields[0].val = HORIZ_ALIGN_LEFT;
      tt->enum_def.fields[1].name = tdrpStrDup("HORIZ_ALIGN_CENTER");
      tt->enum_def.fields[1].val = HORIZ_ALIGN_CENTER;
      tt->enum_def.fields[2].name = tdrpStrDup("HORIZ_ALIGN_RIGHT");
      tt->enum_def.fields[2].val = HORIZ_ALIGN_RIGHT;
    tt->single_val.e = HORIZ_ALIGN_CENTER;
    tt++;
    
    // Parameter 'text_font_style'
    // ctype is '_font_style_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = ENUM_TYPE;
    tt->param_name = tdrpStrDup("text_font_style");
    tt->descr = tdrpStrDup("Font style for the text");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &text_font_style - &_start_;
    tt->enum_def.name = tdrpStrDup("font_style_t");
    tt->enum_def.nfields = 7;
    tt->enum_def.fields = (enum_field_t *)
        tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
      tt->enum_def.fields[0].name = tdrpStrDup("TEXT_NORM");
      tt->enum_def.fields[0].val = TEXT_NORM;
      tt->enum_def.fields[1].name = tdrpStrDup("TEXT_BOLD");
      tt->enum_def.fields[1].val = TEXT_BOLD;
      tt->enum_def.fields[2].name = tdrpStrDup("TEXT_ITALICS");
      tt->enum_def.fields[2].val = TEXT_ITALICS;
      tt->enum_def.fields[3].name = tdrpStrDup("TEXT_SUBSCRIPT");
      tt->enum_def.fields[3].val = TEXT_SUBSCRIPT;
      tt->enum_def.fields[4].name = tdrpStrDup("TEXT_SUPERSCRIPT");
      tt->enum_def.fields[4].val = TEXT_SUPERSCRIPT;
      tt->enum_def.fields[5].name = tdrpStrDup("TEXT_UNDERLINE");
      tt->enum_def.fields[5].val = TEXT_UNDERLINE;
      tt->enum_def.fields[6].name = tdrpStrDup("TEXT_STRIKETHROUGH");
      tt->enum_def.fields[6].val = TEXT_STRIKETHROUGH;
    tt->single_val.e = TEXT_NORM;
    tt++;
    
    // Parameter 'text_font_size'
    // ctype is 'long'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = LONG_TYPE;
    tt->param_name = tdrpStrDup("text_font_size");
    tt->descr = tdrpStrDup("Size of font to use for text");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &text_font_size - &_start_;
    tt->single_val.l = 0;
    tt++;
    
    // Parameter 'text_background_color'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("text_background_color");
    tt->descr = tdrpStrDup("Text background color.");
    tt->help = tdrpStrDup("Set to empty string to use display background color.");
    tt->val_offset = (char *) &text_background_color - &_start_;
    tt->single_val.s = tdrpStrDup("");
    tt++;
    
    // Parameter 'font_name'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("font_name");
    tt->descr = tdrpStrDup("Font name.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &font_name - &_start_;
    tt->single_val.s = tdrpStrDup("");
    tt++;
    
    // Parameter 'Comment 7'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 7");
    tt->comment_hdr = tdrpStrDup("BOUNDING BOX OPTIONS");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'useBoundingBox'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("useBoundingBox");
    tt->descr = tdrpStrDup("Set to TRUE to only include stations within the lat-lon bounding box.");
    tt->help = tdrpStrDup("Only accept stations for which the position is inside the bounding box. Note: this will be overridden if the clientspecifies horizontal limits.");
    tt->val_offset = (char *) &useBoundingBox - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'bounding_box'
    // ctype is '_bounding_box_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRUCT_TYPE;
    tt->param_name = tdrpStrDup("bounding_box");
    tt->descr = tdrpStrDup("If useBoundingBox is true, only stations within this box will be included in the product list.");
    tt->help = tdrpStrDup("To span the international date line, specify a continuous interval using positive longitudes which exceed 180 ornegative longitudes which are less than -180. For example, min_lon = 80 and max_lon = 240 will span between 80E and 120W acrossthe Pacific.");
    tt->val_offset = (char *) &bounding_box - &_start_;
    tt->struct_def.name = tdrpStrDup("bounding_box_t");
    tt->struct_def.nfields = 4;
    tt->struct_def.fields = (struct_field_t *)
        tdrpMalloc(tt->struct_def.nfields * sizeof(struct_field_t));
      tt->struct_def.fields[0].ftype = tdrpStrDup("float");
      tt->struct_def.fields[0].fname = tdrpStrDup("min_lat");
      tt->struct_def.fields[0].ptype = FLOAT_TYPE;
      tt->struct_def.fields[0].rel_offset = 
        (char *) &bounding_box.min_lat - (char *) &bounding_box;
      tt->struct_def.fields[1].ftype = tdrpStrDup("float");
      tt->struct_def.fields[1].fname = tdrpStrDup("min_lon");
      tt->struct_def.fields[1].ptype = FLOAT_TYPE;
      tt->struct_def.fields[1].rel_offset = 
        (char *) &bounding_box.min_lon - (char *) &bounding_box;
      tt->struct_def.fields[2].ftype = tdrpStrDup("float");
      tt->struct_def.fields[2].fname = tdrpStrDup("max_lat");
      tt->struct_def.fields[2].ptype = FLOAT_TYPE;
      tt->struct_def.fields[2].rel_offset = 
        (char *) &bounding_box.max_lat - (char *) &bounding_box;
      tt->struct_def.fields[3].ftype = tdrpStrDup("float");
      tt->struct_def.fields[3].fname = tdrpStrDup("max_lon");
      tt->struct_def.fields[3].ptype = FLOAT_TYPE;
      tt->struct_def.fields[3].rel_offset = 
        (char *) &bounding_box.max_lon - (char *) &bounding_box;
    tt->n_struct_vals = 4;
    tt->struct_vals = (tdrpVal_t *)
        tdrpMalloc(tt->n_struct_vals * sizeof(tdrpVal_t));
      tt->struct_vals[0].f = -90;
      tt->struct_vals[1].f = -180;
      tt->struct_vals[2].f = 90;
      tt->struct_vals[3].f = 180;
    tt++;
    
    // trailing entry has param_name set to NULL
    
    tt->param_name = NULL;
    
    return;
  
  }
