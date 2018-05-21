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
// Code for program StormInitBdry
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
    tt->comment_hdr = tdrpStrDup("StormInitBdry is a small application that is\ndesigned to facilitate the study of the relation\nbetween storm initiation and boundaries.\n\nThe storm initiation data comes from the output\nof the StormInitLocation program, and the boudary\ninformation typically comes from the colide algorithm\n(although use of MIGFA is also possible).\n\nThe program reads storm initiation locations from\nan SPDB database for a temporal interval specified\nby the command line arguments :\n-start \"YYYY MM DD hh mm ss\" -end \"YYYY MM DD hh mm ss\"\n\nFor each initiation point, the program reads boundary\ndata from another SPDB database. The temporal window to read\nfrom is determined by the secsPriorToInit and secsPostInit\nparameters.\n\nFor each boundary, the program computes some statistics about\nthe relation between the initiation point and the boundary.\nThese include the distance from the boundary and the angle the\nline from the boundary to the init point makes with the\nmean boundary velocity vector. Note that if a boundary is\ndetermined to be stationary - its mean velocity is less than\nthe minBdryVel parameter below - then the angle cannot be\ncalculated, so this is a special case.\n\nThe program then applies limits to these statistics to determine\nwhich output file they should go into. These limits are applied\nto the angle, distance and the exrapolation time for the boundary.\nThe limits are specified in the Limits[] structure below.\nThe default settings are used to determine if the initiation\npoint is in front of, to the side of, or behind the boundary.\nA stationary boundary is a special case. Since the angular\nconsiderations cannot be calculated, they are simply not applied.\nIn this case the staticBdryLimit structure determines what limits\nto apply, and obviously the angle is not included in the output.\n\nOutput files appear in outDir and are named by the convention :\nLimitName_YYYYMMDD_hhmmss.dat\nWhere YYYYMMDD_hhmmss is the time specified by the -start argument\nand LimitName is the name of the Limit from Limits[].\n\nThe output files are ASCII files in which the colums have\nthe following significance :\n\n(1) The unix time of the initiation point, seconds since Jan 1 1970\n(2-7) The year, month, day, hour, minute and second of\n    the initiation point.\n(8) The boundary time minus the init time, in seconds.\n(9) The extrapolation seconds for the boundary (0 if detection)\n(10-11) The lat, lon of the initiation point.\n(12-13) The lat, lon of the closest point in the boundary to the\n        initiation point.\n(14) The sequence number of the boundary.\n(15) The group ID of the boundary.\n(16-17) The Titan complex and simpletrack numbers\n         of the storm that was initiated.\n(18) The maximum DBZ the storm achived.\n(19) The maximum area the storm achieved.\n(20) The duration of the storm, in minutes.\n(21) The minimum distance from the boundary to the\n     initiation point, Km.\n(22) The modulus of the boundary velocity, Km/Hr\n(23-24) The U and V components of the mean boundary velocity.\n(25) OPTIONAL : The angle between the direction of the\n     direction of the mean boundary velocity and the line\n     from the boundary to the storm initiation point, in degrees.\n     This is not output for the case of static boundaries, but\n     since all the static boundaries are written to a seperate\n     file, all the entries in that file have 24 entries, while\n     all the other files have 25 colums. So all the files can be\n     loaded into MatLab, ExCel etc.\n\nNiles Oien December 2002.");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'spdbUrl'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("spdbUrl");
    tt->descr = tdrpStrDup("Input storm init location SPDB URL");
    tt->help = tdrpStrDup("The GenPt structures that drive the program\nare read from this SPDB URL.");
    tt->val_offset = (char *) &spdbUrl - &_start_;
    tt->single_val.s = tdrpStrDup("spdbp:://localhost::spdb/StormInitLoc");
    tt++;
    
    // Parameter 'bdryUrl'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("bdryUrl");
    tt->descr = tdrpStrDup("Input SPDB boundary URL.");
    tt->help = tdrpStrDup("The boundaries are read from here.");
    tt->val_offset = (char *) &bdryUrl - &_start_;
    tt->single_val.s = tdrpStrDup("spdbp:://localhost::spdb/bdry");
    tt++;
    
    // Parameter 'secsPriorToInit'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("secsPriorToInit");
    tt->descr = tdrpStrDup("For each storm init point, the temporal window\nto search for boundaries runs from the init time minus\nsecsPriorToInit to secsPostInit");
    tt->help = tdrpStrDup("Default is to look 600 secs before and 300 secs after\ninit points for boundaries.");
    tt->val_offset = (char *) &secsPriorToInit - &_start_;
    tt->single_val.i = 600;
    tt++;
    
    // Parameter 'secsPostInit'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("secsPostInit");
    tt->descr = tdrpStrDup("For each storm init point, the temporal window\nto search for boundaries runs from the init time minus\nsecsPriorToInit to secsPostInit");
    tt->help = tdrpStrDup("Default is to look 600 secs before and 300 secs after\ninit points for boundaries.");
    tt->val_offset = (char *) &secsPostInit - &_start_;
    tt->single_val.i = 300;
    tt++;
    
    // Parameter 'badVal'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("badVal");
    tt->descr = tdrpStrDup("Value to output when data are bad/missing.");
    tt->help = tdrpStrDup("Set to something physical values cannot reach.");
    tt->val_offset = (char *) &badVal - &_start_;
    tt->single_val.d = -999;
    tt++;
    
    // Parameter 'outDir'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("outDir");
    tt->descr = tdrpStrDup("Output directory.");
    tt->help = tdrpStrDup("Data files are written here.");
    tt->val_offset = (char *) &outDir - &_start_;
    tt->single_val.s = tdrpStrDup("./some/directory/structure");
    tt++;
    
    // Parameter 'debug'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("debug");
    tt->descr = tdrpStrDup("Set to print more messages as data are processed.");
    tt->help = tdrpStrDup("Can usually be FALSE");
    tt->val_offset = (char *) &debug - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'Instance'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("Instance");
    tt->descr = tdrpStrDup("Instance to check in to Procmap with");
    tt->help = tdrpStrDup("Set to something unique.");
    tt->val_offset = (char *) &Instance - &_start_;
    tt->single_val.s = tdrpStrDup("primary");
    tt++;
    
    // Parameter 'Limits'
    // ctype is '_Limit_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRUCT_TYPE;
    tt->param_name = tdrpStrDup("Limits");
    tt->descr = tdrpStrDup("Limits into which the relations between boundaries and\nstorm initiation points fall into. Limits are placed\non distance to the boundary and the angle between the boundary's\naverage velocity, and the line between the storm init point and\nthe closest point to it in the boundary. These angles are between\n0 and 180 degrees. Limits are inclusive. Limits are also placed\non the extrapolation time. NOTE that none of these limits will\napply if the boundary is determined to be stationary, according\nthe velocity theshold set by minBdryVel.\nLimits are inclusive.");
    tt->help = tdrpStrDup("Typically used to deliniate between init points that are\nin front of a boundary, behind a boundary and to the side of\na boundary. The name is used in the output filename, so no\nspaces or odd characters please. Several catergories can be met\nsimultaneously.");
    tt->array_offset = (char *) &_Limits - &_start_;
    tt->array_n_offset = (char *) &Limits_n - &_start_;
    tt->is_array = TRUE;
    tt->array_len_fixed = FALSE;
    tt->array_elem_size = sizeof(Limit_t);
    tt->array_n = 3;
    tt->struct_def.name = tdrpStrDup("Limit_t");
    tt->struct_def.nfields = 7;
    tt->struct_def.fields = (struct_field_t *)
        tdrpMalloc(tt->struct_def.nfields * sizeof(struct_field_t));
      tt->struct_def.fields[0].ftype = tdrpStrDup("string");
      tt->struct_def.fields[0].fname = tdrpStrDup("Name");
      tt->struct_def.fields[0].ptype = STRING_TYPE;
      tt->struct_def.fields[0].rel_offset = 
        (char *) &_Limits->Name - (char *) _Limits;
      tt->struct_def.fields[1].ftype = tdrpStrDup("double");
      tt->struct_def.fields[1].fname = tdrpStrDup("min_angle");
      tt->struct_def.fields[1].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[1].rel_offset = 
        (char *) &_Limits->min_angle - (char *) _Limits;
      tt->struct_def.fields[2].ftype = tdrpStrDup("double");
      tt->struct_def.fields[2].fname = tdrpStrDup("max_angle");
      tt->struct_def.fields[2].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[2].rel_offset = 
        (char *) &_Limits->max_angle - (char *) _Limits;
      tt->struct_def.fields[3].ftype = tdrpStrDup("double");
      tt->struct_def.fields[3].fname = tdrpStrDup("min_dist");
      tt->struct_def.fields[3].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[3].rel_offset = 
        (char *) &_Limits->min_dist - (char *) _Limits;
      tt->struct_def.fields[4].ftype = tdrpStrDup("double");
      tt->struct_def.fields[4].fname = tdrpStrDup("max_dist");
      tt->struct_def.fields[4].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[4].rel_offset = 
        (char *) &_Limits->max_dist - (char *) _Limits;
      tt->struct_def.fields[5].ftype = tdrpStrDup("int");
      tt->struct_def.fields[5].fname = tdrpStrDup("minExtrapSecs");
      tt->struct_def.fields[5].ptype = INT_TYPE;
      tt->struct_def.fields[5].rel_offset = 
        (char *) &_Limits->minExtrapSecs - (char *) _Limits;
      tt->struct_def.fields[6].ftype = tdrpStrDup("int");
      tt->struct_def.fields[6].fname = tdrpStrDup("maxExtrapSecs");
      tt->struct_def.fields[6].ptype = INT_TYPE;
      tt->struct_def.fields[6].rel_offset = 
        (char *) &_Limits->maxExtrapSecs - (char *) _Limits;
    tt->n_struct_vals = 21;
    tt->struct_vals = (tdrpVal_t *)
        tdrpMalloc(tt->n_struct_vals * sizeof(tdrpVal_t));
      tt->struct_vals[0].s = tdrpStrDup("Front");
      tt->struct_vals[1].d = 0;
      tt->struct_vals[2].d = 30;
      tt->struct_vals[3].d = 0;
      tt->struct_vals[4].d = 50;
      tt->struct_vals[5].i = 0;
      tt->struct_vals[6].i = 0;
      tt->struct_vals[7].s = tdrpStrDup("Side");
      tt->struct_vals[8].d = 30;
      tt->struct_vals[9].d = 150;
      tt->struct_vals[10].d = 0;
      tt->struct_vals[11].d = 20;
      tt->struct_vals[12].i = 0;
      tt->struct_vals[13].i = 0;
      tt->struct_vals[14].s = tdrpStrDup("Rear");
      tt->struct_vals[15].d = 150;
      tt->struct_vals[16].d = 180;
      tt->struct_vals[17].d = 0;
      tt->struct_vals[18].d = 150;
      tt->struct_vals[19].i = 0;
      tt->struct_vals[20].i = 0;
    tt++;
    
    // Parameter 'minBdryVel'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("minBdryVel");
    tt->descr = tdrpStrDup("Lower limit on boundary velocity, m/s.");
    tt->help = tdrpStrDup("If the boundary's mean velocity is less than this, then\nthe velocity will be set to 0. None of the limits in the Limits\nstruct will apply, instead, only the minStationaryDist\nand maxStationaryDist parameters will be used. The output file\nwill be named 'stationary'");
    tt->val_offset = (char *) &minBdryVel - &_start_;
    tt->single_val.d = 0.5;
    tt++;
    
    // Parameter 'staticBdryLimit'
    // ctype is '_Limit_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRUCT_TYPE;
    tt->param_name = tdrpStrDup("staticBdryLimit");
    tt->descr = tdrpStrDup("This is the limit that is used when the boundary is determined\nto be stationary from the minBdryVel threshold.");
    tt->help = tdrpStrDup(" In this case the angular limits have no meaning\nand are not applied. They default to -999.0 to reflect this.");
    tt->val_offset = (char *) &staticBdryLimit - &_start_;
    tt->struct_def.name = tdrpStrDup("Limit_t");
    tt->struct_def.nfields = 7;
    tt->struct_def.fields = (struct_field_t *)
        tdrpMalloc(tt->struct_def.nfields * sizeof(struct_field_t));
      tt->struct_def.fields[0].ftype = tdrpStrDup("string");
      tt->struct_def.fields[0].fname = tdrpStrDup("Name");
      tt->struct_def.fields[0].ptype = STRING_TYPE;
      tt->struct_def.fields[0].rel_offset = 
        (char *) &staticBdryLimit.Name - (char *) &staticBdryLimit;
      tt->struct_def.fields[1].ftype = tdrpStrDup("double");
      tt->struct_def.fields[1].fname = tdrpStrDup("min_angle");
      tt->struct_def.fields[1].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[1].rel_offset = 
        (char *) &staticBdryLimit.min_angle - (char *) &staticBdryLimit;
      tt->struct_def.fields[2].ftype = tdrpStrDup("double");
      tt->struct_def.fields[2].fname = tdrpStrDup("max_angle");
      tt->struct_def.fields[2].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[2].rel_offset = 
        (char *) &staticBdryLimit.max_angle - (char *) &staticBdryLimit;
      tt->struct_def.fields[3].ftype = tdrpStrDup("double");
      tt->struct_def.fields[3].fname = tdrpStrDup("min_dist");
      tt->struct_def.fields[3].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[3].rel_offset = 
        (char *) &staticBdryLimit.min_dist - (char *) &staticBdryLimit;
      tt->struct_def.fields[4].ftype = tdrpStrDup("double");
      tt->struct_def.fields[4].fname = tdrpStrDup("max_dist");
      tt->struct_def.fields[4].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[4].rel_offset = 
        (char *) &staticBdryLimit.max_dist - (char *) &staticBdryLimit;
      tt->struct_def.fields[5].ftype = tdrpStrDup("int");
      tt->struct_def.fields[5].fname = tdrpStrDup("minExtrapSecs");
      tt->struct_def.fields[5].ptype = INT_TYPE;
      tt->struct_def.fields[5].rel_offset = 
        (char *) &staticBdryLimit.minExtrapSecs - (char *) &staticBdryLimit;
      tt->struct_def.fields[6].ftype = tdrpStrDup("int");
      tt->struct_def.fields[6].fname = tdrpStrDup("maxExtrapSecs");
      tt->struct_def.fields[6].ptype = INT_TYPE;
      tt->struct_def.fields[6].rel_offset = 
        (char *) &staticBdryLimit.maxExtrapSecs - (char *) &staticBdryLimit;
    tt->n_struct_vals = 7;
    tt->struct_vals = (tdrpVal_t *)
        tdrpMalloc(tt->n_struct_vals * sizeof(tdrpVal_t));
      tt->struct_vals[0].s = tdrpStrDup("Static");
      tt->struct_vals[1].d = -999;
      tt->struct_vals[2].d = -999;
      tt->struct_vals[3].d = 0;
      tt->struct_vals[4].d = 50;
      tt->struct_vals[5].i = 0;
      tt->struct_vals[6].i = 0;
    tt++;
    
    // trailing entry has param_name set to NULL
    
    tt->param_name = NULL;
    
    return;
  
  }
