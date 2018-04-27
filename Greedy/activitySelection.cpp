#include <bits/stdc++.h>

using namespace std;

struct activity{
    string activityName;
    int startTime;
    int endTime;
};

bool isGreater(activity a, activity b){
    return a.endTime < b.endTime;
}

vector <activity> activitySelector(activity acts[], int n){
    sort(acts, acts + n, isGreater);
    vector <activity> v;
    v.push_back(acts[0]);
    for (int i = 1; i < n; i++){
        if (acts[i].startTime >= v[v.size() - 1].endTime)
            v.push_back(acts[i]);
    }
    return v;
}

void printActivities(vector <activity> v){
    cout << "Perform activities in following order:\n";
    for (int i = 0; i < v.size(); i++){
        cout << i + 1 << ". "  << v[i].activityName << "\n";
    }
}

int main(){
    int numActivity;
    cin >> numActivity;
    activity acts[numActivity];
    for (int i = 0; i < numActivity; i++){
        cin >> acts[i].activityName >> acts[i].startTime >> acts[i].endTime;
    }
    vector <activity> v = activitySelector(acts, numActivity);
    printActivities(v);
    return 0;
}
