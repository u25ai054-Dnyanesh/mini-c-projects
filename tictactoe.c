#include<stdio.h>
#include<stdlib.h>

void takeInput(char matrix[3][3], int *r, int *c) {
    while (1) {
    	int p;
        printf("Enter row and column using key pad");
        scanf("%d",&p);
        switch(p)
        {
        	case 1:*r=2;
        	*c=0;
        		break;
        	case 2:*r=2;
        	*c=1;
        		break;
        	case 3:*r=2;
        	*c=2;
        		break;
        	case 4:*r=1;
        	*c=0;
        		break;
        	case 5:*r=1;
        	*c=1;
        		break;
        	case 6:*r=1;
        	*c=2;
        		break;
        	case 7:*r=0;
        	*c=0;
        		break;
        	case 8:*r=0;
        	*c=1;
        		break;
        	case 9:*r=0;
        	*c=2;
        		break;
		}

        if (*r < 0 || *r > 2 || *c < 0 || *c > 2) {
            printf("Invalid position! Try again.\n");
            continue;
        }

        if (matrix[*r][*c] != '.') {
            printf("That spot is already taken! Try again.\n");
            continue;
        }

        break; 
    }
}


int won(char a, char matrix[3][3]) {
    if (matrix[0][0] != '.' && matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2]) {
        return 1;
    }
    if (matrix[0][2] != '.' && matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0]) {
        return 1;
    }
    for (int i=0; i<3; i++) {
        if (matrix[i][0] != '.' && matrix[i][0] == matrix[i][1] && matrix[i][1] == matrix[i][2]) {
            return 1;
        }
        if (matrix[0][i] != '.' && matrix[0][i] == matrix[1][i] && matrix[1][i] == matrix[2][i]) {
            return 1;
        }
    }
    return 0;
}
int main() {
    char matrix[3][3];
    for (int k=0 ;k<3; k++) {
        for(int m=0; m<3; m++) {
            matrix[k][m] = '.';
        }
    }
    for (int k=0 ;k<3; k++) {
        for(int m=0; m<3; m++) {
            printf(" %c ", matrix[k][m]);
        }
        printf("\n");
    }
    int z=0;
    while (z<9) {
        int i, j;

        printf("Enter turn of X:\n");
        takeInput(matrix, &i, &j);
        matrix[i][j] = 'X';


        z++;
        for (int k=0 ;k<3; k++) {
            for(int m=0; m<3; m++) {
                printf(" %c ", matrix[k][m]);
            }
            printf("\n");
        }

        if (won('X', matrix)) {
            printf("'X' WON!!");
            exit(1);
        }
        

        printf("Enter turn of 0:\n");
        takeInput(matrix, &i, &j);
        matrix[i][j] = '0';

        z++;
        for (int k=0 ;k<3; k++) {
            for(int m=0; m<3; m++) {
                printf(" %c ", matrix[k][m]);
            }
            printf("\n");
        }
        if (won('0', matrix)) {
            printf("'0' WON!!");
            exit(1);
        }
        


    }
}
