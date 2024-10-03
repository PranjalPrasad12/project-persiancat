#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

// Callback function to write data into a string
size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    size_t totalSize = size * nmemb;
    char* buffer = (char*)contents;

    // Allocate memory for the user-provided buffer and append the contents
    strcat(userp, buffer);
    return totalSize;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
        return 1;
    }

    CURL* curl;
    CURLcode res;
    char* readBuffer = malloc(1000000);  // Allocate enough memory for the web page content
    readBuffer[0] = '\0';  // Initialize buffer as an empty string

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, argv[1]);  // Set the URL to fetch
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);  // Set callback for writing data
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, readBuffer);  // Pass the buffer to the callback

        // Perform the request, `res` will get the return code
        res = curl_easy_perform(curl);
        
        // Check for errors
        if (res == CURLE_OK) {
            printf("Fetched content:\n%s\n", readBuffer);
        } else {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }

        // Cleanup
        curl_easy_cleanup(curl);
    }

    // Free the allocated memory
    free(readBuffer);

    return 0;
}
