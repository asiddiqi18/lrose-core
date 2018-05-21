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
// Code for program LdataWatcher
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
    tt->comment_hdr = tdrpStrDup("LdataWatcher program");
    tt->comment_text = tdrpStrDup("LdataWatcher watches ldata file in a directory, optionally registers the latest time with the DataMapper, optionally writes an FMQ, and optionally runs a script.");
    tt++;
    
    // Parameter 'Comment 1'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 1");
    tt->comment_hdr = tdrpStrDup("DEBUGGING AND PROCESS CONTROL");
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
    
    // Parameter 'procmap_register_interval'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("procmap_register_interval");
    tt->descr = tdrpStrDup("Register interval for procmap - secs");
    tt->help = tdrpStrDup("If the script takes longer than 60 secs to complete, you will need to set this to a higher value to avoid the process being killed and restarted by the auto_restarter.");
    tt->val_offset = (char *) &procmap_register_interval - &_start_;
    tt->single_val.i = 60;
    tt++;
    
    // Parameter 'Comment 2'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 2");
    tt->comment_hdr = tdrpStrDup("INPUT DATA");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'inputPath'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("inputPath");
    tt->descr = tdrpStrDup("Directory path for input data.");
    tt->help = tdrpStrDup("This directory is watched for new _latest_data_info files.");
    tt->val_offset = (char *) &inputPath - &_start_;
    tt->single_val.s = tdrpStrDup("./latest_data");
    tt++;
    
    // Parameter 'use_url'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("use_url");
    tt->descr = tdrpStrDup("Option to read from DsLdataServer.");
    tt->help = tdrpStrDup("If TRUE, inputUrl will be used. If FALSE, inputPath will be used.");
    tt->val_offset = (char *) &use_url - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'inputUrl'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("inputUrl");
    tt->descr = tdrpStrDup("Directory path for input data.");
    tt->help = tdrpStrDup("This directory is watched for new _latest_data_info files.");
    tt->val_offset = (char *) &inputUrl - &_start_;
    tt->single_val.s = tdrpStrDup("");
    tt++;
    
    // Parameter 'max_realtime_valid_age'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("max_realtime_valid_age");
    tt->descr = tdrpStrDup("Maximum age for files, realtime mode, seconds");
    tt->help = tdrpStrDup("Default is 15 minutes.");
    tt->val_offset = (char *) &max_realtime_valid_age - &_start_;
    tt->single_val.i = 900;
    tt++;
    
    // Parameter 'read_ldata_fmq_from_start'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("read_ldata_fmq_from_start");
    tt->descr = tdrpStrDup("Option to read FMQ for latest_data_info from start.");
    tt->help = tdrpStrDup("If TRUE, the all of the entries in the FMQ will be read, from the start. This is useful for archive mode, or for debugging what is in an FMQ.");
    tt->val_offset = (char *) &read_ldata_fmq_from_start - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'save_read_state'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("save_read_state");
    tt->descr = tdrpStrDup("Option to save read state.");
    tt->help = tdrpStrDup("If TRUE, each time a read is successful, a _latest_read_info XML file will be written to a tmp directory, so that read state can be maintained in case the application crashes");
    tt->val_offset = (char *) &save_read_state - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'Comment 3'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 3");
    tt->comment_hdr = tdrpStrDup("REGISTER WITH DATA MAPPER WHEN DATA ARRIVES");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'register_with_datamapper'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("register_with_datamapper");
    tt->descr = tdrpStrDup("Option to register the data set with the DataMapper.");
    tt->help = tdrpStrDup("If TRUE, when a new _latest_data_info file arrives, that info will be used to register with the DataMapper on the local machine.");
    tt->val_offset = (char *) &register_with_datamapper - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'data_type'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("data_type");
    tt->descr = tdrpStrDup("Data type - typically mdv, spdb, www, netCDF");
    tt->help = tdrpStrDup("Not used if set to null, or if register_with_datamapper is false.");
    tt->val_offset = (char *) &data_type - &_start_;
    tt->single_val.s = tdrpStrDup("");
    tt++;
    
    // Parameter 'Comment 4'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 4");
    tt->comment_hdr = tdrpStrDup("WRITE FMQ ON BEHALF OF DATA SET WRITER WHEN DATA ARRIVES");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'write_fmq'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("write_fmq");
    tt->descr = tdrpStrDup("Option to write out an FMQ which matches the _latest_data_info.");
    tt->help = tdrpStrDup("If TRUE, the info in the ldata file will be written to an FMQ in the same directory. The intention is to provide a mechanism for adding the FMQ to directories of data arriving from clients which cannot write the FMQ directly.");
    tt->val_offset = (char *) &write_fmq - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'Comment 5'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 5");
    tt->comment_hdr = tdrpStrDup("CALL SCRIPT WHEN DATA ARRIVES");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'call_script'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("call_script");
    tt->descr = tdrpStrDup("Option to spawn a script when a new file is detected.");
    tt->help = tdrpStrDup("If TRUE, the script 'script_to_call' will be called with the following args derived from the latest_data_info file: unix_time, year, month, day, hour, min, sec, file_ext, user_info1, user_info2, n_fcasts, lead_time_1, lead_time_2, ... If n_fcasts is 0, that will be the last arg and there will be no lead times.");
    tt->val_offset = (char *) &call_script - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'script_style'
    // ctype is '_script_style_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = ENUM_TYPE;
    tt->param_name = tdrpStrDup("script_style");
    tt->descr = tdrpStrDup("Type of script to call.");
    tt->help = tdrpStrDup("\nThe original, and default, behavior is to call a script with an ordered list of arguments - SCRIPT_WITH_ORDERED_ARGS. This is difficult to maintain, since adding extra args can cause the script to fail if the order changes. The new option, SCRIPT_WITH_COMMAND_LINE_OPTIONS, precedes each argument with a '-arg' style command line argument, so that order is not longer important, and extra args can be added without causing problems for client scripts.\n\nFor SCRIPT_WITH_ORDERED_ARGS, the args are in the following order:\n  unix_time, year, month, day, hour, min, sec, file_ext, user_info1, user_info2, fcast_flag. fcast_flag will be 1 if this is a forecast data set, 0 if not. If fcast_flag is set, the next arg will be the lead_time. If not, fcast_flag is the last parameter. \nIf include_data_path is true, 2 extra args will be added at the start of the list: the full data path and the directory relative to $RAP_DATA_DIR. Therefore the arg list will be:\n  full_data_path, rel_dir, unix_time ...\nFor the late_data_script, the data_late_secs parameter will be added as the first arg. Therefore the arg list will be:\n  data_late_secs, full_data_path, rel_dir, unix_time, ....\n\nFor SCRIPT_WITH_COMMAND_LINE_OPTIONS, the following command line args will be included, in no particular order:\n  -unix_time ? valid time in unix time\n  -year ? valid time year\n  -month ? valid time month\n  -day ? valid time day\n  -hour ? valid time hour\n  -min ? valid time min\n  -sec ? valid time sec\n  -rap_data_dir ? RAP_DATA_DIR env var\n  -abs_dir_path ? absolute path of directory containing _latest_data_info\n  -full_path ? same as abs_dir_path, backward-compatibility\n  -rel_dir ? rel path of directory containing _latest_data_info\n             relative to RAP_DATA_DIR\n  -sub_dir ? same as rel_dir, backward-compatibility\n  -rel_data_path ? path of data file rel to _latest_data_info\n  -file_ext ? file extension\n  -data_type ? data type string, for DataMapper\n  -user_info1 ? info supplied by writer\n  -user_info2 ? info supplied by writer\n  -is_forecast ? true/false\n  -forecast_lead_secs ? lead time in secs, if applicable\n  -writer ? application writing the file\n  -data_late_secs ? echo of data_late_secs parameters\nand each arg will be followed by its respective value.\n\nFor SCRIPT_WITH_COMMAND_LINE_OPTIONS_DOUBLE_DASH, the command line arguments are included as described for SCRIPT_WITH_COMMAND_LINE_OPTIONS except that the option names are preceded by two dashes rather than one for use with languages like python.\n\nFor SCRIPT_WITH_SPECIFIED_ORDERED_ARGS, only the options specified in the script_options parameter will be included on the command line. The options will be included in the order specified with no preceding tags.\n\nFor SCRIPT_WITH_SPECIFIED_OPTIONS, only the options specified in the script_options parameter will be included on the command line.\n\nFor SCRIPT_WITH_SPECIFIED_OPTIONS_DOUBLE_DASH, only the options specified in the script_options parameter will be included on the command line and the options will be preceded with a double dash for use by languages like python.\n\n");
    tt->val_offset = (char *) &script_style - &_start_;
    tt->enum_def.name = tdrpStrDup("script_style_t");
    tt->enum_def.nfields = 6;
    tt->enum_def.fields = (enum_field_t *)
        tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
      tt->enum_def.fields[0].name = tdrpStrDup("SCRIPT_WITH_ORDERED_ARGS");
      tt->enum_def.fields[0].val = SCRIPT_WITH_ORDERED_ARGS;
      tt->enum_def.fields[1].name = tdrpStrDup("SCRIPT_WITH_COMMAND_LINE_OPTIONS");
      tt->enum_def.fields[1].val = SCRIPT_WITH_COMMAND_LINE_OPTIONS;
      tt->enum_def.fields[2].name = tdrpStrDup("SCRIPT_WITH_COMMAND_LINE_OPTIONS_DOUBLE_DASH");
      tt->enum_def.fields[2].val = SCRIPT_WITH_COMMAND_LINE_OPTIONS_DOUBLE_DASH;
      tt->enum_def.fields[3].name = tdrpStrDup("SCRIPT_WITH_SPECIFIED_ORDERED_ARGS");
      tt->enum_def.fields[3].val = SCRIPT_WITH_SPECIFIED_ORDERED_ARGS;
      tt->enum_def.fields[4].name = tdrpStrDup("SCRIPT_WITH_SPECIFIED_OPTIONS");
      tt->enum_def.fields[4].val = SCRIPT_WITH_SPECIFIED_OPTIONS;
      tt->enum_def.fields[5].name = tdrpStrDup("SCRIPT_WITH_SPECIFIED_OPTIONS_DOUBLE_DASH");
      tt->enum_def.fields[5].val = SCRIPT_WITH_SPECIFIED_OPTIONS_DOUBLE_DASH;
    tt->single_val.e = SCRIPT_WITH_ORDERED_ARGS;
    tt++;
    
    // Parameter 'script_options'
    // ctype is '_script_options_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = ENUM_TYPE;
    tt->param_name = tdrpStrDup("script_options");
    tt->descr = tdrpStrDup("List of options to include on the script command line.");
    tt->help = tdrpStrDup("Only used if script_style is set to SCRIPT_WITH_SPECIFIED_OPTIONS or SCRIPT_WITH_SPECIFIED_OPTIONS_DOUBLE_DASH.");
    tt->array_offset = (char *) &_script_options - &_start_;
    tt->array_n_offset = (char *) &script_options_n - &_start_;
    tt->is_array = TRUE;
    tt->array_len_fixed = FALSE;
    tt->array_elem_size = sizeof(script_options_t);
    tt->array_n = 1;
    tt->enum_def.name = tdrpStrDup("script_options_t");
    tt->enum_def.nfields = 26;
    tt->enum_def.fields = (enum_field_t *)
        tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
      tt->enum_def.fields[0].name = tdrpStrDup("OPTION_UNIX_TIME");
      tt->enum_def.fields[0].val = OPTION_UNIX_TIME;
      tt->enum_def.fields[1].name = tdrpStrDup("OPTION_YEAR");
      tt->enum_def.fields[1].val = OPTION_YEAR;
      tt->enum_def.fields[2].name = tdrpStrDup("OPTION_MONTH");
      tt->enum_def.fields[2].val = OPTION_MONTH;
      tt->enum_def.fields[3].name = tdrpStrDup("OPTION_DAY");
      tt->enum_def.fields[3].val = OPTION_DAY;
      tt->enum_def.fields[4].name = tdrpStrDup("OPTION_HOUR");
      tt->enum_def.fields[4].val = OPTION_HOUR;
      tt->enum_def.fields[5].name = tdrpStrDup("OPTION_MIN");
      tt->enum_def.fields[5].val = OPTION_MIN;
      tt->enum_def.fields[6].name = tdrpStrDup("OPTION_SEC");
      tt->enum_def.fields[6].val = OPTION_SEC;
      tt->enum_def.fields[7].name = tdrpStrDup("OPTION_RAP_DATA_DIR");
      tt->enum_def.fields[7].val = OPTION_RAP_DATA_DIR;
      tt->enum_def.fields[8].name = tdrpStrDup("OPTION_FULL_PATH");
      tt->enum_def.fields[8].val = OPTION_FULL_PATH;
      tt->enum_def.fields[9].name = tdrpStrDup("OPTION_ABS_DIR_PATH");
      tt->enum_def.fields[9].val = OPTION_ABS_DIR_PATH;
      tt->enum_def.fields[10].name = tdrpStrDup("OPTION_SUB_DIR");
      tt->enum_def.fields[10].val = OPTION_SUB_DIR;
      tt->enum_def.fields[11].name = tdrpStrDup("OPTION_REL_DIR");
      tt->enum_def.fields[11].val = OPTION_REL_DIR;
      tt->enum_def.fields[12].name = tdrpStrDup("OPTION_REL_DATA_PATH");
      tt->enum_def.fields[12].val = OPTION_REL_DATA_PATH;
      tt->enum_def.fields[13].name = tdrpStrDup("OPTION_FULL_FILE_PATH");
      tt->enum_def.fields[13].val = OPTION_FULL_FILE_PATH;
      tt->enum_def.fields[14].name = tdrpStrDup("OPTION_REL_FILE_PATH");
      tt->enum_def.fields[14].val = OPTION_REL_FILE_PATH;
      tt->enum_def.fields[15].name = tdrpStrDup("OPTION_FILE_NAME");
      tt->enum_def.fields[15].val = OPTION_FILE_NAME;
      tt->enum_def.fields[16].name = tdrpStrDup("OPTION_FILE_EXT");
      tt->enum_def.fields[16].val = OPTION_FILE_EXT;
      tt->enum_def.fields[17].name = tdrpStrDup("OPTION_DATA_TYPE");
      tt->enum_def.fields[17].val = OPTION_DATA_TYPE;
      tt->enum_def.fields[18].name = tdrpStrDup("OPTION_USER_INFO1");
      tt->enum_def.fields[18].val = OPTION_USER_INFO1;
      tt->enum_def.fields[19].name = tdrpStrDup("OPTION_USER_INFO2");
      tt->enum_def.fields[19].val = OPTION_USER_INFO2;
      tt->enum_def.fields[20].name = tdrpStrDup("OPTION_IS_FORECAST");
      tt->enum_def.fields[20].val = OPTION_IS_FORECAST;
      tt->enum_def.fields[21].name = tdrpStrDup("OPTION_FORECAST_LEAD_SECS");
      tt->enum_def.fields[21].val = OPTION_FORECAST_LEAD_SECS;
      tt->enum_def.fields[22].name = tdrpStrDup("OPTION_WRITER");
      tt->enum_def.fields[22].val = OPTION_WRITER;
      tt->enum_def.fields[23].name = tdrpStrDup("OPTION_DATA_LATE_SECS");
      tt->enum_def.fields[23].val = OPTION_DATA_LATE_SECS;
      tt->enum_def.fields[24].name = tdrpStrDup("OPTION_DEBUG");
      tt->enum_def.fields[24].val = OPTION_DEBUG;
      tt->enum_def.fields[25].name = tdrpStrDup("OPTION_VERBOSE");
      tt->enum_def.fields[25].val = OPTION_VERBOSE;
    tt->array_vals = (tdrpVal_t *)
        tdrpMalloc(tt->array_n * sizeof(tdrpVal_t));
      tt->array_vals[0].e = OPTION_UNIX_TIME;
    tt++;
    
    // Parameter 'script_to_call'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("script_to_call");
    tt->descr = tdrpStrDup("Name of script to call if call_script is true");
    tt->help = tdrpStrDup("The script will be called with the args specified in the 'call_script parameter'. Also, take note of the 'include_input_path' parameter which places extra args at the start of the arg list. If you need extra args ahead of these args, put them in this string after the script name.");
    tt->val_offset = (char *) &script_to_call - &_start_;
    tt->single_val.s = tdrpStrDup("run_and_exit_script.pl");
    tt++;
    
    // Parameter 'include_input_path'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("include_input_path");
    tt->descr = tdrpStrDup("Option to pass two additional arguments (RAP_DATA_DIR and inputPath) to the called script.");
    tt->help = tdrpStrDup("The inputPath will be relative to RAP_DATA_DIR and will not include the _latest_data_info file. Also, note that these two additional arguments will occur BEFORE the standard arguments described in 'call_script' above.");
    tt->val_offset = (char *) &include_input_path - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'run_script_in_background'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("run_script_in_background");
    tt->descr = tdrpStrDup("Option to run script in background.");
    tt->help = tdrpStrDup("If TRUE, the script will be run in the background. Therefore, the system call will return immediately. If FALSE, LdataWatcher will register with procmap while waiting for the script to complete.");
    tt->val_offset = (char *) &run_script_in_background - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'terminate_script_if_hung'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("terminate_script_if_hung");
    tt->descr = tdrpStrDup("Option to terminate script if it hangs.");
    tt->help = tdrpStrDup("If TRUE, the script will be killed if it does not return within 'script_max_run_secs'.");
    tt->val_offset = (char *) &terminate_script_if_hung - &_start_;
    tt->single_val.b = pTRUE;
    tt++;
    
    // Parameter 'script_max_run_secs'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("script_max_run_secs");
    tt->descr = tdrpStrDup("Max time allowed for script - secs.");
    tt->help = tdrpStrDup("If 'terminate_script_if_hung' is TRUE, the script will be killed if it does not complete withing this number of secs.");
    tt->val_offset = (char *) &script_max_run_secs - &_start_;
    tt->single_val.i = 3600;
    tt++;
    
    // Parameter 'script_min_interval_secs'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("script_min_interval_secs");
    tt->descr = tdrpStrDup("Min allowed interval between calling script - secs.");
    tt->help = tdrpStrDup("The script will only be called if at least this number of seconds has elapsed since it was last called. If less time has gone by, the program will queue up the script call until the interval has elapsed. If multiple calls occur during a single interval, only the last one will be activated.");
    tt->val_offset = (char *) &script_min_interval_secs - &_start_;
    tt->single_val.i = 0;
    tt++;
    
    // Parameter 'supplementary_args'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("supplementary_args");
    tt->descr = tdrpStrDup("Supplementary arguments to be added to end of argument list.");
    tt->help = tdrpStrDup("This allows you to add command line arguments for calling the script. These are added at the END of the list. Only applies if script style is one of the OPTIONS types, i.e. NOT ORDERED.");
    tt->array_offset = (char *) &_supplementary_args - &_start_;
    tt->array_n_offset = (char *) &supplementary_args_n - &_start_;
    tt->is_array = TRUE;
    tt->array_len_fixed = FALSE;
    tt->array_elem_size = sizeof(char*);
    tt->array_n = 0;
    tt->array_vals = (tdrpVal_t *)
        tdrpMalloc(tt->array_n * sizeof(tdrpVal_t));
    tt++;
    
    // Parameter 'Comment 6'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 6");
    tt->comment_hdr = tdrpStrDup("CALL SCRIPT WHEN DATA IS LATE");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'call_data_late_script'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("call_data_late_script");
    tt->descr = tdrpStrDup("Option to spawn a script when data is late.");
    tt->help = tdrpStrDup("If TRUE, the script 'data_late_script_to_call' will be called when data has not arrived within the last 'data_late_secs'. The call to the script will be repeated every 'data_late_secs' until data arrives. The script is called with the following args derived from the latest_data_info file: data_late_secs, RAP_DATA_DIR, inputPath, unix_time, year, month, day, hour, min, sec, file_ext, user_info1, user_info2, n_fcasts, lead_time_1, lead_time_2, ... If n_fcasts is 0, that will be the last arg and there will be no lead times. The inputPath will be relative to RAP_DATA_DIR and will not include the _latest_data_info file. The script will be run in the background. If 'terminate_script_if_hung' is TRUE, the script will be terminated if it does not complete within 'script_max_run_secs'");
    tt->val_offset = (char *) &call_data_late_script - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'data_late_script'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("data_late_script");
    tt->descr = tdrpStrDup("Name of script to call if call_data_late_script is true");
    tt->help = tdrpStrDup("The script will be called with the args specified in the 'call_data_late_script' parameter. If you need extra args ahead of these standard args, put them in this string after the script name.");
    tt->val_offset = (char *) &data_late_script - &_start_;
    tt->single_val.s = tdrpStrDup("data_late_script.pl");
    tt++;
    
    // Parameter 'data_late_secs'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("data_late_secs");
    tt->descr = tdrpStrDup("Max data interval before it is considered late - secs.");
    tt->help = tdrpStrDup("If data has not arrived within this interval, and call_data_late_script is true, the data late script is called.");
    tt->val_offset = (char *) &data_late_secs - &_start_;
    tt->single_val.i = 3600;
    tt++;
    
    // trailing entry has param_name set to NULL
    
    tt->param_name = NULL;
    
    return;
  
  }
