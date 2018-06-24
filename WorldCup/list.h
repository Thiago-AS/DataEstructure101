/** @file list.h
 *  @brief Define as funções de manipulação da lista.
 *
 *  Arquivo que define todas as funções de criação e manipulação da lista duplamente encadeada utilizada.
 */
#ifndef WORLDCUP_LIST_H
#define WORLDCUP_LIST_H

#include "structs.h"

/** @brief Cria um time.
 *  @param _nome Nome do time.
 *  @param _ataque Ataque do time.
 *  @param _defesa Defesa do time.
 *  @param _resistencia Resistencia do time.
 *  @param _velocidade Velocidade do time.
 *  @return Retorna o endereço para estrutura Team criada.
 */
Team* team_create(char* _nome, int _ataque, int _defesa, int _resistencia, int _velocidade);

/** @brief Cria uma lista.
 *  @return Retorna o endereço para estrutura List criada.
 */
List* list_alloc();

/** @brief Cria um elemento da lista.
 *  @param team Estrutura do time a ser alocado na lista.
 *  @return Retorna o endereço para estrutura L_element criada.
 */
L_element* element_alloc(Team* team);

/** @brief Lê o arquivo dado e seleciona os times aleatoriamente.
 *  @param file_name Nome do arquivo a ser lido.
 *  @return Retorna o endereço para estrutura List criada, contendo os 16 times.
 */
List* read_file(char* file_name);

/** @brief Insere elemento na lista.
 *  @param element Elemento a ser inserido.
 *  @param list Lista a ser inserido o elemento.
 */
void insert_element(L_element* element, List* list);

/** @brief Libera a memoria da lista.
 *  @param list Lista a ser excluida.
 */
void list_free(List* list);

/** @brief Libera a memoria do time.
 *  @param team Time a ser excluido.
 */
void team_free(Team* team);


#endif
