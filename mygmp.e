-- Copyright (c) 2020 James J. Cook
-- Simple wrapper for libmygmp.dll

-- Written for Euphoria v4.0.5

-- Code is for Win32 only.

-- See "mygmp.c" for details.

-- TODO: Update it for "mpfr" functions, working on it ;-)

-- NOTE: Any value larger than a 31-bit signed integer is stored as an "atom" in Euphoria,
--  even floats, doubles, signed and unsigned ints.

namespace mygmp

include std/dll.e
include std/machine.e

-- For MPFR rounding:
public constant 
MPFR_RNDN=0,  -- round to nearest, with ties to even
MPFR_RNDZ=1,    -- round toward zero
MPFR_RNDU=2,    -- round toward +Inf
MPFR_RNDD=3,    -- round toward -Inf
MPFR_RNDA=4,    -- round away from zero
-- MPFR_RNDF=5,    -- faithful rounding (not implemented yet)
MPFR_RNDNA=-1 -- round to nearest, with ties away from zero (mpfr_round)


public atom mygmp
public integer
xgeneric_free,
xsizeof_int,
xsizeof_q,
xsizeof_float,

xsizeof_f,
-- xallocate_f,
xregister_f,
xregister_f2,
xclear_f,
xclear_f_cache,
xf_get_default_prec,
xf_set_default_prec,
xf_get_prec,
xf_set_prec,
xf_set,
xf_set_ui,
xf_set_si,
-- extern int f_set_uj(void * p, unsigned long long op, int rnd);
-- extern int f_set_sj(void * p, long long op, int rnd);
-- xf_set_flt,
xf_set_d,
-- extern int f_set_ld(void * p, long double op, int rnd); // "long double" is "double" on Microsoft's compiler
xf_set_int,
xf_set_q,
xf_set_float,
xf_set_ui_2exp,
xf_set_si_2exp,
-- extern int f_set_uj_2exp(void * p, unsigned long long op, long long e, int rnd);
-- extern int f_set_sj_2exp(void * p, long long op, long long e, int rnd);
xf_set_int_2exp,
xf_set_str,
-- xf_strtofr,
xf_set_nan,
xf_set_inf,
xf_set_zero,
xf_swap,
-- // Initialize x and set its value from the string s in base base, rounded in the direction rnd
-- xf_init_set_str,
xf_get_flt,
xf_get_d,
-- extern long double f_get_ld(void * p, int rnd); // "long double" is "double" on Microsoft's compiler
xf_get_si,
xf_get_ui,
-- extern long long f_get_sj(void * p, int rnd);
-- extern unsigned long long f_get_uj(void * p, int rnd);
xf_get_d_2exp,
-- extern long double f_get_ld_2exp(long *exp, void * p, int rnd); // "long double" is "double" on Microsoft's compiler
xf_frexp,
xf_get_int_2exp,
xf_get_int,
-- xf_get_q,
xf_get_float,
xf_get_str,
xf_free_str,
xf_fits_ulong_p,
xf_fits_slong_p,
xf_fits_uint_p,
xf_fits_sint_p,
xf_fits_ushort_p,
xf_fits_sshort_p,
xf_fits_uintmax_p,
xf_fits_intmax_p,
xf_add,
xf_add_ui,
xf_add_si,
xf_add_d,
xf_add_int,
xf_add_q,
xf_sub,
xf_ui_sub,
xf_sub_ui,
xf_si_sub,
xf_sub_si,
xf_d_sub,
xf_sub_d,
xf_int_sub,
xf_sub_int,
xf_sub_q,
xf_mul,
xf_mul_ui,
xf_mul_si,
xf_mul_d,
xf_mul_int,
xf_mul_q,
--// Not to be confused with "sqrt", Set rop to op^2 rounded in the direction rnd:
xf_sqr,
xf_div,
xf_ui_div,
xf_div_ui,
xf_si_div,
xf_div_si,
xf_d_div,
xf_div_d,
xf_div_int,
xf_div_q,
xf_sqrt,
xf_sqrt_ui,
xf_rec_sqrt,
xf_cbrt,
-- xf_rootn_ui,
xf_root,
xf_pow,
xf_pow_ui,
xf_pow_si,
xf_pow_int,
xf_ui_pow_ui,
xf_ui_pow,
xf_neg,
xf_abs,
xf_dim,
xf_mul_2ui,
xf_mul_2si,
xf_div_2ui,
xf_div_2si,
xf_cmp,
xf_cmp_ui,
xf_cmp_si,
xf_cmp_d,
-- xf_cmp_ld,
xf_cmp_int,
xf_cmp_q,
xf_cmp_float,
xf_cmp_ui_2exp,
xf_cmp_si_2exp,
xf_cmpabs,
xf_nan_p,
xf_inf_p,
xf_number_p,
xf_zero_p,
xf_regular_p,
xf_sgn,
xf_greater_p,
xf_greaterequal_p,
xf_less_p,
xf_lessequal_p,
xf_equal_p,
xf_lessgreater_p,
xf_unordered_p,
xf_log,
-- xf_log_ui,
xf_log2,
xf_log10,
xf_log1p,
xf_exp,
xf_exp2,
xf_exp10,
xf_expm1,
xf_cos,
xf_sin,
xf_tan,
xf_sin_cos,
xf_sec,
xf_csc,
xf_cot,
xf_acos,
xf_asin,
xf_atan,
xf_atan2,
xf_cosh,
xf_sinh,
xf_tanh,
xf_sinh_cosh,
xf_sech,
xf_csch,
xf_coth,
xf_acosh,
xf_asinh,
xf_atanh,
xf_fac_ui,
xf_eint,
xf_li2,
xf_gamma,
-- xf_gamma_inc,
xf_lngamma,
xf_lgamma,
xf_digamma,
-- xf_beta,
xf_zeta,
xf_zeta_ui,
xf_erf,
xf_erfc,
xf_j0,
xf_j1,
xf_jn,
xf_y0,
xf_y1,
xf_yn,
xf_fma,
xf_fms,
-- xf_fmma,
-- xf_fmms,
xf_agm,
xf_hypot,
xf_ai,
xf_const_log2,
xf_const_pi,
xf_const_euler,
xf_const_catalan,
xf_free_cache,
xf_free_pool,
xf_mp_memory_cleanup,
xf_sum,
xf_out_str_filename,
xf_inp_str_filename,
xf_dump,
xf_fprintf_filename,
xf_printf,
--// xf_snprintf,
xf_asprintf,

xf_rint,
xf_ceil,
xf_floor,
xf_round,
xf_trunc,
xf_rint_ceil,
xf_rint_floor,
xf_rint_round,
xf_rint_roundeven,
xf_rint_trunc,
xf_frac,
xf_modf,
xf_fmod,
xf_fmodquo,
xf_remainder,
xf_remquo,
xf_integer_p,
xf_set_default_rounding_mode,
xf_get_default_rounding_mode,
xf_prec_round,
xf_can_round,
xf_min_prec,
xf_print_rnd_mode,
xf_nexttoward,
xf_nextabove,
xf_nextbelow,
xf_min,
xf_max,
xf_get_exp,
xf_set_exp,
xf_signbit,
xf_setsign,
xf_copysign,

xf_get_version,
xf_MPFR_VERSION,
xf_MPFR_VERSION_MAJOR,
xf_MPFR_VERSION_MINOR,
xf_MPFR_VERSION_PATCHLEVEL,
xf_MPFR_VERSION_NUM,
xf_get_patches,
xf_buildopt_tls_p,
xf_buildopt_decimal_p,
xf_buildopt_gmpinternals_p,

xf_get_emin,
xf_get_emax,
xf_set_emin,
xf_set_emax,
xf_get_emin_min,
xf_get_emin_max,
xf_get_emax_min,
xf_get_emax_max,
xf_check_range,
xf_subnormalize,
xf_clear_underflow,
xf_clear_overflow,
xf_clear_divby0,
xf_clear_nanflag,
xf_clear_inexflag,
xf_clear_erangeflag,
xf_clear_flags,
xf_set_underflow,
xf_set_overflow,
xf_set_divby0,
xf_set_nanflag,
xf_set_inexflag,
xf_set_erangeflag,

xf_underflow_p,
xf_overflow_p,
xf_divby0_p,
xf_nanflag_p,
xf_inexflag_p,
xf_erangeflag_p,

--// END mpfr FUNCTIONS.

--// BEGIN INT FUNCTIONS:

-- xallocate_int,
xregister_int,
xclear_int,
xint_set,
xint_set_ui,
xint_set_si,
xint_set_d,
xint_set_q,
xint_set_float,
xint_set_str,
xint_get_ui,
xint_get_si,
xint_get_d,
xint_get_d_2exp,
xint_get_str,
xint_add,
xint_add_ui,
xint_sub,
xint_sub_ui,
xint_ui_sub,
xint_mul,
xint_mul_si,
xint_mul_ui,
xint_addmul,
xint_addmul_ui,
xint_submul,
xint_submul_ui,
xint_mul_2exp,
xint_neg,
xint_abs,

xint_cdiv_q,
xint_cdiv_r,
xint_cdiv_qr,
xint_cdiv_q_ui,
xint_cdiv_r_ui,
xint_cdiv_qr_ui,
xint_cdiv_ui,
xint_cdiv_q_2exp,
xint_cdiv_r_2exp,
xint_fdiv_q,
xint_fdiv_r,
xint_fdiv_qr,
xint_fdiv_q_ui,
xint_fdiv_r_ui,
xint_fdiv_qr_ui,
xint_fdiv_ui,
xint_fdiv_q_2exp,
xint_fdiv_r_2exp,
xint_tdiv_q,
xint_tdiv_r,
xint_tdiv_qr,
xint_tdiv_q_ui,
xint_tdiv_r_ui,
xint_tdiv_qr_ui,
xint_tdiv_ui,
xint_tdiv_q_2exp,
xint_tdiv_r_2exp,
xint_mod,
xint_mod_ui,
xint_divexact,
xint_divexact_ui,
xint_divisible_p,
xint_divisible_ui_p,
xint_divisible_2exp_p,
xint_congruent_p,
xint_congruent_ui_p,
xint_congruent_2exp_p,
xint_powm,
xint_powm_ui,
xint_powm_sec,
xint_pow_ui,
xint_ui_pow_ui,
xint_root,
xint_rootrem,
xint_sqrt,
xint_sqrtrem,
xint_perfect_power_p,
xint_perfect_square_p,

xint_probab_prime_p,
xint_nextprime,
xint_gcd,
xint_gcd_ui,
xint_gcdext,
xint_lcm,
xint_lcm_ui,
xint_invert,
xint_jacobi,
xint_legendre,
xint_kronecker,
xint_kronecker_si,
xint_kronecker_ui,
xint_si_kronecker,
xint_ui_kronecker,
xint_remove,
xint_fac_ui,
xint_2fac_ui,
xint_mfac_uiui,
xint_primorial_ui,
xint_bin_ui,
xint_bin_uiui,
xint_fib_ui,
xint_fib2_ui,
xint_lucnum_ui,
xint_lucnum2_ui,

xint_cmp,
xint_cmp_d,
xint_cmp_si,
xint_cmp_ui,
xint_cmpabs,
xint_cmpabs_d,
xint_cmpabs_ui,
xint_sgn,
xint_and,
xint_ior,
xint_xor,
xint_com,
xint_popcount,
xint_hamdist,
xint_scan0,
xint_scan1,
xint_setbit,
xint_clrbit,
xint_combit,
xint_tstbit,

xint_out_str_filename,
xint_inp_str_filename,
xint_out_raw_filename,
xint_inp_raw_filename,

xint_import,
xint_export,

xint_urandomb,
xint_urandomm,
xint_rrandomb,
xint_random,
xint_random2,
xsizeof_randstate,
xint_randinit_default,
xint_randinit_mt,
xint_randinit_lc_2exp,
xint_randinit_lc_2exp_size,
xint_randinit_set,
xint_randclear,
xint_randseed,
xint_randseed_ui,
xint_urandomb_ui,
xint_urandomm_ui,

xint_fits_ulong_p,
xint_fits_slong_p,
xint_fits_uint_p,
xint_fits_sint_p,
xint_fits_ushort_p,
xint_fits_sshort_p,
xint_odd_p,
xint_even_p,
xint_sizeinbase,

-- xallocate_q,
xregister_q,
xclear_q,
xq_set,
xq_set_str,
xq_get_str,
xq_swap,
xq_add,
xq_sub,
xq_mul,
xq_div,
xq_neg,
xq_abs,
xq_inv,
xq_cmp,
xq_equal,
xq_get_num,
xq_get_den,
xq_set_num,
xq_set_den,

xfloat_set_default_prec,
xfloat_get_default_prec,
-- xallocate_float,
xregister_float,
xregister_float2,
xclear_float,
xfloat_get_prec,
xfloat_set_prec,
xfloat_set,
xfloat_set_str,
xfloat_get_str,
xfloat_swap,
xfloat_add,
xfloat_sub,
xfloat_mul,
xfloat_div,
xfloat_sqrt,
xfloat_sqrt_ui,
xfloat_pow_ui,
xfloat_neg,
xfloat_abs,
xfloat_cmp,
xfloat_reldiff,
xfloat_ceil,
xfloat_floor,
xfloat_trunc,
xfloat_integer_p,
$

integer sizeof_int, sizeof_q, sizeof_float, sizeof_f

public procedure init()
mygmp = open_dll("libmygmp.dll")
if mygmp = 0 then
	puts(2, "Can\'t open \"libmygmp.dll\"\n")
end if

xgeneric_free = define_c_proc(mygmp, "generic_free", {C_POINTER})
xsizeof_int = define_c_func(mygmp, "sizeof_int", {}, C_SIZE_T)
xsizeof_q = define_c_func(mygmp, "sizeof_q", {}, C_SIZE_T)
xsizeof_float = define_c_func(mygmp, "sizeof_float", {}, C_SIZE_T)
xsizeof_f = define_c_func(mygmp, "sizeof_f", {}, C_SIZE_T)

sizeof_int = c_func(xsizeof_int, {})
sizeof_q = c_func(xsizeof_q, {})
sizeof_float = c_func(xsizeof_float, {})
sizeof_f = c_func(xsizeof_f, {})

