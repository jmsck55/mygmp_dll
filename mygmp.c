// Copyright (c) 2020 James J. Cook
// Contains functions for wrapping GMP and MPFR functions.

// Status:
// MPFR mostly complete
// MPZ mostly complete
// MPQ experimental
// MPF experimental

#include "mygmp.h"

// standard includes:
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <gmp.h>
#include <mpfr.h>

#ifdef TEST_FOO
void foo(void)
{
	puts("Hello, I'm a shared library");
	printf("size of mpz_t is: %d\n", sizeof(mpz_t));
	printf("size of mpq_t is: %d\n", sizeof(mpq_t));
	printf("size of mpf_t is: %d\n", sizeof(mpf_t));
	printf("size of mpfr_t is: %d\n", sizeof(mpfr_t));
}
#endif

int version() {
	// MPFR (f) functions done;
	// MPZ (int) functions done;
	// MPQ (q) and MPF (float) are incomplete for now, however the functions that are coded should still work.
	return 3;
}

void generic_free(void * p) {
	free(p);
}
size_t sizeof_int() {
	return sizeof(mpz_t);
}
size_t sizeof_q() {
	return sizeof(mpq_t);
}
size_t sizeof_float() {
	return sizeof(mpf_t);
}

// BEGIN mpfr FUNCTIONS:

size_t sizeof_f() {
	return sizeof(mpfr_t);
}

void * allocate_f() {
	return malloc(sizeof(mpfr_t));
}

void register_f(void * p) {
	mpfr_init((mpfr_ptr)p);
}
void register_f2(void * p, long prec) {
	mpfr_init2((mpfr_ptr)p, (mpfr_prec_t)prec);
}
void clear_f(void * p) {
	mpfr_clear((mpfr_ptr)p);
	// remember to free argument "p" with generic_free(), after calling this function.
}
void clear_f_cache() {
	mpfr_free_cache();
	// remember to free cache for constants at end of program
}

long f_get_default_prec() {
	return (long)mpfr_get_default_prec();
}
void f_set_default_prec(long prec) {
	mpfr_set_default_prec((mpfr_prec_t)prec);
}
long f_get_prec(void * p) {
	return (long)mpfr_get_prec((mpfr_ptr)p);
}
void f_set_prec(void * p, long prec) {
	mpfr_set_prec((mpfr_ptr)p, (mpfr_prec_t)prec);
}

// typedef enum {
//   MPFR_RNDN=0,  // round to nearest, with ties to even
//   MPFR_RNDZ,    // round toward zero
//   MPFR_RNDU,    // round toward +Inf
//   MPFR_RNDD,    // round toward -Inf
//   MPFR_RNDA,    // round away from zero
//   MPFR_RNDF,    // faithful rounding (not implemented yet)
//   MPFR_RNDNA=-1 // round to nearest, with ties away from zero (mpfr_round)
// } mpfr_rnd_t;

int f_set(void * p, void * op, int rnd) {
	return mpfr_set((mpfr_ptr)p, (mpfr_ptr)op, (mpfr_rnd_t)rnd);
}
int f_set_ui(void * p, unsigned long int op, int rnd) {
	return mpfr_set_ui((mpfr_ptr)p, op, (mpfr_rnd_t)rnd);
}
int f_set_si(void * p, long int op, int rnd) {
	return mpfr_set_si((mpfr_ptr)p, op, (mpfr_rnd_t)rnd);
}
//int f_set_uj(void * p, unsigned long long op, int rnd) {
//	return mpfr_set_uj((mpfr_ptr)p, op, (mpfr_rnd_t)rnd);
//}
//int f_set_sj(void * p, long long op, int rnd) {
//	return mpfr_set_sj((mpfr_ptr)p, op, (mpfr_rnd_t)rnd);
//}
int f_set_flt(void * p, float op, int rnd) {
	return mpfr_set_flt((mpfr_ptr)p, op, (mpfr_rnd_t)rnd);
}
int f_set_d(void * p, double op, int rnd) {
	return mpfr_set_d((mpfr_ptr)p, op, (mpfr_rnd_t)rnd);
}
int f_set_ld(void * p, long double op, int rnd) {
	return mpfr_set_ld((mpfr_ptr)p, op, (mpfr_rnd_t)rnd);
}
//int f_set_float128(void * p, __float128 op, int rnd);
//int f_set_decimal64(void * p, _Decimal64 op, int rnd);

int f_set_int(void * p, void * op1, int rnd) {
	return mpfr_set_z((mpfr_ptr)p, (mpz_srcptr)op1, (mpfr_rnd_t)rnd);
}
int f_set_q(void * p, void * op1, int rnd) {
	return mpfr_set_q((mpfr_ptr)p, (mpq_srcptr)op1, (mpfr_rnd_t)rnd);
}
int f_set_float(void * p, void * op1, int rnd) {
	return mpfr_set_f((mpfr_ptr)p, (mpf_srcptr)op1, (mpfr_rnd_t)rnd);
}

int f_set_ui_2exp(void * rop, unsigned long int op, long e, int rnd) {
	return mpfr_set_ui_2exp((mpfr_ptr)rop, op, (mpfr_exp_t)e, (mpfr_rnd_t)rnd);
}
int f_set_si_2exp(void * rop, long int op, long e, int rnd) {
	return mpfr_set_si_2exp((mpfr_ptr)rop, op, (mpfr_exp_t)e, (mpfr_rnd_t)rnd);
}
//int f_set_uj_2exp(void * rop, unsigned long long op, long long e, int rnd) {
//	return mpfr_set_uj_2exp((mpfr_ptr)rop, (uintmax_t)op, (intmax_t)e, (mpfr_rnd_t)rnd);
//}
//int f_set_sj_2exp(void * rop, long long op, long long e, int rnd) {
//	return mpfr_set_sj_2exp((mpfr_ptr)rop, (intmax_t)op, (intmax_t)e, (mpfr_rnd_t)rnd);
//}
int f_set_int_2exp(void * rop, void * op, long e, int rnd) {
	return mpfr_set_z_2exp((mpfr_ptr)rop, (mpz_srcptr)op, (mpfr_exp_t)e, (mpfr_rnd_t)rnd);
}
// Set the value of rop from op × 2^e, rounded toward the given direction rnd. Note that the
// input 0 is converted to +0.

int f_set_str(void * p, const char *s, int base, int rnd) {
	return mpfr_set_str((mpfr_ptr)p, s, base, (mpfr_rnd_t)rnd);
}
int f_strtofr(void * p, const char *nptr, char **endptr, int base, int rnd) {
	return mpfr_strtofr((mpfr_ptr)p, nptr, endptr, base, (mpfr_rnd_t)rnd);
}

void f_set_nan(void * p) {
	mpfr_set_nan((mpfr_ptr)p);
}
void f_set_inf(void * p, int sign) {
	mpfr_set_inf((mpfr_ptr)p, sign);
}
void f_set_zero(void * p, int sign) {
	mpfr_set_zero((mpfr_ptr)p, sign);
}
// Set the variable x to NaN (Not-a-Number), infinity or zero respectively. In mpfr_set_inf or
// mpfr_set_zero, x is set to plus infinity or plus zero iff sign is nonnegative; in mpfr_set_nan,
// the sign bit of the result is unspecified.

void f_swap(void * x, void * y) {
	mpfr_swap((mpfr_ptr)x, (mpfr_ptr)y);
}

// Initialize x and set its value from the string s in base base, rounded in the direction rnd
int f_init_set_str(void * p, const char *s, int base, int rnd) {
	return mpfr_init_set_str((mpfr_ptr)p, s, base, (mpfr_rnd_t)rnd);
}

// Conversion functions

float f_get_flt(void * p, int rnd) {
	return mpfr_get_flt((mpfr_ptr)p, (mpfr_rnd_t)rnd);
}
double f_get_d(void * p, int rnd) {
	return mpfr_get_d((mpfr_ptr)p, (mpfr_rnd_t)rnd);
}
long double f_get_ld(void * p, int rnd) {
	return mpfr_get_ld((mpfr_ptr)p, (mpfr_rnd_t)rnd);
}

long f_get_si(void * p, int rnd) {
	return mpfr_get_si((mpfr_ptr)p, (mpfr_rnd_t)rnd);
}
unsigned long f_get_ui(void * p, int rnd) {
	return mpfr_get_ui((mpfr_ptr)p, (mpfr_rnd_t)rnd);
}
//long long f_get_sj(void * p, int rnd) {
//	return mpfr_get_sj((mpfr_ptr)p, (mpfr_rnd_t)rnd);
//}
//unsigned long long f_get_uj(void * p, int rnd) {
//	return mpfr_get_uj((mpfr_ptr)p, (mpfr_rnd_t)rnd);
//}

double f_get_d_2exp(long *exp, void * p, int rnd) {
	return mpfr_get_d_2exp(exp, (mpfr_srcptr)p, (mpfr_rnd_t)rnd);
}
long double f_get_ld_2exp(long *exp, void * p, int rnd) {
	return mpfr_get_ld_2exp(exp, (mpfr_srcptr)p, (mpfr_rnd_t)rnd);
}

int f_frexp(long *exp, void * y, void * x, int rnd) {
	return mpfr_frexp((mpfr_exp_t*)exp, (mpfr_ptr)y, (mpfr_srcptr)x, (mpfr_rnd_t)rnd);
}
long f_get_int_2exp(void * r, void * p) {
	return (long)mpfr_get_z_2exp((mpz_ptr)r, (mpfr_srcptr)p);
}
int f_get_int(void * r, void * p, int rnd) {
	return mpfr_get_z((mpz_ptr)r, (mpfr_srcptr)p, (mpfr_rnd_t)rnd);
}
//void f_get_q(void * r, void * p) {
//	mpfr_get_q((mpq_ptr)r, (mpfr_srcptr)p);
//}
int f_get_float(void * r, void * p, int rnd) {
	return mpfr_get_f((mpf_ptr)r, (mpfr_srcptr)p, (mpfr_rnd_t)rnd);
}

char * f_get_str(char *str, long *expptr, int b, size_t n, void * p, int rnd) {
	return mpfr_get_str(str, (mpfr_exp_t *)expptr, b, n, (mpfr_ptr)p, (mpfr_rnd_t)rnd);
}
void f_free_str(char *str) {
	mpfr_free_str(str);
}

int f_fits_ulong_p(void * p, int rnd) {
	return mpfr_fits_ulong_p((mpfr_srcptr)p, (mpfr_rnd_t)rnd);
}
int f_fits_slong_p(void * p, int rnd) {
	return mpfr_fits_slong_p((mpfr_srcptr)p, (mpfr_rnd_t)rnd);
}
int f_fits_uint_p(void * p, int rnd) {
	return mpfr_fits_uint_p((mpfr_srcptr)p, (mpfr_rnd_t)rnd);
}
int f_fits_sint_p(void * p, int rnd) {
	return mpfr_fits_sint_p((mpfr_srcptr)p, (mpfr_rnd_t)rnd);
}
int f_fits_ushort_p(void * p, int rnd) {
	return mpfr_fits_ushort_p((mpfr_srcptr)p, (mpfr_rnd_t)rnd);
}
int f_fits_sshort_p(void * p, int rnd) {
	return mpfr_fits_sshort_p((mpfr_srcptr)p, (mpfr_rnd_t)rnd);
}
int f_fits_uintmax_p(void * p, int rnd) {
	return mpfr_fits_uintmax_p((mpfr_srcptr)p, (mpfr_rnd_t)rnd);
}
int f_fits_intmax_p(void * p, int rnd) {
	return mpfr_fits_intmax_p((mpfr_srcptr)p, (mpfr_rnd_t)rnd);
}

// Basic Arithmetic Functions

int f_add(void * r, void * p, void * op, int rnd) {
	return mpfr_add((mpfr_ptr)r, (mpfr_srcptr)p, (mpfr_srcptr)op, (mpfr_rnd_t)rnd);
}
int f_add_ui(void * r, void * p, unsigned long int op2, int rnd) {
	return mpfr_add_ui((mpfr_ptr)r, (mpfr_srcptr)p, op2, (mpfr_rnd_t)rnd);
}
int f_add_si(void * r, void * p, long int op2, int rnd) {
	return mpfr_add_si((mpfr_ptr)r, (mpfr_srcptr)p, op2, (mpfr_rnd_t)rnd);
}
int f_add_d(void * r, void * p, double op2, int rnd) {
	return mpfr_add_d((mpfr_ptr)r, (mpfr_srcptr)p, op2, (mpfr_rnd_t)rnd);
}
int f_add_int(void * r, void * p, void * op2, int rnd) {
	return mpfr_add_z((mpfr_ptr)r, (mpfr_srcptr)p, (mpz_srcptr)op2, (mpfr_rnd_t)rnd);
}
int f_add_q(void * r, void * p, void * op2, int rnd) {
	return mpfr_add_q((mpfr_ptr)r, (mpfr_srcptr)p, (mpq_srcptr)op2, (mpfr_rnd_t)rnd);
}
// Set rop to op1 +op2 rounded in the direction rnd. The IEEE 754 rules are used, in particular
// for signed zeros. But for types having no signed zeros, 0 is considered unsigned (i.e., (+0)
// + 0 = (+0) and (−0) + 0 = (−0)). The mpfr_add_d function assumes that the radix of the
// double type is a power of 2, with a precision at most that declared by the C implementation
// (macro IEEE_DBL_MANT_DIG, and if not defined 53 bits).

int f_sub(void * r, void * op1, void * op2, int rnd) {
	return mpfr_sub((mpfr_ptr)r, (mpfr_srcptr)op1, (mpfr_srcptr)op2, (mpfr_rnd_t)rnd);
}
int f_ui_sub(void * r, unsigned long int op1, void * op2, int rnd) {
	return mpfr_ui_sub((mpfr_ptr)r, op1, (mpfr_srcptr)op2, (mpfr_rnd_t)rnd);
}
int f_sub_ui(void * r, void * op1, unsigned long int op2, int rnd) {
	return mpfr_sub_ui((mpfr_ptr)r, (mpfr_srcptr)op1, op2, (mpfr_rnd_t)rnd);
}
int f_si_sub(void * r, long int op1, void * op2, int rnd) {
	return mpfr_si_sub((mpfr_ptr)r, op1, (mpfr_srcptr)op2, (mpfr_rnd_t)rnd);
}
int f_sub_si(void * r, void * op1, long int op2, int rnd) {
	return mpfr_sub_si((mpfr_ptr)r, (mpfr_srcptr)op1, op2, (mpfr_rnd_t)rnd);
}
int f_d_sub(void * r, double op1, void * op2, int rnd) {
	return mpfr_d_sub((mpfr_ptr)r, op1, (mpfr_srcptr)op2, (mpfr_rnd_t)rnd);
}
int f_sub_d(void * r, void * op1, double op2, int rnd) {
	return mpfr_sub_d((mpfr_ptr)r, (mpfr_srcptr)op1, op2, (mpfr_rnd_t)rnd);
}
int f_int_sub(void * r, void * op1, void * op2, int rnd) {
	return mpfr_z_sub((mpfr_ptr)r, (mpz_srcptr)op1, (mpfr_srcptr)op2, (mpfr_rnd_t)rnd);
}
int f_sub_int(void * r, void * op1, void * op2, int rnd) {
	return mpfr_sub_z((mpfr_ptr)r, (mpfr_srcptr)op1, (mpz_srcptr)op2, (mpfr_rnd_t)rnd);
}
int f_sub_q(void * r, void * op1, void * op2, int rnd) {
	return mpfr_sub_q((mpfr_ptr)r, (mpfr_ptr)op1, (mpq_ptr)op2, (mpfr_rnd_t)rnd);
}
// Set rop to op1 −op2 rounded in the direction rnd. The IEEE 754 rules are used, in particular
// for signed zeros. But for types having no signed zeros, 0 is considered unsigned (i.e., (+0) −
// 0 = (+0), (−0) − 0 = (−0), 0 − (+0) = (−0) and 0 − (−0) = (+0)). The same restrictions
// than for mpfr_add_d apply to mpfr_d_sub and mpfr_sub_d.

int f_mul(void * r, void * p, void * op, int rnd) {
	return mpfr_mul((mpfr_ptr)r, (mpfr_srcptr)p, (mpfr_srcptr)op, (mpfr_rnd_t)rnd);
}
int f_mul_ui(void * r, void * p, unsigned long int op2, int rnd) {
	return mpfr_mul_ui((mpfr_ptr)r, (mpfr_srcptr)p, op2, (mpfr_rnd_t)rnd);
}
int f_mul_si(void * r, void * p, long int op2, int rnd) {
	return mpfr_mul_si((mpfr_ptr)r, (mpfr_srcptr)p, op2, (mpfr_rnd_t)rnd);
}
int f_mul_d(void * r, void * p, double op2, int rnd) {
	return mpfr_mul_d((mpfr_ptr)r, (mpfr_srcptr)p, op2, (mpfr_rnd_t)rnd);
}
int f_mul_int(void * r, void * p, void * op2, int rnd) {
	return mpfr_mul_z((mpfr_ptr)r, (mpfr_srcptr)p, (mpz_srcptr)op2, (mpfr_rnd_t)rnd);
}
int f_mul_q(void * r, void * p, void * op2, int rnd) {
	return mpfr_mul_q((mpfr_ptr)r, (mpfr_srcptr)p, (mpq_srcptr)op2, (mpfr_rnd_t)rnd);
}
// Set rop to op1×op2 rounded in the direction rnd. When a result is zero, its sign is the product
// of the signs of the operands (for types having no signed zeros, 0 is considered positive). The
// same restrictions than for mpfr_add_d apply to mpfr_mul_d.

int f_sqr(void * r, void * p, int rnd) {
	return mpfr_sqr((mpfr_ptr)r, (mpfr_srcptr)p, (mpfr_rnd_t)rnd);
}
// Not to be confused with "sqrt", Set rop to op^2 rounded in the direction rnd.

int f_div(void * r, void * op1, void * op2, int rnd) {
	return mpfr_div((mpfr_ptr)r, (mpfr_srcptr)op1, (mpfr_srcptr)op2, (mpfr_rnd_t)rnd);
}
int f_ui_div(void * r, unsigned long int op1, void * op2, int rnd) {
	return mpfr_ui_div((mpfr_ptr)r, op1, (mpfr_srcptr)op2, (mpfr_rnd_t)rnd);
}
int f_div_ui(void * r, void * op1, unsigned long int op2, int rnd) {
	return mpfr_div_ui((mpfr_ptr)r, (mpfr_srcptr)op1, op2, (mpfr_rnd_t)rnd);
}
int f_si_div(void * r, long int op1, void * op2, int rnd) {
	return mpfr_si_div((mpfr_ptr)r, op1, (mpfr_srcptr)op2, (mpfr_rnd_t)rnd);
}
int f_div_si(void * r, void * op1, long int op2, int rnd) {
	return mpfr_div_si((mpfr_ptr)r, (mpfr_srcptr)op1, op2, (mpfr_rnd_t)rnd);
}
int f_d_div(void * r, double op1, void * op2, int rnd) {
	return mpfr_d_div((mpfr_ptr)r, op1, (mpfr_srcptr)op2, (mpfr_rnd_t)rnd);
}
int f_div_d(void * r, void * op1, double op2, int rnd) {
	return mpfr_div_d((mpfr_ptr)r, (mpfr_srcptr)op1, op2, (mpfr_rnd_t)rnd);
}
int f_div_int(void * r, void * p, void * op2, int rnd) {
	return mpfr_div_z((mpfr_ptr)r, (mpfr_srcptr)p, (mpz_srcptr)op2, (mpfr_rnd_t)rnd);
}
int f_div_q(void * r, void * p, void * op2, int rnd) {
	return mpfr_div_q((mpfr_ptr)r, (mpfr_srcptr)p, (mpq_srcptr)op2, (mpfr_rnd_t)rnd);
}
// Set rop to op1/op2 rounded in the direction rnd. When a result is zero, its sign is the product
// of the signs of the operands. For types having no signed zeros, 0 is considered positive; but
// note that if op1 is non-zero and op2 is zero, the result might change from ±Inf to NaN
// in future MPFR versions if there is an opposite decision on the IEEE 754 side. The same
// restrictions than for mpfr_add_d apply to mpfr_d_div and mpfr_div_d.

int f_sqrt(void * r, void * p, int rnd) {
	return mpfr_sqrt((mpfr_ptr)r, (mpfr_srcptr)p, (mpfr_rnd_t)rnd);
}
int f_sqrt_ui(void * r, unsigned long int op, int rnd) {
	return mpfr_sqrt_ui((mpfr_ptr)r, op, (mpfr_rnd_t)rnd);
}
// Set rop to √op rounded in the direction rnd. Set rop to −0 if op is −0, to be consistent with
// the IEEE 754 standard. Set rop to NaN if op is negative.

int f_rec_sqrt(void * r, void * p, int rnd) {
	return mpfr_rec_sqrt((mpfr_ptr)r, (mpfr_srcptr)p, (mpfr_rnd_t)rnd);
}
// Set rop to 1/√(op) rounded in the direction rnd. Set rop to +Inf if op is ±0, +0 if op is +Inf,
// and NaN if op is negative. Warning! Therefore the result on −0 is different from the one
// of the rSqrt function recommended by the IEEE 754-2008 standard (Section 9.2.1), which is
// −Inf instead of +Inf.

int f_cbrt(void * r, void * p, int rnd) {
	return mpfr_cbrt((mpfr_ptr)r, (mpfr_srcptr)p, (mpfr_rnd_t)rnd);
}
//int f_rootn_ui(void * r, void * p, unsigned long int k, int rnd) {
//	return mpfr_rootn_ui((mpfr_ptr)r, (mpfr_srcptr)p, k, (mpfr_rnd_t)rnd);
//}

// Set rop to the cubic root (resp. the kth root) of op rounded in the direction rnd. For k =
// 0, set rop to NaN. For k odd (resp. even) and op negative (including −Inf), set rop to a
// negative number (resp. NaN). If op is zero, set rop to zero with the sign obtained by the
// usual limit rules, i.e., the same sign as op if k is odd, and positive if k is even.
// These functions agree with the rootn function of the IEEE 754-2008 standard (Section 9.2).

int f_root(void * r, void * p, unsigned long int k, int rnd) {
	return mpfr_root((mpfr_ptr)r, (mpfr_srcptr)p, k, (mpfr_rnd_t)rnd);
}

// This function is the same as mpfr_rootn_ui except when op is −0 and k is even: the result
// is −0 instead of +0 (the reason was to be consistent with mpfr_sqrt). Said otherwise, if op
// is zero, set rop to op.
// This function predates the IEEE 754-2008 standard and behaves differently from its rootn
// function. It is marked as deprecated and will be removed in a future release.

