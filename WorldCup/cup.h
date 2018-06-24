/** @file cup.h
 *  @brief Define as funções de resolução das partidas.
 *
 *  Arquivo que define as funções utilizadas quanto ao ambito de resolução das partidas da copa.
 *  A partir dos resultados gera a interface de usuário com as opções ou resultados respectivos.
 *
 */

#ifndef WORLDCUP_CUP_H
#define WORLDCUP_CUP_H

#include "structs.h"

/** @brief Compara o valor dos atributos e define o vencedor.
 *  @param team_one Time 1.
 *  @param team_two Time 2.
 *  @param attribute Atributo escolhido.
 *  @return Retorna o endereço time vencedor.
 */
Team* match(Team* team_one, Team* team_two, int attribute);

/** @brief Imprime o vencedor da partida, respectivos atributos e rodada.
 *  @param winner Time vencedor.
 *  @param loser Time perdedor.
 *  @param player Time escolhido pelo usuario.
 *  @param attribute Atributo escolhido.
 *  @param round Rodada da copa.
 */
void result_screen(Team* winner, Team* loser, Team* player, int attribute, int round);

/** @brief Imprime o nome e o atributo dos respectivos times.
 *  @param team_one Time 1.
 *  @param team_two Time 2.
 *  @param attribute Atributo escolhido.
 */
void print_attribute(Team *team1, Team *team2, int attribute);

/** @brief Realiza as rodadas da copa.
 *  @param heap Estrutura heap contendo os times.
 *  @param rounds Rodada a ser executada.
 *  @param player Time escolhido pelo usuario.
 *  @param log Estrutura que guarda o historico das partidas.
 */
void rounds(t_heap* heap ,int rounds, Team* player, game_log* log);

/** @brief Imprime os times disponiveis para serem escolhidos, e permite o usuário escolher.
 *  @param heap Estrutura heap contendo os times.
 *  @return Retorna endereço do time escolhido pelo usuario.
 */
Team* choose_team(t_heap* heap);

/** @brief Imprime um atributo aleatório referente ao time.
 *  @param team Time a ser impresso o atributo.
 */
void print_random_attribute(Team* team, int attribute);

/** @brief Realiza a rodada de jogada do usuario, imprimindo seus atributos e o permitindo escolher um.
 *  @param player Time escolhido pelo usuario.
 *  @param enemy Time contra quem o usuario esta disputando.
 *  @param previous_choice Opção de atributo usado anteriormente pelo usuario.
 *  @return Retorna a opção de atributo escolhido pelo usuario.
 */
int player_match(Team* player, Team* enemy, int previous_choice);

/** @brief Imprime o historico das partidas, imprimindo as rodadas, as partidas com os times e seus respectivos atributos.
 *  @param log Estrutura que guarda o historico das partidas.
 *  @param heap Estrutura heap representando a arvore da copa.
 */
void print_log(t_heap* heap, game_log* log);

/** @brief Disponibiliza o menu principal para o usuario.
 */
void menu();

/** @brief Libera a memoria alocada de todas as estruturas utilizadas na copa.
 *  @param log Estrutura que guarda o historico das partidas.
 *  @param heap Estrutura heap representando a arvore da copa.
 *  @param list Estrutura da lista duplamente encadeada.
 */
void clear_game(t_heap* heap, List* list, game_log* log);

#endif