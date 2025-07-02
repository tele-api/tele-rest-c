#ifndef post_edit_message_text_request_chat_id_TEST
#define post_edit_message_text_request_chat_id_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define post_edit_message_text_request_chat_id_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/post_edit_message_text_request_chat_id.h"
post_edit_message_text_request_chat_id_t* instantiate_post_edit_message_text_request_chat_id(int include_optional);



post_edit_message_text_request_chat_id_t* instantiate_post_edit_message_text_request_chat_id(int include_optional) {
  post_edit_message_text_request_chat_id_t* post_edit_message_text_request_chat_id = NULL;
  if (include_optional) {
    post_edit_message_text_request_chat_id = post_edit_message_text_request_chat_id_create(
    );
  } else {
    post_edit_message_text_request_chat_id = post_edit_message_text_request_chat_id_create(
    );
  }

  return post_edit_message_text_request_chat_id;
}


#ifdef post_edit_message_text_request_chat_id_MAIN

void test_post_edit_message_text_request_chat_id(int include_optional) {
    post_edit_message_text_request_chat_id_t* post_edit_message_text_request_chat_id_1 = instantiate_post_edit_message_text_request_chat_id(include_optional);

	cJSON* jsonpost_edit_message_text_request_chat_id_1 = post_edit_message_text_request_chat_id_convertToJSON(post_edit_message_text_request_chat_id_1);
	printf("post_edit_message_text_request_chat_id :\n%s\n", cJSON_Print(jsonpost_edit_message_text_request_chat_id_1));
	post_edit_message_text_request_chat_id_t* post_edit_message_text_request_chat_id_2 = post_edit_message_text_request_chat_id_parseFromJSON(jsonpost_edit_message_text_request_chat_id_1);
	cJSON* jsonpost_edit_message_text_request_chat_id_2 = post_edit_message_text_request_chat_id_convertToJSON(post_edit_message_text_request_chat_id_2);
	printf("repeating post_edit_message_text_request_chat_id:\n%s\n", cJSON_Print(jsonpost_edit_message_text_request_chat_id_2));
}

int main() {
  test_post_edit_message_text_request_chat_id(1);
  test_post_edit_message_text_request_chat_id(0);

  printf("Hello world \n");
  return 0;
}

#endif // post_edit_message_text_request_chat_id_MAIN
#endif // post_edit_message_text_request_chat_id_TEST