int f_pow(void * r, void * p, void * op, int rnd) {
	return mpfr_pow((mpfr_ptr)r, (mpfr_srcptr)p, (mpfr_srcptr)op, (mpfr_rnd_t)rnd);
}
int f_pow_ui(void * r, void * p, unsigned long int op2, int rnd) {
	return mpfr_pow_ui((mpfr_ptr)r, (mpfr_srcptr)p, op2, (mpfr_rnd_t)rnd);
}
int f_pow_si(void * r, void * p, long int op2, int rnd) {
	return mpfr_pow_si((mpfr_ptr)r, (mpfr_srcptr)p, op2, (mpfr_rnd_t)rnd);
}
int f_pow_int(void * r, void * p, void * op2, int rnd) {
	return mpfr_pow_z((mpfr_ptr)r, (mpfr_srcptr)p, (mpz_srcptr)op2, (mpfr_rnd_t)rnd);
}
int f_ui_pow_ui(void * r, unsigned long int op1, unsigned long int op2, int rnd) {
	return mpfr_ui_pow_ui((mpfr_ptr)r, op1, op2, (mpfr_rnd_t)rnd);
}
int f_ui_pow(void * r, unsigned long int op1, void * op2, int rnd) {
	return mpfr_ui_pow((mpfr_ptr)r, op1, (mpfr_srcptr)op2, (mpfr_rnd_t)rnd);
}
// Set rop to op1^op2, rounded in the direction rnd. Special values are handled as described in
// the ISO C99 and IEEE 754-2008 standards for the pow function:
// • pow(±0, y) returns plus or minus infinity for y a negative odd integer.
// • pow(±0, y) returns plus infinity for y negative and not an odd integer.
// • pow(±0, y) returns plus or minus zero for y a positive odd integer.
// • pow(±0, y) returns plus zero for y positive and not an odd integer.
// • pow(-1, ±Inf) returns 1.
// • pow(+1, y) returns 1 for any y, even a NaN.
// • pow(x, ±0) returns 1 for any x, even a NaN.
// • pow(x, y) returns NaN for finite negative x and finite non-integer y.
// • pow(x, -Inf) returns plus infinity for 0 < |x| < 1, and plus zero for |x| > 1.
// • pow(x, +Inf) returns plus zero for 0 < |x| < 1, and plus infinity for |x| > 1.
// • pow(-Inf, y) returns minus zero for y a negative odd integer.
// • pow(-Inf, y) returns plus zero for y negative and not an odd integer.
// • pow(-Inf, y) returns minus infinity for y a positive odd integer.
// • pow(-Inf, y) returns plus infinity for y positive and not an odd integer.
// • pow(+Inf, y) returns plus zero for y negative, and plus infinity for y positive.
// Note: When 0 is of integer type, it is regarded as +0 by these functions. We do not use the
// usual limit rules in this case, as these rules are not used for pow.

int f_neg(void * r, void * p, int rnd) {
	return mpfr_neg((mpfr_ptr)r, (mpfr_srcptr)p, (mpfr_rnd_t)rnd);
}
int f_abs(void * r, void * p, int rnd) {
	return mpfr_abs((mpfr_ptr)r, (mpfr_srcptr)p, (mpfr_rnd_t)rnd);
}
// Set rop to −op and the absolute value of op respectively, rounded in the direction rnd. Just
// changes or adjusts the sign if rop and op are the same variable, otherwise a rounding might
// occur if the precision of rop is less than that of op.
// The sign rule also applies to NaN in order to mimic the IEEE 754 negate and abs operations,
// i.e., for mpfr_neg, the sign is reversed, and for mpfr_abs, the sign is set to positive. But
// contrary to IEEE 754, the NaN flag is set as usual.

int f_dim(void * r, void * op1, void * op2, int rnd) {
	return mpfr_dim((mpfr_ptr)r, (mpfr_srcptr)op1, (mpfr_srcptr)op2, (mpfr_rnd_t)rnd);
}
// Set rop to the positive difference of op1 and op2, i.e., op1 −op2 rounded in the direction rnd
// if op1 > op2, +0 if op1 ≤ op2, and NaN if op1 or op2 is NaN.

int f_mul_2ui(void * r, void * p, unsigned long int op2, int rnd) {
	return mpfr_mul_2ui((mpfr_ptr)r, (mpfr_srcptr)p, op2, (mpfr_rnd_t)rnd);
}
int f_mul_2si(void * r, void * p, long int op2, int rnd) {
	return mpfr_mul_2si((mpfr_ptr)r, (mpfr_srcptr)p, op2, (mpfr_rnd_t)rnd);
}
// Set rop to op1 × 2^op2 rounded in the direction rnd. Just increases the exponent by op2 when
// rop and op1 are identical.

int f_div_2ui(void * r, void * p, unsigned long int op2, int rnd) {
	return mpfr_div_2ui((mpfr_ptr)r, (mpfr_srcptr)p, op2, (mpfr_rnd_t)rnd);
}
int f_div_2si(void * r, void * p, long int op2, int rnd) {
	return mpfr_div_2si((mpfr_ptr)r, (mpfr_srcptr)p, op2, (mpfr_rnd_t)rnd);
}
// Set rop to op1/(2^op2) rounded in the direction rnd. Just decreases the exponent by op2 when
// rop and op1 are identical.

// Comparison Functions

int f_cmp(void * p, void * op2) {
	return mpfr_cmp((mpfr_srcptr)p, (mpfr_srcptr)op2);
}
int f_cmp_ui(void * p, unsigned long int op2) {
	return mpfr_cmp_ui((mpfr_srcptr)p, op2);
}
int f_cmp_si(void * p, long int op2) {
	return mpfr_cmp_si((mpfr_srcptr)p, op2);
}
int f_cmp_d(void * p, double op2) {
	return mpfr_cmp_d((mpfr_srcptr)p, op2);
}
int f_cmp_ld(void * p, long double op2) {
	return mpfr_cmp_ld((mpfr_srcptr)p, op2);
}
int f_cmp_int(void * p, void * op2) {
	return mpfr_cmp_z((mpfr_srcptr)p, (mpz_srcptr)op2);
}
int f_cmp_q(void * p, void * op2) {
	return mpfr_cmp_q((mpfr_srcptr)p, (mpq_srcptr)op2);
}
int f_cmp_float(void * p, void * op2) {
	return mpfr_cmp_f((mpfr_srcptr)p, (mpf_srcptr)op2);
}
// Compare op1 and op2. Return a positive value if op1 > op2, zero if op1 = op2, and a
// negative value if op1 < op2. Both op1 and op2 are considered to their full own precision,
// which may differ. If one of the operands is NaN, set the erange flag and return zero.
// Note: These functions may be useful to distinguish the three possible cases. If you need
// to distinguish two cases only, it is recommended to use the predicate functions (e.g., mpfr_
// equal_p for the equality) described below; they behave like the IEEE 754 comparisons, in
// particular when one or both arguments are NaN. But only floating-point numbers can be
// compared (you may need to do a conversion first).

int f_cmp_ui_2exp(void * op1, unsigned long int op2, long e) {
	return mpfr_cmp_ui_2exp((mpfr_srcptr)op1, op2, (mpfr_exp_t)e);
}
int f_cmp_si_2exp(void * op1, long int op2, long e) {
	return mpfr_cmp_si_2exp((mpfr_srcptr)op1, op2, (mpfr_exp_t)e);
}
// Compare op1 and op2 × 2^e Similar as above.

int f_cmpabs(void * op1, void * op2) {
	return mpfr_cmpabs((mpfr_srcptr)op1, (mpfr_srcptr)op2);
}
// Compare |op1| and |op2|. Return a positive value if |op1| > |op2|, zero if |op1| = |op2|,
// and a negative value if |op1| < |op2|. If one of the operands is NaN, set the erange flag and
// return zero.

int f_nan_p(void * op) {
	return mpfr_nan_p((mpfr_srcptr)op);
}
int f_inf_p(void * op) {
	return mpfr_inf_p((mpfr_srcptr)op);
}
int f_number_p(void * op) {
	return mpfr_number_p((mpfr_srcptr)op);
}
int f_zero_p(void * op) {
	return mpfr_zero_p((mpfr_srcptr)op);
}
int f_regular_p(void * op) {
	return mpfr_regular_p((mpfr_srcptr)op);
}
// Return non-zero if op is respectively NaN, an infinity, an ordinary number (i.e., neither NaN
// nor an infinity), zero, or a regular number (i.e., neither NaN, nor an infinity nor zero). Return
// zero otherwise.

int f_sgn(void * op) {
	return mpfr_sgn((mpfr_srcptr)op);
}
// Return a positive value if op > 0, zero if op = 0, and a negative value if op < 0. If the
// operand is NaN, set the erange flag and return zero. This is equivalent to mpfr_cmp_ui (op,
// 0), but more efficient.

int f_greater_p(void * op1, void * op2) {
	return mpfr_greater_p((mpfr_srcptr)op1, (mpfr_srcptr)op2);
}
int f_greaterequal_p(void * op1, void * op2) {
	return mpfr_greaterequal_p((mpfr_srcptr)op1, (mpfr_srcptr)op2);
}
int f_less_p(void * op1, void * op2) {
	return mpfr_less_p((mpfr_srcptr)op1, (mpfr_srcptr)op2);
}
int f_lessequal_p(void * op1, void * op2) {
	return mpfr_lessequal_p((mpfr_srcptr)op1, (mpfr_srcptr)op2);
}
int f_equal_p(void * op1, void * op2) {
	return mpfr_equal_p((mpfr_srcptr)op1, (mpfr_srcptr)op2);
}
// Return non-zero if op1 > op2, op1 ≥ op2, op1 < op2, op1 ≤ op2, op1 = op2 respectively,
// and zero otherwise. Those functions return zero whenever op1 and/or op2 is NaN.

int f_lessgreater_p(void * op1, void * op2) {
	return mpfr_lessgreater_p((mpfr_srcptr)op1, (mpfr_srcptr)op2);
}
// Return non-zero if op1 < op2 or op1 > op2 (i.e., neither op1, nor op2 is NaN, and op1 != op2),
// zero otherwise (i.e., op1 and/or op2 is NaN, or op1 = op2).

int f_unordered_p(void * op1, void * op2) {
	return mpfr_unordered_p((mpfr_srcptr)op1, (mpfr_srcptr)op2);
}
// Return non-zero if op1 or op2 is a NaN (i.e., they cannot be compared), zero otherwise.

// Special Functions

// All those functions, except explicitly stated (for example mpfr_sin_cos), return a [ternary
// value], page 8, i.e., zero for an exact return value, a positive value for a return value larger than
// the exact result, and a negative value otherwise.
// Important note: in some domains, computing special functions (even more with correct rounding) is expensive, even for small precision, for example the trigonometric and Bessel functions
// for large argument. For some functions, the memory usage might depend not only on the output
// precision: it is the case of the mpfr_rootn_ui function where the memory usage is also linear
// in the argument k, and of the incomplete Gamma function (dependence on the precision of op).

int f_log(void * r, void * op, int rnd) {
	return mpfr_log((mpfr_ptr)r, (mpfr_srcptr)op, (mpfr_rnd_t)rnd);
}
//int f_log_ui(void * r, unsigned long op, int rnd) {
//	return mpfr_log_ui((mpfr_ptr)r, op, (mpfr_rnd_t)rnd);
//}
int f_log2(void * r, void * op, int rnd) {
	return mpfr_log2((mpfr_ptr)r, (mpfr_srcptr)op, (mpfr_rnd_t)rnd);
}
int f_log10(void * r, void * op, int rnd) {
	return mpfr_log10((mpfr_ptr)r, (mpfr_srcptr)op, (mpfr_rnd_t)rnd);
}
// Set rop to the natural logarithm of op, log2(op) or log10(op), respectively, rounded in the
// direction rnd. Set rop to +0 if op is 1 (in all rounding modes), for consistency with the ISO
// C99 and IEEE 754-2008 standards. Set rop to −Inf if op is ±0 (i.e., the sign of the zero has
// no influence on the result).

int f_log1p(void * r, void * op, int rnd) {
	return mpfr_log1p((mpfr_ptr)r, (mpfr_srcptr)op, (mpfr_rnd_t)rnd);
}
// Set rop to the logarithm of one plus op, rounded in the direction rnd. Set rop to −Inf if op
// is −1.

int f_exp(void * r, void * op, int rnd) {
	return mpfr_exp((mpfr_ptr)r, (mpfr_srcptr)op, (mpfr_rnd_t)rnd);
}
int f_exp2(void * r, void * op, int rnd) {
	return mpfr_exp2((mpfr_ptr)r, (mpfr_srcptr)op, (mpfr_rnd_t)rnd);
}
int f_exp10(void * r, void * op, int rnd) {
	return mpfr_exp10((mpfr_ptr)r, (mpfr_srcptr)op, (mpfr_rnd_t)rnd);
}
// Set rop to the exponential of op, to 2^(op) or to 10^(op), respectively, rounded in the direction rnd.

int f_expm1(void * r, void * op, int rnd) {
	return mpfr_expm1((mpfr_ptr)r, (mpfr_srcptr)op, (mpfr_rnd_t)rnd);
}
// Set rop to (e^(op) − 1), rounded in the direction rnd.

int f_cos(void * r, void * op, int rnd) {
	return mpfr_cos((mpfr_ptr)r, (mpfr_srcptr)op, (mpfr_rnd_t)rnd);
}
int f_sin(void * r, void * op, int rnd) {
	return mpfr_sin((mpfr_ptr)r, (mpfr_srcptr)op, (mpfr_rnd_t)rnd);
}
int f_tan(void * r, void * op, int rnd) {
	return mpfr_tan((mpfr_ptr)r, (mpfr_srcptr)op, (mpfr_rnd_t)rnd);
}
// Set rop to the cosine of op, sine of op, tangent of op, rounded in the direction rnd.

int f_sin_cos(void * sop, void * cop, void * op, int rnd) {
	return mpfr_sin_cos((mpfr_ptr)sop, (mpfr_ptr)cop, (mpfr_srcptr)op, (mpfr_rnd_t)rnd);
}
// Set simultaneously sop to the sine of op and cop to the cosine of op, rounded in the direction
// rnd with the corresponding precisions of sop and cop, which must be different variables.
// Return 0 iff both results are exact, more precisely it returns s + 4c where s = 0 if sop is
// exact, s = 1 if sop is larger than the sine of op, s = 2 if sop is smaller than the sine of op,
// and similarly for c and the cosine of op.

int f_sec(void * r, void * op, int rnd) {
	return mpfr_sec((mpfr_ptr)r, (mpfr_srcptr)op, (mpfr_rnd_t)rnd);
}
int f_csc(void * r, void * op, int rnd) {
	return mpfr_csc((mpfr_ptr)r, (mpfr_srcptr)op, (mpfr_rnd_t)rnd);
}
int f_cot(void * r, void * op, int rnd) {
	return mpfr_cot((mpfr_ptr)r, (mpfr_srcptr)op, (mpfr_rnd_t)rnd);
}
// Set rop to the secant of op, cosecant of op, cotangent of op, rounded in the direction rnd.

int f_acos(void * r, void * op, int rnd) {
	return mpfr_acos((mpfr_ptr)r, (mpfr_srcptr)op, (mpfr_rnd_t)rnd);
}
int f_asin(void * r, void * op, int rnd) {
	return mpfr_asin((mpfr_ptr)r, (mpfr_srcptr)op, (mpfr_rnd_t)rnd);
}
int f_atan(void * r, void * op, int rnd) {
	return mpfr_atan((mpfr_ptr)r, (mpfr_srcptr)op, (mpfr_rnd_t)rnd);
}
// Set rop to the arc-cosine, arc-sine or arc-tangent of op, rounded in the direction rnd. Note
// that since acos(-1) returns the floating-point number closest to π according to the given
// rounding mode, this number might not be in the output range 0 ≤ rop < π of the arc-cosine
// function; still, the result lies in the image of the output range by the rounding function. The
// same holds for asin(-1), asin(1), atan(-Inf), atan(+Inf) or for atan(op) with large op
// and small precision of rop.

int f_atan2(void * rop, void * y, void * x, int rnd) {
	return mpfr_atan2((mpfr_ptr)rop, (mpfr_srcptr)y, (mpfr_srcptr)x, (mpfr_rnd_t)rnd);
}
// Set rop to the arc-tangent2 of y and x, rounded in the direction rnd: if x > 0, atan2(y, x)
// = atan(y/x); if x < 0, atan2(y, x) = sign(y)*(Pi - atan(|y/x|)), thus a number from −π
// to π. As for atan, in case the exact mathematical result is +π or −π, its rounded result
// might be outside the function output range.
// atan2(y, 0) does not raise any floating-point exception. Special values are handled as described in the ISO C99 and IEEE 754-2008 standards for the atan2 function:
// • atan2(+0, -0) returns +π.
// • atan2(-0, -0) returns −π.
// • atan2(+0, +0) returns +0.
// • atan2(-0, +0) returns −0.
// • atan2(+0, x) returns +π for x < 0.
// • atan2(-0, x) returns −π for x < 0.
// • atan2(+0, x) returns +0 for x > 0.
// • atan2(-0, x) returns −0 for x > 0.
// • atan2(y, 0) returns −π/2 for y < 0.
// • atan2(y, 0) returns +π/2 for y > 0.
// • atan2(+Inf, -Inf) returns +3π/4.
// • atan2(-Inf, -Inf) returns −3π/4.
// • atan2(+Inf, +Inf) returns +π/4.
// • atan2(-Inf, +Inf) returns −π/4.
// • atan2(+Inf, x) returns +π/2 for finite x.
// • atan2(-Inf, x) returns −π/2 for finite x.
// • atan2(y, -Inf) returns +π for finite y > 0.
// • atan2(y, -Inf) returns −π for finite y < 0.
// • atan2(y, +Inf) returns +0 for finite y > 0.
// • atan2(y, +Inf) returns −0 for finite y < 0.

int f_cosh(void * r, void * op, int rnd) {
	return mpfr_cosh((mpfr_ptr)r, (mpfr_srcptr)op, (mpfr_rnd_t)rnd);
}
int f_sinh(void * r, void * op, int rnd) {
	return mpfr_sinh((mpfr_ptr)r, (mpfr_srcptr)op, (mpfr_rnd_t)rnd);
}
int f_tanh(void * r, void * op, int rnd) {
	return mpfr_tanh((mpfr_ptr)r, (mpfr_srcptr)op, (mpfr_rnd_t)rnd);
}
// Set rop to the hyperbolic cosine, sine or tangent of op, rounded in the direction rnd.

int f_sinh_cosh(void * sop, void * cop, void * op, int rnd) {
	return mpfr_sinh_cosh((mpfr_ptr)sop, (mpfr_ptr)cop, (mpfr_srcptr)op, (mpfr_rnd_t)rnd);
}
// Set simultaneously sop to the hyperbolic sine of op and cop to the hyperbolic cosine of op,
// rounded in the direction rnd with the corresponding precision of sop and cop, which must be
// different variables. Return 0 iff both results are exact (see mpfr_sin_cos for a more detailed
// description of the return value).

int f_sech(void * r, void * op, int rnd) {
	return mpfr_sech((mpfr_ptr)r, (mpfr_srcptr)op, (mpfr_rnd_t)rnd);
}
int f_csch(void * r, void * op, int rnd) {
	return mpfr_csch((mpfr_ptr)r, (mpfr_srcptr)op, (mpfr_rnd_t)rnd);
}
int f_coth(void * r, void * op, int rnd) {
	return mpfr_coth((mpfr_ptr)r, (mpfr_srcptr)op, (mpfr_rnd_t)rnd);
}
// Set rop to the hyperbolic secant of op, cosecant of op, cotangent of op, rounded in the
// direction rnd.

int f_acosh(void * r, void * op, int rnd) {
	return mpfr_acosh((mpfr_ptr)r, (mpfr_srcptr)op, (mpfr_rnd_t)rnd);
}
int f_asinh(void * r, void * op, int rnd) {
	return mpfr_asinh((mpfr_ptr)r, (mpfr_srcptr)op, (mpfr_rnd_t)rnd);
}
int f_atanh(void * r, void * op, int rnd) {
	return mpfr_atanh((mpfr_ptr)r, (mpfr_srcptr)op, (mpfr_rnd_t)rnd);
}
// Set rop to the inverse hyperbolic cosine, sine or tangent of op, rounded in the direction rnd.

int f_fac_ui(void * rop, unsigned long int op, int rnd) {
	return mpfr_fac_ui((mpfr_ptr)rop, op, (mpfr_rnd_t)rnd);
}
// Set rop to the factorial of op, rounded in the direction rnd.

int f_eint(void * r, void * p, int rnd) {
	return mpfr_eint((mpfr_ptr)r, (mpfr_ptr)p, (mpfr_rnd_t)rnd);
}
// Set rop to the exponential integral of op, rounded in the direction rnd. This is the sum of
// Euler’s constant, of the logarithm of the absolute value of op, and of the sum for k from 1 to
// infinity of opk/(k · k!). For positive op, it corresponds to the Ei function at op (see formula
// 5.1.10 from the Handbook of Mathematical Functions from Abramowitz and Stegun), and
// for negative op, to the opposite of the E1 function (sometimes called eint1) at −op (formula
// 5.1.1 from the same reference).

int f_li2(void * r, void * op, int rnd) {
	return mpfr_li2((mpfr_ptr)r, (mpfr_srcptr)op, (mpfr_rnd_t)rnd);
}
// Set rop to real part of the dilogarithm of op, rounded in the direction rnd. MPFR defines
// the dilogarithm function as −R (op, t=0) (log(1 − t)/t) dt.

int f_gamma(void * r, void * op, int rnd) {
	return mpfr_gamma((mpfr_ptr)r, (mpfr_srcptr)op, (mpfr_rnd_t)rnd);
}
//int f_gamma_inc(void * rop, void * op, void * op2, int rnd) {
//	return mpfr_gamma_inc((mpfr_ptr)rop, (mpfr_srcptr)op, (mpfr_srcptr)op2, (mpfr_rnd_t)rnd);
//}
// Set rop to the value of the Gamma function on op, resp. the incomplete Gamma function on
// op and op2, rounded in the direction rnd. (In the literature, mpfr_gamma_inc is called upper
// incomplete Gamma function, or sometimes complementary incomplete Gamma function.)
// For mpfr_gamma (and mpfr_gamma_inc when op2 is zero), when op is a negative integer, rop
// is set to NaN.
// Note: the current implementation of mpfr_gamma_inc is slow for large values of rop or op,
// in which case some internal overflow might also occur.

