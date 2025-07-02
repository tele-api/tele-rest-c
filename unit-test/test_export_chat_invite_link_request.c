#ifndef export_chat_invite_link_request_TEST
#define export_chat_invite_link_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define export_chat_invite_link_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/export_chat_invite_link_request.h"
export_chat_invite_link_request_t* instantiate_export_chat_invite_link_request(int include_optional);

#include "test_send_message_request_chat_id.c"


export_chat_invite_link_request_t* instantiate_export_chat_invite_link_request(int include_optional) {
  export_chat_invite_link_request_t* export_chat_invite_link_request = NULL;
  if (include_optional) {
    export_chat_invite_link_request = export_chat_invite_link_request_create(
      null
    );
  } else {
    export_chat_invite_link_request = export_chat_invite_link_request_create(
      null
    );
  }

  return export_chat_invite_link_request;
}


#ifdef export_chat_invite_link_request_MAIN

void test_export_chat_invite_link_request(int include_optional) {
    export_chat_invite_link_request_t* export_chat_invite_link_request_1 = instantiate_export_chat_invite_link_request(include_optional);

	cJSON* jsonexport_chat_invite_link_request_1 = export_chat_invite_link_request_convertToJSON(export_chat_invite_link_request_1);
	printf("export_chat_invite_link_request :\n%s\n", cJSON_Print(jsonexport_chat_invite_link_request_1));
	export_chat_invite_link_request_t* export_chat_invite_link_request_2 = export_chat_invite_link_request_parseFromJSON(jsonexport_chat_invite_link_request_1);
	cJSON* jsonexport_chat_invite_link_request_2 = export_chat_invite_link_request_convertToJSON(export_chat_invite_link_request_2);
	printf("repeating export_chat_invite_link_request:\n%s\n", cJSON_Print(jsonexport_chat_invite_link_request_2));
}

int main() {
  test_export_chat_invite_link_request(1);
  test_export_chat_invite_link_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // export_chat_invite_link_request_MAIN
#endif // export_chat_invite_link_request_TEST