-- xallocate_f = define_c_func(mygmp, "allocate_f", {}, C_POINTER)
xregister_f = define_c_proc(mygmp, "register_f", {C_POINTER})
xregister_f2 = define_c_proc(mygmp, "register_f2", {C_POINTER, C_LONG})
xclear_f = define_c_proc(mygmp, "clear_f", {C_POINTER})
xclear_f_cache = define_c_proc(mygmp, "clear_f_cache", {})
xf_get_default_prec = define_c_func(mygmp, "f_get_default_prec", {}, C_LONG)
xf_set_default_prec = define_c_proc(mygmp, "f_set_default_prec", {C_LONG})
xf_get_prec = define_c_func(mygmp, "f_get_prec", {C_POINTER}, C_LONG)
xf_set_prec = define_c_proc(mygmp, "f_set_prec", {C_POINTER, C_LONG})
xf_set = define_c_func(mygmp, "f_set", {C_POINTER, C_POINTER, C_INT}, C_INT)
xf_set_ui = define_c_func(mygmp, "f_set_ui", {C_POINTER, C_ULONG, C_INT}, C_INT)
xf_set_si = define_c_func(mygmp, "f_set_si", {C_POINTER, C_LONG, C_INT}, C_INT)
-- xf_set_flt = define_c_func(mygmp, "f_set_flt", {C_POINTER, C_FLOAT, C_INT}, C_INT)
xf_set_d = define_c_func(mygmp, "f_set_d", {C_POINTER, C_DOUBLE, C_INT}, C_INT)
xf_set_int = define_c_func(mygmp, "f_set_int", {C_POINTER, C_POINTER, C_INT}, C_INT)
xf_set_q = define_c_func(mygmp, "f_set_q", {C_POINTER, C_POINTER, C_INT}, C_INT)
xf_set_float = define_c_func(mygmp, "f_set_float", {C_POINTER, C_POINTER, C_INT}, C_INT)
xf_set_ui_2exp = define_c_func(mygmp, "f_set_ui_2exp", {C_POINTER, C_ULONG, C_LONG, C_INT}, C_INT)
xf_set_si_2exp = define_c_func(mygmp, "f_set_si_2exp", {C_POINTER, C_LONG, C_LONG, C_INT}, C_INT)
xf_set_int_2exp = define_c_func(mygmp, "f_set_int_2exp", {C_POINTER, C_POINTER, C_LONG, C_INT}, C_INT)
xf_set_str = define_c_func(mygmp, "f_set_str", {C_POINTER, C_POINTER, C_INT, C_INT}, C_INT)
-- xf_strtofr = define_c_func(mygmp, "f_strtofr", {C_POINTER, C_POINTER, C_POINTER, C_INT, C_INT}, C_INT)
xf_set_nan = define_c_proc(mygmp, "f_set_nan", {C_POINTER})
xf_set_inf = define_c_proc(mygmp, "f_set_inf", {C_POINTER, C_INT})
xf_set_zero = define_c_proc(mygmp, "f_set_zero", {C_POINTER, C_INT})
xf_swap = define_c_proc(mygmp, "f_swap", {C_POINTER, C_POINTER})
-- // Initialize x and set its value from the string s in base base, rounded in the direction rnd
-- xf_init_set_str = define_c_func(mygmp, "f_init_set_str", {C_POINTER, C_POINTER, C_INT, C_INT}, C_INT)
xf_get_flt = define_c_func(mygmp, "f_get_flt", {C_POINTER, C_INT}, C_FLOAT)
xf_get_d = define_c_func(mygmp, "f_get_d", {C_POINTER, C_INT}, C_DOUBLE)
-- extern long double f_get_ld(C_POINTER, C_INT); // "long double" is "double" on Microsoft's compiler
xf_get_si = define_c_func(mygmp, "f_get_si", {C_POINTER, C_INT}, C_LONG)
xf_get_ui = define_c_func(mygmp, "f_get_ui", {C_POINTER, C_INT}, C_ULONG)
-- extern long long f_get_sj(C_POINTER, C_INT);
-- extern unsigned long long f_get_uj(C_POINTER, C_INT);
xf_get_d_2exp = define_c_func(mygmp, "f_get_d_2exp", {C_POINTER, C_POINTER, C_INT}, C_DOUBLE)
-- extern long double f_get_ld_2exp(long *exp, C_POINTER, C_INT); // "long double" is "double" on Microsoft's compiler
xf_frexp = define_c_func(mygmp, "f_frexp", {C_POINTER, C_POINTER, C_POINTER, C_INT}, C_INT)
xf_get_int_2exp = define_c_func(mygmp, "f_get_int_2exp", {C_POINTER, C_POINTER}, C_LONG)
xf_get_int = define_c_func(mygmp, "f_get_int", {C_POINTER, C_POINTER, C_INT}, C_INT)
-- xf_get_q = define_c_proc(mygmp, "f_get_q", {C_POINTER, C_POINTER})
xf_get_float = define_c_func(mygmp, "f_get_float", {C_POINTER, C_POINTER, C_INT}, C_INT)
xf_get_str = define_c_func(mygmp, "f_get_str", {C_POINTER, C_POINTER, C_INT, C_SIZE_T, C_POINTER, C_INT}, C_POINTER)
xf_free_str = define_c_proc(mygmp, "f_free_str", {C_POINTER})
xf_fits_ulong_p = define_c_func(mygmp, "f_fits_ulong_p", {C_POINTER, C_INT}, C_INT)
xf_fits_slong_p = define_c_func(mygmp, "f_fits_slong_p", {C_POINTER, C_INT}, C_INT)
xf_fits_uint_p = define_c_func(mygmp, "f_fits_uint_p", {C_POINTER, C_INT}, C_INT)
xf_fits_sint_p = define_c_func(mygmp, "f_fits_sint_p", {C_POINTER, C_INT}, C_INT)
xf_fits_ushort_p = define_c_func(mygmp, "f_fits_ushort_p", {C_POINTER, C_INT}, C_INT)
xf_fits_sshort_p = define_c_func(mygmp, "f_fits_sshort_p", {C_POINTER, C_INT}, C_INT)
xf_fits_uintmax_p = define_c_func(mygmp, "f_fits_uintmax_p", {C_POINTER, C_INT}, C_INT)
xf_fits_intmax_p = define_c_func(mygmp, "f_fits_intmax_p", {C_POINTER, C_INT}, C_INT)
xf_add = define_c_func(mygmp, "f_add", {C_POINTER, C_POINTER, C_POINTER, C_INT}, C_INT)
xf_add_ui = define_c_func(mygmp, "f_add_ui", {C_POINTER, C_POINTER, C_ULONG, C_INT}, C_INT)
xf_add_si = define_c_func(mygmp, "f_add_si", {C_POINTER, C_POINTER, C_LONG, C_INT}, C_INT)
xf_add_d = define_c_func(mygmp, "f_add_d", {C_POINTER, C_POINTER, C_DOUBLE, C_INT}, C_INT)
xf_add_int = define_c_func(mygmp, "f_add_int", {C_POINTER, C_POINTER, C_POINTER, C_INT}, C_INT)
xf_add_q = define_c_func(mygmp, "f_add_q", {C_POINTER, C_POINTER, C_POINTER, C_INT}, C_INT)
xf_sub = define_c_func(mygmp, "f_sub", {C_POINTER, C_POINTER, C_POINTER, C_INT}, C_INT)
xf_ui_sub = define_c_func(mygmp, "f_ui_sub", {C_POINTER, C_ULONG, C_POINTER, C_INT}, C_INT)
xf_sub_ui = define_c_func(mygmp, "f_sub_ui", {C_POINTER, C_POINTER, C_ULONG, C_INT}, C_INT)
xf_si_sub = define_c_func(mygmp, "f_si_sub", {C_POINTER, C_LONG, C_POINTER, C_INT}, C_INT)
xf_sub_si = define_c_func(mygmp, "f_sub_si", {C_POINTER, C_POINTER, C_LONG, C_INT}, C_INT)
xf_d_sub = define_c_func(mygmp, "f_d_sub", {C_POINTER, C_DOUBLE, C_POINTER, C_INT}, C_INT)
xf_sub_d = define_c_func(mygmp, "f_sub_d", {C_POINTER, C_POINTER, C_DOUBLE, C_INT}, C_INT)
xf_int_sub = define_c_func(mygmp, "f_int_sub", {C_POINTER, C_POINTER, C_POINTER, C_INT}, C_INT)
xf_sub_int = define_c_func(mygmp, "f_sub_int", {C_POINTER, C_POINTER, C_POINTER, C_INT}, C_INT)
xf_sub_q = define_c_func(mygmp, "f_sub_q", {C_POINTER, C_POINTER, C_POINTER, C_INT}, C_INT)
xf_mul = define_c_func(mygmp, "f_mul", {C_POINTER, C_POINTER, C_POINTER, C_INT}, C_INT)
xf_mul_ui = define_c_func(mygmp, "f_mul_ui", {C_POINTER, C_POINTER, C_ULONG, C_INT}, C_INT)
xf_mul_si = define_c_func(mygmp, "f_mul_si", {C_POINTER, C_POINTER, C_LONG, C_INT}, C_INT)
xf_mul_d = define_c_func(mygmp, "f_mul_d", {C_POINTER, C_POINTER, C_DOUBLE, C_INT}, C_INT)
xf_mul_int = define_c_func(mygmp, "f_mul_int", {C_POINTER, C_POINTER, C_POINTER, C_INT}, C_INT)
xf_mul_q = define_c_func(mygmp, "f_mul_q", {C_POINTER, C_POINTER, C_POINTER, C_INT}, C_INT)
--// Not to be confused with "sqrt", Set rop to op^2 rounded in the direction rnd:
xf_sqr = define_c_func(mygmp, "f_sqr", {C_POINTER, C_POINTER, C_INT}, C_INT)
xf_div = define_c_func(mygmp, "f_div", {C_POINTER, C_POINTER, C_POINTER, C_INT}, C_INT)
xf_ui_div = define_c_func(mygmp, "f_ui_div", {C_POINTER, C_ULONG, C_POINTER, C_INT}, C_INT)
xf_div_ui = define_c_func(mygmp, "f_div_ui", {C_POINTER, C_POINTER, C_ULONG, C_INT}, C_INT)
xf_si_div = define_c_func(mygmp, "f_si_div", {C_POINTER, C_LONG, C_POINTER, C_INT}, C_INT)
xf_div_si = define_c_func(mygmp, "f_div_si", {C_POINTER, C_POINTER, C_LONG, C_INT}, C_INT)
xf_d_div = define_c_func(mygmp, "f_d_div", {C_POINTER, C_DOUBLE, C_POINTER, C_INT}, C_INT)
xf_div_d = define_c_func(mygmp, "f_div_d", {C_POINTER, C_POINTER, C_DOUBLE, C_INT}, C_INT)
xf_div_int = define_c_func(mygmp, "f_div_int", {C_POINTER, C_POINTER, C_POINTER, C_INT}, C_INT)
xf_div_q = define_c_func(mygmp, "f_div_q", {C_POINTER, C_POINTER, C_POINTER, C_INT}, C_INT)
xf_sqrt = define_c_func(mygmp, "f_sqrt", {C_POINTER, C_POINTER, C_INT}, C_INT)
xf_sqrt_ui = define_c_func(mygmp, "f_sqrt_ui", {C_POINTER, C_ULONG, C_INT}, C_INT)
xf_rec_sqrt = define_c_func(mygmp, "f_rec_sqrt", {C_POINTER, C_POINTER, C_INT}, C_INT)
xf_cbrt = define_c_func(mygmp, "f_cbrt", {C_POINTER, C_POINTER, C_INT}, C_INT)
-- xf_rootn_ui = define_c_func(mygmp, "f_rootn_ui", {C_POINTER, C_POINTER, C_ULONG, C_INT}, C_INT)
xf_root = define_c_func(mygmp, "f_root", {C_POINTER, C_POINTER, C_ULONG, C_INT}, C_INT)
xf_pow = define_c_func(mygmp, "f_pow", {C_POINTER, C_POINTER, C_POINTER, C_INT}, C_INT)
xf_pow_ui = define_c_func(mygmp, "f_pow_ui", {C_POINTER, C_POINTER, C_ULONG, C_INT}, C_INT)
xf_pow_si = define_c_func(mygmp, "f_pow_si", {C_POINTER, C_POINTER, C_LONG, C_INT}, C_INT)
xf_pow_int = define_c_func(mygmp, "f_pow_int", {C_POINTER, C_POINTER, C_POINTER, C_INT}, C_INT)
xf_ui_pow_ui = define_c_func(mygmp, "f_ui_pow_ui", {C_POINTER, C_ULONG, C_ULONG, C_INT}, C_INT)
xf_ui_pow = define_c_func(mygmp, "f_ui_pow", {C_POINTER, C_ULONG, C_POINTER, C_INT}, C_INT)
xf_neg = define_c_func(mygmp, "f_neg", {C_POINTER, C_POINTER, C_INT}, C_INT)
xf_abs = define_c_func(mygmp, "f_abs", {C_POINTER, C_POINTER, C_INT}, C_INT)
xf_dim = define_c_func(mygmp, "f_dim", {C_POINTER, C_POINTER, C_POINTER, C_INT}, C_INT)
xf_mul_2ui = define_c_func(mygmp, "f_mul_2ui", {C_POINTER, C_POINTER, C_ULONG, C_INT}, C_INT)
xf_mul_2si = define_c_func(mygmp, "f_mul_2si", {C_POINTER, C_POINTER, C_LONG, C_INT}, C_INT)
xf_div_2ui = define_c_func(mygmp, "f_div_2ui", {C_POINTER, C_POINTER, C_ULONG, C_INT}, C_INT)
xf_div_2si = define_c_func(mygmp, "f_div_2si", {C_POINTER, C_POINTER, C_LONG, C_INT}, C_INT)
xf_cmp = define_c_func(mygmp, "f_cmp", {C_POINTER, C_POINTER}, C_INT)
xf_cmp_ui = define_c_func(mygmp, "f_cmp_ui", {C_POINTER, C_ULONG}, C_INT)
xf_cmp_si = define_c_func(mygmp, "f_cmp_si", {C_POINTER, C_LONG}, C_INT)
xf_cmp_d = define_c_func(mygmp, "f_cmp_d", {C_POINTER, C_DOUBLE}, C_INT)
-- xf_cmp_ld = define_c_func(mygmp, "f_cmp_ld", {C_POINTER, long double}, C_INT)
xf_cmp_int = define_c_func(mygmp, "f_cmp_int", {C_POINTER, C_POINTER}, C_INT)
xf_cmp_q = define_c_func(mygmp, "f_cmp_q", {C_POINTER, C_POINTER}, C_INT)
xf_cmp_float = define_c_func(mygmp, "f_cmp_float", {C_POINTER, C_POINTER}, C_INT)
xf_cmp_ui_2exp = define_c_func(mygmp, "f_cmp_ui_2exp", {C_POINTER, C_ULONG, C_LONG}, C_INT)
xf_cmp_si_2exp = define_c_func(mygmp, "f_cmp_si_2exp", {C_POINTER, C_LONG, C_LONG}, C_INT)
xf_cmpabs = define_c_func(mygmp, "f_cmpabs", {C_POINTER, C_POINTER}, C_INT)
xf_nan_p = define_c_func(mygmp, "f_nan_p", {C_POINTER}, C_INT)
xf_inf_p = define_c_func(mygmp, "f_inf_p", {C_POINTER}, C_INT)
xf_number_p = define_c_func(mygmp, "f_number_p", {C_POINTER}, C_INT)
xf_zero_p = define_c_func(mygmp, "f_zero_p", {C_POINTER}, C_INT)
xf_regular_p = define_c_func(mygmp, "f_regular_p", {C_POINTER}, C_INT)
xf_sgn = define_c_func(mygmp, "f_sgn", {C_POINTER}, C_INT)
xf_greater_p = define_c_func(mygmp, "f_greater_p", {C_POINTER, C_POINTER}, C_INT)
xf_greaterequal_p = define_c_func(mygmp, "f_greaterequal_p", {C_POINTER, C_POINTER}, C_INT)
xf_less_p = define_c_func(mygmp, "f_less_p", {C_POINTER, C_POINTER}, C_INT)
xf_lessequal_p = define_c_func(mygmp, "f_lessequal_p", {C_POINTER, C_POINTER}, C_INT)
xf_equal_p = define_c_func(mygmp, "f_equal_p", {C_POINTER, C_POINTER}, C_INT)
xf_lessgreater_p = define_c_func(mygmp, "f_lessgreater_p", {C_POINTER, C_POINTER}, C_INT)
xf_unordered_p = define_c_func(mygmp, "f_unordered_p", {C_POINTER, C_POINTER}, C_INT)
xf_log = define_c_func(mygmp, "f_log", {C_POINTER, C_POINTER, C_INT}, C_INT)
-- xf_log_ui = define_c_func(mygmp, "f_log_ui", {C_POINTER, C_ULONG, C_INT}, C_INT)
xf_log2 = define_c_func(mygmp, "f_log2", {C_POINTER, C_POINTER, C_INT}, C_INT)
xf_log10 = define_c_func(mygmp, "f_log10", {C_POINTER, C_POINTER, C_INT}, C_INT)
xf_log1p = define_c_func(mygmp, "f_log1p", {C_POINTER, C_POINTER, C_INT}, C_INT)
xf_exp = define_c_func(mygmp, "f_exp", {C_POINTER, C_POINTER, C_INT}, C_INT)
xf_exp2 = define_c_func(mygmp, "f_exp2", {C_POINTER, C_POINTER, C_INT}, C_INT)
xf_exp10 = define_c_func(mygmp, "f_exp10", {C_POINTER, C_POINTER, C_INT}, C_INT)
xf_expm1 = define_c_func(mygmp, "f_expm1", {C_POINTER, C_POINTER, C_INT}, C_INT)
xf_cos = define_c_func(mygmp, "f_cos", {C_POINTER, C_POINTER, C_INT}, C_INT)
xf_sin = define_c_func(mygmp, "f_sin", {C_POINTER, C_POINTER, C_INT}, C_INT)
xf_tan = define_c_func(mygmp, "f_tan", {C_POINTER, C_POINTER, C_INT}, C_INT)
xf_sin_cos = define_c_func(mygmp, "f_sin_cos", {C_POINTER, C_POINTER, C_POINTER, C_INT}, C_INT)
xf_sec = define_c_func(mygmp, "f_sec", {C_POINTER, C_POINTER, C_INT}, C_INT)
xf_csc = define_c_func(mygmp, "f_csc", {C_POINTER, C_POINTER, C_INT}, C_INT)
xf_cot = define_c_func(mygmp, "f_cot", {C_POINTER, C_POINTER, C_INT}, C_INT)
xf_acos = define_c_func(mygmp, "f_acos", {C_POINTER, C_POINTER, C_INT}, C_INT)
xf_asin = define_c_func(mygmp, "f_asin", {C_POINTER, C_POINTER, C_INT}, C_INT)
xf_atan = define_c_func(mygmp, "f_atan", {C_POINTER, C_POINTER, C_INT}, C_INT)
xf_atan2 = define_c_func(mygmp, "f_atan2", {C_POINTER, C_POINTER, C_POINTER, C_INT}, C_INT)
xf_cosh = define_c_func(mygmp, "f_cosh", {C_POINTER, C_POINTER, C_INT}, C_INT)
xf_sinh = define_c_func(mygmp, "f_sinh", {C_POINTER, C_POINTER, C_INT}, C_INT)
xf_tanh = define_c_func(mygmp, "f_tanh", {C_POINTER, C_POINTER, C_INT}, C_INT)
xf_sinh_cosh = define_c_func(mygmp, "f_sinh_cosh", {C_POINTER, C_POINTER, C_POINTER, C_INT}, C_INT)
xf_sech = define_c_func(mygmp, "f_sech", {C_POINTER, C_POINTER, C_INT}, C_INT)
xf_csch = define_c_func(mygmp, "f_csch", {C_POINTER, C_POINTER, C_INT}, C_INT)
xf_coth = define_c_func(mygmp, "f_coth", {C_POINTER, C_POINTER, C_INT}, C_INT)
xf_acosh = define_c_func(mygmp, "f_acosh", {C_POINTER, C_POINTER, C_INT}, C_INT)
xf_asinh = define_c_func(mygmp, "f_asinh", {C_POINTER, C_POINTER, C_INT}, C_INT)
xf_atanh = define_c_func(mygmp, "f_atanh", {C_POINTER, C_POINTER, C_INT}, C_INT)
xf_fac_ui = define_c_func(mygmp, "f_fac_ui", {C_POINTER, C_ULONG, C_INT}, C_INT)
xf_eint = define_c_func(mygmp, "f_eint", {C_POINTER, C_POINTER, C_INT}, C_INT)
xf_li2 = define_c_func(mygmp, "f_li2", {C_POINTER, C_POINTER, C_INT}, C_INT)
xf_gamma = define_c_func(mygmp, "f_gamma", {C_POINTER, C_POINTER, C_INT}, C_INT)
-- xf_gamma_inc = define_c_func(mygmp, "f_gamma_inc", {C_POINTER, C_POINTER, C_POINTER, C_INT}, C_INT)
xf_lngamma = define_c_func(mygmp, "f_lngamma", {C_POINTER, C_POINTER, C_INT}, C_INT)
xf_lgamma = define_c_func(mygmp, "f_lgamma", {C_POINTER, C_POINTER, C_POINTER, C_INT}, C_INT)
xf_digamma = define_c_func(mygmp, "f_digamma", {C_POINTER, C_POINTER, C_INT}, C_INT)
-- xf_beta = define_c_func(mygmp, "f_beta", {C_POINTER, C_POINTER, C_POINTER, C_INT}, C_INT)
xf_zeta = define_c_func(mygmp, "f_zeta", {C_POINTER, C_POINTER, C_INT}, C_INT)
xf_zeta_ui = define_c_func(mygmp, "f_zeta_ui", {C_POINTER, C_ULONG, C_INT}, C_INT)
xf_erf = define_c_func(mygmp, "f_erf", {C_POINTER, C_POINTER, C_INT}, C_INT)
xf_erfc = define_c_func(mygmp, "f_erfc", {C_POINTER, C_POINTER, C_INT}, C_INT)
xf_j0 = define_c_func(mygmp, "f_j0", {C_POINTER, C_POINTER, C_INT}, C_INT)
xf_j1 = define_c_func(mygmp, "f_j1", {C_POINTER, C_POINTER, C_INT}, C_INT)
xf_jn = define_c_func(mygmp, "f_jn", {C_POINTER, C_LONG, C_POINTER, C_INT}, C_INT)
xf_y0 = define_c_func(mygmp, "f_y0", {C_POINTER, C_POINTER, C_INT}, C_INT)
xf_y1 = define_c_func(mygmp, "f_y1", {C_POINTER, C_POINTER, C_INT}, C_INT)
xf_yn = define_c_func(mygmp, "f_yn", {C_POINTER, C_LONG, C_POINTER, C_INT}, C_INT)
xf_fma = define_c_func(mygmp, "f_fma", {C_POINTER, C_POINTER, C_POINTER, C_POINTER, C_INT}, C_INT)
xf_fms = define_c_func(mygmp, "f_fms", {C_POINTER, C_POINTER, C_POINTER, C_POINTER, C_INT}, C_INT)
-- xf_fmma = define_c_func(mygmp, "f_fmma", {C_POINTER, C_POINTER, C_POINTER, C_POINTER, C_POINTER, C_INT}, C_INT)
-- xf_fmms = define_c_func(mygmp, "f_fmms", {C_POINTER, C_POINTER, C_POINTER, C_POINTER, C_POINTER, C_INT}, C_INT)
xf_agm = define_c_func(mygmp, "f_agm", {C_POINTER, C_POINTER, C_POINTER, C_INT}, C_INT)
xf_hypot = define_c_func(mygmp, "f_hypot", {C_POINTER, C_POINTER, C_POINTER, C_INT}, C_INT)
xf_ai = define_c_func(mygmp, "f_ai", {C_POINTER, C_POINTER, C_INT}, C_INT)
xf_const_log2 = define_c_func(mygmp, "f_const_log2", {C_POINTER, C_INT}, C_INT)
xf_const_pi = define_c_func(mygmp, "f_const_pi", {C_POINTER, C_INT}, C_INT)
xf_const_euler = define_c_func(mygmp, "f_const_euler", {C_POINTER, C_INT}, C_INT)
xf_const_catalan = define_c_func(mygmp, "f_const_catalan", {C_POINTER, C_INT}, C_INT)
xf_free_cache = define_c_proc(mygmp, "f_free_cache", {})
xf_free_pool = define_c_proc(mygmp, "f_free_pool", {})
xf_mp_memory_cleanup = define_c_func(mygmp, "f_mp_memory_cleanup", {}, C_INT)
xf_sum = define_c_func(mygmp, "f_sum", {C_POINTER, C_POINTER, C_ULONG, C_INT}, C_INT)
xf_out_str_filename = define_c_func(mygmp, "f_out_str_filename", {C_POINTER, C_INT, C_SIZE_T, C_POINTER, C_INT}, C_SIZE_T)
xf_inp_str_filename = define_c_func(mygmp, "f_inp_str_filename", {C_POINTER, C_POINTER, C_INT, C_INT}, C_SIZE_T)
xf_dump = define_c_proc(mygmp, "f_dump", {C_POINTER})
xf_fprintf_filename = define_c_func(mygmp, "f_fprintf_filename", {C_POINTER, C_POINTER, C_POINTER}, C_INT)
xf_printf = define_c_func(mygmp, "f_printf", {C_POINTER, C_POINTER}, C_INT)
--// xf_snprintf = define_c_func(mygmp, "f_snprintf", {C_POINTER, C_SIZE_T, C_POINTER, C_POINTER}, C_INT)
xf_asprintf = define_c_func(mygmp, "f_asprintf", {C_POINTER, C_POINTER, C_POINTER}, C_INT)

