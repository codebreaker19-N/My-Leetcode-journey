class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> free;
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> busy;

        int n = servers.size();
        for (int i=0;i<n;i++){
            free.push({servers[i], i});
        }
        vector<int> ans;
        long long time = 0;

        for(int i=0;i<tasks.size();i++){
            time = max(time, (long long)i);

            while(!busy.empty() && busy.top().first<=time){
                int id = busy.top().second;
                busy.pop();
                free.push({servers[id], id});
            }

            if(free.empty()){
                time = busy.top().first;

                while(!busy.empty() && busy.top().first <= time){
                    int id = busy.top().second;
                    busy.pop();
                    free.push({servers[id], id});
                }
            }
            int id = free.top().second;
            free.pop();
            ans.push_back(id);
            busy.push({time + tasks[i], id});
        }

        return ans;
    }
};