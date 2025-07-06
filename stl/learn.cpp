#include <bits/stdc++.h>
using namespace std;

int sum(int a, int b){
    return a + b;
}

void explainPair(){
   pair<int,int> p = {1, 2}; 
   cout<<p.first<<" "<<p.second<<endl;

   pair<int,pair<int,int>> p2 = {1, {2, 3}};
   cout<<p2.first<<" "<<p2.second.first<<" "<<p2.second.second;
}


void iterateVector(vector <int> &v){
    cout<<"Iterating through vector using range-based for loop: ";
    // for (vector<int>::iterator i = v.begin(); i != v.end(); i++)
    // {
    //     cout<<*i<<" ";
    // }
    for (auto i = v.begin(); i < v.end(); i++)
    {
        cout<<*i<<" ";
    }
    cout<<endl<<"Using auto keyword: "<<endl;
    for(auto i : v){
        cout<<i<<" ";
    }
}

void earseVector(vector<int> &v){
    // v.erase(v.begin() + 1); 
    // this will remove the second element
    v.erase(v.begin() + 2, v.begin() + 4);
    // this will remove the second and third element
    // for(auto i : v){
    //     cout<<i<<" ";   
    // }
}
void insertVector(vector<int> &v){
    v.insert(v.begin()+1, 100);
    v.insert(v.begin()+2, 2, 6);
    for (auto i : v){
        cout<<i<<" ";
    }
}

void explainVector(){
    vector<int> v;
    v.push_back(1);
    v.emplace_back(2);

    vector<pair<int, int>> v2;
    v2.push_back({1, 2});
    v2.emplace_back(3, 4);


    vector<int> allHundrend(5,100);
    // for(auto i : allHundrend){
    //     cout<<i<<" ";
    // }

    vector<int> v3;
    v3.push_back(1);
    v3.push_back(2);
    v3.push_back(3);

    vector<int> copy(v3);

    // for(auto i : copy){
    //     cout<<i<<" ";
    // }

    vector<int>::iterator it = v3.begin();

    // This will give the address next to the last element
    vector<int>::iterator it2 = v3.end();
    it2--;
    cout<<*it2<<endl; 

    vector<int>::reverse_iterator rit = v3.rend();
    rit--;
    cout<<*rit<<endl; 

    vector<int>::reverse_iterator rit2 = v3.rbegin();
    rit2++;
    // This will give the address of second last element
    cout<<*rit2<<endl;

    // iterateVector(v3);
    vector<int>v4={10, 20, 12, 23};
    earseVector(v4);
    insertVector(v4);

}

void explainList(){
    list<int> l;
    l.push_back(1);
    l.emplace_back(2);
    l.push_front(3);
    for(auto i : l){
        cout<<i<<" ";
    }
    // rest same functions as vector
}
void explainDeque(){
    deque<int> d;
    d.push_back(1);
    d.push_front(2);
    d.emplace_back(3);
    for(auto i : d){
        cout<<i<<" ";
    }
    // rest same functions as vector
}


void explainStack(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(3);
    s.emplace(5);

    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;

    cout<<s.size()<<endl;
    cout<<s.empty()<<endl;
}

void explainQueue(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(4);

    q.back()+=5;

    cout<<q.front()<<endl;

    cout<<q.back()<<endl;

    q.pop();
    cout<<q.front()<<endl;
    // size swap empty same as stack
}

void explainPO(){
    // push O(log n) pop O(log n) top O(1)
    priority_queue<int> pq;
    pq.push(5);
    pq.push(2);
    pq.push(8);
    pq.emplace(10);

    cout<<"Maximum element is "<<pq.top()<<endl; 

    priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push(5);
    minHeap.push(2);
    minHeap.push(8);
    minHeap.emplace(10);    

    cout<<"Minimum element is "<<minHeap.top()<<endl;
}


int main(){
    int s = sum(2, 3);
    // cout << s << endl;
    // explainPair();
    // explainVector();
    // explainList();
    // explainDeque();
    // explainStack();
    // explainQueue();
    explainPO();
}