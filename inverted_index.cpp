#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <cctype>
#include <boost/tokenizer.hpp>
using namespace std;
using namespace boost;

// Create a map, Key: term, Value: set(posting list)
map<string, set<string>> index_list;

// 创建 index 和 posting list
void Build_Index(tokenizer<char_separator<char>>::iterator &word, int n){
    string str = *word;
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    index_list[str].insert(to_string(n));
}

int main() {
    vector<string> filename;
    // 将文件名一一读入
    cout << "请输入文件名:" << endl;
    while(!cin.eof()){
        string s;
        cin >> s;
        filename.push_back(s);
    }

    // 逐个读取文件
    ifstream fp;
    int i;
    // 定义文件中可能出现的分隔符
    char_separator<char> sep{".?!,:;-()[]{}\"' "};
    for(i = 0; i < filename.size(); ++i){
        fp.open(filename[i]);
        // 逐行读取文件并逐个分隔提取单词
        string fline;
        while(!fp.eof()){
            getline(fp, fline); // 逐行读取文件
            // 逐个分隔单词并创建 index 和 posting list
            tokenizer<char_separator<char>> tok(fline, sep);
            for(tokenizer<char_separator<char>>::iterator word = tok.begin(); word != tok.end(); ++word){
                Build_Index(word, i + 1); // 调用创建 index list 的函数
            }
        }
        fp.close();
    }

    // 将倒排索引写入文件
    ofstream fout;
    fout.open("inverted_index.txt");
    for(auto &item: index_list){
        string posting_list;
        for(auto &value: item.second)
            posting_list += value + " ";
        fout << item.first << " " << item.second.size() << " " << posting_list << endl;
    }
    fout.close();
    return 0;
}