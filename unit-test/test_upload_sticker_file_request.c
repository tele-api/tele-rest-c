#ifndef upload_sticker_file_request_TEST
#define upload_sticker_file_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define upload_sticker_file_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/upload_sticker_file_request.h"
upload_sticker_file_request_t* instantiate_upload_sticker_file_request(int include_optional);



upload_sticker_file_request_t* instantiate_upload_sticker_file_request(int include_optional) {
  upload_sticker_file_request_t* upload_sticker_file_request = NULL;
  if (include_optional) {
    upload_sticker_file_request = upload_sticker_file_request_create(
      56,
      null,
      telegram_bot_api_upload_sticker_file_request_STICKERFORMAT_static
    );
  } else {
    upload_sticker_file_request = upload_sticker_file_request_create(
      56,
      null,
      telegram_bot_api_upload_sticker_file_request_STICKERFORMAT_static
    );
  }

  return upload_sticker_file_request;
}


#ifdef upload_sticker_file_request_MAIN

void test_upload_sticker_file_request(int include_optional) {
    upload_sticker_file_request_t* upload_sticker_file_request_1 = instantiate_upload_sticker_file_request(include_optional);

	cJSON* jsonupload_sticker_file_request_1 = upload_sticker_file_request_convertToJSON(upload_sticker_file_request_1);
	printf("upload_sticker_file_request :\n%s\n", cJSON_Print(jsonupload_sticker_file_request_1));
	upload_sticker_file_request_t* upload_sticker_file_request_2 = upload_sticker_file_request_parseFromJSON(jsonupload_sticker_file_request_1);
	cJSON* jsonupload_sticker_file_request_2 = upload_sticker_file_request_convertToJSON(upload_sticker_file_request_2);
	printf("repeating upload_sticker_file_request:\n%s\n", cJSON_Print(jsonupload_sticker_file_request_2));
}

int main() {
  test_upload_sticker_file_request(1);
  test_upload_sticker_file_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // upload_sticker_file_request_MAIN
#endif // upload_sticker_file_request_TEST
