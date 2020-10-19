// JOGO DA VELHA //

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>
#include <time.h>
int placar_j1 = 0, placar_j2 = 0;

void tabuleiro(char casas[9]) {
	system("cls");
	printf("\nPlacar: Jogador1 | %d X %d | Jogador2\n\n", placar_j1, placar_j2);
	printf("\n\t  %c | %c | %c \n", casas[0], casas[1], casas[2]);
	printf("\t -----------\n");
	printf("\t  %c | %c | %c \n", casas[3], casas[4], casas[5]);
	printf("\t -----------\n");
	printf("\t  %c | %c | %c \n", casas[6], casas[7], casas[8]);
}

int main() {

	setlocale(LC_ALL, "Portuguese");
	char resposta, casas[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
	int cont_jogadas = 0, casa_jogada, vez = 0, quem_joga = 1, vencedor, opc;

	do {

		printf(
				"Digite 1 para jogar contra uma pessoa ou 2 para jogar contra a CPU: \n");
		fflush(stdout);
		scanf("%d", &opc);
		if (opc != 1 && opc != 2) {
			printf("Opção inválida!");
		}

	} while (opc != 1 && opc != 2);

	do {
		cont_jogadas = 1;
		for (int i = 0; i <= 8; i++) {
			casas[i] = ' ';
		}
		do {
			resposta = 'Z';

			tabuleiro(casas);
			printf("\nVez do jogador%d !\n\n", quem_joga);

			if (vez % 2 == 0) {
				printf("Digite a casa para marcar[1-9]\n");
				fflush(stdout);
				scanf("%d", &casa_jogada);
			} else {
				if (opc == 1) {
					printf("Digite a casa para marcar[1-9]\n");
					fflush(stdout);
					scanf("%d", &casa_jogada);
				} else {
					if (casas[0] == 'O' && casas[1] == 'O' && casas[2] == ' ') {
						casa_jogada = 3;
					} else if (casas[3] == 'O' && casas[4] == 'O'
							&& casas[5] == ' ') {
						casa_jogada = 6;
					} else if (casas[6] == 'O' && casas[7] == 'O'
							&& casas[8] == ' ') {
						casa_jogada = 9;
					}

					else if (casas[0] == 'O' && casas[1] == ' '
							&& casas[2] == 'O') {
						casa_jogada = 2;
					} else if (casas[3] == 'O' && casas[4] == ' '
							&& casas[5] == 'O') {
						casa_jogada = 5;
					} else if (casas[6] == 'O' && casas[7] == ' '
							&& casas[8] == 'O') {
						casa_jogada = 8;
					}

					else if (casas[0] == ' ' && casas[1] == 'O'
							&& casas[2] == 'O') {
						casa_jogada = 1;
					} else if (casas[3] == ' ' && casas[4] == 'O'
							&& casas[5] == 'O') {
						casa_jogada = 4;
					} else if (casas[6] == ' ' && casas[7] == 'O'
							&& casas[8] == 'O') {
						casa_jogada = 7;
					}

					/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
					 * -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
					 * ----------------------------------------------------------------------------------------------------------------------------------------
					 * ----------------------------------------------------------------------------------------------------------------------*/
					else if (casas[0] == 'O' && casas[3] == 'O'
							&& casas[6] == ' ') {
						casa_jogada = 7;
					} else if (casas[1] == 'O' && casas[4] == 'O'
							&& casas[7] == ' ') {
						casa_jogada = 8;
					} else if (casas[2] == 'O' && casas[5] == 'O'
							&& casas[8] == ' ') {
						casa_jogada = 9;
					}

					else if (casas[0] == 'O' && casas[3] == ' '
							&& casas[6] == 'O') {
						casa_jogada = 4;
					} else if (casas[1] == 'O' && casas[4] == ' '
							&& casas[7] == 'O') {
						casa_jogada = 5;
					} else if (casas[2] == 'O' && casas[5] == ' '
							&& casas[8] == 'O') {
						casa_jogada = 5;
					}

					else if (casas[0] == ' ' && casas[3] == 'O'
							&& casas[6] == 'O') {
						casa_jogada = 1;
					} else if (casas[1] == ' ' && casas[4] == 'O'
							&& casas[7] == 'O') {
						casa_jogada = 2;
					} else if (casas[2] == ' ' && casas[5] == 'O'
							&& casas[8] == 'O') {
						casa_jogada = 3;
					}

					/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
					 * -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
					 * ----------------------------------------------------------------------------------------------------------------------------------------
					 * ----------------------------------------------------------------------------------------------------------------------*/
					else if (casas[0] == ' ' && casas[4] == 'O'
							&& casas[8] == 'O') {
						casa_jogada = 1;
					} else if (casas[0] == 'O' && casas[4] == ' '
							&& casas[8] == 'O') {
						casa_jogada = 5;
					} else if (casas[0] == 'O' && casas[4] == 'O'
							&& casas[8] == ' ') {
						casa_jogada = 9;
					}

					else if (casas[2] == ' ' && casas[4] == 'O'
							&& casas[6] == 'O') {
						casa_jogada = 3;
					} else if (casas[2] == 'O' && casas[4] == ' '
							&& casas[6] == 'O') {
						casa_jogada = 5;
					} else if (casas[2] == 'O' && casas[4] == 'O'
							&& casas[6] == ' ') {
						casa_jogada = 7;
					}

					else if (casas[0] == 'X' && casas[1] == 'X'
							&& casas[2] == ' ') {
						casa_jogada = 3;
					} else if (casas[3] == 'X' && casas[4] == 'X'
							&& casas[5] == ' ') {
						casa_jogada = 6;
					} else if (casas[6] == 'X' && casas[7] == 'X'
							&& casas[8] == ' ') {
						casa_jogada = 9;
					}

					else if (casas[0] == 'X' && casas[1] == ' '
							&& casas[2] == 'X') {
						casa_jogada = 2;
					} else if (casas[3] == 'X' && casas[4] == ' '
							&& casas[5] == 'X') {
						casa_jogada = 5;
					} else if (casas[6] == 'X' && casas[7] == ' '
							&& casas[8] == 'X') {
						casa_jogada = 8;
					}

					else if (casas[0] == ' ' && casas[1] == 'X'
							&& casas[2] == 'X') {
						casa_jogada = 1;
					} else if (casas[3] == ' ' && casas[4] == 'X'
							&& casas[5] == 'X') {
						casa_jogada = 4;
					} else if (casas[6] == ' ' && casas[7] == 'X'
							&& casas[8] == 'X') {
						casa_jogada = 7;
					}

					/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
					 * -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
					 * ----------------------------------------------------------------------------------------------------------------------------------------
					 * ----------------------------------------------------------------------------------------------------------------------*/
					else if (casas[0] == 'X' && casas[3] == 'X'
							&& casas[6] == ' ') {
						casa_jogada = 7;
					} else if (casas[1] == 'X' && casas[4] == 'X'
							&& casas[7] == ' ') {
						casa_jogada = 8;
					} else if (casas[2] == 'X' && casas[5] == 'X'
							&& casas[8] == ' ') {
						casa_jogada = 9;
					}

					else if (casas[0] == 'X' && casas[3] == ' '
							&& casas[6] == 'X') {
						casa_jogada = 4;
					} else if (casas[1] == 'X' && casas[4] == ' '
							&& casas[7] == 'X') {
						casa_jogada = 5;
					} else if (casas[2] == 'X' && casas[5] == ' '
							&& casas[8] == 'X') {
						casa_jogada = 5;
					}

					else if (casas[0] == ' ' && casas[3] == 'X'
							&& casas[6] == 'X') {
						casa_jogada = 1;
					} else if (casas[1] == ' ' && casas[4] == 'X'
							&& casas[7] == 'X') {
						casa_jogada = 2;
					} else if (casas[2] == ' ' && casas[5] == 'X'
							&& casas[8] == 'X') {
						casa_jogada = 3;
					}

					/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
					 * -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
					 * ----------------------------------------------------------------------------------------------------------------------------------------
					 * ----------------------------------------------------------------------------------------------------------------------*/
					else if (casas[0] == ' ' && casas[4] == 'X'
							&& casas[8] == 'X') {
						casa_jogada = 1;
					} else if (casas[0] == 'X' && casas[4] == ' '
							&& casas[8] == 'X') {
						casa_jogada = 5;
					} else if (casas[0] == 'X' && casas[4] == 'X'
							&& casas[8] == ' ') {
						casa_jogada = 9;
					}

					else if (casas[2] == ' ' && casas[4] == 'X'
							&& casas[6] == 'X') {
						casa_jogada = 3;
					} else if (casas[2] == 'X' && casas[4] == ' '
							&& casas[6] == 'X') {
						casa_jogada = 5;
					} else if (casas[2] == 'X' && casas[4] == 'X'
							&& casas[6] == ' ') {
						casa_jogada = 7;
					}

					else {
						do {
							srand((unsigned) time(NULL));
							casa_jogada = 1 + rand() % 9;
						} while (casas[casa_jogada - 1] != ' ');

					}
				}
			}

			if (casa_jogada < 1 || casa_jogada > 9) {
				casa_jogada = 0;
				printf(
						"Jogada inválida, a casa não existe, tente novamente !\n");
				system("pause");
			} else if (casas[casa_jogada - 1] != ' ') {
				casa_jogada = 0;
				printf(
						"Jogada inválida, a casa já está ocupada, tente novamente !\n");
				system("pause");
			} else {
				if (vez % 2 == 0) {
					casas[casa_jogada - 1] = 'X';
					quem_joga++;
				} else {
					casas[casa_jogada - 1] = 'O';
					quem_joga--;
				}

				vez++;
				cont_jogadas++;
			}
			if (casas[0] == 'X' && casas[1] == 'X' && casas[2] == 'X') {
				cont_jogadas = 11;
			}
			if (casas[3] == 'X' && casas[4] == 'X' && casas[5] == 'X') {
				cont_jogadas = 11;
			}
			if (casas[6] == 'X' && casas[7] == 'X' && casas[8] == 'X') {
				cont_jogadas = 11;
			}

			if (casas[0] == 'X' && casas[3] == 'X' && casas[6] == 'X') {
				cont_jogadas = 11;
			}
			if (casas[1] == 'X' && casas[4] == 'X' && casas[7] == 'X') {
				cont_jogadas = 11;
			}
			if (casas[2] == 'X' && casas[5] == 'X' && casas[8] == 'X') {
				cont_jogadas = 11;
			}

			if (casas[2] == 'X' && casas[4] == 'X' && casas[6] == 'X') {
				cont_jogadas = 11;
			}
			if (casas[0] == 'X' && casas[4] == 'X' && casas[8] == 'X') {
				cont_jogadas = 11;
			}

			/*---------------------------------------------------------------------------------------------------------------------
			 * ----------------------------------------------------------------------------------------------------------------------*/
			if (casas[0] == 'O' && casas[1] == 'O' && casas[2] == 'O') {
				cont_jogadas = 12;
			}
			if (casas[3] == 'O' && casas[4] == 'O' && casas[5] == 'O') {
				cont_jogadas = 12;
			}
			if (casas[6] == 'O' && casas[7] == 'O' && casas[8] == 'O') {
				cont_jogadas = 12;
			}

			if (casas[0] == 'O' && casas[3] == 'O' && casas[6] == 'O') {
				cont_jogadas = 12;
			}
			if (casas[1] == 'O' && casas[4] == 'O' && casas[7] == 'O') {
				cont_jogadas = 12;
			}
			if (casas[2] == 'O' && casas[5] == 'O' && casas[8] == 'O') {
				cont_jogadas = 12;
			}

			if (casas[2] == 'O' && casas[4] == 'O' && casas[6] == 'O') {
				cont_jogadas = 12;
			}
			if (casas[0] == 'O' && casas[4] == 'O' && casas[8] == 'O') {
				cont_jogadas = 12;
			}

		} while (cont_jogadas <= 9);
		tabuleiro(casas);
		if (cont_jogadas == 10) {
			printf("Jogo empatado!\n");
		} else if (cont_jogadas == 11) {
			placar_j1++;
			printf("\nVencedor Jogador1 !\n\n");
			printf("Placar Jogador1 | %d X %d | Jogador2\n", placar_j1,
					placar_j2);
		} else if (cont_jogadas == 12) {
			placar_j2++;
			printf("\nVencedor Jogador2 !\n\n");
			printf("Placar: Jogador1 %d X %d Jogador2\n", placar_j1, placar_j2);
		}

		while (resposta != 's' && resposta != 'n') {
			printf("Deseja jogar novamente? S/N \n");
			fflush(stdout);
			scanf("%s", &resposta);
			resposta = tolower(resposta);
			if (resposta != 's' && resposta != 'n') {
				printf("Resposta inválida !\n");
			}
		}

	} while (resposta == 's');

	if (placar_j1 > placar_j2) {
		vencedor = 1;
		printf("\nParabéns ao vencedor o Jogador%d !!!\n", vencedor);

	} else if (placar_j2 > placar_j1) {
		vencedor = 2;
		printf("\nParabéns ao vencedor o Jogador%d !!!\n", vencedor);

	} else {
		printf("\nParabéns aos dois jogadores, terminou empatado !!!\n");

	}

	printf("\n!!!! FIM DO PROGRAMA !!!!\n");

	system("pause");

	return 0;
}

