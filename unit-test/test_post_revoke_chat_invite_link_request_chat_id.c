#ifndef post_revoke_chat_invite_link_request_chat_id_TEST
#define post_revoke_chat_invite_link_request_chat_id_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define post_revoke_chat_invite_link_request_chat_id_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/post_revoke_chat_invite_link_request_chat_id.h"
post_revoke_chat_invite_link_request_chat_id_t* instantiate_post_revoke_chat_invite_link_request_chat_id(int include_optional);



post_revoke_chat_invite_link_request_chat_id_t* instantiate_post_revoke_chat_invite_link_request_chat_id(int include_optional) {
  post_revoke_chat_invite_link_request_chat_id_t* post_revoke_chat_invite_link_request_chat_id = NULL;
  if (include_optional) {
    post_revoke_chat_invite_link_request_chat_id = post_revoke_chat_invite_link_request_chat_id_create(
    );
  } else {
    post_revoke_chat_invite_link_request_chat_id = post_revoke_chat_invite_link_request_chat_id_create(
    );
  }

  return post_revoke_chat_invite_link_request_chat_id;
}


#ifdef post_revoke_chat_invite_link_request_chat_id_MAIN

void test_post_revoke_chat_invite_link_request_chat_id(int include_optional) {
    post_revoke_chat_invite_link_request_chat_id_t* post_revoke_chat_invite_link_request_chat_id_1 = instantiate_post_revoke_chat_invite_link_request_chat_id(include_optional);

	cJSON* jsonpost_revoke_chat_invite_link_request_chat_id_1 = post_revoke_chat_invite_link_request_chat_id_convertToJSON(post_revoke_chat_invite_link_request_chat_id_1);
	printf("post_revoke_chat_invite_link_request_chat_id :\n%s\n", cJSON_Print(jsonpost_revoke_chat_invite_link_request_chat_id_1));
	post_revoke_chat_invite_link_request_chat_id_t* post_revoke_chat_invite_link_request_chat_id_2 = post_revoke_chat_invite_link_request_chat_id_parseFromJSON(jsonpost_revoke_chat_invite_link_request_chat_id_1);
	cJSON* jsonpost_revoke_chat_invite_link_request_chat_id_2 = post_revoke_chat_invite_link_request_chat_id_convertToJSON(post_revoke_chat_invite_link_request_chat_id_2);
	printf("repeating post_revoke_chat_invite_link_request_chat_id:\n%s\n", cJSON_Print(jsonpost_revoke_chat_invite_link_request_chat_id_2));
}

int main() {
  test_post_revoke_chat_invite_link_request_chat_id(1);
  test_post_revoke_chat_invite_link_request_chat_id(0);

  printf("Hello world \n");
  return 0;
}

#endif // post_revoke_chat_invite_link_request_chat_id_MAIN
#endif // post_revoke_chat_invite_link_request_chat_id_TEST
