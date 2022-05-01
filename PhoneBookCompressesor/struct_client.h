#pragma once

typedef struct _client
{
    char id[9];          // 12345678	
    char phone[12];     // 054-1234567 	
} Client;


typedef struct _short_client
{
    unsigned char short_id[4];
    unsigned char short_phone[5];
} Short_client;
