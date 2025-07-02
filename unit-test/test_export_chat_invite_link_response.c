#ifndef export_chat_invite_link_response_TEST
#define export_chat_invite_link_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define export_chat_invite_link_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/export_chat_invite_link_response.h"
export_chat_invite_link_response_t* instantiate_export_chat_invite_link_response(int include_optional);



export_chat_invite_link_response_t* instantiate_export_chat_invite_link_response(int include_optional) {
  export_chat_invite_link_response_t* export_chat_invite_link_response = NULL;
  if (include_optional) {
    export_chat_invite_link_response = export_chat_invite_link_response_create(
      1,
      "0"
    );
  } else {
    export_chat_invite_link_response = export_chat_invite_link_response_create(
      1,
      "0"
    );
  }

  return export_chat_invite_link_response;
}


#ifdef export_chat_invite_link_response_MAIN

void test_export_chat_invite_link_response(int include_optional) {
    export_chat_invite_link_response_t* export_chat_invite_link_response_1 = instantiate_export_chat_invite_link_response(include_optional);

	cJSON* jsonexport_chat_invite_link_response_1 = export_chat_invite_link_response_convertToJSON(export_chat_invite_link_response_1);
	printf("export_chat_invite_link_response :\n%s\n", cJSON_Print(jsonexport_chat_invite_link_response_1));
	export_chat_invite_link_response_t* export_chat_invite_link_response_2 = export_chat_invite_link_response_parseFromJSON(jsonexport_chat_invite_link_response_1);
	cJSON* jsonexport_chat_invite_link_response_2 = export_chat_invite_link_response_convertToJSON(export_chat_invite_link_response_2);
	printf("repeating export_chat_invite_link_response:\n%s\n", cJSON_Print(jsonexport_chat_invite_link_response_2));
}

int main() {
  test_export_chat_invite_link_response(1);
  test_export_chat_invite_link_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // export_chat_invite_link_response_MAIN
#endif // export_chat_invite_link_response_TEST
