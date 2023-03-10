#include <bits/stdc++.h>
using namespace std;
string listOfPatientsNames[101];
bool listOfPatientsStatus[101];
int listOfSpecializations[20];
void startingPage();
int getCurrentPatient(int specialization);
void add(string name,bool status,int specialization);
void addRegular(string name,int specialization);
void addUrgent(string name,int specialization);
void addNewPatient();
void printStatus(bool x);
void printAllPatients(int specialization);
bool chooseTheOrder();
void GetNextPatient(int specialization);

int main(){
    bool work=1;
    while(work){
        startingPage();
        work=chooseTheOrder();
    }
}

void startingPage(){
        cout<<"1) Add new Patient\n"
        <<"2) Print all patients\n"
        <<"3) Get next patient\n"
        <<"4) Exit\n";
}
bool chooseTheOrder(){
    cout<<"input you choice: ";
    int choice;
    cin>>choice;
    switch (choice) {
        case 1:{
            addNewPatient();
            break;
        }
        case 2:{
            cout<<"Input specialization of the Patients you want to print:  ";
            int s;
            cin>>s;
            printAllPatients(s);
            break;
        }
        case 3:{
            cout<<"Input specialization of the patient: ";
            int s;
            cin>>s;
            GetNextPatient(s);
            break;
        }
        case 4:{
            cout<<"---------- The system stopped successfully ----------";
            return false;
        }
        default:{
            cout<<"\n---------- inValid choice Please try again ----------\n";
        }
    }
    return true;
}
int getCurrentPatient(int specialization){
    return listOfSpecializations[specialization]+((specialization-1)*5);;
}
void GetNextPatient(int specialization){
    int current= ((specialization-1)*5)+1;
    bool isEmpty=(listOfSpecializations[specialization]==0);
    if(isEmpty){
        cout<<"---------- Sorry ,there are no patients on this specialization ----------\n";
    }
    string name=listOfPatientsNames[current];
    bool status=listOfPatientsStatus[current];
    listOfSpecializations[specialization]--;
    cout<<"-- "<<name<<' ';printStatus(status);cout<<" --"<<'\n';
}

void addUrgent(string name,int specialization){
    listOfSpecializations[specialization]++;
    int endOfListOfSpecialization= getCurrentPatient(specialization);
    int startOfTheList=((specialization-1)*5)+1;
    for(int i=endOfListOfSpecialization;i>startOfTheList;i--){
        listOfPatientsStatus[i]=listOfPatientsStatus[i-1];
        listOfPatientsNames[i]=listOfPatientsNames[i-1];
    }
    listOfPatientsNames[startOfTheList]=name;
    listOfPatientsStatus[startOfTheList]= true;
}
void addRegular(string name,int specialization){
    listOfSpecializations[specialization]++;
    bool status= false;
    int CurrentPatient= getCurrentPatient(specialization);
    listOfPatientsNames[CurrentPatient]=name;
    listOfPatientsStatus[CurrentPatient]=status;
}
void add(string name,bool status,int specialization){

    if(status==1)
    {
        addUrgent(name,specialization);
    }
    else {
        addRegular(name,specialization);
    }
}
void addNewPatient() {
    int specialization;
    string name;bool status;
    cout<<"Input specialization ,name and status(1:Urgent,0:Regular) :- \n";
    cin>>specialization>>name>>status;
    bool isFull=(listOfSpecializations[specialization]==5);
    if(isFull) {
        cout << "---------- Sorry, Specialization " << specialization << " have the maximum number of people ---------- ";
        return;
    }
    add(name,status,specialization);
}
void printStatus(bool x){
    if(x){
        cout<<"Urgent";
    }
    else{
        cout<<"Regular";
    }
}
void printAllPatients(int specialization){
    int endOfListOfSpecialization= getCurrentPatient(specialization);
    int startOfTheList=((specialization-1)*5)+1;
    bool isEmpty=((listOfSpecializations[specialization])==0);
    if(isEmpty){
        cout<<"Sorry , specialization "<<specialization<<" have no waiting list\n";
        return;
    }
    cout<<"---------- there are "<<listOfSpecializations[specialization]<<" on specialization ----------"<<specialization<<'\n';
    for(int i=startOfTheList;i<=endOfListOfSpecialization;i++){
        cout<<"- "<<listOfPatientsNames[i]<<' ';
        printStatus(listOfPatientsStatus[i]);
        cout<<'\n';
    }
}
