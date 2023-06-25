#ifndef SEA_ERROR_H
#define SEA_ERROR_H

typedef enum sea_Error_Type_def {
  SEA_ERROR_INTERNAL = 0,
  SEA_ERROR_IO = 1,
  SEA_ERROR_MEMORY = 2,
  SEA_ERROR_MAX = 3,
} sea_Error_Type;

typedef struct sea_Error_def {
  char* message;
  sea_Error_Type type;
} sea_Error;


sea_Error sea_Error_Create(char* message, sea_Error_Type type);

void sea_Error_SetMessage(sea_Error* const self, char* message);

void sea_Error_SetType(sea_Error* const self, sea_Error_Type type);

const char* sea_Error_GetType(const sea_Error* const self);

#endif
