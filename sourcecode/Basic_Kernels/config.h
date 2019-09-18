/** Copyright (c) 2019 ETH Zurich, Integrated System Laboratory, Renzo Andri
 *  @file config.h
 *  @brief General configurations for the SW optimizations
 *
 *  This file can be used to select between different implementations for the extended RISC-Y core,
 *  have a look into the tzscale/Basic_Kernels/config.h for the corresponding configurations for the
 *  tzscale implementations.
 *
 * @author Renzo Andri (andrire)
 */

#ifndef ASIP
/// Fixed-point implementation
#define FixedPt 1
/// Use SIMD instructions
#define SIMD

/// Prints for Debug active
// #define DEBUG
// #define DEBUG_LSTM

/// Print out results
#define PRINTF_ACTIVE



/// Output FM tiling
// #define FMOUTTILING

/// Use lw+incr+sdotp VLIW extension
#define VLIWEXT
/// Do activation on the fly
#define DOACTONTHEFLY
/// On RISC-Y use TANH and sigmoid extension
#define PULP_USETANHSIG


#ifdef PULP_USETANHSIG
/// Select tanh function to be used
#define generic_tanh(value) pulpRNNExt_tanh(value)
/// Select sigmoid function to be used
#define generic_sig(value) pulpRNNExt_sig(value);
#else
#define generic_tanh(value) Tanh(value)
#define generic_sig(value) sig(value);
#endif

#endif
