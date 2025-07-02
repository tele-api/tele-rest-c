#ifndef delete_sticker_set_response_TEST
#define delete_sticker_set_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define delete_sticker_set_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/delete_sticker_set_response.h"
delete_sticker_set_response_t* instantiate_delete_sticker_set_response(int include_optional);



delete_sticker_set_response_t* instantiate_delete_sticker_set_response(int include_optional) {
  delete_sticker_set_response_t* delete_sticker_set_response = NULL;
  if (include_optional) {
    delete_sticker_set_response = delete_sticker_set_response_create(
      1,
      1
    );
  } else {
    delete_sticker_set_response = delete_sticker_set_response_create(
      1,
      1
    );
  }

  return delete_sticker_set_response;
}


#ifdef delete_sticker_set_response_MAIN

void test_delete_sticker_set_response(int include_optional) {
    delete_sticker_set_response_t* delete_sticker_set_response_1 = instantiate_delete_sticker_set_response(include_optional);

	cJSON* jsondelete_sticker_set_response_1 = delete_sticker_set_response_convertToJSON(delete_sticker_set_response_1);
	printf("delete_sticker_set_response :\n%s\n", cJSON_Print(jsondelete_sticker_set_response_1));
	delete_sticker_set_response_t* delete_sticker_set_response_2 = delete_sticker_set_response_parseFromJSON(jsondelete_sticker_set_response_1);
	cJSON* jsondelete_sticker_set_response_2 = delete_sticker_set_response_convertToJSON(delete_sticker_set_response_2);
	printf("repeating delete_sticker_set_response:\n%s\n", cJSON_Print(jsondelete_sticker_set_response_2));
}

int main() {
  test_delete_sticker_set_response(1);
  test_delete_sticker_set_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // delete_sticker_set_response_MAIN
#endif // delete_sticker_set_response_TEST
