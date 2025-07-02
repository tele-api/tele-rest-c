#ifndef get_sticker_set_request_TEST
#define get_sticker_set_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define get_sticker_set_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/get_sticker_set_request.h"
get_sticker_set_request_t* instantiate_get_sticker_set_request(int include_optional);



get_sticker_set_request_t* instantiate_get_sticker_set_request(int include_optional) {
  get_sticker_set_request_t* get_sticker_set_request = NULL;
  if (include_optional) {
    get_sticker_set_request = get_sticker_set_request_create(
      "0"
    );
  } else {
    get_sticker_set_request = get_sticker_set_request_create(
      "0"
    );
  }

  return get_sticker_set_request;
}


#ifdef get_sticker_set_request_MAIN

void test_get_sticker_set_request(int include_optional) {
    get_sticker_set_request_t* get_sticker_set_request_1 = instantiate_get_sticker_set_request(include_optional);

	cJSON* jsonget_sticker_set_request_1 = get_sticker_set_request_convertToJSON(get_sticker_set_request_1);
	printf("get_sticker_set_request :\n%s\n", cJSON_Print(jsonget_sticker_set_request_1));
	get_sticker_set_request_t* get_sticker_set_request_2 = get_sticker_set_request_parseFromJSON(jsonget_sticker_set_request_1);
	cJSON* jsonget_sticker_set_request_2 = get_sticker_set_request_convertToJSON(get_sticker_set_request_2);
	printf("repeating get_sticker_set_request:\n%s\n", cJSON_Print(jsonget_sticker_set_request_2));
}

int main() {
  test_get_sticker_set_request(1);
  test_get_sticker_set_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // get_sticker_set_request_MAIN
#endif // get_sticker_set_request_TEST
