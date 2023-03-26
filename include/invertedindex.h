#pragma once

#include <iostream>
#include <vector>
#include <set>
#include <sstream>
#include "converterjson.h"

#ifndef SEARCH_ENGINE_INVERTEDINDEX_H
#define SEARCH_ENGINE_INVERTEDINDEX_H

struct Entry {
    size_t doc_id, count;

    // Данный оператор необходим для проведения тестовых сценариев
    bool operator ==(const Entry& other) const {
        return (doc_id == other.doc_id &&
                count == other.count);
    }
};

/**
* Класс для создания инвертированного индекса
*/
class InvertedIndex {
    std::vector<std::string> docs; //Список содержимого документов
    std::map<std::string, std::vector<Entry>> freq_dictionary; //Частотный словарь

    size_t CountSubstring(const std::string& str, const std::string& sub);
    void UpdateFreqDictionary1();
    void UpdateFreqDictionary(size_t& doc_id, std::string& text);

public:
    InvertedIndex() = default;

    /**
    * Обновить или заполнить базу документов, по которой будем совершать поиск
    * @param input_docs содержимое документов
    */
    void UpdateDocumentBase(const std::vector<std::string>& input_docs);

    /**
    * Метод определяет количество вхождений слова word в загруженной базе документов
    * @param word слово, частоту вхождений которого необходимо определить
    * @return возвращает подготовленный список с частотой слов
    */
    std::vector<Entry> GetWordCount(const std::string& word);

    void PrintInvertedIndex();
};



#endif //SEARCH_ENGINE_INVERTEDINDEX_H
