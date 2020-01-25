/*************************************/
/************ VIVEK PAL **************/
/************ 17MA20048 **************/
/*************************************/
#include<bits/stdc++.h>
#include<string>
#include<string.h>
using namespace std;
/*************************************/
/******* END of HEADER ***************/
/*************************************/

char charcarry(char a, char b)
{
	if(a>b) swap(a,b);
	if(a == '0') return '0';
	if(a == '1')
	{
		if(b == '9') return '1';
		else return '0';
	}
	if(a == '2')
	{
		if(b >= '8') return '1';
		else return '0';
	}
	if(a == '3')
	{
		if(b >= '7') return '1';
		else return '0';
	}
	if(a == '4')
	{
		if(b >= '6') return '1';
		else return '0';
	}
	if(a == '5')
	{
		if(b >= '5') return '1';
		else return '0';
	}
	if(a == '6')
	{
		if(b >= '4') return '1';
		else return '0';
	}
	if(a == '7')
	{
		if(b >= '3') return '1';
		else return '0';
	}
	if(a == '8')
	{
		if(b >= '2') return '1';
		else return '0';
	}
	if(a == '9')
	{
		if(b >= '1') return '1';
		else return '0';
	}
}
char addchar(char x, char y)
{
	char a, b;
	if(x<y) a=x, b=y;
	else a=y, b=x;
	if(a == '0') return b;
	if(a == '1')
	{
		if(b == '1') return '2';
		if(b == '2') return '3';
		if(b == '3') return '4';
		if(b == '4') return '5';
		if(b == '5') return '6';
		if(b == '6') return '7';
		if(b == '7') return '8';
		if(b == '8') return '9';
		if(b == '9') return '0';
	}
	if(a == '2')
	{
		if(b == '2') return '4';
		if(b == '3') return '5';
		if(b == '4') return '6';
		if(b == '5') return '7';
		if(b == '6') return '8';
		if(b == '7') return '9';
		if(b == '8') return '0';
		if(b == '9') return '1';
	}
	if(a == '3')
	{
		if(b == '3') return '6';
		if(b == '4') return '7';
		if(b == '5') return '8';
		if(b == '6') return '9';
		if(b == '7') return '0';
		if(b == '8') return '1';
		if(b == '9') return '2';
	}
	if(a == '4')
	{
		if(b == '4') return '8';
		if(b == '5') return '9';
		if(b == '6') return '0';
		if(b == '7') return '1';
		if(b == '8') return '2';
		if(b == '9') return '3';
	}
	if(a == '5')
	{
		if(b == '5') return '0';
		if(b == '6') return '1';
		if(b == '7') return '2';
		if(b == '8') return '3';
		if(b == '9') return '4';
	}
	if(a == '6')
	{
		if(b == '6') return '2';
		if(b == '7') return '3';
		if(b == '8') return '4';
		if(b == '9') return '5';
	}
	if(a == '7')
	{
		if(b == '7') return '4';
		if(b == '8') return '5';
		if(b == '9') return '6';
	}
	if(a == '8')
	{
		if(b == '8') return '6';
		if(b == '9') return '7';
	}
	if(a == '9')
		if(b == '9') return '8';
}
string addstring(string str1, string str2)
{
	string sum;
	if(str1.length()<str2.length())
		str1.swap(str2);
	reverse(str1.begin(), str1.end());
	reverse(str2.begin(), str2.end());
	string zero;
	string::iterator ii;
	for(ii=str1.begin()+str2.length();ii!=str1.end();ii++)
	{
		str2 = str2+'0';
	}
	if(str1.length() != str2.length()) str2 = str2 +'0';
	//cout<<str1<<' '<<str2<<endl;
	char carry = '0', car1='0', car2='0';
	char add = '0';
	string::iterator jj = str2.begin();
	for(ii=str1.begin();ii!=str1.end();ii++)
	{
		/*if(carry == '1')
		{
			add = addchar(*(sum.end()-1), carry);
			carry = charcarry(*(sum.end()-1), carry);
			sum = sum.substr(0, sum.find(*sum.end()-1));
			sum = sum + add;
		}*/

		car1 = '0';
		car2 = '0';
		//cout<<"digits "<<*ii<<' '<<*jj<<"------ ";
		add = addchar(*ii, *jj);
		car1 = charcarry(*ii, *jj);

		if(carry == '1')
		{
			car2 = charcarry(add, carry);
			add = addchar(add, carry);
		}
		if(car1=='1'||car2=='1') carry = '1';
		else carry = '0';

		//cout<<add<<endl;
		sum = sum + add;
		//cout<<sum<<endl;
		jj++;
	}
	/*add = addchar(*(sum.end()-1), carry);
	carry = charcarry(*(sum.end()-1), carry);
	sum = sum.substr(0, sum.find(*sum.end()-1));
	sum = sum + add;
	sum = sum + carry;
	cout<<sum<<endl;*/
	if(carry == '1')sum = sum + carry;
	reverse(sum.begin(), sum.end());
	//cout<<sum<<endl;
	return sum;
}
//8888888888888888888888888888888888888

