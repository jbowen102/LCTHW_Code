#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dbg.h"

#define MAX_NUM_FILES 50
#define MAX_PATH_LEN 200
#define MAX_BUFFER 500
// #define LOG_FILE_LIST "./.logfind_files"


struct Connection {
  FILE *file;
  char path[MAX_PATH_LEN];
  char entry[MAX_PATH_LEN];
};


struct Connection *create_conn(char *filepath)
{
  struct Connection *conn = malloc(sizeof(struct Connection));

  conn->file = fopen(filepath, "r");
  // conn->path = filepath;
  strcpy(conn->path, filepath);
  // Confirmed in get_next_path() that src size not larger than MAX_PATH_LEN.

  return conn;
}


void close_conn(struct Connection *conn)
{
  if (conn->file) {
    fclose(conn->file);
  }

  free(conn);
}


int get_next_path(struct Connection *list_conn)
{
  // Reset string to all 0s:
  memset(list_conn->entry, 0, strlen(list_conn->entry));
  // https://stackoverflow.com/questions/8107826/proper-way-to-empty-a-c-string
  // fgets return value is a string pointer to the dest string memory loc.
  fgets(list_conn->entry, MAX_PATH_LEN, list_conn->file);
  // https://stackoverflow.com/questions/18253413/difference-between-fgets-and-fread
  check(strlen(list_conn->entry) < MAX_PATH_LEN - 1, "Possible path truncation: %s", list_conn->entry);

  // Eliminate the trailing newline character:
  list_conn->entry[strcspn(list_conn->entry, "\n")] = 0;
  // https://stackoverflow.com/questions/2693776/removing-trailing-newline-character-from-fgets-input

  return 0;
error:
  return -1;
}


