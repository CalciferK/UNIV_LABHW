// 수평,수직,대각선,역대각선도 체크하는 오목
// 6목은 허용하지 않음
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
		printf("Player %c(열 행):", turn);
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
	int sum1 = 1; //수평	// 일단 하나를 놓았으니까 1이 들어간다.
	int sum2 = 1; //수직
	int sum3 = 1; //대각선
	int sum4 = 1; //역대각선
	int ri, ci;

	// 수평 왼쪽 검사
	ri = r;
	ci = c - 1;
	while (ci != -1 && b[ri][ci] == player) { 
		sum1++;
		ci--;
	}

	//수평 오른쪽 검사
	ci = c + 1;
	while (ci != 10 && b[ri][ci] == player) { 
		sum1++;
		ci++;
	}

	if (sum1 == 5)
		return 1;

	//수직 위쪽 검사
	ci = c;
	ri = r - 1;
	while (ri != -1 && b[ri][ci] == player) { 
		sum2++;
		ri--;
	}

	//수직 아래쪽 검사
	ri = r + 1;
	while (ri != 10 && b[ri][ci] == player) { 
		sum2++;
		ri++;
	}

	if (sum2 == 5)
		return 1;

	//대각선 위쪽 검사
	ri = r - 1;
	ci = c - 1;
	while (ri != -1 && ci != -1 && b[ri][ci] == player) { 
		sum3++;
		ri--;
		ci--;
	}

	//대각선 아래쪽 검사
	ci = c + 1;
	ri = r + 1;
	while (ri != 10 && ci != 10 && b[ri][ci] == player) { 
		sum3++;
		ri++;
		ci++;
	}

	if (sum3 == 5)
		return 1;

	//역대각선 위쪽 검사
	ri = r - 1;
	ci = c + 1;
	while (ri != -1 && ci != 10 && b[ri][ci] == player) { 
		sum3++;
		ri--;
		ci++;
	}

	//역대각선 아래쪽 검사
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