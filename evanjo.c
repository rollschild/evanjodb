#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct InputBufferTemplate {
  char* buffer_;
  size_t buffer_len_;
  ssize_t input_len_;
};

struct InputBufferTemplate* NewInputBuffer() {
  struct InputBufferTemplate* input_buffer_ptr = malloc(
      sizeof(struct InputBufferTemplate));
  input_buffer_ptr->buffer_ = NULL;
  input_buffer_ptr->buffer_len_ = 0;
  input_buffer_ptr->input_len_ = 0;

  return input_buffer_ptr;
};

void PrintPrompt() {
  printf("evanjodb=$ ");
};

void ReadInput(struct InputBufferTemplate* input_buffer_ptr) {
  ssize_t bytes_read = getline(&(input_buffer_ptr->buffer_), 
                                &(input_buffer_ptr->buffer_len_),
                                stdin);
  // buffer_read will return 1 even if nothing input
  // ...because of the end-of-line
  if (bytes_read < 0) {
    printf("Invalid input!\n");
    exit(EXIT_FAILURE);
  }
  /*
  else if (buffer_read == 0) {
     
  }
  */

  input_buffer_ptr->input_len_ = bytes_read - 1;
  input_buffer_ptr->buffer_[bytes_read - 1] = 0;
};

// First step is to realize REPL
int main(int argc, char* argv[]) {
  struct InputBufferTemplate InputBuffer;
  struct InputBufferTemplate* input_buffer_ptr = NewInputBuffer();
  while(true) {
    PrintPrompt();
    ReadInput(input_buffer_ptr);

    // For now, only .exit is recognizable
    if (strcmp(input_buffer_ptr->buffer_, ".exit") == 0) {
      printf("So I will see you when I see you :-)\n");
      exit(EXIT_SUCCESS); // ?
    }
    else {
      printf("Unrecognized command \"%s\"!\n", input_buffer_ptr->buffer_);
    }
  }
}