int fill_log_list(struct Connection *list_conn, char log_list[MAX_NUM_FILES][MAX_PATH_LEN])
{
  int file_index = 0;
  for ( ; file_index < MAX_NUM_FILES; file_index++)
  {
    int rc = get_next_path(list_conn);
    check(rc != -1, "get_next_path failed at file_index %d", file_index);

    if (!list_conn->entry[0]) {
      break;
    } else {
      // log_info("Value of list_conn->file: %s", list_conn->entry);
      strcpy(log_list[file_index], list_conn->entry);
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
  printf("\n");

  // log_info("filepath: %s", list_conn->entry);

  return file_index;
error:
  return -1;
}


// // Rabin-carp algorithm. Time complexity (expected): O(n+m), where n = strlen(file_conn->entry) and m = strlen(search_term)
// int faster_substring_search(struct Connection *file_conn, char *search_term)
// {
//
// }
// Algorithm Design Manual 3.7.2 (p. 91)


// // naive search. Time complexity (worst-case): O(nm), where n = strlen(file_conn->entry) and m = strlen(search_term)
// // no longer used. Using strncmp directly in entry_search now.
// int substring_search(char *search_window, char *search_term)
// {
//   int rc = strncmp(search_window, search_term, strlen(search_term));
//   if (rc == 0) {
//       debug("string match\n");
//       return 1;
//     } else {
//       return 0;
//     }
//
// error:
//   return -1;
// }


int entry_search(struct Connection *file_conn, char **search_terms)
{
  char *search_term = search_terms[0];

  int search_length = strlen(search_term);
  // If line is shorter than search term, skip:
  if (strlen(file_conn->entry) < search_length) {
    return 0;
  }

  debug("[LINE]: %s", file_conn->entry);
  debug("strlen(entry) = %ld", strlen(file_conn->entry));
  debug("search_length for search pattern \"%s\": %d", search_term, search_length);
  debug("loop limit: %ld\n", strlen(file_conn->entry)-search_length);

  for (int c = 0; c < strlen(file_conn->entry)-search_length+1; c++)
  {
    debug("\tc: %d", c);

    int rc = strncmp(file_conn->entry+c, search_term, search_length);
    if (rc == 0) {
        debug("string match\n");
        return 1;
      }
  }
  return 0;
error:
  return -1;
}


int file_search_or(struct Connection *file_conn, char **search_terms)
{
  printf("\n");
  log_info("file_search running on %s\n", file_conn->path);

  char *ret = "s";

  do {
    // Reset string to all 0s:
    memset(file_conn->entry, 0, strlen(file_conn->entry));

    // Read line in from file.
    ret = fgets(file_conn->entry, MAX_BUFFER, file_conn->file);
    check(strlen(file_conn->entry) < MAX_BUFFER - 1, "Possible entry truncation: %s", file_conn->entry);

    // Eliminate the trailing newline character:
    file_conn->entry[strcspn(file_conn->entry, "\n")] = 0;

    // search file_conn->entry (the file's current line) for term(s) in question
    int rc = entry_search(file_conn, search_terms);
    check(rc != -1, "entry_search failed at entry %s", file_conn->entry);
    if (rc == 1) {
      // match found!
      printf("%s\n", file_conn->entry);
    }

    // return 0;    // to search just first line of each file.

  } while (ret != NULL);

  return 0;
error:
  return -1;
}

int file_search_and(struct Connection *file_conn, char **search_terms)
{
  printf("\n");
  log_info("file_search running on %s\n", file_conn->path);

  char *ret = "s";

  do {
    // Reset string to all 0s:
    memset(file_conn->entry, 0, strlen(file_conn->entry));

    // Read line in from file.
    ret = fgets(file_conn->entry, MAX_BUFFER, file_conn->file);
    check(strlen(file_conn->entry) < MAX_BUFFER - 1, "Possible entry truncation: %s", file_conn->entry);

    // Eliminate the trailing newline character:
    file_conn->entry[strcspn(file_conn->entry, "\n")] = 0;

    // search file_conn->entry (the file's current line) for term(s) in question
    int rc = entry_search(file_conn, search_terms);
    check(rc != -1, "entry_search failed at entry %s", file_conn->entry);
    if (rc == 1) {
      // match found!
      printf("%s\n", file_conn->entry);
    }

    // return 0;    // to search just first line of each file.

  } while (ret != NULL);

  return 0;
error:
  return -1;
}


int main(int argc, char *argv[])
{

  check(argc >= 2, "Need at least one search term (use \"-o\" for \"or\").");

  int and_mode;
  int term_count;
  char **search_terms;
  if (strncmp(argv[1], "-o", 2) == 0) {
    check(argc > 2, "Need a search term after the \"-o\"");
    and_mode = 0;
    term_count = argc-2;
    search_terms = argv+2;
  } else {
    and_mode = 1;
    term_count = argc-1;
    search_terms = argv+1;
  }

  debug("mode: %s\n", (and_mode ? "AND" : "OR"));

  debug("term_count: %d", term_count);
  debug("search_terms:");
  for (int i = 0; i < term_count; i++)
  {
    debug("\t%s", search_terms[i]);
  }

  char *log_list_loc = "./.logfind_files";
  struct Connection *list_conn = create_conn(log_list_loc);

  char log_list[MAX_NUM_FILES][MAX_PATH_LEN];

  int file_count = fill_log_list(list_conn, log_list);
  check(file_count != -1, "fill_log_list failed");

  struct Connection *file_conn;
  for (int i = 0; i < file_count; i++)
  {
    file_conn = create_conn(log_list[i]);

    int rc = -1;
    if (and_mode) {
      rc = file_search_or(file_conn, search_terms);
    } else {
      rc = file_search_and(file_conn, search_terms);
    }
    check(rc != -1, "file_search failed at file %d: %s", i, log_list[i]);

    close_conn(file_conn);

      // return 0;    // comment this out to limit searching to just first file.

  }

  // free stuff
  close_conn(list_conn);
  return 0;

error:
  fcloseall();
  if (list_conn) close_conn(list_conn);
  if (file_conn) close_conn(file_conn);
  return -1;
}
