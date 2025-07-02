#ifndef replace_sticker_in_set_request_TEST
#define replace_sticker_in_set_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define replace_sticker_in_set_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/replace_sticker_in_set_request.h"
replace_sticker_in_set_request_t* instantiate_replace_sticker_in_set_request(int include_optional);

#include "test_input_sticker.c"


replace_sticker_in_set_request_t* instantiate_replace_sticker_in_set_request(int include_optional) {
  replace_sticker_in_set_request_t* replace_sticker_in_set_request = NULL;
  if (include_optional) {
    replace_sticker_in_set_request = replace_sticker_in_set_request_create(
      56,
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_input_sticker(0)
    );
  } else {
    replace_sticker_in_set_request = replace_sticker_in_set_request_create(
      56,
      "0",
      "0",
      NULL
    );
  }

  return replace_sticker_in_set_request;
}


#ifdef replace_sticker_in_set_request_MAIN

void test_replace_sticker_in_set_request(int include_optional) {
    replace_sticker_in_set_request_t* replace_sticker_in_set_request_1 = instantiate_replace_sticker_in_set_request(include_optional);

	cJSON* jsonreplace_sticker_in_set_request_1 = replace_sticker_in_set_request_convertToJSON(replace_sticker_in_set_request_1);
	printf("replace_sticker_in_set_request :\n%s\n", cJSON_Print(jsonreplace_sticker_in_set_request_1));
	replace_sticker_in_set_request_t* replace_sticker_in_set_request_2 = replace_sticker_in_set_request_parseFromJSON(jsonreplace_sticker_in_set_request_1);
	cJSON* jsonreplace_sticker_in_set_request_2 = replace_sticker_in_set_request_convertToJSON(replace_sticker_in_set_request_2);
	printf("repeating replace_sticker_in_set_request:\n%s\n", cJSON_Print(jsonreplace_sticker_in_set_request_2));
}

int main() {
  test_replace_sticker_in_set_request(1);
  test_replace_sticker_in_set_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // replace_sticker_in_set_request_MAIN
#endif // replace_sticker_in_set_request_TEST
