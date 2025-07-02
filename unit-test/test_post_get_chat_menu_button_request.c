#ifndef post_get_chat_menu_button_request_TEST
#define post_get_chat_menu_button_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define post_get_chat_menu_button_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/post_get_chat_menu_button_request.h"
post_get_chat_menu_button_request_t* instantiate_post_get_chat_menu_button_request(int include_optional);



post_get_chat_menu_button_request_t* instantiate_post_get_chat_menu_button_request(int include_optional) {
  post_get_chat_menu_button_request_t* post_get_chat_menu_button_request = NULL;
  if (include_optional) {
    post_get_chat_menu_button_request = post_get_chat_menu_button_request_create(
      56
    );
  } else {
    post_get_chat_menu_button_request = post_get_chat_menu_button_request_create(
      56
    );
  }

  return post_get_chat_menu_button_request;
}


#ifdef post_get_chat_menu_button_request_MAIN

void test_post_get_chat_menu_button_request(int include_optional) {
    post_get_chat_menu_button_request_t* post_get_chat_menu_button_request_1 = instantiate_post_get_chat_menu_button_request(include_optional);

	cJSON* jsonpost_get_chat_menu_button_request_1 = post_get_chat_menu_button_request_convertToJSON(post_get_chat_menu_button_request_1);
	printf("post_get_chat_menu_button_request :\n%s\n", cJSON_Print(jsonpost_get_chat_menu_button_request_1));
	post_get_chat_menu_button_request_t* post_get_chat_menu_button_request_2 = post_get_chat_menu_button_request_parseFromJSON(jsonpost_get_chat_menu_button_request_1);
	cJSON* jsonpost_get_chat_menu_button_request_2 = post_get_chat_menu_button_request_convertToJSON(post_get_chat_menu_button_request_2);
	printf("repeating post_get_chat_menu_button_request:\n%s\n", cJSON_Print(jsonpost_get_chat_menu_button_request_2));
}

int main() {
  test_post_get_chat_menu_button_request(1);
  test_post_get_chat_menu_button_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // post_get_chat_menu_button_request_MAIN
#endif // post_get_chat_menu_button_request_TEST
