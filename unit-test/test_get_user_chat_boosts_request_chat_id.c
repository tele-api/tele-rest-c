#ifndef get_user_chat_boosts_request_chat_id_TEST
#define get_user_chat_boosts_request_chat_id_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define get_user_chat_boosts_request_chat_id_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/get_user_chat_boosts_request_chat_id.h"
get_user_chat_boosts_request_chat_id_t* instantiate_get_user_chat_boosts_request_chat_id(int include_optional);



get_user_chat_boosts_request_chat_id_t* instantiate_get_user_chat_boosts_request_chat_id(int include_optional) {
  get_user_chat_boosts_request_chat_id_t* get_user_chat_boosts_request_chat_id = NULL;
  if (include_optional) {
    get_user_chat_boosts_request_chat_id = get_user_chat_boosts_request_chat_id_create(
    );
  } else {
    get_user_chat_boosts_request_chat_id = get_user_chat_boosts_request_chat_id_create(
    );
  }

  return get_user_chat_boosts_request_chat_id;
}


#ifdef get_user_chat_boosts_request_chat_id_MAIN

void test_get_user_chat_boosts_request_chat_id(int include_optional) {
    get_user_chat_boosts_request_chat_id_t* get_user_chat_boosts_request_chat_id_1 = instantiate_get_user_chat_boosts_request_chat_id(include_optional);

	cJSON* jsonget_user_chat_boosts_request_chat_id_1 = get_user_chat_boosts_request_chat_id_convertToJSON(get_user_chat_boosts_request_chat_id_1);
	printf("get_user_chat_boosts_request_chat_id :\n%s\n", cJSON_Print(jsonget_user_chat_boosts_request_chat_id_1));
	get_user_chat_boosts_request_chat_id_t* get_user_chat_boosts_request_chat_id_2 = get_user_chat_boosts_request_chat_id_parseFromJSON(jsonget_user_chat_boosts_request_chat_id_1);
	cJSON* jsonget_user_chat_boosts_request_chat_id_2 = get_user_chat_boosts_request_chat_id_convertToJSON(get_user_chat_boosts_request_chat_id_2);
	printf("repeating get_user_chat_boosts_request_chat_id:\n%s\n", cJSON_Print(jsonget_user_chat_boosts_request_chat_id_2));
}

int main() {
  test_get_user_chat_boosts_request_chat_id(1);
  test_get_user_chat_boosts_request_chat_id(0);

  printf("Hello world \n");
  return 0;
}

#endif // get_user_chat_boosts_request_chat_id_MAIN
#endif // get_user_chat_boosts_request_chat_id_TEST
