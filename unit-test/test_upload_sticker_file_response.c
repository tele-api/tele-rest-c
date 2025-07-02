#ifndef upload_sticker_file_response_TEST
#define upload_sticker_file_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define upload_sticker_file_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/upload_sticker_file_response.h"
upload_sticker_file_response_t* instantiate_upload_sticker_file_response(int include_optional);

#include "test_binary_t*.c"


upload_sticker_file_response_t* instantiate_upload_sticker_file_response(int include_optional) {
  upload_sticker_file_response_t* upload_sticker_file_response = NULL;
  if (include_optional) {
    upload_sticker_file_response = upload_sticker_file_response_create(
      1,
       // false, not to have infinite recursion
      instantiate_binary_t*(0)
    );
  } else {
    upload_sticker_file_response = upload_sticker_file_response_create(
      1,
      NULL
    );
  }

  return upload_sticker_file_response;
}


#ifdef upload_sticker_file_response_MAIN

void test_upload_sticker_file_response(int include_optional) {
    upload_sticker_file_response_t* upload_sticker_file_response_1 = instantiate_upload_sticker_file_response(include_optional);

	cJSON* jsonupload_sticker_file_response_1 = upload_sticker_file_response_convertToJSON(upload_sticker_file_response_1);
	printf("upload_sticker_file_response :\n%s\n", cJSON_Print(jsonupload_sticker_file_response_1));
	upload_sticker_file_response_t* upload_sticker_file_response_2 = upload_sticker_file_response_parseFromJSON(jsonupload_sticker_file_response_1);
	cJSON* jsonupload_sticker_file_response_2 = upload_sticker_file_response_convertToJSON(upload_sticker_file_response_2);
	printf("repeating upload_sticker_file_response:\n%s\n", cJSON_Print(jsonupload_sticker_file_response_2));
}

int main() {
  test_upload_sticker_file_response(1);
  test_upload_sticker_file_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // upload_sticker_file_response_MAIN
#endif // upload_sticker_file_response_TEST
