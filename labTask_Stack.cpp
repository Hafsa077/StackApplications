       #include <iostream>
       #include<cmath>
       #include<string>

       using namespace std;

       struct stack1{
           int stackArr[10];
           int top;
           char stackChar[10];
       }s;

       int n=10;
       void pushChar(char value){
           if(s.top==n-1){
                cout<<"Stack is full! overflow condition...."<<endl;
                cout<<"Empty out stack first"<<endl;
           }
           else{
                s.top++;
                s.stackChar[s.top]=value;
           }
       }
       void popChar(){
           if(s.top==-1){
                cout<<"Stack is empty! underflow condition...."<<endl;
                cout<<"Fill the stack first"<<endl;
           }
           else{
                char temp = s.stackChar[s.top];
                s.stackChar[s.top]=0;
                s.top--;
           }
       }
       void push(int value){
           if(s.top==n-1){
                cout<<"Stack is full! overflow condition...."<<endl;
                cout<<"Empty out stack first"<<endl;
           }
           else{
                s.top++;
                s.stackArr[s.top]=value;
           }
       }
       void pop(){
           if(s.top==-1){
                cout<<"Stack is empty! underflow condition...."<<endl;
                cout<<"Fill the stack first"<<endl;
           }
           else{
                int temp = s.stackArr[s.top];
                s.stackArr[s.top]=0;
                s.top--;
           }
       }

       void display(){
           if(s.top==-1){
                cout<<"Stack is Empty!"<<endl;
           }
           for(int i=0; i<=s.top; i++){
                cout<<s.stackArr[i]<<" ";
           }
           cout<<endl;
       }
       void conversion(){
           int val,num;
           cout<<"For decimal to binary press 1"<<endl;
           cout<<"For binary to decimal press 0"<<endl;
           cin>>val;

           s.top=-1;
           if(val==1){
                cout<<"Enter a decimal number: ";
                cin>>num;
                while(num>0){
                        push(num%2);
                        num=num/2;
                }

                cout<<"The required binary number is: ";
                for(int i=s.top;i>=0;i--){
                    cout<<s.stackArr[i];
                    pop();

                }
                cout<<endl;
           }
           else{
               cout<<"Enter a binary number: ";
                cin>>num;
                int i=0;
                while(num>0){
                    push((num%10)*pow(2,i));
                    i++;
                    num=num/10;
                }
                int sum=0;
                for(int i=s.top; i>=0; i--){
                    sum=sum+s.stackArr[i];
                    pop();
                }
                cout<<"The required decimal number is: "<<sum<<endl;
           }
       }

       void balancedS(){
           s.top=-1;
           string str;
           cout<<"Enter an equation to check: ";
           cin>>str;
           const char* arr=str.c_str();
           for(int i=0;i<str.length();i++){
                if(arr[i]=='('||arr[i]=='{'||arr[i]=='['){
                    pushChar(arr[i]);
                }
                else if(arr[i]==')'||arr[i]=='}'||arr[i]==']'){
                    if(s.top==-1){
                        cout<<"The equation is not balanced"<<endl;
                        break;
                    }
                    else{
                        if(arr[i]==')'&&s.stackChar[s.top]!='('){
                            cout<<"The equation is unbalanced"<<endl;
                            break;
                        }
                        else if(arr[i]=='}'&&s.stackChar[s.top]!='{'){
                            cout<<"The equation is unbalanced"<<endl;
                            break;
                        }
                        else if(arr[i]==')]'&&s.stackChar[s.top]!='(['){
                            cout<<"The equation is unbalanced"<<endl;
                            break;
                        }
                    popChar();
                    }
                }
           }
           if(s.top==-1){
                cout<<"The equation is balanced"<<endl;
           }
       }

       int main(){
           s.top=-1;
           int value;
           cout<<"....Menu...."<<endl;
           cout<<"Push    = 0"<<endl;
           cout<<"Pop     = 1"<<endl;
           cout<<"Display = 2"<<endl;
           cout<<"Convert = 3"<<endl;
           cout<<"Checking for balanced symbol = 4"<<endl;

           while(true){
            cout<<"Enter any of the above mentioned values to perform a function: ";
            cin>>value;
            switch(value){
            case 0:
                cout<< "Enter a value to push on the stack = ";
                cin>>value;
                push(value);
                break;

            case 1:
                pop();
                break;

            case 2:
                display();
                break;

            case 3:
                conversion();
                break;

            case 4:
                balancedS();
                break;
            }

            cout<<"Press 1 to continue and 0 to stop"<<endl;
            cin>>value;
            if(value==0)
                break;
            else
                continue;
           }
       }
