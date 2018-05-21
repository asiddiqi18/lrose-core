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
// Code for program Nids2Mdv
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
    tt->comment_hdr = tdrpStrDup("Read NIDS level 3 data in polar radar coordinates, write out to MDV. Supports polar and Cartesian grid output.");
    tt->comment_text = tdrpStrDup("");
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
    
    // Parameter 'malloc_debug_level'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("malloc_debug_level");
    tt->descr = tdrpStrDup("Malloc debug level");
    tt->help = tdrpStrDup("0 - none, 1 - corruption checking, 2 - records all malloc blocks and checks, 3 - printout of all mallocs etc.");
    tt->val_offset = (char *) &malloc_debug_level - &_start_;
    tt->has_min = TRUE;
    tt->has_max = TRUE;
    tt->min_val.i = 0;
    tt->max_val.i = 3;
    tt->single_val.i = 0;
    tt++;
    
    // Parameter 'no_threads'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("no_threads");
    tt->descr = tdrpStrDup("No threads option. Forces single-threaded operation.");
    tt->help = tdrpStrDup("For debugging purposes. Note that the program will handle only a single data directory in single-threaded operation.");
    tt->val_offset = (char *) &no_threads - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'instance'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("instance");
    tt->descr = tdrpStrDup("Process instance");
    tt->help = tdrpStrDup("Used for registration with procmap.");
    tt->val_offset = (char *) &instance - &_start_;
    tt->single_val.s = tdrpStrDup("Test");
    tt++;
    
    // Parameter 'dmapDir'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("dmapDir");
    tt->descr = tdrpStrDup("The data dir to register with the DataMapper, if registration is desired. Ignored in archive mode.");
    tt->help = tdrpStrDup("The data dir to register with the DataMapper. If this string is empty, no DataMapper registration will be performed. Ignored in archive mode.");
    tt->val_offset = (char *) &dmapDir - &_start_;
    tt->single_val.s = tdrpStrDup("");
    tt++;
    
    // Parameter 'Comment 2'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 2");
    tt->comment_hdr = tdrpStrDup("PROGRAM MODE OF OPERATION.");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'mode'
    // ctype is '_mode_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = ENUM_TYPE;
    tt->param_name = tdrpStrDup("mode");
    tt->descr = tdrpStrDup("Operating mode");
    tt->help = tdrpStrDup("In realtime mode, this program waits for a new input file. In archive mode, it moves through the files between the times set by the user.");
    tt->val_offset = (char *) &mode - &_start_;
    tt->enum_def.name = tdrpStrDup("mode_t");
    tt->enum_def.nfields = 2;
    tt->enum_def.fields = (enum_field_t *)
        tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
      tt->enum_def.fields[0].name = tdrpStrDup("ARCHIVE");
      tt->enum_def.fields[0].val = ARCHIVE;
      tt->enum_def.fields[1].name = tdrpStrDup("REALTIME");
      tt->enum_def.fields[1].val = REALTIME;
    tt->single_val.e = ARCHIVE;
    tt++;
    
    // Parameter 'Comment 3'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 3");
    tt->comment_hdr = tdrpStrDup("DATA INPUT.");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'realtime_data_sets'
    // ctype is '_data_set_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRUCT_TYPE;
    tt->param_name = tdrpStrDup("realtime_data_sets");
    tt->descr = tdrpStrDup("Array of data sets to be processed.");
    tt->help = tdrpStrDup("The program will check each input directory in order.New data is processed and written as MDV to the individual radar subdirectory output directory. Note that the output_dir is only  used if 'specify_individual_output_dirs' is set TRUE. See specify_individual_output_dirs for more details.");
    tt->array_offset = (char *) &_realtime_data_sets - &_start_;
    tt->array_n_offset = (char *) &realtime_data_sets_n - &_start_;
    tt->is_array = TRUE;
    tt->array_len_fixed = FALSE;
    tt->array_elem_size = sizeof(data_set_t);
    tt->array_n = 1;
    tt->struct_def.name = tdrpStrDup("data_set_t");
    tt->struct_def.nfields = 3;
    tt->struct_def.fields = (struct_field_t *)
        tdrpMalloc(tt->struct_def.nfields * sizeof(struct_field_t));
      tt->struct_def.fields[0].ftype = tdrpStrDup("string");
      tt->struct_def.fields[0].fname = tdrpStrDup("input_dir");
      tt->struct_def.fields[0].ptype = STRING_TYPE;
      tt->struct_def.fields[0].rel_offset = 
        (char *) &_realtime_data_sets->input_dir - (char *) _realtime_data_sets;
      tt->struct_def.fields[1].ftype = tdrpStrDup("string");
      tt->struct_def.fields[1].fname = tdrpStrDup("output_dir");
      tt->struct_def.fields[1].ptype = STRING_TYPE;
      tt->struct_def.fields[1].rel_offset = 
        (char *) &_realtime_data_sets->output_dir - (char *) _realtime_data_sets;
      tt->struct_def.fields[2].ftype = tdrpStrDup("string");
      tt->struct_def.fields[2].fname = tdrpStrDup("radar_name");
      tt->struct_def.fields[2].ptype = STRING_TYPE;
      tt->struct_def.fields[2].rel_offset = 
        (char *) &_realtime_data_sets->radar_name - (char *) _realtime_data_sets;
    tt->n_struct_vals = 3;
    tt->struct_vals = (tdrpVal_t *)
        tdrpMalloc(tt->n_struct_vals * sizeof(tdrpVal_t));
      tt->struct_vals[0].s = tdrpStrDup(".");
      tt->struct_vals[1].s = tdrpStrDup("output");
      tt->struct_vals[2].s = tdrpStrDup("no-name");
    tt++;
    
    // Parameter 'archive_data_set'
    // ctype is '_data_set_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRUCT_TYPE;
    tt->param_name = tdrpStrDup("archive_data_set");
    tt->descr = tdrpStrDup("Archive data sets to be processed.");
    tt->help = tdrpStrDup("The input_dir is ignored, since the file paths to be processed are specified on the command line.");
    tt->val_offset = (char *) &archive_data_set - &_start_;
    tt->struct_def.name = tdrpStrDup("data_set_t");
    tt->struct_def.nfields = 3;
    tt->struct_def.fields = (struct_field_t *)
        tdrpMalloc(tt->struct_def.nfields * sizeof(struct_field_t));
      tt->struct_def.fields[0].ftype = tdrpStrDup("string");
      tt->struct_def.fields[0].fname = tdrpStrDup("input_dir");
      tt->struct_def.fields[0].ptype = STRING_TYPE;
      tt->struct_def.fields[0].rel_offset = 
        (char *) &archive_data_set.input_dir - (char *) &archive_data_set;
      tt->struct_def.fields[1].ftype = tdrpStrDup("string");
      tt->struct_def.fields[1].fname = tdrpStrDup("output_dir");
      tt->struct_def.fields[1].ptype = STRING_TYPE;
      tt->struct_def.fields[1].rel_offset = 
        (char *) &archive_data_set.output_dir - (char *) &archive_data_set;
      tt->struct_def.fields[2].ftype = tdrpStrDup("string");
      tt->struct_def.fields[2].fname = tdrpStrDup("radar_name");
      tt->struct_def.fields[2].ptype = STRING_TYPE;
      tt->struct_def.fields[2].rel_offset = 
        (char *) &archive_data_set.radar_name - (char *) &archive_data_set;
    tt->n_struct_vals = 3;
    tt->struct_vals = (tdrpVal_t *)
        tdrpMalloc(tt->n_struct_vals * sizeof(tdrpVal_t));
      tt->struct_vals[0].s = tdrpStrDup(".");
      tt->struct_vals[1].s = tdrpStrDup("output");
      tt->struct_vals[2].s = tdrpStrDup("no-name");
    tt++;
    
    // Parameter 'max_realtime_data_age'
    // ctype is 'long'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = LONG_TYPE;
    tt->param_name = tdrpStrDup("max_realtime_data_age");
    tt->descr = tdrpStrDup("Max age (in seconds) of input data for it to be valid");
    tt->help = tdrpStrDup("Only used in realtime mode.");
    tt->val_offset = (char *) &max_realtime_data_age - &_start_;
    tt->single_val.l = 360;
    tt++;
    
    // Parameter 'use_latest_data_info'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("use_latest_data_info");
    tt->descr = tdrpStrDup("Option to use latest_data_info file to trigger input. REALTIME mode only");
    tt->help = tdrpStrDup("Some upstream processes, such as WsiNidsIngest, will generate latest_data_info files. Others, such as the LDM, do not. If this option is on, each thread triggers  off the lates_data_info file. If the option is off, the thread watches the directory for new files.");
    tt->val_offset = (char *) &use_latest_data_info - &_start_;
    tt->single_val.b = pTRUE;
    tt++;
    
    // Parameter 'get_latest_file_only'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("get_latest_file_only");
    tt->descr = tdrpStrDup("Option to only get the latest valid file, rather than all the files  younger than max_realtime_data_age.");
    tt->help = tdrpStrDup("Only used in realtime mode and if use_latest_data_info is FALSE. If set,  only the latest file will be processed. If not set, all files younger than max_input_data_age will be processed.");
    tt->val_offset = (char *) &get_latest_file_only - &_start_;
    tt->single_val.b = pTRUE;
    tt++;
    
    // Parameter 'Comment 4'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 4");
    tt->comment_hdr = tdrpStrDup("DATA OUTPUT.");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'specify_individual_output_dirs'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("specify_individual_output_dirs");
    tt->descr = tdrpStrDup("Option to specify the output dir for each radar.");
    tt->help = tdrpStrDup("If true, the data will be written to the output_dir specified in the 'data_sets' parameter. If false, the output_dir will be computed from the output_dir and the radar_name as follows: \n\toutput_dir = output_dir/radar_name.");
    tt->val_offset = (char *) &specify_individual_output_dirs - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'global_output_dir'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("global_output_dir");
    tt->descr = tdrpStrDup("Output directory. Individual radars will be output to separate subdirectories of this directory.");
    tt->help = tdrpStrDup("This is used if specify_individual_output_dirs is false.The program will create a subdirectory for each radar, using the radar name in lower case.");
    tt->val_offset = (char *) &global_output_dir - &_start_;
    tt->single_val.s = tdrpStrDup("output");
    tt++;
    
    // Parameter 'preserve_input_geometry'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("preserve_input_geometry");
    tt->descr = tdrpStrDup("Specifies if source data is radial.");
    tt->help = tdrpStrDup("If set to TRUE, data is radial. If FALSE, data is grid.This is implemented only for radial data at this time -- cartesian input data must have output geometry specified.");
    tt->val_offset = (char *) &preserve_input_geometry - &_start_;
    tt->single_val.b = pTRUE;
    tt++;
    
    // Parameter 'output_grid'
    // ctype is '_output_grid_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRUCT_TYPE;
    tt->param_name = tdrpStrDup("output_grid");
    tt->descr = tdrpStrDup("Output grid dimensions.");
    tt->help = tdrpStrDup("The grid origin will be at the radar site. This is ignored if preserve_input_geometry is TRUE, since the input geometry is used for the output file. This MUST be specified for cartesian input data, and it must match the geometry of the input grid.");
    tt->val_offset = (char *) &output_grid - &_start_;
    tt->struct_def.name = tdrpStrDup("output_grid_t");
    tt->struct_def.nfields = 6;
    tt->struct_def.fields = (struct_field_t *)
        tdrpMalloc(tt->struct_def.nfields * sizeof(struct_field_t));
      tt->struct_def.fields[0].ftype = tdrpStrDup("int");
      tt->struct_def.fields[0].fname = tdrpStrDup("nx");
      tt->struct_def.fields[0].ptype = INT_TYPE;
      tt->struct_def.fields[0].rel_offset = 
        (char *) &output_grid.nx - (char *) &output_grid;
      tt->struct_def.fields[1].ftype = tdrpStrDup("int");
      tt->struct_def.fields[1].fname = tdrpStrDup("ny");
      tt->struct_def.fields[1].ptype = INT_TYPE;
      tt->struct_def.fields[1].rel_offset = 
        (char *) &output_grid.ny - (char *) &output_grid;
      tt->struct_def.fields[2].ftype = tdrpStrDup("float");
      tt->struct_def.fields[2].fname = tdrpStrDup("minx");
      tt->struct_def.fields[2].ptype = FLOAT_TYPE;
      tt->struct_def.fields[2].rel_offset = 
        (char *) &output_grid.minx - (char *) &output_grid;
      tt->struct_def.fields[3].ftype = tdrpStrDup("float");
      tt->struct_def.fields[3].fname = tdrpStrDup("miny");
      tt->struct_def.fields[3].ptype = FLOAT_TYPE;
      tt->struct_def.fields[3].rel_offset = 
        (char *) &output_grid.miny - (char *) &output_grid;
      tt->struct_def.fields[4].ftype = tdrpStrDup("float");
      tt->struct_def.fields[4].fname = tdrpStrDup("dx");
      tt->struct_def.fields[4].ptype = FLOAT_TYPE;
      tt->struct_def.fields[4].rel_offset = 
        (char *) &output_grid.dx - (char *) &output_grid;
      tt->struct_def.fields[5].ftype = tdrpStrDup("float");
      tt->struct_def.fields[5].fname = tdrpStrDup("dy");
      tt->struct_def.fields[5].ptype = FLOAT_TYPE;
      tt->struct_def.fields[5].rel_offset = 
        (char *) &output_grid.dy - (char *) &output_grid;
    tt->n_struct_vals = 6;
    tt->struct_vals = (tdrpVal_t *)
        tdrpMalloc(tt->n_struct_vals * sizeof(tdrpVal_t));
      tt->struct_vals[0].i = 460;
      tt->struct_vals[1].i = 460;
      tt->struct_vals[2].f = -229.5;
      tt->struct_vals[3].f = -229.5;
      tt->struct_vals[4].f = 1;
      tt->struct_vals[5].f = 1;
    tt++;
    
    // Parameter 'is_radial'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("is_radial");
    tt->descr = tdrpStrDup("Specifies if source data is radial.");
    tt->help = tdrpStrDup("If set to TRUE, data is radial. If FALSE, data is grid.");
    tt->val_offset = (char *) &is_radial - &_start_;
    tt->single_val.b = pTRUE;
    tt++;
    
    // Parameter 'data_field_name_long'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("data_field_name_long");
    tt->descr = tdrpStrDup("field name for data -- long form");
    tt->help = tdrpStrDup("This value is put in the MDV field header.");
    tt->val_offset = (char *) &data_field_name_long - &_start_;
    tt->single_val.s = tdrpStrDup("Vertically Integrated Liquid");
    tt++;
    
    // Parameter 'data_field_name'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("data_field_name");
    tt->descr = tdrpStrDup("field name for data -- short form");
    tt->help = tdrpStrDup("This value is put in the MDV field header.");
    tt->val_offset = (char *) &data_field_name - &_start_;
    tt->single_val.s = tdrpStrDup("vil");
    tt++;
    
    // Parameter 'data_units'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("data_units");
    tt->descr = tdrpStrDup("data units");
    tt->help = tdrpStrDup("This value is put in the MDV field header.");
    tt->val_offset = (char *) &data_units - &_start_;
    tt->single_val.s = tdrpStrDup("kg m-2");
    tt++;
    
    // Parameter 'data_transform'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("data_transform");
    tt->descr = tdrpStrDup("data transformation");
    tt->help = tdrpStrDup("This value is put in the MDV field header.");
    tt->val_offset = (char *) &data_transform - &_start_;
    tt->single_val.s = tdrpStrDup("none");
    tt++;
    
    // Parameter 'data_field_code'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("data_field_code");
    tt->descr = tdrpStrDup("field code for data");
    tt->help = tdrpStrDup("This value is put in the MDV field header.");
    tt->val_offset = (char *) &data_field_code - &_start_;
    tt->single_val.i = 263;
    tt++;
    
    // Parameter 'data_scale'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("data_scale");
    tt->descr = tdrpStrDup("scale value used for converting between byte values and data values");
    tt->help = tdrpStrDup("The byte value is calculated from the byte value using the following formula: byte = (value - data_bias) / data_scale. ");
    tt->val_offset = (char *) &data_scale - &_start_;
    tt->single_val.d = 0.3;
    tt++;
    
    // Parameter 'data_bias'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("data_bias");
    tt->descr = tdrpStrDup("bias value used for converting between byte values and data values");
    tt->help = tdrpStrDup("The byte value is calculated from the byte value using the following formula: byte = (value - data_bias) / data_scale. ");
    tt->val_offset = (char *) &data_bias - &_start_;
    tt->single_val.d = 0;
    tt++;
    
    // Parameter 'compute_scale_and_bias'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("compute_scale_and_bias");
    tt->descr = tdrpStrDup("Option to automatically compute the data scale and bias.");
    tt->help = tdrpStrDup("If set to TRUE, the data scale and bias will automatically be computed from the input data, otherwise the data_scale and data_bias parameter values will be used.");
    tt->val_offset = (char *) &compute_scale_and_bias - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'processing_delay'
    // ctype is 'long'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = LONG_TYPE;
    tt->param_name = tdrpStrDup("processing_delay");
    tt->descr = tdrpStrDup("processing delay in seconds");
    tt->help = tdrpStrDup("The number of seconds to wait before processing an input file. This delay allows activity on the file to finish before we ");
    tt->val_offset = (char *) &processing_delay - &_start_;
    tt->single_val.l = 0;
    tt++;
    
    // Parameter 'realtime_sleep_secs'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("realtime_sleep_secs");
    tt->descr = tdrpStrDup("Sleep this amount of time between checking for new data.");
    tt->help = tdrpStrDup("Typically checking every second is fine. On a heavily loaded machine,there may be some advantage to sleeping a bit longer");
    tt->val_offset = (char *) &realtime_sleep_secs - &_start_;
    tt->has_min = TRUE;
    tt->has_max = TRUE;
    tt->min_val.i = 1;
    tt->max_val.i = 120;
    tt->single_val.i = 1;
    tt++;
    
    // Parameter 'postProcessOutput'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("postProcessOutput");
    tt->descr = tdrpStrDup("Option to post-process the mdv file.");
    tt->help = tdrpStrDup("If set to TRUE, a command will be submitted to the fmq.This can be used to create images for the data as they arrive.");
    tt->val_offset = (char *) &postProcessOutput - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'postProcessFmqUrl'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("postProcessFmqUrl");
    tt->descr = tdrpStrDup("Output FMQ for Post processing Commands");
    tt->help = tdrpStrDup("If postProcessOutput is set to TRUE, this url names the fmq file for storing post-processing requests. The radar type will be appended to this url.");
    tt->val_offset = (char *) &postProcessFmqUrl - &_start_;
    tt->single_val.s = tdrpStrDup("Nids2Mdv-Cmd");
    tt++;
    
    // Parameter 'postProcessCommand'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("postProcessCommand");
    tt->descr = tdrpStrDup("Post processing command -  Sent to command FMQ");
    tt->help = tdrpStrDup(" Name of a script used to post process MDV files. For historical reasons the postProcessOutput FMQ uses The following script arguments: Script_name Radar_name Mdv_file_name Arguments");
    tt->val_offset = (char *) &postProcessCommand - &_start_;
    tt->single_val.s = tdrpStrDup("none");
    tt++;
    
    // Parameter 'postProcessCmdArguments'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("postProcessCmdArguments");
    tt->descr = tdrpStrDup("Arguments to be appended to the postProcessCommand command");
    tt->help = tdrpStrDup("Can be used to determine which color scale to use, etc.");
    tt->val_offset = (char *) &postProcessCmdArguments - &_start_;
    tt->single_val.s = tdrpStrDup(" BREF1");
    tt++;
    
    // trailing entry has param_name set to NULL
    
    tt->param_name = NULL;
    
    return;
  
  }