int f_lngamma(void * r, void * op, int rnd) {
	return mpfr_lngamma((mpfr_ptr)r, (mpfr_srcptr)op, (mpfr_rnd_t)rnd);
}
// Set rop to the value of the logarithm of the Gamma function on op, rounded in the direction
// rnd. When op is 1 or 2, set rop to +0 (in all rounding modes). When op is an infinity or
// a nonpositive integer, set rop to +Inf, following the general rules on special values. When
// −2k − 1 < op < −2k, k being a nonnegative integer, set rop to NaN. See also mpfr_lgamma.

int f_lgamma(void * rop, int *signp, void * op, int rnd) {
	return mpfr_lgamma((mpfr_ptr)rop, signp, (mpfr_srcptr)op, (mpfr_rnd_t)rnd);
}
// Set rop to the value of the logarithm of the absolute value of the Gamma function on op,
// rounded in the direction rnd. The sign (1 or −1) of Gamma(op) is returned in the object
// pointed to by signp. When op is 1 or 2, set rop to +0 (in all rounding modes). When op
// is an infinity or a nonpositive integer, set rop to +Inf. When op is NaN, −Inf or a negative
// integer, *signp is undefined, and when op is ±0, *signp is the sign of the zero.

int f_digamma(void * r, void * op, int rnd) {
	return mpfr_digamma((mpfr_ptr)r, (mpfr_srcptr)op, (mpfr_rnd_t)rnd);
}
// Set rop to the value of the Digamma (sometimes also called Psi) function on op, rounded in
// the direction rnd. When op is a negative integer, set rop to NaN.

//int f_beta(void * rop, void * op1, void * op2, int rnd) {
//	return mpfr_beta((mpfr_ptr)rop, (mpfr_srcptr)op1, (mpfr_srcptr)op2, (mpfr_rnd_t)rnd);
//}
// Set rop to the value of the Beta function at arguments op1 and op2. Note: the current code
// does not try to avoid internal overflow or underflow, and might use a huge internal precision
// in some cases.

int f_zeta(void * r, void * op, int rnd) {
	return mpfr_zeta((mpfr_ptr)r, (mpfr_srcptr)op, (mpfr_rnd_t)rnd);
}
int f_zeta_ui(void * rop, unsigned long op, int rnd) {
	return mpfr_zeta_ui((mpfr_ptr)rop, op, (mpfr_rnd_t)rnd);
}
// Set rop to the value of the Riemann Zeta function on op, rounded in the direction rnd.

int f_erf(void * r, void * op, int rnd) {
	return mpfr_erf((mpfr_ptr)r, (mpfr_srcptr)op, (mpfr_rnd_t)rnd);
}
int f_erfc(void * r, void * op, int rnd) {
	return mpfr_erfc((mpfr_ptr)r, (mpfr_srcptr)op, (mpfr_rnd_t)rnd);
}
// Set rop to the value of the error function on op (resp. the complementary error function on
// op) rounded in the direction rnd.

int f_j0(void * r, void * op, int rnd) {
	return mpfr_j0((mpfr_ptr)r, (mpfr_srcptr)op, (mpfr_rnd_t)rnd);
}
int f_j1(void * r, void * op, int rnd) {
	return mpfr_j1((mpfr_ptr)r, (mpfr_srcptr)op, (mpfr_rnd_t)rnd);
}
int f_jn(void * rop, long n, void * op, int rnd) {
	return mpfr_jn((mpfr_ptr)rop, n, (mpfr_ptr)op, (mpfr_rnd_t)rnd);
}
// Set rop to the value of the first kind Bessel function of order 0, (resp. 1 and n) on op, rounded
// in the direction rnd. When op is NaN, rop is always set to NaN. When op is plus or minus
// Infinity, rop is set to +0. When op is zero, and n is not zero, rop is set to +0 or −0 depending
// on the parity and sign of n, and the sign of op.

int f_y0(void * r, void * op, int rnd) {
	return mpfr_y0((mpfr_ptr)r, (mpfr_srcptr)op, (mpfr_rnd_t)rnd);
}
int f_y1(void * r, void * op, int rnd) {
	return mpfr_y1((mpfr_ptr)r, (mpfr_srcptr)op, (mpfr_rnd_t)rnd);
}
int f_yn(void * rop, long n, void * op, int rnd) {
	return mpfr_yn((mpfr_ptr)rop, n, (mpfr_ptr)op, (mpfr_rnd_t)rnd);
}
// Set rop to the value of the second kind Bessel function of order 0 (resp. 1 and n) on op,
// rounded in the direction rnd. When op is NaN or negative, rop is always set to NaN. When
// op is +Inf, rop is set to +0. When op is zero, rop is set to +Inf or −Inf depending on the
// parity and sign of n.

int f_fma(void * rop, void * op1, void * op2, void * op3, int rnd) {
	return mpfr_fma((mpfr_ptr)rop, (mpfr_srcptr)op1, (mpfr_srcptr)op2, (mpfr_srcptr)op3, (mpfr_rnd_t)rnd);
}
int f_fms(void * rop, void * op1, void * op2, void * op3, int rnd) {
	return mpfr_fms((mpfr_ptr)rop, (mpfr_srcptr)op1, (mpfr_srcptr)op2, (mpfr_srcptr)op3, (mpfr_rnd_t)rnd);
}
// Set rop to (op1×op2)+op3 (resp. (op1×op2)−op3) rounded in the direction rnd. Concerning
// special values (signed zeros, infinities, NaN), these functions behave like a multiplication
// followed by a separate addition or subtraction. That is, the fused operation matters only for
// rounding.

//int f_fmma(void * rop, void * op1, void * op2, void * op3, void * op4, int rnd) {
//	return mpfr_fmma((mpfr_ptr)rop, (mpfr_srcptr)op1, (mpfr_srcptr)op2, (mpfr_srcptr)op3, (mpfr_srcptr)op4, (mpfr_rnd_t)rnd);
//}
//int f_fmms(void * rop, void * op1, void * op2, void * op3, void * op4, int rnd) {
//	return mpfr_fmms((mpfr_ptr)rop, (mpfr_srcptr)op1, (mpfr_srcptr)op2, (mpfr_srcptr)op3, (mpfr_srcptr)op4, (mpfr_rnd_t)rnd);
//}
// Set rop to (op1×op2)+(op3×op4) (resp. (op1×op2)−(op3×op4)) rounded in the direction
// rnd. In case the computation of op1 × op2 overflows or underflows (or that of op3 × op4),
// the result rop is computed as if the two intermediate products were computed with rounding
// toward zero.

int f_agm(void * rop, void * op1, void * op2, int rnd) {
	return mpfr_agm((mpfr_ptr)rop, (mpfr_srcptr)op1, (mpfr_srcptr)op2, (mpfr_rnd_t)rnd);
}
// Set rop to the arithmetic-geometric mean of op1 and op2, rounded in the direction rnd. The
// arithmetic-geometric mean is the common limit of the sequences un and vn, where u(0)=op1,
// v(0)=op2, u(n+1) is the arithmetic mean of un and vn, and vn+1 is the geometric mean of un and
// vn. If any operand is negative and the other one is not zero, set rop to NaN. If any operand
// is zero and the other one is finite (resp. infinite), set rop to +0 (resp. NaN).

int f_hypot(void * rop, void * x, void * y, int rnd) {
	return mpfr_hypot((mpfr_ptr)rop, (mpfr_srcptr)x, (mpfr_srcptr)y, (mpfr_rnd_t)rnd);
}
// Set rop to the Euclidean norm of x and y, i.e., √(x^2 + y^2), rounded in the direction rnd.
// Special values are handled as described in the ISO C99 (Section F.9.4.3) and IEEE 754-2008
// (Section 9.2.1) standards: If x or y is an infinity, then +Inf is returned in rop, even if the
// other number is NaN.

int f_ai(void * r, void * p, int rnd) {
	return mpfr_ai((mpfr_ptr)r, (mpfr_srcptr)p, (mpfr_rnd_t)rnd);
}
// Set rop to the value of the Airy function Ai on x, rounded in the direction rnd. When x is
// NaN, rop is always set to NaN. When x is +Inf or −Inf, rop is +0. The current implementation
// is not intended to be used with large arguments. It works with |x| typically smaller than 500.
// For larger arguments, other methods should be used and will be implemented in a future
// version.

int f_const_log2(void * rop, int rnd) {
	return mpfr_const_log2((mpfr_ptr)rop, (mpfr_rnd_t)rnd);
}
int f_const_pi(void * rop, int rnd) {
	return mpfr_const_pi((mpfr_ptr)rop, (mpfr_rnd_t)rnd);
}
int f_const_euler(void * rop, int rnd) {
	return mpfr_const_euler((mpfr_ptr)rop, (mpfr_rnd_t)rnd);
}
int f_const_catalan(void * rop, int rnd) {
	return mpfr_const_catalan((mpfr_ptr)rop, (mpfr_rnd_t)rnd);
}
// Set rop to the logarithm of 2, the value of π, of Euler’s constant 0.577. . ., of Catalan’s
// constant 0.915. . ., respectively, rounded in the direction rnd. These functions cache the
// computed values to avoid other calculations if a lower or equal precision is requested. To free
// these caches, use mpfr_free_cache or mpfr_free_cache2.

// You can also use clear_f_cache(), it calls the same function.
void f_free_cache(void) {
	mpfr_free_cache();
}
// Free all caches and pools used by MPFR internally (those local to the current thread and
// those shared by all threads). You should call this function before terminating a thread, even
// if you did not call mpfr_const_* functions directly (they could have been called internally).

//void f_free_cache2(mpfr_free_cache_t way) {
//	mpfr_free_cache2(way);
//}
// Free various caches and pools used by MPFR internally, as specified by way, which is a set
// of flags:
// • those local to the current thread if flag MPFR_FREE_LOCAL_CACHE is set;
// • those shared by all threads if flag MPFR_FREE_GLOBAL_CACHE is set.
// The other bits of way are currently ignored and are reserved for future use; they should be
// zero.
// Note: mpfr_free_cache2(MPFR_FREE_LOCAL_CACHE|MPFR_FREE_GLOBAL_CACHE) is
// currently equivalent to mpfr_free_cache().

//void f_free_pool(void) {
//	mpfr_free_pool();
//}
// Free the pools used by MPFR internally. Note: This function is automatically called after
// the thread-local caches are freed (with mpfr_free_cache or mpfr_free_cache2).

//int f_mp_memory_cleanup(void) {
//	return mpfr_mp_memory_cleanup();
//}
// This function should be called before calling mp_set_memory_functions. See Section 4.7
// [Memory Handling], page 11, for more information. Zero is returned in case of success,
// nonzero in case of error. Errors are currently not possible, but checking the return value is
// recommended for future compatibility.

// The variable "tab" is "const mpfr_ptr tab[]" a pointer to a const array of "mpfr_ptr" variables
int f_sum(void * rop, void * tab, unsigned long int n, int rnd) {
	return mpfr_sum((mpfr_ptr)rop, (mpfr_ptr *const)tab, n, (mpfr_rnd_t)rnd);
}
// Set rop to the sum of all elements of tab, whose size is n, correctly rounded in the direction
// rnd. Warning: for efficiency reasons, tab is an array of pointers to mpfr_t, not an array
// of mpfr_t. If n = 0, then the result is +0, and if n = 1, then the function is equivalent to
// mpfr_set. For the special exact cases, the result is the same as the one obtained with a
// succession of additions (mpfr_add) in infinite precision. In particular, if the result is an exact
// zero and n ≥ 1:
// • if all the inputs have the same sign (i.e., all +0 or all −0), then the result has the same
// sign as the inputs;
// • otherwise, either because all inputs are zeros with at least a +0 and a −0, or because some
// inputs are non-zero (but they globally cancel), the result is +0, except for the MPFR_RNDD
// rounding mode, where it is −0.


// Input and Output Functions

// This section describes functions that perform input from an input/output stream, and functions
// that output to an input/output stream. Passing a null pointer for a stream to any of these
// functions will make them read from stdin and write to stdout, respectively.
// When using a function that takes a FILE * argument, you must include the <stdio.h> standard
// header before mpfr.h, to allow mpfr.h to define prototypes for these functions.

size_t f_out_str_filename(const char * filename, int base, size_t n, void * op, int rnd) {
	FILE * pFile;
	if (filename == NULL)
	{
		return mpfr_out_str(NULL, base, n, (mpfr_srcptr)op, (mpfr_rnd_t)rnd);
	}
	pFile = fopen(filename,"w");
	if (pFile != NULL)
	{
		size_t ret = mpfr_out_str(pFile, base, n, (mpfr_srcptr)op, (mpfr_rnd_t)rnd);
		fclose (pFile);
		return ret;
	}
	return 0;
}
// Output op on stream stream, as a string of digits in base base, rounded in the direction rnd.
// The base may vary from 2 to 62. Print n significant digits exactly, or if n is 0, enough digits
// so that op can be read back exactly (see mpfr_get_str).
// In addition to the significant digits, a decimal point (defined by the current locale) at the
// right of the first digit and a trailing exponent in base 10, in the form ‘eNNN’, are printed. If
// base is greater than 10, ‘@’ will be used instead of ‘e’ as exponent delimiter.
// Return the number of characters written, or if an error occurred, return 0.

size_t f_inp_str_filename(void * rop, const char * filename, int base, int rnd) {
	FILE * pFile;
	if (filename == NULL)
	{
		return mpfr_inp_str((mpfr_ptr)rop, NULL, base, (mpfr_rnd_t)rnd);
	}
	pFile = fopen(filename,"r");
	if (pFile != NULL)
	{
		size_t ret = mpfr_inp_str((mpfr_ptr)rop, pFile, base, (mpfr_rnd_t)rnd);
		fclose (pFile);
		return ret;
	}
	return 0;
}
// Input a string in base base from stream stream, rounded in the direction rnd, and put the
// read float in rop.
// This function reads a word (defined as a sequence of characters between whitespace) and
// parses it using mpfr_set_str. See the documentation of mpfr_strtofr for a detailed description of the valid string formats.
// Return the number of bytes read, or if an error occurred, return 0.

//int f_fpif_export(FILE *stream, int op) {
//	return mpfr_fpif_export(stream, (mpfr_ptr)op);
//}
// Export the number op to the stream stream in a floating-point interchange format. In
// particular one can export on a 32-bit computer and import on a 64-bit computer, or export
// on a little-endian computer and import on a big-endian computer. The precision of op and
// the sign bit of a NaN are stored too. Return 0 iff the export was successful.
// Note: this function is experimental and its interface might change in future versions.

//int mpfr_fpif_import(mpfr t op, FILE *stream) {
//	return mpfr_fpif_import((mpfr_ptr)op, FILE *stream);
//}
// Import the number op from the stream stream in a floating-point interchange format (see
// mpfr_fpif_export). Note that the precision of op is set to the one read from the stream,
// and the sign bit is always retrieved (even for NaN). If the stored precision is zero or greater
// than MPFR_PREC_MAX, the function fails (it returns non-zero) and op is unchanged. If the
// function fails for another reason, op is set to NaN and it is unspecified whether the precision
// of op has changed to the one read from the file. Return 0 iff the import was successful.
// Note: this function is experimental and its interface might change in future versions.

void f_dump(void * op) {
	mpfr_dump((mpfr_ptr)op);
}
// Output op on stdout in some unspecified format, then a newline character. This function is
// mainly for debugging purpose. Thus invalid data may be supported. Everything that is not
// specified may change without breaking the ABI and may depend on the environment.
// The current output format is the following: a minus sign if the sign bit is set (even for NaN);
// ‘@NaN@’, ‘@Inf@’ or ‘0’ if the argument is NaN, an infinity or zero, respectively; otherwise the
// remaining of the output is as follows: ‘0.’ then the p bits of the binary significand, where p is
// the precision of the number; if the trailing bits are not all zeros (which must not occur with
// valid data), they are output enclosed by square brackets; the character ‘E’ followed by the
// exponent written in base 10; in case of invalid data or out-of-range exponent, this function
// outputs three exclamation marks (‘!!!’), followed by flags, followed by three exclamation
// marks (‘!!!’) again. These flags are: ‘N’ if the most significant bit of the significand is 0
// (i.e., the number is not normalized); ‘T’ if there are non-zero trailing bits; ‘U’ if this is a UBF
// number (internal use only); ‘<’ if the exponent is less than the current minimum exponent;
// ‘>’ if the exponent is greater than the current maximum exponent.


// Formatted Output Functions

// The class of mpfr_printf functions provides formatted output in a similar manner as the standard C printf.
// These functions are defined only if your system supports ISO C variadic functions and the corresponding argument access macros.
// When using any of these functions, you must include the <stdio.h> standard header before
// mpfr.h, to allow mpfr.h to define prototypes for these functions.

// 5.9.2 Format String
// The format specification accepted by mpfr_printf is an extension of the printf one. The
// conversion specification is of the form:
// % [flags] [width] [.[precision]] [type] [rounding] conv
// ‘flags’, ‘width’, and ‘precision’ have the same meaning as for the standard printf (in particular, 
// notice that the ‘precision’ is related to the number of digits displayed in the base chosen
// by ‘conv’ and not related to the internal precision of the mpfr_t variable), but note that for
// ‘Re’, the default precision is not the same as the one for ‘e’. mpfr_printf accepts the same
// ‘type’ specifiers as GMP (except the non-standard and deprecated ‘q’, use ‘ll’ instead), namely
// the length modifiers defined in the C standard:
// ‘h’ short
// ‘hh’ char
// ‘j’ intmax_t or uintmax_t
// ‘l’ long or wchar_t
// ‘ll’ long long
// ‘L’ long double
// ‘t’ ptrdiff_t
// ‘z’ size_t
// and the ‘type’ specifiers defined in GMP plus ‘R’ and ‘P’ specific to MPFR (the second column
// in the table below shows the type of the argument read in the argument list and the kind of
// ‘conv’ specifier to use after the ‘type’ specifier):
// ‘F’ mpf_t, float conversions
// ‘Q’ mpq_t, integer conversions
// ‘M’ mp_limb_t, integer conversions
// ‘N’ mp_limb_t array, integer conversions
// ‘Z’ mpz_t, integer conversions
// ‘P’ mpfr_prec_t, integer conversions
// ‘R’ mpfr_t, float conversions
// The ‘type’ specifiers have the same restrictions as those mentioned in the GMP documentation:
// see Section “Formatted Output Strings” in GNU MP. In particular, the ‘type’ specifiers (except
// ‘R’ and ‘P’) are supported only if they are supported by gmp_printf in your GMP build; this
// implies that the standard specifiers, such as ‘t’, must also be supported by your C library if you
// want to use them.
// The ‘rounding’ field is specific to mpfr_t arguments and should not be used with other types.
// With conversion specification not involving ‘P’ and ‘R’ types, mpfr_printf behaves exactly as
// gmp_printf.
// The ‘P’ type specifies that a following ‘d’, ‘i’, ‘o’, ‘u’, ‘x’, or ‘X’ conversion specifier applies
// to a mpfr_prec_t argument. It is needed because the mpfr_prec_t type does not necessarily
// correspond to an int or any fixed standard type. The ‘precision’ field specifies the minimum
// number of digits to appear. The default ‘precision’ is 1. For example:
// 	mpfr_t x;
// 	mpfr_prec_t p;
// 	mpfr_init (x);
// 	...
// 	p = mpfr_get_prec (x);
// 	mpfr_printf ("variable x with %Pu bits", p);
// The ‘R’ type specifies that a following ‘a’, ‘A’, ‘b’, ‘e’, ‘E’, ‘f’, ‘F’, ‘g’, ‘G’, or ‘n’ conversion
// specifier applies to a mpfr_t argument. The ‘R’ type can be followed by a ‘rounding’ specifier
// denoted by one of the following characters:
// ‘U’ round toward plus infinity
// ‘D’ round toward minus infinity
// ‘Y’ round away from zero
// ‘Z’ round toward zero
// ‘N’ round to nearest (with ties to even)
// ‘*’ rounding mode indicated by the mpfr_rnd_t argument just before the corresponding mpfr_t variable.
// The default rounding mode is rounding to nearest. The following three examples are equivalent:
// 	mpfr_t x;
// 	mpfr_init (x);
// 	...
// 	mpfr_printf ("%.128Rf", x);
// 	mpfr_printf ("%.128RNf", x);
// 	mpfr_printf ("%.128R*f", MPFR_RNDN, x);
// Note that the rounding away from zero mode is specified with ‘Y’ because ISO C reserves the
// ‘A’ specifier for hexadecimal output (see below).
// The output ‘conv’ specifiers allowed with mpfr_t parameter are:
// ‘a’ ‘A’ hex float, C99 style
// ‘b’ binary output
// ‘e’ ‘E’ scientific-format float
// ‘f’ ‘F’ fixed-point float
// ‘g’ ‘G’ fixed-point or scientific float
// The conversion specifier ‘b’ which displays the argument in binary is specific to mpfr_t arguments
// and should not be used with other types. Other conversion specifiers have the same meaning as
// for a double argument.
// In case of non-decimal output, only the significand is written in the specified base, the exponent
// is always displayed in decimal. Special values are always displayed as nan, -inf, and inf for
// ‘a’, ‘b’, ‘e’, ‘f’, and ‘g’ specifiers and NAN, -INF, and INF for ‘A’, ‘E’, ‘F’, and ‘G’ specifiers.
// If the ‘precision’ field is not empty, the mpfr_t number is rounded to the given precision in
// the direction specified by the rounding mode. If the precision is zero with rounding to nearest
// mode and one of the following ‘conv’ specifiers: ‘a’, ‘A’, ‘b’, ‘e’, ‘E’, tie case is rounded to
// even when it lies between two consecutive values at the wanted precision which have the same
// exponent, otherwise, it is rounded away from zero. For instance, 85 is displayed as "8e+1" and
// 95 is displayed as "1e+2" with the format specification "%.0RNe". This also applies when the
// ‘g’ (resp. ‘G’) conversion specifier uses the ‘e’ (resp. ‘E’) style. If the precision is set to a value
// greater than the maximum value for an int, it will be silently reduced down to INT_MAX.
// If the ‘precision’ field is empty (as in %Re or %.RE) with ‘conv’ specifier ‘e’ and ‘E’, the number
// is displayed with enough digits so that it can be read back exactly, assuming that the input and
// output variables have the same precision and that the input and output rounding modes are
// both rounding to nearest (as for mpfr_get_str). The default precision for an empty ‘precision’
// field with ‘conv’ specifiers ‘f’, ‘F’, ‘g’, and ‘G’ is 6.
// 5.9.3 Functions
// For all the following functions, if the number of characters that ought to be written exceeds
// the maximum limit INT_MAX for an int, nothing is written in the stream (resp. to stdout, to
// buf, to str), the function returns −1, sets the erange flag, and errno is set to EOVERFLOW if the
// EOVERFLOW macro is defined (such as on POSIX systems). Note, however, that errno might be
// changed to another value by some internal library call if another error occurs there (currently,
// this would come from the unallocation function).

