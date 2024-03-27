#ifndef MYFUNCTIONS_H
#define MYFUNCTIONS_H

#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Flags {
  int e;
  int i;
  int v;
  int c;
  int l;
  int n;
  int h;
  int s;
  int f;
  int o;
};

char process_command_line_arguments(int argc, char *argv[], struct Flags *flags,
                                    char *combinedPattern);
void polya_reader(struct Flags flags, char **pattern, int argument_count,
                  char *combinedPattern);

#endif