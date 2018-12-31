#include<iostream>
#include<stdlib.h>  
#include<vector>
#include<stack>
#include<fstream>

using namespace std;

int main()
{
	int i=3,j=6,k=12;
	cout<<"i=="<<i<<",j=="<<j<<",k=="<<k<<endl;
	i+=2;
	{
		cout<<"i=="<<i<<",j=="<<j<<",k=="<<k<<endl;
		int i=9;
		i++;
		cout<<"i=="<<i<<",j=="<<j<<",k=="<<k<<endl;
		{
            int k=1;		
          cout<<"i=="<<i<<",j=="<<j<<",k=="<<k<<endl;
		  k++;
		}
		k++;
		cout<<"i=="<<i<<",j=="<<j<<",k=="<<k<<endl;
		j+=2;
	}	
	cout<<"i=="<<i<<",j=="<<j<<",k=="<<k<<endl;
    system("pause");
	return 0;
}
