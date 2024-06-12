#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define KEY_SIZE 10

// Função para gerar uma chave
void generate_key(char *key) {
    int sum = 0;
    srand(time(NULL));
    for (int i = 0; i < KEY_SIZE - 1; i++) {
        int num = rand() % 10;
        key[i] = num + '0';
        sum += num;
    }
    // Último dígito será a soma dos anteriores módulo 10
    key[KEY_SIZE - 1] = (sum % 10) + '0';
    key[KEY_SIZE] = '\0'; // Terminador de string
}

// Função para verificar a chave
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
    return check_digit == (key[KEY_SIZE - 1] - '0');
}

int main() {
    char key[KEY_SIZE + 1];
    int choice;
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Gerar chave\n");
        printf("2. Verificar chave\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                generate_key(key);
                printf("Chave gerada: %s\n", key);
                break;
            case 2:
                printf("Digite a chave para verificar: ");
                scanf("%s", key);
                if (verify_key(key)) {
                    printf("A chave é válida.\n");
                } else {
                    printf("A chave é inválida.\n");
                }
                break;
            case 3:
                printf("Saindo...\n");
                return 0;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }
    return 0;
}
