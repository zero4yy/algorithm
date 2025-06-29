// 有问题 ！！！！

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

struct WordPair{
	string first, second;
	int freq;

	// 自定义优先级
	bool operator < (const WordPair &other) const {
		if(freq != other.freq) return freq < other.freq;
		string merge1 = first + second, merge2 = other.first + other.second;
		if(merge1.length() != merge2.length()) return merge1.length() > merge2.length();
		if(first.length() != other.first.length()) return first.length() > other.first.length();
		return merge1 > merge2; // 字典序小的优先	
	}
};	

int n, m;
unordered_map<string, int> word_freq; // 单词及频率
vector<string> v_list; // 词汇表
map<pair<string, string>, int> pair_freq; // 词汇对 及 频率
vector<vector<string>> token_word; // 拆分后的单词序列
priority_queue<WordPair> pq;

// 初始化
void init() {
	unordered_set<string> char_set;
	for(auto [word, freq] : word_freq) {
		vector<string> tokens;
		for(char c : word) {
			string s(1, c);
			tokens.push_back(s);
			char_set.insert(s);
		}
		token_word.push_back(tokens);
	}
	v_list.assign(char_set.begin(), char_set.end()); // 按字典序初始化词汇表
}

// 统计词汇对的出现频率 并将词汇对加入优先队列
void cmpt_pair_freq() {
	pair_freq.clear();
	for(auto &tokens : token_word) {
		int freq = word_freq[accumulate(tokens.begin(), tokens.end(), string(""))];
		for(int i = 0; i + 1 < tokens.size(); i ++) {
			pair_freq[{tokens[i], tokens[i + 1]}] += freq;
		}
	}


	while(pq.size()) pq.pop();
	for(const auto &[p, freq] : pair_freq) {
		pq.push({p.first, p.second, freq});
	}
}

// 合并最佳词汇对
void merge_best_pair() {
	if(pq.empty()) return;
	auto best_pair = pq.top();
	pq.pop();
	string new_token = best_pair.first + best_pair.second;
	v_list.push_back(new_token);
	map<pair<string, string>, int> new_pair_freq; // 更新后的 词汇对 及 频率


	// 更新拆分后的单词序列
	for(auto &tokens : token_word) {
		vector<string>new_tokens;
		for(int i = 0; i < tokens.size(); i ++) {
			if(i + 1 < tokens.size() && tokens[i] == best_pair.first && tokens[i + 1] == best_pair.second) {
				new_tokens.push_back(new_token);
				i ++; // 跳过下一个字符
			} else {
				new_tokens.push_back(tokens[i]);
			}
		}
		tokens = new_tokens;
	}

	// 更新词汇对
	for(auto &tokens : token_word) {
		int freq = word_freq[accumulate(tokens.begin(), tokens.end(), string(""))];
		for(int i = 0; i + 1 < tokens.size(); i ++) {
			new_pair_freq[{tokens[i], tokens[i + 1]}] += freq;
		}
	}

	while(pq.size()) pq.pop();
	for(const auto &[p, freq] : new_pair_freq) {
		pq.push({p.first, p.second, freq});
	}
}

void work() {
	init();
	cmpt_pair_freq();
	while(v_list.size() < m && pq.size()) {
		merge_best_pair();
	}
}

int main() {
	cin >> n >> m;
	for(int i = 0; i < n; i ++) {
		string word;
		int freq;
		cin >> word >> freq;
		word_freq[word] = freq;
	}
	work();
	for(const auto &word : v_list) cout << word << endl;
	return 0;
}