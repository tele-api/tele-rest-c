#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "invoice.h"



static invoice_t *invoice_create_internal(
    char *title,
    char *description,
    char *start_parameter,
    char *currency,
    int total_amount
    ) {
    invoice_t *invoice_local_var = malloc(sizeof(invoice_t));
    if (!invoice_local_var) {
        return NULL;
    }
    invoice_local_var->title = title;
    invoice_local_var->description = description;
    invoice_local_var->start_parameter = start_parameter;
    invoice_local_var->currency = currency;
    invoice_local_var->total_amount = total_amount;

    invoice_local_var->_library_owned = 1;
    return invoice_local_var;
}

__attribute__((deprecated)) invoice_t *invoice_create(
    char *title,
    char *description,
    char *start_parameter,
    char *currency,
    int total_amount
    ) {
    return invoice_create_internal (
        title,
        description,
        start_parameter,
        currency,
        total_amount
        );
}

void invoice_free(invoice_t *invoice) {
    if(NULL == invoice){
        return ;
    }
    if(invoice->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "invoice_free");
        return ;
    }
    listEntry_t *listEntry;
    if (invoice->title) {
        free(invoice->title);
        invoice->title = NULL;
    }
    if (invoice->description) {
        free(invoice->description);
        invoice->description = NULL;
    }
    if (invoice->start_parameter) {
        free(invoice->start_parameter);
        invoice->start_parameter = NULL;
    }
    if (invoice->currency) {
        free(invoice->currency);
        invoice->currency = NULL;
    }
    free(invoice);
}

cJSON *invoice_convertToJSON(invoice_t *invoice) {
    cJSON *item = cJSON_CreateObject();

    // invoice->title
    if (!invoice->title) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "title", invoice->title) == NULL) {
    goto fail; //String
    }


    // invoice->description
    if (!invoice->description) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "description", invoice->description) == NULL) {
    goto fail; //String
    }


    // invoice->start_parameter
    if (!invoice->start_parameter) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "start_parameter", invoice->start_parameter) == NULL) {
    goto fail; //String
    }


    // invoice->currency
    if (!invoice->currency) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "currency", invoice->currency) == NULL) {
    goto fail; //String
    }


    // invoice->total_amount
    if (!invoice->total_amount) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "total_amount", invoice->total_amount) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

invoice_t *invoice_parseFromJSON(cJSON *invoiceJSON){

    invoice_t *invoice_local_var = NULL;

    // invoice->title
    cJSON *title = cJSON_GetObjectItemCaseSensitive(invoiceJSON, "title");
    if (cJSON_IsNull(title)) {
        title = NULL;
    }
    if (!title) {
        goto end;
    }

    
    if(!cJSON_IsString(title))
    {
    goto end; //String
    }

    // invoice->description
    cJSON *description = cJSON_GetObjectItemCaseSensitive(invoiceJSON, "description");
    if (cJSON_IsNull(description)) {
        description = NULL;
    }
    if (!description) {
        goto end;
    }

    
    if(!cJSON_IsString(description))
    {
    goto end; //String
    }

    // invoice->start_parameter
    cJSON *start_parameter = cJSON_GetObjectItemCaseSensitive(invoiceJSON, "start_parameter");
    if (cJSON_IsNull(start_parameter)) {
        start_parameter = NULL;
    }
    if (!start_parameter) {
        goto end;
    }

    
    if(!cJSON_IsString(start_parameter))
    {
    goto end; //String
    }

    // invoice->currency
    cJSON *currency = cJSON_GetObjectItemCaseSensitive(invoiceJSON, "currency");
    if (cJSON_IsNull(currency)) {
        currency = NULL;
    }
    if (!currency) {
        goto end;
    }

    
    if(!cJSON_IsString(currency))
    {
    goto end; //String
    }

    // invoice->total_amount
    cJSON *total_amount = cJSON_GetObjectItemCaseSensitive(invoiceJSON, "total_amount");
    if (cJSON_IsNull(total_amount)) {
        total_amount = NULL;
    }
    if (!total_amount) {
        goto end;
    }

    
    if(!cJSON_IsNumber(total_amount))
    {
    goto end; //Numeric
    }


    invoice_local_var = invoice_create_internal (
        strdup(title->valuestring),
        strdup(description->valuestring),
        strdup(start_parameter->valuestring),
        strdup(currency->valuestring),
        total_amount->valuedouble
        );

    return invoice_local_var;
end:
    return NULL;

}
