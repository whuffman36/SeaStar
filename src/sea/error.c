#include "sea/error.h"

sea_Error sea_Error_Create(char* message, sea_Error_Type type) {
  sea_Error error;
  sea_Error_SetMessage(&error, message);
  sea_Error_SetType(&error, type);
  return error;
}

void sea_Error_SetMessage(sea_Error* const self, char* message) {
  self->message = message;
}

void sea_Error_SetType(sea_Error* const self, sea_Error_Type type) {
  if (type < SEA_ERROR_INTERNAL || type > SEA_ERROR_MAX) {
    type = SEA_ERROR_MAX;
  }
  self->type = type;
}

const char* sea_Error_GetType(const sea_Error* const self) {
  switch(self->type) {
    case SEA_ERROR_INTERNAL:
      return "SEA_ERROR_INTERNAL";
    case SEA_ERROR_IO:
      return "SEA_ERROR_IO";
    case SEA_ERROR_MEMORY:
      return "SEA_ERROR_MEMORY";
    default:
      return "SEA_ERROR_MAX";
  }
}