xf_rint = define_c_func(mygmp, "f_rint", {C_POINTER, C_POINTER, C_INT}, C_INT)
xf_ceil = define_c_func(mygmp, "f_ceil", {C_POINTER, C_POINTER}, C_INT)
xf_floor = define_c_func(mygmp, "f_floor", {C_POINTER, C_POINTER}, C_INT)
xf_round = define_c_func(mygmp, "f_round", {C_POINTER, C_POINTER}, C_INT)
xf_trunc = define_c_func(mygmp, "f_trunc", {C_POINTER, C_POINTER}, C_INT)
xf_rint_ceil = define_c_func(mygmp, "f_rint_ceil", {C_POINTER, C_POINTER, C_INT}, C_INT)
xf_rint_floor = define_c_func(mygmp, "f_rint_floor", {C_POINTER, C_POINTER, C_INT}, C_INT)
xf_rint_round = define_c_func(mygmp, "f_rint_round", {C_POINTER, C_POINTER, C_INT}, C_INT)
xf_rint_roundeven = define_c_func(mygmp, "f_rint_roundeven", {C_POINTER, C_POINTER, C_INT}, C_INT)
xf_rint_trunc = define_c_func(mygmp, "f_rint_trunc", {C_POINTER, C_POINTER, C_INT}, C_INT)
xf_frac = define_c_func(mygmp, "f_frac", {C_POINTER, C_POINTER, C_INT}, C_INT)
xf_modf = define_c_func(mygmp, "f_modf", {C_POINTER, C_POINTER, C_POINTER, C_INT}, C_INT)
xf_fmod = define_c_func(mygmp, "f_fmod", {C_POINTER, C_POINTER, C_POINTER, C_INT}, C_INT)
xf_fmodquo = define_c_func(mygmp, "f_fmodquo", {C_POINTER, C_POINTER, C_POINTER, C_POINTER, C_INT}, C_INT)
xf_remainder = define_c_func(mygmp, "f_remainder", {C_POINTER, C_POINTER, C_POINTER, C_INT}, C_INT)
xf_remquo = define_c_func(mygmp, "f_remquo", {C_POINTER, C_POINTER, C_POINTER, C_POINTER, C_INT}, C_INT)
xf_integer_p = define_c_func(mygmp, "f_integer_p", {C_POINTER}, C_INT)
xf_set_default_rounding_mode = define_c_proc(mygmp, "f_set_default_rounding_mode", {C_INT})
xf_get_default_rounding_mode = define_c_func(mygmp, "f_get_default_rounding_mode", {}, C_INT)
xf_prec_round = define_c_func(mygmp, "f_prec_round", {C_POINTER, C_LONG, C_INT}, C_INT)
xf_can_round = define_c_func(mygmp, "f_can_round", {C_POINTER, C_LONG, C_INT, C_INT, C_LONG}, C_INT)
xf_min_prec = define_c_func(mygmp, "f_min_prec", {C_POINTER}, C_LONG)
xf_print_rnd_mode = define_c_func(mygmp, "f_print_rnd_mode", {C_INT}, C_POINTER)
xf_nexttoward = define_c_proc(mygmp, "f_nexttoward", {C_POINTER, C_POINTER})
xf_nextabove = define_c_proc(mygmp, "f_nextabove", {C_POINTER})
xf_nextbelow = define_c_proc(mygmp, "f_nextbelow", {C_POINTER})
xf_min = define_c_func(mygmp, "f_min", {C_POINTER, C_POINTER, C_POINTER, C_INT}, C_INT)
xf_max = define_c_func(mygmp, "f_max", {C_POINTER, C_POINTER, C_POINTER, C_INT}, C_INT)
xf_get_exp = define_c_func(mygmp, "f_get_exp", {C_POINTER}, C_LONG)
xf_set_exp = define_c_func(mygmp, "f_set_exp", {C_POINTER, C_LONG}, C_INT)
xf_signbit = define_c_func(mygmp, "f_signbit", {C_POINTER}, C_INT)
xf_setsign = define_c_func(mygmp, "f_setsign", {C_POINTER, C_POINTER, C_INT, C_INT}, C_INT)
xf_copysign = define_c_func(mygmp, "f_copysign", {C_POINTER, C_POINTER, C_POINTER, C_INT}, C_INT)

xf_get_version = define_c_func(mygmp, "f_get_version", {}, C_POINTER)
xf_MPFR_VERSION = define_c_func(mygmp, "f_MPFR_VERSION", {}, C_LONG)
xf_MPFR_VERSION_MAJOR = define_c_func(mygmp, "f_MPFR_VERSION_MAJOR", {}, C_LONG)
xf_MPFR_VERSION_MINOR = define_c_func(mygmp, "f_MPFR_VERSION_MINOR", {}, C_LONG)
xf_MPFR_VERSION_PATCHLEVEL = define_c_func(mygmp, "f_MPFR_VERSION_PATCHLEVEL", {}, C_LONG)
xf_MPFR_VERSION_NUM = define_c_func(mygmp, "f_MPFR_VERSION_NUM", {C_LONG, C_LONG, C_LONG}, C_LONG)
xf_get_patches = define_c_func(mygmp, "f_get_patches", {}, C_POINTER)
xf_buildopt_tls_p = define_c_func(mygmp, "f_buildopt_tls_p", {}, C_INT)
xf_buildopt_decimal_p = define_c_func(mygmp, "f_buildopt_decimal_p", {}, C_INT)
xf_buildopt_gmpinternals_p = define_c_func(mygmp, "f_buildopt_gmpinternals_p", {}, C_INT)
xf_get_emin = define_c_func(mygmp, "f_get_emin", {}, C_LONG)
xf_get_emax = define_c_func(mygmp, "f_get_emax", {}, C_LONG)
xf_set_emin = define_c_func(mygmp, "f_set_emin", {C_LONG}, C_INT)
xf_set_emax = define_c_func(mygmp, "f_set_emax", {C_LONG}, C_INT)
xf_get_emin_min = define_c_func(mygmp, "f_get_emin_min", {}, C_LONG)
xf_get_emin_max = define_c_func(mygmp, "f_get_emin_max", {}, C_LONG)
xf_get_emax_min = define_c_func(mygmp, "f_get_emax_min", {}, C_LONG)
xf_get_emax_max = define_c_func(mygmp, "f_get_emax_max", {}, C_LONG)
xf_check_range = define_c_func(mygmp, "f_check_range", {C_POINTER, C_INT, C_INT}, C_INT)
xf_subnormalize = define_c_func(mygmp, "f_subnormalize", {C_POINTER, C_INT, C_INT}, C_INT)
xf_clear_underflow = define_c_proc(mygmp, "f_clear_underflow", {})
xf_clear_overflow = define_c_proc(mygmp, "f_clear_overflow", {})
xf_clear_divby0 = define_c_proc(mygmp, "f_clear_divby0", {})
xf_clear_nanflag = define_c_proc(mygmp, "f_clear_nanflag", {})
xf_clear_inexflag = define_c_proc(mygmp, "f_clear_inexflag", {})
xf_clear_erangeflag = define_c_proc(mygmp, "f_clear_erangeflag", {})
xf_clear_flags = define_c_proc(mygmp, "f_clear_flags", {})
xf_set_underflow = define_c_proc(mygmp, "f_set_underflow", {})
xf_set_overflow = define_c_proc(mygmp, "f_set_overflow", {})
xf_set_divby0 = define_c_proc(mygmp, "f_set_divby0", {})
xf_set_nanflag = define_c_proc(mygmp, "f_set_nanflag", {})
xf_set_inexflag = define_c_proc(mygmp, "f_set_inexflag", {})
xf_set_erangeflag = define_c_proc(mygmp, "f_set_erangeflag", {})
xf_underflow_p = define_c_func(mygmp, "f_underflow_p", {}, C_INT)
xf_overflow_p = define_c_func(mygmp, "f_overflow_p", {}, C_INT)
xf_divby0_p = define_c_func(mygmp, "f_divby0_p", {}, C_INT)
xf_nanflag_p = define_c_func(mygmp, "f_nanflag_p", {}, C_INT)
xf_inexflag_p = define_c_func(mygmp, "f_inexflag_p", {}, C_INT)
xf_erangeflag_p = define_c_func(mygmp, "f_erangeflag_p", {}, C_INT)

--// END mpfr FUNCTIONS.

--// BEGIN INT FUNCTIONS:

-- xallocate_int = define_c_func(mygmp, "allocate_int", {}, C_POINTER)
xregister_int = define_c_proc(mygmp, "register_int", {C_POINTER})
xclear_int = define_c_proc(mygmp, "clear_int", {C_POINTER})
xint_set = define_c_proc(mygmp, "int_set", {C_POINTER, C_POINTER})
xint_set_ui = define_c_proc(mygmp, "int_set_ui", {C_POINTER, C_ULONG})
xint_set_si = define_c_proc(mygmp, "int_set_si", {C_POINTER, C_LONG})
xint_set_d = define_c_proc(mygmp, "int_set_d", {C_POINTER, C_DOUBLE})
xint_set_q = define_c_proc(mygmp, "int_set_q", {C_POINTER, C_POINTER})
xint_set_float = define_c_proc(mygmp, "int_set_float", {C_POINTER, C_POINTER})
xint_set_str = define_c_func(mygmp, "int_set_str", {C_POINTER, C_POINTER, C_INT}, C_INT)
xint_get_ui = define_c_func(mygmp, "int_get_ui", {C_POINTER}, C_ULONG)
xint_get_si = define_c_func(mygmp, "int_get_si", {C_POINTER}, C_LONG)
xint_get_d = define_c_func(mygmp, "int_get_d", {C_POINTER}, C_DOUBLE)
xint_get_d_2exp = define_c_func(mygmp, "int_get_d_2exp", {C_POINTER, C_POINTER}, C_DOUBLE)
xint_get_str = define_c_func(mygmp, "int_get_str", {C_POINTER, C_INT, C_POINTER}, C_POINTER)
xint_add = define_c_proc(mygmp, "int_add", {C_POINTER, C_POINTER, C_POINTER})
xint_add_ui = define_c_proc(mygmp, "int_add_ui", {C_POINTER, C_POINTER, C_ULONG})
xint_sub = define_c_proc(mygmp, "int_sub", {C_POINTER, C_POINTER, C_POINTER})
xint_sub_ui = define_c_proc(mygmp, "int_sub_ui", {C_POINTER, C_POINTER, C_ULONG})
xint_ui_sub = define_c_proc(mygmp, "int_ui_sub", {C_POINTER, C_ULONG, C_POINTER})
xint_mul = define_c_proc(mygmp, "int_mul", {C_POINTER, C_POINTER, C_POINTER})
xint_mul_si = define_c_proc(mygmp, "int_mul_si", {C_POINTER, C_POINTER, C_LONG})
xint_mul_ui = define_c_proc(mygmp, "int_mul_ui", {C_POINTER, C_POINTER, C_ULONG})
xint_addmul = define_c_proc(mygmp, "int_addmul", {C_POINTER, C_POINTER, C_POINTER})
xint_addmul_ui = define_c_proc(mygmp, "int_addmul_ui", {C_POINTER, C_POINTER, C_ULONG})
xint_submul = define_c_proc(mygmp, "int_submul", {C_POINTER, C_POINTER, C_POINTER})
xint_submul_ui = define_c_proc(mygmp, "int_submul_ui", {C_POINTER, C_POINTER, C_ULONG})
xint_mul_2exp = define_c_proc(mygmp, "int_mul_2exp", {C_POINTER, C_POINTER, C_ULONG})
xint_neg = define_c_proc(mygmp, "int_neg", {C_POINTER, C_POINTER})
xint_abs = define_c_proc(mygmp, "int_abs", {C_POINTER, C_POINTER})

xint_cdiv_q = define_c_proc(mygmp, "int_cdiv_q", {C_POINTER, C_POINTER, C_POINTER})
xint_cdiv_r = define_c_proc(mygmp, "int_cdiv_r", {C_POINTER, C_POINTER, C_POINTER})
xint_cdiv_qr = define_c_proc(mygmp, "int_cdiv_qr", {C_POINTER, C_POINTER, C_POINTER, C_POINTER})
xint_cdiv_q_ui = define_c_func(mygmp, "int_cdiv_q_ui", {C_POINTER, C_POINTER, C_ULONG}, C_ULONG)
xint_cdiv_r_ui = define_c_func(mygmp, "int_cdiv_r_ui", {C_POINTER, C_POINTER, C_ULONG}, C_ULONG)
xint_cdiv_qr_ui = define_c_func(mygmp, "int_cdiv_qr_ui", {C_POINTER, C_POINTER, C_POINTER, C_ULONG}, C_ULONG)
xint_cdiv_ui = define_c_func(mygmp, "int_cdiv_ui", {C_POINTER, C_ULONG}, C_ULONG)
xint_cdiv_q_2exp = define_c_proc(mygmp, "int_cdiv_q_2exp", {C_POINTER, C_POINTER, C_ULONG})
xint_cdiv_r_2exp = define_c_proc(mygmp, "int_cdiv_r_2exp", {C_POINTER, C_POINTER, C_ULONG})
xint_fdiv_q = define_c_proc(mygmp, "int_fdiv_q", {C_POINTER, C_POINTER, C_POINTER})
xint_fdiv_r = define_c_proc(mygmp, "int_fdiv_r", {C_POINTER, C_POINTER, C_POINTER})
xint_fdiv_qr = define_c_proc(mygmp, "int_fdiv_qr", {C_POINTER, C_POINTER, C_POINTER, C_POINTER})
xint_fdiv_q_ui = define_c_func(mygmp, "int_fdiv_q_ui", {C_POINTER, C_POINTER, C_ULONG}, C_ULONG)
xint_fdiv_r_ui = define_c_func(mygmp, "int_fdiv_r_ui", {C_POINTER, C_POINTER, C_ULONG}, C_ULONG)
xint_fdiv_qr_ui = define_c_func(mygmp, "int_fdiv_qr_ui", {C_POINTER, C_POINTER, C_POINTER, C_ULONG}, C_ULONG)
xint_fdiv_ui = define_c_func(mygmp, "int_fdiv_ui", {C_POINTER, C_ULONG}, C_ULONG)
xint_fdiv_q_2exp = define_c_proc(mygmp, "int_fdiv_q_2exp", {C_POINTER, C_POINTER, C_ULONG})
xint_fdiv_r_2exp = define_c_proc(mygmp, "int_fdiv_r_2exp", {C_POINTER, C_POINTER, C_ULONG})
xint_tdiv_q = define_c_proc(mygmp, "int_tdiv_q", {C_POINTER, C_POINTER, C_POINTER})
xint_tdiv_r = define_c_proc(mygmp, "int_tdiv_r", {C_POINTER, C_POINTER, C_POINTER})
xint_tdiv_qr = define_c_proc(mygmp, "int_tdiv_qr", {C_POINTER, C_POINTER, C_POINTER, C_POINTER})
xint_tdiv_q_ui = define_c_func(mygmp, "int_tdiv_q_ui", {C_POINTER, C_POINTER, C_ULONG}, C_ULONG)
xint_tdiv_r_ui = define_c_func(mygmp, "int_tdiv_r_ui", {C_POINTER, C_POINTER, C_ULONG}, C_ULONG)
xint_tdiv_qr_ui = define_c_func(mygmp, "int_tdiv_qr_ui", {C_POINTER, C_POINTER, C_POINTER, C_ULONG}, C_ULONG)
xint_tdiv_ui = define_c_func(mygmp, "int_tdiv_ui", {C_POINTER, C_ULONG}, C_ULONG)
xint_tdiv_q_2exp = define_c_proc(mygmp, "int_tdiv_q_2exp", {C_POINTER, C_POINTER, C_ULONG})
xint_tdiv_r_2exp = define_c_proc(mygmp, "int_tdiv_r_2exp", {C_POINTER, C_POINTER, C_ULONG})
xint_mod = define_c_proc(mygmp, "int_mod", {C_POINTER, C_POINTER, C_POINTER})
xint_mod_ui = define_c_func(mygmp, "int_mod_ui", {C_POINTER, C_POINTER, C_ULONG}, C_ULONG)
xint_divexact = define_c_proc(mygmp, "int_divexact", {C_POINTER, C_POINTER, C_POINTER})
xint_divexact_ui = define_c_proc(mygmp, "int_divexact_ui", {C_POINTER, C_POINTER, C_ULONG})
xint_divisible_p = define_c_func(mygmp, "int_divisible_p", {C_POINTER, C_POINTER}, C_INT)
xint_divisible_ui_p = define_c_func(mygmp, "int_divisible_ui_p", {C_POINTER, C_ULONG}, C_INT)
xint_divisible_2exp_p = define_c_func(mygmp, "int_divisible_2exp_p", {C_POINTER, C_ULONG}, C_INT)
xint_congruent_p = define_c_func(mygmp, "int_congruent_p", {C_POINTER, C_POINTER, C_POINTER}, C_INT)
xint_congruent_ui_p = define_c_func(mygmp, "int_congruent_ui_p", {C_POINTER, C_ULONG, C_ULONG}, C_INT)
xint_congruent_2exp_p = define_c_func(mygmp, "int_congruent_2exp_p", {C_POINTER, C_POINTER, C_ULONG}, C_INT)
xint_powm = define_c_proc(mygmp, "int_powm", {C_POINTER, C_POINTER, C_POINTER, C_POINTER})
xint_powm_ui = define_c_proc(mygmp, "int_powm_ui", {C_POINTER, C_POINTER, C_ULONG, C_POINTER})
xint_powm_sec = define_c_proc(mygmp, "int_powm_sec", {C_POINTER, C_POINTER, C_POINTER, C_POINTER})
xint_pow_ui = define_c_proc(mygmp, "int_pow_ui", {C_POINTER, C_POINTER, C_ULONG})
xint_ui_pow_ui = define_c_proc(mygmp, "int_ui_pow_ui", {C_POINTER, C_ULONG, C_ULONG})
xint_root = define_c_func(mygmp, "int_root", {C_POINTER, C_POINTER, C_ULONG}, C_INT)
xint_rootrem = define_c_proc(mygmp, "int_rootrem", {C_POINTER, C_POINTER, C_POINTER, C_ULONG})
xint_sqrt = define_c_proc(mygmp, "int_sqrt", {C_POINTER, C_POINTER})
xint_sqrtrem = define_c_proc(mygmp, "int_sqrtrem", {C_POINTER, C_POINTER, C_POINTER})
xint_perfect_power_p = define_c_func(mygmp, "int_perfect_power_p", {C_POINTER}, C_INT)
xint_perfect_square_p = define_c_func(mygmp, "int_perfect_square_p", {C_POINTER}, C_INT)

xint_probab_prime_p = define_c_func(mygmp, "int_probab_prime_p", {C_POINTER, C_INT}, C_INT)
xint_nextprime = define_c_proc(mygmp, "int_nextprime", {C_POINTER, C_POINTER})
xint_gcd = define_c_proc(mygmp, "int_gcd", {C_POINTER, C_POINTER, C_POINTER})
xint_gcd_ui = define_c_func(mygmp, "int_gcd_ui", {C_POINTER, C_POINTER, C_ULONG}, C_ULONG)
xint_gcdext = define_c_proc(mygmp, "int_gcdext", {C_POINTER, C_POINTER, C_POINTER, C_POINTER, C_POINTER})
xint_lcm = define_c_proc(mygmp, "int_lcm", {C_POINTER, C_POINTER, C_POINTER})
xint_lcm_ui = define_c_proc(mygmp, "int_lcm_ui", {C_POINTER, C_POINTER, C_ULONG})
xint_invert = define_c_func(mygmp, "int_invert", {C_POINTER, C_POINTER, C_POINTER}, C_INT)
xint_jacobi = define_c_func(mygmp, "int_jacobi", {C_POINTER, C_POINTER}, C_INT)
xint_legendre = define_c_func(mygmp, "int_legendre", {C_POINTER, C_POINTER}, C_INT)
xint_kronecker = define_c_func(mygmp, "int_kronecker", {C_POINTER, C_POINTER}, C_INT)
xint_kronecker_si = define_c_func(mygmp, "int_kronecker_si", {C_POINTER, C_LONG}, C_INT)
xint_kronecker_ui = define_c_func(mygmp, "int_kronecker_ui", {C_POINTER, C_ULONG}, C_INT)
xint_si_kronecker = define_c_func(mygmp, "int_si_kronecker", {C_POINTER, C_POINTER}, C_INT)
xint_ui_kronecker = define_c_func(mygmp, "int_ui_kronecker", {C_POINTER, C_POINTER}, C_INT)
xint_remove = define_c_func(mygmp, "int_remove", {C_POINTER, C_POINTER, C_POINTER}, C_ULONG)
xint_fac_ui = define_c_proc(mygmp, "int_fac_ui", {C_POINTER, C_ULONG})
xint_2fac_ui = define_c_proc(mygmp, "int_2fac_ui", {C_POINTER, C_ULONG})
xint_mfac_uiui = define_c_proc(mygmp, "int_mfac_uiui", {C_POINTER, C_ULONG, C_ULONG})
xint_primorial_ui = define_c_proc(mygmp, "int_primorial_ui", {C_POINTER, C_ULONG})
xint_bin_ui = define_c_proc(mygmp, "int_bin_ui", {C_POINTER, C_POINTER, C_ULONG})
xint_bin_uiui = define_c_proc(mygmp, "int_bin_uiui", {C_POINTER, C_ULONG, C_ULONG})
xint_fib_ui = define_c_proc(mygmp, "int_fib_ui", {C_POINTER, C_ULONG})
xint_fib2_ui = define_c_proc(mygmp, "int_fib2_ui", {C_POINTER, C_POINTER, C_ULONG})
xint_lucnum_ui = define_c_proc(mygmp, "int_lucnum_ui", {C_POINTER, C_ULONG})
xint_lucnum2_ui = define_c_proc(mygmp, "int_lucnum2_ui", {C_POINTER, C_POINTER, C_ULONG})

