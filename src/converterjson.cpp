#include "converterjson.h"

bool ConverterJSON::GetFileContent(const std::string& fileName, std::string& content) {
    std::ifstream file(fileName);

    if (!file.is_open())
        return false;

    content = std::string((std::istreambuf_iterator<char>(file)),
                          std::istreambuf_iterator<char>());

    file.close();
    return true;
}

bool ConverterJSON::ReadConfigFile() {
    std::string json_str{};

    if (!GetFileContent(CONFIG_FILE, json_str)) {
        std::cerr << "Error of reading file " << CONFIG_FILE << std::endl;
        return false;
    }

    nlohmann::json json_obj = nlohmann::json::parse(json_str);

    nlohmann::json config_obj = json_obj.at("config");

    settings.config.name = config_obj.at("name");
    settings.config.version = config_obj.at("version");
    settings.config.max_responces = config_obj.at("max_responses");

    for (auto & filePath : json_obj.at("files").items()) {
        settings.files.push_back(filePath.value());
    }

    return true;
}

bool ConverterJSON::ReadRequestsFile() {
    std::string json_str{};

    if (!GetFileContent(REQS_FILE, json_str)) {
        std::cerr << "Error of reading file " << REQS_FILE << std::endl;
        return false;
    }

    nlohmann::json json_obj = nlohmann::json::parse(json_str);

    for (auto & request : json_obj.at("requests").items()) {
        requests.push_back(request.value());
    }

    return true;
}

std::vector<std::string> ConverterJSON::GetTextDocuments() {
    std::vector<std::string> result;

    for (auto & file : settings.files) {
        std::string fileContent{};

        if (!GetFileContent(file, fileContent)) {
            std::cerr << "Error of reading file " << file << std::endl;
        } else {
            result.push_back(fileContent);
        }
    }

    return std::move(result);
}

int ConverterJSON::GetResponsesLimit() {
    return settings.config.max_responces;
}

std::vector<std::string> ConverterJSON::GetRequests() {
    return std::move(requests);
}

void ConverterJSON::putAnswers(std::vector<std::vector<std::pair<int, float>>> answers) {

}

