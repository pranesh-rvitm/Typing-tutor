#include <iostream>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<stdio.h>
#include<process.h>
#include <windows.h>
#include<unistd.h>
#include<fstream>
#include <string>
#include <string.h>

using namespace std;
/* The following function called sentence is used to find the accuracy of typing sentences .
The accuracy is calculated by considering  the number of mistakes and the  letters missed in the sentence*/
void sentence()
{

    cout<<"\n\n\n\t\t\t INSTRUCTIONS ";
    cout<<"\n\t\t\t============";
    cout<<"\n\t ->type the sentences you see on the screen. ";
    Sleep(1);
    char choice;
    cout<<"\n\nDo you want to start?(y/n)\n";
    cin>>choice;
    int nol;
    if(choice=='y'||choice=='Y')
    {
        Sleep(1);
        cout<<"\n";
        srand(getpid());
        string line,input;
        int siz,wrong,mis=0;
        ifstream file ("sample.txt");//connecting the file and the program
        cout<<"How many lines do you want to type \n";
        cin>>nol;


        int ran=(1+(rand()%(10-nol)));
        if (file.is_open())// checking if the file is open
        {
            for (int lineno = 1; getline (file,line) ; lineno++)//cursing through every line in the sentence
                if (lineno >=ran&&lineno<ran+nol)//condition to use a random line from the file
                {

                    cout << line<<"\n" ;//printing the line obtained from the file
                    srand(time(NULL));
                    getline (cin,input);// getting the line entered by the user to calculate accuaracy
                    while (input.length()==0 )
                        getline(cin, input);
                    siz+=line.size();//calculating the total number of letters in the sentence obtained from the file
                    for(int i=0; i<input.size(); i++)
                    {
                        mis++;
                        if(input[i]!='\0'&&line[i]!='\0')//comparing each letter in the sentence and the input
                        {
                            if(line.at(i)!=input.at(i))//counting the number of wrong letters entered by user
                            {
                                wrong++;
                            }
                        }
                    }
                    cout<<"\n";
                }
            if((siz-mis)!=0)//checking if user has missed any letters
                cout<<"You have missed "<<(siz-mis-2)<<" letters \n"; //printing the missed leters
            cout<<"You have made "<<wrong<< "  mistakes \n";//printing the number of mistakes made by the user
            float acc=(float)(mis-wrong)/(siz-2)*100.0;//calculating the accuracy of the typing
            cout<<"Accuracy is "<<acc<<"% \n";
            file.close(); // closing the file
        }
        else cout << "Can not open the file";


    }
    else if(choice!='y'&&choice!='y'&&choice!='n'&&choice!='N')//checking for wrong input as choice
    {
        cout<<"Wrong Input";
    }
}





void alphabet()
{
    rand();
    char choice;
    int num;
    int score=0,wrong=0,randnum;
    char letter,key;
    cout<<"\n\n\n\t\t\t INSTRUCTIONS ";
    cout<<"\n\t\t\t============";
    cout<<"\n\t1 ->type the letters you see on the screen. ";
    Sleep(1);
    cout<<"\n\nDo you want to start?(y/n)";
    choice=getch();
    if(choice=='y'||choice=='Y')
    {
        Sleep(1);
        cout<<"\n\n3.for every wrong answer you will hear this Beep";
        Beep(600,900);
        Beep(1000,800);
        Sleep(1);

    }
    cout<<"\n\nPress enter any key when you are ready.";

    int number;
    float acc=0.0;
    cout<<"\n\nWhat should be the max score:";
    cin>>number;
    for(int i=0; i<number; i++)
    {
        randnum=rand()%25;
        for(int j=0; j<randnum; j++)
            cout<<"\n";
        srand(time(NULL));
        for(int j=0; j<randnum; j++)
            cout<<"\t";
        int temp=((rand()%2)==0)?65:97;
        num=temp+(rand()%25);
        letter=(char)num;
        cout<<letter;
        cin>>key;
        if(key==letter)
        {
            score++;
        }
        else
        {
            Beep(600,800);
            Beep(1000,800);
            Sleep(1);
            wrong++;
        }
    }
    cout<<"\n\n\nYour total score is "<<score;
    cout<<"\n\n\n wrong answers are"<<wrong;
    acc=(score*100.0)/number;
    cout<<"\n\n\n your accuracy is "<<acc<<"%";
    // getch();
}


int main()
{

    cout<<"\t\t\twelcome to the typing tutor\n\n" ;
    cout<<"\t\t\t\tWELCOME";
    Sleep(1);
    int opt;

    cout<<"\n\n\t\t=====TEST YOUR ACCURACY AND SPEED HERE=====";
menu:
    cout<<"\n\n\n\t\t--:: INDEX ::--";
    cout<<"\n\n\t\t1.GAME OF LETTERS";
    cout<<"\n\n\t\t2.PRACTICE TYPING SENTENCES";
    cout<<"\n\n\t\t0.EXIT";
    cout<<"\n\n\n\t\tEnter your choice : ";
    cin>>opt;  //getting the user's choice
    switch(opt)
    {
    case 1:
        alphabet();//calling function alphabet
        Sleep(2000);//delaying function to pause for 2000 milliseconds
        goto menu;
        break;
    case 2:
        sentence();//calling function sentence
        Sleep(2000);//delaying function to pause for 2000 milliseconds
        goto menu;
    case 0:
        cout<<"\n\n\t\t !!!!!THANK YOU!!!!! \n\n";
        exit(0);
    default:
        cout<<" \n\n !!!! Wrong Input Try again  !!!!\n\n";
        goto menu;
    }
}
