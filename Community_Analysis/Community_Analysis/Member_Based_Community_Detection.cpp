
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;
const int MAX = 110;
bool map[MAX][MAX];   //图

int bestn=0; //当前最大顶点数,默认是的求最大团的参数
int best[MAX]; //当前最优解
vector<vector<int> > maxcliques;
int n, m;  //点数  边数
void dfs(int i, int num, vector<int> current){

	if (num != 0 && current.size() == num)
	{
		maxcliques.push_back(current);
		return;
	}
	/**
	for (int j = 0; j < current.size(); j++)
	{
		printf("%d  %d ", i,current[j]);
	}
	*/
	int len = 0,flag=0;
	for (int j = i+1; j <= n; j++)
	{
		for (int k = 0; k<current.size(); k++)
		{
			if (map[current[k]][j] != 1)
			{
				break;
			}
			else if (map[current[k]][j] == 1)
			{
				len++;
			}
		}
		if (len == current.size())
		{

			if (n - i >= num - current.size())
			{
				current.push_back(j);
				dfs(j, num, current);
				current.pop_back();
				len = 0;
			}
		}
	}
	if (num == 0&&flag==1)
	{
		if (bestn == 0)
		{
			bestn = current.size();
			maxcliques.push_back(current);
			for (int j = 0; j < current.size(); j++)
			{
				printf("%d ", current[j]);
			}
			return;
		}
		else if (current.size() > bestn)
		{
			bestn = current.size();
			maxcliques.clear();
			maxcliques.push_back(current);
			return;
		}
		else if (current.size() == bestn)
		{
			maxcliques.push_back(current);
			return;
		}
	}
}
int main(){

	int u, v;
	FILE *fd;
	if (fopen_s(&fd,"data.txt", "r")==NULL)
	{
		cout << "open error" << endl;
	}
	fscanf_s(fd,"%d\n", &n);
	memset(map, 0, sizeof(map));
	for (int i = 0; i < 14; i++)
	{
		fscanf_s(fd,"%d%d", &u, &v);
		map[u][v] = map[v][u] = 1;
	}
	vector<int> current;
	for (int i = 1; i <= n; i++)
	{
		current.push_back(i);
		dfs(i, 3, current);
		current.clear();
	}
	for (int i = 0; i < maxcliques.size(); i++)
	{
		for (int j = 0; j < maxcliques[i].size(); j++)
		{
			printf("%d ", maxcliques[i][j]);
		}
		printf("oo\n");
	}
	return 0;
}