// Copyright (c) 2020 James J. Cook
// Informational program, version.c

// compile with:
// cc -o version version.c -lmpfr -lgmp

#include <stdio.h>
#include <mpfr.h>
int main (void)
{
	printf ("MPFR library: %-12s\nMPFR header: %s (based on %d.%d.%d)\n",
		mpfr_get_version (), MPFR_VERSION_STRING, MPFR_VERSION_MAJOR,
		MPFR_VERSION_MINOR, MPFR_VERSION_PATCHLEVEL);
	printf("Press enter to continue.\n");
	getc(stdin);
	return 0;
}
