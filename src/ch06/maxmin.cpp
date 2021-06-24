#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main()
{
	string line1 = "We were her pride of 10 she named us --";
	string line2 = "Benjamin, Phoenix, the Prodigal";
	string line3 = "and perspicacious pacific Suzanne";
	string sentence = line1 + ' ' + line2 + ' ' + line3;

	cout << '"' << sentence << '"' << endl;
	string::size_type pos = 0, prev_pos = 0;
	typedef pair<short, string> track;
	vector<track> words;
	string word;
	short len;

	// 收集句中的单词
	while ((pos = sentence.find_first_of(' ', pos)) != string::npos) {
		len = pos - prev_pos;
		word = sentence.substr(prev_pos, len);
		cout << word << endl;
		words.push_back(make_pair(len, word));
		prev_pos = ++pos;
	}

	// 收集最后一个单词
	len = sentence.size() - prev_pos;
	word = sentence.substr(prev_pos, len);
	cout << word << endl;
	words.push_back(make_pair(len, word));

	int min = words[0].first;
	int max = words[0].first;
	vector<track>::size_type i;

	// 决定 max 和 min 的值
	for (i = 0; i < words.size(); ++i) {
		if (min > words[i].first)
			min = words[i].first;
		if (max < words[i].first)
			max = words[i].first;
	}
	cout << "MIN \n";
	for (i = 0; i < words.size(); ++i) {
		if (min == words[i].first)
			cout << words[i].first << " " << words[i].second << endl;
	}
	cout << "MAX \n";
	for (i = 0; i < words.size(); ++i) {
		if (max == words[i].first)
			cout << words[i].first << " " << words[i].second << endl;
	}

	return 0;
}
