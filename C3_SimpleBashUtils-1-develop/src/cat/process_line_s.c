#include "header.h"

void process_line_s(Flags *flags, FILE *file) {
  if (flags->s) {
    char current_key = fgetc(file);
    while (current_key == '\n') {
      current_key = fgetc(file);
    }
    ungetc(current_key, file);
  }
}
