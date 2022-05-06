
#include <bits/stdc++.h>

using namespace std;



struct Process{

    int id,bt,pr,wt, en;

};

bool comp (Process a, Process b)
{
    return a.pr < b.pr;
}


void getWaitingTime ( struct Process arr[], int sz ) // to calculate waiting time to each process
{

    arr[0].wt = 0;
    arr[0].en = arr[0].pr;
    int t =0;
    for (int i=1 ; i<sz ; ++i)
    {
        t+=arr[i-1].bt;
        arr[i].wt = t;
        arr[i].en = arr[i].wt + arr[i].bt;

    }


}


void input(Process arr[], int num){

    for (int i = 0; i < num; ++i) {
        cout<<"(P"<<i+1<<")" << endl;
        arr[i].id=i+1;
        cout << " Burst time = ";
        cin>>arr[i].bt;
        cout <<  " Priority = ";
        cin >>arr[i].pr;
        cout << endl;

    }

}


void output (struct Process arr[], int sz )
{
    for (int i=0 ; i<80 ; ++i) cout << "*";
    cout << endl << "\a";


    cout << "|     Process\t   Burst Time\tPriority Time\tWaiting Time \t\t       |"<<endl;

    for (int i=0 ; i<sz ; ++i)
    {

        cout  <<"|       P" << arr[i].id << "\t\t"<<arr[i].bt << "\t\t"<< arr[i].pr <<"\t\t" << arr[i].wt  << "\t\t       |"<< endl;
    }

    for (int i=0 ; i<80 ; ++i) cout << "*";
    cout << endl << endl;


    // ----------- Gantt Chart ------------ //

    cout << "Gantt Chart" << endl;

    cout << endl;

    for (int i=0 ; i<sz ; ++i)
    {

        for (int j=0 ; j<arr[i].bt*3 ; ++j)
        {

            if (j == arr[i].bt) cout << "p" << arr[i].id;
            else
                cout << " ";
        }

    }

    cout << endl<< 0;
    for (int i=0 ; i<sz ; ++i)
    {
        int deg=0, t=arr[i+1].wt;
        while (t>0)
        {
            deg++;
            t/=10;
        }

        for (int j=0 ; j<arr[i].bt *3- deg/2 ; ++j) cout << " ";
        cout << arr[i].en;
    }
    cout << endl<< endl ;

//   ----- Calculate Average Time -----   //
    cout <<" Average Time " <<endl << endl;
    double sum =0;
    cout << "   ";
    for (int i=0 ; i<sz ; ++i)
    {
        sum += arr[i].wt;
        cout << " "<< arr[i].wt;
        if (i!=sz-1) cout << " +";
    }
    cout << endl << " ";
    for (int i=0; i<sz*3+5 ; ++i) cout << '_';

    cout  <<  "  = " << sum / sz <<endl;

    for (int i=0 ; i<sz*1.5 ; ++i) cout<< " ";
    cout << sz << endl << endl;




}


int main()
{
    Process *arr;
    int nums;
    cout<<"Enter number of Processes:  ";
    cin>>nums;


    arr=new Process[nums];

    input(arr , nums);
    sort (arr, arr+nums, comp );
    getWaitingTime(arr, nums);
    output(arr, nums);

    delete []arr;


    return 0;
}