string addstringafter(string str1, string str2)
{
	string sum;
	if(str1.length()<str2.length())
		str1.swap(str2);
	string zero;
	string::iterator ii;
	for(ii=str1.begin()+str2.length();ii!=str1.end();ii++)
	{
		str2 = str2+'0';
	}
	if(str1.length() != str2.length()) str2 = str2 +'0';
	reverse(str1.begin(), str1.end());
	reverse(str2.begin(), str2.end());
	//cout<<str1<<' '<<str2<<endl;
	char carry = '0', car1='0', car2='0';
	char add = '0';
	string::iterator jj = str2.begin();
	for(ii=str1.begin();ii!=str1.end();ii++)
	{
		/*if(carry == '1')
		{
			add = addchar(*(sum.end()-1), carry);
			carry = charcarry(*(sum.end()-1), carry);
			sum = sum.substr(0, sum.find(*sum.end()-1));
			sum = sum + add;
		}*/

		car1 = '0';
		car2 = '0';
		//cout<<"digits "<<*ii<<' '<<*jj<<"------ ";
		add = addchar(*ii, *jj);
		car1 = charcarry(*ii, *jj);

		if(carry == '1')
		{
			car2 = charcarry(add, carry);
			add = addchar(add, carry);
		}
		if(car1=='1'||car2=='1') carry = '1';
		else carry = '0';

		//cout<<add<<endl;
		sum = sum + add;
		//cout<<sum<<endl;
		jj++;
	}
	/*add = addchar(*(sum.end()-1), carry);
	carry = charcarry(*(sum.end()-1), carry);
	sum = sum.substr(0, sum.find(*sum.end()-1));
	sum = sum + add;
	sum = sum + carry;
	cout<<sum<<endl;*/
	if(carry == '1')sum = sum + carry;
	reverse(sum.begin(), sum.end());
	//printf("------------");
	//cout<<sum<<endl;
	return sum;
}

int main()
{
	fstream inFile;
	inFile.open("input.txt");
	string str1, str2;
	getline(inFile, str1);
	getline(inFile, str2);
	inFile.close();
	printf("The given Numbers are -- \n");
	cout<<str1<<endl;
	cout<<str2<<endl;
	/*cout<<str2.find('.')<<endl;
	string::iterator i;
	for(i = str1.begin();i!=str1.end();i++)
		cout<<*i;
	cout<<endl;
	string sum;
	sum = str2+str1;//concatenation.....
	cout<<sum<<endl;*/

	string str1dot = str1.substr(str1.find(*str1.begin()),str1.find('.'));
	//cout<<str1dot<<endl;
	string str2dot = str2.substr(str2.find(*str2.begin()),str2.find('.'));
	//cout<<str2dot<<endl;

	string sum;
	string sum1 = addstring(str1dot, str2dot);
	bool flag1=false, flag2=false, flag=false;
	if(str1.find('.')==std::string::npos) flag1=true;
	if(str2.find('.')==std::string::npos) flag2=true;
	flag=flag1 & flag2;
	if(!flag && flag1) str1+=".0";
	if(!flag && flag2) str2+=".0";
	//cout<<sum1<<endl;

	if(!flag){
			string dotstr1 = str1.substr(str1.find('.')+1, str1.find(*str1.end()));
			//cout<<dotstr1<<endl;
			string dotstr2 = str2.substr(str2.find('.')+1, str2.find(*str2.end()));
			//cout<<dotstr2<<endl;

			string sum2 = addstringafter(dotstr1, dotstr2);
			//cout<<sum2<<endl;

			if(dotstr1.length() > dotstr2.length())
			{
				if(dotstr1.length() != sum2.length())
				{
					sum1 = addstring(sum1, "1");
					sum2 = sum2.substr(1, sum2.length()-1);
				}
			}
			else
			{
				if(dotstr2.length() != sum2.length())
				{
					sum1 = addstring(sum1, "1");
					sum2 = sum2.substr(1, sum2.length()-1);
				}
			}

			sum = sum1 + '.' + sum2;
	}else sum=sum1;


	printf("*** The final Sum is \n\n");
	cout<<sum<<endl;

	inFile.open("output.txt");
	inFile<<"The final sum is \n"<<endl;
	inFile<<sum<<endl;

}
