#include <stdio.h>
#include <stdlib.h>
#include "dbg.h"

#define MAX_PATH_LEN 200
// #define LOG_FILE_LIST "./.logfind_files"

struct Connection {
  FILE *file;
  char current_filepath[MAX_PATH_LEN];
};


// // Function to find line of text w/ word for an individual log file
// void grepper(char *log_filename)
// {
//
//
// }


// function to read new line when main() asks for it
// int get_next_path(struct Connection *conn)
// {
//   int rc = fread(conn->current_filepath, MAX_PATH_LEN, 1, conn->file);
// 	check(rc == 1, "Couldn't read from file list.");
//
//   return 0;
//
// error:
//   return -1;
// }
int get_next_path(struct Connection *conn)
{
  int rc = fread(conn->current_filepath, MAX_PATH_LEN, 1, conn->file);
  if (rc == 1) {
    return -1;
  } else {
    return 0;
  }

}


int main(int argc, char *argv[])
{
  char *log_file_list = "./.logfind_files";

  struct Connection *conn = malloc(sizeof(struct Connection));
  conn->file = fopen(log_file_list, "r");

  get_next_path(conn);

  printf("filepath: %s", conn->current_filepath);

  // free stuff
  return 0;
}
