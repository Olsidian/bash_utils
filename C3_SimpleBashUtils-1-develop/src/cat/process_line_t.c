#include "header.h"

void process_line_t(Flags *flags, const char current_key) {
  if (flags->t && current_key == '\t') {
    printf("^I");
  }
}
