#ifndef delete_sticker_set_request_TEST
#define delete_sticker_set_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define delete_sticker_set_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/delete_sticker_set_request.h"
delete_sticker_set_request_t* instantiate_delete_sticker_set_request(int include_optional);



delete_sticker_set_request_t* instantiate_delete_sticker_set_request(int include_optional) {
  delete_sticker_set_request_t* delete_sticker_set_request = NULL;
  if (include_optional) {
    delete_sticker_set_request = delete_sticker_set_request_create(
      "0"
    );
  } else {
    delete_sticker_set_request = delete_sticker_set_request_create(
      "0"
    );
  }

  return delete_sticker_set_request;
}


#ifdef delete_sticker_set_request_MAIN

void test_delete_sticker_set_request(int include_optional) {
    delete_sticker_set_request_t* delete_sticker_set_request_1 = instantiate_delete_sticker_set_request(include_optional);

	cJSON* jsondelete_sticker_set_request_1 = delete_sticker_set_request_convertToJSON(delete_sticker_set_request_1);
	printf("delete_sticker_set_request :\n%s\n", cJSON_Print(jsondelete_sticker_set_request_1));
	delete_sticker_set_request_t* delete_sticker_set_request_2 = delete_sticker_set_request_parseFromJSON(jsondelete_sticker_set_request_1);
	cJSON* jsondelete_sticker_set_request_2 = delete_sticker_set_request_convertToJSON(delete_sticker_set_request_2);
	printf("repeating delete_sticker_set_request:\n%s\n", cJSON_Print(jsondelete_sticker_set_request_2));
}

int main() {
  test_delete_sticker_set_request(1);
  test_delete_sticker_set_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // delete_sticker_set_request_MAIN
#endif // delete_sticker_set_request_TEST
