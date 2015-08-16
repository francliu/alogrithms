/*************************************************************************
> File Name: matrix.h
> Author: ������
> Mail: liujianfei526@163.com
> Created Time: 2015��04��06�� ����һ 23ʱ09��51��
************************************************************************/
#include<iostream>
#include<vector>
#include<map>
#define N 10
using namespace std;
class matrix
{
public:
	//����: ���ò�����Ԫ�ĸ�˹��ȥ������A�������B
	//��ڲ���: ���뷽��������󣬷������
	bool Gauss(float A[][N], float B[][N], int n)
	{
		int i, j, k;
		float max, temp;
		float t[N][N];                //��ʱ����
		//��A����������ʱ����t[n][n]��
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				t[i][j] = A[i][j];
			}
		}
		//��ʼ��B����Ϊ��λ��
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				B[i][j] = (i == j) ? (float)1 : 0;
			}
		}
		for (i = 0; i < n; i++)
		{
			//Ѱ����Ԫ
			max = t[i][i];
			k = i;
			for (j = i + 1; j < n; j++)
			{
				if (fabs(t[j][i]) > fabs(max))
				{
					max = t[j][i];
					k = j;
				}
			}
			//�����Ԫ�����в��ǵ�i�У������н���
			if (k != i)
			{
				for (j = 0; j < n; j++)
				{
					temp = t[i][j];
					t[i][j] = t[k][j];
					t[k][j] = temp;
					//B���潻��
					temp = B[i][j];
					B[i][j] = B[k][j];
					B[k][j] = temp;
				}
			}
			//�ж���Ԫ�Ƿ�Ϊ0, ����, �����A�������Ⱦ���,�����������
			if (t[i][i] == 0)
			{
				cout << "There is no inverse matrix!";
				return false;
			}
			//��ȥA�ĵ�i�г�ȥi������ĸ���Ԫ��
			temp = t[i][i];
			for (j = 0; j < n; j++)
			{
				t[i][j] = t[i][j] / temp;        //���Խ����ϵ�Ԫ�ر�Ϊ1
				B[i][j] = B[i][j] / temp;        //�������
			}
			for (j = 0; j < n; j++)        //��0��->��n��
			{
				if (j != i)                //���ǵ�i��
				{
					temp = t[j][i];
					for (k = 0; k < n; k++)        //��j��Ԫ�� - i��Ԫ��*j��i��Ԫ��
					{
						t[j][k] = t[j][k] - t[i][k] * temp;
						B[j][k] = B[j][k] - B[i][k] * temp;
					}
				}
			}
		}
		return true;
	}
	void print(float p[N][N], int n)
	{
		int i, j;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				printf("%.1f ", p[i][j]);
			}
		}
	}
	void dialog(float D[N][N], float Node[N])
	{

		//��ʼ��D����
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				D[i][j] = (i == j) ? (float)(Node[i]) : 0;
			}
		}
	}
	//�������
	void muti_matric(float temp[N][N], float invD[N][10], float vertex[N][N])
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				float num = 0;
				for (int k = 0; k < N; k++)
				{
					num += vertex[i][k] * invD[k][j];
				}
				temp[i][j] = num;
				//cout<<temp[i][j]<<" ";
			}
			//cout<<endl;
		}
	}
	/**
	* @brief ��ʵ�Գƾ��������ֵ�������������ſ˱ȷ�
	* �����Ÿ��(Jacobi)������ʵ�Գƾ����ȫ������ֵ����������
	* @param pMatrix				����Ϊn*n�����飬���ʵ�Գƾ���
	* @param nDim					����Ľ���
	* @param pdblVects				����Ϊn*n�����飬������������(���д洢)
	* @param dbEps					����Ҫ��
	* @param nJt					���ͱ�������������������
	* @param pdbEigenValues			����ֵ����
	* @return
	*/
	bool JacbiCor(double * pMatrix, int nDim, double *pdblVects, double *pdbEigenValues, double dbEps, int nJt)
	{
		for (int i = 0; i < nDim; i++)
		{
			pdblVects[i*nDim + i] = 1.0f;
			for (int j = 0; j < nDim; j++)
			{
				if (i != j)
					pdblVects[i*nDim + j] = 0.0f;
			}
		}

		int nCount = 0;		//��������
		while (1)
		{
			//��pMatrix�ķǶԽ������ҵ����Ԫ��
			double dbMax = pMatrix[1];
			int nRow = 0;
			int nCol = 1;
			for (int i = 0; i < nDim; i++)			//��
			{
				for (int j = 0; j < nDim; j++)		//��
				{
					double d = fabs(pMatrix[i*nDim + j]);

					if ((i != j) && (d> dbMax))
					{
						dbMax = d;
						nRow = i;
						nCol = j;
					}
				}
			}

			if (dbMax < dbEps)     //���ȷ���Ҫ��
				break;

			if (nCount > nJt)       //����������������
				break;

			nCount++;

			double dbApp = pMatrix[nRow*nDim + nRow];
			double dbApq = pMatrix[nRow*nDim + nCol];
			double dbAqq = pMatrix[nCol*nDim + nCol];

			//������ת�Ƕ�
			double dbAngle = 0.5*atan2(-2 * dbApq, dbAqq - dbApp);
			double dbSinTheta = sin(dbAngle);
			double dbCosTheta = cos(dbAngle);
			double dbSin2Theta = sin(2 * dbAngle);
			double dbCos2Theta = cos(2 * dbAngle);

			pMatrix[nRow*nDim + nRow] = dbApp*dbCosTheta*dbCosTheta +
				dbAqq*dbSinTheta*dbSinTheta + 2 * dbApq*dbCosTheta*dbSinTheta;
			pMatrix[nCol*nDim + nCol] = dbApp*dbSinTheta*dbSinTheta +
				dbAqq*dbCosTheta*dbCosTheta - 2 * dbApq*dbCosTheta*dbSinTheta;
			pMatrix[nRow*nDim + nCol] = 0.5*(dbAqq - dbApp)*dbSin2Theta + dbApq*dbCos2Theta;
			pMatrix[nCol*nDim + nRow] = pMatrix[nRow*nDim + nCol];

			for (int i = 0; i < nDim; i++)
			{
				if ((i != nCol) && (i != nRow))
				{
					int u = i*nDim + nRow;	//p
					int w = i*nDim + nCol;	//q
					dbMax = pMatrix[u];
					pMatrix[u] = pMatrix[w] * dbSinTheta + dbMax*dbCosTheta;
					pMatrix[w] = pMatrix[w] * dbCosTheta - dbMax*dbSinTheta;
				}
			}

			for (int j = 0; j < nDim; j++)
			{
				if ((j != nCol) && (j != nRow))
				{
					int u = nRow*nDim + j;	//p
					int w = nCol*nDim + j;	//q
					dbMax = pMatrix[u];
					pMatrix[u] = pMatrix[w] * dbSinTheta + dbMax*dbCosTheta;
					pMatrix[w] = pMatrix[w] * dbCosTheta - dbMax*dbSinTheta;
				}
			}

			//������������
			for (int i = 0; i < nDim; i++)
			{
				int u = i*nDim + nRow;		//p
				int w = i*nDim + nCol;		//q
				dbMax = pdblVects[u];
				pdblVects[u] = pdblVects[w] * dbSinTheta + dbMax*dbCosTheta;
				pdblVects[w] = pdblVects[w] * dbCosTheta - dbMax*dbSinTheta;
			}

		}

		//������ֵ���������Լ�����������������,����ֵ��pMatrix���Խ����ϵ�Ԫ��
		std::map<double, int> mapEigen;
		for (int i = 0; i < nDim; i++)
		{
			pdbEigenValues[i] = pMatrix[i*nDim + i];

			mapEigen.insert(make_pair(pdbEigenValues[i], i));
		}

		double *pdbTmpVec = new double[nDim*nDim];
		std::map<double, int>::reverse_iterator iter = mapEigen.rbegin();
		for (int j = 0; iter != mapEigen.rend(), j < nDim; ++iter, ++j)
		{
			for (int i = 0; i < nDim; i++)
			{
				pdbTmpVec[i*nDim + j] = pdblVects[i*nDim + iter->second];
			}

			//����ֵ��������
			pdbEigenValues[j] = iter->first;
		}

		//�趨������
		for (int i = 0; i < nDim; i++)
		{
			double dSumVec = 0;
			for (int j = 0; j < nDim; j++)
				dSumVec += pdbTmpVec[j * nDim + i];
			if (dSumVec<0)
			{
				for (int j = 0; j < nDim; j++)
					pdbTmpVec[j * nDim + i] *= -1;
			}
		}

		memcpy(pdblVects, pdbTmpVec, sizeof(double)*nDim*nDim);
		delete[]pdbTmpVec;

		return 1;
	}
	void mutex(float I[N][N], float vertex[N][N], float a, int n)
	{

		//��ʼ��I����Ϊ��λ��
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				I[i][j] = (i == j) ? (float)1 : 0;
			}
		}
		//�������
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				I[i][j] = I[i][j] - a*vertex[i][j];
			}
		}
		//print(I,n);
	}
};
