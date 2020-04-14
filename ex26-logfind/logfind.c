#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dbg.h"

#define MAX_NUM_FILES 50
#define MAX_PATH_LEN 200
// #define LOG_FILE_LIST "./.logfind_files"


struct Connection {
  FILE *file;
  char current_filepath[MAX_PATH_LEN];
};


int get_next_path(struct Connection *conn)
{
  // int rc = fread(conn->current_filepath, MAX_PATH_LEN, 5, conn->file);
  // Reset string to all 0s:
  memset(conn->current_filepath, 0, strlen(conn->current_filepath));
  // https://stackoverflow.com/questions/8107826/proper-way-to-empty-a-c-string
  // fgets return value is a string pointer to the dest string memory loc.
  // char *str_returned = fgets(conn->current_filepath, MAX_PATH_LEN, conn->file);
  fgets(conn->current_filepath, MAX_PATH_LEN, conn->file);
  // https://stackoverflow.com/questions/18253413/difference-between-fgets-and-fread
  check(strlen(conn->current_filepath) < MAX_PATH_LEN - 1, "Possible path truncation: %s", conn->current_filepath);

  // Eliminate the trailing newline character:
  // if (conn->current_filepath[0]) {
  conn->current_filepath[strcspn(conn->current_filepath, "\n")] = 0;
  // https://stackoverflow.com/questions/2693776/removing-trailing-newline-character-from-fgets-input
  // log_info("\t(rc: %d)", rc);
  // return str_returned;

  return 0;
error:
  return -1;
}


int fill_log_list(struct Connection *conn, char log_list[MAX_NUM_FILES][MAX_PATH_LEN])
{
  int file_index = 0;
  for ( ; file_index < MAX_NUM_FILES; file_index++)
  {
    int rc = get_next_path(conn);
    check(rc == 0, "get_next_path failed at file_index %d", file_index);

    if (!conn->current_filepath[0]) {
      break;
    } else {
      // log_info("Value of conn->file: %s", conn->current_filepath);
      strcpy(log_list[file_index], conn->current_filepath);
      // https://stackoverflow.com/questions/14020380/strcpy-vs-strdup
      // From ex17: w/ strncpy normally need to include additional code to force end of dest
      // string to be '\0' in case src string too long, but that's handled in
      // get_next_path already.
      // w/ strcpy, normally need to include code to test that dest can fit src string.
    }
  }
  check(file_index < MAX_NUM_FILES, "Possible path-list truncation. " \
              "Check log_list length is less than %d", MAX_NUM_FILES);

  // log_info("sizeof(log_list) = %ld", sizeof(log_list)/MAX_PATH_LEN);
  printf("\nlog_list:\n");
  for (int n = 0; n < file_index; n++) {
    printf("%d) %s\n", n, log_list[n]);
  }

  // log_info("filepath: %s", conn->current_filepath);

  return 0;
error:
  return -1;
}


int main(int argc, char *argv[])
{
  char *log_list_loc = "./.logfind_files";

  struct Connection *conn = malloc(sizeof(struct Connection));
  conn->file = fopen(log_list_loc, "r");

  char log_list[MAX_NUM_FILES][MAX_PATH_LEN];

  int rc = fill_log_list(conn, log_list);
  check(rc == 0, "fill_log_list failed");


  // free stuff
  free(conn);
  return 0;

error:
  if (conn) free(conn);
}
