#ifndef create_new_sticker_set_request_TEST
#define create_new_sticker_set_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define create_new_sticker_set_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/create_new_sticker_set_request.h"
create_new_sticker_set_request_t* instantiate_create_new_sticker_set_request(int include_optional);



create_new_sticker_set_request_t* instantiate_create_new_sticker_set_request(int include_optional) {
  create_new_sticker_set_request_t* create_new_sticker_set_request = NULL;
  if (include_optional) {
    create_new_sticker_set_request = create_new_sticker_set_request_create(
      56,
      "0",
      "0",
      list_createList(),
      telegram_bot_api_create_new_sticker_set_request_STICKERTYPE_mask,
      1
    );
  } else {
    create_new_sticker_set_request = create_new_sticker_set_request_create(
      56,
      "0",
      "0",
      list_createList(),
      telegram_bot_api_create_new_sticker_set_request_STICKERTYPE_mask,
      1
    );
  }

  return create_new_sticker_set_request;
}


#ifdef create_new_sticker_set_request_MAIN

void test_create_new_sticker_set_request(int include_optional) {
    create_new_sticker_set_request_t* create_new_sticker_set_request_1 = instantiate_create_new_sticker_set_request(include_optional);

	cJSON* jsoncreate_new_sticker_set_request_1 = create_new_sticker_set_request_convertToJSON(create_new_sticker_set_request_1);
	printf("create_new_sticker_set_request :\n%s\n", cJSON_Print(jsoncreate_new_sticker_set_request_1));
	create_new_sticker_set_request_t* create_new_sticker_set_request_2 = create_new_sticker_set_request_parseFromJSON(jsoncreate_new_sticker_set_request_1);
	cJSON* jsoncreate_new_sticker_set_request_2 = create_new_sticker_set_request_convertToJSON(create_new_sticker_set_request_2);
	printf("repeating create_new_sticker_set_request:\n%s\n", cJSON_Print(jsoncreate_new_sticker_set_request_2));
}

int main() {
  test_create_new_sticker_set_request(1);
  test_create_new_sticker_set_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // create_new_sticker_set_request_MAIN
#endif // create_new_sticker_set_request_TEST