int f_fprintf_filename(const char * filename, const char *format, void * op) {
	FILE * pFile;
	if (filename == NULL)
	{
		return mpfr_fprintf(NULL, format, (mpfr_srcptr)op);
	}
	pFile = fopen(filename,"w");
	if (pFile != NULL)
	{
		int ret = mpfr_fprintf(pFile, format, (mpfr_srcptr)op);
		fclose (pFile);
		return ret;
	}
	return INT_MIN; // (-2147483648)
}
// Print to the stream stream the optional arguments under the control of the format string
// format. Return the number of characters written or a negative value if an error occurred.

int f_printf(const char *format, void * op) {
	return mpfr_printf(format, (mpfr_srcptr)op);
}
// Print to stdout the optional arguments under the control of the format string format.
// Return the number of characters written or a negative value if an error occurred.

//int mpfr_sprintf(char *buf, const char *format,  . . .) {
// Form a null-terminated string corresponding to the optional arguments under the control of
// the format string format, and print it in buf. No overlap is permitted between buf and
// the other arguments. Return the number of characters written in the array buf not counting
// the terminating null character or a negative value if an error occurred.

int f_snprintf(char *buf, size_t n, const char *format, void * op) {
	return mpfr_snprintf(buf, n, format, (mpfr_srcptr)op);
}
// Form a null-terminated string corresponding to the optional arguments under the control of
// the format string format, and print it in buf. If n is zero, nothing is written and buf
// may be a null pointer, otherwise, the n−1 first characters are written in buf and the n-th is
// a null character. Return the number of characters that would have been written had n been
// sufficiently large, not counting the terminating null character, or a negative value if an error
// occurred.

int f_asprintf(char **str, const char *format, void * op) {
	// be sure to: free(*str);
	return mpfr_asprintf(str, format, (mpfr_srcptr)op);
}
// Write their output as a null terminated string in a block of memory allocated using the
// allocation function (see Section 4.7 [Memory Handling], page 11). A pointer to the block is
// stored in str. The block of memory must be freed using mpfr_free_str. The return value is
// the number of characters written in the string, excluding the null-terminator, or a negative
// value if an error occurred, in which case the contents of str are undefined.


// Integer and Remainder Related Functions

int f_rint(void * rop, void * op, int rnd) {
	return mpfr_rint((mpfr_ptr)rop, (mpfr_srcptr)op, (mpfr_rnd_t)rnd);
}
int f_ceil(void * rop, void * op) {
	return mpfr_ceil((mpfr_ptr)rop, (mpfr_srcptr)op);
}
int f_floor(void * rop, void * op) {
	return mpfr_floor((mpfr_ptr)rop, (mpfr_srcptr)op);
}
int f_round(void * rop, void * op) {
	return mpfr_round((mpfr_ptr)rop, (mpfr_srcptr)op);
}
//int f_roundeven(void * rop, void * op) {
//	return mpfr_roundeven((mpfr_ptr)rop, (mpfr_srcptr)op);
//}

int f_trunc(void * rop, void * op) {
	return mpfr_trunc((mpfr_ptr)rop, (mpfr_srcptr)op);
}
// Set rop to op rounded to an integer. mpfr_rint rounds to the nearest representable integer
// in the given direction rnd, and the other five functions behave in a similar way with some
// fixed rounding mode:
// • mpfr_ceil: to the next higher or equal representable integer (like mpfr_rint with MPFR_
// RNDU);
// • mpfr_floor to the next lower or equal representable integer (like mpfr_rint with MPFR_
// RNDD);
// • mpfr_round to the nearest representable integer, rounding halfway cases away from zero
// (as in the roundTiesToAway mode of IEEE 754-2008);
// • mpfr_roundeven to the nearest representable integer, rounding halfway cases with the
// even-rounding rule (like mpfr_rint with MPFR_RNDN);
// • mpfr_trunc to the next representable integer toward zero (like mpfr_rint with MPFR_
// RNDZ).
// When op is a zero or an infinity, set rop to the same value (with the same sign).
// The return value is zero when the result is exact, positive when it is greater than the original
// value of op, and negative when it is smaller. More precisely, the return value is 0 when op
// is an integer representable in rop, 1 or −1 when op is an integer that is not representable in
// rop, 2 or −2 when op is not an integer.
// When op is NaN, the NaN flag is set as usual. In the other cases, the inexact flag is set
// when rop differs from op, following the ISO C99 rule for the rint function. If you want
// the behavior to be more like IEEE 754 / ISO TS 18661-1, i.e., the usual behavior where the
// round-to-integer function is regarded as any other mathematical function, you should use one
// the mpfr_rint_* functions instead.
// Note that no double rounding is performed; for instance, 10.5 (1010.1 in binary) is rounded
// by mpfr_rint with rounding to nearest to 12 (1100 in binary) in 2-bit precision, because
// the two enclosing numbers representable on two bits are 8 and 12, and the closest is 12. (If
// one first rounded to an integer, one would round 10.5 to 10 with even rounding, and then 10
// would be rounded to 8 again with even rounding.)

int f_rint_ceil(void * rop, void * op, int rnd) {
	return mpfr_rint_ceil((mpfr_ptr)rop, (mpfr_srcptr)op, (mpfr_rnd_t)rnd);
}
int f_rint_floor(void * rop, void * op, int rnd) {
	return mpfr_rint_floor((mpfr_ptr)rop, (mpfr_srcptr)op, (mpfr_rnd_t)rnd);
}
int f_rint_round(void * rop, void * op, int rnd) {
	return mpfr_rint_round((mpfr_ptr)rop, (mpfr_srcptr)op, (mpfr_rnd_t)rnd);
}
//int f_rint_roundeven(void * rop, void * op, int rnd) {
//	return mpfr_rint_roundeven((mpfr_ptr)rop, (mpfr_srcptr)op, (mpfr_rnd_t)rnd);
//}
int f_rint_trunc(void * rop, void * op, int rnd) {
	return mpfr_rint_trunc((mpfr_ptr)rop, (mpfr_srcptr)op, (mpfr_rnd_t)rnd);
}
// Set rop to op rounded to an integer:
// • mpfr_rint_ceil: to the next higher or equal integer;
// • mpfr_rint_floor: to the next lower or equal integer;
// • mpfr_rint_round: to the nearest integer, rounding halfway cases away from zero;
// • mpfr_rint_roundeven: to the nearest integer, rounding halfway cases to the nearest
// even integer;
// • mpfr_rint_trunc to the next integer toward zero.
// If the result is not representable, it is rounded in the direction rnd. When op is a zero or
// an infinity, set rop to the same value (with the same sign). The return value is the ternary
// value associated with the considered round-to-integer function (regarded in the same way as
// any other mathematical function).
// Contrary to mpfr_rint, those functions do perform a double rounding: first op is rounded
// to the nearest integer in the direction given by the function name, then this nearest integer
// (if not representable) is rounded in the given direction rnd. Thus these round-to-integer
// functions behave more like the other mathematical functions, i.e., the returned result is the
// correct rounding of the exact result of the function in the real numbers.
// For example, mpfr_rint_round with rounding to nearest and a precision of two bits rounds
// 6.5 to 7 (halfway cases away from zero), then 7 is rounded to 8 by the round-even rule, despite
// the fact that 6 is also representable on two bits, and is closer to 6.5 than 8.

int f_frac(void * rop, void * op, int rnd) {
	return mpfr_frac((mpfr_ptr)rop, (mpfr_srcptr)op, (mpfr_rnd_t)rnd);
}
// Set rop to the fractional part of op, having the same sign as op, rounded in the direction rnd
// (unlike in mpfr_rint, rnd affects only how the exact fractional part is rounded, not how the
// fractional part is generated). When op is an integer or an infinity, set rop to zero with the
// same sign as op.

int f_modf(void * iop, void * fop, void * op, int rnd) {
	return mpfr_modf((mpfr_ptr)iop, (mpfr_ptr)fop, (mpfr_srcptr)op, (mpfr_rnd_t)rnd);
}
// Set simultaneously iop to the integral part of op and fop to the fractional part of op, rounded
// in the direction rnd with the corresponding precision of iop and fop (equivalent to mpfr_
// trunc(iop, op, rnd) and mpfr_frac(fop, op, rnd)). The variables iop and fop must be
// different. Return 0 iff both results are exact (see mpfr_sin_cos for a more detailed description
// of the return value).

int f_fmod(void * r, void * x, void * y, int rnd) {
	return mpfr_fmod((mpfr_ptr)r, (mpfr_srcptr)x, (mpfr_srcptr)y, (mpfr_rnd_t)rnd);
}
//int f_fmodquo(void * r, long* q, void * x, void * y, int rnd) {
//	return mpfr_fmodquo((mpfr_ptr)r, q, (mpfr_srcptr)x, (mpfr_srcptr)y, (mpfr_rnd_t)rnd);
//}
int f_remainder(void * r, void * x, void * y, int rnd) {
	return mpfr_remainder((mpfr_ptr)r, (mpfr_srcptr)x, (mpfr_srcptr)y, (mpfr_rnd_t)rnd);
}
int f_remquo(void * r, long* q, void * x, void * y, int rnd) {
	return mpfr_remquo((mpfr_ptr)r, q, (mpfr_srcptr)x, (mpfr_srcptr)y, (mpfr_rnd_t)rnd);
}
// Set r to the value of x − ny, rounded according to the direction rnd, where n is the integer
// quotient of x divided by y, defined as follows: n is rounded toward zero for mpfr_fmod and
// mpfr_fmodquo, and to the nearest integer (ties rounded to even) for mpfr_remainder and
// mpfr_remquo.
// Special values are handled as described in Section F.9.7.1 of the ISO C99 standard: If x is
// infinite or y is zero, r is NaN. If y is infinite and x is finite, r is x rounded to the precision of
// r. If r is zero, it has the sign of x. The return value is the ternary value corresponding to r.
// Additionally, mpfr_fmodquo and mpfr_remquo store the low significant bits from the quotient
// n in *q (more precisely the number of bits in a long minus one), with the sign of x divided
// by y (except if those low bits are all zero, in which case zero is returned). Note that x may
// be so large in magnitude relative to y that an exact representation of the quotient is not
// practical. The mpfr_remainder and mpfr_remquo functions are useful for additive argument
// reduction.

int f_integer_p(void * op) {
	return mpfr_integer_p((mpfr_srcptr)op);
}
// Return non-zero iff op is an integer.


// Rounding-Related Functions

void f_set_default_rounding_mode(int rnd) {
	mpfr_set_default_rounding_mode((mpfr_rnd_t)rnd);
}
// Set the default rounding mode to rnd. The default rounding mode is to nearest initially.

int f_get_default_rounding_mode(void) {
	return (int)mpfr_get_default_rounding_mode();
}
// Get the default rounding mode.

int f_prec_round(void * x, long prec, int rnd) {
	return mpfr_prec_round((mpfr_ptr)x, (mpfr_prec_t)prec, (mpfr_rnd_t)rnd);
}
// Round x according to rnd with precision prec, which must be an integer between MPFR_PREC_
// MIN and MPFR_PREC_MAX (otherwise the behavior is undefined). If prec is greater or equal to
// the precision of x, then new space is allocated for the significand, and it is filled with zeros.
// Otherwise, the significand is rounded to precision prec with the given direction. In both
// cases, the precision of x is changed to prec.
// Here is an example of how to use mpfr_prec_round to implement Newton’s algorithm to
// compute the inverse of a, assuming x is already an approximation to n bits:
//		mpfr_set_prec (t, 2 * n);
//		mpfr_set (t, a, MPFR_RNDN); // round a to 2n bits
//		mpfr_mul (t, t, x, MPFR_RNDN); // t is correct to 2n bits
//		mpfr_ui_sub (t, 1, t, MPFR_RNDN); // high n bits cancel with 1
//		mpfr_prec_round (t, n, MPFR_RNDN); // t is correct to n bits
//		mpfr_mul (t, t, x, MPFR_RNDN); // t is correct to n bits
//		mpfr_prec_round (x, 2 * n, MPFR_RNDN); // exact
//		mpfr_add (x, x, t, MPFR_RNDN); // x is correct to 2n bits
// Warning! You must not use this function if x was initialized with MPFR_DECL_INIT or with
// mpfr_custom_init_set (see Section 5.15 [Custom Interface], page 46).

int f_can_round(void * b, long err, int rnd1, int rnd2, long prec) {
	return mpfr_can_round((mpfr_srcptr)b, (mpfr_exp_t)err, (mpfr_rnd_t)rnd1, (mpfr_rnd_t)rnd2, (mpfr_prec_t)prec);
}
// Assuming b is an approximation of an unknown number x in the direction rnd1 with error
// at most two to the power E(b)-err where E(b) is the exponent of b, return a non-zero value
// if one is able to round correctly x to precision prec with the direction rnd2 assuming an
// unbounded exponent range, and 0 otherwise (including for NaN and Inf). In other words, if
// the error on b is bounded by two to the power k ulps, and b has precision prec, you should
// give err=prec−k. This function does not modify its arguments.
// If rnd1 is MPFR_RNDN or MPFR_RNDF, the error is considered to be either positive or negative,
// thus the possible range is twice as large as with a directed rounding for rnd1 (with the same
// value of err).
// When rnd2 is MPFR_RNDF, let rnd3 be the opposite direction if rnd1 is a directed rounding,
// and MPFR_RNDN if rnd1 is MPFR_RNDN or MPFR_RNDF. The returned value of mpfr_can_round
// (b, err, rnd1, MPFR_RNDF, prec) is non-zero iff after the call mpfr_set (y, b, rnd3) with
// y of precision prec, y is guaranteed to be a faithful rounding of x.
// Note: The [ternary value], page 8, cannot be determined in general with this function. However, if it is known that the exact value is not exactly representable in precision prec, then
// one can use the following trick to determine the (non-zero) ternary value in any rounding
// mode rnd2 (note that MPFR_RNDZ below can be replaced by any directed rounding mode):
//		if (mpfr_can_round (b, err, MPFR_RNDN, MPFR_RNDZ,
//		prec + (rnd2 == MPFR_RNDN)))
//		{
//			// round the approximation ’b’ to the result ’r’ of ’prec’ bits
//			// with rounding mode ’rnd2’ and get the ternary value ’inex’
//			inex = mpfr_set (r, b, rnd2);
//		}
// Indeed, if rnd2 is MPFR_RNDN, this will check if one can round to prec+1 bits with a directed
// rounding: if so, one can surely round to nearest to prec bits, and in addition one can determine
// the correct ternary value, which would not be the case when b is near from a value exactly
// representable on prec bits.
// A detailed example is available in the examples subdirectory, file can_round.c.

long f_min_prec(void * x) {
	return (long)mpfr_min_prec((mpfr_srcptr)x);
}
// Return the minimal number of bits required to store the significand of x, and 0 for special
// values, including 0.

const char * f_print_rnd_mode(int rnd) {
	return mpfr_print_rnd_mode((mpfr_rnd_t)rnd);
}
// Return a string ("MPFR RNDD", "MPFR RNDU", "MPFR RNDN", "MPFR RNDZ",
// "MPFR RNDA") corresponding to the rounding mode rnd, or a null pointer if rnd is an
// invalid rounding mode.

//int mpfr_round_nearest_away (int (foo)(mpfr t, type1 t, ..., mpfr rnd t), [Macro]
//mpfr t rop, type1 t op, ...)
// Given a function foo and one or more values op (which may be a mpfr_t, a long, a double,
// etc.), put in rop the round-to-nearest-away rounding of foo(op,...). This rounding is
// defined in the same way as round-to-nearest-even, except in case of tie, where the value
// away from zero is returned. The function foo takes as input, from second to penultimate
// argument(s), the argument list given after rop, a rounding mode as final argument, puts in its
// first argument the value foo(op,...) rounded according to this rounding mode, and returns
// the corresponding ternary value (which is expected to be correct, otherwise mpfr_round_
// nearest_away will not work as desired). Due to implementation constraints, this function
// must not be called when the minimal exponent emin is the smallest possible one. This macro
// has been made such that the compiler is able to detect mismatch between the argument list
// op and the function prototype of foo. Multiple input arguments op are supported only with
// C99 compilers. Otherwise, for C89 compilers, only one such argument is supported.
// Note: this macro is experimental and its interface might change in future versions.
//		unsigned long ul;
//		mpfr_t f, r;
//		// Code that inits and sets r, f, and ul, and if needed sets emin
//		int return mpfr_round_nearest_away (mpfr_add_ui, r, f, ul);


// Miscellaneous Functions

void f_nexttoward(void * x, void * y) {
	mpfr_nexttoward((mpfr_ptr)x, (mpfr_srcptr)y);
}
// If x or y is NaN, set x to NaN; note that the NaN flag is set as usual. If x and y are equal, x
// is unchanged. Otherwise, if x is different from y, replace x by the next floating-point number
// (with the precision of x and the current exponent range) in the direction of y (the infinite
// values are seen as the smallest and largest floating-point numbers). If the result is zero, it
// keeps the same sign. No underflow, overflow, or inexact exception is raised.

void f_nextabove(void * x) {
	mpfr_nextabove((mpfr_ptr)x);
}
void f_nextbelow(void * x) {
	mpfr_nextbelow((mpfr_ptr)x);
}
// Equivalent to mpfr_nexttoward where y is plus infinity (resp. minus infinity).

int f_min(void * rop, void * op1, void * op2, int rnd) {
	return mpfr_min((mpfr_ptr)rop, (mpfr_srcptr)op1, (mpfr_srcptr)op2, (mpfr_rnd_t)rnd);
}
int f_max(void * rop, void * op1, void * op2, int rnd) {
	return mpfr_max((mpfr_ptr)rop, (mpfr_srcptr)op1, (mpfr_srcptr)op2, (mpfr_rnd_t)rnd);
}
// Set rop to the minimum (resp. maximum) of op1 and op2. If op1 and op2 are both NaN,
// then rop is set to NaN. If op1 or op2 is NaN, then rop is set to the numeric value. If op1
// and op2 are zeros of different signs, then rop is set to −0 (resp. +0).

//int mpfr_urandomb (mpfr t rop, gmp randstate t state) {
//	int mpfr_urandomb (mpfr t rop, gmp randstate t state);
//}
// Generate a uniformly distributed random float in the interval 0 ≤ rop < 1. More precisely,
// the number can be seen as a float with a random non-normalized significand and exponent 0,
// which is then normalized (thus if e denotes the exponent after normalization, then the least
// −e significant bits of the significand are always 0).
// Return 0, unless the exponent is not in the current exponent range, in which case rop is set
// to NaN and a non-zero value is returned (this should never happen in practice, except in
// very specific cases). The second argument is a gmp_randstate_t structure which should be
// created using the GMP gmp_randinit function (see the GMP manual).
// Note: for a given version of MPFR, the returned value of rop and the new value of state
// (which controls further random values) do not depend on the machine word size.

//int mpfr_urandom (mpfr t rop, gmp randstate t state, mpfr rnd t rnd) {
//	int mpfr_urandom (mpfr t rop, gmp randstate t state, mpfr rnd t rnd);
//}
// Generate a uniformly distributed random float. The floating-point number rop can be seen
// as if a random real number is generated according to the continuous uniform distribution on
// the interval [0, 1] and then rounded in the direction rnd.
// The second argument is a gmp_randstate_t structure which should be created using the
// GMP gmp_randinit function (see the GMP manual).
// Note: the note for mpfr_urandomb holds too. Moreover, the exact number (the random value
// to be rounded) and the next random state do not depend on the current exponent range and
// the rounding mode. However, they depend on the target precision: from the same state of
// the random generator, if the precision of the destination is changed, then the value may be
// completely different (and the state of the random generator is different too).

//int mpfr_nrandom (mpfr t rop1, gmp randstate t state, mpfr rnd t rnd) {
//	int mpfr_nrandom (mpfr t rop1, gmp randstate t state, mpfr rnd t;
//}
//int mpfr_grandom (mpfr t rop1, mpfr t rop2, gmp randstate t state, mpfr rnd t rnd) {
//	int mpfr_grandom (mpfr t rop1, mpfr t rop2, gmp randstate t state, mpfr rnd t rnd);
//}
// Generate one (possibly two for mpfr_grandom) random floating-point number according to
// a standard normal Gaussian distribution (with mean zero and variance one). For mpfr_
// grandom, if rop2 is a null pointer, then only one value is generated and stored in rop1.
// The floating-point number rop1 (and rop2) can be seen as if a random real number were
// generated according to the standard normal Gaussian distribution and then rounded in the
// direction rnd.
// The gmp_randstate_t argument should be created using the GMP gmp_randinit function
// (see the GMP manual).
// For mpfr_grandom, the combination of the ternary values is returned like with mpfr_sin_cos.
// If rop2 is a null pointer, the second ternary value is assumed to be 0 (note that the encoding
// of the only ternary value is not the same as the usual encoding for functions that return only
// one result). Otherwise the ternary value of a random number is always non-zero.
// Note: the note for mpfr_urandomb holds too. In addition, the exponent range and the
// rounding mode might have a side effect on the next random state.
// Note: mpfr_nrandom is much more efficient than mpfr_grandom, especially for large precision.
// Thus mpfr_grandom is marked as deprecated and will be removed in a future release.

//int int_erandom(void * rop1, void * state, int rnd) {
//	return mpfr_erandom((mpfr_ptr)rop1, (__gmp_randstate_struct*)state, (mpfr_rnd_t)rnd);
//}
// Generate one random floating-point number according to an exponential distribution, with
// mean one. Other characteristics are identical to mpfr_nrandom.

long f_get_exp(void * x) {
	return (long)mpfr_get_exp((mpfr_srcptr)x);
}
// Return the exponent of x, assuming that x is a non-zero ordinary number and the significand
// is considered in [1/2,1). For this function, x is allowed to be outside of the current range of
// acceptable values. The behavior for NaN, infinity or zero is undefined.

int f_set_exp(void * x, long e) {
	return mpfr_set_exp((mpfr_ptr)x, (mpfr_exp_t)e);
}
// Set the exponent of x to e if x is a non-zero ordinary number and e is in the current exponent
// range, and return 0; otherwise, return a non-zero value (x is not changed).

int f_signbit(void * op) {
	return mpfr_signbit((mpfr_srcptr)op);
}
// Return a non-zero value iff op has its sign bit set (i.e., if it is negative, −0, or a NaN whose
// representation has its sign bit set).

