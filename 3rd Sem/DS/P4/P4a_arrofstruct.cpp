#include<bits/stdc++.h>
using namespace std;

struct mobile{
    int id;
    string name;
    int cost;
};
                                
int main()                        
{
    int n, ch, f = 0, i=0, id, r1, r2;
    char res;
    cout << "Enter number of mobiles to enter : ";
    cin >> n;
    struct mobile m[n];
   while(f == 0){
        cout << "1.Add mobile \n2.Display database \n3.Search \n4.Display with salary filter \n5.Exit" << endl;
        cout << "Enter your choice" << endl;
        cin >> ch;
        switch(ch){
            case 1:
                cout << "Enter mobile id, name and cost" << endl;
                cin >> m[i].id >> m[i].name >> m[i].cost;
                i++;
            break;
            case 2:
                for(int j=0; j<i; j++){
                    cout << m[j].id << " " << m[j].name << " " << m[j].cost << endl << endl;
                }
            break;
            case 3:
                cout << "Enter mobile id : ";
                cin >> id;
                for(int j=0; j<i; j++){
                    if(id == m[j].id){
                        cout << m[j].id << " " << m[j].name << " " << m[j].cost << endl << endl;
                    }
                }                   
            break;                      
            case 4:
                cout << "Enter price range : ";
                cin >> r1; cout << "to" << endl; cin >> r2;
                cout << endl;
                for(int j=0; j<i; j++){
                    if(r1 <= m[j].cost && m[j].cost <= r2){
                        cout << "id: " << m[j].id << " name: " << m[j].name << " cost: " << m[j].cost << endl << endl;
                    }
                }
            break;
            default:
                f = 1;
        }
        cout << endl;
    }
    return 0;
}


