#include "sea/dsa/darray.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

sea_Darray_(int)

int main(void) {

  sea_Darray_int dyn_array = sea_Darray_int_Create(5);

  assert(dyn_array.size == 5);
  assert(dyn_array.capacity == 5);
  assert(dyn_array.data[4] == 0);

  sea_Darray_int_Append(&dyn_array, 3);

  assert(dyn_array.size == 6);
  assert(dyn_array.capacity == 10);
  assert(dyn_array.data[4] == 0);
  assert(dyn_array.data[5] == 3);

  sea_Darray_int_Destroy(&dyn_array);

  printf("All tests pass.\n");
  return EXIT_SUCCESS;
}