int f_setsign(void * rop, void * op, int s, int rnd) {
	return mpfr_setsign((mpfr_ptr)rop, (mpfr_srcptr)op, s, (mpfr_rnd_t)rnd);
}
// Set the value of rop from op, rounded toward the given direction rnd, then set (resp. clear)
// its sign bit if s is non-zero (resp. zero), even when op is a NaN.

int f_copysign(void * rop, void * op1, void * op2, int rnd) {
	return mpfr_copysign((mpfr_ptr)rop, (mpfr_srcptr)op1, (mpfr_srcptr)op2, (mpfr_rnd_t)rnd);
}
// Set the value of rop from op1, rounded toward the given direction rnd, then set its sign bit to
// that of op2 (even when op1 or op2 is a NaN). This function is equivalent to mpfr_setsign
// (rop, op1, mpfr_signbit (op2), rnd).

const char * f_get_version(void) {
	return mpfr_get_version();
}
// Return the MPFR version, as a null-terminated string.

long f_MPFR_VERSION() {
	return MPFR_VERSION;
}
long f_MPFR_VERSION_MAJOR() {
	return MPFR_VERSION_MAJOR;
}
long f_MPFR_VERSION_MINOR() {
	return MPFR_VERSION_MINOR;
}
long f_MPFR_VERSION_PATCHLEVEL() {
	return MPFR_VERSION_PATCHLEVEL;
}
//MPFR_VERSION_STRING // Use "f_get_version()" instead of using this macro
// MPFR_VERSION is the version of MPFR as a preprocessing constant. MPFR_VERSION_MAJOR,
// MPFR_VERSION_MINOR and MPFR_VERSION_PATCHLEVEL are respectively the major, minor and
// patch level of MPFR version, as preprocessing constants. MPFR_VERSION_STRING is the version (with an optional suffix, used in development and pre-release versions) as a string constant, which can be compared to the result of mpfr_get_version to check at run time the
// header file and library used match:
//	if (strcmp (mpfr_get_version (), MPFR_VERSION_STRING))
//		fprintf (stderr, "Warning: header and library do not match\n");
// Note: Obtaining different strings is not necessarily an error, as in general, a program compiled
// with some old MPFR version can be dynamically linked with a newer MPFR library version
// (if allowed by the library versioning system).

long f_MPFR_VERSION_NUM(long major, long minor, long patchlevel) {
	return MPFR_VERSION_NUM(major, minor, patchlevel);
}
// Create an integer in the same format as used by MPFR_VERSION from the given major, minor
// and patchlevel. Here is an example of how to check the MPFR version at compile time:
//	#if (!defined(MPFR_VERSION) || (MPFR_VERSION<MPFR_VERSION_NUM(3,0,0)))
//		# error "Wrong MPFR version."
//	#endif

const char * f_get_patches(void) {
	return mpfr_get_patches();
}
// Return a null-terminated string containing the ids of the patches applied to the MPFR library
// (contents of the PATCHES file), separated by spaces. Note: If the program has been compiled
// with an older MPFR version and is dynamically linked with a new MPFR library version, the
// identifiers of the patches applied to the old (compile-time) MPFR version are not available
// (however this information should not have much interest in general).

int f_buildopt_tls_p(void) {
	return mpfr_buildopt_tls_p();
}
// 	Return a non-zero value if MPFR was compiled as thread safe using compiler-level Thread
// 	Local Storage (that is, MPFR was built with the ‘--enable-thread-safe’ configure option,
// 	see INSTALL file), return zero otherwise.

//int f_buildopt_float128_p (void) {
//	int mpfr_buildopt_float128_p (void);
//}
// Return a non-zero value if MPFR was compiled with ‘__float128’ support (that is, MPFR
// was built with the ‘--enable-float128’ configure option), return zero otherwise.

int f_buildopt_decimal_p(void) {
	return mpfr_buildopt_decimal_p();
}
// Return a non-zero value if MPFR was compiled with decimal float support (that is, MPFR
// was built with the ‘--enable-decimal-float’ configure option), return zero otherwise.

int f_buildopt_gmpinternals_p (void) {
	return mpfr_buildopt_gmpinternals_p();
}
// Return a non-zero value if MPFR was compiled with GMP internals (that is, MPFR was built
// with either ‘--with-gmp-build’ or ‘--enable-gmp-internals’ configure option), return zero
// otherwise.

//int f_buildopt_sharedcache_p (void) {
//	int mpfr_buildopt_sharedcache_p (void);
//}
// Return a non-zero value if MPFR was compiled so that all threads share the same cache
// for one MPFR constant, like mpfr_const_pi or mpfr_const_log2 (that is, MPFR was built
// with the ‘--enable-shared-cache’ configure option), return zero otherwise. If the return
// value is non-zero, MPFR applications may need to be compiled with the ‘-pthread’ option.

//const a * mpfr_buildopt_tune_case (void) {
//	const char * mpfr_buildopt_tune_case (void);
//}
// Return a string saying which thresholds file has been used at compile time. This file is
// normally selected from the processor type.


// Exception Related Functions

long f_get_emin(void) {
	return (long)mpfr_get_emin();
}
long f_get_emax(void) {
	return (long)mpfr_get_emax();
}
// Return the (current) smallest and largest exponents allowed for a floating-point variable. The
// smallest positive value of a floating-point variable is 1/2 × 2
// emin and the largest value has the
// form (1 − ε) × 2
// emax, where ε depends on the precision of the considered variable.

int f_set_emin(long exp) {
	return mpfr_set_emin((mpfr_exp_t)exp);
}
int f_set_emax(long exp) {
	return mpfr_set_emax((mpfr_exp_t)exp);
}
// Set the smallest and largest exponents allowed for a floating-point variable. Return a nonzero value when exp is not in the range accepted by the implementation (in that case the
// smallest or largest exponent is not changed), and zero otherwise.
// For the subsequent operations, it is the user’s responsibility to check that any floating-point
// value used as an input is in the new exponent range (for example using mpfr_check_range).
// If a floating-point value outside the new exponent range is used as an input, the default
// behavior is undefined, in the sense of the ISO C standard; the behavior may also be explicitly
// documented, such as for mpfr_check_range.
// Note: Caches may still have values outside the current exponent range. This is not an issue
// as the user cannot use these caches directly via the API (MPFR extends the exponent range
// internally when need be).
// If emin > emax and a floating-point value needs to be produced as output, the behavior is
// undefined (mpfr_set_emin and mpfr_set_emax do not check this condition as it might occur
// between successive calls to these two functions).

long f_get_emin_min(void) {
	return (long)mpfr_get_emin_min();
}
long f_get_emin_max(void) {
	return (long)mpfr_get_emin_max();
}
long f_get_emax_min(void) {
	return (long)mpfr_get_emax_min();
}
long f_get_emax_max(void) {
	return (long)mpfr_get_emax_max();
}
// Return the minimum and maximum of the exponents allowed for mpfr_set_emin and
// mpfr_set_emax respectively. These values are implementation dependent, thus a program
// using mpfr_set_emax(mpfr_get_emax_max()) or mpfr_set_emin(mpfr_get_emin_min())
// may not be portable.

int f_check_range(void * x, int t, int rnd) {
	return mpfr_check_range((mpfr_ptr)x, t, (mpfr_rnd_t)rnd);
}
// This function assumes that x is the correctly rounded value of some real value y in the
// direction rnd and some extended exponent range, and that t is the corresponding [ternary
// value], page 8. For example, one performed t = mpfr_log (x, u, rnd), and y is the exact
// logarithm of u. Thus t is negative if x is smaller than y, positive if x is larger than y, and
// zero if x equals y. This function modifies x if needed to be in the current range of acceptable
// values: It generates an underflow or an overflow if the exponent of x is outside the current
// allowed range; the value of t may be used to avoid a double rounding. This function returns
// zero if the new value of x equals the exact one y, a positive value if that new value is larger
// than y, and a negative value if it is smaller than y. Note that unlike most functions, the new
// result x is compared to the (unknown) exact one y, not the input value x, i.e., the ternary
// value is propagated.
// Note: If x is an infinity and t is different from zero (i.e., if the rounded result is an inexact
// infinity), then the overflow flag is set. This is useful because mpfr_check_range is typically
// called (at least in MPFR functions) after restoring the flags that could have been set due to
// internal computations.

int f_subnormalize(void * x, int t, int rnd) {
	return mpfr_subnormalize((mpfr_ptr)x, t, (mpfr_rnd_t)rnd);
}
// This function rounds x emulating subnormal number arithmetic: if x is outside the subnormal exponent range of the emulated floating-point system, this function just propagates the
// [ternary value], page 8, t; otherwise, it rounds x to precision EXP(x)-emin+1 according to
// rounding mode rnd and previous ternary value t, avoiding double rounding problems. More
// precisely in the subnormal domain, denoting by e the value of emin, x is rounded in fixedpoint arithmetic to an integer multiple of 2e−1
// ; as a consequence, 1.5 × 2
// e−1 when t is zero is
// rounded to 2e with rounding to nearest.
// PREC(x) is not modified by this function. rnd and t must be the rounding mode and the
// returned ternary value used when computing x (as in mpfr_check_range). The subnormal
// exponent range is from emin to emin+PREC(x)-1. If the result cannot be represented in the
// current exponent range of MPFR (due to a too small emax), the behavior is undefined. Note
// that unlike most functions, the result is compared to the exact one, not the input value x,
// i.e., the ternary value is propagated.
// As usual, if the returned ternary value is non zero, the inexact flag is set. Moreover, if a
// second rounding occurred (because the input x was in the subnormal range), the underflow
// flag is set.
// Warning! If you change emin (with mpfr_set_emin) just before calling mpfr_subnormalize,
// you need to make sure that the value is in the current exponent range of MPFR. But it is
// better to change emin before any computation, if possible.
// This is an example of how to emulate binary double IEEE 754 arithmetic (binary64 in IEEE
// 754-2008) using MPFR:
//	{
//		mpfr_t xa, xb; int i; volatile double a, b;
//		mpfr_set_default_prec (53);
//		mpfr_set_emin (-1073); mpfr_set_emax (1024);
//		mpfr_init (xa); mpfr_init (xb);
//		b = 34.3; mpfr_set_d (xb, b, MPFR_RNDN);
//		a = 0x1.1235P-1021; mpfr_set_d (xa, a, MPFR_RNDN);
//		a /= b;
//		return mpfr_div (xa, xa, xb, MPFR_RNDN);
//		return mpfr_subnormalize (xa, i, MPFR_RNDN); // new ternary value
//		mpfr_clear (xa); mpfr_clear (xb);
//	}
// Note that mpfr_set_emin and mpfr_set_emax are called early enough in order to make sure
// that all computed values are in the current exponent range. Warning! This emulates a double
// IEEE 754 arithmetic with correct rounding in the subnormal range, which may not be the case
// for your hardware.
// Below is another example showing how to emulate fixed-point arithmetic in a specific case. Here
// we compute the sine of the integers 1 to 17 with a result in a fixed-point arithmetic rounded at
// 2
// −42 (using the fact that the result is at most 1 in absolute value):
//	{
//		mpfr_t x; int i, inex;
//		mpfr_set_emin (-41);
//		mpfr_init2 (x, 42);
//		for (return 1; i <= 17; i++)
//		{
//			mpfr_set_ui (x, i, MPFR_RNDN);
//			inex = mpfr_sin (x, x, MPFR_RNDZ);
//			mpfr_subnormalize (x, inex, MPFR_RNDZ);
//			mpfr_dump (x);
//		}
//		mpfr_clear (x);
//	}

void f_clear_underflow(void) {
	mpfr_clear_underflow();
}
void f_clear_overflow(void) {
	mpfr_clear_overflow();
}
void f_clear_divby0(void) {
	mpfr_clear_divby0();
}
void f_clear_nanflag(void) {
	mpfr_clear_nanflag();
}
void f_clear_inexflag(void) {
	mpfr_clear_inexflag();
}
void f_clear_erangeflag(void) {
	mpfr_clear_erangeflag();
}
// Clear (lower) the underflow, overflow, divide-by-zero, invalid, inexact and erange flags.

void f_clear_flags(void) {
	mpfr_clear_flags();
}
// Clear (lower) all global flags (underflow, overflow, divide-by-zero, invalid, inexact, erange).
// Note: a group of flags can be cleared by using mpfr_flags_clear.

void f_set_underflow(void) {
	mpfr_set_underflow();
}
void f_set_overflow(void) {
	mpfr_set_overflow();
}
void f_set_divby0(void) {
	mpfr_set_divby0();
}
void f_set_nanflag(void) {
	mpfr_set_nanflag();
}
void f_set_inexflag(void) {
	mpfr_set_inexflag();
}
void f_set_erangeflag(void) {
	mpfr_set_erangeflag();
}
// Set (raise) the underflow, overflow, divide-by-zero, invalid, inexact and erange flags.

int f_underflow_p(void) {
	return mpfr_underflow_p();
}
int f_overflow_p(void) {
	return mpfr_overflow_p();
}
int f_divby0_p(void) {
	return mpfr_divby0_p();
}
int f_nanflag_p(void) {
	return mpfr_nanflag_p();
}
int f_inexflag_p(void) {
	return mpfr_inexflag_p();
}
int f_erangeflag_p(void) {
	return mpfr_erangeflag_p();
}
// Return the corresponding (underflow, overflow, divide-by-zero, invalid, inexact, erange) flag,
// which is non-zero iff the flag is set.
// The mpfr_flags_ functions below that take an argument mask can operate on any subset of the
// exception flags: a flag is part of this subset (or group) if and only if the corresponding bit of the
// argument mask is set. The MPFR_FLAGS_ macros will normally be used to build this argument.
// See Section 4.6 [Exceptions], page 10.

//void mpfr_flags_clear (mpfr flags t mask)
// Clear (lower) the group of flags specified by mask.
//void mpfr_flags_set (mpfr flags t mask)
// Set (raise) the group of flags specified by mask.
//mpfr_flags_t mpfr_flags_test (mpfr flags t mask)
// Return the flags specified by mask. To test whether any flag from mask is set, compare the
// return value to 0. You can also test individual flags by AND’ing the result with MPFR_FLAGS_
// macros. Example:
// mpfr_flags_t t = mpfr_flags_test (MPFR_FLAGS_UNDERFLOW|
// MPFR_FLAGS_OVERFLOW)
//	...
//	if (t) // underflow and/or overflow (unlikely)
//	{
//		if (t & MPFR_FLAGS_UNDERFLOW) { // handle underflow
//		}
//		if (t & MPFR_FLAGS_OVERFLOW) { // handle overflow
//		}
//	}
//mpfr_flags_t mpfr_flags_save (void)
// Return all the flags. It is equivalent to mpfr_flags_test(MPFR_FLAGS_ALL).
//void mpfr_flags_restore (mpfr flags t flags, mpfr flags t mask)
// Restore the flags specified by mask to their state represented in flags.


// END mpfr FUNCTIONS


// BEGIN INT FUNCTIONS:

void * allocate_int() {
	return malloc(sizeof(mpz_t));
}
void register_int(void * p) {
	mpz_init((mpz_ptr)p);
}
void clear_int(void * p) {
	mpz_clear((mpz_ptr)p);
}

void int_set(void * dst, void * src) {
	mpz_set((mpz_ptr)dst, (mpz_srcptr)src);
}
void int_set_ui(void * rop, unsigned long int op) {
	mpz_set_ui((mpz_ptr)rop, op);
}
void int_set_si(void * rop, signed long int op) {
	mpz_set_si((mpz_ptr)rop, op);
}
void int_set_d(void * rop, double op) {
	mpz_set_d((mpz_ptr)rop, op);
}
void int_set_q(void * rop, void * op) {
	mpz_set_q((mpz_ptr)rop, (mpq_srcptr)op);
}
void int_set_float(void * rop, void * op) {
	mpz_set_f((mpz_ptr)rop, (mpf_srcptr)op);
}

int int_set_str(void * dst, const char *str, int base) {
// This function returns 0 if the entire string is a valid number in base base. Otherwise it returns -1.
	return mpz_set_str((mpz_ptr)dst, str, base);
}

unsigned long int int_get_ui(void * op) {
	return mpz_get_ui((mpz_ptr)op);
}
signed long int int_get_si(void * op) {
	return mpz_get_si((mpz_ptr)op);
}
double int_get_d(void * op) {
	return mpz_get_d((mpz_ptr)op);
}
double int_get_d_2exp(signed long int *exp, void * op) {
	return mpz_get_d_2exp(exp, (mpz_ptr)op);
}

char * int_get_str(char *str, int base, void * src) {
	return mpz_get_str(str, base, (mpz_srcptr)src);
}

/*
void mpz_init (mpz t x) Initialize x, and set its value to 0.
void mpz_inits (mpz t x, ...) Initialize a NULL-terminated list of mpz_t variables, and set their values to 0.
void mpz_init2 (mpz t x, mp_bitcnt_t n) Initialize x, with space for n-bit numbers, and set its value to 0. Calling this function instead of mpz_init or mpz_inits is never necessary; reallocation is handled automatically by GMP when needed.
While n defines the initial space, x will grow automatically in the normal way, if necessary, for subsequent values stored. mpz_init2 makes it possible to avoid such reallocations if a maximum size is known in advance.
In preparation for an operation, GMP often allocates one limb more than ultimately needed. To make sure GMP will not perform reallocation for x, you need to add the number of bits in mp_limb_t to n.
void mpz_clear (mpz t x) Free the space occupied by x. Call this function for all mpz_t variables when you are done with them.
void mpz_clears (mpz t x, ...) Free the space occupied by a NULL-terminated list of mpz_t variables.
void mpz_realloc2 (mpz t x, mp_bitcnt_t n) Change the space allocated for x to n bits. The value in x is preserved if it fits, or is set to 0 if not.
Calling this function is never necessary; reallocation is handled automatically by GMP when needed. But this function can be used to increase the space for a variable in order to avoid repeated automatic reallocations, or to decrease it to give memory back to the heap.
*/

/*
void mpz_set (mpz t rop, const mpz t op)
void mpz_set_ui (mpz t rop, unsigned long int op)
void mpz_set_si (mpz t rop, signed long int op)
void mpz_set_d (mpz t rop, double op)
void mpz_set_q (mpz t rop, const mpq t op)
void mpz_set_f (mpz t rop, const mpf t op)
*/

void int_add(void * dst, void * op1, void * op2) {
	mpz_add((mpz_ptr)dst, (mpz_srcptr)op1, (mpz_srcptr)op2);
}
void int_add_ui(void * dst, void * op1, unsigned long int op2) {
	mpz_add_ui((mpz_ptr)dst, (mpz_srcptr)op1, op2);
}
void int_sub(void * dst, void * op1, void * op2) {
	mpz_sub((mpz_ptr)dst, (mpz_srcptr)op1, (mpz_srcptr)op2);
}
void int_sub_ui(void * dst, void * op1, unsigned long int op2) {
	mpz_sub_ui((mpz_ptr)dst, (mpz_srcptr)op1, op2);
}
void int_ui_sub(void * dst, unsigned long int op1, void * op2) {
	mpz_ui_sub((mpz_ptr)dst, op1, (mpz_srcptr)op2);
}
void int_mul(void * dst, void * op1, void * op2) {
	mpz_mul((mpz_ptr)dst, (mpz_srcptr)op1, (mpz_srcptr)op2);
}
void int_mul_si(void * dst, void * op1, long int op2) {
	mpz_mul_si((mpz_ptr)dst, (mpz_srcptr)op1, op2);
}
void int_mul_ui(void * dst, void * op1, unsigned long int op2) {
	mpz_mul_ui((mpz_ptr)dst, (mpz_srcptr)op1, op2);
}
void int_addmul(void * dst, void * op1, void * op2) {
	mpz_addmul((mpz_ptr)dst, (mpz_srcptr)op1, (mpz_srcptr)op2);
}
void int_addmul_ui(void * dst, void * op1, unsigned long int op2) {
	mpz_addmul_ui((mpz_ptr)dst, (mpz_srcptr)op1, op2);
}
void int_submul(void * dst, void * op1, void * op2) {
	mpz_submul((mpz_ptr)dst, (mpz_srcptr)op1, (mpz_srcptr)op2);
}
void int_submul_ui(void * dst, void * op1, unsigned long int op2) {
	mpz_submul_ui((mpz_ptr)dst, (mpz_srcptr)op1, op2);
}
void int_mul_2exp(void * dst, void * op1, unsigned long int op2) {
	mpz_mul_2exp((mpz_ptr)dst, (mpz_srcptr)op1, (mp_bitcnt_t)op2);
}
void int_neg(void * dst, void * op1) {
	mpz_neg((mpz_ptr)dst, (mpz_srcptr)op1);
}
void int_abs(void * dst, void * op1) {
	mpz_abs((mpz_ptr)dst, (mpz_srcptr)op1);
}

/*
void mpz_add (mpz t rop, const mpz t op1, const mpz t op2) 
void mpz_sub (mpz t rop, const mpz t op1, const mpz t op2) 
void mpz_mul (mpz t rop, const mpz t op1, const mpz t op2) 
void mpz_addmul (mpz t rop, const mpz t op1, const mpz t op2) 
void mpz_submul (mpz t rop, const mpz t op1, const mpz t op2) 
void mpz_neg (mpz t rop, const mpz t op) Set rop to -op.
void mpz_abs (mpz t rop, const mpz t op) Set rop to the absolute value of op.
*/

