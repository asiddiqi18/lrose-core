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
// Code for program MdvAccumulate
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
    tt->comment_hdr = tdrpStrDup("MdvAccumulate");
    tt->comment_text = tdrpStrDup("This program accumulates gridded data through time. The idea is that a grid is maintained that is overwritten with new data whenever new data appears. Pre-existing data will remain in areas where no new data has been received.");
    tt++;
    
    // Parameter 'Comment 1'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 1");
    tt->comment_hdr = tdrpStrDup("DEBUGGING PARAMETERS");
    tt->comment_text = tdrpStrDup("Parameters controlling debug outputs.");
    tt++;
    
    // Parameter 'debug'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("debug");
    tt->descr = tdrpStrDup("debug flag");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &debug - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'verbose'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("verbose");
    tt->descr = tdrpStrDup("verbose debug flag");
    tt->help = tdrpStrDup("If true, verbose debug messages will be printed.");
    tt->val_offset = (char *) &verbose - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'Comment 2'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 2");
    tt->comment_hdr = tdrpStrDup("PROCESS PARAMETERS");
    tt->comment_text = tdrpStrDup("");
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
    
    // Parameter 'Comment 3'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 3");
    tt->comment_hdr = tdrpStrDup("PROCESS TRIGGERING PARAMETERS");
    tt->comment_text = tdrpStrDup("Parameters describing the process triggering.");
    tt++;
    
    // Parameter 'trigger_mode'
    // ctype is '_trigger_mode_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = ENUM_TYPE;
    tt->param_name = tdrpStrDup("trigger_mode");
    tt->descr = tdrpStrDup("Input triggering mode");
    tt->help = tdrpStrDup("In LATEST_DATA mode, the program waits for new data from the MDV location specified by the latest_data_trigger parameter.\nIn TIME_LIST mode, the program operates on archive data as specified in the time_list_trigger parameter.\n");
    tt->val_offset = (char *) &trigger_mode - &_start_;
    tt->enum_def.name = tdrpStrDup("trigger_mode_t");
    tt->enum_def.nfields = 2;
    tt->enum_def.fields = (enum_field_t *)
        tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
      tt->enum_def.fields[0].name = tdrpStrDup("LATEST_DATA");
      tt->enum_def.fields[0].val = LATEST_DATA;
      tt->enum_def.fields[1].name = tdrpStrDup("TIME_LIST");
      tt->enum_def.fields[1].val = TIME_LIST;
    tt->single_val.e = LATEST_DATA;
    tt++;
    
    // Parameter 'time_list_trigger'
    // ctype is '_time_list_trigger_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRUCT_TYPE;
    tt->param_name = tdrpStrDup("time_list_trigger");
    tt->descr = tdrpStrDup("Trigger information used when using the TIME_LIST trigger");
    tt->help = tdrpStrDup("url specifies the triggering url.\nstart_time specifies the archive start time in any format recognized by the DateTime class.\nend_time specifies the archive end time in any format recognized by the DateTime class.");
    tt->val_offset = (char *) &time_list_trigger - &_start_;
    tt->struct_def.name = tdrpStrDup("time_list_trigger_t");
    tt->struct_def.nfields = 2;
    tt->struct_def.fields = (struct_field_t *)
        tdrpMalloc(tt->struct_def.nfields * sizeof(struct_field_t));
      tt->struct_def.fields[0].ftype = tdrpStrDup("string");
      tt->struct_def.fields[0].fname = tdrpStrDup("start_time");
      tt->struct_def.fields[0].ptype = STRING_TYPE;
      tt->struct_def.fields[0].rel_offset = 
        (char *) &time_list_trigger.start_time - (char *) &time_list_trigger;
      tt->struct_def.fields[1].ftype = tdrpStrDup("string");
      tt->struct_def.fields[1].fname = tdrpStrDup("end_time");
      tt->struct_def.fields[1].ptype = STRING_TYPE;
      tt->struct_def.fields[1].rel_offset = 
        (char *) &time_list_trigger.end_time - (char *) &time_list_trigger;
    tt->n_struct_vals = 2;
    tt->struct_vals = (tdrpVal_t *)
        tdrpMalloc(tt->n_struct_vals * sizeof(tdrpVal_t));
      tt->struct_vals[0].s = tdrpStrDup("2001/1/1 00:00:00");
      tt->struct_vals[1].s = tdrpStrDup("2002/1/2 00:00:00");
    tt++;
    
    // Parameter 'Comment 4'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 4");
    tt->comment_hdr = tdrpStrDup("PROCESS I/O PARAMETERS");
    tt->comment_text = tdrpStrDup("Parameters describing the input and output locations.");
    tt++;
    
    // Parameter 'input_url'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("input_url");
    tt->descr = tdrpStrDup("Input URL");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &input_url - &_start_;
    tt->single_val.s = tdrpStrDup("mdvp:://localhost::mdv/input");
    tt++;
    
    // Parameter 'accum_url'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("accum_url");
    tt->descr = tdrpStrDup("Accumulation URL");
    tt->help = tdrpStrDup("This is the URL where the data is accumulated. It is used for both input and output since the previous accumulation file is read in and updated to create the new accumulation file.");
    tt->val_offset = (char *) &accum_url - &_start_;
    tt->single_val.s = tdrpStrDup("mdvp:://localhost::mdv/accumulate");
    tt++;
    
    // Parameter 'max_accum_secs'
    // ctype is 'long'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = LONG_TYPE;
    tt->param_name = tdrpStrDup("max_accum_secs");
    tt->descr = tdrpStrDup("Amount of time the accumulation is valid in seconds.");
    tt->help = tdrpStrDup("Data in the accumulation that is older than this will be set to missing.");
    tt->val_offset = (char *) &max_accum_secs - &_start_;
    tt->single_val.l = 3600;
    tt++;
    
    // Parameter 'Comment 5'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 5");
    tt->comment_hdr = tdrpStrDup("ALGORITHM PARAMETERS");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'remap_data'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("remap_data");
    tt->descr = tdrpStrDup("Remap data flag");
    tt->help = tdrpStrDup("If true, the output data will be remapped to the given projection. If false, the output data will be written to the same projection as is used by the input data.");
    tt->val_offset = (char *) &remap_data - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'remap_info'
    // ctype is '_remap_info_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRUCT_TYPE;
    tt->param_name = tdrpStrDup("remap_info");
    tt->descr = tdrpStrDup("Information for remapping the input fields");
    tt->help = tdrpStrDup("If remap_type is REMAP_LATLON, the following fields are used:\n\tnx, ny, minx, miny, dx, dy\n\nIf remap_type is REMAP_FLAT, the following fields are used:\n\tnx, ny, minx, miny, dx, dy, origin_lat, origin_lon, rotation\n\nIf remap_type is REMAP_LAMBERT_CONFORMAL2, the following fields are used:\n\tnx, ny, minx, miny, dx, dy, origin_lat, origin_lon, lat1, lat2");
    tt->val_offset = (char *) &remap_info - &_start_;
    tt->struct_def.name = tdrpStrDup("remap_info_t");
    tt->struct_def.nfields = 12;
    tt->struct_def.fields = (struct_field_t *)
        tdrpMalloc(tt->struct_def.nfields * sizeof(struct_field_t));
      tt->struct_def.fields[0].ftype = tdrpStrDup("remap_type_t");
      tt->struct_def.fields[0].fname = tdrpStrDup("remap_type");
      tt->struct_def.fields[0].ptype = ENUM_TYPE;
      tt->struct_def.fields[0].rel_offset = 
        (char *) &remap_info.remap_type - (char *) &remap_info;
        tt->struct_def.fields[0].enum_def.name = tdrpStrDup("remap_type_t");
        tt->struct_def.fields[0].enum_def.nfields = 3;
        tt->struct_def.fields[0].enum_def.fields = (enum_field_t *) tdrpMalloc
          (tt->struct_def.fields[0].enum_def.nfields * sizeof(enum_field_t));
        tt->struct_def.fields[0].enum_def.fields[0].name = tdrpStrDup("REMAP_LATLON");
        tt->struct_def.fields[0].enum_def.fields[0].val = REMAP_LATLON;
        tt->struct_def.fields[0].enum_def.fields[1].name = tdrpStrDup("REMAP_FLAT");
        tt->struct_def.fields[0].enum_def.fields[1].val = REMAP_FLAT;
        tt->struct_def.fields[0].enum_def.fields[2].name = tdrpStrDup("REMAP_LAMBERT_CONFORMAL2");
        tt->struct_def.fields[0].enum_def.fields[2].val = REMAP_LAMBERT_CONFORMAL2;
      tt->struct_def.fields[1].ftype = tdrpStrDup("int");
      tt->struct_def.fields[1].fname = tdrpStrDup("nx");
      tt->struct_def.fields[1].ptype = INT_TYPE;
      tt->struct_def.fields[1].rel_offset = 
        (char *) &remap_info.nx - (char *) &remap_info;
      tt->struct_def.fields[2].ftype = tdrpStrDup("int");
      tt->struct_def.fields[2].fname = tdrpStrDup("ny");
      tt->struct_def.fields[2].ptype = INT_TYPE;
      tt->struct_def.fields[2].rel_offset = 
        (char *) &remap_info.ny - (char *) &remap_info;
      tt->struct_def.fields[3].ftype = tdrpStrDup("double");
      tt->struct_def.fields[3].fname = tdrpStrDup("minx");
      tt->struct_def.fields[3].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[3].rel_offset = 
        (char *) &remap_info.minx - (char *) &remap_info;
      tt->struct_def.fields[4].ftype = tdrpStrDup("double");
      tt->struct_def.fields[4].fname = tdrpStrDup("miny");
      tt->struct_def.fields[4].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[4].rel_offset = 
        (char *) &remap_info.miny - (char *) &remap_info;
      tt->struct_def.fields[5].ftype = tdrpStrDup("double");
      tt->struct_def.fields[5].fname = tdrpStrDup("dx");
      tt->struct_def.fields[5].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[5].rel_offset = 
        (char *) &remap_info.dx - (char *) &remap_info;
      tt->struct_def.fields[6].ftype = tdrpStrDup("double");
      tt->struct_def.fields[6].fname = tdrpStrDup("dy");
      tt->struct_def.fields[6].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[6].rel_offset = 
        (char *) &remap_info.dy - (char *) &remap_info;
      tt->struct_def.fields[7].ftype = tdrpStrDup("double");
      tt->struct_def.fields[7].fname = tdrpStrDup("origin_lat");
      tt->struct_def.fields[7].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[7].rel_offset = 
        (char *) &remap_info.origin_lat - (char *) &remap_info;
      tt->struct_def.fields[8].ftype = tdrpStrDup("double");
      tt->struct_def.fields[8].fname = tdrpStrDup("origin_lon");
      tt->struct_def.fields[8].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[8].rel_offset = 
        (char *) &remap_info.origin_lon - (char *) &remap_info;
      tt->struct_def.fields[9].ftype = tdrpStrDup("double");
      tt->struct_def.fields[9].fname = tdrpStrDup("rotation");
      tt->struct_def.fields[9].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[9].rel_offset = 
        (char *) &remap_info.rotation - (char *) &remap_info;
      tt->struct_def.fields[10].ftype = tdrpStrDup("double");
      tt->struct_def.fields[10].fname = tdrpStrDup("lat1");
      tt->struct_def.fields[10].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[10].rel_offset = 
        (char *) &remap_info.lat1 - (char *) &remap_info;
      tt->struct_def.fields[11].ftype = tdrpStrDup("double");
      tt->struct_def.fields[11].fname = tdrpStrDup("lat2");
      tt->struct_def.fields[11].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[11].rel_offset = 
        (char *) &remap_info.lat2 - (char *) &remap_info;
    tt->n_struct_vals = 12;
    tt->struct_vals = (tdrpVal_t *)
        tdrpMalloc(tt->n_struct_vals * sizeof(tdrpVal_t));
      tt->struct_vals[0].e = REMAP_LATLON;
      tt->struct_vals[1].i = 0;
      tt->struct_vals[2].i = 0;
      tt->struct_vals[3].d = 0;
      tt->struct_vals[4].d = 0;
      tt->struct_vals[5].d = 0;
      tt->struct_vals[6].d = 0;
      tt->struct_vals[7].d = 0;
      tt->struct_vals[8].d = 0;
      tt->struct_vals[9].d = 0;
      tt->struct_vals[10].d = 0;
      tt->struct_vals[11].d = 0;
    tt++;
    
    // Parameter 'background_field_info'
    // ctype is '_background_field_info_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRUCT_TYPE;
    tt->param_name = tdrpStrDup("background_field_info");
    tt->descr = tdrpStrDup("Information on background fields to use");
    tt->help = tdrpStrDup("If you want to use a background field with any of your input fields, put the information here. When the program reads an input field, it will check this list to see if it needs to use a background field. If the input field is found in this list, the specified background URL will be checked for new data. If there is more recent data in the background field than in the most recent accumulation file, the background field will be used rather than the accumulation file.\n\tinput_field_name - The name of the field in the input MDV file. This must match exactly.\n\tbackground_field_url - The URL to use for retrieving the background field. I'm allowing a different URL for each background field just in case a server is needed for calculating the background field (for example if you need a wind speed background field but the MDV file has U and V instead).\n\tbackground_field_name - The name of the background field as it appears in the MDV file (or as it will appear from the server.\n\tbackground_field_level_num - The level number of the background field to use. Set to -1 to use a composite of the background field.\nNote that currently you can only specify a background field if your input field is 2-dimensional.\nAlso note that even though you can specify a different URL for each background field, I am assuming that all of the fields come from the same URL. This affects the accumulation in the timing out of data fields. When a background field is found for any input field, I replace the latest accumulations with the appropriate background fields and set the data time for each grid point to the background field time. I also set all of the accumulation fields that I couldn't find background fields for to missing data values so that the data timing for all fields is the same. If any other behavior is desired, it will require a lot more coding and disk space since we'll have to keep data times for every grid point and every field rather than using the same data time for all of the fields at the same grid point.");
    tt->array_offset = (char *) &_background_field_info - &_start_;
    tt->array_n_offset = (char *) &background_field_info_n - &_start_;
    tt->is_array = TRUE;
    tt->array_len_fixed = FALSE;
    tt->array_elem_size = sizeof(background_field_info_t);
    tt->array_n = 0;
    tt->struct_def.name = tdrpStrDup("background_field_info_t");
    tt->struct_def.nfields = 4;
    tt->struct_def.fields = (struct_field_t *)
        tdrpMalloc(tt->struct_def.nfields * sizeof(struct_field_t));
      tt->struct_def.fields[0].ftype = tdrpStrDup("string");
      tt->struct_def.fields[0].fname = tdrpStrDup("input_field_name");
      tt->struct_def.fields[0].ptype = STRING_TYPE;
      tt->struct_def.fields[0].rel_offset = 
        (char *) &_background_field_info->input_field_name - (char *) _background_field_info;
      tt->struct_def.fields[1].ftype = tdrpStrDup("string");
      tt->struct_def.fields[1].fname = tdrpStrDup("background_field_url");
      tt->struct_def.fields[1].ptype = STRING_TYPE;
      tt->struct_def.fields[1].rel_offset = 
        (char *) &_background_field_info->background_field_url - (char *) _background_field_info;
      tt->struct_def.fields[2].ftype = tdrpStrDup("string");
      tt->struct_def.fields[2].fname = tdrpStrDup("background_field_name");
      tt->struct_def.fields[2].ptype = STRING_TYPE;
      tt->struct_def.fields[2].rel_offset = 
        (char *) &_background_field_info->background_field_name - (char *) _background_field_info;
      tt->struct_def.fields[3].ftype = tdrpStrDup("long");
      tt->struct_def.fields[3].fname = tdrpStrDup("background_field_level_num");
      tt->struct_def.fields[3].ptype = LONG_TYPE;
      tt->struct_def.fields[3].rel_offset = 
        (char *) &_background_field_info->background_field_level_num - (char *) _background_field_info;
    tt->n_struct_vals = 0;
    tt->struct_vals = (tdrpVal_t *)
        tdrpMalloc(tt->n_struct_vals * sizeof(tdrpVal_t));
    tt++;
    
    // Parameter 'Comment 6'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 6");
    tt->comment_hdr = tdrpStrDup("QUALITY CONTROL PARAMETERS");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'field_qcs'
    // ctype is '_field_qc_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRUCT_TYPE;
    tt->param_name = tdrpStrDup("field_qcs");
    tt->descr = tdrpStrDup("Quality control parameters for the accumulation fields.");
    tt->help = tdrpStrDup("\tfield_name - Name of the accumulation field for which this QC information applies.\n\tmax_value_diff - Maximum data value change allowed between accumulations. If set to a positive value, any new data whose value differs from the previous accumulation value (or the background field value if the background field is newer than the previous accumulation) by more than this ammount will be rejected and the previous accumulation value will be used instead. If set to a negative value, all new data values will be used in the accumulation.");
    tt->array_offset = (char *) &_field_qcs - &_start_;
    tt->array_n_offset = (char *) &field_qcs_n - &_start_;
    tt->is_array = TRUE;
    tt->array_len_fixed = FALSE;
    tt->array_elem_size = sizeof(field_qc_t);
    tt->array_n = 0;
    tt->struct_def.name = tdrpStrDup("field_qc_t");
    tt->struct_def.nfields = 2;
    tt->struct_def.fields = (struct_field_t *)
        tdrpMalloc(tt->struct_def.nfields * sizeof(struct_field_t));
      tt->struct_def.fields[0].ftype = tdrpStrDup("string");
      tt->struct_def.fields[0].fname = tdrpStrDup("field_name");
      tt->struct_def.fields[0].ptype = STRING_TYPE;
      tt->struct_def.fields[0].rel_offset = 
        (char *) &_field_qcs->field_name - (char *) _field_qcs;
      tt->struct_def.fields[1].ftype = tdrpStrDup("double");
      tt->struct_def.fields[1].fname = tdrpStrDup("max_value_diff");
      tt->struct_def.fields[1].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[1].rel_offset = 
        (char *) &_field_qcs->max_value_diff - (char *) _field_qcs;
    tt->n_struct_vals = 0;
    tt->struct_vals = (tdrpVal_t *)
        tdrpMalloc(tt->n_struct_vals * sizeof(tdrpVal_t));
    tt++;
    
    // trailing entry has param_name set to NULL
    
    tt->param_name = NULL;
    
    return;
  
  }
