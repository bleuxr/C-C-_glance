#include <iostream>  
using namespace std;


int compare(const int *d1, const int *d2)
{
	int i = 0;
	while (d1[i] != 10 && d2[i] != 10)
	{
		i++;
	}
	if (d1[i] == 10 && d2[i] == 10)
	{
		for (; i >= 0; i--)
		{
			if (d1[i] > d2[i])
				return 1;
			if (d1[i] < d2[i])
				return -1;
		}
		return 0;
	}
	else if (d1[i]==10)
	{
		return -1;
	}
	else
	{
		return 1;
	}
}


void arradd(int *d,const int *d1, const int *d2)
{
	int i = 0, j = 0, pass = 0;
	while (d1[i] != 10 && d2[i] != 10)
	{
		d[i] = (d1[i] + d2[i] + pass) % 10;
		pass = (d1[i] + d2[i] + pass) / 10;
		i++;
	}
	j = i;
	while (d1[i] != 10)
	{
		d[i] = (d1[i] + pass) % 10;
		pass = (d1[i] + pass) / 10;
		i++;
	}
	while (d2[j] != 10)
	{
		d[j] = (d2[j] + pass) % 10;
		pass = (d2[j] + pass) / 10;
		j++;
	}
	i = (i > j) ? i : j;
	d[i] = pass;
	while (d[i] == 0)
	{
		i--;
	}
	d[i + 1] = 10;
}


void arrsub(int *d, const int *d1, const int *d2)
{
	int i = 0, pass = 0, result = 0;
	while (d2[i] != 10)
	{
		result = d1[i] - d2[i] - pass;
		if (result >= 0)
		{
			d[i] = result;
			pass = 0;
		}
		else
		{
			d[i] = result + 10;
			pass = 1;
		}
		i++;
	}
	while (d1[i] != 10)
	{
		result = d1[i] - pass;
		if (result > 0)
		{
			d[i] = result;
			pass = 0;
		}
		else
		{
			d[i] = result + 10;
			pass = 1;
		}
		i++;
	}

	d[i] = pass;
	while (d[i] == 0)
	{
		i--;
	}
	d[i + 1] = 10;
}


class largenum
{
private:
	int data[200];
	int flag;
public:
	largenum(const int *da,int f)
	{
		int i = 0;

		flag = f;

		while (da[i] != 10)
		{
			data[i] = da[i];
			i++;
		}
		data[i] = 10;
	}
	largenum(largenum &d,int f)
	{
		int i = 0;

		flag = f;

		while (d.data[i] != 10)
		{
			data[i] = d.data[i];
			i++;
		}
		data[i] = 10;
	}
	friend largenum operator+(const largenum &d1, const largenum &d2)
	{
		if (d1.flag == 0 && d2.flag == 0)
		{
			int d[200];
			arradd(d, d1.data, d2.data);
			largenum r(d, 0);
			return r;
		}
		else if (d1.flag==1&&d2.flag==1)
		{
			int d[200];
			arradd(d, d1.data, d2.data);
			largenum r(d, 1);
			return r;
		}
		else if (d1.flag==0&&d2.flag==1)
		{
			int com = compare(d1.data, d2.data);
			if (com > 0) {
				int d[200];
				arrsub(d, d1.data, d2.data);
				largenum r(d, 0);
				return r;
			}
			else if (com <0)
			{
				int d[200];
				arrsub(d, d2.data, d1.data);
				largenum r(d, 1);
				return r;
			}
			else
			{
				int d[200];
				d[0] = 10;
				largenum r(d, 0);
				return r;
			}
		}
		else
		{
			int com = compare(d1.data, d2.data);
			if (com > 0) {
				int d[200];
				arrsub(d, d1.data, d2.data);
				largenum r(d, 1);
				return r;
			}
			else if (com <0)
			{
				int d[200];
				arrsub(d, d2.data, d1.data);
				largenum r(d, 0);
				return r;
			}
			else
			{
				int d[200];
				d[0] = 10;
				largenum r(d, 0);
				return r;
			}
		}
	}

	friend largenum operator-(const largenum &d1, const largenum &d2)
	{
		if (d1.flag == 0 && d2.flag == 0)
		{
			int com = compare(d1.data, d2.data);
			if (com > 0) {
				int d[200];
				arrsub(d, d1.data, d2.data);
				largenum r(d, 0);
				return r;
			}
			else if (com <0)
			{
				int d[200];
				arrsub(d, d2.data, d1.data);
				largenum r(d, 1);
				return r;
			}
			else
			{
				int d[200];
				d[0] = 10;
				largenum r(d, 0);
				return r;
			}
		}
		else if (d1.flag == 1 && d2.flag == 1)
		{
			int com = compare(d1.data, d2.data);
			if (com > 0) {
				int d[200];
				arrsub(d, d1.data, d2.data);
				largenum r(d, 1);
				return r;
			}
			else if (com <0)
			{
				int d[200];
				arrsub(d, d2.data, d1.data);
				largenum r(d, 0);
				return r;
			}
			else
			{
				int d[200];
				d[0] = 10;
				largenum r(d, 0);
				return r;
			}
		}
		else if (d1.flag == 0 && d2.flag == 1)
		{
			int d[200];
			arradd(d, d1.data, d2.data);
			largenum r(d, 0);
			return r;
		}
		else
		{
			int d[200];
			arradd(d, d1.data, d2.data);
			largenum r(d, 1);
			return r;
		}
	}


	friend ostream &operator<<(ostream &out, const largenum&d);


};


ostream &operator<<(ostream &out, const largenum &d)
{
	int i = 0;

	if (d.data[i] == 10)
	{
		out << 0;
		return out;
	}


	if (d.flag == 1)
	{
		out << '-';
	}

	
	while (d.data[i] != 10)
	{
		i++;
	}
	for (--i; i >= 0; i--) {
		out << d.data[i];
	}

	return out;
}


int main()
{
	int i = 0, j = 0, flag1 = 0, flag2 = 0;

	char d1[200];
	char d2[200];
	d1[i] = getchar();
	if (d1[i] == '-')
	{
		flag1 = 1;
		d1[i] = getchar();
	}
	else if(d1[i]==' ')
	{
		d1[i] = getchar();
	}
	while (d1[i] != '\n')
	{
		i++;
		d1[i] = getchar();
	}
	d1[i] = '\0';


	i = 0;
	d2[i] = getchar();
	if (d2[i] == '-')
	{
		flag2 = 1;
		d2[i] = getchar();
	}
	else if(d2[i]==' ')
	{
		d2[i] = getchar();
	}
	while (d2[i] != '\n')
	{
		i++;
		d2[i] = getchar();
	}
	d2[i] = '\0';


	int in1[200], in2[200];

	i = 0;
	j = 0;
	while (d1[i] != '\0')
	{
		i++;
	}
	in1[i] = 10;
	for (--i; i >= 0; i--)
	{
		in1[i] = d1[j] - '0';
		j++;
	}


	i = 0;
	j = 0;
	while (d2[i] != '\0')
	{
		i++;
	}
	in2[i] = 10;
	for (--i; i >= 0; i--)
	{
		in2[i] = d2[j] - '0';
		j++;
	}



	largenum l1(in1,flag1);
	largenum l2(in2,flag2);
	largenum l3(l1 + l2);
	largenum l4(l1 - l2);
	cout << l3 << endl << l4 << endl;

	return 0;
}