void int_cdiv_q(void * dst, void * op1, void * op2) {
	mpz_cdiv_q((mpz_ptr)dst, (mpz_srcptr)op1, (mpz_srcptr)op2);
}
void int_cdiv_r(void * dst, void * op1, void * op2) {
	mpz_cdiv_r((mpz_ptr)dst, (mpz_srcptr)op1, (mpz_srcptr)op2);
}
void int_cdiv_qr(void * dstq, void * dstr, void * op1, void * op2) {
	mpz_cdiv_qr((mpz_ptr)dstq, (mpz_ptr)dstr, (mpz_srcptr)op1, (mpz_srcptr)op2);
}
unsigned long int int_cdiv_q_ui(void * dstq, void * n, unsigned long int d) {
	return mpz_cdiv_q_ui((mpz_ptr)dstq, (mpz_srcptr)n, d);
}
unsigned long int int_cdiv_r_ui(void * dstr, void * n, unsigned long int d) {
	return mpz_cdiv_r_ui((mpz_ptr)dstr, (mpz_srcptr)n, d);
}
unsigned long int int_cdiv_qr_ui(void * dstq, void * dstr, void * n, unsigned long int d) {
	return mpz_cdiv_qr_ui((mpz_ptr)dstq, (mpz_ptr)dstr, (mpz_srcptr)n, d);
}
unsigned long int int_cdiv_ui (void * n, unsigned long int d) {
	return mpz_cdiv_ui((mpz_srcptr)n, d);
}
void int_cdiv_q_2exp(void * dstq, void * n, unsigned long b) {
	mpz_cdiv_q_2exp((mpz_ptr)dstq, (mpz_srcptr)n, (mp_bitcnt_t)b);
}
void int_cdiv_r_2exp(void * dstr, void * n, unsigned long b) {
	mpz_cdiv_r_2exp((mpz_ptr)dstr, (mpz_srcptr)n, (mp_bitcnt_t)b);
}
void int_fdiv_q(void * dstq, void * op1, void * op2) {
	mpz_fdiv_q((mpz_ptr)dstq, (mpz_srcptr)op1, (mpz_srcptr)op2);
}
void int_fdiv_r(void * dstr, void * op1, void * op2) {
	mpz_fdiv_r((mpz_ptr)dstr, (mpz_srcptr)op1, (mpz_srcptr)op2);
}
void int_fdiv_qr(void * dstq, void * dstr, void * n, void * d) {
	mpz_fdiv_qr((mpz_ptr)dstq, (mpz_ptr)dstr, (mpz_srcptr)n, (mpz_srcptr)d);
}
unsigned long int int_fdiv_q_ui(void * dstq, void * n, unsigned long int d) {
	return mpz_fdiv_q_ui((mpz_ptr)dstq, (mpz_srcptr)n, d);
}
unsigned long int int_fdiv_r_ui(void * dstr, void * n, unsigned long int d) {
	return mpz_fdiv_r_ui((mpz_ptr)dstr, (mpz_srcptr)n, d);
}
unsigned long int int_fdiv_qr_ui(void * dstq, void * dstr, void * n, unsigned long int d) {
	return mpz_fdiv_qr_ui((mpz_ptr)dstq, (mpz_ptr)dstr, (mpz_srcptr)n, d);
}
unsigned long int int_fdiv_ui(void * n, unsigned long int d) {
	return mpz_fdiv_ui((mpz_srcptr)n, d);
}
void int_fdiv_q_2exp(void * dstq, void * n, unsigned long b) {
	mpz_fdiv_q_2exp((mpz_ptr)dstq, (mpz_srcptr)n, (mp_bitcnt_t)b);
}
void int_fdiv_r_2exp(void * dstr, void * n, unsigned long b) {
	mpz_fdiv_r_2exp((mpz_ptr)dstr, (mpz_srcptr)n, (mp_bitcnt_t)b);
}
void int_tdiv_q(void * dstq, void * op1, void * op2) {
	mpz_tdiv_q((mpz_ptr)dstq, (mpz_srcptr)op1, (mpz_srcptr)op2);
}
void int_tdiv_r(void * dstr, void * op1, void * op2) {
	mpz_tdiv_r((mpz_ptr)dstr, (mpz_srcptr)op1, (mpz_srcptr)op2);
}
void int_tdiv_qr(void * dstq, void * dstr, void * n, void * d) {
	mpz_tdiv_qr((mpz_ptr)dstq, (mpz_ptr)dstr, (mpz_srcptr)n, (mpz_srcptr)d);
}
unsigned long int int_tdiv_q_ui(void * dstq, void * n, unsigned long int d) {
	return mpz_tdiv_q_ui((mpz_ptr)dstq, (mpz_srcptr)n, d);
}
unsigned long int int_tdiv_r_ui(void * dstr, void * n, unsigned long int d) {
	return mpz_tdiv_r_ui((mpz_ptr)dstr, (mpz_srcptr)n, d);
}
unsigned long int int_tdiv_qr_ui(void * dstq, void * dstr, void * n, unsigned long int d) {
	return mpz_tdiv_qr_ui((mpz_ptr)dstq, (mpz_ptr)dstr, (mpz_srcptr)n, d);
}
unsigned long int int_tdiv_ui(void * n, unsigned long int d) {
	return mpz_tdiv_ui((mpz_srcptr)n, d);
}
void int_tdiv_q_2exp(void * dstq, void * n, unsigned long b) {
	mpz_tdiv_q_2exp((mpz_ptr)dstq, (mpz_srcptr)n, (mp_bitcnt_t)b);
}
void int_tdiv_r_2exp(void * dstr, void * n, unsigned long b) {
	mpz_tdiv_r_2exp((mpz_ptr)dstr, (mpz_srcptr)n, (mp_bitcnt_t)b);
}
void int_mod(void * r, void * n, void * d) {
	mpz_mod((mpz_ptr)r, (mpz_srcptr)n, (mpz_srcptr)d);
}
unsigned long int int_mod_ui(void * dstr, void * n, unsigned long int d) {
	return mpz_mod_ui((mpz_ptr)dstr, (mpz_srcptr)n, d);
}
void int_divexact(void * dstq, void * n, void * d) {
	mpz_divexact((mpz_ptr)dstq, (mpz_srcptr)n, (mpz_srcptr)d);
}
void int_divexact_ui(void * dstq, void * n, unsigned long d) {
	mpz_divexact_ui((mpz_ptr)dstq, (mpz_srcptr)n, d);
}
int int_divisible_p(void * n, void * d) {
	return mpz_divisible_p((mpz_srcptr)n, (mpz_srcptr)d);
}
int int_divisible_ui_p(void * n, unsigned long int d) {
	return mpz_divisible_ui_p((mpz_srcptr)n, d);
}
int int_divisible_2exp_p(void * n, unsigned long b) {
	return mpz_divisible_2exp_p((mpz_srcptr)n, (mp_bitcnt_t)b);
}
int int_congruent_p(void * n, void * c, void * d) {
	return mpz_congruent_p((mpz_srcptr)n, (mpz_srcptr)c, (mpz_srcptr)d);
}
int int_congruent_ui_p(void * n, unsigned long int c, unsigned long int d) {
	return mpz_congruent_ui_p((mpz_srcptr)n, c, d);
}
int int_congruent_2exp_p(void * n, void * c, unsigned long b) {
	return mpz_congruent_2exp_p((mpz_srcptr)n, (mpz_srcptr)c, (mp_bitcnt_t)b);
}
/*
void mpz_cdiv_q (mpz t q, const mpz t n, const mpz t d)
void mpz_cdiv_r (mpz t r, const mpz t n, const mpz t d)
void mpz_cdiv_qr (mpz t q, mpz t r, const mpz t n, const mpz t d)
unsigned long int mpz_cdiv_q_ui (mpz t q, const mpz t n, unsigned long int d)
unsigned long int mpz_cdiv_r_ui (mpz t r, const mpz t n, unsigned long int d)
unsigned long int mpz_cdiv_qr_ui (mpz t q, mpz t r, const mpz t n, unsigned long int d)
unsigned long int mpz_cdiv_ui (const mpz t n, unsigned long int d)
void mpz_cdiv_q_2exp (mpz t q, const mpz t n, mp_bitcnt_t b)
void mpz_cdiv_r_2exp (mpz t r, const mpz t n, mp_bitcnt_t b)
void mpz_fdiv_q (mpz t q, const mpz t n, const mpz t d)
void mpz_fdiv_r (mpz t r, const mpz t n, const mpz t d)
void mpz_fdiv_qr (mpz t q, mpz t r, const mpz t n, const mpz t d)
unsigned long int mpz_fdiv_q_ui (mpz t q, const mpz t n, unsigned long int d)
unsigned long int mpz_fdiv_r_ui (mpz t r, const mpz t n, unsigned long int d)
unsigned long int mpz_fdiv_qr_ui (mpz t q, mpz t r, const mpz t n, unsigned long int d)
unsigned long int mpz_fdiv_ui (const mpz t n, unsigned long int d)
void mpz_fdiv_q_2exp (mpz t q, const mpz t n, mp_bitcnt_t b)
void mpz_fdiv_r_2exp (mpz t r, const mpz t n, mp_bitcnt_t b)
void mpz_tdiv_q (mpz t q, const mpz t n, const mpz t d)
void mpz_tdiv_r (mpz t r, const mpz t n, const mpz t d)
void mpz_tdiv_qr (mpz t q, mpz t r, const mpz t n, const mpz t d)
unsigned long int mpz_tdiv_q_ui (mpz t q, const mpz t n, unsigned long int d)
unsigned long int mpz_tdiv_r_ui (mpz t r, const mpz t n, unsigned long int d)
unsigned long int mpz_tdiv_qr_ui (mpz t q, mpz t r, const mpz t n, unsigned long int d)
unsigned long int mpz_tdiv_ui (const mpz t n, unsigned long int d)
void mpz_tdiv_q_2exp (mpz t q, const mpz t n, mp_bitcnt_t b)
void mpz_tdiv_r_2exp (mpz t r, const mpz t n, mp_bitcnt_t b)
void mpz_mod (mpz t r, const mpz t n, const mpz t d)
unsigned long int mpz_mod_ui (mpz t r, const mpz t n, unsigned long int d)
void mpz_divexact (mpz t q, const mpz t n, const mpz t d)
void mpz_divexact_ui (mpz t q, const mpz t n, unsigned long d)
int mpz_divisible_p (const mpz t n, const mpz t d)
int mpz_divisible_ui_p (const mpz t n, unsigned long int d)
int mpz_divisible_2exp_p (const mpz t n, mp_bitcnt_t b)
int mpz_congruent_p (const mpz t n, const mpz t c, const mpz t d)
int mpz_congruent_ui_p (const mpz t n, unsigned long int c, unsigned long int d)
int mpz_congruent_2exp_p (const mpz t n, const mpz t c, mp_bitcnt_t b)
*/

void int_powm(void * dst, void * base, void * exp, void * mod) {
	mpz_powm((mpz_ptr)dst, (mpz_srcptr)base, (mpz_srcptr)exp, (mpz_srcptr)mod);
}
void int_powm_ui(void * dst, void * base, unsigned long int exp, void * mod) {
	mpz_powm_ui((mpz_ptr)dst, (mpz_srcptr)base, exp, (mpz_srcptr)mod);
}
void int_powm_sec(void * dst, void * base, void * exp, void * mod) {
// It is required that exp > 0 and that mod is odd.
// This function is designed to take the same time and have the same cache access patterns for any two same-size arguments, assuming that function arguments are placed at the same position and that the machine state is identical upon function entry. This function is intended for cryptographic purposes, where resilience to side-channel attacks is desired.
	mpz_powm_sec((mpz_ptr)dst, (mpz_srcptr)base, (mpz_srcptr)exp, (mpz_srcptr)mod);
}
void int_pow_ui(void * dst, void * base, unsigned long int exp) {
	mpz_pow_ui((mpz_ptr)dst, (mpz_srcptr)base, exp);
}
void int_ui_pow_ui(void * dst, unsigned long int base, unsigned long int exp) {
	mpz_ui_pow_ui((mpz_ptr)dst, base, exp);
}
/*
void mpz_powm (mpz t rop, const mpz t base, const mpz t exp, const mpz t mod)
void mpz_powm_ui (mpz t rop, const mpz t base, unsigned long int exp, const mpz t mod)
void mpz_powm_sec (mpz t rop, const mpz t base, const mpz t exp, const mpz t mod)
void mpz_pow_ui (mpz t rop, const mpz t base, unsigned long int exp)
void mpz_ui_pow_ui (mpz t rop, unsigned long int base, unsigned long int exp)
*/

int int_root(void * dst, void * op, unsigned long int n) {
	return mpz_root((mpz_ptr)dst, (mpz_srcptr)op, n);
}
void int_rootrem(void * root, void * rem, void * u, unsigned long int n) {
	mpz_rootrem((mpz_ptr)root, (mpz_ptr)rem, (mpz_srcptr)u, n);
}
void int_sqrt(void * dst, void * op) {
	mpz_sqrt((mpz_ptr)dst, (mpz_srcptr)op);
}
void int_sqrtrem(void * rop1, void * rop2, void * op) {
	mpz_sqrtrem((mpz_ptr)rop1, (mpz_ptr)rop2, (mpz_srcptr)op);
}
int int_perfect_power_p(void * op) {
	return mpz_perfect_power_p((mpz_srcptr)op);
}
int int_perfect_square_p(void * op) {
	return mpz_perfect_square_p((mpz_ptr)op);
}

/*
int mpz_root (mpz t rop, const mpz t op, unsigned long int n) Set rop to b n vopc, the truncated integer part of the nth root of op. Return non-zero if the computation was exact, i.e., if op is rop to the nth power.
void mpz_rootrem (mpz t root, mpz t rem, const mpz t u, unsigned long int n) Set root to b n vuc, the truncated integer part of the nth root of u. Set rem to the remainder,( u-rootn).
void mpz_sqrt (mpz t rop, const mpz t op) Set rop to bvopc, the truncated integer part of the square root of op.
void mpz_sqrtrem (mpz t rop1, mpz t rop2, const mpz t op) Set rop1 to bvopc, like mpz_sqrt. Set rop2 to the remainder (op -rop12), which will be zero if op is a perfect square.
If rop1 and rop2 are the same variable, the results are undefined.
int mpz_perfect_power_p (const mpz t op) Return non-zero if op is a perfect power, i.e., if there exist integers a and b, with b > 1, such that op = ab.
Under this definition both 0 and 1 are considered to be perfect powers. Negative values of op are accepted, but of course can only be odd perfect powers.
int mpz_perfect_square_p (const mpz t op) Return non-zero if op is a perfect square, i.e., if the square root of op is an integer. Under this definition both 0 and 1 are considered to be perfect squares.
*/

// Number Theoretic Functions

int int_probab_prime_p(void * n, int reps) {
	return mpz_probab_prime_p((mpz_srcptr)n, reps);
}
void int_nextprime(void * rop, void * op) {
	return mpz_nextprime((mpz_ptr)rop, (mpz_srcptr)op);
}
void int_gcd(void * rop, void * op1, void * op2) {
	return mpz_gcd((mpz_ptr)rop, (mpz_srcptr)op1, (mpz_srcptr)op2);
}
unsigned long int int_gcd_ui(void * rop, void * op1, unsigned long int op2) {
	return mpz_gcd_ui((mpz_ptr)rop, (mpz_srcptr)op1, op2);
}
void int_gcdext(void * g, void * s, void * t, void * a, void * b) {
	return mpz_gcdext((mpz_ptr)g, (mpz_ptr)s, (mpz_ptr)t, (mpz_srcptr)a, (mpz_srcptr)b);
}
void int_lcm(void * rop, void * op1, void * op2) {
	return mpz_lcm((mpz_ptr)rop, (mpz_srcptr)op1, (mpz_srcptr)op2);
}
void int_lcm_ui(void * rop, void * op1, unsigned long op2) {
	return mpz_lcm_ui((mpz_ptr)rop, (mpz_srcptr)op1, op2);
}
int int_invert(void * rop, void * op1, void * op2) {
	return mpz_invert((mpz_ptr)rop, (mpz_srcptr)op1, (mpz_srcptr)op2);
}
int int_jacobi(void * a, void * b) {
	return mpz_jacobi((mpz_srcptr)a, (mpz_srcptr)b);
}
int int_legendre(void * a, void * p) {
	return mpz_legendre((mpz_srcptr)a, (mpz_srcptr)p);
}
int int_kronecker(void * a, void * b) {
	return mpz_kronecker((mpz_srcptr)a, (mpz_srcptr)b);
}
int int_kronecker_si(void * a, long b) {
	return mpz_kronecker_si((mpz_srcptr)a, b);
}
int int_kronecker_ui(void * a, unsigned long b) {
	return mpz_kronecker_ui((mpz_srcptr)a, b);
}
int int_si_kronecker(long a, void * b) {
	return mpz_si_kronecker(a, (mpz_srcptr)b);
}
int int_ui_kronecker(unsigned long a, void * b) {
	return mpz_ui_kronecker(a, (mpz_srcptr)b);
}
unsigned long int_remove(void * rop, void * op, void * f) {
	return (unsigned long)mpz_remove((mpz_ptr)rop, (mpz_srcptr)op, (mpz_srcptr)f);
}
void int_fac_ui(void * rop, unsigned long int n) {
	return mpz_fac_ui((mpz_ptr)rop, n);
}
void int_2fac_ui(void * rop, unsigned long int n) {
	return mpz_2fac_ui((mpz_ptr)rop, n);
}
void int_mfac_uiui(void * rop, unsigned long int n, unsigned long int m) {
	return mpz_mfac_uiui((mpz_ptr)rop, n, m);
}
void int_primorial_ui(void * rop, unsigned long int n) {
	return mpz_primorial_ui((mpz_ptr)rop, n);
}
void int_bin_ui(void * rop, void * n, unsigned long int k) {
	return mpz_bin_ui((mpz_ptr)rop, (mpz_srcptr)n, k);
}
void int_bin_uiui(void * rop, unsigned long int n, unsigned long int k) {
	return mpz_bin_uiui((mpz_ptr)rop, n, k);
}
void int_fib_ui(void * fn, unsigned long int n) {
	return mpz_fib_ui((mpz_ptr)fn, n);
}
void int_fib2_ui(void * fn, void * fnsub1, unsigned long int n) {
	return mpz_fib2_ui((mpz_ptr)fn, (mpz_ptr)fnsub1, n);
}
void int_lucnum_ui(void * ln, unsigned long int n) {
	return mpz_lucnum_ui((mpz_ptr)ln, n);
}
void int_lucnum2_ui(void * ln, void * lnsub1, unsigned long int n) {
	return mpz_lucnum2_ui((mpz_ptr)ln, (mpz_ptr)lnsub1, n);
}

int int_cmp(void * op1, void * op2) {
	return mpz_cmp((mpz_srcptr)op1, (mpz_srcptr)op2);
}
int int_cmp_d(void * op1, double op2) {
	return mpz_cmp_d((mpz_srcptr)op1, op2);
}
int int_cmp_si(void * op1, signed long int op2) {
	return mpz_cmp_si((mpz_srcptr)op1, op2);
}
int int_cmp_ui(void * op1, unsigned long int op2) {
	return mpz_cmp_ui((mpz_srcptr)op1, op2);
}
int int_cmpabs(void * op1, void * op2) {
	return mpz_cmpabs((mpz_srcptr)op1, (mpz_srcptr)op2);
}
int int_cmpabs_d(void * op1, double op2) {
	return mpz_cmpabs_d((mpz_srcptr)op1, op2);
}
int int_cmpabs_ui(void * op1, unsigned long int op2) {
	return mpz_cmpabs_ui((mpz_srcptr)op1, op2);
}
int int_sgn(void * op) {
	return mpz_sgn((mpz_srcptr)op);
}
void int_and(void * rop, void * op1, void * op2) {
	mpz_and((mpz_ptr)rop, (mpz_srcptr)op1, (mpz_srcptr)op2);
}
void int_ior(void * rop, void * op1, void * op2) {
	mpz_ior((mpz_ptr)rop, (mpz_srcptr)op1, (mpz_srcptr)op2);
}
void int_xor(void * rop, void * op1, void * op2) {
	mpz_xor((mpz_ptr)rop, (mpz_srcptr)op1, (mpz_srcptr)op2);
}
void int_com(void * rop, void * op) {
	mpz_com((mpz_ptr)rop, (mpz_srcptr)op);
}
unsigned long int_popcount(void * op) {
	return (unsigned long)mpz_popcount((mpz_srcptr)op);
}
unsigned long int_hamdist(void * op1, void * op2) {
	return (unsigned long)mpz_hamdist((mpz_srcptr)op1, (mpz_srcptr)op2);
}
unsigned long int_scan0(void * op, unsigned long starting_bit) {
	return (unsigned long)mpz_scan0((mpz_srcptr)op, (mp_bitcnt_t)starting_bit);
}
unsigned long int_scan1(void * op, unsigned long starting_bit) {
	return (unsigned long)mpz_scan1((mpz_srcptr)op, (mp_bitcnt_t)starting_bit);
}
void int_setbit(void * rop, unsigned long bit_index) {
	mpz_setbit((mpz_ptr)rop, (mp_bitcnt_t)bit_index);
}
void int_clrbit(void * rop, unsigned long bit_index) {
	mpz_clrbit((mpz_ptr)rop, (mp_bitcnt_t)bit_index);
}
void int_combit(void * rop, unsigned long bit_index) {
	mpz_combit((mpz_ptr)rop, (mp_bitcnt_t)bit_index);
}
int int_tstbit(void * op, unsigned long bit_index) {
	return mpz_tstbit((mpz_srcptr)op, (mp_bitcnt_t)bit_index);
}
// size_t mpz_out_str (FILE *stream, int base, const mpz t op)
size_t int_out_str_filename(const char * filename, int base, void * op) {
	FILE * pFile;
	if (filename == NULL)
	{
		return mpz_out_str(NULL, base, (mpz_srcptr)op);
	}
	pFile = fopen(filename,"w");
	if (pFile != NULL)
	{
		size_t ret = mpz_out_str(pFile, base, (mpz_srcptr)op);
		fclose (pFile);
		return ret;
	}
	return 0;
}
// size_t mpz_inp_str (mpz t rop, FILE *stream, int base)
size_t int_inp_str_filename(void * rop, const char * filename, int base) {
	FILE * pFile;
	if (filename == NULL)
	{
		return mpz_inp_str((mpz_ptr)rop, NULL, base);
	}
	pFile = fopen(filename,"r");
	if (pFile != NULL)
	{
		size_t ret = mpz_inp_str((mpz_ptr)rop, pFile, base);
		fclose (pFile);
		return ret;
	}
	return 0;
}
// size_t mpz_out_raw (FILE *stream, const mpz t op)
size_t int_out_raw_filename(const char * filename, void * op) {
	FILE * pFile;
	if (filename == NULL)
	{
		return mpz_out_raw(NULL, (mpz_srcptr)op);
	}
	pFile = fopen(filename,"wb");
	if (pFile != NULL)
	{
		size_t ret = mpz_out_raw(pFile, (mpz_srcptr)op);
		fclose (pFile);
		return ret;
	}
	return 0;
}
// size_t mpz_inp_raw (mpz t rop, FILE *stream)
size_t int_inp_raw_filename(void * rop, const char * filename) {
	FILE * pFile;
	if (filename == NULL)
	{
		return mpz_inp_raw((mpz_ptr)rop, NULL);
	}
	pFile = fopen(filename,"rb");
	if (pFile != NULL)
	{
		size_t ret = mpz_inp_raw((mpz_ptr)rop, pFile);
		fclose (pFile);
		return ret;
	}
	return 0;
}

void int_import(void * rop, size_t count, int order, size_t size, int endian, size_t nails, const void *op) {
	mpz_import((mpz_ptr)rop, count, order, size, endian, nails, op);
}
void * int_export(void * rop, size_t * countp, int order, size_t size, int endian, size_t nails, const void * op) {
	return mpz_export(rop, countp, order, size, endian, nails, (mpz_srcptr)op);
}

