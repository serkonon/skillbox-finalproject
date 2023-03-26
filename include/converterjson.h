#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include "nlohmann/json.hpp"

#ifndef SEARCH_ENGINE_CONVERTERJSON_H
#define SEARCH_ENGINE_CONVERTERJSON_H

/**
* Класс для работы с JSON-файлами
*/
class ConverterJSON {
    struct Config {
        std::string name;
        std::string version;
        unsigned char max_responces;
    };

    struct Settings {
        Config config;
        std::vector<std::string> files;
    };

    const std::string CONFIG_FILE = "json/config.json";
    const std::string REQS_FILE = "json/requests.json";
    Settings settings;
    std::vector<std::string> requests;

    bool GetFileContent(const std::string& fileName, std::string& content);

public:
    bool ReadConfigFile();
    bool ReadRequestsFile();

    std::string GetConfigName() {
        return std::move(settings.config.name);
    };

    std::vector<std::string> GetFilePaths() {
        return std::move(settings.files);
    };

    ConverterJSON() = default;
    /**
    * Метод получения содержимого файлов
    * @return Возвращает список с содержимым файлов перечисленных
    *
    в config.json
    */
    std::vector<std::string> GetTextDocuments();

    /**
    * Метод считывает поле max_responses для определения предельного
    * количества ответов на один запрос
    * @return
    */
    int GetResponsesLimit();

    /**
    * Метод получения запросов из файла requests.json
    * @return возвращает список запросов из файла requests.json
    */
    std::vector<std::string> GetRequests();

    /**
    * Положить в файл answers.json результаты поисковых запросов
    */
    void putAnswers(std::vector<std::vector<std::pair<int, float>>>
    answers);
};


#endif //SEARCH_ENGINE_CONVERTERJSON_H
