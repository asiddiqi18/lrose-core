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
// Code for program ConvStrat
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
    tt->comment_hdr = tdrpStrDup("Program name: ConvStrat");
    tt->comment_text = tdrpStrDup("ConvStrat finds convective and stratiform regions within a Cartesian radar volume.");
    tt++;
    
    // Parameter 'Comment 1'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 1");
    tt->comment_hdr = tdrpStrDup("PROCESS CONTROL");
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
    tt->enum_def.nfields = 4;
    tt->enum_def.fields = (enum_field_t *)
        tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
      tt->enum_def.fields[0].name = tdrpStrDup("DEBUG_OFF");
      tt->enum_def.fields[0].val = DEBUG_OFF;
      tt->enum_def.fields[1].name = tdrpStrDup("DEBUG_NORM");
      tt->enum_def.fields[1].val = DEBUG_NORM;
      tt->enum_def.fields[2].name = tdrpStrDup("DEBUG_VERBOSE");
      tt->enum_def.fields[2].val = DEBUG_VERBOSE;
      tt->enum_def.fields[3].name = tdrpStrDup("DEBUG_EXTRA");
      tt->enum_def.fields[3].val = DEBUG_EXTRA;
    tt->single_val.e = DEBUG_OFF;
    tt++;
    
    // Parameter 'instance'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("instance");
    tt->descr = tdrpStrDup("Process instance");
    tt->help = tdrpStrDup("Used for registration with procmap.");
    tt->val_offset = (char *) &instance - &_start_;
    tt->single_val.s = tdrpStrDup("test");
    tt++;
    
    // Parameter 'mode'
    // ctype is '_mode_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = ENUM_TYPE;
    tt->param_name = tdrpStrDup("mode");
    tt->descr = tdrpStrDup("Operating mode");
    tt->help = tdrpStrDup("In REALTIME mode, the program waits for a new input file. In ARCHIVE mode, it moves through the data between the start and end times set on the command line. In FILELIST mode, it moves through the list of file names specified on the command line.");
    tt->val_offset = (char *) &mode - &_start_;
    tt->enum_def.name = tdrpStrDup("mode_t");
    tt->enum_def.nfields = 3;
    tt->enum_def.fields = (enum_field_t *)
        tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
      tt->enum_def.fields[0].name = tdrpStrDup("ARCHIVE");
      tt->enum_def.fields[0].val = ARCHIVE;
      tt->enum_def.fields[1].name = tdrpStrDup("REALTIME");
      tt->enum_def.fields[1].val = REALTIME;
      tt->enum_def.fields[2].name = tdrpStrDup("FILELIST");
      tt->enum_def.fields[2].val = FILELIST;
    tt->single_val.e = ARCHIVE;
    tt++;
    
    // Parameter 'Comment 2'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 2");
    tt->comment_hdr = tdrpStrDup("DATA INPUT");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'input_url'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("input_url");
    tt->descr = tdrpStrDup("URL for input data.");
    tt->help = tdrpStrDup("This is used in REALTIME and ARCHIVE modes only. In FILELIST mode, the file paths are specified on the command line.");
    tt->val_offset = (char *) &input_url - &_start_;
    tt->single_val.s = tdrpStrDup("mdv/input");
    tt++;
    
    // Parameter 'dbz_field_name'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("dbz_field_name");
    tt->descr = tdrpStrDup("dBZ field name in input MDV files.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &dbz_field_name - &_start_;
    tt->single_val.s = tdrpStrDup("DBZ");
    tt++;
    
    // Parameter 'Comment 3'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 3");
    tt->comment_hdr = tdrpStrDup("SPECIFYING VERTICAL LEVELS - TEMPERAURE or HEIGHT?");
    tt->comment_text = tdrpStrDup("We need to specify the vertical separation between shallow, mid-level and high clouds. We use the freezing level to separate warm clouds and cold clouds. And we use the divergence level to separate the mid-level clouds from high-level clouds such as anvil. These vertical limits can be specified as heights MSL (in km), or as temperatures. If temperatures are used, we read in the temperature profile from a model.");
    tt++;
    
    // Parameter 'vert_levels_type'
    // ctype is '_vert_levels_type_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = ENUM_TYPE;
    tt->param_name = tdrpStrDup("vert_levels_type");
    tt->descr = tdrpStrDup("How we specify the vertical levels.");
    tt->help = tdrpStrDup("If temperatures are used, we need to read in the temperature profile from a model.");
    tt->val_offset = (char *) &vert_levels_type - &_start_;
    tt->enum_def.name = tdrpStrDup("vert_levels_type_t");
    tt->enum_def.nfields = 2;
    tt->enum_def.fields = (enum_field_t *)
        tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
      tt->enum_def.fields[0].name = tdrpStrDup("VERT_LEVELS_BY_TEMP");
      tt->enum_def.fields[0].val = VERT_LEVELS_BY_TEMP;
      tt->enum_def.fields[1].name = tdrpStrDup("VERT_LEVELS_BY_HT");
      tt->enum_def.fields[1].val = VERT_LEVELS_BY_HT;
    tt->single_val.e = VERT_LEVELS_BY_HT;
    tt++;
    
    // Parameter 'temp_profile_url'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("temp_profile_url");
    tt->descr = tdrpStrDup("URL for temperature profile data, in MDV/Netcdf-CF format.");
    tt->help = tdrpStrDup("We read in the model data that is closest in time to the reflectivity data.");
    tt->val_offset = (char *) &temp_profile_url - &_start_;
    tt->single_val.s = tdrpStrDup("mdv/model");
    tt++;
    
    // Parameter 'temp_profile_field_name'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("temp_profile_field_name");
    tt->descr = tdrpStrDup("Name of temperature field in the model data. This should be in degrees C.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &temp_profile_field_name - &_start_;
    tt->single_val.s = tdrpStrDup("Temp");
    tt++;
    
    // Parameter 'temp_profile_search_margin'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("temp_profile_search_margin");
    tt->descr = tdrpStrDup("Search margin for finding the temp profile data (secs).");
    tt->help = tdrpStrDup("The temp profile must be within this number of seconds of the dbz data.");
    tt->val_offset = (char *) &temp_profile_search_margin - &_start_;
    tt->single_val.i = 21600;
    tt++;
    
    // Parameter 'shallow_threshold_ht'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("shallow_threshold_ht");
    tt->descr = tdrpStrDup("Shallow cloud height threshold (km).");
    tt->help = tdrpStrDup("Shallow cloud tops are below this height. Used if vert_levels_type = VERT_LEVELS_BY_HT.");
    tt->val_offset = (char *) &shallow_threshold_ht - &_start_;
    tt->single_val.d = 4.5;
    tt++;
    
    // Parameter 'shallow_threshold_temp'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("shallow_threshold_temp");
    tt->descr = tdrpStrDup("Shallow cloud temperature threshold (degC).");
    tt->help = tdrpStrDup("Shallow cloud tops are below this temperature. Used if vert_levels_type = VERT_LEVELS_BY_TEMP.");
    tt->val_offset = (char *) &shallow_threshold_temp - &_start_;
    tt->single_val.d = 0;
    tt++;
    
    // Parameter 'deep_threshold_ht'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("deep_threshold_ht");
    tt->descr = tdrpStrDup("Deep cloud height threshold (km).");
    tt->help = tdrpStrDup("Deep clouds extend above this height. Used if vert_levels_type = VERT_LEVELS_BY_HT.");
    tt->val_offset = (char *) &deep_threshold_ht - &_start_;
    tt->single_val.d = 8;
    tt++;
    
    // Parameter 'deep_threshold_temp'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("deep_threshold_temp");
    tt->descr = tdrpStrDup("Deep cloud temperature threshold (degC).");
    tt->help = tdrpStrDup("Deep clouds extend above this height. Used if vert_levels_type = VERT_LEVELS_BY_TEMP.");
    tt->val_offset = (char *) &deep_threshold_temp - &_start_;
    tt->single_val.d = -12;
    tt++;
    
    // Parameter 'Comment 4'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 4");
    tt->comment_hdr = tdrpStrDup("ALGORITHM PARAMETERS");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'min_valid_height'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("min_valid_height");
    tt->descr = tdrpStrDup("Min height used in analysis (km).");
    tt->help = tdrpStrDup("Only data at or above this altitude is used.");
    tt->val_offset = (char *) &min_valid_height - &_start_;
    tt->single_val.d = 0;
    tt++;
    
    // Parameter 'max_valid_height'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("max_valid_height");
    tt->descr = tdrpStrDup("Max height used in analysis (km).");
    tt->help = tdrpStrDup("Only data at or below this altitude is used.");
    tt->val_offset = (char *) &max_valid_height - &_start_;
    tt->single_val.d = 25;
    tt++;
    
    // Parameter 'min_valid_dbz'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("min_valid_dbz");
    tt->descr = tdrpStrDup("Minimum reflectivity threshold for this analysis (dBZ).");
    tt->help = tdrpStrDup("Reflectivity below this threshold is set to missing.");
    tt->val_offset = (char *) &min_valid_dbz - &_start_;
    tt->single_val.d = 10;
    tt++;
    
    // Parameter 'min_valid_volume_for_convective'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("min_valid_volume_for_convective");
    tt->descr = tdrpStrDup("Min volume of a convective region (km3).");
    tt->help = tdrpStrDup("Regions of smaller volume will be labeled SMALL.");
    tt->val_offset = (char *) &min_valid_volume_for_convective - &_start_;
    tt->single_val.d = 20;
    tt++;
    
    // Parameter 'dbz_for_echo_tops'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("dbz_for_echo_tops");
    tt->descr = tdrpStrDup("Reflectivity for determing echo tops.");
    tt->help = tdrpStrDup("Echo tops are defined as the max ht with reflectivity at or above this value.");
    tt->val_offset = (char *) &dbz_for_echo_tops - &_start_;
    tt->single_val.d = 18;
    tt++;
    
    // Parameter 'Comment 5'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 5");
    tt->comment_hdr = tdrpStrDup("COMPUTING REFLECTIVITY TEXTURE");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'texture_radius_km'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("texture_radius_km");
    tt->descr = tdrpStrDup("Radius for texture analysis (km).");
    tt->help = tdrpStrDup("We determine the reflectivity 'texture' at a point by computing the standard deviation of the square of the reflectivity, for all grid points within this radius of the central point. We then compute the square root of that sdev.");
    tt->val_offset = (char *) &texture_radius_km - &_start_;
    tt->single_val.d = 7;
    tt++;
    
    // Parameter 'min_valid_fraction_for_texture'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("min_valid_fraction_for_texture");
    tt->descr = tdrpStrDup("Minimum fraction of surrounding points for texture computations.");
    tt->help = tdrpStrDup("For a valid computation of texture, we require at least this fraction of points around the central point to have valid reflectivity.");
    tt->val_offset = (char *) &min_valid_fraction_for_texture - &_start_;
    tt->single_val.d = 0.25;
    tt++;
    
    // Parameter 'min_valid_fraction_for_fit'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("min_valid_fraction_for_fit");
    tt->descr = tdrpStrDup("Minimum fraction of surrounding points for 2D fit to DBZ.");
    tt->help = tdrpStrDup("We compute a 2D fit to the reflectivity around a grid point, to remove any systematic gradient. For a valid fit, we require at least this fraction of points around the central point to have valid reflectivity.");
    tt->val_offset = (char *) &min_valid_fraction_for_fit - &_start_;
    tt->single_val.d = 0.67;
    tt++;
    
    // Parameter 'Comment 6'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 6");
    tt->comment_hdr = tdrpStrDup("SETTING CONVECTIVE OR STRATIFORM FLAGS BASED ON CONVECTIVITY");
    tt->comment_text = tdrpStrDup("If neither is set, we flag the point as MIXED.");
    tt++;
    
    // Parameter 'min_convectivity_for_convective'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("min_convectivity_for_convective");
    tt->descr = tdrpStrDup("Minimum convectivity for convective at a point.");
    tt->help = tdrpStrDup("If the convectivity at a point exceeds this value, we set the convective flag at this point.");
    tt->val_offset = (char *) &min_convectivity_for_convective - &_start_;
    tt->single_val.d = 0.5;
    tt++;
    
    // Parameter 'max_convectivity_for_stratiform'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("max_convectivity_for_stratiform");
    tt->descr = tdrpStrDup("Maximum convectivity for stratiform at a point.");
    tt->help = tdrpStrDup("If the convectivity at a point is less than this value, we set the stratiform flag at this point. If it is above this but less than min_convectivity_for_convective we flag the point as MIXED.");
    tt->val_offset = (char *) &max_convectivity_for_stratiform - &_start_;
    tt->single_val.d = 0.4;
    tt++;
    
    // Parameter 'min_overlap_for_convective_clumps'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("min_overlap_for_convective_clumps");
    tt->descr = tdrpStrDup("Minimum grid overlap in convective regions.");
    tt->help = tdrpStrDup("A convective region is identified as a series of adjacent 'runs' of grid cells data in the EW direction. When testing for overlap, some minimum number of overlap grids must be used. This is that minimum overlap in grid units.");
    tt->val_offset = (char *) &min_overlap_for_convective_clumps - &_start_;
    tt->single_val.i = 1;
    tt++;
    
    // Parameter 'Comment 7'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 7");
    tt->comment_hdr = tdrpStrDup("DATA OUTPUT");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'output_url'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("output_url");
    tt->descr = tdrpStrDup("Output URL.");
    tt->help = tdrpStrDup("Output files are written to this URL.");
    tt->val_offset = (char *) &output_url - &_start_;
    tt->single_val.s = tdrpStrDup("mdv/stratiform");
    tt++;
    
    // Parameter 'write_partition'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("write_partition");
    tt->descr = tdrpStrDup("Write out partition fields.");
    tt->help = tdrpStrDup("This will write out the 3D, 2D and column-max partition.");
    tt->val_offset = (char *) &write_partition - &_start_;
    tt->single_val.b = pTRUE;
    tt++;
    
    // Parameter 'write_texture'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("write_texture");
    tt->descr = tdrpStrDup("Write out texture fields.");
    tt->help = tdrpStrDup("This will write out the 3D and column-max texture.");
    tt->val_offset = (char *) &write_texture - &_start_;
    tt->single_val.b = pTRUE;
    tt++;
    
    // Parameter 'write_convectivity'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("write_convectivity");
    tt->descr = tdrpStrDup("Write out convectivity fields.");
    tt->help = tdrpStrDup("This will write out the 3D and column-max convectivity.");
    tt->val_offset = (char *) &write_convectivity - &_start_;
    tt->single_val.b = pTRUE;
    tt++;
    
    // Parameter 'write_3D_dbz'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("write_3D_dbz");
    tt->descr = tdrpStrDup("Write out 3D dbz field.");
    tt->help = tdrpStrDup("This will be an echo of the input field.");
    tt->val_offset = (char *) &write_3D_dbz - &_start_;
    tt->single_val.b = pTRUE;
    tt++;
    
    // Parameter 'write_convective_dbz'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("write_convective_dbz");
    tt->descr = tdrpStrDup("Write out convective dbz field.");
    tt->help = tdrpStrDup("This will write out the 3D convective DBZ field.");
    tt->val_offset = (char *) &write_convective_dbz - &_start_;
    tt->single_val.b = pTRUE;
    tt++;
    
    // Parameter 'write_col_max_dbz'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("write_col_max_dbz");
    tt->descr = tdrpStrDup("Write out column maximum dbz field.");
    tt->help = tdrpStrDup("This is the max reflectivity at any height.");
    tt->val_offset = (char *) &write_col_max_dbz - &_start_;
    tt->single_val.b = pTRUE;
    tt++;
    
    // Parameter 'write_tops'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("write_tops");
    tt->descr = tdrpStrDup("Write out echo, convective and stratiform tops.");
    tt->help = tdrpStrDup("These are 2D fields.");
    tt->val_offset = (char *) &write_tops - &_start_;
    tt->single_val.b = pTRUE;
    tt++;
    
    // Parameter 'write_fraction_active'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("write_fraction_active");
    tt->descr = tdrpStrDup("Write out 2D field showing fraction active.");
    tt->help = tdrpStrDup("This the active fraction in the computational circle.");
    tt->val_offset = (char *) &write_fraction_active - &_start_;
    tt->single_val.b = pTRUE;
    tt++;
    
    // Parameter 'write_height_grids'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("write_height_grids");
    tt->descr = tdrpStrDup("Write out 2D field showing shallow and deep heights.");
    tt->help = tdrpStrDup("These are based on model temperature.");
    tt->val_offset = (char *) &write_height_grids - &_start_;
    tt->single_val.b = pTRUE;
    tt++;
    
    // Parameter 'write_temperature'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("write_temperature");
    tt->descr = tdrpStrDup("Write out 3D temperature field.");
    tt->help = tdrpStrDup("This comes from a model, remapped onto the reflectivity grid.");
    tt->val_offset = (char *) &write_temperature - &_start_;
    tt->single_val.b = pTRUE;
    tt++;
    
    // trailing entry has param_name set to NULL
    
    tt->param_name = NULL;
    
    return;
  
  }