// Random number functions:

void int_urandomb(void * rop, void * state, unsigned long n) {
	mpz_urandomb((mpz_ptr)rop, (__gmp_randstate_struct*) state, (mp_bitcnt_t)n);
}
void int_urandomm(void * rop, void * state, void * n) {
	mpz_urandomm((mpz_ptr)rop, (__gmp_randstate_struct*) state, (mpz_srcptr)n);
}
void int_rrandomb(void * rop, void * state, unsigned long n) {
	mpz_rrandomb((mpz_ptr)rop, (__gmp_randstate_struct*) state, (mp_bitcnt_t)n);
}
void int_random(void * rop, long max_size) {
	mpz_random((mpz_ptr)rop, (mp_size_t)max_size);
}
void int_random2(void * rop, long max_size) {
	mpz_random2((mpz_ptr)rop, (mp_size_t)max_size);
}

// 9.1 Random State Initialization

size_t sizeof_randstate() {
	return sizeof(__gmp_randstate_struct);
}

void int_randinit_default(void * state) {
	gmp_randinit_default((__gmp_randstate_struct*) state);
}
void int_randinit_mt(void * state) {
	gmp_randinit_mt((__gmp_randstate_struct*) state);
}
void int_randinit_lc_2exp(void * state, void * a, unsigned long c, unsigned long m2exp) {
	gmp_randinit_lc_2exp((__gmp_randstate_struct*) state, (mpz_srcptr)a, c, (mp_bitcnt_t)m2exp);
}
int int_randinit_lc_2exp_size(void * state, unsigned long size) {
	return gmp_randinit_lc_2exp_size((__gmp_randstate_struct*) state, (mp_bitcnt_t)size);
}
void int_randinit_set(void * rop, void * op) {
	gmp_randinit_set((__gmp_randstate_struct*) rop, (__gmp_randstate_struct*) op);
}
//void gmp_randinit (gmp randstate t state, gmp randalg t alg, . . .);
void int_randclear(void * state) {
	gmp_randclear((__gmp_randstate_struct*) state);
}

// 9.2 Random State Seeding
void int_randseed(void * state, void * seed) {
	gmp_randseed((__gmp_randstate_struct*) state, (mpz_srcptr)seed);
}
void int_randseed_ui(void * state, unsigned long int seed) {
	gmp_randseed_ui((__gmp_randstate_struct*) state, seed);
}

// 9.3 Random State Miscellaneous
unsigned long int_urandomb_ui(void * state, unsigned long n) {
	return gmp_urandomb_ui ((__gmp_randstate_struct*) state, n);
}
unsigned long int_urandomm_ui(void * state, unsigned long n) {
	return gmp_urandomm_ui ((__gmp_randstate_struct*) state, n);
}

/*
9.1 Random State Initialization
void gmp_randinit_default (gmp randstate t state) [Function]
Initialize state with a default algorithm. This will be a compromise between speed and
randomness, and is recommended for applications with no special requirements. Currently
this is gmp_randinit_mt.
void gmp_randinit_mt (gmp randstate t state) [Function]
Initialize state for a Mersenne Twister algorithm. This algorithm is fast and has good randomness properties.
void gmp_randinit_lc_2exp (gmp randstate t state, const mpz t a, [Function]
unsigned long c, mp bitcnt t m2exp)
Initialize state with a linear congruential algorithm X = (aX + c) mod 2m2exp
.
The low bits of X in this algorithm are not very random. The least significant bit will have
a period no more than 2, and the second bit no more than 4, etc. For this reason only the
high half of each X is actually used.
When a random number of more than m2exp/2 bits is to be generated, multiple iterations
of the recurrence are used and the results concatenated.
int gmp_randinit_lc_2exp_size (gmp randstate t state, mp bitcnt t [Function]
size)
Initialize state for a linear congruential algorithm as per gmp_randinit_lc_2exp. a, c and
m2exp are selected from a table, chosen so that size bits (or more) of each X will be used,
i.e. m2exp/2 ≥ size.
If successful the return value is non-zero. If size is bigger than the table data provides then
the return value is zero. The maximum size currently supported is 128.
void gmp_randinit_set (gmp randstate t rop, gmp randstate t op) [Function]
Initialize rop with a copy of the algorithm and state from op.
void gmp_randinit (gmp randstate t state, gmp randalg t alg, . . .) [Function]
This function is obsolete.
Initialize state with an algorithm selected by alg. The only choice is GMP_RAND_ALG_LC, which
is gmp_randinit_lc_2exp_size described above. A third parameter of type unsigned long
Chapter 9: Random Number Functions 71
is required, this is the size for that function. GMP_RAND_ALG_DEFAULT or 0 are the same as
GMP_RAND_ALG_LC.
gmp_randinit sets bits in the global variable gmp_errno to indicate an error. GMP_ERROR_
UNSUPPORTED_ARGUMENT if alg is unsupported, or GMP_ERROR_INVALID_ARGUMENT if the size
parameter is too big. It may be noted this error reporting is not thread safe (a good reason
to use gmp_randinit_lc_2exp_size instead).
void gmp_randclear (gmp randstate t state) [Function]
Free all memory occupied by state.
9.2 Random State Seeding
void gmp_randseed (gmp randstate t state, const mpz t seed) [Function]
void gmp_randseed_ui (gmp randstate t state, unsigned long int seed) [Function]
Set an initial seed value into state.
The size of a seed determines how many different sequences of random numbers that it’s
possible to generate. The “quality” of the seed is the randomness of a given seed compared
to the previous seed used, and this affects the randomness of separate number sequences. The
method for choosing a seed is critical if the generated numbers are to be used for important
applications, such as generating cryptographic keys.
Traditionally the system time has been used to seed, but care needs to be taken with this.
If an application seeds often and the resolution of the system clock is low, then the same
sequence of numbers might be repeated. Also, the system time is quite easy to guess, so if
unpredictability is required then it should definitely not be the only source for the seed value.
On some systems there’s a special device /dev/random which provides random data better
suited for use as a seed.
9.3 Random State Miscellaneous
unsigned long gmp_urandomb_ui (gmp randstate t state, unsigned long [Function]
n)
Return a uniformly distributed random number of n bits, i.e. in the range 0 to 2n−1 inclusive.
n must be less than or equal to the number of bits in an unsigned long.
unsigned long gmp_urandomm_ui (gmp randstate t state, unsigned long [Function]
n)
Return a uniformly distributed random number in the range 0 to n − 1, inclusive.
*/

int int_fits_ulong_p(void * op) {
	return mpz_fits_ulong_p((mpz_srcptr)op);
}
int int_fits_slong_p(void * op) {
	return mpz_fits_slong_p((mpz_srcptr)op);
}
int int_fits_uint_p(void * op) {
	return mpz_fits_uint_p((mpz_srcptr)op);
}
int int_fits_sint_p(void * op) {
	return mpz_fits_sint_p((mpz_srcptr)op);
}
int int_fits_ushort_p(void * op) {
	return mpz_fits_ushort_p((mpz_srcptr)op);
}
int int_fits_sshort_p(void * op) {
	return mpz_fits_sshort_p((mpz_srcptr)op);
}
int int_odd_p(void * op) {
	return mpz_odd_p((mpz_srcptr)op);
}
int int_even_p(void * op) {
	return mpz_even_p((mpz_srcptr)op);
}
size_t int_sizeinbase(void * op, int base) {
	return mpz_sizeinbase((mpz_srcptr)op, base);
}


// END INT FUNCTIONS.

// BEGIN RATIONAL NUMBER FUNCTIONS:

/*
6 Rational Number Functions
This chapter describes the GMP functions for performing arithmetic on rational numbers. These functions start with the prefix mpq_.
Rational numbers are stored in objects of type mpq_t.
All rational arithmetic functions assume operands have a canonical form, and canonicalize their result. The canonical form means that the denominator and the numerator have no common factors, and that the denominator is positive. Zero has the unique representation 0/1.
Pure assignment functions do not canonicalize the assigned variable. It is the responsibility of the user to canonicalize the assigned variable before any arithmetic operations are performed on that variable.
void mpq_canonicalize (mpq t op) Remove any factors that are common to the numerator and denominator of op, and make the denominator positive.
*/

void * allocate_q() {
	return malloc(sizeof(mpq_t));
}
void register_q(void * p) {
	mpq_init((mpq_ptr)p);
}
void clear_q(void * p) {
	mpq_clear((mpq_ptr)p);
}

void q_set(void * dst, void * src) {
	mpq_set((mpq_ptr)dst, (mpq_srcptr)src);
}
int q_set_str(void * dst, const char *str, int base) {
// This function returns 0 if the entire string is a valid number in base base. Otherwise it returns -1.
	return mpq_set_str((mpq_ptr)dst, str, base);
}

char * q_get_str(char *str, int base, void * src) {
	return mpq_get_str(str, base, (mpq_srcptr)src);
}

void q_swap(void * rop1, void * rop2) {
	// Swap the values rop1 and rop2 efficiently.
	mpq_swap((mpq_ptr)rop1, (mpq_ptr)rop2);
}

/*
6.1 Initialization and Assignment Functions
void mpq_init (mpq t x) Initialize x and set it to 0/1. Each variable should normally only be initialized once, or at least cleared out (using the function mpq_clear) between each initialization.
void mpq_inits (mpq t x, ...) Initialize a NULL-terminated list of mpq_t variables, and set their values to 0/1.
void mpq_clear (mpq t x) Free the space occupied by x. Make sure to call this function for all mpq_t variables when you are done with them.
void mpq_clears (mpq t x, ...) Free the space occupied by a NULL-terminated list of mpq_t variables.
void mpq_set (mpq t rop, const mpq t op) 
void mpq_set_z (mpq t rop, const mpz t op) Assign rop from op.
void mpq_set_ui (mpq t rop, unsigned long int op1, unsigned long int op2) 
void mpq_set_si (mpq t rop, signed long int op1, unsigned long int op2) Set the value of rop to op1/op2. Note that if op1 and op2 have common factors, rop has to be passed to mpq_canonicalize before any operations are performed on rop.
int mpq_set_str (mpq t rop, const char *str, int base) Set rop from a null-terminated string str in the given base.
The string can be an integer like �41� or a fraction like �41/152�. The fraction must be in canonical form (see Chapter 6 [Rational Number Functions], page 46), or if not then mpq_canonicalize must be called.
The numerator and optional denominator are parsed the same as in mpz_set_str (see Section 5.2 [Assigning Integers], page 31). White space is allowed in the string, and is simply ignored. The base can vary from 2 to 62, or if base is 0 then the leading characters are used:
Chapter 6: Rational Number Functions 47
0x or 0X for hex, 0b or 0B for binary, 0 for octal, or decimal otherwise. Note that this is done separately for the numerator and denominator, so for instance 0xEF/100 is 239/100, whereas 0xEF/0x100 is 239/256. The return value is 0 if the entire string is a valid number, or -1 if not.
void mpq_swap (mpq t rop1, mpq t rop2) Swap the values rop1 and rop2 efficiently.
6.2 Conversion Functions
double mpq_get_d (const mpq t op) Convert op to a double, truncating if necessary (i.e. rounding towards zero).
If the exponent from the conversion is too big or too small to fit a double then the result is system dependent. For too big an infinity is returned when available. For too small 0.0 is normally returned. Hardware overflow, underflow and denorm traps may or may not occur.
void mpq_set_d (mpq t rop, double op) 
void mpq_set_f (mpq t rop, const mpf t op) Set rop to the value of op. There is no rounding, this conversion is exact.
char * mpq_get_str (char *str, int base, const mpq t op) Convert op to a string of digits in base base. The base may vary from 2 to 36. The string will be of the form �num/den�, or if the denominator is 1 then just �num�.
If str is NULL, the result string is allocated using the current allocation function (see Chapter 13 [Custom Allocation], page 90). The block will be strlen(str)+1 bytes, that being exactly enough for the string and null-terminator.
If str is not NULL, it should point to a block of storage large enough for the result, that being
mpz_sizeinbase (mpq_numref(op), base) + mpz_sizeinbase (mpq_denref(op), base) + 3
The three extra bytes are for a possible minus sign, possible slash, and the null-terminator.
A pointer to the result string is returned, being either the allocated block, or the given str.
*/

void q_add(void * sum, void * addend1, void * addend2) {
	mpq_add((mpq_ptr)sum, (mpq_srcptr)addend1, (mpq_srcptr)addend2);
}
void q_sub(void * difference, void * minuend, void * subtrahend) {
	mpq_sub((mpq_ptr)difference, (mpq_srcptr)minuend, (mpq_srcptr)subtrahend);
}
void q_mul(void * product, void * multiplier, void * multiplicand) {
	mpq_mul((mpq_ptr)product, (mpq_srcptr)multiplier, (mpq_srcptr)multiplicand);
}
void q_div(void * quotient, void * dividend, void * divisor) {
	mpq_div((mpq_ptr)quotient, (mpq_srcptr)dividend, (mpq_srcptr)divisor);
}
void q_neg(void * negated_operand, void * operand) {
	mpq_neg((mpq_ptr)negated_operand, (mpq_srcptr)operand);
}
void q_abs(void * rop, void * op) {
	mpq_abs((mpq_ptr)rop, (mpq_srcptr)op);
}
void q_inv(void * inverted_number, void * number) {
	mpq_inv((mpq_ptr)inverted_number, (mpq_srcptr)number);
}

/*
6.3 Arithmetic Functions
void mpq_add (mpq t sum, const mpq t addend1, const mpq t addend2) Set sum to addend1 + addend2.
void mpq_sub (mpq t difference, const mpq t minuend, const mpq t subtrahend) Set difference to minuend - subtrahend.
void mpq_mul (mpq t product, const mpq t multiplier, const mpq t multiplicand) Set product to multiplier �multiplicand.
void mpq_mul_2exp (mpq t rop, const mpq t op1, mp_bitcnt_t op2) Set rop to op1 �2op2.
48 GNU MP 6.1.2
void mpq_div (mpq t quotient, const mpq t dividend, const mpq t divisor) Set quotient to dividend/divisor.
void mpq_div_2exp (mpq t rop, const mpq t op1, mp_bitcnt_t op2) Set rop to op1/2op2.
void mpq_neg (mpq t negated_operand, const mpq t operand) Set negated operand to -operand. 
void mpq_abs (mpq t rop, const mpq t op) Set rop to the absolute value of op.
void mpq_inv (mpq t inverted_number, const mpq t number) Set inverted number to 1/number. If the new denominator is zero, this routine will divide by zero.
*/

int q_cmp(void * op1, void * op2) {
	return mpq_cmp((mpq_srcptr)op1, (mpq_srcptr)op2);
}
int q_equal(void * op1, void * op2) {
	return mpq_equal((mpq_srcptr)op1, (mpq_srcptr)op2);
}

/*
6.4 Comparison Functions
int mpq_cmp (const mpq t op1, const mpq t op2) 
int mpq_cmp_z (const mpq t op1, const mpz t op2) Compare op1 and op2. Return a positive value if op1 > op2, zero if op1 = op2, and a negative value if op1 < op2.
To determine if two rationals are equal, mpq_equal is faster than mpq_cmp.
[Macro]int mpq_cmp_ui (const mpq t op1, unsigned long int num2, unsigned long int den2) 
[Macro]int mpq_cmp_si (const mpq t op1, long int num2, unsigned long int den2) Compare op1 and num2/den2. Return a positive value if op1 > num2/den2, zero if op1 = num2/den2, and a negative value if op1 < num2/den2.
num2 and den2 are allowed to have common factors.
These functions are implemented as a macros and evaluate their arguments multiple times.
[Macro]int mpq_sgn (const mpq t op) Return +1 if op > 0, 0 if op = 0, and -1 if op < 0. This function is actually implemented as a macro. It evaluates its argument multiple times.
int mpq_equal (const mpq t op1, const mpq t op2) Return non-zero if op1 and op2 are equal, zero if they are non-equal. Although mpq_cmp can be used for the same purpose, this function is much faster.
*/

void q_get_num(void * int_numerator, void * rational) {
	mpq_get_num((mpz_ptr)int_numerator, (mpq_srcptr)rational);
}
void q_get_den(void * int_denominator, void * rational) {
	mpq_get_den((mpz_ptr)int_denominator, (mpq_srcptr)rational);
}
void q_set_num(void * rational, void * int_numerator) {
	mpq_set_num((mpq_ptr)rational, (mpz_srcptr)int_numerator);
}
void q_set_den(void * rational, void * int_denominator) {
	mpq_set_den((mpq_ptr)rational, (mpz_srcptr)int_denominator);
}

/*
6.5 Applying Integer Functions to Rationals The set of mpq functions is quite small. In particular, there are few functions for either input or output. The following functions give direct access to the numerator and denominator of an mpq_t.
Note that if an assignment to the numerator and/or denominator could take an mpq_t out of the canonical form described at the start of this chapter (see Chapter 6 [Rational Number Functions], page 46) then mpq_canonicalize must be called before any other mpq functions are applied to that mpq_t.
Chapter 6: Rational Number Functions 49
[Macro]mpz_t mpq_numref (const mpq t op) 
[Macro]mpz_t mpq_denref (const mpq t op) Return a reference to the numerator and denominator of op, respectively. The mpz functions can be used on the result of these macros.
void mpq_get_num (mpz t numerator, const mpq t rational) 
void mpq_get_den (mpz t denominator, const mpq t rational) 
void mpq_set_num (mpq t rational, const mpz t numerator) 
void mpq_set_den (mpq t rational, const mpz t denominator) Get or set the numerator or denominator of a rational. These functions are equivalent to calling mpz_set with an appropriate mpq_numref or mpq_denref. Direct use of mpq_numref or mpq_denref is recommended instead of these functions.
*/

// END RATIONAL NUMBER FUNCTIONS.

// BEGIN FLOATING-POINT FUNCTIONS:

/*
7 Floating-point Functions
GMP floating point numbers are stored in objects of type mpf_t and functions operating on them have an mpf_ prefix.
The mantissa of each float has a user-selectable precision, in practice only limited by available memory. Each variable has its own precision, and that can be increased or decreased at any time. This selectable precision is a minimum value, GMP rounds it up to a whole limb.
The accuracy of a calculation is determined by the priorly set precision of the destination variable and the numeric values of the input variables. Input variables� set precisions do not affect calculations (except indirectly as their values might have been affected when they were assigned).
The exponent of each float has fixed precision, one machine word on most systems. In the current implementation the exponent is a count of limbs, so for example on a 32-bit system this means a range of roughly 2-68719476768 to 268719476736, or on a 64-bit system this will be much greater. Note however that mpf_get_str can only return an exponent which fits an mp_exp_t and currently mpf_set_str doesn�t accept exponents bigger than a long.
Each variable keeps track of the mantissa data actually in use. This means that if a float is exactly represented in only a few bits then only those bits will be used in a calculation, even if the variable�s selected precision is high. This is a performance optimization; it does not affect the numeric results.
Internally, GMP sometimes calculates with higher precision than that of the destination variable in order to limit errors. Final results are always truncated to the destination variable�s precision.
The mantissa is stored in binary. One consequence of this is that decimal fractions like 0.1 cannot be represented exactly. The same is true of plain IEEE double floats. This makes both highly unsuitable for calculations involving money or other values that should be exact decimal fractions. (Suitably scaled integers, or perhaps rationals, are better choices.)
The mpf functions and variables have no special notion of infinity or not-a-number, and applications must take care not to overflow the exponent or results will be unpredictable.
Note that the mpf functions are not intended as a smooth extension to IEEE P754 arithmetic. In particular results obtained on one computer often differ from the results on a computer with a different word size.
New projects should consider using the GMP extension library MPFR (http://mpfr.org) instead. MPFR provides well-defined precision and accurate rounding, and thereby naturally extends IEEE P754.
*/

void float_set_default_prec(unsigned long prec) {
	mpf_set_default_prec((mp_bitcnt_t)prec);
}
unsigned long float_get_default_prec() {
	return (unsigned long)mpf_get_default_prec();
}

void * allocate_float() {
	return malloc(sizeof(mpf_t));
}
void register_float(void * p) {
	mpf_init((mpf_ptr)p);
}
void register_float2(void * p, unsigned long prec) {
	mpf_init2((mpf_ptr)p, (mp_bitcnt_t)prec);
}
void clear_float(void * p) {
	mpf_clear((mpf_ptr)p);
}

unsigned long float_get_prec(void * op) {
	return (unsigned long)mpf_get_prec((mpf_srcptr)op);
}
void float_set_prec(void * rop, unsigned long prec) {
	mpf_set_prec((mpf_ptr)rop, (mp_bitcnt_t)prec);
}

/*
7.1 Initialization Functions
void mpf_set_default_prec (mp_bitcnt_t prec) Set the default precision to be at least prec bits. All subsequent calls to mpf_init will use this precision, but previously initialized variables are unaffected.
mp_bitcnt_t mpf_get_default_prec (void) Return the default precision actually used.
An mpf_t object must be initialized before storing the first value in it. The functions mpf_init and mpf_init2 are used for that purpose.
Chapter 7: Floating-point Functions 51
void mpf_init (mpf t x) Initialize x to 0. Normally, a variable should be initialized once only or at least be cleared, using mpf_clear, between initializations. The precision of x is undefined unless a default precision has already been established by a call to mpf_set_default_prec.
void mpf_init2 (mpf t x, mp_bitcnt_t prec) Initialize x to 0 and set its precision to be at least prec bits. Normally, a variable should be initialized once only or at least be cleared, using mpf_clear, between initializations.
void mpf_inits (mpf t x, ...) Initialize a NULL-terminated list of mpf_t variables, and set their values to 0. The precision of the initialized variables is undefined unless a default precision has already been established by a call to mpf_set_default_prec.
void mpf_clear (mpf t x) Free the space occupied by x. Make sure to call this function for all mpf_t variables when you are done with them.
void mpf_clears (mpf t x, ...) Free the space occupied by a NULL-terminated list of mpf_t variables.
Here is an example on how to initialize floating-point variables:
{
  mpf_t x, y;
  mpf_init (x); // use default precision // 
  mpf_init2 (y, 256); // precision at least 256 bits //
  ... // Unless the program is about to exit, do
  ... // 
  mpf_clear (x);
  mpf_clear (y);
}
The following three functions are useful for changing the precision during a calculation. A typical use would be for adjusting the precision gradually in iterative algorithms like Newton-Raphson, making the computation precision closely match the actual accurate part of the numbers.
mp_bitcnt_t mpf_get_prec (const mpf t op) Return the current precision of op, in bits.
void mpf_set_prec (mpf t rop, mp_bitcnt_t prec) Set the precision of rop to be at least prec bits. The value in rop will be truncated to the new precision.
This function requires a call to realloc, and so should not be used in a tight loop.
void mpf_set_prec_raw (mpf t rop, mp_bitcnt_t prec) Set the precision of rop to be at least prec bits, without changing the memory allocated.
prec must be no more than the allocated precision for rop, that being the precision when rop was initialized, or in the most recent mpf_set_prec.
The value in rop is unchanged, and in particular if it had a higher precision than prec it will retain that higher precision. New values written to rop will use the new prec.
Before calling mpf_clear or the full mpf_set_prec, another mpf_set_prec_raw call must be made to restore rop to its original allocated precision. Failing to do so will have unpredictable results.
mpf_get_prec can be used before mpf_set_prec_raw to get the original allocated precision. After mpf_set_prec_raw it reflects the prec value set.
mpf_set_prec_raw is an efficient way to use an mpf_t variable at different precisions during a calculation, perhaps to gradually increase precision in an iteration, or just to use various different precisions for different purposes during a calculation.
*/

