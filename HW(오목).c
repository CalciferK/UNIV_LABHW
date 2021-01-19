// ����,����,�밢��,���밢���� üũ�ϴ� ����
// 6���� ������� ����
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define BOARD_SIZE 10

int winCheck(char b[][BOARD_SIZE], int r, int c);
void display(char b[][BOARD_SIZE]);

void main()
{
	char board[BOARD_SIZE][BOARD_SIZE];
	char turn = 'X';
	int r, c;
	int i, j;
	int count = 1;
	int win;

	for (i = 0; i < BOARD_SIZE; i++)
		for (j = 0; j < BOARD_SIZE; j++)
			board[i][j] = ' ';

	display(board);
	do
	{
		printf("Player %c(�� ��):", turn);
		scanf("%d %d", &r, &c);

		if (board[r][c] != ' ') 
			continue;

		board[r][c] = turn;
		display(board);

		if (win = winCheck(board, r, c))
			printf("Player %c wins!\n", turn);

		turn = (turn == 'X' ? 'O' : 'X');
		count++;

	} while (win == 0 && count <= BOARD_SIZE * BOARD_SIZE);

	if (win == 0 && count == BOARD_SIZE * BOARD_SIZE)
		printf("Nobody win!\n");
}

int winCheck(char b[][BOARD_SIZE], int r, int c) {
	char player = b[r][c];
	int sum1 = 1; //����	// �ϴ� �ϳ��� �������ϱ� 1�� ����.
	int sum2 = 1; //����
	int sum3 = 1; //�밢��
	int sum4 = 1; //���밢��
	int ri, ci;

	// ���� ���� �˻�
	ri = r;
	ci = c - 1;
	while (ci != -1 && b[ri][ci] == player) { 
		sum1++;
		ci--;
	}

	//���� ������ �˻�
	ci = c + 1;
	while (ci != 10 && b[ri][ci] == player) { 
		sum1++;
		ci++;
	}

	if (sum1 == 5)
		return 1;

	//���� ���� �˻�
	ci = c;
	ri = r - 1;
	while (ri != -1 && b[ri][ci] == player) { 
		sum2++;
		ri--;
	}

	//���� �Ʒ��� �˻�
	ri = r + 1;
	while (ri != 10 && b[ri][ci] == player) { 
		sum2++;
		ri++;
	}

	if (sum2 == 5)
		return 1;

	//�밢�� ���� �˻�
	ri = r - 1;
	ci = c - 1;
	while (ri != -1 && ci != -1 && b[ri][ci] == player) { 
		sum3++;
		ri--;
		ci--;
	}

	//�밢�� �Ʒ��� �˻�
	ci = c + 1;
	ri = r + 1;
	while (ri != 10 && ci != 10 && b[ri][ci] == player) { 
		sum3++;
		ri++;
		ci++;
	}

	if (sum3 == 5)
		return 1;

	//���밢�� ���� �˻�
	ri = r - 1;
	ci = c + 1;
	while (ri != -1 && ci != 10 && b[ri][ci] == player) { 
		sum3++;
		ri--;
		ci++;
	}

	//���밢�� �Ʒ��� �˻�
	ci = c - 1;
	ri = r + 1;
	while (ri != 10 && ci != -1 && b[ri][ci] == player) { 
		sum3++;
		ri++;
		ci--;
	}

	if (sum3 == 5)
		return 1;

	return 0;
}

void display(char b[][BOARD_SIZE])
{
	char ch;
	int i, j;
	printf("     ");
	for (i = 0; i < BOARD_SIZE; i++)
		printf("%2d", i);
	printf("\n     ---------------------\n");
	for (i = 0; i < BOARD_SIZE; i++) {
		printf("%3d |", i);
		for (j = 0; j < BOARD_SIZE; j++)
			printf(" %c", b[i][j]);
		printf("\n");
	}
}