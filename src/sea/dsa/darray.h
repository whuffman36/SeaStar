#ifndef SEA_DSA_DARRAY_H
#define SEA_DSA_DARRAY_H

#include <stddef.h>
#include <stdlib.h>

#define sea_Darray_(T) \
typedef struct sea_Darray_##T##_def {\
  T* data;\
  size_t size;\
  size_t capacity;\
} sea_Darray_##T;\
\
/*\
* Creates a new `sea_Darray` with `size` elements of type T.\
* Allocated memory is zeroed. If size is 0, no allocation happens and\
* an empty `sea_Darray` is returned.\
*/\
sea_Darray_##T sea_Darray_##T##_Create(size_t size) {\
  sea_Darray_##T self;\
  if (size > 0) {\
    self.data = (T*)calloc(size, sizeof(T));\
    self.size = size;\
    self.capacity = size;\
    return self;\
  }\
  self.data = NULL;\
  self.size = 0;\
  self.capacity = 0;\
  return self;\
}\
\
/*\
* Creates a new `sea_Darray` with the same data as `other`.\
*/\
sea_Darray_##T sea_Darray_##T##_CopyFrom(const sea_Darray_##T* const other) {\
  sea_Darray_##T self;\
  self.data = (T*)malloc(sizeof(T) * other->capacity);\
  self.size = other->size;\
  self.capacity = other->capacity;\
  \
  for (size_t i = 0; i < self.size; ++i) {\
    self.data[i] = other->data[i];\
  }\
  return self;\
}\
\
/*\
* Adds `data` to the end of `self`. Memory reallocation may happen.\
*/\
void sea_Darray_##T##_Append(sea_Darray_##T* const self, T data) {\
  if (self->size == self->capacity) {\
    self->data = (T*)realloc(self->data, sizeof(T) * self->capacity * 2);\
    if (self->data == NULL) {\
      return;\
    }\
    self->capacity = self->capacity * 2;\
    self->data[(self->size)++] = data;\
    return;\
  }\
  self->data[(self->size)++] = data;\
}\
\
/*\
* Frees resources for `self`.\
*/\
void sea_Darray_##T##_Destroy(sea_Darray_##T* const self) {\
  free(self->data);\
  self->data = NULL;\
  self->size = 0;\
  self->capacity = 0;\
}\




#endif  // SEA_DSA_DARRAY_H
