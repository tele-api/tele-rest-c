#ifndef chat_photo_TEST
#define chat_photo_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define chat_photo_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/chat_photo.h"
chat_photo_t* instantiate_chat_photo(int include_optional);



chat_photo_t* instantiate_chat_photo(int include_optional) {
  chat_photo_t* chat_photo = NULL;
  if (include_optional) {
    chat_photo = chat_photo_create(
      "0",
      "0",
      "0",
      "0"
    );
  } else {
    chat_photo = chat_photo_create(
      "0",
      "0",
      "0",
      "0"
    );
  }

  return chat_photo;
}


#ifdef chat_photo_MAIN

void test_chat_photo(int include_optional) {
    chat_photo_t* chat_photo_1 = instantiate_chat_photo(include_optional);

	cJSON* jsonchat_photo_1 = chat_photo_convertToJSON(chat_photo_1);
	printf("chat_photo :\n%s\n", cJSON_Print(jsonchat_photo_1));
	chat_photo_t* chat_photo_2 = chat_photo_parseFromJSON(jsonchat_photo_1);
	cJSON* jsonchat_photo_2 = chat_photo_convertToJSON(chat_photo_2);
	printf("repeating chat_photo:\n%s\n", cJSON_Print(jsonchat_photo_2));
}

int main() {
  test_chat_photo(1);
  test_chat_photo(0);

  printf("Hello world \n");
  return 0;
}

#endif // chat_photo_MAIN
#endif // chat_photo_TEST