xint_cmp = define_c_func(mygmp, "int_cmp", {C_POINTER, C_POINTER}, C_INT)
xint_cmp_d = define_c_func(mygmp, "int_cmp_d", {C_POINTER, C_DOUBLE}, C_INT)
xint_cmp_si = define_c_func(mygmp, "int_cmp_si", {C_POINTER, C_LONG}, C_INT)
xint_cmp_ui = define_c_func(mygmp, "int_cmp_ui", {C_POINTER, C_ULONG}, C_INT)
xint_cmpabs = define_c_func(mygmp, "int_cmpabs", {C_POINTER, C_POINTER}, C_INT)
xint_cmpabs_d = define_c_func(mygmp, "int_cmpabs_d", {C_POINTER, C_DOUBLE}, C_INT)
xint_cmpabs_ui = define_c_func(mygmp, "int_cmpabs_ui", {C_POINTER, C_ULONG}, C_INT)
xint_sgn = define_c_func(mygmp, "int_sgn", {C_POINTER}, C_INT)
xint_and = define_c_proc(mygmp, "int_and", {C_POINTER, C_POINTER, C_POINTER})
xint_ior = define_c_proc(mygmp, "int_ior", {C_POINTER, C_POINTER, C_POINTER})
xint_xor = define_c_proc(mygmp, "int_xor", {C_POINTER, C_POINTER, C_POINTER})
xint_com = define_c_proc(mygmp, "int_com", {C_POINTER, C_POINTER})
xint_popcount = define_c_func(mygmp, "int_popcount", {C_POINTER}, C_ULONG)
xint_hamdist = define_c_func(mygmp, "int_hamdist", {C_POINTER, C_POINTER}, C_ULONG)
xint_scan0 = define_c_func(mygmp, "int_scan0", {C_POINTER, C_ULONG}, C_ULONG)
xint_scan1 = define_c_func(mygmp, "int_scan1", {C_POINTER, C_ULONG}, C_ULONG)
xint_setbit = define_c_proc(mygmp, "int_setbit", {C_POINTER, C_ULONG})
xint_clrbit = define_c_proc(mygmp, "int_clrbit", {C_POINTER, C_ULONG})
xint_combit = define_c_proc(mygmp, "int_combit", {C_POINTER, C_ULONG})
xint_tstbit = define_c_func(mygmp, "int_tstbit", {C_POINTER, C_ULONG}, C_INT)

xint_out_str_filename = define_c_func(mygmp, "int_out_str_filename", {C_POINTER, C_INT, C_POINTER}, C_SIZE_T)
xint_inp_str_filename = define_c_func(mygmp, "int_inp_str_filename", {C_POINTER, C_POINTER, C_INT}, C_SIZE_T)
xint_out_raw_filename = define_c_func(mygmp, "int_out_raw_filename", {C_POINTER, C_POINTER}, C_SIZE_T)
xint_inp_raw_filename = define_c_func(mygmp, "int_inp_raw_filename", {C_POINTER, C_POINTER}, C_SIZE_T)

xint_import = define_c_proc(mygmp, "int_import", {C_POINTER, C_SIZE_T, C_INT, C_SIZE_T, C_INT, C_SIZE_T, C_POINTER})
xint_export = define_c_func(mygmp, "int_export", {C_POINTER, C_POINTER, C_INT, C_SIZE_T, C_INT, C_SIZE_T, C_POINTER}, C_POINTER)

xint_urandomb = define_c_proc(mygmp, "int_urandomb", {C_POINTER, C_POINTER, C_ULONG})
xint_urandomm = define_c_proc(mygmp, "int_urandomm", {C_POINTER, C_POINTER, C_POINTER})
xint_rrandomb = define_c_proc(mygmp, "int_rrandomb", {C_POINTER, C_POINTER, C_ULONG})
xint_random = define_c_proc(mygmp, "int_random", {C_POINTER, C_LONG})
xint_random2 = define_c_proc(mygmp, "int_random2", {C_POINTER, C_LONG})
xsizeof_randstate = define_c_func(mygmp, "sizeof_randstate", {}, C_SIZE_T)
xint_randinit_default = define_c_proc(mygmp, "int_randinit_default", {C_POINTER})
xint_randinit_mt = define_c_proc(mygmp, "int_randinit_mt", {C_POINTER})
xint_randinit_lc_2exp = define_c_proc(mygmp, "int_randinit_lc_2exp", {C_POINTER, C_POINTER, C_ULONG, C_ULONG})
xint_randinit_lc_2exp_size = define_c_func(mygmp, "int_randinit_lc_2exp_size", {C_POINTER, C_ULONG}, C_INT)
xint_randinit_set = define_c_proc(mygmp, "int_randinit_set", {C_POINTER, C_POINTER})
xint_randclear = define_c_proc(mygmp, "int_randclear", {C_POINTER})
xint_randseed = define_c_proc(mygmp, "int_randseed", {C_POINTER, C_POINTER})
xint_randseed_ui = define_c_proc(mygmp, "int_randseed_ui", {C_POINTER, C_ULONG})
xint_urandomb_ui = define_c_func(mygmp, "int_urandomb_ui", {C_POINTER, C_ULONG}, C_ULONG)
xint_urandomm_ui = define_c_func(mygmp, "int_urandomm_ui", {C_POINTER, C_ULONG}, C_ULONG)

xint_fits_ulong_p = define_c_func(mygmp, "int_fits_ulong_p", {C_POINTER}, C_INT)
xint_fits_slong_p = define_c_func(mygmp, "int_fits_slong_p", {C_POINTER}, C_INT)
xint_fits_uint_p = define_c_func(mygmp, "int_fits_uint_p", {C_POINTER}, C_INT)
xint_fits_sint_p = define_c_func(mygmp, "int_fits_sint_p", {C_POINTER}, C_INT)
xint_fits_ushort_p = define_c_func(mygmp, "int_fits_ushort_p", {C_POINTER}, C_INT)
xint_fits_sshort_p = define_c_func(mygmp, "int_fits_sshort_p", {C_POINTER}, C_INT)
xint_odd_p = define_c_func(mygmp, "int_odd_p", {C_POINTER}, C_INT)
xint_even_p = define_c_func(mygmp, "int_even_p", {C_POINTER}, C_INT)
xint_sizeinbase = define_c_func(mygmp, "int_sizeinbase", {C_POINTER, C_INT}, C_SIZE_T)

-- xallocate_q = define_c_func(mygmp, "allocate_q", {}, C_POINTER)
xregister_q = define_c_proc(mygmp, "register_q", {C_POINTER})
xclear_q = define_c_proc(mygmp, "clear_q", {C_POINTER})
xq_set = define_c_proc(mygmp, "q_set", {C_POINTER, C_POINTER})
xq_set_str = define_c_func(mygmp, "q_set_str", {C_POINTER, C_POINTER, C_INT}, C_INT)
xq_get_str = define_c_func(mygmp, "q_get_str", {C_POINTER, C_INT, C_POINTER}, C_POINTER)
xq_swap = define_c_proc(mygmp, "q_swap", {C_POINTER, C_POINTER})
xq_add = define_c_proc(mygmp, "q_add", {C_POINTER, C_POINTER, C_POINTER})
xq_sub = define_c_proc(mygmp, "q_sub", {C_POINTER, C_POINTER, C_POINTER})
xq_mul = define_c_proc(mygmp, "q_mul", {C_POINTER, C_POINTER, C_POINTER})
xq_div = define_c_proc(mygmp, "q_div", {C_POINTER, C_POINTER, C_POINTER})
xq_neg = define_c_proc(mygmp, "q_neg", {C_POINTER, C_POINTER})
xq_abs = define_c_proc(mygmp, "q_abs", {C_POINTER, C_POINTER})
xq_inv = define_c_proc(mygmp, "q_inv", {C_POINTER, C_POINTER})
xq_cmp = define_c_func(mygmp, "q_cmp", {C_POINTER, C_POINTER}, C_INT)
xq_equal = define_c_func(mygmp, "q_equal", {C_POINTER, C_POINTER}, C_INT)
xq_get_num = define_c_proc(mygmp, "q_get_num", {C_POINTER, C_POINTER})
xq_get_den = define_c_proc(mygmp, "q_get_den", {C_POINTER, C_POINTER})
xq_set_num = define_c_proc(mygmp, "q_set_num", {C_POINTER, C_POINTER})
xq_set_den = define_c_proc(mygmp, "q_set_den", {C_POINTER, C_POINTER})
xfloat_set_default_prec = define_c_proc(mygmp, "float_set_default_prec", {C_ULONG})
xfloat_get_default_prec = define_c_func(mygmp, "float_get_default_prec", {}, C_ULONG)
-- xallocate_float = define_c_func(mygmp, "allocate_float", {}, C_POINTER)
xregister_float = define_c_proc(mygmp, "register_float", {C_POINTER})
xregister_float2 = define_c_proc(mygmp, "register_float2", {C_POINTER, C_ULONG})
xclear_float = define_c_proc(mygmp, "clear_float", {C_POINTER})
xfloat_get_prec = define_c_func(mygmp, "float_get_prec", {C_POINTER}, C_ULONG)
xfloat_set_prec = define_c_proc(mygmp, "float_set_prec", {C_POINTER, C_ULONG})
xfloat_set = define_c_proc(mygmp, "float_set", {C_POINTER, C_POINTER})
xfloat_set_str = define_c_func(mygmp, "float_set_str", {C_POINTER, C_POINTER, C_INT}, C_INT)
xfloat_get_str = define_c_func(mygmp, "float_get_str", {C_POINTER, C_POINTER, C_INT, C_SIZE_T, C_POINTER}, C_POINTER)
xfloat_swap = define_c_proc(mygmp, "float_swap", {C_POINTER, C_POINTER})
xfloat_add = define_c_proc(mygmp, "float_add", {C_POINTER, C_POINTER, C_POINTER})
xfloat_sub = define_c_proc(mygmp, "float_sub", {C_POINTER, C_POINTER, C_POINTER})
xfloat_mul = define_c_proc(mygmp, "float_mul", {C_POINTER, C_POINTER, C_POINTER})
xfloat_div = define_c_proc(mygmp, "float_div", {C_POINTER, C_POINTER, C_POINTER})
xfloat_sqrt = define_c_proc(mygmp, "float_sqrt", {C_POINTER, C_POINTER})
xfloat_sqrt_ui = define_c_proc(mygmp, "float_sqrt_ui", {C_POINTER, C_ULONG})
xfloat_pow_ui = define_c_proc(mygmp, "float_pow_ui", {C_POINTER, C_POINTER, C_ULONG})
xfloat_neg = define_c_proc(mygmp, "float_neg", {C_POINTER, C_POINTER})
xfloat_abs = define_c_proc(mygmp, "float_abs", {C_POINTER, C_POINTER})
xfloat_cmp = define_c_func(mygmp, "float_cmp", {C_POINTER, C_POINTER}, C_INT)
xfloat_reldiff = define_c_proc(mygmp, "float_reldiff", {C_POINTER, C_POINTER, C_POINTER})
xfloat_ceil = define_c_proc(mygmp, "float_ceil", {C_POINTER, C_POINTER})
xfloat_floor = define_c_proc(mygmp, "float_floor", {C_POINTER, C_POINTER})
xfloat_trunc = define_c_proc(mygmp, "float_trunc", {C_POINTER, C_POINTER})
xfloat_integer_p = define_c_func(mygmp, "float_integer_p", {C_POINTER}, C_INT)

end procedure
init()

public constant GINT = 1, GQUOT = 2, GFLOAT = 3, GMPFR = 4

public type gint(sequence s)
	if length(s) = 2 then
		if s[1] = GINT then
			return 1
		end if
	end if
	return 0
end type
public type gquot(sequence s)
	if length(s) = 2 then
		if s[1] = GQUOT then
			return 1
		end if
	end if
	return 0
end type
public type gfloat(sequence s)
	if length(s) = 2 then
		if s[1] = GFLOAT then
			return 1
		end if
	end if
	return 0
end type
public type gmpfr(sequence s)
	if length(s) = 2 then
		if s[1] = GMPFR then
			return 1
		end if
	end if
	return 0
end type



public procedure generic_free(atom a)
	c_proc(xgeneric_free, {a})
end procedure


public function csizeof_int()
	return sizeof_int
	-- return c_func(xsizeof_int, {})
end function
public function csizeof_q()
	return sizeof_q
	-- return c_func(xsizeof_q, {})
end function
public function csizeof_float()
	return sizeof_float
	-- return c_func(xsizeof_float, {})
end function
-- extern size_t sizeof_f();
public function csizeof_f()
	return sizeof_f
	-- return c_func(xsizeof_f, {})
end function


-- extern void f_set_default_prec(long prec);
public procedure f_set_default_prec(atom prec)
	c_proc(xf_set_default_prec, {prec})
end procedure
-- extern long f_get_default_prec();
public function f_get_default_prec()
	return c_func(xf_get_default_prec, {})
end function


-- extern void * allocate_f();
function allocate_f()
	return allocate_data(sizeof_f)
	-- return c_func(xallocate_f, {})
end function
-- extern void register_f(void * p);
procedure register_f(atom a)
	c_proc(xregister_f, {a})
end procedure
-- extern void register_f2(void * p, long prec);
procedure register_f2(atom a, atom b)
	c_proc(xregister_f2, {a, b})
end procedure
-- extern void clear_f(void * p);
procedure clear_f(atom a)
	c_proc(xclear_f, {a})
end procedure

-- extern void clear_f_cache();
public procedure clear_f_cache()
	c_proc(xclear_f_cache, {})
end procedure

public function new_f()
	atom ma
	ma = allocate_f()
	register_f(ma)
	return {GMPFR, ma}
end function
public function new_f2(atom prec)
	atom ma
	ma = allocate_f()
	register_f2(ma, prec)
	return {GMPFR, ma}
end function
public procedure delete_f(gmpfr a)
	clear_f(a[2])
	free(a[2])
end procedure

-- extern long f_get_prec(void * p);
public function f_get_prec(gmpfr a)
	return c_func(xf_get_prec, {a[2]})
end function
-- extern void f_set_prec(void * p, long prec);
public procedure f_set_prec(gmpfr a, atom prec)
	c_proc(xf_set_prec, {a[2], prec})
end procedure

-- extern int f_set(void * p, void * op, int rnd); // mpfr_rnd_t rnd
public procedure f_set(gmpfr a, gmpfr b)
	c_proc(xf_set, {a[2], b[2]})
end procedure

-- extern int f_set_ui(void * p, unsigned long int op, int rnd);
public function f_set_ui(gmpfr a, atom op, integer rnd)
	return c_func(xf_set_ui, {a[2], op, rnd})
end function
-- extern int f_set_si(void * p, long int op, int rnd);
public function f_set_si(gmpfr a, atom op, integer rnd)
	return c_func(xf_set_si, {a[2], op, rnd})
end function
-- -- extern int f_set_uj(void * p, unsigned long long op, int rnd);
-- -- extern int f_set_sj(void * p, long long op, int rnd);
-- -- extern int f_set_flt(void * p, float op, int rnd);
-- extern int f_set_d(void * p, double op, int rnd);
public function f_set_d(gmpfr a, atom op, integer rnd)
	return c_func(xf_set_d, {a[2], op, rnd})
end function
-- -- extern int f_set_ld(void * p, long double op, int rnd); // "long double" is "double" on Microsoft's compiler
-- extern int f_set_int(void * p, void * op1, int rnd);
public function f_set_int(gmpfr a, gint b, integer rnd)
	return c_func(xf_set_int, {a[2], b[2], rnd})
end function
-- extern int f_set_q(void * p, void * op1, int rnd);
public function f_set_q(gmpfr a, gquot b, integer rnd)
	return c_func(xf_set_q, {a[2], b[2], rnd})
end function
-- extern int f_set_float(void * p, void * op1, int rnd);
public function f_set_float(gmpfr a, gfloat b, integer rnd)
	return c_func(xf_set_float, {a[2], b[2], rnd})
end function
-- extern int f_set_ui_2exp(void * p, unsigned long int op, long e, int rnd);
public function f_set_ui_2exp(gmpfr a, atom op, atom e, integer rnd)
	return c_func(xf_set_ui_2exp, {a[2], op, e, rnd})
end function
-- extern int f_set_si_2exp(void * p, long int op, long e, int rnd);
public function f_set_si_2exp(gmpfr a, atom op, atom e, integer rnd)
	return c_func(xf_set_si_2exp, {a[2], op, e, rnd})
end function
-- -- extern int f_set_uj_2exp(void * p, unsigned long long op, long long e, int rnd);
-- -- extern int f_set_sj_2exp(void * p, long long op, long long e, int rnd);
-- extern int f_set_int_2exp(void * p, void * op, long e, int rnd);
public function f_set_int_2exp(gmpfr a, gint b, atom e, integer rnd)
	return c_func(xf_set_int_2exp, {a[2], b[2], e, rnd})
end function
-- extern int f_set_str(void * p, const char *s, int base, int rnd);
function f_set_str(atom a, atom b, atom c, atom d)
	return c_func(xf_set_str, {a, b, c, d})
end function
public function f_set_string(gmpfr a, sequence st, integer base, integer rnd)
	atom str, ret
	str = allocate_string(st)
	ret = f_set_str(a[2], str, base, rnd)
	free(str)
	return ret
end function
-- -- extern int f_strtofr(void * p, const char *nptr, char **endptr, int base, int rnd);
-- extern void f_set_nan(void * p);
public function f_set_nan(gmpfr a)
	return c_func(xf_set_nan, {a[2]})
end function
-- extern void f_set_inf(void * p, int sign);
public function f_set_inf(gmpfr a, integer sign)
	return c_func(xf_set_inf, {a[2], sign})
end function
-- extern void f_set_zero(void * p, int sign);
public function f_set_zero(gmpfr a, integer sign)
	return c_func(xf_set_zero, {a[2], sign})
end function

-- extern void f_swap(void * x, void * y); // should be faster than other ways of doing it
public procedure f_swap(gmpfr a, gmpfr b)
	c_proc(xf_swap, {a[2], b[2]})
end procedure

--// Initialize x and set its value from the string s in base base, rounded in the direction rnd
-- extern int f_init_set_str(void * p, const char *s, int base, int rnd);

-- extern float f_get_flt(void * p, int rnd);
public function f_get_flt(gmpfr a, integer rnd)
	return c_func(xf_get_flt, {a[2], rnd})
end function
-- extern double f_get_d(void * p, int rnd);
public function f_get_d(gmpfr a, integer rnd)
	return c_func(xf_get_d, {a[2], rnd})
end function
-- -- extern long double f_get_ld(void * p, int rnd); // "long double" is "double" on Microsoft's compiler
-- extern long f_get_si(void * p, int rnd);
public function f_get_si(gmpfr a, integer rnd)
	return c_func(xf_get_si, {a[2], rnd})
end function
-- extern unsigned long f_get_ui(void * p, int rnd);
public function f_get_ui(gmpfr a, integer rnd)
	return c_func(xf_get_ui, {a[2], rnd})
end function
-- -- extern long long f_get_sj(void * p, int rnd);
-- -- extern unsigned long long f_get_uj(void * p, int rnd);
-- extern double f_get_d_2exp(long *exp, void * p, int rnd);
public function f_get_d_2exp(gmpfr a, integer rnd)
	atom ma, d, exp
	sequence ret
	ma = allocate_data(4) -- for 32-bit platforms
	d = c_func(xf_get_d_2exp, {ma, a[2], rnd})
	exp = peek4s(ma)
	free(ma)
	ret = {d, exp}
	return ret
end function
-- -- extern long double f_get_ld_2exp(long *exp, void * p, int rnd); // "long double" is "double" on Microsoft's compiler
-- extern int f_frexp(long *exp, void * y, void * x, int rnd);
public function f_frexp(gmpfr y, gmpfr x, integer rnd)
	atom ma, d, exp
	sequence ret
	ma = allocate_data(4) -- for 32-bit platforms
	d = c_func(xf_frexp, {ma, y[2], x[2], rnd})
	exp = peek4s(ma)
	free(ma)
	ret = {d, exp}
	return ret
end function
-- extern long f_get_int_2exp(void * r, void * p);
public function f_get_int_2exp(gint r, gmpfr a)
	return c_func(xf_get_int_2exp, {r[2], a[2]})
end function
-- extern int f_get_int(void * r, void * p, int rnd);
public function f_get_int(gint r, gmpfr a, integer rnd)
	return c_func(xf_get_int, {r[2], a[2], rnd})
