#ifndef add_sticker_to_set_request_TEST
#define add_sticker_to_set_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define add_sticker_to_set_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/add_sticker_to_set_request.h"
add_sticker_to_set_request_t* instantiate_add_sticker_to_set_request(int include_optional);

#include "test_input_sticker.c"


add_sticker_to_set_request_t* instantiate_add_sticker_to_set_request(int include_optional) {
  add_sticker_to_set_request_t* add_sticker_to_set_request = NULL;
  if (include_optional) {
    add_sticker_to_set_request = add_sticker_to_set_request_create(
      56,
      "0",
       // false, not to have infinite recursion
      instantiate_input_sticker(0)
    );
  } else {
    add_sticker_to_set_request = add_sticker_to_set_request_create(
      56,
      "0",
      NULL
    );
  }

  return add_sticker_to_set_request;
}


#ifdef add_sticker_to_set_request_MAIN

void test_add_sticker_to_set_request(int include_optional) {
    add_sticker_to_set_request_t* add_sticker_to_set_request_1 = instantiate_add_sticker_to_set_request(include_optional);

	cJSON* jsonadd_sticker_to_set_request_1 = add_sticker_to_set_request_convertToJSON(add_sticker_to_set_request_1);
	printf("add_sticker_to_set_request :\n%s\n", cJSON_Print(jsonadd_sticker_to_set_request_1));
	add_sticker_to_set_request_t* add_sticker_to_set_request_2 = add_sticker_to_set_request_parseFromJSON(jsonadd_sticker_to_set_request_1);
	cJSON* jsonadd_sticker_to_set_request_2 = add_sticker_to_set_request_convertToJSON(add_sticker_to_set_request_2);
	printf("repeating add_sticker_to_set_request:\n%s\n", cJSON_Print(jsonadd_sticker_to_set_request_2));
}

int main() {
  test_add_sticker_to_set_request(1);
  test_add_sticker_to_set_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // add_sticker_to_set_request_MAIN
#endif // add_sticker_to_set_request_TEST
