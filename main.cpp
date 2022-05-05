
#include <bits/stdc++.h>

using namespace std;



struct Process{

    int id,bt,pr,wt;
    int ar;

};

bool comp (Process a, Process b)
{
    return a.pr < b.pr;
}

void getWaitingTime ( struct Process arr[], int sz ) // to calculate waiting time to each process
{

  arr[0].wt = 0;
  int t =0;
  for (int i=1 ; i<sz ; ++i)
  {
      t+=arr[i-1].bt;
      arr[i].wt = t;

  }


}


void input(Process arr[], int num){

    cout<<"Processes\t Burst time \t Priority \t Arrival time\n";
    for (int i = 0; i < num; ++i) {
        cout<<"P"<<i+1;
        arr[i].id=i+1;
        cin>>arr[i].bt>>arr[i].pr>>arr[i].ar;

    }
    cout<<"----------------------------------------------------------------------\n";
}


void output (Process arr[], int sz )
{
   for (int i=0 ; i<80 ; ++i) cout << "*";
   cout << endl << "\a";

   cout << "|     Process\t   Burst Time\tPriority Time\tWaiting Time \t\t       |"<<endl;

   for (int i=0 ; i<sz ; ++i)
   {
       cout << "|       P" << arr[i].id << "\t\t"<<arr[i].bt << "\t\t"<< arr[i].pr <<"\t\t" << arr[i].wt  << "\t\t       |"<< endl;
   }

for (int i=0 ; i<80 ; ++i) cout << "*";
   cout << endl;

}

void gantChart(Process arr[],int size){
    cout<<"\t\t\t GantChart\n";
    for(int i=0;i<size;i++){
        cout<<setw(arr[i].bt)<<"P"<<arr[i].id<<"\t";
    }
    cout<<endl<<"0";
    int total=0;
    for (int i = 0; i < size; ++i) {
        total+=arr[i].bt;
        cout<<setfill('#')<<setw(arr[i].bt*2)<<total;
    }
}
void AverageTime(Process arr[],int size){
    int sum=0;
    for (int i = 0; i < size; ++i) {
        sum+=arr[i].wt;
    }
    cout<<"\n Average Waiting Time "<<sum<<"/"<<size<<"= "<<(float)sum/size<<endl;
}
int main()
{
    int nums;
    cout<<"Enter number of Processes: ";
    cin>>nums;
    Process arr[nums];

       input(arr , nums);
       sort (arr, arr+nums, comp );
       getWaitingTime(arr, nums);
       output(arr, nums);
       gantChart(arr,nums);
       AverageTime(arr,nums);

        return 0;
}

