#include "header.h"

char process_command_line_arguments(int argc, char *argv[], struct Flags *flags,
                                    char *combinedPattern) {
  int key;
  // int i = 1;
  int pattern_count = 0;
  while ((key = getopt(argc, argv, "e:ivclnhsof:")) != -1) {
    switch (key) {
      case 'e':
        flags->e = 1;
        if (pattern_count != 0) {
          strcat(combinedPattern, "|");
        }
        strcat(combinedPattern, optarg);
        pattern_count++;
        break;
      case 'i':
        flags->i = REG_ICASE;
        break;
      case 'v':
        flags->v = 1;
        break;
      case 'c':
        flags->c = 1;
        break;
      case 'l':
        flags->l = 1;
        break;
      case 'n':
        flags->n = 1;
        break;
      case 'h':
        flags->h = 1;
        break;
      case 's':
        flags->s = 1;
        break;
      case 'f':
        flags->f = 1;
        FILE *file = fopen(optarg, "r");
        if (file != NULL) {
          char file_space[5000];
          if (pattern_count != 0) {
            strcat(combinedPattern, "|");
          }
          while ((fgets(file_space, 5000, file)) != NULL) {
            strncat(combinedPattern, file_space, strlen(file_space) - 1);
            strcat(combinedPattern, "|");
          }
          combinedPattern[strlen(combinedPattern) - 1] = '\0';
          pattern_count++;
          fclose(file);
        } else {
          fprintf(stderr, "grep: %s: No such file or directory\n", optarg);
          return 1;
        }
        break;
      case 'o':
        flags->o = 1;
        break;
      default:
        fprintf(stderr, "Usage: [options] template [file_name]\n");
    }
  }
  if (!flags->e && !flags->f) optind++;

  return 0;
}
