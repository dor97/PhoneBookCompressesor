#include"compressData.h"


//The function create a short/compress client array
Short_client* createShortClientArr(int n)
{
    Client* clientArr = (Client*)malloc(sizeof(Client) * n);
    Short_client* shortarr = (Short_client*)malloc(sizeof(Short_client) * n);
    cheackAllocation(clientArr);
    cheackAllocation(shortarr);
    unsigned char temp;
    int i, j = 0;

    fillArray(clientArr, n);

    for (i = 0; i < n; i++)
    {
        compressId(&(clientArr[i].id), &(shortarr[i].short_id));

        compressPhoneNumber(&(clientArr[i].phone), &(shortarr[i].short_phone));
    }
    free(clientArr);
    return shortarr;
}

//The function compress a client phone number into a short/compress client phone number
void compressPhoneNumber(char* phone, unsigned char* compPhone)
{
    int j = 0;
    unsigned char temp;

    while (phone[j] != '\0')
    {
        compPhone[j / 2] = phone[j] - '0';
        compPhone[j / 2] <<= 4;
        if (j == 2)
            j++;
        temp = phone[j + 1] - '0';
        compPhone[j / 2] = compPhone[j / 2] | temp;

        j += 2;
    }
}

//The function compress a client ID into a short/compress client ID
void compressId(char* id, unsigned char* compId)
{
    int j = 0;
    unsigned char temp;

    while (id[j] != '\0')
    {
        compId[j / 2] = id[j] - '0';
        compId[j / 2] <<= 4;
        temp = id[j + 1] - '0';
        compId[j / 2] = compId[j / 2] | temp;

        j += 2;
    }
}

//The function fills an array of clients
void fillArray(Client* clientArr, int size)
{
    int i;
    char c;

    for (i = 0; i < size; i++)
    {
        printf("enter id\n");
        scanf("%s", clientArr[i].id);

        printf("enter phone number\n");
        scanf("%s", clientArr[i].phone);
    }
    c = getchar(); //gets rid of the \n
}

//The function search for a client phone with a given id
char* searchClientByID(Short_client* arr, int n, char* id)
{
    int j = 0, i;
    unsigned char* compId = (unsigned char*)malloc(sizeof(unsigned char) * 4);
    cheackAllocation(compId);
    char* phone = NULL;
    bool flage = true;

    compressId(id, compId);

    while (phone == NULL && j < n)
    {
        flage = true;
        i = 0;
        while (i < 4 && flage)
        {
            if (arr[j].short_id[i] != compId[i])
                flage = false;
            i++;
        }
        if (flage)
        {
            phone = (char*)malloc(sizeof(char) * 12);
            cheackAllocation(phone);
            uncompressPhoneNumber(phone, arr[j].short_phone);
        }
        j++;
    }
    return phone;
}

//The function uncompress a phone number
void uncompressPhoneNumber(char* phone, char* compPhone)
{
    unsigned char p = 15, temp;
    int i;

    for (i = 0; i < 10; i += 2)
    {
        p = ~p;
        temp = compPhone[i / 2] & p;
        phone[i] = temp >> 4;
        phone[i] += '0';

        if (i == 2)
        {
            i++;
            phone[i] = '-';
        }
        p = ~p;
        temp = compPhone[i / 2] & p;
        phone[i + 1] = temp + '0';
    }
    phone[i] = '\0';
}

//The function cheacks allocation
void cheackAllocation(void* chack)
{
    if (chack == NULL)
    {
        printf("Memory allocation failure");
        exit(1);
    }
}