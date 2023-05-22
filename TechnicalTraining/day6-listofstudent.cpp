#include <iostream>
#include <vector>
using namespace std;

vector <int> find_common(vector<pair<int, string>> roll_name_list, vector<pair<int, string>> roll_course_list, vector<pair<int, float>> roll_cgpa_list){
    int i=0,j=0,k=0;
    vector <int> common_roll;

    while(i< roll_name_list.size() && j<roll_course_list.size() && k<roll_cgpa_list.size()){
        if (roll_name_list[i].first == roll_course_list[j].first && roll_course_list[j].first == roll_cgpa_list[k].first){
            common_roll.push_back(roll_name_list[i].first);
            i++;j++;k++;
        }
        else if (roll_name_list[i].first < roll_course_list[j].first)
            i++;
        else if (roll_course_list[i].first < roll_cgpa_list[j].first)
            j++;
        else 
            k++;   
    }
    return common_roll;
}


int main(){
    vector<pair<int, string>> roll_name_list = {{1, "Alice"}, {2, "Bob"}, {3, "Charlie"}};
    vector<pair<int, string>> roll_course_list = {{2, "BCA"}, {3, "BE"}, {4, "BSc"}};
    vector<pair<int, float>> roll_cgpa_list = {{1, 8.0}, {2, 9.2}, {3, 7.8}};
    
    vector<int> common_roll_nos = find_common(roll_name_list, roll_course_list, roll_cgpa_list);
    
    cout << "Common roll numbers: ";
    for (int roll_no : common_roll_nos) {
        cout << roll_no << " ";
    }
    cout << endl;
    
    return 0;
}
