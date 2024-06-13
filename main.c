#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h> 

#define KEY_SIZE 10

// Function to generate a key
void generate_key(char *key, int numCodes) {
    int sum = 0;
    srand(time(NULL));
    for (int j = 0; j < numCodes; j++) {
        for (int i = 0; i < KEY_SIZE - 1; i++) {
            int num = rand() % 10;
            key[i] = num + '0';
            sum += num;
        }
        // Last digit will be the sum of the previous digits modulo 10
        key[KEY_SIZE - 1] = (sum % 10) + '0';
        key[KEY_SIZE] = '\0'; // String terminator
        printf("Chave gerada: %s\n", key);
    }
}

// Function to verify the key
int verify_key(const char *key) {
    if (strlen(key) != KEY_SIZE) {
        return 0;
    }
    int sum = 0;
    for (int i = 0; i < KEY_SIZE - 1; i++) {
        if (key[i] < '0' || key[i] > '9') {
            return 0;
        }
        sum += key[i] - '0';
    }
    int check_digit = sum % 10;
    return (check_digit == (key[KEY_SIZE - 1] - '0'));
}

int main() {
    char key[KEY_SIZE + 1];
    int choice;
    int numCodes;
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Gerar chave\n");
        printf("2. Verificar chave\n");
        printf("3. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Digite o numero de codigos a serem gerados: ");
                scanf("%d", &numCodes);
                generate_key(key, numCodes);
                break;
            case 2:
                printf("Digite a chave para verificar: ");
                scanf("%s", key);
                if (verify_key(key)) {
                    printf("A chave eh valida.\n");
                } else {
                    printf("A chave eh invalida.\n");
                }
                break;
            case 3:
                printf("Saindo...\n");
                return 0;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    }
    return 0;
}
