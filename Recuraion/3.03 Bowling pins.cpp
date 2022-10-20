#include <bits/stdc++.h>
using namespace std;
map<pair<string, int>, int> winners;
//0 mine
//1 opponent
int winner(char pin[], int n, int turn){
	if (winners[pair<string,int>(string(pin), turn)]){
		return winners[pair<string,int>(string(pin), turn)];
	}
	if (winners[pair<string,int>(string(pin), ((turn==1)?2:1))]){
		return ((winners[pair<string,int>(string(pin), ((turn==1)?2:1))]==1)?2:1);
	}

    int flag=0;
    for (int i=0;i<n;i++){
        if (pin[i]=='I'){
            flag=1;
         	break;   
        }    
    }
    if (!flag){
        return ((turn==1)?2:1);
    }
    
    for (int i=0;i<n;i++){
        int temp = 0;
        if (pin[i]=='I'){
            pin[i]='X';
            temp = winner(pin, n, ((turn==1)?2:1));
            if (temp==turn){
            	
            	pin[i]='I';
            	winners[pair<string,int>(string(pin), turn)] = temp;
                return temp;
            }
            pin[i]='I';
        }
        
        temp=0;
        if (i<(n-1)){
            if ((pin[i]=='I')&&(pin[i+1]=='I')){
                pin[i]='X';
                pin[i+1]='X';
                temp = winner(pin, n, ((turn==1)?2:1));
                if (temp==turn){
                	
                	pin[i]='I';
                	pin[i+1]='I';
                	winners[pair<string,int>(string(pin), turn)] = temp;
                    return temp;
                }
                pin[i]='I';
                pin[i+1]='I';
            }
        }
    }
    winners[pair<string,int>(string(pin), turn)] = ((turn==1)?2:1);
    return ((turn==1)?2:1);
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int q;
    cin>>q;
    for (int i=0;i<q;i++){
        int n;
        cin>>n;
        char pin[n];
        for (int j=0;j<n;j++){
            cin>>pin[j];
        }
        int a;
        if (winners[pair<string,int>(string(pin), 1)]){
			a = winners[pair<string,int>(string(pin), 1)];
		}
		else if (winners[pair<string,int>(string(pin), 2)]){
			a = ((winners[pair<string,int>(string(pin), 2)]==1)?2:1);
		}
		else
        	a = winner(pin, n, 1);
        if (a==1){
            cout<<"WIN"<<endl;
        }
        else{
            cout<<"LOSE"<<endl;
        }
    }
    return 0;
}
