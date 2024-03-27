#include "header.h"

void process_line_e(Flags *flags, const char current_key) {
  if (flags->e) {
    if (current_key == '\t') {
      fputc(current_key, stdout);
    } else if (current_key == '\n') {
      fputc('$', stdout);
    }
  }
}
