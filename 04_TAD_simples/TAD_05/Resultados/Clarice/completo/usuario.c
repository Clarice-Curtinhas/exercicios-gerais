#include <stdio.h>
#include <stdlib.h>

typedef struct Usuario {
    char nome[50]; /**< Nome do usuário. */
    char cpf[15]; /**< CPF do usuário. */
} tUsuario;

/**
 * @brief Cria um novo usuário.
 * @param nome Nome do usuário.
 * @param cpf CPF do usuário.
 * @return O novo usuário criado.
 */
tUsuario CriaUsuario(char nome[20], char cpf[15]){
    int nomeQnt = 0, cpfQnt = 0;
    tUsuario usuario;

    while(nome[nomeQnt] != '\0'){
        usuario.nome[nomeQnt] = nome[nomeQnt];
        nomeQnt++;
    }
    usuario.nome[nomeQnt] = '\0';

    while(cpf[cpfQnt] != '\0'){
        usuario.cpf[cpfQnt] = cpf[cpfQnt];
        cpfQnt++;
    }
    usuario.cpf[cpfQnt] = '\0';

    return usuario;
}

/**
 * @brief Imprime os dados de um usuário.
 * @param user Usuário a ser impresso.
 */
void ImprimeUsuario(tUsuario user){
    printf("Nome: %s\n", user.nome);
    printf("CPF: %s\n", user.cpf);
}