end function
-- extern void f_get_q(void * r, void * p);
--public procedure f_get_q(gquot r, gmpfr a)
--      c_proc(xf_get_q, {r[2], a[2]})
--end procedure
-- extern int f_get_float(void * r, void * p, int rnd);
public function f_get_float(gfloat r, gmpfr a, integer rnd)
	return c_func(xf_get_float, {r[2], a[2], rnd})
end function


-- extern char * f_get_str(char *str, long *expptr, int b, size_t n, void * p, int rnd);
function f_get_str(atom str, atom ma_exp, integer b, integer n, atom p, integer rnd)
	return c_func(xf_get_str, {str, ma_exp, b, n, p, rnd})
end function
-- extern void f_free_str(char *str);
procedure f_free_str(atom ma_str)
	c_proc(xf_free_str, {ma_str})
end procedure
public function f_get_string(integer base, atom n_digits, gint a, integer rnd)
	atom str, expptr, exponent
	sequence st
	expptr = allocate_data(4) -- pointer to an int or long int
	str = f_get_str(NULL, expptr, base, n_digits, a[2], rnd)
	exponent = peek4s(expptr)
	free(expptr)
	st = peek_string(str)
	f_free_str(str)
	return {st, exponent}
end function

-- extern int f_fits_ulong_p(void * p, int rnd);
public function f_fits_ulong_p(gmpfr a, integer rnd)
	return c_func(xf_fits_ulong_p, {a[2], rnd})
end function
-- extern int f_fits_slong_p(void * p, int rnd);
public function f_fits_slong_p(gmpfr a, integer rnd)
	return c_func(xf_fits_slong_p, {a[2], rnd})
end function
-- extern int f_fits_uint_p(void * p, int rnd);
public function f_fits_uint_p(gmpfr a, integer rnd)
	return c_func(xf_fits_uint_p, {a[2], rnd})
end function
-- extern int f_fits_sint_p(void * p, int rnd);
public function f_fits_sint_p(gmpfr a, integer rnd)
	return c_func(xf_fits_sint_p, {a[2], rnd})
end function
-- extern int f_fits_ushort_p(void * p, int rnd);
public function f_fits_ushort_p(gmpfr a, integer rnd)
	return c_func(xf_fits_ushort_p, {a[2], rnd})
end function
-- extern int f_fits_sshort_p(void * p, int rnd);
public function f_fits_sshort_p(gmpfr a, integer rnd)
	return c_func(xf_fits_sshort_p, {a[2], rnd})
end function
-- extern int f_fits_uintmax_p(void * p, int rnd);
public function f_fits_uintmax_p(gmpfr a, integer rnd)
	return c_func(xf_fits_uintmax_p, {a[2], rnd})
end function
-- extern int f_fits_intmax_p(void * p, int rnd);
public function f_fits_intmax_p(gmpfr a, integer rnd)
	return c_func(xf_fits_intmax_p, {a[2], rnd})
end function

-- extern int f_add(void * r, void * p, void * op, int rnd);
public function f_add(gmpfr r, gmpfr a, gmpfr b, integer rnd)
	return c_func(xf_add, {r[2], a[2], b[2], rnd})
end function
-- extern int f_add_ui(void * r, void * p, unsigned long int op2, int rnd);
public function f_add_ui(gmpfr r, gmpfr a, atom op, integer rnd)
	return c_func(xf_add_ui, {r[2], a[2], op, rnd})
end function
-- extern int f_add_si(void * r, void * p, long int op2, int rnd);
public function f_add_si(gmpfr r, gmpfr a, atom op, integer rnd)
	return c_func(xf_add_si, {r[2], a[2], op, rnd})
end function
-- extern int f_add_d(void * r, void * p, double op2, int rnd);
public function f_add_d(gmpfr r, gmpfr a, atom op, integer rnd)
	return c_func(xf_add_d, {r[2], a[2], op, rnd})
end function
-- extern int f_add_int(void * r, void * p, void * op2, int rnd);
public function f_add_int(gmpfr r, gmpfr p, gint op, integer rnd)
	return c_func(xf_add_int, {r[2], p[2], op[2], rnd})
end function
-- extern int f_add_q(void * r, void * p, void * op2, int rnd);
public function f_add_q(gmpfr r, gmpfr p, gquot op, integer rnd)
	return c_func(xf_add_q, {r[2], p[2], op[2], rnd})
end function

-- extern int f_sub(void * r, void * op1, void * op2, int rnd);
public function f_sub(gmpfr r, gmpfr op1, gmpfr op2, integer rnd)
	return c_func(xf_sub, {r[2], op1[2], op2[2], rnd})
end function
-- extern int f_ui_sub(void * r, unsigned long int op1, void * op2, int rnd);
public function f_ui_sub(gmpfr r, atom op1, gmpfr op2, integer rnd)
	return c_func(xf_ui_sub, {r[2], op1, op2[2], rnd})
end function
-- extern int f_sub_ui(void * r, void * op1, unsigned long int op2, int rnd);
public function f_sub_ui(gmpfr r, gmpfr op1, atom op2, integer rnd)
	return c_func(xf_sub_ui, {r[2], op1[2], op2, rnd})
end function
-- extern int f_si_sub(void * r, long int op1, void * op2, int rnd);
public function f_si_sub(gmpfr r, atom op1, gmpfr op2, integer rnd)
	return c_func(xf_si_sub, {r[2], op1, op2[2], rnd})
end function
-- extern int f_sub_si(void * r, void * op1, long int op2, int rnd);
public function f_sub_si(gmpfr r, gmpfr op1, atom op2, integer rnd)
	return c_func(xf_sub_si, {r[2], op1[2], op2, rnd})
end function
-- extern int f_d_sub(void * r, double op1, void * op2, int rnd);
public function f_d_sub(gmpfr r, atom op1, gmpfr op2, integer rnd)
	return c_func(xf_d_sub, {r[2], op1, op2[2], rnd})
end function
-- extern int f_sub_d(void * r, void * op1, double op2, int rnd);
public function f_sub_d(gmpfr r, gmpfr op1, atom op2, integer rnd)
	return c_func(xf_sub_d, {r[2], op1[2], op2, rnd})
end function
-- extern int f_int_sub(void * r, void * op1, void * op2, int rnd);
public function f_int_sub(gmpfr r, gint op1, gmpfr op2, integer rnd)
	return c_func(xf_int_sub, {r[2], op1[2], op2[2], rnd})
end function
-- extern int f_sub_int(void * r, void * op1, void * op2, int rnd);
public function f_sub_int(gmpfr r, gmpfr op1, gint op2, integer rnd)
	return c_func(xf_sub_int, {r[2], op1[2], op2[2], rnd})
end function
-- extern int f_sub_q(void * r, void * op1, void * op2, int rnd);
public function f_sub_q(gmpfr r, gmpfr op1, gquot op2, integer rnd)
	return c_func(xf_sub_q, {r[2], op1[2], op2[2], rnd})
end function
-- extern int f_mul(void * r, void * p, void * op, int rnd);
public function f_mul(gmpfr r, gmpfr op1, gmpfr op2, integer rnd)
	return c_func(xf_mul, {r[2], op1[2], op2[2], rnd})
end function
-- extern int f_mul_ui(void * r, void * p, unsigned long int op2, int rnd);
public function f_mul_ui(gmpfr r, gmpfr op1, atom op2, integer rnd)
	return c_func(xf_mul_ui, {r[2], op1[2], op2, rnd})
end function
-- extern int f_mul_si(void * r, void * p, long int op2, int rnd);
public function f_mul_si(gmpfr r, gmpfr op1, atom op2, integer rnd)
	return c_func(xf_mul_si, {r[2], op1[2], op2, rnd})
end function
-- extern int f_mul_d(void * r, void * p, double op2, int rnd);
public function f_mul_d(gmpfr r, gmpfr op1, atom op2, integer rnd)
	return c_func(xf_mul_d, {r[2], op1[2], op2, rnd})
end function
-- extern int f_mul_int(void * r, void * p, void * op2, int rnd);
public function f_mul_int(gmpfr r, gmpfr op1, gint op2, integer rnd)
	return c_func(xf_mul_int, {r[2], op1[2], op2[2], rnd})
end function
-- extern int f_mul_q(void * r, void * p, void * op2, int rnd);
public function f_mul_q(gmpfr r, gmpfr op1, gquot op2, integer rnd)
	return c_func(xf_mul_q, {r[2], op1[2], op2[2], rnd})
end function
--// "f_sqr": Not to be confused with "sqrt", Set rop to op^2 rounded in the direction rnd:
-- extern int f_sqr(void * r, void * p, int rnd);
public function f_sqr(gmpfr r, gmpfr p, integer rnd)
	return c_func(xf_sqr, {r[2], p[2], rnd})
end function
-- extern int f_div(void * r, void * op1, void * op2, int rnd);
public function f_div(gmpfr r, gmpfr op1, gmpfr op2, integer rnd)
	return c_func(xf_div, {r[2], op1[2], op2[2], rnd})
end function
-- extern int f_ui_div(void * r, unsigned long int op1, void * op2, int rnd);
public function f_ui_div(gmpfr r, atom op1, gmpfr op2, integer rnd)
	return c_func(xf_ui_div, {r[2], op1, op2[2], rnd})
end function
-- extern int f_div_ui(void * r, void * op1, unsigned long int op2, int rnd);
public function f_div_ui(gmpfr r, gmpfr op1, atom op2, integer rnd)
	return c_func(xf_div_ui, {r[2], op1[2], op2, rnd})
end function
-- extern int f_si_div(void * r, long int op1, void * op2, int rnd);
public function f_si_div(gmpfr r, atom op1, gmpfr op2, integer rnd)
	return c_func(xf_si_div, {r[2], op1, op2[2], rnd})
end function
-- extern int f_div_si(void * r, void * op1, long int op2, int rnd);
public function f_div_si(gmpfr r, gmpfr op1, atom op2, integer rnd)
	return c_func(xf_div_si, {r[2], op1[2], op2, rnd})
end function
-- extern int f_d_div(void * r, double op1, void * op2, int rnd);
public function f_d_div(gmpfr r, atom op1, gmpfr op2, integer rnd)
	return c_func(xf_d_div, {r[2], op1, op2[2], rnd})
end function
-- extern int f_div_d(void * r, void * op1, double op2, int rnd);
public function f_div_d(gmpfr r, gmpfr op1, atom op2, integer rnd)
	return c_func(xf_div_d, {r[2], op1[2], op2, rnd})
end function
-- extern int f_div_int(void * r, void * p, void * op2, int rnd);
public function f_div_int(gmpfr r, gmpfr op1, gint op2, integer rnd)
	return c_func(xf_div_int, {r[2], op1[2], op2[2], rnd})
end function
-- extern int f_div_q(void * r, void * p, void * op2, int rnd);
public function f_div_q(gmpfr r, gmpfr op1, gquot op2, integer rnd)
	return c_func(xf_div_q, {r[2], op1[2], op2[2], rnd})
end function
-- extern int f_sqrt(void * r, void * p, int rnd);
public function f_sqrt(gmpfr r, gmpfr p, integer rnd)
	return c_func(xf_sqrt, {r[2], p[2], rnd})
end function
-- extern int f_sqrt_ui(void * r, unsigned long int op, int rnd);
public function f_sqrt_ui(gmpfr r, atom op, integer rnd)
	return c_func(xf_sqrt_ui, {r[2], op, rnd})
end function
-- extern int f_rec_sqrt(void * r, void * p, int rnd);
public function f_rec_sqrt(gmpfr r, gmpfr p, integer rnd)
	return c_func(xf_rec_sqrt, {r[2], p[2], rnd})
end function
-- extern int f_cbrt(void * r, void * p, int rnd);
public function f_cbrt(gmpfr r, gmpfr p, integer rnd)
	return c_func(xf_cbrt, {r[2], p[2], rnd})
end function
-- extern int f_rootn_ui(void * r, void * p, unsigned long int k, int rnd);
--public function f_rootn_ui(gmpfr r, gmpfr p, atom k, integer rnd)
--      return c_func(xf_rootn_ui, {r[2], p[2], k, rnd})
--end function
-- extern int f_root(void * r, void * p, unsigned long int k, int rnd);
public function f_root(gmpfr r, gmpfr p, atom k, integer rnd)
	return c_func(xf_root, {r[2], p[2], k, rnd})
end function
-- extern int f_pow(void * r, void * p, void * op, int rnd);
public function f_pow(gmpfr r, gmpfr p, gmpfr op, integer rnd)
	return c_func(xf_pow, {r[2], p[2], op[2], rnd})
end function
-- extern int f_pow_ui(void * r, void * p, unsigned long int op2, int rnd);
public function f_pow_ui(gmpfr r, gmpfr p, atom op, integer rnd)
	return c_func(xf_pow_ui, {r[2], p[2], op, rnd})
end function
-- extern int f_pow_si(void * r, void * p, long int op2, int rnd);
public function f_pow_si(gmpfr r, gmpfr p, atom op, integer rnd)
	return c_func(xf_pow_si, {r[2], p[2], op, rnd})
end function
-- extern int f_pow_int(void * r, void * p, void * op2, int rnd);
public function f_pow_int(gmpfr r, gmpfr p, gint op, integer rnd)
	return c_func(xf_pow_int, {r[2], p[2], op[2], rnd})
end function
-- extern int f_ui_pow_ui(void * r, unsigned long int op1, unsigned long int op2, int rnd);
public function f_ui_pow_ui(gmpfr r, atom op1, atom op2, integer rnd)
	return c_func(xf_ui_pow_ui, {r[2], op1, op2, rnd})
end function
-- extern int f_ui_pow(void * r, unsigned long int op1, void * op2, int rnd);
public function f_ui_pow(gmpfr r, atom op1, gmpfr op2, integer rnd)
	return c_func(xf_ui_pow, {r[2], op1, op2[2], rnd})
end function
-- extern int f_neg(void * r, void * p, int rnd);
public function f_neg(gmpfr r, gmpfr p, integer rnd)
	return c_func(xf_neg, {r[2], p[2], rnd})
end function
-- extern int f_abs(void * r, void * p, int rnd);
public function f_abs(gmpfr r, gmpfr p, integer rnd)
	return c_func(xf_abs, {r[2], p[2], rnd})
end function
-- extern int f_dim(void * r, void * op1, void * op2, int rnd); // finds the absolute difference between two numbers
public function f_dim(gmpfr r, gmpfr op1, gmpfr op2, integer rnd)
	return c_func(xf_dim, {r[2], op1[2], op2[2], rnd})
end function
-- extern int f_mul_2ui(void * r, void * p, unsigned long int op2, int rnd);
public function f_mul_2ui(gmpfr r, gmpfr p, atom op, integer rnd)
	return c_func(xf_mul_2ui, {r[2], p[2], op, rnd})
end function
-- extern int f_mul_2si(void * r, void * p, long int op2, int rnd);
public function f_mul_2si(gmpfr r, gmpfr p, atom op, integer rnd)
	return c_func(xf_mul_2si, {r[2], p[2], op, rnd})
end function
-- extern int f_div_2ui(void * r, void * p, unsigned long int op2, int rnd);
public function f_div_2ui(gmpfr r, gmpfr p, atom op, integer rnd)
	return c_func(xf_div_2ui, {r[2], p[2], op, rnd})
end function
-- extern int f_div_2si(void * r, void * p, long int op2, int rnd);
public function f_div_2si(gmpfr r, gmpfr p, atom op, integer rnd)
	return c_func(xf_div_2si, {r[2], p[2], op, rnd})
end function
-- extern int f_cmp(void * p, void * op2);
public function f_cmp(gmpfr r, gmpfr op)
	return c_func(xf_cmp, {r[2], op[2]})
end function
-- extern int f_cmp_ui(void * p, unsigned long int op2);
public function f_cmp_ui(gmpfr r, atom op)
	return c_func(xf_cmp_ui, {r[2], op})
end function
-- extern int f_cmp_si(void * p, long int op2);
public function f_cmp_si(gmpfr r, atom op)
	return c_func(xf_cmp_si, {r[2], op})
end function
-- extern int f_cmp_d(void * p, double op2);
public function f_cmp_d(gmpfr r, atom op)
	return c_func(xf_cmp_d, {r[2], op})
end function
--// extern int f_cmp_ld(void * p, long double op2);
-- extern int f_cmp_int(void * p, void * op2);
public function f_cmp_int(gmpfr r, gint op)
	return c_func(xf_cmp_int, {r[2], op[2]})
end function
-- extern int f_cmp_q(void * p, void * op2);
public function f_cmp_q(gmpfr r, gquot op)
	return c_func(xf_cmp_q, {r[2], op[2]})
end function
-- extern int f_cmp_float(void * p, void * op2);
public function f_cmp_float(gmpfr r, gfloat op)
	return c_func(xf_cmp_float, {r[2], op[2]})
end function
-- extern int f_cmp_ui_2exp(void * op1, unsigned long int op2, long e);
public function f_cmp_ui_2exp(gmpfr r, atom op, atom e)
	return c_func(xf_cmp_ui_2exp, {r[2], op, e})
end function
-- extern int f_cmp_si_2exp(void * op1, long int op2, long e);
public function f_cmp_si_2exp(gmpfr r, atom op, atom e)
	return c_func(xf_cmp_si_2exp, {r[2], op, e})
end function
-- extern int f_cmpabs(void * op1, void * op2);
public function f_cmpabs(gmpfr r, gmpfr op)
	return c_func(xf_cmpabs, {r[2], op[2]})
end function
-- extern int f_nan_p(void * op);
public function f_nan_p(gmpfr r)
	return c_func(xf_nan_p, {r[2]})
end function
-- extern int f_inf_p(void * op);
public function f_inf_p(gmpfr r)
	return c_func(xf_inf_p, {r[2]})
end function
-- extern int f_number_p(void * op);
public function f_number_p(gmpfr r)
	return c_func(xf_number_p, {r[2]})
end function
-- extern int f_zero_p(void * op);
public function f_zero_p(gmpfr r)
	return c_func(xf_zero_p, {r[2]})
end function
-- extern int f_regular_p(void * op);
public function f_regular_p(gmpfr r)
	return c_func(xf_regular_p, {r[2]})
end function
-- extern int f_sgn(void * op);
public function f_sgn(gmpfr r)
	return c_func(xf_sgn, {r[2]})
end function
-- extern int f_greater_p(void * op1, void * op2);
public function f_greater_p(gmpfr r, gmpfr op)
	return c_func(xf_greater_p, {r[2], op[2]})
end function
-- extern int f_greaterequal_p(void * op1, void * op2);
public function f_greaterequal_p(gmpfr r, gmpfr op)
	return c_func(xf_greaterequal_p, {r[2], op[2]})
end function
-- extern int f_less_p(void * op1, void * op2);
public function f_less_p(gmpfr r, gmpfr op)
	return c_func(xf_less_p, {r[2], op[2]})
end function
-- extern int f_lessequal_p(void * op1, void * op2);
public function f_lessequal_p(gmpfr r, gmpfr op)
	return c_func(xf_lessequal_p, {r[2], op[2]})
end function
-- extern int f_equal_p(void * op1, void * op2);
public function f_equal_p(gmpfr r, gmpfr op)
	return c_func(xf_equal_p, {r[2], op[2]})
end function
-- extern int f_lessgreater_p(void * op1, void * op2);
public function f_lessgreater_p(gmpfr r, gmpfr op)
	return c_func(xf_lessgreater_p, {r[2], op[2]})
end function
-- extern int f_unordered_p(void * op1, void * op2);
public function f_unordered_p(gmpfr r, gmpfr op)
	return c_func(xf_unordered_p, {r[2], op[2]})
end function
-- extern int f_log(void * r, void * p, int rnd);
public function f_log(gmpfr r, gmpfr p, integer rnd)
	return c_func(xf_log, {r[2], p[2], rnd})
end function
-- extern int f_log_ui(void * r, unsigned long op, int rnd);
--public function f_log_ui(gmpfr r, atom op, integer rnd)
--      return c_func(xf_log_ui, {r[2], op, rnd})
--end function
-- extern int f_log2(void * r, void * p, int rnd);
public function f_log2(gmpfr r, gmpfr p, integer rnd)
	return c_func(xf_log2, {r[2], p[2], rnd})
end function
-- extern int f_log10(void * r, void * p, int rnd);
public function f_log10(gmpfr r, gmpfr p, integer rnd)
	return c_func(xf_log10, {r[2], p[2], rnd})
end function
-- extern int f_log1p(void * r, void * p, int rnd);
public function f_log1p(gmpfr r, gmpfr p, integer rnd)
	return c_func(xf_log1p, {r[2], p[2], rnd})
