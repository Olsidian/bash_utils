#include "header.h"

void process_file(Flags *flags, FILE *file) {
  static char previos_key = '\n';
  static unsigned key_count = 1;
  char current_key = fgetc(file);

  while (!feof(file)) {
    if (flags->s) {
      string_count(current_key, &key_count);
    }
    if (current_key != '\n' || key_count <= 2) {
      if (flags->b) {
        process_line_b(flags, previos_key, current_key);
      } else {
        process_line_n(flags, previos_key);
      }
      if (isprint(current_key)) {
        key_print(current_key);
      } else if (current_key == '\t') {
        if (flags->t) {
          process_line_t(flags, current_key);
        } else {
          key_print(current_key);
        }
      } else if (current_key == '\n') {
        process_line_e(flags, current_key);
        key_print(current_key);

      } else if (iscntrl(current_key) && current_key != '\t' &&
                 current_key != '\n') {
        process_line_v(flags, current_key);
      } else if (!isprint((unsigned char)current_key)) {
        not_ASCII_print(flags, current_key);
      }
      if (previos_key == '\n' && current_key == '\n') {
        process_line_s(flags, file);
      }
    }

    previos_key = current_key;
    current_key = fgetc(file);
  }

  fclose(file);
}

void string_count(const char current_key, unsigned *const key_count) {
  if (current_key == '\n') {
    *key_count += 1;
  } else {
    *key_count = 0;
  }
}

void key_print(const char current_key) { fputc(current_key, stdout); }
