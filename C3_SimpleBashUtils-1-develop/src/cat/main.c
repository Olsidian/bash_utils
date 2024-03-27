#include "header.h"

int main(int argc, char *argv[]) {
  const struct option LONG_OPTIONS[] = {
      {"show-nonprinting", no_argument, 0, 'v'},
      {"number-nonblank", no_argument, 0, 'b'},
      {"show-ends", no_argument, 0, 'e'},
      {"number", no_argument, 0, 'n'},
      {"squeeze-blank", no_argument, 0, 's'},
      {"show-tabs", no_argument, 0, 't'},
      {0, 0, 0, 0}};

  Flags flags = {0};

  int opt;

  while ((opt = getopt_long(argc, argv, "vbenstT", LONG_OPTIONS, 0)) != -1) {
    switch (opt) {
      case 'v':
        flags.v = 1;
        break;
      case 'b':
        flags.b = 1;
        break;
      case 'e':
        flags.e = 1;
        flags.v = 1;
        break;
      case 'n':
        flags.n = 1;
        break;
      case 's':
        flags.s = 1;
        break;
      case 't':
        flags.t = 1;
        flags.v = 1;
        break;
      case 'T':
        flags.t = 1;
        break;
      default:

        fprintf(stderr,
                "Использование: %s [--show-nonprinting] [--number-nonblank] "
                "[--show-ends] [--number] [--squeeze-blank] [--show-tabs]\n",
                argv[0]);
    }
  }

  if (optind >= argc) {
    fprintf(stderr, "Ожидается аргумент после опций\n");
    return 3;
  }
  for (int i = optind; i < argc; i++) {
    FILE *file = fopen(argv[i], "r");
    if (file == NULL) {
      perror("Ошибка открытия файла");
      return 2;
    }
    process_file(&flags, file);
  }
  return 0;
}