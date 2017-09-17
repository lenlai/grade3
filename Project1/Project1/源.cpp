#include<iostream>
#include<cmath>
using namespace std;
const int MAX = 1000;


class Entry
{
public:
	static void welcome()
	{
		cout << "��ӭ����������������棬�ó�����Ϊ���ݱ��ʽ���м��㡣\n"
			<< "����ʵ�ֵļ���Ϊ�Ӽ��˳��������㣬"
			<< "֧��С�����㣬Ҳ֧�ָ����Ķ��룬����Ҫ�����Ž���������\n"
			<< "���·����봦������ʽ���Իس�������\n"
			<< "=========================Felix============================\n\n"
			<< "��������ʽ���س�������";
	}
};


class Input
{
public:
	Input()
	{
		for (int i = 0; i < MAX; i++)
			Str_input[i] = '\0';
	}
	char Str_input[MAX];
	void inStr()
	{
		cin >> Str_input;
	}
};


class Output
{
public:
	Output()
	{
		result = 0;
	}
	void getRes(double res)
	{
		result = res;
	}
	void printRes()
	{
		cout << "������ʽ�Ľ��Ϊ��" << result << endl;
	}
private:
	double result;
};


template <class Type>
class STACK {                 //����ջ��
private:
	Type base[MAX];
	int Size;
public:
	STACK() { Size = 0; };
	void push(Type a)     //��ջ
	{
		base[Size] = a;
		Size++;
	}
	Type pop()            //��ջ
	{
		return base[--Size];
	}
	int size()
	{
		return Size;
	}
};



class Calculate_Cla
{
public:
	bool IsData(char);
	bool IsSym(char);
	int IsPar(char);
	bool Check(char *);
	int setPri(char);                 //�жϷ��ŵ����ȼ���
	double ToData(char*);               //���ַ���ת��Ϊ��ֵ
	double Call(double, double, char);    //���尴���ż���
	int GetMatch(char* buffer, int pos); //����ջ�ҵ�ƥ�������
	void Opr(STACK<char>&, STACK<double>&, int&); //����ջ����
	double Calculate(char*, double&);   //�ַ����Ķ��뼰����

};
bool Calculate_Cla::IsData(char ch)      //�ж��������������Ƿ�Ϊ0-9
{
	return ((ch >= '0'&&ch <= '9') || ch == '.') ? true : false;
}
bool Calculate_Cla::IsSym(char ch)      //�ж��Ƿ�����Ƿ������
{
	return (ch == '+' || ch == '-' || ch == '*' || ch == '/') ? true : false;
}
int Calculate_Cla::IsPar(char ch)
{
	if (ch == '(')
		return 1;
	if (ch == ')')
		return -1;
	return 0;
}
bool Calculate_Cla::Check(char *ch)
{
	int a = 0;
	for (int i = 0; i<strlen(ch); i++)
		if (ch[i] == '.')
			a++;
	if (a>1)
		return false;
	return true;
}
int Calculate_Cla::setPri(char ch)          //���ŵ����ȼ���
{
	switch (ch)
	{
	case '+':
		return 0;
	case '-':
		return 0;
	case '*':
		return 1;
	case '/':
		return 1;
	default:
		return -1;
	}
}
double Calculate_Cla::ToData(char* ch)   //������ת��Ϊ��ֵ
{
	int i, j, sumn = 0;
	double sum = 0.0;
	if (!Check(ch)) return 0.0;
	for (i = 0; i<strlen(ch); i++)             //������������
	{
		if (ch[i] != '.')
			sumn = sumn * 10 + (ch[i] - '0');
		else break;
	}
	if (i<strlen(ch))
		for (j = i + 1; j<strlen(ch); j++)        //С������
			sum = sum * 10 + (ch[j] - '0');
	sum /= pow(10.0, (double)(strlen(ch) - 1 - i));
	return (sum + sumn);                      //����ֵ
}
double Calculate_Cla::Call(double sum, double data, char ch)
{
	double ans = 0.0;
	switch (ch)
	{
	case '+':
		ans = sum + data;
		break;
	case '-':
		ans = sum - data;
		break;
	case '*':
		ans = sum*data;
		break;
	case '/':
		if (data != 0.0)
			ans = sum / data;
		else
		{
			cout << "������ֳ�0������ֹ��\n";
			system("pause");
			exit(1);
		}
		break;
	default:ans = 0.0;
		break;
	}
	return ans;
}
int Calculate_Cla::GetMatch(char* buffer, int pos)     //����ջ�ҵ�ƥ�������
{
	STACK<char> Temp;
	int i;
	for (i = pos; i<strlen(buffer); i++)
	{
		if (IsPar(buffer[i]) == 1)
			Temp.push('0');
		if (IsPar(buffer[i]) == -1)
		{
			Temp.pop();
			if (Temp.size() == 0) return i;
		}
	}
	return -1;
}
void Calculate_Cla::Opr(STACK<char>& symbol, STACK<double>& data, int& mark)
{
	double sum;
	while (symbol.size() != 0)
	{
		char tem = symbol.pop();
		int temp = setPri(tem);
		symbol.push(tem);
		if (temp<mark)
			break;
		else {
			sum = Call(data.pop(), data.pop(), symbol.pop());
			data.push(sum);
		}
	}
}
double Calculate_Cla::Calculate(char* buffer, double& sum)   //�ַ�������͸�����������
{
	STACK<double> data;
	STACK<char> symbol;
	double ans;
	char temp[MAX];
	int ct = 0, mark = 0, tp = 0;
	data.push(sum);
	while (ct <= strlen(buffer))
	{
		if (IsData(buffer[ct]))            //��������ֻ�С����
		{
			while (ct < strlen(buffer) && IsData(buffer[ct]))
				temp[tp++] = buffer[ct++];
			temp[tp] = '\0';
			tp = 0;                         //����������Ҳ��С��Ϊֹ
			ans = ToData(temp);             //�Ѷ������ַ���ת��Ϊ��
			data.push(ans);

			if (ct == strlen(buffer))        //�Ѿ������ַ���ĩβ
			{
				mark = 0;
				Opr(symbol, data, mark);    //����
				sum = data.pop();           //��ʱdataջ�л�ʣһ�����ݣ����ǽ��
				return sum;               //���ؽ��
			}
			else {
				int mark = setPri(buffer[ct]);
				Opr(symbol, data, mark);     //����
			}
		}
		else if (IsSym(buffer[ct]))         //����������
			symbol.push(buffer[ct++]);     //�������symbolջ
		else
		{
			char BF[100]; int k = 0;          //��������ǣ���ֻ��������
			while (IsPar(buffer[ct]) != 1 && ct <= strlen(buffer))
				BF[k++] = buffer[ct++];
			BF[k] = '\0';
			if (IsPar(buffer[ct]) == 1)       //һ�����������ţ�Ѱ����ƥ���������
			{
				int i, j;
				char Temp[100];
				for (i = ct + 1, j = 0; i<GetMatch(buffer, ct); i++, j++)
					Temp[j] = buffer[i];     //����������е��ַ�������Temp
				Temp[j] = '\0';
				data.push(Calculate(Temp, sum)); //�ݹ����Calculateֱ��û������
												 //Ȼ��ʼ���㣬ֵ��㷵��������ս������dataջ
				ct += (strlen(Temp) + 1);       //�����Ѿ���������ַ�
				if (ct + 1 == strlen(buffer))    //���￼���ַ��������Ž�β�����
				{
					mark = 0;
					Opr(symbol, data, mark);
					sum = data.pop();
					return sum;
				}
				else
				{
					mark = setPri(buffer[ct + 1]); //���ǵĻ���������
					Opr(symbol, data, mark);
				}
				ct++;                           //������һ���ַ�
			}
		}
	}
	return 0.;
}



