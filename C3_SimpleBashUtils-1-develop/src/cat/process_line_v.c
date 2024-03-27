#include "header.h"

void process_line_v(Flags *flags, const char current_key) {
  if (flags->v) {
    key_print('^');
    if (current_key == ASCII_TABLE && current_key != '\t') {
      key_print(current_key - NONPRINT);
    } else {
      key_print(current_key + NONPRINT);
    }
  } else {
    key_print(current_key);
  }
}

void not_ASCII_print(Flags *flags, const char current_key) {
  if (flags->v) {
    const char not_ASCII = (signed char)current_key + ASCII_TABLE + 1;
    key_print('M');
    key_print('-');
    if (isprint(not_ASCII)) {
      key_print(not_ASCII);
    } else {
      process_line_v(flags, not_ASCII);
    }
  } else {
    key_print(current_key);
  }
}