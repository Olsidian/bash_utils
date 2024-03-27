#ifndef MYFUNCTIONS_H
#define MYFUNCTIONS_H

#include <ctype.h>
#include <getopt.h>
#include <stdio.h>

#define ASCII_TABLE 127
#define NONPRINT 64

typedef struct {
  int v;
  int b;
  int e;
  int n;
  int s;
  int t;
  int T;
} Flags;

void process_file(Flags *flags, FILE *file);
void string_count(const char current_key, unsigned *const key_count);
void key_print(const char current_key);
void not_ASCII_print(Flags *flags, const char current_key);
void process_line_v(Flags *flags, const char current_key);
void process_line_b(Flags *flags, const char previos_key,
                    const char current_key);
void process_line_e(Flags *flags, const char current_key);
void process_line_n(Flags *flags, const char previos_key);
void process_line_s(Flags *flags, FILE *file);
void process_line_t(Flags *flags, const char current_key);

#endif