class CheckStr
{
public:
	static int check(char *str)
	{
		int i;
		STACK<char> Temp;
		for (i = 0; i < strlen(str); i++)
		{
			char t = str[i];
			if (!((int(str[i]) <= 57 && int(str[i]) >= 48) || str[i] == '(' || str[i] == ')' || str[i] == '*'
				|| str[i] == '+' || str[i] == '-' || str[i] == '/' || str[i] == '.'))       //����Ƿ��зǷ��ַ�
				return 2;
			else if (str[i] == '(')
				Temp.push('0');
			else if (str[i] == ')')
			{
				if (Temp.size() <= 0)                                      //��������Ƿ�ƥ�䣬�������Ƿ����
					return 1;
				else
					Temp.pop();
			}
		}
		if (Temp.size() != 0)                                                //��������Ƿ�ƥ�䣬�������Ƿ����
			return 1;
		return 0;
	}
};

int main()
{
	Entry::welcome();                           //��ӭģ��
	double sum = 0.0;
	cout.precision(12);

	Input in;
	Calculate_Cla cl;
	Output out;

	while (1)
	{
		in.inStr();                              //����ģ��
		int res = CheckStr::check(in.Str_input); //�ж�ģ��
		if (res == 0)
			break;
		else if (res == 1)
			cout << "�����ַ������Ų�ƥ�䣬���������룺\n";
		else if (res == 2)
			cout << "�����ַ����зǷ��ַ������������룺\n";
		else
		{
		}
	}
	out.getRes(cl.Calculate(in.Str_input, sum)); //����ģ��
	out.printRes();                               //���ģ��
	system("pause");
	return 0;
}