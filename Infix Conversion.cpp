#include <iostream>

using namespace std;

char charStack[20];
int top = -1;
int n = 20;

void push(char value){
   if(top==n-1){
        cout<<"Stack is full! overflow condition...."<<endl;
        cout<<"Empty out the stack first"<<endl;
   }
   else{
        top++;
        charStack[top]=value;
   }
}
void pop(){
   if(top==-1){
        cout<<"Stack is empty! underflow condition...."<<endl;
        cout<<"Fill the stack first"<<endl;
   }
   else{
        char temp = charStack[top];
        charStack[top]=0;
        top--;
   }
}
void convertPostfix(){
    string exp;
    cout<<"Enter an infix expression to convert"<<endl;
    cin>>exp;

    const char* charArr=exp.c_str();

    char resultant[exp.length()];
    int j=0;

    for(int i=0; i<exp.length(); i++){
        if(charArr[i]=='('||charArr[i]=='{'||charArr[i]=='['){
            push(charArr[i]);
        }
        else if(charArr[i]=='*'||charArr[i]=='/'||charArr[i]=='+'||charArr[i]=='-'||charArr[i]=='^'){
            if(top==-1)
                push(charArr[i]);
            else{
                if(charArr[i]=='+'||charArr[i]=='-'){
                    while(charStack[top]=='*'||charStack[top]=='/'||charStack[top]=='^'||charStack[top]=='+'||charStack[top]=='-'){
                        resultant[j]=charStack[top];
                        j++;
                        pop();
                    }
                    push(charArr[i]);
                }
                else if((charArr[i]=='*'||charArr[i]=='/'||charArr[i]=='^')& (charStack[top]=='/'||charStack[top]=='*'||charStack[top]=='^')){
                    while(charStack[top]=='/'||charStack[top]=='*'||charStack[top]=='^'){
                        resultant[j]=charStack[top];
                        j++;
                        pop();
                    }
                    push(charArr[i]);
                }
                else{
                    push(charArr[i]);
                }
            }
        }
        else if(charArr[i]==')'||charArr[i]=='}'||charArr[i]==']'){

            while(charStack[top]!='('&charStack[top]!='{'&charStack[top]!='['){
                 resultant[j]=charStack[top];
                 j++;
                 pop();
            }
            pop();
        }
        else{
            resultant[j]=charArr[i];
            j++;
        }
    }

    while(top!=-1){
       resultant[j]=charStack[top];
       j++;
       pop();
    }

    int i=0;
    while(resultant[i]!='\0'){
        cout<<resultant[i];
        i++;
    }
    cout<<endl;
}

void convertPrefix(){
    string exp;
    cout<<"Enter an infix expression to convert"<<endl;
    cin>>exp;

    const char* charArr=exp.c_str();

    char resultant[exp.length()];
    int j=0;

    for(int i=exp.length()-1; i>=0; i--){
        if(charArr[i]==')'||charArr[i]=='}'||charArr[i]==']'){
            push(charArr[i]);
        }
        else if(charArr[i]=='*'||charArr[i]=='/'||charArr[i]=='+'||charArr[i]=='-'||charArr[i]=='^'){
            if(top==-1)
                push(charArr[i]);
            else{
                if(charArr[i]=='+'||charArr[i]=='-'){
                    while(charStack[top]=='*'||charStack[top]=='/'||charStack[top]=='^'){
                        resultant[j]=charStack[top];
                        j++;
                        pop();
                    }
                    push(charArr[i]);
                }
                else{
                    push(charArr[i]);
                }
            }
        }
        else if(charArr[i]=='('||charArr[i]=='{'||charArr[i]=='['){

            while(charStack[top]!=')'&charStack[top]!='}'&charStack[top]!=']'){
                 resultant[j]=charStack[top];
                 j++;
                 pop();
            }
            pop();
        }
        else{
            resultant[j]=charArr[i];
            j++;
        }
    }

    while(top!=-1){
       resultant[j]=charStack[top];
       j++;
       pop();
    }

    for(int i=j-1; i>=0; i--){
        cout<<resultant[i];
    }
    cout<<endl;
}
int main()
{
    convertPrefix();
    convertPostfix();


}
