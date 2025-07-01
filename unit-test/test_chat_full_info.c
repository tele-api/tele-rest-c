#ifndef chat_full_info_TEST
#define chat_full_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define chat_full_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/chat_full_info.h"
chat_full_info_t* instantiate_chat_full_info(int include_optional);

#include "test_accepted_gift_types.c"
#include "test_chat_photo.c"
#include "test_birthdate.c"
#include "test_business_intro.c"
#include "test_business_location.c"
#include "test_business_opening_hours.c"
#include "test_chat.c"
#include "test_message.c"
#include "test_chat_permissions.c"
#include "test_chat_location.c"


chat_full_info_t* instantiate_chat_full_info(int include_optional) {
  chat_full_info_t* chat_full_info = NULL;
  if (include_optional) {
    chat_full_info = chat_full_info_create(
      56,
      telegram_bot_api_chat_full_info_TYPE_private,
      56,
      56,
       // false, not to have infinite recursion
      instantiate_accepted_gift_types(0),
      "0",
      "0",
      "0",
      "0",
      1,
       // false, not to have infinite recursion
      instantiate_chat_photo(0),
      list_createList(),
       // false, not to have infinite recursion
      instantiate_birthdate(0),
       // false, not to have infinite recursion
      instantiate_business_intro(0),
       // false, not to have infinite recursion
      instantiate_business_location(0),
       // false, not to have infinite recursion
      instantiate_business_opening_hours(0),
       // false, not to have infinite recursion
      instantiate_chat(0),
      list_createList(),
      "0",
      56,
      "0",
      "0",
      56,
      "0",
      1,
      1,
      1,
      1,
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_message(0),
       // false, not to have infinite recursion
      instantiate_chat_permissions(0),
      1,
      56,
      56,
      56,
      1,
      1,
      1,
      1,
      "0",
      1,
      "0",
      56,
       // false, not to have infinite recursion
      instantiate_chat_location(0)
    );
  } else {
    chat_full_info = chat_full_info_create(
      56,
      telegram_bot_api_chat_full_info_TYPE_private,
      56,
      56,
      NULL,
      "0",
      "0",
      "0",
      "0",
      1,
      NULL,
      list_createList(),
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      list_createList(),
      "0",
      56,
      "0",
      "0",
      56,
      "0",
      1,
      1,
      1,
      1,
      "0",
      "0",
      NULL,
      NULL,
      1,
      56,
      56,
      56,
      1,
      1,
      1,
      1,
      "0",
      1,
      "0",
      56,
      NULL
    );
  }

  return chat_full_info;
}


#ifdef chat_full_info_MAIN

void test_chat_full_info(int include_optional) {
    chat_full_info_t* chat_full_info_1 = instantiate_chat_full_info(include_optional);

	cJSON* jsonchat_full_info_1 = chat_full_info_convertToJSON(chat_full_info_1);
	printf("chat_full_info :\n%s\n", cJSON_Print(jsonchat_full_info_1));
	chat_full_info_t* chat_full_info_2 = chat_full_info_parseFromJSON(jsonchat_full_info_1);
	cJSON* jsonchat_full_info_2 = chat_full_info_convertToJSON(chat_full_info_2);
	printf("repeating chat_full_info:\n%s\n", cJSON_Print(jsonchat_full_info_2));
}

int main() {
  test_chat_full_info(1);
  test_chat_full_info(0);

  printf("Hello world \n");
  return 0;
}

#endif // chat_full_info_MAIN
#endif // chat_full_info_TEST
