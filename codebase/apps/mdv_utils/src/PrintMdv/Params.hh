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
// Code for program PrintMdv
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
    DEBUG_OFF = 0,
    DEBUG_NORM = 1,
    DEBUG_VERBOSE = 2
  } debug_t;

  typedef enum {
    GET_VOLUME = 0,
    GET_VSECTION = 1,
    GET_TIME_LIST = 2,
    GET_TIME_HEIGHT = 3,
    GET_GIS = 4,
    GET_TABLE = 5,
    GET_ALL_HEADERS = 6
  } get_mode_t;

  typedef enum {
    READ_LATEST = 0,
    READ_CLOSEST = 1,
    READ_FIRST_BEFORE = 2,
    READ_FIRST_AFTER = 3,
    READ_BEST_FORECAST = 4,
    READ_SPECIFIED_FORECAST = 5
  } read_search_mode_t;

  typedef enum {
    VERT_TYPE_PRESSURE = 3,
    VERT_TYPE_Z = 4,
    VERT_FLIGHT_LEVEL = 15
  } vlevel_type_t;

  typedef enum {
    ENCODING_ASIS = 0,
    ENCODING_INT8 = 1,
    ENCODING_INT16 = 2,
    ENCODING_FLOAT32 = 5
  } encoding_type_t;

  typedef enum {
    COMPRESSION_ASIS = -1,
    COMPRESSION_NONE = 0,
    COMPRESSION_RLE = 1,
    COMPRESSION_LZO = 2,
    COMPRESSION_ZLIB = 3,
    COMPRESSION_BZIP = 4,
    COMPRESSION_GZIP = 5,
    COMPRESSION_GZIP_VOL = 6
  } compression_type_t;

  typedef enum {
    SCALING_NONE = 0,
    SCALING_ROUNDED = 1,
    SCALING_INTEGRAL = 2,
    SCALING_DYNAMIC = 3,
    SCALING_SPECIFIED = 4
  } scaling_type_t;

  typedef enum {
    TIME_LIST_VALID = 0,
    TIME_LIST_GEN = 1,
    TIME_LIST_FORECAST = 2,
    TIME_LIST_FIRST = 3,
    TIME_LIST_LAST = 4,
    TIME_LIST_GEN_PLUS_FORECASTS = 5,
    TIME_LIST_VALID_MULT_GEN = 6,
    TIME_LIST_CLOSEST = 7,
    TIME_LIST_FIRST_BEFORE = 8,
    TIME_LIST_FIRST_AFTER = 9,
    TIME_LIST_BEST_FORECAST = 10,
    TIME_LIST_SPECIFIED_FORECAST = 11
  } time_list_mode_t;

  typedef enum {
    FORMAT_MDV = 0,
    FORMAT_XML = 1,
    FORMAT_NCF = 2
  } file_format_t;

  // struct typedefs

  typedef struct {
    int min_lead_time;
    int max_lead_time;
    tdrp_bool_t request_by_gen_time;
  } forecast_constraints_t;

  typedef struct {
    float min_lat;
    float min_lon;
    float max_lat;
    float max_lon;
  } horiz_limits_t;

  typedef struct {
    float lat;
    float lon;
  } vsect_waypt_t;

  typedef struct {
    int nz;
    double minz;
    double dz;
  } remap_z_grid_t;

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

  debug_t debug;

  tdrp_bool_t specify_file_by_time;

  char* url;

  char* path;

  get_mode_t get_mode;

  tdrp_bool_t threaded;

  read_search_mode_t read_search_mode;

  char* read_search_time;

  int read_search_margin;

  int read_forecast_lead_time;

  tdrp_bool_t set_latest_valid_mod_time;

  char* latest_valid_mod_time;

  tdrp_bool_t set_valid_time_search_wt;

  double valid_time_search_wt;

  tdrp_bool_t constrain_forecast_lead_times;

  forecast_constraints_t forecast_constraints;

  tdrp_bool_t read_set_horiz_limits;

  horiz_limits_t read_horiz_limits;

  tdrp_bool_t read_set_vlevel_limits;

  float read_lower_vlevel;

  float read_upper_vlevel;

  tdrp_bool_t read_set_plane_num_limits;

  int read_lower_plane_num;

  int read_upper_plane_num;

  tdrp_bool_t read_set_vlevel_type;

  vlevel_type_t read_vlevel_type;

  encoding_type_t read_encoding_type;

  compression_type_t read_compression_type;

  scaling_type_t read_scaling_type;

  float read_scale;

  float read_bias;

  tdrp_bool_t read_composite;

  tdrp_bool_t read_set_fill_missing;

  tdrp_bool_t read_transform_to_linear;

  tdrp_bool_t read_set_field_nums;

  int *_read_field_nums;
  int read_field_nums_n;

  tdrp_bool_t read_set_field_names;

  char* *_read_field_names;
  int read_field_names_n;

  vsect_waypt_t *_read_vsect_waypts;
  int read_vsect_waypts_n;

  tdrp_bool_t disable_vsection_interp;

  tdrp_bool_t read_set_decimation;

  int decimation_max_nxy;

  tdrp_bool_t remap_z_to_constant_grid;

  remap_z_grid_t remap_z_grid;

  tdrp_bool_t read_time_list_also;

  tdrp_bool_t read_field_file_headers_also;

  tdrp_bool_t read_as_single_part;

  time_list_mode_t time_list_mode;

  char* time_list_start;

  char* time_list_end;

  char* time_list_gen;

  char* time_list_search;

  int time_list_margin;

  tdrp_bool_t print_summary;

  tdrp_bool_t print_data;

  tdrp_bool_t print_native;

  tdrp_bool_t start_at_top;

  tdrp_bool_t print_canonical;

  tdrp_bool_t print_chunks;

  tdrp_bool_t save_to_file;

  tdrp_bool_t no_print;

  char* save_url;

  file_format_t file_format;

  tdrp_bool_t test_no_print;

  int test_n_retrievals;

  char _end_; // end of data region
              // needed for zeroing out data

private:

  void _init();

  mutable TDRPtable _table[74];

  const char *_className;

  bool _exitDeferred;

};

#endif