end function
-- extern int f_exp(void * r, void * p, int rnd);
public function f_exp(gmpfr r, gmpfr p, integer rnd)
	return c_func(xf_exp, {r[2], p[2], rnd})
end function
-- extern int f_exp2(void * r, void * p, int rnd);
public function f_exp2(gmpfr r, gmpfr p, integer rnd)
	return c_func(xf_exp2, {r[2], p[2], rnd})
end function
-- extern int f_exp10(void * r, void * p, int rnd);
public function f_exp10(gmpfr r, gmpfr p, integer rnd)
	return c_func(xf_exp10, {r[2], p[2], rnd})
end function
-- extern int f_expm1(void * r, void * p, int rnd);
public function f_expm1(gmpfr r, gmpfr p, integer rnd)
	return c_func(xf_expm1, {r[2], p[2], rnd})
end function
-- extern int f_cos(void * r, void * p, int rnd);
public function f_cos(gmpfr r, gmpfr p, integer rnd)
	return c_func(xf_cos, {r[2], p[2], rnd})
end function
-- extern int f_sin(void * r, void * p, int rnd);
public function f_sin(gmpfr r, gmpfr p, integer rnd)
	return c_func(xf_sin, {r[2], p[2], rnd})
end function
-- extern int f_tan(void * r, void * p, int rnd);
public function f_tan(gmpfr r, gmpfr p, integer rnd)
	return c_func(xf_tan, {r[2], p[2], rnd})
end function
-- extern int f_sin_cos(void * sop, void * cop, void * op, int rnd);
public function f_sin_cos(gmpfr sop, gmpfr cop, gmpfr p, integer rnd)
	return c_func(xf_sin_cos, {sop[2], cop[2], p[2], rnd})
end function
-- extern int f_sec(void * r, void * p, int rnd);
public function f_sec(gmpfr r, gmpfr p, integer rnd)
	return c_func(xf_sec, {r[2], p[2], rnd})
end function
-- extern int f_csc(void * r, void * p, int rnd);
public function f_csc(gmpfr r, gmpfr p, integer rnd)
	return c_func(xf_csc, {r[2], p[2], rnd})
end function
-- extern int f_cot(void * r, void * p, int rnd);
public function f_cot(gmpfr r, gmpfr p, integer rnd)
	return c_func(xf_cot, {r[2], p[2], rnd})
end function
-- extern int f_acos(void * r, void * p, int rnd);
public function f_acos(gmpfr r, gmpfr p, integer rnd)
	return c_func(xf_acos, {r[2], p[2], rnd})
end function
-- extern int f_asin(void * r, void * p, int rnd);
public function f_asin(gmpfr r, gmpfr p, integer rnd)
	return c_func(xf_asin, {r[2], p[2], rnd})
end function
-- extern int f_atan(void * r, void * p, int rnd);
public function f_atan(gmpfr r, gmpfr p, integer rnd)
	return c_func(xf_atan, {r[2], p[2], rnd})
end function
-- extern int f_atan2(void * rop, void * y, void * x, int rnd);
public function f_atan2(gmpfr r, gmpfr y, gmpfr x, integer rnd)
	return c_func(xf_atan2, {r[2], y[2], x[2], rnd})
end function
-- extern int f_cosh(void * r, void * p, int rnd);
public function f_cosh(gmpfr r, gmpfr p, integer rnd)
	return c_func(xf_cosh, {r[2], p[2], rnd})
end function
-- extern int f_sinh(void * r, void * p, int rnd);
public function f_sinh(gmpfr r, gmpfr p, integer rnd)
	return c_func(xf_sinh, {r[2], p[2], rnd})
end function
-- extern int f_tanh(void * r, void * p, int rnd);
public function f_tanh(gmpfr r, gmpfr p, integer rnd)
	return c_func(xf_tanh, {r[2], p[2], rnd})
end function
-- extern int f_sinh_cosh(void * sop, void * cop, void * op, int rnd);
public function f_sinh_cosh(gmpfr sop, gmpfr cop, gmpfr p, integer rnd)
	return c_func(xf_sinh_cosh, {sop[2], cop[2], p[2], rnd})
end function
-- extern int f_sech(void * r, void * p, int rnd);
public function f_sech(gmpfr r, gmpfr p, integer rnd)
	return c_func(xf_sech, {r[2], p[2], rnd})
end function
-- extern int f_csch(void * r, void * p, int rnd);
public function f_csch(gmpfr r, gmpfr p, integer rnd)
	return c_func(xf_csch, {r[2], p[2], rnd})
end function
-- extern int f_coth(void * r, void * p, int rnd);
public function f_coth(gmpfr r, gmpfr p, integer rnd)
	return c_func(xf_coth, {r[2], p[2], rnd})
end function
-- extern int f_acosh(void * r, void * p, int rnd);
public function f_acosh(gmpfr r, gmpfr p, integer rnd)
	return c_func(xf_acosh, {r[2], p[2], rnd})
end function
-- extern int f_asinh(void * r, void * p, int rnd);
public function f_asinh(gmpfr r, gmpfr p, integer rnd)
	return c_func(xf_asinh, {r[2], p[2], rnd})
end function
-- extern int f_atanh(void * r, void * p, int rnd);
public function f_atanh(gmpfr r, gmpfr p, integer rnd)
	return c_func(xf_atanh, {r[2], p[2], rnd})
end function
-- extern int f_fac_ui(void * rop, unsigned long int op, int rnd);
public function f_fac_ui(gmpfr r, atom op, integer rnd)
	return c_func(xf_fac_ui, {r[2], op, rnd})
end function
-- extern int f_eint(void * r, void * p, int rnd);
public function f_eint(gmpfr r, gmpfr op, integer rnd)
	return c_func(xf_eint, {r[2], op[2], rnd})
end function
-- extern int f_li2(void * r, void * p, int rnd);
public function f_li2(gmpfr r, gmpfr op, integer rnd)
	return c_func(xf_li2, {r[2], op[2], rnd})
end function
-- extern int f_gamma(void * r, void * p, int rnd);
public function f_gamma(gmpfr r, gmpfr op, integer rnd)
	return c_func(xf_gamma, {r[2], op[2], rnd})
end function
-- extern int f_gamma_inc(void * rop, void * op, void * op2, int rnd);
--public function f_gamma_inc(gmpfr r, gmpfr op1, gmpfr op2, integer rnd)
--      return c_func(xf_gamma_inc, {r[2], op1[2], op2[2], rnd})
--end function
-- extern int f_lngamma(void * r, void * p, int rnd);
public function f_lngamma(gmpfr r, gmpfr op, integer rnd)
	return c_func(xf_lngamma, {r[2], op[2], rnd})
end function
-- extern int f_lgamma(void * rop, int *signp, void * op, int rnd);
public function f_lgamma(gmpfr r, gmpfr op, integer rnd)
-- NOTE: Get the "sign" from the return value.
	atom ret, ma_signp, sign
	ma_signp = allocate_data(4)
	ret = c_func(xf_lgamma, {r[2], ma_signp, op[2], rnd})
	sign = peek4s(ma_signp)
	free(ma_signp)
	return {ret, sign}
end function
-- extern int f_digamma(void * r, void * p, int rnd);
public function f_digamma(gmpfr r, gmpfr op, integer rnd)
	return c_func(xf_digamma, {r[2], op[2], rnd})
end function
-- extern int f_beta(void * rop, void * op1, void * op2, int rnd);
--public function f_beta(gmpfr r, gmpfr op1, gmpfr op2, integer rnd)
--      return c_func(xf_beta, {r[2], op1[2], op2[2], rnd})
--end function
-- extern int f_zeta(void * r, void * p, int rnd);
public function f_zeta(gmpfr r, gmpfr op, integer rnd)
	return c_func(xf_zeta, {r[2], op[2], rnd})
end function
-- extern int f_zeta_ui(void * rop, unsigned long op, int rnd);
public function f_zeta_ui(gmpfr r, atom op, integer rnd)
	return c_func(xf_zeta_ui, {r[2], op, rnd})
end function
-- extern int f_erf(void * r, void * p, int rnd);
public function f_erf(gmpfr r, gmpfr op, integer rnd)
	return c_func(xf_erf, {r[2], rnd})
end function
-- extern int f_erfc(void * r, void * p, int rnd);
public function f_erfc(gmpfr r, gmpfr op, integer rnd)
	return c_func(xf_erfc, {r[2], op[2], rnd})
end function
-- extern int f_j0(void * r, void * p, int rnd);
public function f_j0(gmpfr r, gmpfr op, integer rnd)
	return c_func(xf_j0, {r[2], op[2], rnd})
end function
-- extern int f_j1(void * r, void * p, int rnd);
public function f_j1(gmpfr r, gmpfr op, integer rnd)
	return c_func(xf_j1, {r[2], op[2], rnd})
end function
-- extern int f_jn(void * rop, long n, void * op, int rnd);
public function f_jn(gmpfr r, atom n, gmpfr op, integer rnd)
	return c_func(xf_jn, {r[2], n, op[2], rnd})
end function
-- extern int f_y0(void * r, void * p, int rnd);
public function f_y0(gmpfr r, gmpfr op, integer rnd)
	return c_func(xf_y0, {r[2], op[2], rnd})
end function
-- extern int f_y1(void * r, void * p, int rnd);
public function f_y1(gmpfr r, gmpfr op, integer rnd)
	return c_func(xf_y1, {r[2], op[2], rnd})
end function
-- extern int f_yn(void * rop, long n, void * op, int rnd);
public function f_yn(gmpfr r, atom n, gmpfr op, integer rnd)
	return c_func(xf_yn, {r[2], n, op[2], rnd})
end function
-- extern int f_fma(void * rop, void * op1, void * op2, void * op3, int rnd);
public function f_fma(gmpfr r, gmpfr op1, gmpfr op2, gmpfr op3, integer rnd)
	return c_func(xf_fma, {r[2], op1[2], op2[2], op3[2], rnd})
end function
-- extern int f_fms(void * rop, void * op1, void * op2, void * op3, int rnd);
public function f_fms(gmpfr r, gmpfr op1, gmpfr op2, gmpfr op3, integer rnd)
	return c_func(xf_fms, {r[2], op1[2], op2[2], op3[2], rnd})
end function
-- extern int f_fmma(void * rop, void * op1, void * op2, void * op3, void * op4, int rnd);
--public function f_fmma(gmpfr r, gmpfr op1, gmpfr op2, gmpfr op3, integer rnd)
--      return c_func(xf_fmma, {r[2], op1[2], op2[2], op3[2], rnd})
--end function
-- extern int f_fmms(void * rop, void * op1, void * op2, void * op3, void * op4, int rnd);
--public function f_fmms(gmpfr r, gmpfr op1, gmpfr op2, gmpfr op3, integer rnd)
--      return c_func(xf_fmms, {r[2], op1[2], op2[2], op3[2], rnd})
--end function
-- extern int f_agm(void * rop, void * op1, void * op2, int rnd);
public function f_agm(gmpfr r, gmpfr op1, gmpfr op2, integer rnd)
	return c_func(xf_agm, {r[2], op1[2], op2[2], rnd})
end function
-- extern int f_hypot(void * rop, void * x, void * y, int rnd);
public function f_hypot(gmpfr r, gmpfr x, gmpfr y, integer rnd)
	return c_func(xf_hypot, {r[2], x[2], y[2], rnd})
end function
-- extern int f_ai(void * r, void * p, int rnd);
public function f_ai(gmpfr r, gmpfr op, integer rnd)
	return c_func(xf_ai, {r[2], op[2], rnd})
end function
-- extern int f_const_log2(void * rop, int rnd);
public function f_const_log2(gmpfr r, integer rnd)
	return c_func(xf_const_log2, {r[2], rnd})
end function
-- extern int f_const_pi(void * rop, int rnd);
public function f_const_pi(gmpfr r, integer rnd)
	return c_func(xf_const_pi, {r[2], rnd})
end function
-- extern int f_const_euler(void * rop, int rnd);
public function f_const_euler(gmpfr r, integer rnd)
	return c_func(xf_const_euler, {r[2], rnd})
end function
-- extern int f_const_catalan(void * rop, int rnd);
public function f_const_catalan(gmpfr r, integer rnd)
	return c_func(xf_const_catalan, {r[2], rnd})
end function

-- extern void f_free_cache(void);
public procedure f_free_cache()
	c_proc(xf_free_cache, {})
end procedure
-- extern void f_free_pool(void);
public procedure f_free_pool()
	c_proc(xf_free_pool, {})
end procedure
-- extern int f_mp_memory_cleanup(void);
public function f_mp_memory_cleanup()
	return c_func(xf_mp_memory_cleanup, {})
end function
-- extern int f_sum(void * rop, void * tab, unsigned long int n, int rnd);
public function f_sum(gmpfr r, sequence tab, integer rnd)
	atom ma, tmp
	integer len
	gmpfr ele
	len = length(tab)
	ma = allocate_data(4 * len)
	tmp = ma
	for i = 1 to len do
		ele = tab[i]
		poke4(tmp, ele[2])
		tmp += 4
	end for
	tmp = c_func(xf_sum, {r[2], ma, len, rnd})
	free(ma)
	return tmp
end function
-- extern size_t f_out_str_filename(const char * filename, int base, size_t n, void * op, int rnd);
public function f_out_str_filename(sequence filename, integer base, atom n, gmpfr op, integer rnd)
	atom str, ret
	if length(filename) then
		str = allocate_string(filename)
	else
		str = NULL
	end if
	ret = c_func(xf_out_str_filename, {str, base, n, op[2], rnd})
	free(str)
	return ret
end function
-- extern size_t f_inp_str_filename(void * rop, const char * filename, int base, int rnd);
public function f_inp_str_filename(gmpfr r, sequence filename, integer base, integer rnd)
	atom str, ret
	if length(filename) then
		str = allocate_string(filename)
	else
		str = NULL
	end if
	ret = c_func(xf_inp_str_filename, {r[2], str, base, rnd})
	free(str)
	return {GMPFR, ret}
end function
-- extern void f_dump(void * op);
public procedure f_dump(gmpfr op)
	c_proc(xf_dump, {op[2]})
end procedure
-- extern int f_fprintf_filename(const char * filename, const char *format, void * op);
public function f_fprintf_filename(sequence filename, sequence format, gmpfr op)
	atom str, ma_format, ret
	if length(filename) then
		str = allocate_string(filename)
	else
		str = NULL
	end if
	ma_format = allocate_string(format)
	ret = c_func(xf_fprintf_filename, {str, ma_format, op[2]})
	free(str)
	free(ma_format)
	return ret
end function
-- extern int f_printf(const char *format, void * op);
public function f_printf(sequence format, gmpfr op)
	atom ma_format, ret
	ma_format = allocate_string(format)
	ret = c_func(xf_printf, {ma_format, op[2]})
	free(ma_format)
	return ret
end function
--// extern int f_snprintf(char *buf, size_t n, const char *format, void * op);
-- extern int f_asprintf(char **str, const char *format, void * op);
public function f_sprintf(sequence format, gmpfr op)
	atom str_ptr, ma, ret
	sequence st
	str_ptr = allocate_data(4)
	ma = allocate_string(format)
	ret = c_func(xf_asprintf, {str_ptr, ma, op[2]})
	free(ma)
	if ret < 0 then
		st = {}
	else
		ma = peek4u(str_ptr)
		st = peek_string(ma)
		f_free_str(ma)
	end if
	free(str_ptr)
	return st
end function

-- extern int f_rint(void * rop, void * op, int rnd);
public function f_rint(gmpfr r, gmpfr op, integer rnd)
	return c_func(xf_rint, {r[2], op[2], rnd})
end function
-- extern int f_ceil(void * rop, void * op);
public function f_ceil(gmpfr r, gmpfr op)
	return c_func(xf_ceil, {r[2], op[2]})
end function
-- extern int f_floor(void * rop, void * op);
public function f_floor(gmpfr r, gmpfr op)
	return c_func(xf_floor, {r[2], op[2]})
end function
-- extern int f_round(void * rop, void * op);
public function f_round(gmpfr r, gmpfr op)
	return c_func(xf_round, {r[2], op[2]})
end function
-- extern int f_trunc(void * rop, void * op);
public function f_trunc(gmpfr r, gmpfr op)
	return c_func(xf_trunc, {r[2], op[2]})
end function
-- extern int f_rint_ceil(void * rop, void * op, int rnd);
public function f_rint_ceil(gmpfr r, gmpfr op, integer rnd)
	return c_func(xf_rint_ceil, {r[2], op[2], rnd})
end function
-- extern int f_rint_floor(void * rop, void * op, int rnd);
public function f_rint_floor(gmpfr r, gmpfr op, integer rnd)
	return c_func(xf_rint_floor, {r[2], op[2], rnd})
end function
-- extern int f_rint_round(void * rop, void * op, int rnd);
public function f_rint_round(gmpfr r, gmpfr op, integer rnd)
	return c_func(xf_rint_round, {r[2], op[2], rnd})
end function
-- extern int f_rint_roundeven(void * rop, void * op, int rnd);
public function f_rint_roundeven(gmpfr r, gmpfr op, integer rnd)
	return c_func(xf_rint_roundeven, {r[2], op[2], rnd})
end function
-- extern int f_rint_trunc(void * rop, void * op, int rnd);
public function f_rint_trunc(gmpfr r, gmpfr op, integer rnd)
	return c_func(xf_rint_trunc, {r[2], op[2], rnd})
end function
-- extern int f_frac(void * rop, void * op, int rnd);
public function f_frac(gmpfr r, gmpfr op, integer rnd)
	return c_func(xf_frac, {r[2], op[2], rnd})
end function
-- extern int f_modf(void * iop, void * fop, void * op, int rnd);
public function f_modf(gmpfr iret, gmpfr fret, gmpfr op, integer rnd)
	return c_func(xf_modf, {iret[2], fret[2], op[2], rnd})
end function
-- extern int f_fmod(void * r, void * x, void * y, int rnd);
public function f_fmod(gmpfr r, gmpfr x, gmpfr y, integer rnd)
	return c_func(xf_fmod, {r[2], x[2], y[2], rnd})
end function
-- extern int f_fmodquo(void * r, long* q, void * x, void * y, int rnd);
public function f_fmodquo(gmpfr r, gmpfr x, gmpfr y, integer rnd)
	atom ret, ma_q, q
	ma_q = allocate_data(4)
	ret = c_func(xf_fmodquo, {r[2], ma_q, x[2], y[2], rnd})
	q = peek4s(ma_q)
	free(ma_q)
	return {ret, q}
end function
-- extern int f_remainder(void * r, void * x, void * y, int rnd);
public function f_remainder(gmpfr r, gmpfr x, gmpfr y, integer rnd)
	return c_func(xf_remainder, {r[2], x[2], y[2], rnd})
end function
-- extern int f_remquo(void * r, long* q, void * x, void * y, int rnd);
public function f_remquo(gmpfr r, gmpfr x, gmpfr y, integer rnd)
	atom ret, ma_q, q
	ma_q = allocate_data(4)
	ret = c_func(xf_remquo, {r[2], ma_q, x[2], y[2], rnd})
	q = peek4s(ma_q)
	free(ma_q)
	return {ret, q}
end function
-- extern int f_integer_p(void * op);
public function f_integer_p(gmpfr op)
	return c_func(xf_integer_p, {op[2]})
end function

-- extern void f_set_default_rounding_mode(int rnd);
public procedure f_set_default_rounding_mode(integer rnd)
	c_proc(xf_set_default_rounding_mode, {rnd})
end procedure
-- extern int f_get_default_rounding_mode(void);
public function f_get_default_rounding_mode()
	return c_func(xf_get_default_rounding_mode, {})
end function

-- NOTE: Precision Rounding can be achieved with this function:

-- extern int f_prec_round(void * x, long prec, int rnd);
public function f_prec_round(gmpfr x, atom prec, integer rnd)
	return c_func(xf_prec_round, {x[2], prec, rnd})
end function

-- extern int f_can_round(void * b, long err, int rnd1, int rnd2, long prec);
public function f_can_round(gmpfr b, atom err, integer rnd1, integer rnd2, atom prec)
	return c_func(xf_can_round, {b[2], err, rnd1, rnd2, prec})
end function
-- extern long f_min_prec(void * x);
public function f_min_prec(gmpfr x)
	return c_func(xf_min_prec, {x[2]})
end function
-- extern const char * f_print_rnd_mode(int rnd);
-- NOTE: Don't free this string because it is a "const" string.
public function f_print_rnd_mode(integer rnd)
	return peek_string(c_func(xf_print_rnd_mode, {rnd}))
end function
-- extern void f_nexttoward(void * x, void * y);
public procedure f_nexttoward(gmpfr x, gmpfr y)
	c_proc(xf_nexttoward, {x[2], y[2]})
