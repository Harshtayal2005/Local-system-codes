#include<iostream>
#include<map> // complexity for insertion, deletion, searching = O(logn)
#include<unordered_map> // complexity for insertion, deletion, searching = O(1)
using namespace std;

int main(){
    // map creation using inbuit functions
    unordered_map<string, int> m;
    //insertion
    //method 1
    pair<string, int> p = make_pair("string1", 1);
    m.insert(p);

    //method 2
    pair<string, int> p1("string2", 2);
    m.insert(p1);

    //method 3
    m["string3"] = 3;

    //size
    cout<<m.size()<<endl;

    //searching
    cout<<m["string1"]<<endl; // return value 1
    cout<<m.at("string2")<<endl; // this will also return value at key, here 2
    cout<<m.size()<<endl; // size 3
    cout<<m["string4"]<<endl; // string4 is not inserted so this function will create a 0 value for this key
    cout<<m.size()<<endl; // size 4
    cout<<m.at("string4")<<endl; // return value 0
    // cout<<m.at("string5")<<endl;
    /* string5 is not inserted but unlike string4, this function will not create any key
    value pair and simply abort the function */
    /* Conclusion : m[key] and m.at(key), both will return the value at key but m[key] will also create a value 
    0 for unknown key whereas m.at(key) will simply abort the function for unknown key */

    // to check presence of a key, use "count()" function
    // count() will give 0 if the key is absent and 1 if the key is present()
    cout<<m.count("string5")<<endl; // return 0
    cout<<m.count("string4")<<endl; // return 1

    //erase
    cout<<m.size()<<endl; // return 4
    m.erase("string4");
    cout<<m.size()<<endl; // return 3

    // traversing the key-value using "for-each" loop
    for(auto i:m){
        cout<<i.first<<"->"<<i.second<<endl; // returns the key
    }

    // traversing the key-value using iterator
    // syntax for unordered_map: unordered_map<data_type, data_type> :: iterator it_name = position_to_begin_with
    unordered_map<string, int> :: iterator it = m.begin();
    while(it != m.end()){
        cout<<it->first<<"->"<<it->second<<endl;
        it++;
    }
    /* we can see that the order of printing is not the same as we inserted because it's a unordered map. If we use
    ordered map for the same then the print will be in same order as we inserted */
    
    // ------NOTE-------
    // m.begin() will always point to the first key in map but
    // m.end() will always point to the key ahead of end key, i.e NULL 
    return 0;
}