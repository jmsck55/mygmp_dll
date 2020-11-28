-- Copyright (c) 2020 James J. Cook

include mygmp.e

with trace
trace(1)

gint a, b
sequence st

a = new_int()
b = new_int()

printf(1, "Status: (0 for good) %d\n", {int_set_string(a, "1234", 10)})

int_set(b, a)

int_add(a, a, b)
int_sub(a, b, a)

st = int_get_string(10, a)
printf(1, "Answer is: %s\n", {st})

delete_int(a)
delete_int(b)

puts(1, "Hi world!\n")
getc(0)
