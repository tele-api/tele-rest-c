#ifndef replace_sticker_in_set_response_TEST
#define replace_sticker_in_set_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define replace_sticker_in_set_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/replace_sticker_in_set_response.h"
replace_sticker_in_set_response_t* instantiate_replace_sticker_in_set_response(int include_optional);



replace_sticker_in_set_response_t* instantiate_replace_sticker_in_set_response(int include_optional) {
  replace_sticker_in_set_response_t* replace_sticker_in_set_response = NULL;
  if (include_optional) {
    replace_sticker_in_set_response = replace_sticker_in_set_response_create(
      1,
      1
    );
  } else {
    replace_sticker_in_set_response = replace_sticker_in_set_response_create(
      1,
      1
    );
  }

  return replace_sticker_in_set_response;
}


#ifdef replace_sticker_in_set_response_MAIN

void test_replace_sticker_in_set_response(int include_optional) {
    replace_sticker_in_set_response_t* replace_sticker_in_set_response_1 = instantiate_replace_sticker_in_set_response(include_optional);

	cJSON* jsonreplace_sticker_in_set_response_1 = replace_sticker_in_set_response_convertToJSON(replace_sticker_in_set_response_1);
	printf("replace_sticker_in_set_response :\n%s\n", cJSON_Print(jsonreplace_sticker_in_set_response_1));
	replace_sticker_in_set_response_t* replace_sticker_in_set_response_2 = replace_sticker_in_set_response_parseFromJSON(jsonreplace_sticker_in_set_response_1);
	cJSON* jsonreplace_sticker_in_set_response_2 = replace_sticker_in_set_response_convertToJSON(replace_sticker_in_set_response_2);
	printf("repeating replace_sticker_in_set_response:\n%s\n", cJSON_Print(jsonreplace_sticker_in_set_response_2));
}

int main() {
  test_replace_sticker_in_set_response(1);
  test_replace_sticker_in_set_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // replace_sticker_in_set_response_MAIN
#endif // replace_sticker_in_set_response_TEST