void float_set(void * rop, void * op) {
	mpf_set((mpf_ptr)rop, (mpf_srcptr)op);
}
int float_set_str(void * rop, const char *str, int base) {
	return mpf_set_str((mpf_ptr)rop, str, base);
}
char * float_get_str(char *str, void *expptr, int base, size_t n_digits, void * op) {
	return mpf_get_str(str, (mp_exp_t *)expptr, base, n_digits, (mpf_srcptr)op); // "mpf_srcptr" correction after looking at source "gmp.h"
}

void float_swap(void * rop1, void * rop2) {
	mpf_swap((mpf_ptr)rop1, (mpf_ptr)rop2);
}

/*
7.2 Assignment Functions These functions assign new values to already initialized floats (see Section 7.1 [Initializing Floats], page 50).
void mpf_set (mpf t rop, const mpf t op) 
void mpf_set_ui (mpf t rop, unsigned long int op) 
void mpf_set_si (mpf t rop, signed long int op) 
void mpf_set_d (mpf t rop, double op) 
void mpf_set_z (mpf t rop, const mpz t op) 
void mpf_set_q (mpf t rop, const mpq t op) Set the value of rop from op.
int mpf_set_str (mpf t rop, const char *str, int base) Set the value of rop from the string in str. The string is of the form �M@N� or, if the base is 10 or less, alternatively �MeN�. �M� is the mantissa and �N� is the exponent. The mantissa is always in the specified base. The exponent is either in the specified base or, if base is negative, in decimal. The decimal point expected is taken from the current locale, on systems providing localeconv. The argument base may be in the ranges 2 to 62, or -62 to -2. Negative values are used to specify that the exponent is in decimal.
For bases up to 36, case is ignored; upper-case and lower-case letters have the same value; for bases 37 to 62, upper-case letter represent the usual 10..35 while lower-case letter represent 36..61.
Unlike the corresponding mpz function, the base will not be determined from the leading characters of the string if base is 0. This is so that numbers like �0.23� are not interpreted as octal.
White space is allowed in the string, and is simply ignored. [This is not really true; whitespace is ignored in the beginning of the string and within the mantissa, but not in other places, such as after a minus sign or in the exponent. We are considering changing the definition of this function, making it fail when there is any white-space in the input, since that makes a lot of sense. Please tell us your opinion about this change. Do you really want it to accept "3 14" as meaning 314 as it does now?]
This function returns 0 if the entire string is a valid number in base base. Otherwise it returns -1.
void mpf_swap (mpf t rop1, mpf t rop2) Swap rop1 and rop2 efficiently. Both the values and the precisions of the two variables are swapped.
Chapter 7: Floating-point Functions 53
7.3 Combined Initialization and Assignment Functions For convenience, GMP provides a parallel series of initialize-and-set functions which initialize the output and then store the value there. These functions� names have the form mpf_init_set...
Once the float has been initialized by any of the mpf_init_set... functions, it can be used as the source or destination operand for the ordinary float functions. Don�t use an initialize-and-set function on a variable already initialized!
void mpf_init_set (mpf t rop, const mpf t op) 
void mpf_init_set_ui (mpf t rop, unsigned long int op) 
void mpf_init_set_si (mpf t rop, signed long int op) 
void mpf_init_set_d (mpf t rop, double op) Initialize rop and set its value from op.
The precision of rop will be taken from the active default precision, as set by mpf_set_ default_prec.
int mpf_init_set_str (mpf t rop, const char *str, int base) Initialize rop and set its value from the string in str. See mpf_set_str above for details on the assignment operation.
Note that rop is initialized even if an error occurs. (I.e., you have to call mpf_clear for it.)
The precision of rop will be taken from the active default precision, as set by mpf_set_ default_prec.
7.4 Conversion Functions
double mpf_get_d (const mpf t op) Convert op to a double, truncating if necessary (i.e. rounding towards zero).
If the exponent in op is too big or too small to fit a double then the result is system dependent. For too big an infinity is returned when available. For too small 0.0 is normally returned. Hardware overflow, underflow and denorm traps may or may not occur.
double mpf_get_d_2exp (signed long int *exp, const mpf t op) Convert op to a double, truncating if necessary (i.e. rounding towards zero), and with an exponent returned separately. The return value is in the range 0.5 =|d| < 1 and the exponent is stored to *exp. d �2exp is the (truncated) op value. If op is zero, the return is 0.0 and 0 is stored to *exp.
This is similar to the standard C frexp function (see Section �Normalization Functions� in The GNU C Library Reference Manual).
long mpf_get_si (const mpf t op) 
unsigned long mpf_get_ui (const mpf t op) Convert op to a long or unsigned long, truncating any fraction part. If op is too big for the return type, the result is undefined.
See also mpf_fits_slong_p and mpf_fits_ulong_p (see Section 7.8 [Miscellaneous Float Functions], page 56).
char * mpf_get_str (char *str, mp exp t *expptr, int base, size t n_digits, const mpf t op) Convert op to a string of digits in base base. The base argument may vary from 2 to 62 or from -2 to -36. Up to n digits digits will be generated. Trailing zeros are not returned. No more digits than can be accurately represented by op are ever generated. If n digits is 0 then that accurate maximum number of digits are generated. For base in the range 2..36, digits and lower-case letters are used; for -2..-36, digits and upper-case letters are used; for 37..62, digits, upper-case letters, and lower-case letters (in that significance order) are used.
If str is NULL, the result string is allocated using the current allocation function (see Chapter 13 [Custom Allocation], page 90). The block will be strlen(str)+1 bytes, that being exactly enough for the string and null-terminator.
If str is not NULL, it should point to a block of n digits + 2 bytes, that being enough for the mantissa, a possible minus sign, and a null-terminator. When n digits is 0 to get all significant digits, an application won�t be able to know the space required, and str should be NULL in that case.
The generated string is a fraction, with an implicit radix point immediately to the left of the first digit. The applicable exponent is written through the expptr pointer. For example, the number 3.1416 would be returned as string "31416" and exponent 1.
When op is zero, an empty string is produced and the exponent returned is 0.
A pointer to the result string is returned, being either the allocated block or the given str.
*/

void float_add(void * rop, void * op1, void * op2) {
	mpf_add((mpf_ptr)rop, (mpf_srcptr)op1, (mpf_srcptr)op2);
}
void float_sub(void * rop, void * op1, void * op2) {
	mpf_sub((mpf_ptr)rop, (mpf_srcptr)op1, (mpf_srcptr)op2);
}
void float_mul(void * rop, void * op1, void * op2) {
	mpf_mul((mpf_ptr)rop, (mpf_srcptr)op1, (mpf_srcptr)op2);
}
void float_div(void * rop, void * op1, void * op2) {
	mpf_div((mpf_ptr)rop, (mpf_srcptr)op1, (mpf_srcptr)op2);
}
void float_sqrt(void * rop, void * op) {
	mpf_sqrt((mpf_ptr)rop, (mpf_srcptr)op);
}
void float_sqrt_ui(void * rop, unsigned long int op) {
	mpf_sqrt_ui((mpf_ptr)rop, op);
}
void float_pow_ui(void * rop, void * op1, unsigned long int op2) {
	mpf_pow_ui((mpf_ptr)rop, (mpf_srcptr)op1, op2);
}
void float_neg(void * rop, void * op) {
	mpf_neg((mpf_ptr)rop, (mpf_srcptr)op);
}
void float_abs(void * rop, void * op) {
	mpf_abs((mpf_ptr)rop, (mpf_srcptr)op);
}

/*
7.5 Arithmetic Functions
void mpf_add (mpf t rop, const mpf t op1, const mpf t op2) 
void mpf_sub (mpf t rop, const mpf t op1, const mpf t op2) 
void mpf_mul (mpf t rop, const mpf t op1, const mpf t op2) 
void mpf_div (mpf t rop, const mpf t op1, const mpf t op2) 
void mpf_sqrt (mpf t rop, const mpf t op) 
void mpf_sqrt_ui (mpf t rop, unsigned long int op) Set rop to vop.
void mpf_pow_ui (mpf t rop, const mpf t op1, unsigned long int op2) Set rop to op1op2.
void mpf_neg (mpf t rop, const mpf t op) Set rop to -op.
void mpf_abs (mpf t rop, const mpf t op) Set rop to the absolute value of op.
*/

int float_cmp(void * op1, void * op2) {
	return mpf_cmp((mpf_srcptr)op1, (mpf_srcptr)op2);
}
void float_reldiff(void * rop, void * op1, void * op2) {
	mpf_reldiff((mpf_ptr)rop, (mpf_srcptr)op1, (mpf_srcptr)op2);
}
void float_ceil(void * rop, void * op) {
	mpf_ceil((mpf_ptr)rop, (mpf_srcptr)op);
}
void float_floor(void * rop, void * op) {
	mpf_floor((mpf_ptr)rop, (mpf_srcptr)op);
}
void float_trunc(void * rop, void * op) {
	mpf_trunc((mpf_ptr)rop, (mpf_srcptr)op);
}
int float_integer_p(void * op) {
	return mpf_integer_p((mpf_srcptr)op);
}


/*
7.6 Comparison Functions
int mpf_cmp (const mpf t op1, const mpf t op2) 
int mpf_cmp_z (const mpf t op1, const mpz t op2) 
int mpf_cmp_d (const mpf t op1, double op2) 
int mpf_cmp_ui (const mpf t op1, unsigned long int op2) 
int mpf_cmp_si (const mpf t op1, signed long int op2) Compare op1 and op2. Return a positive value if op1 > op2, zero if op1 = op2, and a negative value if op1 < op2.
mpf_cmp_d can be called with an infinity, but results are undefined for a NaN.
int mpf_eq (const mpf t op1, const mpf t op2, mp_bitcnt_t op3) This function is mathematically ill-defined and should not be used.
Return non-zero if the first op3 bits of op1 and op2 are equal, zero otherwise. Note that numbers like e.g., 256 (binary 100000000) and 255 (binary 11111111) will never be equal by this function�s measure, and furthermore that 0 will only be equal to itself.
void mpf_reldiff (mpf t rop, const mpf t op1, const mpf t op2) Compute the relative difference between op1 and op2 and store the result in rop. This is |op1 -op2|/op1.
[Macro]int mpf_sgn (const mpf t op) Return +1 if op > 0, 0 if op = 0, and -1 if op < 0. This function is actually implemented as a macro. It evaluates its argument multiple times.
*/
/*
7.7 Input and Output Functions Functions that perform input from a stdio stream, and functions that output to a stdio stream, of mpf numbers. Passing a NULL pointer for a stream argument to any of these functions will make them read from stdin and write to stdout, respectively.
When using any of these functions, it is a good idea to include stdio.h before gmp.h, since that will allow gmp.h to define prototypes for these functions.
See also Chapter 10 [Formatted Output], page 72 and Chapter 11 [Formatted Input], page 77.
56 GNU MP 6.1.2
size_t mpf_out_str (FILE *stream, int base, size t n_digits, const mpf t op) Print op to stream, as a string of digits. Return the number of bytes written, or if an error occurred, return 0.
The mantissa is prefixed with an �0.� and is in the given base, which may vary from 2 to 62 or from -2 to -36. An exponent is then printed, separated by an �e�, or if the base is greater than 10 then by an �@�. The exponent is always in decimal. The decimal point follows the current locale, on systems providing localeconv. For base in the range 2..36, digits and lower-case letters are used; for -2..-36, digits and upper-case letters are used; for 37..62, digits, upper-case letters, and lower-case letters (in that significance order) are used.
Up to n digits will be printed from the mantissa, except that no more digits than are accurately representable by op will be printed. n digits can be 0 to select that accurate maximum.
size_t mpf_inp_str (mpf t rop, FILE *stream, int base) Read a string in base base from stream, and put the read float in rop. The string is of the form �M@N� or, if the base is 10 or less, alternatively �MeN�. �M� is the mantissa and �N� is the exponent. The mantissa is always in the specified base. The exponent is either in the specified base or, if base is negative, in decimal. The decimal point expected is taken from the current locale, on systems providing localeconv. The argument base may be in the ranges 2 to 36, or -36 to -2. Negative values are used to specify that the exponent is in decimal.
Unlike the corresponding mpz function, the base will not be determined from the leading characters of the string if base is 0. This is so that numbers like �0.23� are not interpreted as octal.
Return the number of bytes read, or if an error occurred, return 0.
7.8 Miscellaneous Functions
void mpf_ceil (mpf t rop, const mpf t op) 
void mpf_floor (mpf t rop, const mpf t op) 
void mpf_trunc (mpf t rop, const mpf t op) Set rop to op rounded to an integer. mpf_ceil rounds to the next higher integer, mpf_floor to the next lower, and mpf_trunc to the integer towards zero.
int mpf_integer_p (const mpf t op) Return non-zero if op is an integer.
int mpf_fits_ulong_p (const mpf t op) 
int mpf_fits_slong_p (const mpf t op) 
int mpf_fits_uint_p (const mpf t op) 
int mpf_fits_sint_p (const mpf t op) 
int mpf_fits_ushort_p (const mpf t op) 
int mpf_fits_sshort_p (const mpf t op) Return non-zero if op would fit in the respective C data type, when truncated to an integer.
void mpf_urandomb (mpf t rop, gmp randstate t state, mp_bitcnt_t nbits) Generate a uniformly distributed random float in rop, such that 0 = rop < 1, with nbits significant bits in the mantissa or less if the precision of rop is smaller.
The variable state must be initialized by calling one of the gmp_randinit functions (Section 9.1 [Random State Initialization], page 70) before invoking this function.
void mpf_random2 (mpf t rop, mp size t max_size, mp exp t exp) Generate a random float of at most max size limbs, with long strings of zeros and ones in the binary representation. The exponent of the number is in the interval -exp to exp (in limbs). This function is useful for testing functions and algorithms, since these kind of random numbers have proven to be more likely to trigger corner-case bugs. Negative random numbers are generated when max size is negative.
58 GNU MP 6.1.2
8 Low-level Functions
This chapter describes low-level GMP functions, used to implement the high-level GMP functions, but also intended for time-critical user code.
These functions start with the prefix mpn_.
The mpn functions are designed to be as fast as possible, not to provide a coherent calling interface. The different functions have somewhat similar interfaces, but there are variations that make them hard to use. These functions do as little as possible apart from the real multiple precision computation, so that no time is spent on things that not all callers need.
A source operand is specified by a pointer to the least significant limb and a limb count. A destination operand is specified by just a pointer. It is the responsibility of the caller to ensure that the destination has enough space for storing the result.
With this way of specifying operands, it is possible to perform computations on subranges of an argument, and store the result into a subrange of a destination.
A common requirement for all functions is that each source area needs at least one limb. No size argument may be zero. Unless otherwise stated, in-place operations are allowed where source and destination are the same, but not where they only partly overlap.
The mpn functions are the base for the implementation of the mpz_, mpf_, and mpq_ functions.
This example adds the number beginning at s1p and the number beginning at s2p and writes the sum at destp. All areas have n limbs.
cy = mpn_add_n (destp, s1p, s2p, n)
It should be noted that the mpn functions make no attempt to identify high or low zero limbs on their operands, or other special forms. On random data such cases will be unlikely and it�d be wasteful for every function to check every time. An application knowing something about its data can take steps to trim or perhaps split its calculations.
In the notation used below, a source operand is identified by the pointer to the least significant limb, and the limb count in braces. For example, {s1p, s1n}.
mp_limb_t mpn_add_n (mp limb t *rp, const mp limb t *s1p, const mp limb t *s2p, mp size t n) Add {s1p, n} and {s2p, n}, and write the n least significant limbs of the result to rp. Return carry, either 0 or 1.
This is the lowest-level function for addition. It is the preferred function for addition, since it is written in assembly for most CPUs. For addition of a variable to itself (i.e., s1p equals s2p) use mpn_lshift with a count of 1 for optimal speed.
mp_limb_t mpn_add_1 (mp limb t *rp, const mp limb t *s1p, mp size t n, mp limb t s2limb) Add {s1p, n} and s2limb, and write the n least significant limbs of the result to rp. Return carry, either 0 or 1.
mp_limb_t mpn_add (mp limb t *rp, const mp limb t *s1p, mp size t s1n, const mp limb t *s2p, mp size t s2n) Add {s1p, s1n} and {s2p, s2n}, and write the s1n least significant limbs of the result to rp. Return carry, either 0 or 1.
Chapter 8: Low-level Functions 59
This function requires that s1n is greater than or equal to s2n.
mp_limb_t mpn_sub_n (mp limb t *rp, const mp limb t *s1p, const mp limb t *s2p, mp size t n) Subtract {s2p, n} from {s1p, n}, and write the n least significant limbs of the result to rp. Return borrow, either 0 or 1.
This is the lowest-level function for subtraction. It is the preferred function for subtraction, since it is written in assembly for most CPUs.
mp_limb_t mpn_sub_1 (mp limb t *rp, const mp limb t *s1p, mp size t n, mp limb t s2limb) Subtract s2limb from {s1p, n}, and write the n least significant limbs of the result to rp. Return borrow, either 0 or 1.
mp_limb_t mpn_sub (mp limb t *rp, const mp limb t *s1p, mp size t s1n, const mp limb t *s2p, mp size t s2n) Subtract {s2p, s2n} from {s1p, s1n}, and write the s1n least significant limbs of the result to rp. Return borrow, either 0 or 1.
This function requires that s1n is greater than or equal to s2n.
mp_limb_t mpn_neg (mp limb t *rp, const mp limb t *sp, mp size t n) Perform the negation of {sp, n}, and write the result to {rp, n}. This is equivalent to calling mpn_sub_n with a n-limb zero minuend and passing {sp, n} as subtrahend. Return borrow, either 0 or 1.
void mpn_mul_n (mp limb t *rp, const mp limb t *s1p, const mp limb t *s2p, mp size t n) Multiply {s1p, n} and {s2p, n}, and write the 2*n-limb result to rp.
The destination has to have space for 2*n limbs, even if the product�s most significant limb is zero. No overlap is permitted between the destination and either source.
If the two input operands are the same, use mpn_sqr.
mp_limb_t mpn_mul (mp limb t *rp, const mp limb t *s1p, mp size t s1n, const mp limb t *s2p, mp size t s2n) Multiply {s1p, s1n} and {s2p, s2n}, and write the (s1n+s2n)-limb result to rp. Return the most significant limb of the result.
The destination has to have space for s1n + s2n limbs, even if the product�s most significant limb is zero. No overlap is permitted between the destination and either source.
This function requires that s1n is greater than or equal to s2n.
void mpn_sqr (mp limb t *rp, const mp limb t *s1p, mp size t n) Compute the square of {s1p, n} and write the 2*n-limb result to rp.
The destination has to have space for 2n limbs, even if the result�s most significant limb is zero. No overlap is permitted between the destination and the source.
60 GNU MP 6.1.2
mp_limb_t mpn_mul_1 (mp limb t *rp, const mp limb t *s1p, mp size t n, mp limb t s2limb) Multiply {s1p, n} by s2limb, and write the n least significant limbs of the product to rp. Return the most significant limb of the product. {s1p, n} and {rp, n} are allowed to overlap provided rp = s1p. This is a low-level function that is a building block for general multiplication as well as other operations in GMP. It is written in assembly for most CPUs.
Don�t call this function if s2limb is a power of 2; use mpn_lshift with a count equal to the logarithm of s2limb instead, for optimal speed.
mp_limb_t mpn_addmul_1 (mp limb t *rp, const mp limb t *s1p, mp size t n, mp limb t s2limb) Multiply {s1p, n} and s2limb, and add the n least significant limbs of the product to {rp, n} and write the result to rp. Return the most significant limb of the product, plus carry-out from the addition. {s1p, n} and {rp, n} are allowed to overlap provided rp = s1p. This is a low-level function that is a building block for general multiplication as well as other operations in GMP. It is written in assembly for most CPUs.
mp_limb_t mpn_submul_1 (mp limb t *rp, const mp limb t *s1p, mp size t n, mp limb t s2limb) Multiply {s1p, n} and s2limb, and subtract the n least significant limbs of the product from {rp, n} and write the result to rp. Return the most significant limb of the product, plus borrow-out from the subtraction. {s1p, n} and {rp, n} are allowed to overlap provided rp = s1p. This is a low-level function that is a building block for general multiplication and division as well as other operations in GMP. It is written in assembly for most CPUs.
void mpn_tdiv_qr (mp limb t *qp, mp limb t *rp, mp size t qxn, const mp limb t *np, mp size t nn, const mp limb t *dp, mp size t dn) Divide {np, nn} by {dp, dn} and put the quotient at {qp, nn-dn+1} and the remainder at {rp, dn}. The quotient is rounded towards 0.
No overlap is permitted between arguments, except that np might equal rp. The dividend size nn must be greater than or equal to divisor size dn. The most significant limb of the divisor must be non-zero. The qxn operand must be zero.
mp_limb_t mpn_divrem (mp limb t *r1p, mp size t qxn, mp limb t *rs2p, mp size t rs2n, const mp limb t *s3p, mp size t s3n) [This function is obsolete. Please call mpn_tdiv_qr instead for best performance.]
Divide {rs2p, rs2n} by {s3p, s3n}, and write the quotient at r1p, with the exception of the most significant limb, which is returned. The remainder replaces the dividend at rs2p; it will be s3n limbs long (i.e., as many limbs as the divisor).
In addition to an integer quotient, qxn fraction limbs are developed, and stored after the integral limbs. For most usages, qxn will be zero.
It is required that rs2n is greater than or equal to s3n. It is required that the most significant bit of the divisor is set.
If the quotient is not needed, pass rs2p + s3n as r1p. Aside from that special case, no overlap between arguments is permitted.
*/

// END FLOATING-POINT FUNCTIONS.

// Formatted input and output, to be continued...


//here

// END OF FILE
