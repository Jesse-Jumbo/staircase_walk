#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>

using namespace std;

const int X = 8, Y = 8;                            /*�]�@���ܼƥΩ�]�w�}�C(�a��)�j�p*/
int a[X][Y];                                       /*�ŧi�@�ӤG���}�Ca�Ω���C�p��C�U�@�B�A�Ӹ��|���`��*/
int c[X][Y];                                       /*�ŧi�@�ӤG���}�Cc�Ω��x�s�̲׸��|���`��*/
int p[X][Y];                                       /*�ŧi�@�ӤG�}�Cp�Ω��x�s���|*/
int out[X+Y-1];                                    /*�ŧi�@�Ӥ@���}�Cout�A�Ω��X�̲ר����ߤ@(�̤p)���|(�w�]�̤֨B��)*/
 
void staircase_walk()                              /*�w�q�@�Ө禡�B�z�ӱ���|*/
{
    // [Initial States]
    c[0][0] = a[0][0];                             /*��l��c�Ma�}�C�A��}�C�P�@��*/
    p[0][0] = -1;   // �S�����Y                    /*�N���|���_�I�]��-1��ܤ��q����a�訫��*/
    for (int i=1; i<X; i++)                        /*�Ыؤ@�Ӱj���l��c�Mp���Ĥ@�檺��*/
    {
        c[i][0] = c[i-1][0] + a[i][0];             /*�N�Ĥ@�檺�ȡA�Q��a�}�C�A��s�bc�}�C�W�A�C����s���o���ȻP�W�@�檺�Ȭۥ[*/
        p[i][0] = 0;    // �q�W����                /*�NP�}�C�Ĥ@��(�u��q�W���Ӫ����|)�]��0*/
    }
    for (int j=1; j<Y; j++)                        /*�Ыؤ@�Ӱj���l��c�Mp���Ĥ@�C����*/
    {
        c[0][j] = c[0][j-1] + a[0][j];             /*�N�Ĥ@�C���ȡA�Q��a�}�C�A��s�bc�}�C�W�A�C����s���o���ȻP���@�檺�Ȭۥ[*/
        p[0][j] = 1;    // �q������                /*�N�Ĥ@�C(�u��q�����Ӫ����|)�]��1*/
    }
 
    // [Computation]
    for (int i=1; i<X; i++)                        /*�Ф@�Ӱj��Ω��s�q c�M p���ĤG��}�l���C��Y�b(�C)*/
        for (int j=1; j<Y; j++)                    /*�Ф@�Ӱj��Ω��s�q c�M p���ĤG�C�}�l���C��X�b(��)*/
            if (c[i-1][j] < c[i][j-1])             /*�p�GC�}�C�W�A�W������<���䪺��(�N��q�W���ӬO�ڭn���̤p���|��)*/
            {
                c[i][j] = c[i-1][j] + a[i][j];     /*�Q��a�}�C�A�Nc�C���I���ȧ�s���b�ۦP��m���ȥ[�Wc�W������*/
                p[i][j] = 0;    // �q�W����        /*�æbp�}�C�W���I���ȧ�s��0�A�N��ڭ̿�ܱq�W���U��(�����|�Ȥp���W��)*/
            }
            else if (c[i-1][j] > c[i][j-1])        /*�_�h�p�Gc�}�C�W�A�W������>���䪺��(�N��q�����ӬO�ڭn���̤p���|��)*/
            {
                c[i][j] = c[i][j-1] + a[i][j];     /*�Q��a�}�C�A�Nc�C���I���ȧ�s���b�ۦP��m���ȥ[�Wc���䪺��*/
                p[i][j] = 1;    // �q������        /*�æbp�}�C�W���I���ȧ�s��1�A�N��ڭ̿�ܥ����L��(�����|�Ȥp������)*/
            }
            else /*if (c[i-1][j] == c[i][j-1])*/   /*�H�W�ҫD�����p�A�N��c���W�M���Ȭ۵�(==)*/
            {
                // �q�W���ӡB�q�����ӳ��i�H�A�o�̨����C
                c[i][j] = c[i][j-1] + a[i][j];     /*���ި������O�@�ˤp����(can also: c[i][j] = c[i-1][j] + a[i][j])*/
                p[i][j] = 1;                       /*�p�G�O�q�W���ӫhp[i][j] = 0*/
            }
 
    // �ϦV�l�ܸ��u���Y
    int n = 0;  // out size                        /*�ŧi�@�Ӿ��n�A�Ω�out�����ޭ�*/
    for (int i=X-1, j=Y-1; i>=0 && j>=0; )         /*�qp(7, 7)�˰h�`���@���� p(0, 0)�t�H�~�A�Y����*/
    {
        out[n++] = p[i][j];                        /*�C���`���A�ƻs�qp�}�C�N�̲שҨ����̤p���|��out*/
        if (p[i][j] == 0) i--;                     /*�p�Gp�����I�Ȭ�0(�N��q�W����)�A�Ni-1(�N�������W�@��)*/
        else if (p[i][j] == 1) j--;                /*�S�p�Gp�����I�Ȭ�1(�N��q������)�A�Nj-1(�N���������@��)*/
    }
 
    // �L�X���u
    for (int i=n-1; i>=0; --i)                     /*�Ыؤ@�Ӱj��Nout�����Ҧ��ȤϦV��X(����J�ɬO�ϦV���A�{�b�ϤϬ���)*/
        cout << out[i];
}


int main(int argc, char** argv) {
	srand(time(NULL));              		       /*�H�����*/ /*srand()�̷�()���ѼƲ��Ͷü�*/ /*time()�̷ӥثe�ɶ�*/
	
	int rows;
	int columns;
	int map[rows][columns];

	cin >> rows >> columns;
	
	for(int i=0; i<rows; i++){	
		for(int n=0; n<columns; n++){

			map[i][n] = (rand()%9)+1;
	
			cout << setw(2) << map[i][n];			  /**/
			
   		}
 		cout <<endl;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
