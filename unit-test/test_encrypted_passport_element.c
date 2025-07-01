#ifndef encrypted_passport_element_TEST
#define encrypted_passport_element_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define encrypted_passport_element_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/encrypted_passport_element.h"
encrypted_passport_element_t* instantiate_encrypted_passport_element(int include_optional);

#include "test_passport_file.c"
#include "test_passport_file.c"
#include "test_passport_file.c"


encrypted_passport_element_t* instantiate_encrypted_passport_element(int include_optional) {
  encrypted_passport_element_t* encrypted_passport_element = NULL;
  if (include_optional) {
    encrypted_passport_element = encrypted_passport_element_create(
      telegram_bot_api_encrypted_passport_element_TYPE_personal_details,
      "0",
      "0",
      "0",
      "0",
      list_createList(),
       // false, not to have infinite recursion
      instantiate_passport_file(0),
       // false, not to have infinite recursion
      instantiate_passport_file(0),
       // false, not to have infinite recursion
      instantiate_passport_file(0),
      list_createList()
    );
  } else {
    encrypted_passport_element = encrypted_passport_element_create(
      telegram_bot_api_encrypted_passport_element_TYPE_personal_details,
      "0",
      "0",
      "0",
      "0",
      list_createList(),
      NULL,
      NULL,
      NULL,
      list_createList()
    );
  }

  return encrypted_passport_element;
}


#ifdef encrypted_passport_element_MAIN

void test_encrypted_passport_element(int include_optional) {
    encrypted_passport_element_t* encrypted_passport_element_1 = instantiate_encrypted_passport_element(include_optional);

	cJSON* jsonencrypted_passport_element_1 = encrypted_passport_element_convertToJSON(encrypted_passport_element_1);
	printf("encrypted_passport_element :\n%s\n", cJSON_Print(jsonencrypted_passport_element_1));
	encrypted_passport_element_t* encrypted_passport_element_2 = encrypted_passport_element_parseFromJSON(jsonencrypted_passport_element_1);
	cJSON* jsonencrypted_passport_element_2 = encrypted_passport_element_convertToJSON(encrypted_passport_element_2);
	printf("repeating encrypted_passport_element:\n%s\n", cJSON_Print(jsonencrypted_passport_element_2));
}

int main() {
  test_encrypted_passport_element(1);
  test_encrypted_passport_element(0);

  printf("Hello world \n");
  return 0;
}

#endif // encrypted_passport_element_MAIN
#endif // encrypted_passport_element_TEST
