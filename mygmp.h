
// Contains prototypes to most of the major GMP and MPFR functions.

// See "mygmp.c" for details.

// NOTE: "size_t" is "unsigned int" on 32-bit platforms, and
// "unsigned long long" on 64-bit platforms.

#pragma once

#ifndef _MYGMP_H_
#define _MYGMP_H_

#include <stdio.h>

#ifndef NULL
#define NULL 0
#endif

// comment out this line when releasing the software:
//#define TEST_FOO

#ifdef __cplusplus
extern "C" {
#endif

#ifdef TEST_FOO
extern void foo(void);
#endif

extern int version();

extern void generic_free(void * p);
extern size_t sizeof_int();
extern size_t sizeof_q();
extern size_t sizeof_float();

// BEGIN mpfr FUNCTIONS:

// BEGIN IMPIMENTATION OF mpfr FUNCTIONS:

extern size_t sizeof_f();
extern void * allocate_f();
extern void register_f(void * p);
extern void register_f2(void * p, long prec);
extern void clear_f(void * p);
extern void clear_f_cache();

extern long f_get_default_prec();
extern void f_set_default_prec(long prec);
extern long f_get_prec(void * p);
extern void f_set_prec(void * p, long prec);

// typedef enum {
//   MPFR_RNDN=0,  /* round to nearest, with ties to even */
//   MPFR_RNDZ,    /* round toward zero */
//   MPFR_RNDU,    /* round toward +Inf */
//   MPFR_RNDD,    /* round toward -Inf */
//   MPFR_RNDA,    /* round away from zero */
//   MPFR_RNDF,    /* faithful rounding (not implemented yet) */
//   MPFR_RNDNA=-1 /* round to nearest, with ties away from zero (mpfr_round) */
// } mpfr_rnd_t;

extern int f_set(void * p, void * op, int rnd); // mpfr_rnd_t rnd
extern int f_set_ui(void * p, unsigned long int op, int rnd);
extern int f_set_si(void * p, long int op, int rnd);
//extern int f_set_uj(void * p, unsigned long long op, int rnd);
//extern int f_set_sj(void * p, long long op, int rnd);
extern int f_set_flt(void * p, float op, int rnd);
extern int f_set_d(void * p, double op, int rnd);
extern int f_set_ld(void * p, long double op, int rnd); // "long double" is "double" on Microsoft's compiler
//int f_set_float128(void * p, __float128 op, int rnd);
//int f_set_decimal64(void * p, _Decimal64 op, int rnd);
extern int f_set_int(void * p, void * op1, int rnd);
extern int f_set_q(void * p, void * op1, int rnd);
extern int f_set_float(void * p, void * op1, int rnd);
extern int f_set_ui_2exp(void * p, unsigned long int op, long e, int rnd);
extern int f_set_si_2exp(void * p, long int op, long e, int rnd);
//extern int f_set_uj_2exp(void * p, unsigned long long op, long long e, int rnd);
//extern int f_set_sj_2exp(void * p, long long op, long long e, int rnd);
extern int f_set_int_2exp(void * p, void * op, long e, int rnd);
extern int f_set_str(void * p, const char *s, int base, int rnd);
extern int f_strtofr(void * p, const char *nptr, char **endptr, int base, int rnd);
extern void f_set_nan(void * p);
extern void f_set_inf(void * p, int sign);
extern void f_set_zero(void * p, int sign);

extern void f_swap(void * x, void * y); // should be faster than other ways of doing it

// Initialize x and set its value from the string s in base base, rounded in the direction rnd
extern int f_init_set_str(void * p, const char *s, int base, int rnd);

// Conversion functions

extern float f_get_flt(void * p, int rnd);
extern double f_get_d(void * p, int rnd);
extern long double f_get_ld(void * p, int rnd); // "long double" is "double" on Microsoft's compiler
extern long f_get_si(void * p, int rnd);
extern unsigned long f_get_ui(void * p, int rnd);
//extern long long f_get_sj(void * p, int rnd);
//extern unsigned long long f_get_uj(void * p, int rnd);
extern double f_get_d_2exp(long *exp, void * p, int rnd);
extern long double f_get_ld_2exp(long *exp, void * p, int rnd); // "long double" is "double" on Microsoft's compiler
extern int f_frexp(long *exp, void * y, void * x, int rnd);
extern long f_get_int_2exp(void * r, void * p);
extern int f_get_int(void * r, void * p, int rnd);
//extern void f_get_q(void * r, void * p);
extern int f_get_float(void * r, void * p, int rnd);
extern char * f_get_str(char *str, long *expptr, int b, size_t n, void * p, int rnd);
extern void f_free_str(char *str);

extern int f_fits_ulong_p(void * p, int rnd);
extern int f_fits_slong_p(void * p, int rnd);
extern int f_fits_uint_p(void * p, int rnd);
extern int f_fits_sint_p(void * p, int rnd);
extern int f_fits_ushort_p(void * p, int rnd);
extern int f_fits_sshort_p(void * p, int rnd);
extern int f_fits_uintmax_p(void * p, int rnd);
extern int f_fits_intmax_p(void * p, int rnd);

// Basic Arithmetic Functions

extern int f_add(void * r, void * p, void * op, int rnd);
extern int f_add_ui(void * r, void * p, unsigned long int op2, int rnd);
extern int f_add_si(void * r, void * p, long int op2, int rnd);
extern int f_add_d(void * r, void * p, double op2, int rnd);
extern int f_add_int(void * r, void * p, void * op2, int rnd);
extern int f_add_q(void * r, void * p, void * op2, int rnd);
extern int f_sub(void * r, void * op1, void * op2, int rnd);
extern int f_ui_sub(void * r, unsigned long int op1, void * op2, int rnd);
extern int f_sub_ui(void * r, void * op1, unsigned long int op2, int rnd);
extern int f_si_sub(void * r, long int op1, void * op2, int rnd);
extern int f_sub_si(void * r, void * op1, long int op2, int rnd);
extern int f_d_sub(void * r, double op1, void * op2, int rnd);
extern int f_sub_d(void * r, void * op1, double op2, int rnd);
extern int f_int_sub(void * r, void * op1, void * op2, int rnd);
extern int f_sub_int(void * r, void * op1, void * op2, int rnd);
extern int f_sub_q(void * r, void * op1, void * op2, int rnd);
extern int f_mul(void * r, void * p, void * op, int rnd);
extern int f_mul_ui(void * r, void * p, unsigned long int op2, int rnd);
extern int f_mul_si(void * r, void * p, long int op2, int rnd);
extern int f_mul_d(void * r, void * p, double op2, int rnd);
extern int f_mul_int(void * r, void * p, void * op2, int rnd);
extern int f_mul_q(void * r, void * p, void * op2, int rnd);

// Not to be confused with "sqrt", Set rop to op^2 rounded in the direction rnd:
extern int f_sqr(void * r, void * p, int rnd);

extern int f_div(void * r, void * op1, void * op2, int rnd);
extern int f_ui_div(void * r, unsigned long int op1, void * op2, int rnd);
extern int f_div_ui(void * r, void * op1, unsigned long int op2, int rnd);
extern int f_si_div(void * r, long int op1, void * op2, int rnd);
extern int f_div_si(void * r, void * op1, long int op2, int rnd);
extern int f_d_div(void * r, double op1, void * op2, int rnd);
extern int f_div_d(void * r, void * op1, double op2, int rnd);
extern int f_div_int(void * r, void * p, void * op2, int rnd);
extern int f_div_q(void * r, void * p, void * op2, int rnd);
extern int f_sqrt(void * r, void * p, int rnd);
extern int f_sqrt_ui(void * r, unsigned long int op, int rnd);
extern int f_rec_sqrt(void * r, void * p, int rnd);
extern int f_cbrt(void * r, void * p, int rnd);
//extern int f_rootn_ui(void * r, void * p, unsigned long int k, int rnd);
extern int f_root(void * r, void * p, unsigned long int k, int rnd);
extern int f_pow(void * r, void * p, void * op, int rnd);
extern int f_pow_ui(void * r, void * p, unsigned long int op2, int rnd);
extern int f_pow_si(void * r, void * p, long int op2, int rnd);
extern int f_pow_int(void * r, void * p, void * op2, int rnd);
extern int f_ui_pow_ui(void * r, unsigned long int op1, unsigned long int op2, int rnd);
extern int f_ui_pow(void * r, unsigned long int op1, void * op2, int rnd);
extern int f_neg(void * r, void * p, int rnd);
extern int f_abs(void * r, void * p, int rnd);
extern int f_dim(void * r, void * op1, void * op2, int rnd); // finds the absolute difference between two numbers
extern int f_mul_2ui(void * r, void * p, unsigned long int op2, int rnd);
extern int f_mul_2si(void * r, void * p, long int op2, int rnd);
extern int f_div_2ui(void * r, void * p, unsigned long int op2, int rnd);
extern int f_div_2si(void * r, void * p, long int op2, int rnd);

// Comparison Functions

extern int f_cmp(void * p, void * op2);
extern int f_cmp_ui(void * p, unsigned long int op2);
extern int f_cmp_si(void * p, long int op2);
extern int f_cmp_d(void * p, double op2);
extern int f_cmp_ld(void * p, long double op2);
extern int f_cmp_int(void * p, void * op2);
extern int f_cmp_q(void * p, void * op2);
extern int f_cmp_float(void * p, void * op2);
extern int f_cmp_ui_2exp(void * op1, unsigned long int op2, long e);
extern int f_cmp_si_2exp(void * op1, long int op2, long e);
extern int f_cmpabs(void * op1, void * op2);
extern int f_nan_p(void * op);
extern int f_inf_p(void * op);
extern int f_number_p(void * op);
extern int f_zero_p(void * op);
extern int f_regular_p(void * op);
extern int f_sgn(void * op);
extern int f_greater_p(void * op1, void * op2);
extern int f_greaterequal_p(void * op1, void * op2);
extern int f_less_p(void * op1, void * op2);
extern int f_lessequal_p(void * op1, void * op2);
extern int f_equal_p(void * op1, void * op2);
extern int f_lessgreater_p(void * op1, void * op2);
extern int f_unordered_p(void * op1, void * op2);

// Special Functions

extern int f_log(void * r, void * p, int rnd);
//extern int f_log_ui(void * r, unsigned long op, int rnd);
extern int f_log2(void * r, void * p, int rnd);
extern int f_log10(void * r, void * p, int rnd);
extern int f_log1p(void * r, void * p, int rnd);
extern int f_exp(void * r, void * p, int rnd);
extern int f_exp2(void * r, void * p, int rnd);
extern int f_exp10(void * r, void * p, int rnd);
extern int f_expm1(void * r, void * p, int rnd);
extern int f_cos(void * r, void * p, int rnd);
extern int f_sin(void * r, void * p, int rnd);
extern int f_tan(void * r, void * p, int rnd);
extern int f_sin_cos(void * sop, void * cop, void * op, int rnd);
extern int f_sec(void * r, void * p, int rnd);
extern int f_csc(void * r, void * p, int rnd);
extern int f_cot(void * r, void * p, int rnd);
extern int f_acos(void * r, void * p, int rnd);
extern int f_asin(void * r, void * p, int rnd);
extern int f_atan(void * r, void * p, int rnd);
extern int f_atan2(void * rop, void * y, void * x, int rnd);
extern int f_cosh(void * r, void * p, int rnd);
extern int f_sinh(void * r, void * p, int rnd);
extern int f_tanh(void * r, void * p, int rnd);
extern int f_sinh_cosh(void * sop, void * cop, void * op, int rnd);
extern int f_sech(void * r, void * p, int rnd);
extern int f_csch(void * r, void * p, int rnd);
extern int f_coth(void * r, void * p, int rnd);
extern int f_acosh(void * r, void * p, int rnd);
extern int f_asinh(void * r, void * p, int rnd);
extern int f_atanh(void * r, void * p, int rnd);

extern int f_fac_ui(void * rop, unsigned long int op, int rnd);
extern int f_eint(void * r, void * p, int rnd);
extern int f_li2(void * r, void * p, int rnd);
extern int f_gamma(void * r, void * p, int rnd);
//extern int f_gamma_inc(void * rop, void * op, void * op2, int rnd);
extern int f_lngamma(void * r, void * p, int rnd);
extern int f_lgamma(void * rop, int *signp, void * op, int rnd);
extern int f_digamma(void * r, void * p, int rnd);
//extern int f_beta(void * rop, void * op1, void * op2, int rnd);
extern int f_zeta(void * r, void * p, int rnd);
extern int f_zeta_ui(void * rop, unsigned long op, int rnd);
extern int f_erf(void * r, void * p, int rnd);
extern int f_erfc(void * r, void * p, int rnd);
extern int f_j0(void * r, void * p, int rnd);
extern int f_j1(void * r, void * p, int rnd);
extern int f_jn(void * rop, long n, void * op, int rnd);
extern int f_y0(void * r, void * p, int rnd);
extern int f_y1(void * r, void * p, int rnd);
extern int f_yn(void * rop, long n, void * op, int rnd);
extern int f_fma(void * rop, void * op1, void * op2, void * op3, int rnd);
extern int f_fms(void * rop, void * op1, void * op2, void * op3, int rnd);
//extern int f_fmma(void * rop, void * op1, void * op2, void * op3, void * op4, int rnd);
//extern int f_fmms(void * rop, void * op1, void * op2, void * op3, void * op4, int rnd);
extern int f_agm(void * rop, void * op1, void * op2, int rnd);
extern int f_hypot(void * rop, void * x, void * y, int rnd);
extern int f_ai(void * r, void * p, int rnd);

extern int f_const_log2(void * rop, int rnd);
extern int f_const_pi(void * rop, int rnd);
extern int f_const_euler(void * rop, int rnd);
extern int f_const_catalan(void * rop, int rnd);
extern void f_free_cache(void);
//extern void f_free_pool(void);
//extern int f_mp_memory_cleanup(void);

extern int f_sum(void * rop, void * tab, unsigned long int n, int rnd);

// Input and Output Functions
extern size_t f_out_str_filename(const char * filename, int base, size_t n, void * op, int rnd);
extern size_t f_inp_str_filename(void * rop, const char * filename, int base, int rnd);
extern void f_dump(void * op);

// Formatted Output Functions

extern int f_fprintf_filename(const char * filename, const char *format, void * op);
extern int f_printf(const char *format, void * op);
extern int f_snprintf(char *buf, size_t n, const char *format, void * op);
extern int f_asprintf(char **str, const char *format, void * op);

// Integer and Remainder Related Functions

extern int f_rint(void * rop, void * op, int rnd);
extern int f_ceil(void * rop, void * op);
extern int f_floor(void * rop, void * op);
extern int f_round(void * rop, void * op);
extern int f_trunc(void * rop, void * op);
extern int f_rint_ceil(void * rop, void * op, int rnd);
extern int f_rint_floor(void * rop, void * op, int rnd);
extern int f_rint_round(void * rop, void * op, int rnd);
extern int f_rint_trunc(void * rop, void * op, int rnd);
extern int f_frac(void * rop, void * op, int rnd); // as opposed to "f_frac"
extern int f_modf(void * iop, void * fop, void * op, int rnd);
extern int f_fmod(void * r, void * x, void * y, int rnd);
//extern int f_fmodquo(void * r, long* q, void * x, void * y, int rnd);
extern int f_remainder(void * r, void * x, void * y, int rnd);
extern int f_remquo(void * r, long* q, void * x, void * y, int rnd);
extern int f_integer_p(void * op);

// Rounding-Related Functions

extern void f_set_default_rounding_mode(int rnd);
extern int f_get_default_rounding_mode(void);
extern int f_prec_round(void * x, long prec, int rnd);
extern int f_can_round(void * b, long err, int rnd1, int rnd2, long prec);
extern long f_min_prec(void * x);
extern const char * f_print_rnd_mode(int rnd);

// Miscellaneous Functions

extern void f_nexttoward(void * x, void * y);
extern void f_nextabove(void * x);
extern void f_nextbelow(void * x);
extern int f_min(void * rop, void * op1, void * op2, int rnd);
extern int f_max(void * rop, void * op1, void * op2, int rnd);
extern long f_get_exp(void * x);
extern int f_set_exp(void * x, long e);
extern int f_signbit(void * op);
extern int f_setsign(void * rop, void * op, int s, int rnd);
extern int f_copysign(void * rop, void * op1, void * op2, int rnd);

extern const char * f_get_version (void);
extern long f_MPFR_VERSION();
extern long f_MPFR_VERSION_MAJOR();
extern long f_MPFR_VERSION_MINOR();
extern long f_MPFR_VERSION_PATCHLEVEL();
extern long f_MPFR_VERSION_NUM(long major, long minor, long patchlevel);
extern const char * f_get_patches(void);
extern int f_buildopt_tls_p(void);
extern int f_buildopt_decimal_p(void);
extern int f_buildopt_gmpinternals_p (void);

// Exception Related Functions

extern long f_get_emin(void);
extern long f_get_emax(void);
extern int f_set_emin(long exp);
extern int f_set_emax(long exp);
extern long f_get_emin_min(void);
extern long f_get_emin_max(void);
extern long f_get_emax_min(void);
extern long f_get_emax_max(void);
extern int f_check_range(void * x, int t, int rnd);
extern int f_subnormalize(void * x, int t, int rnd);
extern void f_clear_underflow(void);
extern void f_clear_overflow(void);
extern void f_clear_divby0(void);
extern void f_clear_nanflag(void);
extern void f_clear_inexflag(void);
extern void f_clear_erangeflag(void);
extern void f_clear_flags(void);
extern void f_set_underflow(void);
extern void f_set_overflow(void);
extern void f_set_divby0(void);
extern void f_set_nanflag(void);
extern void f_set_inexflag(void);
extern void f_set_erangeflag(void);

extern int f_underflow_p(void);
extern int f_overflow_p(void);
extern int f_divby0_p(void);
extern int f_nanflag_p(void);
extern int f_inexflag_p(void);
extern int f_erangeflag_p(void);

// END mpfr FUNCTIONS.

// BEGIN INT FUNCTIONS:

extern void * allocate_int();
extern void register_int(void * p);
extern void clear_int(void * p);

extern void int_set(void * dst, void * src);
extern void int_set_ui(void * rop, unsigned long int op);
extern void int_set_si(void * rop, signed long int op);
extern void int_set_d(void * rop, double op);
extern void int_set_q(void * rop, void * op);
extern void int_set_float(void * rop, void * op);

extern int int_set_str(void * dst, const char *str, int base);

unsigned long int int_get_ui(void * op);
signed long int int_get_si(void * op);
double int_get_d(void * op);
double int_get_d_2exp(signed long int *exp, void * op);

extern char * int_get_str(char *str, int base, void * src);

extern void int_add(void * dst, void * op1, void * op2);
extern void int_add_ui(void * dst, void * op1, unsigned long int op2);
extern void int_sub(void * dst, void * op1, void * op2);
extern void int_sub_ui(void * dst, void * op1, unsigned long int op2);
extern void int_ui_sub(void * dst, unsigned long int op1, void * op2);
extern void int_mul(void * dst, void * op1, void * op2);
extern void int_mul_si(void * dst, void * op1, long int op2);
extern void int_mul_ui(void * dst, void * op1, unsigned long int op2);
extern void int_addmul(void * dst, void * op1, void * op2);
extern void int_addmul_ui(void * dst, void * op1, unsigned long int op2);
extern void int_submul(void * dst, void * op1, void * op2);
extern void int_submul_ui(void * dst, void * op1, unsigned long int op2);
extern void int_mul_2exp(void * dst, void * op1, unsigned long int op2);
extern void int_neg(void * dst, void * op1);
extern void int_abs(void * dst, void * op1);

extern void int_cdiv_q(void * dst, void * op1, void * op2);
extern void int_cdiv_r(void * dst, void * op1, void * op2);
extern void int_cdiv_qr(void * dstq, void * dstr, void * op1, void * op2);
extern unsigned long int int_cdiv_q_ui(void * dstq, void * n, unsigned long int d);
extern unsigned long int int_cdiv_r_ui(void * dstr, void * n, unsigned long int d);
extern unsigned long int int_cdiv_qr_ui(void * dstq, void * dstr, void * n, unsigned long int d);
extern unsigned long int int_cdiv_ui (void * n, unsigned long int d);
extern void int_cdiv_q_2exp(void * dstq, void * n, unsigned long b);
extern void int_cdiv_r_2exp(void * dstr, void * n, unsigned long b);
extern void int_fdiv_q(void * dstq, void * op1, void * op2);
extern void int_fdiv_r(void * dstr, void * op1, void * op2);
extern void int_fdiv_qr(void * dstq, void * dstr, void * n, void * d);
extern unsigned long int int_fdiv_q_ui(void * dstq, void * n, unsigned long int d);
extern unsigned long int int_fdiv_r_ui(void * dstr, void * n, unsigned long int d);
extern unsigned long int int_fdiv_qr_ui(void * dstq, void * dstr, void * n, unsigned long int d);
extern unsigned long int int_fdiv_ui(void * n, unsigned long int d);
extern void int_fdiv_q_2exp(void * dstq, void * n, unsigned long b);
extern void int_fdiv_r_2exp(void * dstr, void * n, unsigned long b);
extern void int_tdiv_q(void * dstq, void * op1, void * op2);
extern void int_tdiv_r(void * dstr, void * op1, void * op2);
extern void int_tdiv_qr(void * dstq, void * dstr, void * n, void * d);
extern unsigned long int int_tdiv_q_ui(void * dstq, void * n, unsigned long int d);
extern unsigned long int int_tdiv_r_ui(void * dstr, void * n, unsigned long int d);
extern unsigned long int int_tdiv_qr_ui(void * dstq, void * dstr, void * n, unsigned long int d);
extern unsigned long int int_tdiv_ui(void * n, unsigned long int d);
extern void int_tdiv_q_2exp(void * dstq, void * n, unsigned long b);
extern void int_tdiv_r_2exp(void * dstr, void * n, unsigned long b);
extern void int_mod(void * r, void * n, void * d);
extern unsigned long int int_mod_ui(void * dstr, void * n, unsigned long int d);
extern void int_divexact(void * dstq, void * n, void * d);
extern void int_divexact_ui(void * dstq, void * n, unsigned long d);
extern int int_divisible_p(void * n, void * d);
extern int int_divisible_ui_p(void * n, unsigned long int d);
extern int int_divisible_2exp_p(void * n, unsigned long b);
extern int int_congruent_p(void * n, void * c, void * d);
extern int int_congruent_ui_p(void * n, unsigned long int c, unsigned long int d);
extern int int_congruent_2exp_p(void * n, void * c, unsigned long b);

extern void int_powm(void * dst, void * base, void * exp, void * mod);
extern void int_powm_ui(void * dst, void * base, unsigned long int exp, void * mod);
extern void int_powm_sec(void * dst, void * base, void * exp, void * mod);
// It is required that exp > 0 and that mod is odd.
// This function is designed to take the same time and have the same cache access patterns for any two same-size arguments, assuming that function arguments are placed at the same position and that the machine state is identical upon function entry. This function is intended for cryptographic purposes, where resilience to side-channel attacks is desired.
extern void int_pow_ui(void * dst, void * base, unsigned long int exp);
extern void int_ui_pow_ui(void * dst, unsigned long int base, unsigned long int exp);

extern int int_root(void * dst, void * op, unsigned long int n);
extern void int_rootrem(void * root, void * rem, void * u, unsigned long int n);
extern void int_sqrt(void * dst, void * op);
extern void int_sqrtrem(void * rop1, void * rop2, void * op);
extern int int_perfect_power_p(void * op);
extern int int_perfect_square_p(void * op);

// Number Theoretic Functions

extern int int_probab_prime_p(void * n, int reps);
extern void int_nextprime(void * rop, void * op);
extern void int_gcd(void * rop, void * op1, void * op2);
extern unsigned long int int_gcd_ui(void * rop, void * op1, unsigned long int op2);
extern void int_gcdext(void * g, void * s, void * t, void * a, void * b);
extern void int_lcm(void * rop, void * op1, void * op2);
extern void int_lcm_ui(void * rop, void * op1, unsigned long op2);
extern int int_invert(void * rop, void * op1, void * op2);
extern int int_jacobi(void * a, void * b);
extern int int_legendre(void * a, void * p);
extern int int_kronecker(void * a, void * b);
extern int int_kronecker_si(void * a, long b);
extern int int_kronecker_ui(void * a, unsigned long b);
extern int int_si_kronecker(long a, void * b);
extern int int_ui_kronecker(unsigned long a, void * b);
extern unsigned long int_remove(void * rop, void * op, void * f);
extern void int_fac_ui(void * rop, unsigned long int n);
extern void int_2fac_ui(void * rop, unsigned long int n);
extern void int_mfac_uiui(void * rop, unsigned long int n, unsigned long int m);
extern void int_primorial_ui(void * rop, unsigned long int n);
extern void int_bin_ui(void * rop, void * n, unsigned long int k);
extern void int_bin_uiui(void * rop, unsigned long int n, unsigned long int k);
extern void int_fib_ui(void * fn, unsigned long int n);
extern void int_fib2_ui(void * fn, void * fnsub1, unsigned long int n);
extern void int_lucnum_ui(void * ln, unsigned long int n);
extern void int_lucnum2_ui(void * ln, void * lnsub1, unsigned long int n);

extern int int_cmp(void * op1, void * op2);
extern int int_cmp_d(void * op1, double op2);
extern int int_cmp_si(void * op1, signed long int op2);
extern int int_cmp_ui(void * op1, unsigned long int op2);
extern int int_cmpabs(void * op1, void * op2);
extern int int_cmpabs_d(void * op1, double op2);
extern int int_cmpabs_ui(void * op1, unsigned long int op2);
extern int int_sgn(void * op);
extern void int_and(void * rop, void * op1, void * op2);
extern void int_ior(void * rop, void * op1, void * op2);
extern void int_xor(void * rop, void * op1, void * op2);
extern void int_com(void * rop, void * op);
extern unsigned long int_popcount(void * op);
extern unsigned long int_hamdist(void * op1, void * op2);
extern unsigned long int_scan0(void * op, unsigned long starting_bit);
extern unsigned long int_scan1(void * op, unsigned long starting_bit);
extern void int_setbit(void * rop, unsigned long bit_index);
extern void int_clrbit(void * rop, unsigned long bit_index);
extern void int_combit(void * rop, unsigned long bit_index);
extern int int_tstbit(void * op, unsigned long bit_index);

extern size_t int_out_str_filename(const char * filename, int base, void * op);
extern size_t int_inp_str_filename(void * rop, const char * filename, int base);
extern size_t int_out_raw_filename(const char * filename, void * op);
extern size_t int_inp_raw_filename(void * rop, const char * filename);

extern void int_import(void * rop, size_t count, int order, size_t size, int endian, size_t nails, const void *op);
extern void * int_export(void * rop, size_t * countp, int order, size_t size, int endian, size_t nails, const void * op);

// Random number functions:

extern void int_urandomb(void * rop, void * state, unsigned long n);
extern void int_urandomm(void * rop, void * state, void * n);
extern void int_rrandomb(void * rop, void * state, unsigned long n);
extern void int_random(void * rop, long max_size);
extern void int_random2(void * rop, long max_size);

// 9.1 Random State Initialization

extern size_t sizeof_randstate();

extern void int_randinit_default(void * state);
extern void int_randinit_mt(void * state);
extern void int_randinit_lc_2exp(void * state, void * a, unsigned long c, unsigned long m2exp);
extern int int_randinit_lc_2exp_size(void * state, unsigned long size);
extern void int_randinit_set(void * rop, void * op);
extern void int_randclear(void * state);

// 9.2 Random State Seeding
extern void int_randseed(void * state, void * seed);
extern void int_randseed_ui(void * state, unsigned long int seed);

// 9.3 Random State Miscellaneous
extern unsigned long int_urandomb_ui(void * state, unsigned long n);
extern unsigned long int_urandomm_ui(void * state, unsigned long n);


extern int int_fits_ulong_p(void * op);
extern int int_fits_slong_p(void * op);
extern int int_fits_uint_p(void * op);
extern int int_fits_sint_p(void * op);
extern int int_fits_ushort_p(void * op);
extern int int_fits_sshort_p(void * op);
extern int int_odd_p(void * op);
extern int int_even_p(void * op);
extern size_t int_sizeinbase(void * op, int base);


// END INT FUNCTIONS.

// BEGIN RATIONAL NUMBER FUNCTIONS:

extern void * allocate_q();
extern void register_q(void * p);
extern void clear_q(void * p);

extern void q_set(void * dst, void * src);
extern int q_set_str(void * dst, const char *str, int base);
extern char * q_get_str(char *str, int base, void * src);

extern void q_swap(void * rop1, void * rop2);

extern void q_add(void * sum, void * addend1, void * addend2);
extern void q_sub(void * difference, void * minuend, void * subtrahend);
extern void q_mul(void * product, void * multiplier, void * multiplicand);
extern void q_div(void * quotient, void * dividend, void * divisor);
extern void q_neg(void * negated_operand, void * operand);
extern void q_abs(void * rop, void * op);
extern void q_inv(void * inverted_number, void * number);

extern int q_cmp(void * op1, void * op2);
extern int q_equal(void * op1, void * op2);

extern void q_get_num(void * int_numerator, void * rational);
extern void q_get_den(void * int_denominator, void * rational);
extern void q_set_num(void * rational, void * int_numerator);
extern void q_set_den(void * rational, void * int_denominator);

// END RATIONAL NUMBER FUNCTIONS.

// BEGIN FLOATING-POINT FUNCTIONS:

extern void float_set_default_prec(unsigned long prec);
extern unsigned long float_get_default_prec();

extern void * allocate_float();
extern void register_float(void * p);
extern void register_float2(void * p, unsigned long prec);
extern void clear_float(void * p);

extern unsigned long float_get_prec(void * op);
extern void float_set_prec(void * rop, unsigned long prec);

extern void float_set(void * rop, void * op);
extern int float_set_str(void * rop, const char *str, int base);
extern char * float_get_str(char *str, void *expptr, int base, size_t n_digits, void * op);

extern void float_swap(void * rop1, void * rop2);

extern void float_add(void * rop, void * op1, void * op2);
extern void float_sub(void * rop, void * op1, void * op2);
extern void float_mul(void * rop, void * op1, void * op2);
extern void float_div(void * rop, void * op1, void * op2);
extern void float_sqrt(void * rop, void * op);
extern void float_sqrt_ui(void * rop, unsigned long int op);
extern void float_pow_ui(void * rop, void * op1, unsigned long int op2);
extern void float_neg(void * rop, void * op);
extern void float_abs(void * rop, void * op);

extern int float_cmp(void * op1, void * op2);
extern void float_reldiff(void * rop, void * op1, void * op2);
extern void float_ceil(void * rop, void * op);
extern void float_floor(void * rop, void * op);
extern void float_trunc(void * rop, void * op);
extern int float_integer_p(void * op);

// END FLOATING-POINT FUNCTIONS.

// Formatted input and output, to be continued...

//here

#ifdef __cplusplus
}
#endif

// END OF FILE

#endif
