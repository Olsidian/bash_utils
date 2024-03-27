#include "header.h"

void process_line_n(Flags *flags, const char previos_key) {
  static unsigned string_count = 0;
  if (flags->n && previos_key == '\n') {
    fprintf(stdout, "%6u\t", ++string_count);
  }
}
