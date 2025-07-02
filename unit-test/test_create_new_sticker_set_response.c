#ifndef create_new_sticker_set_response_TEST
#define create_new_sticker_set_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define create_new_sticker_set_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/create_new_sticker_set_response.h"
create_new_sticker_set_response_t* instantiate_create_new_sticker_set_response(int include_optional);



create_new_sticker_set_response_t* instantiate_create_new_sticker_set_response(int include_optional) {
  create_new_sticker_set_response_t* create_new_sticker_set_response = NULL;
  if (include_optional) {
    create_new_sticker_set_response = create_new_sticker_set_response_create(
      1,
      1
    );
  } else {
    create_new_sticker_set_response = create_new_sticker_set_response_create(
      1,
      1
    );
  }

  return create_new_sticker_set_response;
}


#ifdef create_new_sticker_set_response_MAIN

void test_create_new_sticker_set_response(int include_optional) {
    create_new_sticker_set_response_t* create_new_sticker_set_response_1 = instantiate_create_new_sticker_set_response(include_optional);

	cJSON* jsoncreate_new_sticker_set_response_1 = create_new_sticker_set_response_convertToJSON(create_new_sticker_set_response_1);
	printf("create_new_sticker_set_response :\n%s\n", cJSON_Print(jsoncreate_new_sticker_set_response_1));
	create_new_sticker_set_response_t* create_new_sticker_set_response_2 = create_new_sticker_set_response_parseFromJSON(jsoncreate_new_sticker_set_response_1);
	cJSON* jsoncreate_new_sticker_set_response_2 = create_new_sticker_set_response_convertToJSON(create_new_sticker_set_response_2);
	printf("repeating create_new_sticker_set_response:\n%s\n", cJSON_Print(jsoncreate_new_sticker_set_response_2));
}

int main() {
  test_create_new_sticker_set_response(1);
  test_create_new_sticker_set_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // create_new_sticker_set_response_MAIN
#endif // create_new_sticker_set_response_TEST
