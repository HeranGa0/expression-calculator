#include<iostream>
#include<vector>

#include<String>
#include"cal.h"
#include<stdio.h>

using namespace std;
using namespace std;
int charTint(int calnum,vector<char>::const_iterator &iter)
{
    int left=0;int power=1;
    for(int inm=1;inm<=calnum-1;inm++)
    {
        power=power*10;
    }
    for(int ins=1;ins<=calnum;ins++,iter++,power=power/10)
    {
            left+=((*iter)-'0')*power;
        }
    return left;
}

int getlen(char *result,vector<char> &b,vector<char>::const_iterator &a)
{
    int i=0;
    while((result[i])!=('\0')){
        b.insert(a+1+i,result[i]);

        i++;


    }

    return 0;

}
int result(vector<char> &b)
{   int result;
while(1)
{vector<char>::const_iterator a=b.cbegin();

bool ifExistKuo=false;

    while(a!=b.cend())
    {
        if((*a)=='('){ifExistKuo=true;break;}
        a++;
    }
    if(true==ifExistKuo)
    {
        a=b.cbegin();
        while((*a)!=')')
        {
            a++;
        }
        vector<char>::const_iterator firstRightKuo=a;
        while((*a)!='(')
        {
            a--;
        }
        vector<char>::const_iterator firstLeftKuo=a;
        bool ifExistM_or_D=false;

        while(a!=firstRightKuo)
        {
                  if((*a)=='*'||(*a)=='/')
                  {
                      ifExistM_or_D=true;
                      break;
                  }

                  a++;
        }

        if(ifExistM_or_D==true)
        {  vector<char>::const_iterator firstLeftKuo2=a;



            int numcaleft=0;int numcaright=0;
        bool judgePOrM=true;
        if('/'==(*firstLeftKuo2)){ judgePOrM=false;}
             vector<char>::const_iterator firstP_or_M=firstLeftKuo2;
             vector<char>::const_iterator firstPMposition=firstLeftKuo2;
             while((firstLeftKuo2!=firstLeftKuo)&&(*firstLeftKuo2!='+')&&(*firstLeftKuo2!='-'))
             {
                 firstLeftKuo2--;numcaleft++;
             }

             vector<char>::const_iterator subintl=firstLeftKuo2;
             vector<char>::const_iterator leftSymbo=firstLeftKuo2;
             subintl++;
             firstP_or_M++;
             while((*firstP_or_M!=')')&&(*firstP_or_M!='+')&&(*firstP_or_M!='-')&&(*firstP_or_M!='*')&&(*firstP_or_M!='/'))
             {
                 numcaright++;
                 firstP_or_M++;
             }
              vector<char>::const_iterator rightSymbo=firstP_or_M;


              numcaleft--;
            int leftnumber= charTint(numcaleft,subintl);

            firstPMposition++;
            int rightnumber=charTint(numcaright,firstPMposition);

            int sum;
            if(true==judgePOrM){ sum=leftnumber*rightnumber;}
            if(false==judgePOrM){sum=leftnumber/rightnumber;}
            cout<<sum<<endl;


            char string[10];
            sprintf(string, "%d", sum);

            b.erase((leftSymbo+1),(rightSymbo));

            getlen(string,b,leftSymbo);






        }
        if(false==ifExistM_or_D)
        {    vector<char>::const_iterator firstLeftKuo2=firstLeftKuo;
        bool ifExistPOrM=false;
        while(firstLeftKuo2!=firstRightKuo)
        {
                  if((*firstLeftKuo2)=='+'||(*firstLeftKuo2)=='-')
                  {
                      ifExistPOrM=true;
                      break;
                  }

                  firstLeftKuo2++;
        }
        if(true==ifExistPOrM)
        {
            int numcaleft=0;int numcaright=0;
        bool judgePOrM=true;
        if('-'==(*firstLeftKuo2)){ judgePOrM=false;}
             vector<char>::const_iterator firstP_or_M=firstLeftKuo2;
             vector<char>::const_iterator firstPMposition=firstLeftKuo2;
             while((firstLeftKuo2!=firstLeftKuo))
             {
                 firstLeftKuo2--;numcaleft++;
             }

             vector<char>::const_iterator subintl=firstLeftKuo2;
             vector<char>::const_iterator leftSymbo=firstLeftKuo2;
             subintl++;//function canshu
             //NOTICE!
             firstP_or_M++;
             while((*firstP_or_M!=')')&&(*firstP_or_M!='+')&&(*firstP_or_M!='-'))
             {
                 numcaright++;
                 firstP_or_M++;
             }
              vector<char>::const_iterator rightSymbo=firstP_or_M;


              numcaleft--;
            int leftnumber= charTint(numcaleft,subintl);

            firstPMposition++;
            int rightnumber=charTint(numcaright,firstPMposition);

            int sum;
            if(true==judgePOrM){ sum=leftnumber+rightnumber;}
            if(false==judgePOrM){sum=leftnumber-rightnumber;}

            char string[10];
            sprintf(string, "%d", sum);

            b.erase((leftSymbo+1),(rightSymbo));

            getlen(string,b,leftSymbo);


        }

        if(false==ifExistPOrM)
        {
            vector<char>::const_iterator ElfirstLeftKuo=firstLeftKuo;
            vector<char>::const_iterator ElfirstLeftKuo2=firstLeftKuo;
            while((*ElfirstLeftKuo)!=')')
            {
                ElfirstLeftKuo++;
            }

            b.erase(ElfirstLeftKuo);
            b.erase(ElfirstLeftKuo2);

        }

        }

    }
    if(false==ifExistKuo)
{
    break;
}

}

int calm=b.size();
vector<char>::const_iterator Fb=b.cbegin();



    result=charTint(calm,Fb);

    return result;
}
int calculate(QString convey)
{

    string input=convey.toStdString();



    string get=input;
    char* string=(char*)get.data();
    vector<char> real;
    while((*string)!='\0')
    {
        real.push_back(*string);
        string++;
    }
    int haha=result(real);
    return haha;
}
