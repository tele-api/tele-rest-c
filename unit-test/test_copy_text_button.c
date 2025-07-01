#ifndef copy_text_button_TEST
#define copy_text_button_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define copy_text_button_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/copy_text_button.h"
copy_text_button_t* instantiate_copy_text_button(int include_optional);



copy_text_button_t* instantiate_copy_text_button(int include_optional) {
  copy_text_button_t* copy_text_button = NULL;
  if (include_optional) {
    copy_text_button = copy_text_button_create(
      "0"
    );
  } else {
    copy_text_button = copy_text_button_create(
      "0"
    );
  }

  return copy_text_button;
}


#ifdef copy_text_button_MAIN

void test_copy_text_button(int include_optional) {
    copy_text_button_t* copy_text_button_1 = instantiate_copy_text_button(include_optional);

	cJSON* jsoncopy_text_button_1 = copy_text_button_convertToJSON(copy_text_button_1);
	printf("copy_text_button :\n%s\n", cJSON_Print(jsoncopy_text_button_1));
	copy_text_button_t* copy_text_button_2 = copy_text_button_parseFromJSON(jsoncopy_text_button_1);
	cJSON* jsoncopy_text_button_2 = copy_text_button_convertToJSON(copy_text_button_2);
	printf("repeating copy_text_button:\n%s\n", cJSON_Print(jsoncopy_text_button_2));
}

int main() {
  test_copy_text_button(1);
  test_copy_text_button(0);

  printf("Hello world \n");
  return 0;
}

#endif // copy_text_button_MAIN
#endif // copy_text_button_TEST
