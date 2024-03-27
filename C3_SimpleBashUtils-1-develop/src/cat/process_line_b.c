#include "header.h"

void process_line_b(Flags *flags, const char previos_key,
                    const char current_key) {
  static unsigned string_count = 0;
  if (flags->b && previos_key == '\n' && current_key != '\n') {
    fprintf(stdout, "%6u\t", ++string_count);
  }
}
