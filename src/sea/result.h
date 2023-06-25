#ifndef SEA_RESULT_H
#define SEA_RESULT_H

#include "sea/error.h"

typedef enum sea_Result_Status_def {
  SEA_RESULT_OK = 0,
  SEA_RESULT_FAIL = 1,
  SEA_RESULT_NONE = 2,
  SEA_RESULT_MAX = 3,
} sea_Result_Status;

#define sea_Result_(T) \
typedef struct sea_Result_##T##_def {\
  union {\
    T value;\
    sea_Error error;\
  };\
  sea_Result_Status status;\
} sea_Result_##T;\
\



#endif  // SEA_RESULT_H
