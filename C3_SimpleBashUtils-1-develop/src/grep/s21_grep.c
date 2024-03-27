#include "header.h"

void polya_reader(struct Flags flags, char **pattern, int argument_count,
                  char *combinedPattern) {
  int regx = 0;
  regex_t regex;
  FILE *file;
  regmatch_t match;
  if (flags.e || flags.f) {
    regcomp(&regex, combinedPattern, REG_EXTENDED | flags.i);
  } else {
    regcomp(&regex, pattern[optind - 1], REG_EXTENDED | flags.i);
  }
  for (int i = optind; i < argument_count; i++) {
    int match_count = 0;
    int line_number = 0;
    int filename_printed = 0;
    file = fopen(pattern[i], "r");
    if ((file != NULL)) {
      char string2[1024];
      while (fgets(string2, 1024, file) != NULL) {
        if (string2[strlen(string2) - 1] == '\n') {
          string2[strlen(string2) - 1] = '\0';
        }
        line_number++;
        regx = regexec(&regex, string2, 1, &match, 0);
        if (regx == flags.v && !((flags.v == 1) && (flags.o == 1))) {
          if ((flags.h == 0) && (flags.c == 0) && (flags.l == 0) &&
              argument_count - optind > 1 && !filename_printed) {
            printf("%s:", pattern[i]);
            filename_printed = 1;
            if (flags.o == 0) {
              filename_printed = 0;
            }
          }
          if ((flags.n) && (flags.o == 0) && (flags.c == 0) && (flags.l == 0)) {
            printf("%d:", line_number);
          }
          if ((flags.o) && (flags.c == 0) && (flags.l == 0)) {
            int offset = 0;
            while (regexec(&regex, string2 + offset, 1, &match, 0) == 0) {
              char *o_string =
                  calloc(match.rm_eo - match.rm_so + 2, sizeof(char));
              strncpy(o_string, string2 + offset + match.rm_so,
                      match.rm_eo - match.rm_so);
              strcat(o_string, "\n\0");
              if ((flags.h == 0) && (flags.c == 0) && (flags.l == 0) &&
                  argument_count - optind > 1 && !filename_printed) {
                printf("%s:", pattern[i]);
                filename_printed = 1;
              }
              if (flags.n) {
                printf("%d:", line_number);
              }
              printf("%s", o_string);
              free(o_string);
              offset += match.rm_eo;
              filename_printed = 0;
            }
          } else {
            if ((!(flags.l)) && (!(flags.c))) printf("%s\n", string2);
          }
        }
        if (regx == flags.v) {
          match_count++;
        }
      }
      if ((flags.l && match_count > 0) && ((flags.c == 0) || (flags.f == 1) ||
                                           (argument_count - optind >= 1))) {
        printf("%s\n", pattern[i]);
      } else if ((flags.c) && (flags.l == 0)) {
        if ((argument_count - optind > 1) && (flags.h == 0)) {
          printf("%s:%d\n", pattern[i], match_count);
        } else {
          printf("%d\n", match_count);
        }
      }
      fclose(file);
    } else if ((!flags.s) && (file == NULL)) {
      fprintf(stderr, "grep: %s: No such file or directory\n", pattern[i]);
    }
  }
  regfree(&regex);
}
