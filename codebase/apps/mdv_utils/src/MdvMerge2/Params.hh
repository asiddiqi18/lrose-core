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
// Code for program MdvMerge2
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
    ARCHIVE = 0,
    REALTIME = 1
  } mode_t;

  typedef enum {
    TIME_TRIGGER = 0,
    FILE_TRIGGER = 1,
    FCST_FILES_TRIGGER = 2
  } trigger_t;

  typedef enum {
    MERGE_MIN = 0,
    MERGE_MAX = 1,
    MERGE_MEAN = 2,
    MERGE_SUM = 3,
    MERGE_LATEST = 4,
    MERGE_CLOSEST = 5
  } merge_method_t;

  typedef enum {
    INT8 = 1,
    INT16 = 2,
    FLOAT32 = 5
  } encoding_t;

  typedef enum {
    GENTIME = 0,
    VALIDTIME = 1
  } fcst_data_time_type_t;

  typedef enum {
    OUTPUT_PROJ_FLAT = 0,
    OUTPUT_PROJ_LATLON = 1,
    OUTPUT_PROJ_LAMBERT = 2
  } output_projection_t;

  typedef enum {
    COMPRESSION_NONE = 0,
    COMPRESSION_RLE = 1,
    COMPRESSION_ZLIB = 3,
    COMPRESSION_GZIP = 5
  } output_compression_t;

  // struct typedefs

  typedef struct {
    tdrp_bool_t applyVlevelLimits;
    double vlevelMin;
    double vlevelMax;
  } vlevelLimits_t;

  typedef struct {
    tdrp_bool_t applyPlaneNumLimits;
    int planeNumMin;
    int planeNumMax;
  } planeNumLimits_t;

  typedef struct {
    char* name;
    merge_method_t merge_method;
    encoding_t merge_encoding;
    double merge_scale;
    double merge_bias;
    encoding_t output_encoding;
  } merge_field_t;

  typedef struct {
    char* url;
    char* field_names;
    tdrp_bool_t is_required;
    tdrp_bool_t must_update;
  } input_url_t;

  typedef struct {
    double lat;
    double lon;
  } output_origin_t;

  typedef struct {
    double lat_1;
    double lat_2;
  } output_std_parallels_t;

  typedef struct {
    long nx;
    long ny;
    long nz;
    double minx;
    double miny;
    double minz;
    double dx;
    double dy;
    double dz;
  } grid_t;

  typedef struct {
    char* url;
    char* gridType;
    long nx;
    long ny;
    double minx;
    double miny;
    double dx;
    double dy;
    double lambertTruelat1;
    double lambertTruelat2;
    double flatEarthRotation;
    double originLat;
    double originLon;
  } remap_input_grids_t;

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

  char* instance;

  int procmap_register_interval_secs;

  mode_t mode;

  trigger_t trigger;

  char* fcst_file_trigger_url;

  double *_fcstLeadTimes;
  int fcstLeadTimes_n;

  int time_trigger_interval;

  int time_trigger_offset;

  int time_trigger_margin;

  tdrp_bool_t past_only;

  int min_time_between_file_triggers;

  int min_number_updated_urls;

  int max_realtime_valid_age;

  int sleepAfterTrigger;

  vlevelLimits_t vlevelLimits;

  planeNumLimits_t planeNumLimits;

  tdrp_bool_t use_specified_vlevels;

  double *_vlevel_array;
  int vlevel_array_n;

  merge_field_t *_merge_fields;
  int merge_fields_n;

  char* range_field_name;

  fcst_data_time_type_t fcst_data_time_type;

  input_url_t *_input_urls;
  int input_urls_n;

  char* output_url;

  int output_timestamp_correction;

  tdrp_bool_t write_ldata;

  tdrp_bool_t write_as_forecast;

  output_projection_t output_projection;

  output_origin_t output_origin;

  double output_rotation;

  output_std_parallels_t output_std_parallels;

  grid_t output_grid;

  output_compression_t output_compression;

  char* output_data_set_name;

  char* output_data_set_source;

  tdrp_bool_t copyMetaDataFromInput;

  remap_input_grids_t *_remap_input_grids;
  int remap_input_grids_n;

  char _end_; // end of data region
              // needed for zeroing out data

private:

  void _init();

  mutable TDRPtable _table[44];

  const char *_className;

  bool _exitDeferred;

};

#endif

