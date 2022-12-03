#include <stdio.h>
#include <pthread.h>
#include <string.h>

#define CAESAR_MOVE 12

struct input {
    char original[100];
    char encrypted[100];
};

void encrypt(struct input *data) {

    printf("Encrypting: %s\n", data->encrypted);

    int i = 0;
    while (data->encrypted[i] != '\0') {

        data->encrypted[i] = data->encrypted[i] + CAESAR_MOVE;
        if(data->encrypted[i] > 'Z'){
            data->encrypted[i] = data->encrypted[i] - ('z'-'a') - 1;
        }

        i++;
    }

    printf("Encrypted: %s\n", data->encrypted);
}

void decrypt(struct input *data) {

    printf("Decrypting: %s\n", data->encrypted);

    int i = 0;
    while (data->encrypted[i] != '\0') {

        data->encrypted[i] = data->encrypted[i] - CAESAR_MOVE;
        if(data->encrypted[i] < 'A'){
            data->encrypted[i] = data->encrypted[i] + ('z'-'a') + 1;
        }

        i++;
    }

    printf("Decrypted: %s\n", data->encrypted);
    printf("Original: %s\n",data->original);
    if(strcmp(data->encrypted, data->original) == 0){
        printf("Decrypted successfully!\n");
    }
}

int main() {


    struct input data;

    printf("Zadajte vstup: ");
    scanf("%s", data.encrypted);

    strcpy(data.original,data.encrypted);

    pthread_t tid1, tid2;

    pthread_create(&tid1, NULL, (void *) encrypt, &data);

    pthread_join(tid1, NULL);

    printf("\n");

    pthread_create(&tid2, NULL, (void *) decrypt, &data);

    pthread_join(tid2, NULL);


    return 0;
}