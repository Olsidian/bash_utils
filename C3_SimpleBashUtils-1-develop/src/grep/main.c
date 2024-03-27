#include "header.h"

int main(int argc, char *argv[]) {
  struct Flags flags = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

  char combinedPattern[20000] = "";

  if (argc <= 1) {
    fprintf(stderr, "Usage: [options] template [file_name]\n");
    return 1;
  }
  process_command_line_arguments(argc, argv, &flags, combinedPattern);
  polya_reader(flags, argv, argc, combinedPattern);
  if (fflush(stdout)) {
    printf("\n");
  }

  return 0;
}
