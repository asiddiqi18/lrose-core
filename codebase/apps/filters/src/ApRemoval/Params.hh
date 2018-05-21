// *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*
// ** Copyright UCAR (c)
// ** University Corporation for Atmospheric Research(UCAR)
// ** National Center for Atmospheric Research(NCAR)
// ** Boulder, Colorado, USA
// *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*
////////////////////////////////////////////
// Params.hh
//
// TDRP header file for 'Params' class.
//
// Code for program ApRemoval
//
// This header file has been automatically
// generated by TDRP, do not modify.
//
/////////////////////////////////////////////

/**
 *
 * @file Params.hh
 *
 * This class is automatically generated by the Table
 * Driven Runtime Parameters (TDRP) system
 *
 * @class Params
 *
 * @author automatically generated
 *
 */

#ifndef Params_hh
#define Params_hh

using namespace std;

#include <tdrp/tdrp.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cfloat>

// Class definition

class Params {

public:

  // enum typedefs

  typedef enum {
    TDBZ = 0,
    GDZ = 1,
    MVE = 2,
    MSW = 3,
    SDVE = 4,
    SDSW = 5,
    SPIN = 6,
    SIGN = 7,
    RGDZ = 8,
    SRDZ = 9,
    RSINZ = 10
  } interest_field_t;

  typedef enum {
    LAND = 0,
    WATER = 1,
    ALL = 2
  } terrain_t;

  typedef enum {
    APDA = 0,
    SCDA = 1,
    PDA = 2
  } filter_type_t;

  typedef enum {
    AND_FILTER = 0,
    OR_FILTER = 1
  } filter_comb_type_t;

  // struct typedefs

  typedef struct {
    double min_elev;
    double max_elev;
  } filter_range_t;

  typedef struct {
    double latitude;
    double longitude;
  } radar_loc_t;

  typedef struct {
    int azimuth_radius;
    int gate_radius;
  } radius_info_t;

  typedef struct {
    double x1;
    double y1;
    double x2;
    double y2;
    double x3;
    double y3;
    double x4;
    double y4;
    double x5;
    double y5;
    double x6;
    double y6;
  } range_weight_func_t;

  typedef struct {
    interest_field_t interest_field;
    double weight;
    double x1;
    double y1;
    double x2;
    double y2;
    double x3;
    double y3;
    double x4;
    double y4;
    double x5;
    double y5;
    double x6;
    double y6;
  } interest_func_t;

  typedef struct {
    filter_type_t filter_type;
    filter_comb_type_t comb_type;
  } filter_comb_t;

  ///////////////////////////
  // Member functions
  //

  ////////////////////////////////////////////
  // Default constructor
  //

  Params ();

  ////////////////////////////////////////////
  // Copy constructor
  //

  Params (const Params&);

  ////////////////////////////////////////////
  // Destructor
  //

  ~Params ();

  ////////////////////////////////////////////
  // Assignment
  //

  void operator=(const Params&);

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

  int loadFromArgs(int argc, char **argv,
                   char **override_list,
                   char **params_path_p,
                   bool defer_exit = false);

  bool exitDeferred() { return (_exitDeferred); }

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

  int loadApplyArgs(const char *params_path,
                    int argc, char **argv,
                    char **override_list,
                    bool defer_exit = false);

  ////////////////////////////////////////////
  // isArgValid()
  // 
  // Check if a command line arg is a valid TDRP arg.
  //

  static bool isArgValid(const char *arg);

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

  int load(const char *param_file_path,
           char **override_list,
           int expand_env, int debug);

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

  int loadFromBuf(const char *param_source_str,
                  char **override_list,
                  const char *inbuf, int inlen,
                  int start_line_num,
                  int expand_env, int debug);

  ////////////////////////////////////////////
  // loadDefaults()
  //
  // Loads up default params for a given class.
  //
  // See load() for more detailed info.
  //
  //  Returns 0 on success, -1 on failure.
  //

  int loadDefaults(int expand_env);

  ////////////////////////////////////////////
  // sync()
  //
  // Syncs the user struct data back into the parameter table,
  // in preparation for printing.
  //
  // This function alters the table in a consistent manner.
  // Therefore it can be regarded as const.
  //

  void sync() const;

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

  void print(FILE *out, tdrp_print_mode_t mode = PRINT_NORM);

