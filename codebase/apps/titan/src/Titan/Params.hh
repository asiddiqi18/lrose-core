// *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*
// ** Copyright UCAR (c) 1992 - 2018
// ** University Corporation for Atmospheric Research(UCAR)
// ** National Center for Atmospheric Research(NCAR)
// ** Boulder, Colorado, USA
// *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*
////////////////////////////////////////////
// Params.hh
//
// TDRP header file for 'Params' class.
//
// Code for program Titan
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
    DEBUG_VERBOSE = 2,
    DEBUG_EXTRA = 3
  } debug_t;

  typedef enum {
    ARCHIVE = 0,
    REALTIME = 1,
    RETRACK = 2,
    FORECAST = 3
  } mode_t;

  typedef enum {
    PRECIP_FROM_COLUMN_MAX = 0,
    PRECIP_AT_SPECIFIED_HT = 1,
    PRECIP_AT_LOWEST_VALID_HT = 2,
    PRECIP_FROM_LOWEST_AVAILABLE_REFL = 3
  } precip_mode_t;

  typedef enum {
    SPECIFY_SOUNDING = 0,
    READ_SOUNDING_FROM_SPDB = 1
  } sounding_mode_t;

  typedef enum {
    HAIL_METRICS = 0,
    NEXRAD_HDA = 1
  } hail_detection_mode_t;

  typedef enum {
    TREND = 0,
    PARABOLIC = 1,
    REGRESSION = 2
  } forecast_type_t;

  // struct typedefs

  typedef struct {
    int hour;
    int min;
  } restart_time_t;

  typedef struct {
    char* name;
    int num;
  } field_t;

  typedef struct {
    int nz;
    double minz;
    double dz;
  } remap_z_grid_t;

  typedef struct {
    double dbz_threshold;
    double min_fraction_all_parts;
    double min_fraction_each_part;
    double min_area_each_part;
  } dual_threshold_t;

  typedef struct {
    double coeff;
    double expon;
  } zr_t;

  typedef struct {
    double height_m;
    double temp_c;
    double pressure_hpa;
    double rh_percent;
    double wspeed_mps;
    double wdirn_deg;
  } sounding_entry_t;

  typedef struct {
    double min_val;
    double max_val;
  } sounding_data_range_t;

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

  mode_t mode;

  tdrp_bool_t auto_restart;

  restart_time_t restart_time;

  int restart_overlap_period;

  char* input_url;

  int max_realtime_valid_age;

  int input_search_sleep_msecs;

  field_t dbz_field;

  tdrp_bool_t use_column_max_dbz;

  double column_min_ht_km;

  double column_max_ht_km;

  tdrp_bool_t negate_dbz_field;

  tdrp_bool_t vel_available;

  field_t vel_field;

  double vel_to_m_per_sec_scale;

  tdrp_bool_t remap_z_to_constant_grid;

  remap_z_grid_t remap_z_grid;

  double low_dbz_threshold;

  double high_dbz_threshold;

  int min_grid_overlap;

  tdrp_bool_t set_dbz_threshold_for_tops;

  double tops_dbz_threshold;

  tdrp_bool_t use_dual_threshold;

  dual_threshold_t dual_threshold;

  tdrp_bool_t create_dual_threshold_files;

  char* dual_threshold_url;

  double base_threshold;

  double top_threshold;

  double min_storm_size;

  double max_storm_size;

  tdrp_bool_t check_range_limits;

  tdrp_bool_t check_second_trip;

  double sectrip_vert_aspect;

  double sectrip_horiz_aspect;

  double sectrip_orientation_error;

  tdrp_bool_t identify_convective_regions;

  double convection_finder_min_valid_height;

  double convection_finder_max_valid_height;

  double convection_finder_min_valid_dbz;

  double dbz_threshold_for_definite_convection;

  double convective_radius_km;

  double convection_finder_texture_radius_km;

  double convection_finder_min_valid_fraction_for_texture;

  double convection_finder_min_texture_value;

  tdrp_bool_t convection_finder_write_debug_files;

  char* convection_finder_output_url;

  double hail_dbz_threshold;

  zr_t ZR;

  zr_t ZM;

  precip_mode_t precip_computation_mode;

  double precip_min_ht;

  double precip_max_ht;

  double precip_plane_ht;

  double dbz_hist_interval;

  sounding_mode_t sounding_mode;

  sounding_entry_t *_specified_sounding;
  int specified_sounding_n;

  char* sounding_spdb_url;

  int sounding_search_time_margin_secs;

  char* sounding_location_name;

  tdrp_bool_t sounding_check_pressure_range;

  sounding_data_range_t sounding_required_pressure_range_hpa;

  tdrp_bool_t sounding_check_height_range;

  sounding_data_range_t sounding_required_height_range_m;

  tdrp_bool_t sounding_check_pressure_monotonically_decreasing;

  hail_detection_mode_t hail_detection_mode;

  debug_t debug_hail_metrics;

  tdrp_bool_t debsounding_check_height_range;

  zr_t hail_ZM;

  double hail_mass_dbz_threshold;

  double FOKR_cat1_zmax_thresh;

  double FOKR_cat2_zmax_thresh;

  double FOKR_cat3_zmax_thresh;

  double FOKR_cat4_zmax_thresh;

  char* storm_data_dir;

  tdrp_bool_t store_storm_runs;

  tdrp_bool_t create_verification_files;

  char* verify_url;

  tdrp_bool_t perform_tracking;

  double tracking_max_speed;

  int tracking_max_delta_time;

  double tracking_weight_distance;

  double tracking_weight_delta_cube_root_volume;

  tdrp_bool_t tracking_use_runs_for_overlaps;

  double tracking_min_sum_fraction_overlap;

  forecast_type_t tracking_forecast_type;

  int tracking_parabolic_growth_period;

  tdrp_bool_t tracking_zero_growth;

  tdrp_bool_t tracking_zero_decay;

  double *_tracking_forecast_weights;
  int tracking_forecast_weights_n;

  double tracking_max_speed_for_valid_forecast;

  int tracking_min_history_for_valid_forecast;

  tdrp_bool_t tracking_scale_forecasts_by_history;

  double tracking_history_for_scaling;

  tdrp_bool_t tracking_limit_rel_speed_change;

  double tracking_rel_speed_max_change;

  int tracking_rel_speed_min_nscans;

  tdrp_bool_t tracking_smooth_invalid_forecasts;

  tdrp_bool_t tracking_spatial_smoothing;

  double tracking_smoothing_radius;

  int tracking_smoothing_min_nstorms;

  tdrp_bool_t smoothing_weight_uses_inverse_distance;

  tdrp_bool_t smoothing_weight_uses_mean_dbz;

  tdrp_bool_t smoothing_weight_uses_top;

  tdrp_bool_t tracking_smooth_fast_growth_decay;

  double tracking_smoothing_growth_threshold;

  double tracking_smoothing_decay_threshold;

  tdrp_bool_t tracking_smooth_erratic_only;

  double erratic_forecast_speed_error;

  double erratic_forecast_direction_error;

  tdrp_bool_t override_early_storm_motion_using_field_tracker;

  char* field_tracker_url;

  char* field_tracker_U_motion_name;

  char* field_tracker_V_motion_name;

  int field_tracker_search_margin_secs;

  int field_tracker_realtime_wait_secs;

  double field_tracker_search_radius_km;

  int field_tracker_initial_period_secs;

  int field_tracker_transition_period_secs;

  char _end_; // end of data region
              // needed for zeroing out data

private:

  void _init();

  mutable TDRPtable _table[149];

  const char *_className;

  bool _exitDeferred;

};

#endif

