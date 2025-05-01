/*
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/maximum-number-of-tasks-you-can-assign
*/



/****************************************************************** C++ ******************************************************************/
//Approach (Binary Search on Answer)
//T.C : O(MLogM+NLogN+Min(M,N)∗Log(Min(M,N))∗Log(Min(M,N))), M = tasks.size(), N = workers.size()
//S.C : O(M)
class Solution {
public:
    bool check(vector<int>& tasks, vector<int>& workers, int pills, int strength, int mid) {
        int pillsUsed = 0;
        multiset<int> st(begin(workers), begin(workers) + mid); //best mid workers

        for(int i = mid-1; i >= 0; i--) {
            int reqrd = tasks[i];
            auto it   = prev(st.end());

            if(*it >= reqrd) {
                st.erase(it);
            } else if(pillsUsed >= pills) {
                return false;
            } else {
                //find the weakest worker which can do this strong task using pills
                auto weakestWorkerIt = st.lower_bound(reqrd - strength);
                if(weakestWorkerIt == st.end()) {
                    return false;
                }
                st.erase(weakestWorkerIt);
                pillsUsed++;
            }
        }

        return true;
    }
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int m = tasks.size();
        int n = workers.size();

        int l = 0;
        int r = min(m, n);

        sort(begin(tasks), end(tasks));
        sort(begin(workers), end(workers), greater<int>());

        int result = 0;

        while(l <= r) {
            int mid = l + (r-l)/2;

            if(check(tasks, workers, pills, strength, mid)) {
                result = mid;
                l = mid+1;
            } else {
                r = mid-1;
            }
        }

        return result;


    }
};


///////////////////////////////
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

class Solution {
public:
    bool canAssign(int k, vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        deque<int> availableWorkers;
        int m = workers.size();

        // Take the strongest k workers
        for (int i = m - k; i < m; ++i) {
            availableWorkers.push_back(workers[i]);
        }

        int pillsUsed = 0;
        for (int i = k - 1; i >= 0; --i) {
            int taskStrength = tasks[i];
            if (!availableWorkers.empty() && availableWorkers.back() >= taskStrength) {
                // Assign the strongest worker without pill
                availableWorkers.pop_back();
            } else {
                // Try to assign the weakest one with a pill
                if (pillsUsed >= pills || availableWorkers.empty() || availableWorkers.front() + strength < taskStrength) {
                    return false;
                }
                // Use pill on the weakest
                availableWorkers.pop_front();
                pillsUsed++;
            }
        }
        return true;
    }

    int maxTasks(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        int left = 0, right = min((int)tasks.size(), (int)workers.size()), ans = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canAssign(mid, tasks, workers, pills, strength)) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return ans;
    }
};

