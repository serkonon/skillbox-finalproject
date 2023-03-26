#include <iostream>
#include <memory>
#include "converterjson.h"
#include "invertedindex.h"


int main(int argc, char* argv[]) {

//    nlohmann::json dict;
//    dict["name"] = "sergey";
//    std::cout << dict << std::endl;
//    std::cout << argv[0] << std::endl;

//    std::unique_ptr<ConverterJSON> Conv = std::make_unique<ConverterJSON>();
    std::unique_ptr<ConverterJSON> Conv(new ConverterJSON);

    if (Conv->ReadConfigFile()) {
//        std::string configName = Conv->GetConfigName();
//        std::vector<std::string> filePaths = Conv->GetFilePaths();
//        std::cout << configName << ", " << filePaths[0] << std::endl;

        std::vector<std::string> contents = Conv->GetTextDocuments();

        int i = 0;
        for (auto & cont: contents) {
//            std::cout << i++ << ":\t" << cont << std::endl;
        }

        std::unique_ptr<InvertedIndex> InvIndex (new InvertedIndex);
        InvIndex->UpdateDocumentBase(contents);

        InvIndex->PrintInvertedIndex();
    }

    if (Conv->ReadRequestsFile()) {
        std::vector<std::string> requests = Conv->GetRequests();

        int i = 0;
        for (auto & req : requests) {
//            std::cout << i++ << ":\t" << req << std::endl;
        }
    }



    return 0;
}
