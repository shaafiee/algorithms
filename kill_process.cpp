class Solution {
private:
    struct process {
        int pid;
        vector<struct process> children;
    };
    
public:
    
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        vector<int> result;

        if (pid.size() == 1) {
            result.push_back(pid[0]);
            return result;
        }
        
        int size = *max_element(pid.begin(), pid.end());
        //struct process* procIndex = new struct process[size];
        vector<struct process> procIndex;
        procIndex.resize(size + 1);
        vector<int> toProcess;
        vector<int> queue;
        
        for (int i = 0; i < pid.size(); i++) {
            procIndex[pid[i]].pid = pid[i];
            if (ppid[i] > 0) {
                procIndex[ppid[i]].children.push_back(procIndex[pid[i]]);
            }
        }

        bool exhausted = false;
        
        int pivot = kill;
        result.push_back(kill);
        toProcess.push_back(kill);
        while (toProcess.size() > 0) {
            queue.clear();
            for (int i = 0; i < toProcess.size(); i++) {
                for (int j = 0; j < procIndex[toProcess[i]].children.size(); j++) {
                    result.push_back(procIndex[toProcess[i]].children[j].pid);
                    if (procIndex[procIndex[toProcess[i]].children[j].pid].children.size() > 0) {
                        queue.push_back(procIndex[toProcess[i]].children[j].pid);
                    }
                }
            }
            if (queue.size() > 0) {
                toProcess = queue;
            } else {
                toProcess.clear();
            }
        }
        
        return result;
        
    }
};
