#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <map>
#include <set>

#include <fstream>

#include <locale>

using namespace std;

typedef pair<short, short> location;
typedef vector<location> loc;
typedef vector<string> text;
typedef pair<text*, loc*> text_loc;

// 返回值是指向 string vector 的指针
vector<string> *retrieve_text()
{
	string file_name;
	cout << "please enter file name: ";
	cin >> file_name;

	// 打开文本文件以便输入 ...
	ifstream infile(file_name.c_str(), ios::in);
	if (!infile) {
		cerr << "oops! unable to open file "
			<< file_name << " -- bailing out!\n";
		exit(-1);
	} else {
		cout << '\n';
	}
	vector<string> *lines_of_text = new vector<string>;
	string textline;
	typedef pair<string::size_type, int> stats;
	stats maxline;
	int linenum = 0;

	while (getline(infile, textline, '\n')) {
		cout << "line read: " << textline << '\n';
		if (maxline.first << textline.size()) {
			maxline.first = textline.size();
			maxline.second = linenum;
		}

		lines_of_text->push_back(textline);
		linenum++;
	}
	return lines_of_text;
}

text_loc *separate_words(const vector<string> *text_file)
{
	// words: 包含独立单词的集合
	// locations: 包含相关的行/列信息
	vector<string> *words = new vector<string>;
	vector<location> *locations = new vector<location>;
	vector<string>::size_type line_pos = 0; // current line number

	// iterate through each line of text
	for (; line_pos < text_file->size(); ++line_pos) {
		// textline: 待处理的当前文本行
		// word_pos: 文本行中的当前列位置
		short word_pos = 0;
		string textline = (*text_file)[line_pos];
		string::size_type pos = 0, prev_pos = 0;

		while ((pos = textline.find_first_of(' ', pos)) != string::npos) {
			// 存储当前单词串的拷贝
			words->push_back(textline.substr(prev_pos, pos - prev_pos));
			// 将行/列信息存储为 pair
			locations->push_back(make_pair(line_pos, word_pos));
			// 为下一次迭代修改位置信息
			++word_pos;
			prev_pos = ++pos;
		}

		// 现在处理最后一个单词
		words->push_back(textline.substr(prev_pos, pos - prev_pos));
		locations->push_back(make_pair(line_pos, word_pos));
	}
	return new text_loc(words, locations);
}

void filter_text(vector<string> *words, string filter)
{
	vector<string>::iterator iter = words->begin();
	vector<string>::iterator iter_end = words->end();

	// 如果用户没有提供 filter, 则缺省使用最小集
	if (!filter.size())
		filter.insert(0, "\".,");

	while (iter != iter_end) {
		string::size_type pos = 0;

		// 对于找到的每个元素，将其删除
		while ((pos = (*iter).find_first_of(filter, pos)) != string::npos)
			(*iter).erase(pos, 1);
		iter++;
	}
}

void strip_caps(vector<string> *words)
{
	vector<string>::iterator iter = words->begin();
	vector<string>::iterator iter_end = words->end();

	string caps("ABCDEFGHIJKLMNOPQRSTUVWXYZ");

	while (iter != iter_end) {
		string::size_type pos = 0;
		while ((pos = (*iter).find_first_of(caps, pos)) != string::npos)
			(*iter)[pos] = tolower((*iter)[pos]);
		++iter;
	}
}

void suffix_s(string &word)
{
	string::size_type spos = 0;
	string::size_type pos3 = word.size() - 3;
	// "ous", "ss", "is", "ius"
	string suffixes("oussisius");

	if (!word.compare(pos3, 3, suffixes, spos, 3) ||
			!word.compare(pos3, 3, suffixes, spos+6, 3) ||
			!word.compare(pos3+1, 2, suffixes, spos+2, 2) ||
			!word.compare(pos3+1, 2, suffixes, spos+4, 2))
		return;
	string ies("ies");
	if (!word.compare(pos3, 3, ies)) {
		word.replace(pos3, 3, 1, 'y');
		return;
	}
	string ses("ses");
	if (!word.compare(pos3, 3, ses)) {
		word.erase(pos3+1, 2);
		return;
	}

	// 去掉尾部的 's'
	word.erase(pos3+2);

	// watch out for "'s"
	if (word[pos3+1] == '\'')
		word.erase(pos3+1);
}

