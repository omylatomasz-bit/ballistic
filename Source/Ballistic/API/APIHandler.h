#pragma once

#include <string>
#include <curl/curl.h>

class APIHandler {
public:
    APIHandler();
    ~APIHandler();

    // Function to handle OpenAI API requests
    std::string sendOpenAIRequest(const std::string &prompt);

    // Function to handle ElevenLabs API requests
    std::string sendElevenLabsRequest(const std::string &data);

private:
    CURL *curl;
    std::string apiKeyOpenAI;
    std::string apiKeyElevenLabs;

    // Utility function to perform the request
    std::string performRequest(const std::string &url, const std::string &postData);
};
