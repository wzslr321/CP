class Solution {
public:
    double average(vector<int>& salary) {
       int min{salary[0]}; 
       int max{salary[0]};
       double sum {double(salary[0])};
        
       for(auto i{1}; i < salary.size(); i ++){
           if(salary[i] > max) max = salary[i];
           if(salary[i] < min) min = salary[i];
           sum += salary[i];
       }
       sum -= min + max;
        
       return sum / (salary.size() - 2);
    }
};