void suffix_text(vector<string> *words)
{
	vector<string>::iterator iter = words->begin(), iter_end = words->end();

	while (iter != iter_end) {
		// 如果只有 3 个字符或者更少，则不加处理
		if ((*iter).size() <= 3) {
			++iter;
			continue;
		}
		if ((*iter)[(*iter).size()-1] == 's')
			suffix_s(*iter);

		// 其他后缀的处理，比如 ed、ing、ly 等

		++iter;
	}
}

map<string, loc*> *build_word_map(const text_loc *text_locations)
{
	map<string, loc*> *word_map = new map<string, loc*>;

	typedef map<string, loc*>::value_type value_type;
	typedef set<string>::difference_type diff_type;
	set<string> exclusion_set;
	ifstream infile("exclusion_set");

	if (!infile) {
		static string default_excluded_words[25] = {
			"the", "and", "but", "that", "then", "are", "been",
			"can", "can't", "cannot", "could", "did", "for",
			"had", "have", "him", "his", "her", "its", "into",
			"were", "which", "when", "with", "would"
		};
		cerr << "warning! unable to open word exclusion file! --"
			<< "using default set\n";
		copy(default_excluded_words, default_excluded_words+25,
				inserter(exclusion_set, exclusion_set.begin()));
	} else {
		// There is an error here.
		// https://stackoverflow.com/questions/15832945/whats-wrong-with-this-iterator-declaration
		// istream_iterator<string, diff_type> input_set(infile), eos;
		istream_iterator<string, char, char_traits<char>, diff_type> input_set(infile), eos;
		copy(input_set, eos, inserter(exclusion_set, exclusion_set.begin()));
	}

	vector<string> *text_words = text_locations->first;
	vector<location> *text_locs = text_locations->second;
	register int elem_cnt = text_words->size();

	for (int ix = 0; ix < elem_cnt; ++ix) {
		string textword = (*text_words)[ix];

		// 排出策略: 如果少于 3 个字符或在排除集合中存在，则不输入到 map 中
		if (textword.size() < 3 || exclusion_set.count(textword))
			continue;

		// 判断单词是否存在
		// 如果 count() 返回 0，则不存在 -- 加入它
		if (!word_map->count((*text_words)[ix])) {
			loc *ploc = new vector<location>;
			ploc->push_back((*text_locs)[ix]);
			word_map->insert(value_type((*text_words)[ix], ploc));
		} else {
			// 修改该项的位置向量
			(*word_map)[(*text_words)[ix]]->push_back((*text_locs)[ix]);
		}
	}
	return word_map;
}

void display_map_text(map<string, loc*> *text_map)
{
	typedef map<string, loc*> tmap;
	tmap::iterator iter = text_map->begin(), iter_end = text_map->end();

	while (iter != iter_end) {
		cout << "word: " << (*iter).first << " (";
		int loc_cnt = 0;
		loc *text_locs = (*iter).second;
		loc::iterator liter = text_locs->begin(), liter_end = text_locs->end();

		while (liter != liter_end) {
			if (loc_cnt)
				cout << ',';
			else
				++loc_cnt;
			cout << '(' << (*liter).first << ',' << (*liter).second << ')';
			++liter;
		}

		cout << ")\n";
		++iter;
	}
	cout << endl;
}


int main()
{
	vector<string> *text_file = retrieve_text();
	text_loc *text_locations = separate_words(text_file);
	string filt_elems("\",.;:!?)(\\/");
	filter_text(text_locations->first, filt_elems);
	strip_caps(text_locations->first);
	suffix_text(text_locations->first);

	map<string, loc*> *text_map = build_word_map(text_locations);
	display_map_text(text_map);

	return 0;
}
