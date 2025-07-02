#ifndef add_sticker_to_set_response_TEST
#define add_sticker_to_set_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define add_sticker_to_set_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/add_sticker_to_set_response.h"
add_sticker_to_set_response_t* instantiate_add_sticker_to_set_response(int include_optional);



add_sticker_to_set_response_t* instantiate_add_sticker_to_set_response(int include_optional) {
  add_sticker_to_set_response_t* add_sticker_to_set_response = NULL;
  if (include_optional) {
    add_sticker_to_set_response = add_sticker_to_set_response_create(
      1,
      1
    );
  } else {
    add_sticker_to_set_response = add_sticker_to_set_response_create(
      1,
      1
    );
  }

  return add_sticker_to_set_response;
}


#ifdef add_sticker_to_set_response_MAIN

void test_add_sticker_to_set_response(int include_optional) {
    add_sticker_to_set_response_t* add_sticker_to_set_response_1 = instantiate_add_sticker_to_set_response(include_optional);

	cJSON* jsonadd_sticker_to_set_response_1 = add_sticker_to_set_response_convertToJSON(add_sticker_to_set_response_1);
	printf("add_sticker_to_set_response :\n%s\n", cJSON_Print(jsonadd_sticker_to_set_response_1));
	add_sticker_to_set_response_t* add_sticker_to_set_response_2 = add_sticker_to_set_response_parseFromJSON(jsonadd_sticker_to_set_response_1);
	cJSON* jsonadd_sticker_to_set_response_2 = add_sticker_to_set_response_convertToJSON(add_sticker_to_set_response_2);
	printf("repeating add_sticker_to_set_response:\n%s\n", cJSON_Print(jsonadd_sticker_to_set_response_2));
}

int main() {
  test_add_sticker_to_set_response(1);
  test_add_sticker_to_set_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // add_sticker_to_set_response_MAIN
#endif // add_sticker_to_set_response_TEST
