#ifndef get_chat_menu_button_request_TEST
#define get_chat_menu_button_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define get_chat_menu_button_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/get_chat_menu_button_request.h"
get_chat_menu_button_request_t* instantiate_get_chat_menu_button_request(int include_optional);



get_chat_menu_button_request_t* instantiate_get_chat_menu_button_request(int include_optional) {
  get_chat_menu_button_request_t* get_chat_menu_button_request = NULL;
  if (include_optional) {
    get_chat_menu_button_request = get_chat_menu_button_request_create(
      56
    );
  } else {
    get_chat_menu_button_request = get_chat_menu_button_request_create(
      56
    );
  }

  return get_chat_menu_button_request;
}


#ifdef get_chat_menu_button_request_MAIN

void test_get_chat_menu_button_request(int include_optional) {
    get_chat_menu_button_request_t* get_chat_menu_button_request_1 = instantiate_get_chat_menu_button_request(include_optional);

	cJSON* jsonget_chat_menu_button_request_1 = get_chat_menu_button_request_convertToJSON(get_chat_menu_button_request_1);
	printf("get_chat_menu_button_request :\n%s\n", cJSON_Print(jsonget_chat_menu_button_request_1));
	get_chat_menu_button_request_t* get_chat_menu_button_request_2 = get_chat_menu_button_request_parseFromJSON(jsonget_chat_menu_button_request_1);
	cJSON* jsonget_chat_menu_button_request_2 = get_chat_menu_button_request_convertToJSON(get_chat_menu_button_request_2);
	printf("repeating get_chat_menu_button_request:\n%s\n", cJSON_Print(jsonget_chat_menu_button_request_2));
}

int main() {
  test_get_chat_menu_button_request(1);
  test_get_chat_menu_button_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // get_chat_menu_button_request_MAIN
#endif // get_chat_menu_button_request_TEST
