#include "invertedindex.h"

size_t InvertedIndex::CountSubstring(const std::string& sourceStr, const std::string& searchStr) {
    size_t count = 0;

    std::stringstream ss(sourceStr);
    std::string word;
    while (ss >> word) {
        if (word == searchStr)
            count++;
    }

    return std::move(count);
}

void InvertedIndex::UpdateDocumentBase(const std::vector<std::string>& input_docs) {
    docs.clear();
    docs = std::vector<std::string>(input_docs);

    for (size_t i = 0; i < docs.size(); i++) {
        UpdateFreqDictionary(i, docs[i]);
    }
}

void InvertedIndex::UpdateFreqDictionary(size_t& doc_id, std::string& text) {
    // Получаем множества уникальных слов
    std::vector<std::string> words{};
    std::istringstream iss(text);
    std::string word;
    while (iss >> word)
        words.push_back(word);
    std::set<std::string> uniqueWords(words.begin(), words.end());

    // Обновляем частотный словарь
    for (auto & uniqueWord : uniqueWords) {
         auto dictEntries = freq_dictionary.find(uniqueWord);
         if (dictEntries == freq_dictionary.end()) {
             freq_dictionary[uniqueWord] = GetWordCount(uniqueWord);
         }
    }

}

std::vector<Entry> InvertedIndex::GetWordCount(const std::string& word) {
    std::vector<Entry> result{};

    for (size_t i = 0; i < docs.size(); i++) {
        size_t count = CountSubstring(docs[i], word);
        if (count > 0)
            result.push_back({i, count});
    }

    return std::move(result);
}

void InvertedIndex::UpdateFreqDictionary1() {
    std::map<std::string, std::map<int, int>> wordCounts;

    freq_dictionary.clear();

    // Подсчитываем кол-во слов по документам
    for (auto it = docs.begin(); it != docs.end(); ++it) {
        int doc_id = std::distance(docs.begin(), it);
        std::stringstream ss(it->data());
        std::string word;
        while (ss >> word) {
            ++wordCounts[word][doc_id];
        }
    }

    // Перегружаем значения в freq_dictionary
    for (const auto & pair : wordCounts) {
        for (const auto & pair1 : pair.second) {
            freq_dictionary[pair.first].push_back({
                static_cast<size_t>(pair1.first),
                static_cast<size_t>(pair1.second)});
        }
    }
}

void InvertedIndex::PrintInvertedIndex() {
    for (auto & pair : freq_dictionary) {
        std::cout << pair.first << ": ";
        for (auto & pair1 : pair.second) {
            std::cout << "{" << pair1.doc_id << ", " << pair1.count << "} ";
        }
        std::cout << std::endl;
    }
}

