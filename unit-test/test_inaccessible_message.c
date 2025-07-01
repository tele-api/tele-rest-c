#ifndef inaccessible_message_TEST
#define inaccessible_message_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define inaccessible_message_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/inaccessible_message.h"
inaccessible_message_t* instantiate_inaccessible_message(int include_optional);

#include "test_chat.c"


inaccessible_message_t* instantiate_inaccessible_message(int include_optional) {
  inaccessible_message_t* inaccessible_message = NULL;
  if (include_optional) {
    inaccessible_message = inaccessible_message_create(
       // false, not to have infinite recursion
      instantiate_chat(0),
      56,
      56
    );
  } else {
    inaccessible_message = inaccessible_message_create(
      NULL,
      56,
      56
    );
  }

  return inaccessible_message;
}


#ifdef inaccessible_message_MAIN

void test_inaccessible_message(int include_optional) {
    inaccessible_message_t* inaccessible_message_1 = instantiate_inaccessible_message(include_optional);

	cJSON* jsoninaccessible_message_1 = inaccessible_message_convertToJSON(inaccessible_message_1);
	printf("inaccessible_message :\n%s\n", cJSON_Print(jsoninaccessible_message_1));
	inaccessible_message_t* inaccessible_message_2 = inaccessible_message_parseFromJSON(jsoninaccessible_message_1);
	cJSON* jsoninaccessible_message_2 = inaccessible_message_convertToJSON(inaccessible_message_2);
	printf("repeating inaccessible_message:\n%s\n", cJSON_Print(jsoninaccessible_message_2));
}

int main() {
  test_inaccessible_message(1);
  test_inaccessible_message(0);

  printf("Hello world \n");
  return 0;
}

#endif // inaccessible_message_MAIN
#endif // inaccessible_message_TEST
