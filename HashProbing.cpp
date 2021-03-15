#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

const int hashTableSize = 10;

struct hashNode
{
    char key[100];
    int value;
};
int convertStringToInt(char *theString)
{
    //convert text menjadi angka menggunakan ascii
    int len = strlen(theString); //panjang dari string
    int theInt = NULL;
    for (int i = 0; i < len; i++)
    {
        theInt += theString[i]; //akan berubah menjadi kode ascii
    }
    return theInt;
    //contoh Arif menjadi 386
}
int hashDivision(int value)
{
    return value % hashTableSize; //mengubah 386 mod 10 menjadi 6
}

void show(hashNode *hashTable[])
{
    struct hashNode *temp = NULL;
    for (int i = 0; i < hashTableSize; i++)
    {
        printf("[%d] ", i);
        if (hashTable[i] != NULL)
        {
            printf("%s:%d", hashTable[i]->key, hashTable[i]->value);
        }
        else
        {
            printf("NULL");
        }
        printf("\n");
    }
}
void insert(char *key, int value, hashNode *hashTable[])
{
    struct hashNode *newNode = (struct hashNode *)malloc(sizeof(struct hashNode));
    strcpy(newNode->key, key);
    newNode->value = value;
    int keyInt = convertStringToInt(key);
    int index = hashDivision(keyInt);
    struct hashNode *temp = NULL;
    while (hashTable[index] != NULL)
    {
        index++; //untuk check apakah index berikut nya kosong
    }
    hashTable[index] = newNode; //jika index nya kosong maka di taro lah value nya
}
int retrieve(char *key, hashNode *hashTable[])
{
    int keyInt = convertStringToInt(key);
    int index = hashDivision(keyInt);
    struct hashNode *temp = NULL;
    temp = hashTable[index];
    if (hashTable[index] == NULL)
    {
        printf("%s:Not Found!\n", key); //jika tidak ketemu
    }
    else
    {
        while (hashTable[index] != NULL)
        {
            if (strcmp(hashTable[index]->key, key) == 0) //apakah temp mulai dari index pertama dari node tersebut jika kedua sama
            {
                printf("%s:%d\n", hashTable[index]->key, hashTable[index]->value);
                return hashTable[index]->value;
            }
            index++;
        }
    }
    return 0;
}
int main()
{
    struct hashNode *hashTable[hashTableSize];
    for (int i = 0; i < hashTableSize; i++)
    {
        hashTable[i] = NULL;
    }
    insert("Arif", 18, hashTable);
    insert("Budi", 19, hashTable);
    insert("Citra", 20, hashTable);
    insert("Dwi", 21, hashTable);
    insert("Eka", 22, hashTable);
    insert("Fajar", 21, hashTable);
    insert("Indah", 19, hashTable);
    insert("Kurniawan", 18, hashTable);
    show(hashTable);
    printf("\n");
    int value = retrieve("Dwi", hashTable);
    value = retrieve("Kurniawan", hashTable);
    value = retrieve("Dian", hashTable);

    return 0;
}
// [0] NULL
// [1] NULL
// [2] Dwi:21
// [3] Eka:22
// [4] Fajar:21
// [5] Indah:19
// [6] Arif:18
// [7] Kurniawan:18
// [8] Budi:19
// [9] Citra:20

// Dwi:21
// Kurniawan:18
// Dian:Not Found!