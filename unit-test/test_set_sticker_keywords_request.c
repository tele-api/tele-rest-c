#ifndef set_sticker_keywords_request_TEST
#define set_sticker_keywords_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define set_sticker_keywords_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/set_sticker_keywords_request.h"
set_sticker_keywords_request_t* instantiate_set_sticker_keywords_request(int include_optional);



set_sticker_keywords_request_t* instantiate_set_sticker_keywords_request(int include_optional) {
  set_sticker_keywords_request_t* set_sticker_keywords_request = NULL;
  if (include_optional) {
    set_sticker_keywords_request = set_sticker_keywords_request_create(
      "0",
      list_createList()
    );
  } else {
    set_sticker_keywords_request = set_sticker_keywords_request_create(
      "0",
      list_createList()
    );
  }

  return set_sticker_keywords_request;
}


#ifdef set_sticker_keywords_request_MAIN

void test_set_sticker_keywords_request(int include_optional) {
    set_sticker_keywords_request_t* set_sticker_keywords_request_1 = instantiate_set_sticker_keywords_request(include_optional);

	cJSON* jsonset_sticker_keywords_request_1 = set_sticker_keywords_request_convertToJSON(set_sticker_keywords_request_1);
	printf("set_sticker_keywords_request :\n%s\n", cJSON_Print(jsonset_sticker_keywords_request_1));
	set_sticker_keywords_request_t* set_sticker_keywords_request_2 = set_sticker_keywords_request_parseFromJSON(jsonset_sticker_keywords_request_1);
	cJSON* jsonset_sticker_keywords_request_2 = set_sticker_keywords_request_convertToJSON(set_sticker_keywords_request_2);
	printf("repeating set_sticker_keywords_request:\n%s\n", cJSON_Print(jsonset_sticker_keywords_request_2));
}

int main() {
  test_set_sticker_keywords_request(1);
  test_set_sticker_keywords_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // set_sticker_keywords_request_MAIN
#endif // set_sticker_keywords_request_TEST
