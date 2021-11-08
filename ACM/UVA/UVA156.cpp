#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;

string sta (string str)
{
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    sort(str.begin(), str.end());
    return str;
}

vector<string> word, word2;
map<string, int> words;

int main()
{
    string str;
    while (cin >> str)
    {
        if (str[0] == '#') break;
        else {
            word.push_back(str);
            string buff = sta(str);
            if (words.count(buff) == 0) words[buff] = 0;
            ++words[buff];
        }
    }
    for (int i = 0; i < word.size(); ++i) if (words[sta(word[i])] == 1) word2.push_back(word[i]);
    sort(word2.begin(), word2.end());
    for (int i = 0; i < word2.size(); ++i) cout << word2[i] << endl;
    system("pause");
    return 0;
}