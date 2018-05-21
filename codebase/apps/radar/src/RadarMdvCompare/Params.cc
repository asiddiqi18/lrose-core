// *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*
// ** Copyright UCAR (c)
// ** University Corporation for Atmospheric Research(UCAR)
// ** National Center for Atmospheric Research(NCAR)
// ** Boulder, Colorado, USA
// *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*
////////////////////////////////////////////
// Params.cc
//
// TDRP C++ code file for class 'Params'.
//
// Code for program RadarMdvCompare
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
using namespace std;

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
    tt->comment_hdr = tdrpStrDup("RadarMdvCompare compares MDV data from 2 radars and compares the values in selected fields.");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'Comment 1'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 1");
    tt->comment_hdr = tdrpStrDup("DEBUGGING AND PROCESS CONTROL.");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'debug'
    // ctype is '_debug_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = ENUM_TYPE;
    tt->param_name = tdrpStrDup("debug");
    tt->descr = tdrpStrDup("Debug option");
    tt->help = tdrpStrDup("If set, debug messages will be printed with the appropriate level of detail.");
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
    
    // Parameter 'Comment 2'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 2");
    tt->comment_hdr = tdrpStrDup("OPERATIONAL MODE AND TRIGGERING.");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'mode'
    // ctype is '_mode_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = ENUM_TYPE;
    tt->param_name = tdrpStrDup("mode");
    tt->descr = tdrpStrDup("Operation mode");
    tt->help = tdrpStrDup("Program may be run in two modes, ARCHIVE and REALTIME.\n\nIn REALTIME mode, the analysis is performed at regular times or as new data arrives.\n\nIn ARCHIVE mode, the file list is obtained from the command line or a start and end time are specified.");
    tt->val_offset = (char *) &mode - &_start_;
    tt->enum_def.name = tdrpStrDup("mode_t");
    tt->enum_def.nfields = 2;
    tt->enum_def.fields = (enum_field_t *)
        tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
      tt->enum_def.fields[0].name = tdrpStrDup("ARCHIVE");
      tt->enum_def.fields[0].val = ARCHIVE;
      tt->enum_def.fields[1].name = tdrpStrDup("REALTIME");
      tt->enum_def.fields[1].val = REALTIME;
    tt->single_val.e = REALTIME;
    tt++;
    
    // Parameter 'trigger'
    // ctype is '_trigger_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = ENUM_TYPE;
    tt->param_name = tdrpStrDup("trigger");
    tt->descr = tdrpStrDup("Trigger mechanism.");
    tt->help = tdrpStrDup("\nTIME_TRIGGER: program is triggered at constant time intervals - see time_trigger_interval.\n\nFILE_TRIGGER: the program watches the first input_dir and triggers based on data in that directory.");
    tt->val_offset = (char *) &trigger - &_start_;
    tt->enum_def.name = tdrpStrDup("trigger_t");
    tt->enum_def.nfields = 2;
    tt->enum_def.fields = (enum_field_t *)
        tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
      tt->enum_def.fields[0].name = tdrpStrDup("TIME_TRIGGER");
      tt->enum_def.fields[0].val = TIME_TRIGGER;
      tt->enum_def.fields[1].name = tdrpStrDup("FILE_TRIGGER");
      tt->enum_def.fields[1].val = FILE_TRIGGER;
    tt->single_val.e = TIME_TRIGGER;
    tt++;
    
    // Parameter 'time_trigger_interval'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("time_trigger_interval");
    tt->descr = tdrpStrDup("Interval for TIME_TRIGGER - secs.");
    tt->help = tdrpStrDup("For TIME_TRIGGER, this is the interval between trigger events. Time triggers are synchronized to the hour, and occur at constant intervals thereafter.");
    tt->val_offset = (char *) &time_trigger_interval - &_start_;
    tt->single_val.i = 300;
    tt++;
    
    // Parameter 'time_trigger_offset'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("time_trigger_offset");
    tt->descr = tdrpStrDup("Time trigger offset - secs.");
    tt->help = tdrpStrDup("Time triggers occur on the hour and at constant intervals thereafter until the next hour. This parameters allows you to schedule the trigger to be offset from the anchored time by the specified number of secs. For example, if you set time_trigger_interval to 600 (10 mins) and time_trigger_offset to 420 (7 minutes), the trigger will occur at 7, 17, 27, 37, 47 and 57 mins after the hour.");
    tt->val_offset = (char *) &time_trigger_offset - &_start_;
    tt->single_val.i = 0;
    tt++;
    
    // Parameter 'time_trigger_margin'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("time_trigger_margin");
    tt->descr = tdrpStrDup("Max time diff for searching for files relative to the trigger time - secs.");
    tt->help = tdrpStrDup("When matching files up with the trigger time, the difference between the trigger time and file time must be less than this margin.");
    tt->val_offset = (char *) &time_trigger_margin - &_start_;
    tt->single_val.i = 600;
    tt++;
    
    // Parameter 'min_time_between_file_triggers'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("min_time_between_file_triggers");
    tt->descr = tdrpStrDup("Minimum time between triggering in REALTIME FILE_TRIGGER mode, in seconds.");
    tt->help = tdrpStrDup("This prevents the arrival of files in FILE_TRIGGER mode from triggering at intervals less than this amount.");
    tt->val_offset = (char *) &min_time_between_file_triggers - &_start_;
    tt->single_val.i = 120;
    tt++;
    
    // Parameter 'max_realtime_valid_age'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("max_realtime_valid_age");
    tt->descr = tdrpStrDup("Maximum file age in REALTIME file triggered mode, seconds.");
    tt->help = tdrpStrDup("Applies to all URLs specified.");
    tt->val_offset = (char *) &max_realtime_valid_age - &_start_;
    tt->single_val.i = 600;
    tt++;
    
    // Parameter 'sleep_after_trigger'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("sleep_after_trigger");
    tt->descr = tdrpStrDup("Number of seconds to sleep after triggering before processing the data. The intent is to allow realtime URLs that come in nearly simultaneously (satellite) to have a chance to catch up.");
    tt->help = tdrpStrDup("Only applies in REALTIME mode.");
    tt->val_offset = (char *) &sleep_after_trigger - &_start_;
    tt->single_val.i = 0;
    tt++;
    
    // Parameter 'Comment 3'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 3");
    tt->comment_hdr = tdrpStrDup("INPUT DATA SPECIFICATIONS.");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'primary_url'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("primary_url");
    tt->descr = tdrpStrDup("URL for primary radar.");
    tt->help = tdrpStrDup("This is the URL from which the trigger is derived.");
    tt->val_offset = (char *) &primary_url - &_start_;
    tt->single_val.s = tdrpStrDup("mdvp:://localhost::mdv/radar1/cart");
    tt++;
    
    // Parameter 'primary_field_name'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("primary_field_name");
    tt->descr = tdrpStrDup("Field name for primary data.");
    tt->help = tdrpStrDup("Only this field will be used for comparison.");
    tt->val_offset = (char *) &primary_field_name - &_start_;
    tt->single_val.s = tdrpStrDup("DBZ");
    tt++;
    
    // Parameter 'secondary_url'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("secondary_url");
    tt->descr = tdrpStrDup("URL for secondary radar.");
    tt->help = tdrpStrDup("Data from this url will be compared against the primary.");
    tt->val_offset = (char *) &secondary_url - &_start_;
    tt->single_val.s = tdrpStrDup("mdvp:://localhost::mdv/radar1/cart");
    tt++;
    
    // Parameter 'secondary_field_name'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("secondary_field_name");
    tt->descr = tdrpStrDup("Field name for secondary data.");
    tt->help = tdrpStrDup("Only this field will be used for comparison.");
    tt->val_offset = (char *) &secondary_field_name - &_start_;
    tt->single_val.s = tdrpStrDup("DBZ");
    tt++;
    
    // Parameter 'max_time_diff'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("max_time_diff");
    tt->descr = tdrpStrDup("Maximum time difference, in secs, between the primary and secondary fields.");
    tt->help = tdrpStrDup("if the time difference exceeds this value, the comparison will not be performed.");
    tt->val_offset = (char *) &max_time_diff - &_start_;
    tt->single_val.i = 300;
    tt++;
    
    // Parameter 'Comment 4'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 4");
    tt->comment_hdr = tdrpStrDup("GEOMETRIC LIMITS.");
    tt->comment_text = tdrpStrDup("Limits for the analysis region.");
    tt++;
    
    // Parameter 'max_vlevel_diff'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("max_vlevel_diff");
    tt->descr = tdrpStrDup("Max difference in vlevels for comparison.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &max_vlevel_diff - &_start_;
    tt->single_val.d = 0.01;
    tt++;
    
    // Parameter 'set_bounding_box'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("set_bounding_box");
    tt->descr = tdrpStrDup("Option to set bounding box.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &set_bounding_box - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'bounding_box'
    // ctype is '_bounding_box_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRUCT_TYPE;
    tt->param_name = tdrpStrDup("bounding_box");
    tt->descr = tdrpStrDup("Horizontal limits for analysis.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &bounding_box - &_start_;
    tt->struct_def.name = tdrpStrDup("bounding_box_t");
    tt->struct_def.nfields = 4;
    tt->struct_def.fields = (struct_field_t *)
        tdrpMalloc(tt->struct_def.nfields * sizeof(struct_field_t));
      tt->struct_def.fields[0].ftype = tdrpStrDup("double");
      tt->struct_def.fields[0].fname = tdrpStrDup("min_lat");
      tt->struct_def.fields[0].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[0].rel_offset = 
        (char *) &bounding_box.min_lat - (char *) &bounding_box;
      tt->struct_def.fields[1].ftype = tdrpStrDup("double");
      tt->struct_def.fields[1].fname = tdrpStrDup("min_lon");
      tt->struct_def.fields[1].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[1].rel_offset = 
        (char *) &bounding_box.min_lon - (char *) &bounding_box;
      tt->struct_def.fields[2].ftype = tdrpStrDup("double");
      tt->struct_def.fields[2].fname = tdrpStrDup("max_lat");
      tt->struct_def.fields[2].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[2].rel_offset = 
        (char *) &bounding_box.max_lat - (char *) &bounding_box;
      tt->struct_def.fields[3].ftype = tdrpStrDup("double");
      tt->struct_def.fields[3].fname = tdrpStrDup("max_lon");
      tt->struct_def.fields[3].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[3].rel_offset = 
        (char *) &bounding_box.max_lon - (char *) &bounding_box;
    tt->n_struct_vals = 4;
    tt->struct_vals = (tdrpVal_t *)
        tdrpMalloc(tt->n_struct_vals * sizeof(tdrpVal_t));
      tt->struct_vals[0].d = -90;
      tt->struct_vals[1].d = -180;
      tt->struct_vals[2].d = 90;
      tt->struct_vals[3].d = 180;
    tt++;
    
    // Parameter 'request_composite'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("request_composite");
    tt->descr = tdrpStrDup("Option to request composite.");
    tt->help = tdrpStrDup("This computes the composite of the data in the vertical, which is the maximum value in the column. If combined with set_vlevel_limits, it will compute the maximum within the vlevel limits specified.");
    tt->val_offset = (char *) &request_composite - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'set_vlevel_limits'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("set_vlevel_limits");
    tt->descr = tdrpStrDup("Option to set vertical limits");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &set_vlevel_limits - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'lower_vlevel'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("lower_vlevel");
    tt->descr = tdrpStrDup("Lower vlevel limit.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &lower_vlevel - &_start_;
    tt->single_val.d = 0;
    tt++;
    
    // Parameter 'upper_vlevel'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("upper_vlevel");
    tt->descr = tdrpStrDup("Upper vlevel limit.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &upper_vlevel - &_start_;
    tt->single_val.d = 100;
    tt++;
    
    // Parameter 'set_range_limits'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("set_range_limits");
    tt->descr = tdrpStrDup("Option to set range limits");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &set_range_limits - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'min_range_km'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("min_range_km");
    tt->descr = tdrpStrDup("Min range from radar in km.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &min_range_km - &_start_;
    tt->single_val.d = 0;
    tt++;
    
    // Parameter 'max_range_km'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("max_range_km");
    tt->descr = tdrpStrDup("Max range from radar in km.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &max_range_km - &_start_;
    tt->single_val.d = 0;
    tt++;
    
    // Parameter 'Comment 5'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 5");
    tt->comment_hdr = tdrpStrDup("COMPARISON DETAILS.");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'min_value_for_diff'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("min_value_for_diff");
    tt->descr = tdrpStrDup("Minimum value for valid comparison.");
    tt->help = tdrpStrDup("The field value for both the primary and secondary radars must exceed this value for the diff to be computed.");
    tt->val_offset = (char *) &min_value_for_diff - &_start_;
    tt->single_val.d = 0;
    tt++;
    
    // Parameter 'max_valid_diff'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("max_valid_diff");
    tt->descr = tdrpStrDup("Maximum valid value for difference.");
    tt->help = tdrpStrDup("If the difference is greater than this, it is ignored.");
    tt->val_offset = (char *) &max_valid_diff - &_start_;
    tt->single_val.d = 10;
    tt++;
    
    // Parameter 'min_valid_diff'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("min_valid_diff");
    tt->descr = tdrpStrDup("Minimum valid value for difference.");
    tt->help = tdrpStrDup("If the difference is less than this, it is ignored.");
    tt->val_offset = (char *) &min_valid_diff - &_start_;
    tt->single_val.d = -10;
    tt++;
    
    // Parameter 'min_number_of_pts_above_threshold'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("min_number_of_pts_above_threshold");
    tt->descr = tdrpStrDup("Minimum number of pts with values above threshold.");
    tt->help = tdrpStrDup("In computing the stats, The field value for both the primary and secondary radars must exceed this value for the diff to be computed.");
    tt->val_offset = (char *) &min_number_of_pts_above_threshold - &_start_;
    tt->single_val.i = 1000;
    tt++;
    
    // Parameter 'threshold_value_for_min_pts'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("threshold_value_for_min_pts");
    tt->descr = tdrpStrDup("Threshold value for checking if stats are valid.");
    tt->help = tdrpStrDup("For the stats to be considered valid, we need at least min_number_of_pts_above_threshold to exceed this threshold. For example, we may say we want at least 1000 points to have DBZ values in excess of 30 DBZ for the stats to be considered valid.");
    tt->val_offset = (char *) &threshold_value_for_min_pts - &_start_;
    tt->single_val.d = 30;
    tt++;
    
    // Parameter 'Comment 6'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 6");
    tt->comment_hdr = tdrpStrDup("OUTPUT OPTIONS.");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'output_dir'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("output_dir");
    tt->descr = tdrpStrDup("Directory for output files.");
    tt->help = tdrpStrDup("Files will be named by the date.");
    tt->val_offset = (char *) &output_dir - &_start_;
    tt->single_val.s = tdrpStrDup("$(DATA_DIR)/inter_radar_comparison");
    tt++;
    
    // Parameter 'output_file_prefix'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("output_file_prefix");
    tt->descr = tdrpStrDup("Prefix for files.");
    tt->help = tdrpStrDup("Files will start with this prefix, then the date, and then the extension.");
    tt->val_offset = (char *) &output_file_prefix - &_start_;
    tt->single_val.s = tdrpStrDup("Marburg_minus_MtStapl");
    tt++;
    
    // Parameter 'output_file_ext'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("output_file_ext");
    tt->descr = tdrpStrDup("Extension for output files.");
    tt->help = tdrpStrDup("File will start with the prefix, then the date, and then this extension.");
    tt->val_offset = (char *) &output_file_ext - &_start_;
    tt->single_val.s = tdrpStrDup("txt");
    tt++;
    
    // Parameter 'write_output_stats'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("write_output_stats");
    tt->descr = tdrpStrDup("Option to print output stats to stdout");
    tt->help = tdrpStrDup("The stats summarise the difference between the primary and secondary data sets.");
    tt->val_offset = (char *) &write_output_stats - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'write_output_table'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("write_output_table");
    tt->descr = tdrpStrDup("Option to print output table to stdout");
    tt->help = tdrpStrDup("Columns will be 'lat lon alt primary secondary diff'. Columns are space-delimted.");
    tt->val_offset = (char *) &write_output_table - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'append_to_summary_file'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("append_to_summary_file");
    tt->descr = tdrpStrDup("Option to append to a global summary file");
    tt->help = tdrpStrDup("Columns will be yyyy mm dd hh mm ss unixsecs unixdays count mean_diff sdev_diff median_diff. Columns are space-delimted.");
    tt->val_offset = (char *) &append_to_summary_file - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'write_results_to_spdb'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("write_results_to_spdb");
    tt->descr = tdrpStrDup("Option to write out analysis results to SPDB.");
    tt->help = tdrpStrDup("The results will be written in XML, stored in SPDB. The data can then be retrieved for plotting or other purposes.");
    tt->val_offset = (char *) &write_results_to_spdb - &_start_;
    tt->single_val.b = pTRUE;
    tt++;
    
    // Parameter 'spdb_output_url'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("spdb_output_url");
    tt->descr = tdrpStrDup("URL for writing results to SPDB XML.");
    tt->help = tdrpStrDup("For local writes, specify the directory. For remote writes, specify the full url: spdbp:://host::dir");
    tt->val_offset = (char *) &spdb_output_url - &_start_;
    tt->single_val.s = tdrpStrDup("/tmp/spdb/radar_mdv_compare");
    tt++;
    
    // trailing entry has param_name set to NULL
    
    tt->param_name = NULL;
    
    return;
  
  }
