#ifndef delete_chat_photo_response_TEST
#define delete_chat_photo_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define delete_chat_photo_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/delete_chat_photo_response.h"
delete_chat_photo_response_t* instantiate_delete_chat_photo_response(int include_optional);



delete_chat_photo_response_t* instantiate_delete_chat_photo_response(int include_optional) {
  delete_chat_photo_response_t* delete_chat_photo_response = NULL;
  if (include_optional) {
    delete_chat_photo_response = delete_chat_photo_response_create(
      1,
      1
    );
  } else {
    delete_chat_photo_response = delete_chat_photo_response_create(
      1,
      1
    );
  }

  return delete_chat_photo_response;
}


#ifdef delete_chat_photo_response_MAIN

void test_delete_chat_photo_response(int include_optional) {
    delete_chat_photo_response_t* delete_chat_photo_response_1 = instantiate_delete_chat_photo_response(include_optional);

	cJSON* jsondelete_chat_photo_response_1 = delete_chat_photo_response_convertToJSON(delete_chat_photo_response_1);
	printf("delete_chat_photo_response :\n%s\n", cJSON_Print(jsondelete_chat_photo_response_1));
	delete_chat_photo_response_t* delete_chat_photo_response_2 = delete_chat_photo_response_parseFromJSON(jsondelete_chat_photo_response_1);
	cJSON* jsondelete_chat_photo_response_2 = delete_chat_photo_response_convertToJSON(delete_chat_photo_response_2);
	printf("repeating delete_chat_photo_response:\n%s\n", cJSON_Print(jsondelete_chat_photo_response_2));
}

int main() {
  test_delete_chat_photo_response(1);
  test_delete_chat_photo_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // delete_chat_photo_response_MAIN
#endif // delete_chat_photo_response_TEST
