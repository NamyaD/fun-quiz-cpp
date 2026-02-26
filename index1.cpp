#include<iostream>
using namespace std;
int main(){
    string name;
    cout<<"Enter your username: ";
    cin>>name;
    int age;
    cout<<"Enter your age(dont worry, we wont tell anyone): ";
    cin>>age;
    if(age >= 18){
    	cout<<"Age:"<<age<<endl;
        string password;
        string confirm_password;
        cout<<"Enter your password(its not 1234, hopefully): ";
        cin>>password;
        int i;
        for(i=1;i<=3;i++){   
            cout<<"Confirm your password(it should be same as your password entered): ";
            cin>>confirm_password;
            if(password == confirm_password){
                cout<<"Password Match"<<endl;
                break;}
            else{
                cout<<"Password do not match"<<endl;}}
        if(i == 4){
            cout<<"Access Denied. The quiz was not even started yet ,it was just passwords."<<endl;}
        else{
            string terms;
            cout<<"Do you accept Terms & Conditions or should we say you have to? (Y/N): "<<endl;
             cout<<"Term 1: By entering this quiz, you confirm that you have at least 2 brain cells working today."<<endl;
              cout<<"Term 2:If you fail, please do not blame the keyboard, mouse, or your childhood. "<<endl;
               cout<<"Term 3:If you score full marks, you are officially Sharma Ji ka beta/beti. "<<endl;
                cout<<"Term 4:You cannot use chatgpt."<<endl;
                cout<<"Term 5:If you score zero, we will pretend we dont know you."<<endl;
                cout<<"Term 6:If you guess and get it right, act natural."<<endl;
                
            cin>>terms;
            if(terms=="Y"|| terms=="yes"|| terms=="y"|| terms=="Yes"|| terms=="YES"){
                cout<<"Login Successful. Atleast, you remembered your password."<<endl;
                cout<<"Quiz is started. All the best!!"<<endl;
                cout<<"First question. Think before you answer:"<<endl;
   int answer;
   int score=0;
   cout<<"Q1:What is the capital of India?"<<endl;
   cout<<"1.Delhi"<<endl;
   cout<<"2.Solan"<<endl;
   cout<<"3.Mumbai"<<endl;
   cout<<"4.Shimla"<<endl;
   int j;
   for(j=1;j<=3;j++){
   cin>>answer;
   if(answer==1){
   	cout<<"Very good your answer is Correct:"<<answer<<endl;
     cout<<"Proudly Indian"<<endl;
     if(j==1){    
   	score++;}
	   break;}
   else{
   	cout<<"Wrong Answer. Try again."<<endl;
   	cout<<"Are you even an indian citizen?"<<endl;
   }}
   if(j== 4){
    cout<<"Moving to next question..."<<endl;}
   cout<<"Second question"<<endl;
   cout<<"Q2What is the capital of America?"<<endl;
   cout<<"1.Washington D.C."<<endl;
   cout<<"2.New york"<<endl;
   cout<<"3.Houston"<<endl;
   cout<<"4.San Diego"<<endl;
    int k;
   for(k=1;k<=3;k++){
   cin>>answer;
   if(answer==1){
   	cout<<"Correct Answer! Even we are surprised.:"<<answer<<endl;
   	     if(k==1){      
            score++;}
	   break;}
   else{
   	cout<<"Wrong Answer.It happens, to you.Try again"<<endl;
   }}
   if(k== 4){
   cout<<"Moving to next question..."<<endl;}
   cout<<"Third Question"<<endl;
   cout<<"Q3What is the capital of germany?"<<endl;
   cout<<"1.Hamburg"<<endl;
   cout<<"2.Berlin"<<endl;
   cout<<"3.Frankfurt"<<endl;
   cout<<"4.Cologne"<<endl;
   int m;
   for(m=1;m<=3;m++){
   cin>>answer;
   if(answer==2){
   	cout<<"Correct answer. Sharma ji is proud:"<<answer<<endl;
   	if(m==1){    
     score++;}
	   break;}
      else{
   	cout<<"Wrong Answer.The question deserved better."<<endl;
   }}
    if(m== 4){
    cout<<"Nice attempt."<<endl;}
   cout<<"Quiz is over.Congratulations, your score is displayed on the screen"<<endl;
   cout<<"Result:"<<score<<endl;}
   else{
                cout<<"You must accept Terms & Conditions."<<endl;
            }}}
    else{
        cout<<"Invalid Age"<<endl;}
   	return 0;}