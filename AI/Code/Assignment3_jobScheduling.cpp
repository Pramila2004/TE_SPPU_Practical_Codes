#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(vector<int> &a,vector<int> &b){
    return a[2]>b[2];
}

int main(){

    int n;
    cout<<"Enter Number of jobs : ";
    cin>>n;

    vector<vector<int>> jobList;
    cout<<"Enter Job name deadline and profit : ";
    for (int i = 0; i < n; i++)
    {
        int j,d,p;
        cin>>j>>d>>p;
        jobList.push_back({j,d,p});
    }


    sort(jobList.begin(),jobList.end(),cmp);

    int maxdeadline=0;

    for (int i = 0; i < n; i++)
    {
        maxdeadline=max(maxdeadline,jobList[i][1]);
    }
    
    vector<int> slot(maxdeadline+1,-1);
    int maxProfit=0;

    for (int i = 0; i < n; i++)
    {
        for (int j = jobList[i][1]; j >=1; j--)
        {
            if (slot[j]== -1)
            {
                slot[j]=jobList[i][0];
                maxProfit+=jobList[i][2];
                break;
            }
            
        }
        
    }

    cout << "\nTotal Profit: " << maxProfit << endl;
    cout << "Scheduled Jobs by Slot:\n";
    for (int i = 1; i <= maxdeadline; i++) {
        if (slot[i] != -1)
            cout << "Slot " << i << ": Job " << slot[i] << endl;
    }

    
    

    

    return 0;
}