end procedure
-- extern void f_nextabove(void * x);
public procedure f_nextabove(gmpfr x)
	c_proc(xf_nextabove, {x[2]})
end procedure
-- extern void f_nextbelow(void * x);
public procedure f_nextbelow(gmpfr x)
	c_proc(xf_nextbelow, {x[2]})
end procedure
-- extern int f_min(void * rop, void * op1, void * op2, int rnd);
public function f_min(gmpfr r, gmpfr op1, gmpfr op2, integer rnd)
	return c_func(xf_min, {r[2], op1[2], op2[2], rnd})
end function
-- extern int f_max(void * rop, void * op1, void * op2, int rnd);
public function f_max(gmpfr r, gmpfr op1, gmpfr op2, integer rnd)
	return c_func(xf_max, {r[2], op1[2], op2[2], rnd})
end function
-- extern long f_get_exp(void * x);
public function f_get_exp(gmpfr x)
	return c_func(xf_get_exp, {x[2]})
end function
-- extern int f_set_exp(void * x, long e);
public function f_set_exp(gmpfr x, atom e)
	return c_func(xf_set_exp, {x[2], e})
end function
-- extern int f_signbit(void * op);
public function f_signbit(gmpfr op)
	return c_func(xf_signbit, {op[2]})
end function
-- extern int f_setsign(void * rop, void * op, int s, int rnd);
public function f_setsign(gmpfr r, gmpfr op, atom s, integer rnd)
	return c_func(xf_setsign, {r[2], op[2], s, rnd})
end function
-- extern int f_copysign(void * rop, void * op1, void * op2, int rnd);
public function f_copysign(gmpfr r, gmpfr op1, gmpfr op2, integer rnd)
	return c_func(xf_copysign, {r[2], op1[2], op2[2], rnd})
end function

-- extern const char * f_get_version (void);
public function f_get_version()
	return peek_string(c_func(xf_get_version, {}))
end function
-- extern long f_MPFR_VERSION();
public function f_MPFR_VERSION()
	return c_func(xf_MPFR_VERSION, {})
end function
-- extern long f_MPFR_VERSION_MAJOR();
public function f_MPFR_VERSION_MAJOR()
	return c_func(xf_MPFR_VERSION_MAJOR, {})
end function
-- extern long f_MPFR_VERSION_MINOR();
public function f_MPFR_VERSION_MINOR()
	return c_func(xf_MPFR_VERSION_MINOR, {})
end function
-- extern long f_MPFR_VERSION_PATCHLEVEL();
public function f_MPFR_VERSION_PATCHLEVEL()
	return c_func(xf_MPFR_VERSION_PATCHLEVEL, {})
end function
-- extern long f_MPFR_VERSION_NUM(long major, long minor, long patchlevel);
public function f_MPFR_VERSION_NUM(atom major, atom minor, atom patchlevel)
	return c_func(xf_MPFR_VERSION_NUM, {major, minor, patchlevel})
end function
-- extern const char * f_get_patches(void);
public function f_get_patches()
	return peek_string(c_func(xf_get_patches, {}))
end function
-- extern int f_buildopt_tls_p(void);
public function f_buildopt_tls_p()
	return c_func(xf_buildopt_tls_p, {})
end function
-- extern int f_buildopt_decimal_p(void);
public function f_buildopt_decimal_p()
	return c_func(xf_buildopt_decimal_p, {})
end function
-- extern int f_buildopt_gmpinternals_p (void);
public function f_buildopt_gmpinternals_p()
	return c_func(xf_buildopt_gmpinternals_p, {})
end function

-- extern long f_get_emin(void);
public function f_get_emin()
	return c_func(xf_get_emin, {})
end function
-- extern long f_get_emax(void);
public function f_get_emax()
	return c_func(xf_get_emax, {})
end function
-- extern int f_set_emin(long exp);
public function f_set_emin(atom exp)
	return c_func(xf_set_emin, {exp})
end function
-- extern int f_set_emax(long exp);
public function f_set_emax(atom exp)
	return c_func(xf_set_emax, {exp})
end function
-- extern long f_get_emin_min(void);
public function f_get_emin_min()
	return c_func(xf_get_emin_min, {})
end function
-- extern long f_get_emin_max(void);
public function f_get_emin_max()
	return c_func(xf_get_emin_max, {})
end function
-- extern long f_get_emax_min(void);
public function f_get_emax_min()
	return c_func(xf_get_emax_min, {})
end function
-- extern long f_get_emax_max(void);
public function f_get_emax_max()
	return c_func(xf_get_emax_max, {})
end function
-- extern int f_check_range(void * x, int t, int rnd);
public function f_check_range(gmpfr x, atom t, integer rnd)
	return c_func(xf_check_range, {x[2], t, rnd})
end function
-- extern int f_subnormalize(void * x, int t, int rnd);
public function f_subnormalize(gmpfr x, atom t, integer rnd)
	return c_func(xf_subnormalize, {x[2], t, rnd})
end function
-- extern void f_clear_underflow(void);
public procedure f_clear_underflow()
	c_proc(xf_clear_underflow, {})
end procedure
-- extern void f_clear_overflow(void);
public procedure f_clear_overflow()
	c_proc(xf_clear_overflow, {})
end procedure
-- extern void f_clear_divby0(void);
public procedure f_clear_divby0()
	c_proc(xf_clear_divby0, {})
end procedure
-- extern void f_clear_nanflag(void);
public procedure f_clear_nanflag()
	c_proc(xf_clear_nanflag, {})
end procedure
-- extern void f_clear_inexflag(void);
public procedure f_clear_inexflag()
	c_proc(xf_clear_inexflag, {})
end procedure
-- extern void f_clear_erangeflag(void);
public procedure f_clear_erangeflag()
	c_proc(xf_clear_erangeflag, {})
end procedure
-- extern void f_clear_flags(void);
public procedure f_clear_flags()
	c_proc(xf_clear_flags, {})
end procedure
-- extern void f_set_underflow(void);
public procedure f_set_underflow()
	c_proc(xf_set_underflow, {})
end procedure
-- extern void f_set_overflow(void);
public procedure f_set_overflow()
	c_proc(xf_set_overflow, {})
end procedure
-- extern void f_set_divby0(void);
public procedure f_set_divby0()
	c_proc(xf_set_divby0, {})
end procedure
-- extern void f_set_nanflag(void);
public procedure f_set_nanflag()
	c_proc(xf_set_nanflag, {})
end procedure
-- extern void f_set_inexflag(void);
public procedure f_set_inexflag()
	c_proc(xf_set_inexflag, {})
end procedure
-- extern void f_set_erangeflag(void);
public procedure f_set_erangeflag()
	c_proc(xf_set_erangeflag, {})
end procedure

-- extern int f_underflow_p(void);
public function f_underflow_p()
	return c_func(xf_underflow_p, {})
end function
-- extern int f_overflow_p(void);
public function f_overflow_p()
	return c_func(xf_overflow_p, {})
end function
-- extern int f_divby0_p(void);
public function f_divby0_p()
	return c_func(xf_divby0_p, {})
end function
-- extern int f_nanflag_p(void);
public function f_nanflag_p()
	return c_func(xf_nanflag_p, {})
end function
-- extern int f_inexflag_p(void);
public function f_inexflag_p()
	return c_func(xf_inexflag_p, {})
end function
-- extern int f_erangeflag_p(void);
public function f_erangeflag_p()
	return c_func(xf_erangeflag_p, {})
end function

-- END mpfr FUNCTIONS.

-- BEGIN INT FUNCTIONS:


function allocate_int()
	return allocate_data(sizeof_int)
	-- Not using this anymore:
	-- return c_func(xallocate_int, {})
end function
procedure register_int(atom a)
	c_proc(xregister_int, {a})
end procedure
procedure clear_int(atom a)
	c_proc(xclear_int, {a})
end procedure

public function new_int()
	atom ma
	ma = allocate_int()
	register_int(ma)
	return {GINT, ma}
end function

public procedure delete_int(gint a)
	clear_int(a[2])
	free(a[2])
end procedure


public procedure int_set(gint a, gint b)
	c_proc(xint_set, {a[2],b[2]})
end procedure

public procedure int_set_ui(gint a, atom b)
	c_proc(xint_set_ui, {a[2], b})
end procedure
public procedure int_set_si(gint a, atom b)
	c_proc(xint_set_si, {a[2], b})
end procedure
public procedure int_set_d(gint a, atom b)
	c_proc(xint_set_d, {a[2], b})
end procedure
public procedure int_set_q(gint a, gquot b)
	c_proc(xint_set_q, {a[2], b[2]})
end procedure
public procedure int_set_float(gint a, gfloat b)
	c_proc(xint_set_float, {a[2], b[2]})
end procedure

function int_set_str(atom a, atom b, atom c)
	return c_func(xint_set_str, {a,b,c})
end function
public function int_set_string(gint a, sequence st, integer base)
-- Returns Status: (0 for good)
	atom str, ret
	str = allocate_string(st)
	ret = int_set_str(a[2], str, base)
	free(str)
	return ret
end function

-- Conversion Functions:

public function int_get_ui(gint op)
	return c_func(xint_get_ui, {op[2]})
end function
public function int_get_si(gint op)
	return c_func(xint_get_si, {op[2]})
end function
public function int_get_d(gint op)
	return c_func(xint_get_d, {op[2]})
end function
public function int_get_d_2exp(gint op)
	atom ret, ma, exponent
	ma = allocate_data(4)
	ret = c_func(xint_get_d_2exp, {ma, op[2]})
	exponent = peek4s(ma)
	free(ma)
	return {ret, exponent}
end function

function int_get_str(atom a, atom b, atom c)
	return c_func(xint_get_str, {a,b,c})
end function
public function int_get_string(integer base, gint a)
	atom str
	sequence st
	str = int_get_str(NULL, base, a[2])
	st = peek_string(str)
	generic_free(str)
	return st
end function


public procedure int_add(gint a, gint b, gint c)
	c_proc(xint_add, {a[2],b[2],c[2]})
end procedure
public procedure int_add_ui(gint a, gint b, atom c)
	c_proc(xint_add, {a[2],b[2],c})
end procedure
public procedure int_sub(gint a, gint b, gint c)
	c_proc(xint_sub, {a[2],b[2],c[2]})
end procedure
public procedure int_sub_ui(gint a, gint b, atom c)
	c_proc(xint_sub, {a[2],b[2],c})
end procedure
public procedure int_ui_sub(gint a, atom b, gint c)
	c_proc(xint_sub, {a[2],b,c[2]})
end procedure
public procedure int_mul(gint a, gint b, gint c)
	c_proc(xint_mul, {a[2],b[2],c[2]})
end procedure
public procedure int_mul_si(gint a, gint b, atom c)
	c_proc(xint_mul, {a[2],b[2],c})
end procedure
public procedure int_mul_ui(gint a, gint b, atom c)
	c_proc(xint_mul, {a[2],b[2],c})
end procedure
public procedure int_addmul(gint a, gint b, gint c)
	c_proc(xint_addmul, {a[2],b[2],c[2]})
end procedure
public procedure int_addmul_ui(gint a, gint b, atom c)
	c_proc(xint_addmul, {a[2],b[2],c})
end procedure
public procedure int_submul(gint a, gint b, gint c)
	c_proc(xint_submul, {a[2],b[2],c[2]})
end procedure
public procedure int_submul_ui(gint a, gint b, atom c)
	c_proc(xint_submul, {a[2],b[2],c})
end procedure
public procedure int_mul_2exp(gint a, gint b, atom c)
	c_proc(xint_mul_2exp, {a[2],b[2],c})
end procedure
public procedure int_neg(gint a, gint b)
	c_proc(xint_neg, {a[2],b[2]})
end procedure
public procedure int_abs(gint a, gint b)
	c_proc(xint_abs, {a[2],b[2]})
end procedure

public procedure int_cdiv_q(gint dst, gint op1, gint op2)
	c_proc(xint_cdiv_q, {dst[2], op1[2], op2[2]})
end procedure
public procedure int_cdiv_r(gint dst, gint op1, gint op2)
	c_proc(xint_cdiv_r, {dst[2], op1[2], op2[2]})
end procedure
public procedure int_cdiv_qr(gint dstq, gint dstr, gint op1, gint op2)
	c_proc(xint_cdiv_qr, {dstq[2], dstr[2], op1[2], op2[2]})
end procedure
public function int_cdiv_q_ui(gint dstq, gint n, atom d)
	return c_func(xint_cdiv_q_ui, {dstq[2], n[2], d})
end function
public function int_cdiv_r_ui(gint dstr, gint n, atom d)
	return c_func(xint_cdiv_r_ui, {dstr[2], n[2], d})
end function
public function int_cdiv_qr_ui(gint dstq, gint dstr, gint n, atom d)
	return c_func(xint_cdiv_qr_ui, {dstq[2], dstr[2], n[2], d})
end function
public function int_cdiv_ui(gint n, atom d)
	return c_func(xint_cdiv_ui, {n[2], d})
end function
public procedure int_cdiv_q_2exp(gint dstq, gint n, atom b)
	c_proc(xint_cdiv_q_2exp, {dstq[2], n[2], b})
end procedure
public procedure int_cdiv_r_2exp(gint dstr, gint n, atom b)
	c_proc(xint_cdiv_r_2exp, {dstr[2], n[2], b})
end procedure
public procedure int_fdiv_q(gint dstq, gint op1, gint op2)
	c_proc(xint_fdiv_q, {dstq[2], op1[2], op2[2]})
end procedure
public procedure int_fdiv_r(gint dstr, gint op1, gint op2)
	c_proc(xint_fdiv_r, {dstr[2], op1[2], op2[2]})
end procedure
public procedure int_fdiv_qr(gint dstq, gint dstr, gint n, gint d)
	c_proc(xint_fdiv_qr, {dstq[2], dstr[2], n[2], d[2]})
end procedure
public function int_fdiv_q_ui(gint dstq, gint n, atom d)
	return c_func(xint_fdiv_q_ui, {dstq[2], n[2], d})
end function
public function int_fdiv_r_ui(gint dstr, gint n, atom d)
	return c_func(xint_fdiv_r_ui, {dstr[2], n[2], d})
end function
public function int_fdiv_qr_ui(gint dstq, gint dstr, gint n, atom d)
	return c_func(xint_fdiv_qr_ui, {dstq[2], dstr[2], n[2], d})
end function
public function int_fdiv_ui(gint n, atom d)
	return c_func(xint_fdiv_ui, {n[2], d})
end function
public procedure int_fdiv_q_2exp(gint dstq, gint n, atom b)
	c_proc(xint_fdiv_q_2exp, {dstq[2], n[2], b})
end procedure
public procedure int_fdiv_r_2exp(gint dstr, gint n, atom b)
	c_proc(xint_fdiv_r_2exp, {dstr[2], n[2], b})
end procedure
public procedure int_tdiv_q(gint dstq, gint op1, gint op2)
	c_proc(xint_tdiv_q, {dstq[2], op1[2], op2[2]})
end procedure
public procedure int_tdiv_r(gint dstr, gint op1, gint op2)
	c_proc(xint_tdiv_r, {dstr[2], op1[2], op2[2]})
end procedure
public procedure int_tdiv_qr(gint dstq, gint dstr, gint n, gint d)
	c_proc(xint_tdiv_qr, {dstq[2], dstr[2], n[2], d[2]})
end procedure
public function int_tdiv_q_ui(gint dstq, gint n, atom d)
	return c_func(xint_tdiv_q_ui, {dstq[2], n[2], d})
end function
public function int_tdiv_r_ui(gint dstr, gint n, atom d)
	return c_func(xint_tdiv_r_ui, {dstr[2], n[2], d})
end function
public function int_tdiv_qr_ui(gint dstq, gint dstr, gint n, atom d)
	return c_func(xint_tdiv_qr_ui, {dstq[2], dstr[2], n[2], d})
end function
public function int_tdiv_ui(gint n, atom d)
	return c_func(xint_tdiv_ui, {n[2], d})
end function
public procedure int_tdiv_q_2exp(gint dstq, gint n, atom b)
	c_proc(xint_tdiv_q_2exp, {dstq[2], n[2], b})
end procedure
public procedure int_tdiv_r_2exp(gint dstr, gint n, atom b)
	c_proc(xint_tdiv_r_2exp, {dstr[2], n[2], b})
end procedure
public procedure int_mod(gint r, gint n, gint d)
	c_proc(xint_mod, {r[2], n[2], d[2]})
end procedure
public function int_mod_ui(gint dstr, gint n, atom d)
	return c_func(xint_mod_ui, {dstr[2], n[2], d})
end function
public procedure int_divexact(gint dstq, gint n, gint d)
	c_proc(xint_divexact, {dstq[2], n[2], d[2]})
end procedure
public procedure int_divexact_ui(gint dstq, gint n, atom d)
	c_proc(xint_divexact_ui, {dstq[2], n[2], d})
end procedure
public function int_divisible_p(gint n, gint d)
	return c_func(xint_divisible_p, {n[2], d[2]})
end function
public function int_divisible_ui_p(gint n, atom d)
	return c_func(xint_divisible_ui_p, {n[2], d})
end function
public function int_divisible_2exp_p(gint n, atom b)
	return c_func(xint_divisible_2exp_p, {n[2], b})
end function
public function int_congruent_p(gint n, gint c, gint d)
	return c_func(xint_congruent_p, {n[2], c[2], d[2]})
end function
public function int_congruent_ui_p(gint n, atom c, atom d)
	return c_func(xint_congruent_ui_p, {n[2], c, d})
end function
public function int_congruent_2exp_p(gint n, gint c, atom b)
	return c_func(xint_congruent_2exp_p, {n[2], c[2], b})
end function
public procedure int_powm(gint dst, gint base, gint exp, gint mod)
	c_proc(xint_powm, {dst[2], base[2], exp[2], mod[2]})
end procedure
public procedure int_powm_ui(gint dst, gint base, atom exp, gint mod)
	c_proc(xint_powm_ui, {dst[2], base[2], exp, mod[2]})
end procedure
public procedure int_powm_sec(gint dst, gint base, gint exp, gint mod)
	c_proc(xint_powm_sec, {dst[2], base[2], exp[2], mod[2]})
end procedure
public procedure int_pow_ui(gint dst, gint base, atom exp)
	c_proc(xint_pow_ui, {dst[2], base[2], exp})
end procedure
public procedure int_ui_pow_ui(gint dst, atom base, atom exp)
	c_proc(xint_ui_pow_ui, {dst[2], base, exp})
end procedure
public function int_root(gint dst, gint op, atom n)
	return c_func(xint_root, {dst[2], op[2], n})
end function
public procedure int_rootrem(gint root, gint rem, gint u, atom n)
	c_proc(xint_rootrem, {root[2], rem[2], u[2], n})
end procedure
public procedure int_sqrt(gint dst, gint op)
	c_proc(xint_sqrt, {dst[2], op[2]})
end procedure
public procedure int_sqrtrem(gint rop1, gint rop2, gint op)
	c_proc(xint_sqrtrem, {rop1[2], rop2[2], op[2]})
end procedure
public function int_perfect_power_p(gint op)
	return c_func(xint_perfect_power_p, {op[2]})
end function
public function int_perfect_square_p(gint op)
	return c_func(xint_perfect_square_p, {op[2]})
end function

public function int_probab_prime_p (gint n, atom reps)
	return c_func(xint_probab_prime_p, {n[2], reps})
end function
public procedure int_nextprime (gint rop, gint op)
	c_proc(xint_nextprime, {rop[2], op[2]})
end procedure
public procedure int_gcd (gint rop, gint op1, gint op2)
	c_proc(xint_gcd, {rop[2], op1[2], op2[2]})
end procedure
public function int_gcd_ui (gint rop, gint op1, atom op2)
	return c_func(xint_gcd_ui, {rop, op1, op2})
end function
public procedure int_gcdext (gint g, gint s, gint t, gint a, gint b)
	c_proc(xint_gcdext, {g[2], s[2], t[2], a[2], b[2]})
end procedure
public procedure int_lcm (gint rop, gint op1, gint op2)
	c_proc(xint_lcm, {rop[2], op1[2], op2[2]})
end procedure
public procedure int_lcm_ui (gint rop, gint op1, atom op2)
	c_proc(xint_lcm_ui, {rop[2], op1[2], op2})
end procedure
public function int_invert (gint rop, gint op1, gint op2)
	return c_func(xint_invert, {rop[2], op1[2], op2[2]})
end function
public function int_jacobi (gint a, gint b)
	return c_func(xint_jacobi, {a[2], b[2]})
end function
public function int_legendre (gint a, gint p)
	return c_func(xint_legendre, {a[2], p[2]})
