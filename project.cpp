#include<iostream>
using namespace std;
char arr[3][3] = {{'1','2','3'},{'4','5',6},{'7','8','9'}};
int row, column;
char token = 'x';
string nam1 ,nam2;
bool tie;
void funcstr() 
{
//creating structure

cout << "   |       |   " << endl;
cout << " "<< arr[0][0] << " |   "<< arr[0][1] << "   |"<< arr[0][2] << endl;
cout << "   |       |   " << endl;
cout << " __|_______|__ " << endl;
cout << "   |       |   " << endl;
cout << " " << arr[1][0] << " |  "<< arr[1][1] << "    |"<< arr[1][2] << endl;
cout << "   |       |   " << endl;
cout << " __|_______|__ " << endl;
cout << "   |       |   " << endl;
cout << " " << arr[2][0] << " |  "<< arr[2][1] << "    |"<< arr[2][2] << endl;
cout << "   |       |   " << endl;
cout << "   |       |   " << endl;
cout << endl;


}
void funclogic(){
    int digit;

    if(token == 'x'){
        cout << nam1 << " please enter your input" << endl;
        cin >> digit;
    }
      if(token == '0'){
        cout << nam2 << " please enter your input" << endl;
        cin >> digit;
    }
    if(digit==1){
        row = 0;
        column = 0;
    }
    if(digit==2){
        row = 0;
        column = 1;
    }
    if(digit==3){
        row = 0;
        column = 2;
    }
    if(digit==4){
        row = 1;
        column = 0;
    }
    if(digit==5){
        row = 1;
        column = 1;
    }
    if(digit==6){
        row = 1;
        column = 2;
    }
    if(digit== 7){
        row = 2;
        column = 0;
    }
    if(digit==8){
        row = 2;
        column = 1;
    }
    if(digit==9){
        row = 2;
        column = 2;
    }
    else if(digit <=0 || digit >=10){
        cout << "hupp budbak" << endl;
    }
    if(token=='x' && arr[row][column] !='x' && arr[row][column] !='0')
    {
        arr[row][column] = 'x';
        token='0';
    }
    else if(token=='0' && arr[row][column] !='x' && arr[row][column] !='0')
    {
        arr[row][column] = '0';
        token='x';
    }
    else{
        cout << "there is no empty space" << endl;
        funclogic();
    }
    // funcstr();
}

// match winn or draw

bool functhree(){
    //for vertica and horizontal check

    for(int i=0;i<3;i++){
        if(arr[i][0]==arr[i][1] && arr[i][0] == arr[i][2] || arr[0][i]==arr[1][i] && arr[0][i] == arr[2][i])
        return true;
    }
    if(arr[0][1] == arr[1][1] && arr[0][0] == arr[2][2] || arr[0][2]==arr[1][1] && arr[0][2] == arr[2][0]){
    return true;
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(arr[i][j] != 'x' && arr[i][j] != '0'){
                return false;
            }
        }
    }
    tie = true;
    return false;
}

int main()
{
cout << "enter the name of first player" << endl;
getline(cin,nam1);
cout << "enter the name of second player" << endl;
getline(cin,nam2);
cout << nam1 << " is first player orr he/she will play first" << endl;
cout << nam2 << " is second player orr he/she will play second" << endl;


while (!functhree())

{
    funcstr();
    funclogic();
    functhree();
}

if(token == 'x' && tie == false){
    cout << nam2 << " is winner" << endl;
}


else if(token=='0' && tie ==false){
    cout << nam1 << " is winner" << endl;
}


else {
    cout << "it's a draw" <<endl;
}

return 0;

}