  ////////////////////////////////////////////
  // checkAllSet()
  //
  // Return TRUE if all set, FALSE if not.
  //
  // If out is non-NULL, prints out warning messages for those
  // parameters which are not set.
  //

  int checkAllSet(FILE *out);

  //////////////////////////////////////////////////////////////
  // checkIsSet()
  //
  // Return TRUE if parameter is set, FALSE if not.
  //
  //

  int checkIsSet(const char *param_name);

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

  int arrayRealloc(const char *param_name,
                   int new_array_n);

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

  int array2DRealloc(const char *param_name,
                     int new_array_n1,
                     int new_array_n2);

  ////////////////////////////////////////////
  // freeAll()
  //
  // Frees up all TDRP dynamic memory.
  //

  void freeAll(void);

  ////////////////////////////////////////////
  // usage()
  //
  // Prints out usage message for TDRP args as passed
  // in to loadFromArgs().
  //

  static void usage(ostream &out);

  ///////////////////////////
  // Data Members
  //

  char _start_; // start of data region
                // needed for zeroing out data
                // and computing offsets

  tdrp_bool_t debug;

  tdrp_bool_t info;

  char* instance;

  char* log_dir;

  char* input_fmq_url;

  char* vel_field_name;

  char* refl_field_name;

  char* sw_field_name;

  tdrp_bool_t use_terrain;

  char* terrain_url;

  char* terrain_field_name;

  tdrp_bool_t radar_scans_top_down;

  char* output_fmq_url;

  int output_fmq_size;

  int output_fmq_nslots;

  char* *_filter_field_names;
  int filter_field_names_n;

  filter_range_t filter_range;

  double gate_spacing;

  long max_num_gates;

  double delta_azimuth;

  radar_loc_t radar_location;

  radius_info_t dbz_radius_info;

  radius_info_t vel_radius_info;

  range_weight_func_t range_weight_func;

  interest_func_t *_ap_interest_func;
  int ap_interest_func_n;

  interest_func_t *_ap_confidence_func;
  int ap_confidence_func_n;

  interest_func_t *_sc_interest_func;
  int sc_interest_func_n;

  interest_func_t *_sc_confidence_func;
  int sc_confidence_func_n;

  interest_func_t *_p_interest_func;
  int p_interest_func_n;

  interest_func_t *_p_confidence_func;
  int p_confidence_func_n;

  tdrp_bool_t p_filter_low_dbz;

  double p_low_dbz_threshold;

  double slant_range_dist;

  terrain_t ap_terrain_use_type;

  terrain_t sc_terrain_use_type;

  terrain_t p_terrain_use_type;

  double sc_spin_threshold;

  double ap_spin_threshold;

  double p_spin_threshold;

  double ap_interest_threshold;

  double sc_interest_threshold;

  double p_interest_threshold;

  tdrp_bool_t eov_trigger;

  filter_comb_t *_filter_combination;
  int filter_combination_n;

  tdrp_bool_t write_ap_interest;

  char* ap_interest_fmq_url;

  int ap_interest_fmq_size;

  int ap_interest_fmq_nslots;

  tdrp_bool_t write_sc_interest;

  char* sc_interest_fmq_url;

  int sc_interest_fmq_size;

  int sc_interest_fmq_nslots;

  tdrp_bool_t write_p_interest;

  char* p_interest_fmq_url;

  int p_interest_fmq_size;

  int p_interest_fmq_nslots;

  tdrp_bool_t write_ap_confidence;

  char* ap_confidence_fmq_url;

  int ap_confidence_fmq_size;

  int ap_confidence_fmq_nslots;

  tdrp_bool_t write_sc_confidence;

  char* sc_confidence_fmq_url;

  int sc_confidence_fmq_size;

  int sc_confidence_fmq_nslots;

  tdrp_bool_t write_p_confidence;

  char* p_confidence_fmq_url;

  int p_confidence_fmq_size;

  int p_confidence_fmq_nslots;

  tdrp_bool_t write_feature_data;

  char* feature_fmq_url;

  int feature_fmq_size;

  int feature_fmq_nslots;

  tdrp_bool_t write_terrain;

  char* terrain_output_path;

  char _end_; // end of data region
              // needed for zeroing out data

private:

  void _init();

  mutable TDRPtable _table[85];

  const char *_className;

  bool _exitDeferred;

};

#endif