end function
public function int_kronecker (gint a, gint b)
	return c_func(xint_kronecker, {a[2], b[2]})
end function
public function int_kronecker_si (gint a, atom b)
	return c_func(xint_kronecker_si, {a[2], b})
end function
public function int_kronecker_ui (gint a, atom b)
	return c_func(xint_kronecker_ui, {a[2], b})
end function
public function int_si_kronecker (atom a, gint b)
	return c_func(xint_si_kronecker, {a, b[2]})
end function
public function int_ui_kronecker (atom a, gint b)
	return c_func(xint_ui_kronecker, {a, b[2]})
end function
public function int_remove (gint rop, gint op, gint f)
	return c_func(xint_remove, {rop[2], op[2], f[2]})
end function
public procedure int_fac_ui (gint rop, atom n)
	c_proc(xint_fac_ui, {rop[2], n})
end procedure
public procedure int_2fac_ui (gint rop, atom n)
	c_proc(xint_2fac_ui, {rop[2], n})
end procedure
public procedure int_mfac_uiui (gint rop, atom n, atom m)
	c_proc(xint_mfac_uiui, {rop[2], n, m})
end procedure
public procedure int_primorial_ui (gint rop, atom n)
	c_proc(xint_primorial_ui, {rop[2], n})
end procedure
public procedure int_bin_ui (gint rop, gint n, atom k)
	c_proc(xint_bin_ui, {rop[2], n[2], k})
end procedure
public procedure int_bin_uiui (gint rop, atom n, atom k)
	c_proc(xint_bin_uiui, {rop[2], n, k})
end procedure
public procedure int_fib_ui (gint fn, atom n)
	c_proc(xint_fib_ui, {fn[2], n})
end procedure
public procedure int_fib2_ui (gint fn, gint fnsub1, atom n)
	c_proc(xint_fib2_ui, {fn[2], fnsub1[2], n})
end procedure
public procedure int_lucnum_ui (gint ln, atom n)
	c_proc(xint_lucnum_ui, {ln[2], n})
end procedure
public procedure int_lucnum2_ui (gint ln, gint lnsub1, atom n)
	c_proc(xint_lucnum2_ui, {ln[2], lnsub1[2], n})
end procedure

public function int_cmp(gint op1, gint op2)
	return c_func(xint_cmp, {op1[2], op2[2]})
end function
public function int_cmp_d(gint op1, atom op2)
	return c_func(xint_cmp_d, {op1[2], op2})
end function
public function int_cmp_si(gint op1, atom op2)
	return c_func(xint_cmp_si, {op1[2], op2})
end function
public function int_cmp_ui(gint op1, atom op2)
	return c_func(xint_cmp_ui, {op1[2], op2})
end function
public function int_cmpabs(gint op1, gint op2)
	return c_func(xint_cmpabs, {op1[2], op2[2]})
end function
public function int_cmpabs_d(gint op1, atom op2)
	return c_func(xint_cmpabs_d, {op1[2], op2})
end function
public function int_cmpabs_ui(gint op1, atom op2)
	return c_func(xint_cmpabs_ui, {op1[2], op2})
end function
public function int_sgn(gint op)
	return c_func(xint_sgn, {op[2]})
end function
public procedure int_and(gint rop, gint op1, gint op2)
	c_proc(xint_and, {rop[2], op1[2], op2[2]})
end procedure
public procedure int_ior(gint rop, gint op1, gint op2)
	c_proc(xint_ior, {rop[2], op1[2], op2[2]})
end procedure
public procedure int_xor(gint rop, gint op1, gint op2)
	c_proc(xint_xor, {rop[2], op1[2], op2[2]})
end procedure
public procedure int_com(gint rop, gint op)
	c_proc(xint_com, {rop[2], op[2]})
end procedure
public function int_popcount(gint op)
	return c_func(xint_popcount, {op[2]})
end function
public function int_hamdist(gint op1, gint op2)
	return c_func(xint_hamdist, {op1[2], op2[2]})
end function
public function int_scan0(gint op, atom starting_bit)
	return c_func(xint_scan0, {op[2], starting_bit})
end function
public function int_scan1(gint op, atom starting_bit)
	return c_func(xint_scan1, {op[2], starting_bit})
end function
public procedure int_setbit(gint rop, atom bit_index)
	c_proc(xint_setbit, {rop[2], bit_index})
end procedure
public procedure int_clrbit(gint rop, atom bit_index)
	c_proc(xint_clrbit, {rop[2], bit_index})
end procedure
public procedure int_combit(gint rop, atom bit_index)
	c_proc(xint_combit, {rop[2], bit_index})
end procedure
public function int_tstbit(gint op, atom bit_index)
	return c_func(xint_tstbit, {op[2], bit_index})
end function

-- mpz Input and Output (IO) Functions:

-- extern size_t int_out_str_filename(const char * filename, int base, void * op);
public function int_out_str_filename(sequence filename, integer base, gint op)
	atom str, ret
	if length(filename) then
		str = allocate_string(filename)
	else
		str = NULL
	end if
	ret = c_func(xint_out_str_filename, {str, base, op[2]})
	free(str)
	return ret
end function
-- extern size_t int_inp_str_filename(void * rop, const char * filename, int base);
public function int_inp_str_filename(gmpfr r, sequence filename, integer base)
	atom str, ret
	if length(filename) then
		str = allocate_string(filename)
	else
		str = NULL
	end if
	ret = c_func(xint_inp_str_filename, {r[2], str, base})
	free(str)
	return {GINT, ret}
end function
-- extern size_t int_out_raw_filename(const char * filename, void * op);
public function int_out_raw_filename(sequence filename, gmpfr op)
	atom str, ret
	if length(filename) then
		str = allocate_string(filename)
	else
		str = NULL
	end if
	ret = c_func(xint_out_str_filename, {str, op[2]})
	free(str)
	return ret
end function
-- extern size_t int_inp_raw_filename(void * rop, const char * filename);
public function int_inp_raw_filename(gmpfr r, sequence filename)
	atom str, ret
	if length(filename) then
		str = allocate_string(filename)
	else
		str = NULL
	end if
	ret = c_func(xint_inp_str_filename, {r[2], str})
	free(str)
	return ret
end function

-- Skipping Random Number functions in this version.

-- Integer Import and Export:

--void int_import(void * rop, size_t count, int order, size_t size, int endian, size_t nails, const void *op) {
--      mpz_import((mpz_ptr)rop, count, order, size, endian, nails, op);
--}
public procedure int_import(gint rop, atom count, atom order, atom size, atom endian, atom nails, atom ma_op)
	c_proc(xint_import, {rop[2], count, order, size, endian, nails, ma_op})
end procedure

--void * int_export(void * rop, size_t * countp, int order, size_t size, int endian, size_t nails, const void * op) {
--      return mpz_export(rop, countp, order, size, endian, nails, (mpz_srcptr)op);
--}
public function int_export(atom order, atom size, atom endian, atom nails, gint op)
-- Use: generic_free() library function on the return pointer value.
	atom ret_ptr, ma_SizeTCountP, count
	sequence ret
	ma_SizeTCountP = allocate_data(4)
	ret_ptr = c_func(xint_export, {NULL, ma_SizeTCountP, order, size, endian, nails, op[2]})
	count = peek4u(ma_SizeTCountP)
	free(ma_SizeTCountP)
	return {ret_ptr, count}
end function

--// Random number functions:

-- void int_urandomb(void * rop, void * state, unsigned long n) {
-- 	mpz_urandomb((mpz_ptr)rop, (__gmp_randstate_struct*) state, (mp_bitcnt_t)n);
-- }
public procedure int_urandomb(gint rop, atom state_ma, atom n)
	c_proc(xint_urandomb, {rop[2], state_ma, n})
end procedure

-- void int_urandomm(void * rop, void * state, void * n) {
-- 	mpz_urandomm((mpz_ptr)rop, (__gmp_randstate_struct*) state, (mpz_srcptr)n);
-- }
public procedure int_urandomm(gint rop, atom state_ma, atom n)
	c_proc(xint_urandomm, {rop[2], state_ma, n})
end procedure

-- void int_rrandomb(void * rop, void * state, unsigned long n) {
-- 	mpz_rrandomb((mpz_ptr)rop, (__gmp_randstate_struct*) state, (mp_bitcnt_t)n);
-- }
public procedure int_rrandomb(gint rop, atom state_ma, atom n)
	c_proc(xint_rrandomb, {rop[2], state_ma, n})
end procedure

-- void int_random(void * rop, long max_size) {
-- 	mpz_random((mpz_ptr)rop, (mp_size_t)max_size);
-- }
public procedure int_random(gint rop, atom max_size)
	c_proc(xint_random, {rop[2], max_size})
end procedure

-- void int_random2(void * rop, long max_size) {
-- 	mpz_random2((mpz_ptr)rop, (mp_size_t)max_size);
-- }
public procedure int_random2(gint rop, atom max_size)
	c_proc(xint_random2, {rop[2], max_size})
end procedure

--// 9.1 Random State Initialization

-- size_t sizeof_randstate() {
-- 	return sizeof(__gmp_randstate_struct);
-- }
public function sizeof_randstate()
	return c_func(xsizeof_randstate, {})
end function

-- void int_randinit_default(void * state) {
-- 	gmp_randinit_default((__gmp_randstate_struct*) state);
-- }
public procedure int_randinit_default(atom state_ma)
	c_proc(xint_randinit_default, {state_ma})
end procedure

-- void int_randinit_mt(void * state) {
-- 	gmp_randinit_mt((__gmp_randstate_struct*) state);
-- }
public procedure int_randinit_mt(atom state_ma)
	c_proc(xint_randinit_mt, {state_ma})
end procedure

-- void int_randinit_lc_2exp(void * state, void * a, unsigned long c, unsigned long m2exp) {
-- 	gmp_randinit_lc_2exp((__gmp_randstate_struct*) state, (mpz_srcptr)a, c, (mp_bitcnt_t)m2exp);
-- }
public procedure int_randinit_lc_2exp(atom state_ma, gint a, atom c, atom m2exp)
	c_proc(xint_randinit_lc_2exp, {state_ma, a[2], c, m2exp})
end procedure

-- int int_randinit_lc_2exp_size(void * state, unsigned long size) {
-- 	return gmp_randinit_lc_2exp_size((__gmp_randstate_struct*) state, (mp_bitcnt_t)size);
-- }
public function int_randinit_lc_2exp_size(atom state_ma, atom size)
	return c_func(xint_randinit_lc_2exp_size, {state_ma, size})
end function

-- void int_randinit_set(void * rop, void * op) {
-- 	gmp_randinit_set((__gmp_randstate_struct*) rop, (__gmp_randstate_struct*) op);
-- }
public procedure int_randinit_set(atom state_ma_rop, atom state_ma_op)
	c_proc(xint_randinit_set, {state_ma_rop, state_ma_op})
end procedure

-- void int_randclear(void * state) {
-- 	gmp_randclear((__gmp_randstate_struct*) state);
-- }
public procedure int_randclear(atom state_ma)
	c_proc(xint_randclear, {state_ma})
end procedure

--// 9.2 Random State Seeding

-- void int_randseed(void * state, void * seed) {
-- 	gmp_randseed((__gmp_randstate_struct*) state, (mpz_srcptr)seed);
-- }
public procedure int_randseed(atom state_ma, gint seed) -- "state_ma" means "memory address of state"
	c_proc(xint_randseed, {state_ma, seed[2]})
end procedure

-- void int_randseed_ui(void * state, unsigned long int seed) {
-- 	gmp_randseed_ui((__gmp_randstate_struct*) state, seed);
-- }
public procedure int_randseed_ui(atom state_ma, atom seed)
	c_proc(xint_randseed_ui, {state_ma, seed})
end procedure

--// 9.3 Random State Miscellaneous

-- unsigned long int_urandomb_ui(void * state, unsigned long n) {
-- 	return gmp_urandomb_ui ((__gmp_randstate_struct*) state, n);
-- }
public function int_urandomb_ui(atom state_ma, atom n)
	return c_func(xint_urandomb_ui, {state_ma, n})
end function

-- unsigned long int_urandomm_ui(void * state, unsigned long n) {
-- 	return gmp_urandomm_ui ((__gmp_randstate_struct*) state, n);
-- }
public function int_urandomm_ui(atom state_ma, atom n)
	return c_func(xint_urandomm_ui, {state_ma, n})
end function


public function int_fits_ulong_p(gint a)
	return c_func(xint_fits_ulong_p, {a[2]})
end function
public function int_fits_slong_p(gint a)
	return c_func(xint_fits_slong_p, {a[2]})
end function
public function int_fits_uint_p(gint a)
	return c_func(xint_fits_uint_p, {a[2]})
end function
public function int_fits_sint_p(gint a)
	return c_func(xint_fits_sint_p, {a[2]})
end function
public function int_fits_ushort_p(gint a)
	return c_func(xint_fits_ushort_p, {a[2]})
end function
public function int_fits_sshort_p(gint a)
	return c_func(xint_fits_sshort_p, {a[2]})
end function
public function int_odd_p(gint a)
	return c_func(xint_odd_p, {a[2]})
end function
public function int_even_p(gint a)
	return c_func(xint_even_p, {a[2]})
end function
public function int_sizeinbase(gint a, atom b)
	return c_func(xint_sizeinbase, {a[2], b})
end function

----

function allocate_q()
	return allocate_data(sizeof_q)
	-- return c_func(xallocate_q, {})
end function
procedure register_q(atom a)
	c_proc(xregister_q, {a})
end procedure
procedure clear_q(atom a)
	c_proc(xclear_q, {a})
end procedure

public function new_quot()
	atom ma
	ma = allocate_q()
	register_q(ma)
	return {GQUOT, ma}
end function

public procedure delete_quot(gquot a)
	clear_q(a[2])
	free(a[2])
end procedure


public procedure q_set(gquot a, gquot b)
	c_proc(xq_set, {a[2],b[2]})
end procedure
function q_set_str(atom a, atom b, atom c)
	return c_func(xq_set_str, {a,b,c})
end function
public function q_set_string(gquot a, sequence st, integer base)
-- Returns Status: (0 for good)
	atom str, ret
	str = allocate_string(st)
	ret = q_set_str(a[2], str, base)
	free(str)
	return ret
end function
public function q_get_str(atom a, atom b, atom c)
	return c_func(xq_get_str, {a,b,c})
end function
public function q_get_string(integer base, gquot a)
	atom str
	sequence st
	str = q_get_str(NULL, base, a[2])
	st = peek_string(str)
	generic_free(str)
	return st
end function


public procedure q_swap(gquot a, gquot b)
	c_proc(xq_swap, {a,b})
end procedure


public procedure q_add(gquot a, gquot b, gquot c)
	c_proc(xq_add, {a[2],b[2],c[2]})
end procedure
public procedure q_sub(gquot a, gquot b, gquot c)
	c_proc(xq_sub, {a[2],b[2],c[2]})
end procedure
public procedure q_mul(gquot a, gquot b, gquot c)
	c_proc(xq_mul, {a[2],b[2],c[2]})
end procedure
public procedure q_div(gquot a, gquot b, gquot c)
	c_proc(xq_div, {a[2],b[2],c[2]})
end procedure
public procedure q_neg(gquot a, gquot b)
	c_proc(xq_neg, {a[2],b[2]})
end procedure
public procedure q_abs(gquot a, gquot b)
	c_proc(xq_abs, {a[2],b[2]})
end procedure
public procedure q_inv(gquot a, gquot b)
	c_proc(xq_inv, {a[2],b[2]})
end procedure


public function q_cmp(gquot a, gquot b)
	return c_func(xq_cmp, {a[2],b[2]})
end function
public function q_equal(gquot a, gquot b)
	return c_func(xq_equal, {a[2],b[2]})
end function


public procedure q_get_num(gint a, gquot b)
	c_proc(xq_get_num, {a[2],b[2]})
end procedure
public procedure q_get_den(gint a, gquot b)
	c_proc(xq_get_den, {a[2],b[2]})
end procedure
public procedure q_set_num(gquot a, gint b)
	c_proc(xq_set_num, {a[2],b[2]})
end procedure
public procedure q_set_den(gquot a, gint b)
	c_proc(xq_set_den, {a[2],b[2]})
end procedure

----

public procedure float_set_default_prec(atom prec)
	-- takes a "unsigned long"
	c_proc(xfloat_set_default_prec, {prec})
end procedure
public function float_get_default_prec()
	-- returns a "unsigned long"
	return c_func(xfloat_get_default_prec, {})
end function


function allocate_float()
	return allocate_data(sizeof_float)
	-- return c_func(xallocate_float, {})
end function
procedure register_float(atom a)
	c_proc(xregister_float, {a})
end procedure
procedure register_float2(atom a, atom b)
	c_proc(xregister_float2, {a,b})
end procedure
procedure clear_float(atom a)
	c_proc(xclear_float, {a})
end procedure

public function new_float()
	atom ma
	ma = allocate_float()
	register_float(ma)
	return {GFLOAT, ma}
end function
public function new_float2(atom prec)
	atom ma
	ma = allocate_float()
	register_float2(ma, prec)
	return {GFLOAT, ma}
end function
public procedure delete_float(gfloat a)
	clear_float(a[2])
	free(a[2])
end procedure


public function float_get_prec(gfloat a)
	return c_func(xfloat_get_prec, {a[2]})
end function
public procedure float_set_prec(gfloat a, atom prec)
	c_proc(xfloat_set_prec, {a[2],prec})
end procedure


public procedure float_set(gfloat a, gfloat b)
	c_proc(xfloat_set, {a[2],b[2]})
end procedure
function float_set_str(atom a, atom b, atom c)
	return c_func(xfloat_set_str, {a,b,c})
end function
public function float_set_string(gfloat a, sequence st, integer base)
-- Returns Status: (0 for good)
	atom str, ret
	str = allocate_string(st)
	ret = float_set_str(a[2], str, base)
	free(str)
	return ret
end function
function float_get_str(atom a, atom b, atom c, atom d, atom e)
	return c_func(xfloat_get_str, {a,b,c,d,e})
end function
public function float_get_string(integer base, atom n_digits, gfloat a)
	atom str, expptr, exponent
	sequence st
	expptr = allocate_data(4) -- pointer to an int or long int
	str = float_get_str(NULL, expptr, base, n_digits, a[2])
	exponent = peek4s(expptr)
	free(expptr)
	st = peek_string(str)
	generic_free(str)
	return {st, exponent}
end function


public procedure float_swap(gfloat a, gfloat b)
	c_proc(xfloat_swap, {a[2],b[2]})
end procedure


public procedure float_add(gfloat a, gfloat b, gfloat c)
	c_proc(xfloat_add, {a[2],b[2],c[2]})
end procedure
public procedure float_sub(gfloat a, gfloat b, gfloat c)
	c_proc(xfloat_sub, {a[2],b[2],c[2]})
end procedure
public procedure float_mul(gfloat a, gfloat b, gfloat c)
	c_proc(xfloat_mul, {a[2],b[2],c[2]})
end procedure
public procedure float_div(gfloat a, gfloat b, gfloat c)
	c_proc(xfloat_div, {a[2],b[2],c[2]})
end procedure
public procedure float_sqrt(gfloat a, gfloat b)
	c_proc(xfloat_sqrt, {a[2],b[2]})
end procedure


public procedure float_sqrt_ui(gfloat a, atom op)
	-- op is an unsigned long int
	c_proc(xfloat_sqrt_ui, {a[2],op})
end procedure
public procedure float_pow_ui(gfloat a, gfloat b, atom op)
	-- op is an unsigned long int
	c_proc(xfloat_pow_ui, {a[2],b[2],op})
end procedure


public procedure float_neg(gfloat a, gfloat b)
	c_proc(xfloat_neg, {a[2],b[2]})
end procedure
public procedure float_abs(gfloat a, gfloat b)
	c_proc(xfloat_abs, {a[2],b[2]})
end procedure


public function float_cmp(gfloat a, gfloat b)
	return c_func(xfloat_cmp, {a[2],b[2]})
end function


public procedure float_reldiff(gfloat a, gfloat b, gfloat c)
	c_proc(xfloat_reldiff, {a[2],b[2],c[2]})
end procedure
public procedure float_ceil(gfloat a, gfloat b)
	c_proc(xfloat_ceil, {a[2],b[2]})
end procedure
public procedure float_floor(gfloat a, gfloat b)
	c_proc(xfloat_floor, {a[2],b[2]})
end procedure
public procedure float_trunc(gfloat a, gfloat b)
	c_proc(xfloat_trunc, {a[2],b[2]})
end procedure
public function float_integer_p(gfloat a)
	return c_func(xfloat_integer_p, {a[2]})
end function

-- END OF FILE
