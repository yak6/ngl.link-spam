#include <iostream>
#include <thread>
#include <vector>
#include <string>
#include <curl/curl.h>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <map>
#include <filesystem>
#include <list>
#include <random>  
#include <iterator>  

std::string fast_useragent() { // for --fuck, --ask
    std::list<std::string> useragents = { 
        "Mozilla/5.0 (Windows NT 6.3; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/42.0.2311.152 Safari/537.36 LBBROWSER",
        "Mozilla/5.0 (Macintosh; Intel Mac OS X 10.8; rv:37.0) Gecko/20100101 Firefox/37.0",
        "Mozilla/5.0 (Windows NT 6.2; ARM; Trident/7.0; Touch; rv:11.0; WPDesktop; Lumia 1520) like Gecko",
        "Mozilla/5.0 (Windows NT 6.1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.65 Safari/537.36",
        "Mozilla/5.0 (Windows NT 6.1; WOW64; rv:42.0) Gecko/20100101 Firefox/42.0",
        "Mozilla/5.0 (iPhone; CPU iPhone OS 7_0_6 like Mac OS X) AppleWebKit/537.51.1 (KHTML, like Gecko) Version/7.0 Mobile/11B651 Safari/9537.53",
        "Mozilla/4.0 (compatible; MSIE 8.0; Windows NT 6.1; WOW64; Trident/4.0; SLCC2; .NET CLR 2.0.50727; .NET CLR 3.5.30729; .NET CLR 3.0.30729; Media Center PC 6.0; InfoPath.2; .NET4.0C; .NET4.0E)",
        "Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.1; WOW64; Trident/4.0; SLCC2; .NET CLR 2.0.50727; .NET4.0C; .NET4.0E; 360SE)",
        "Mozilla/5.0 (Windows NT 6.3; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/37.0.2062.103 Safari/537.36",
        "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_6_8) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/44.0.2403.125 Safari/537.36",
        "Mozilla/4.0 (compatible; MSIE 7.0; Windows NT 6.1; WOW64; Trident/5.0; SLCC2; .NET CLR 2.0.50727; .NET CLR 3.5.30729; .NET CLR 3.0.30729; Media Center PC 6.0; InfoPath.3; .NET4.0C; .NET4.0E)",
        "Mozilla/5.0 (Macintosh; Intel Mac OS X 10.9; rv:34.0) Gecko/20100101 Firefox/34.0",
        "Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/32.0.1700.76 Safari/537.36",
        "Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/41.0.2272.87 Safari/537.36",
        "Mozilla/5.0 (Windows NT 6.1; WOW64; Trident/7.0; PRU_IE; rv:11.0) like Gecko",
        "Mozilla/5.0 (X11; Linux i686) AppleWebKit/537.36 (KHTML, like Gecko) Ubuntu Chromium/37.0.2062.120 Chrome/37.0.2062.120 Safari/537.36",
        "Mozilla/5.0 (iPad; CPU OS 8_4_1 like Mac OS X) AppleWebKit/600.1.4 (KHTML, like Gecko) Mobile/12H321 [FBAN/FBIOS;FBAV/38.0.0.6.79;FBBV/14316658;FBDV/iPad4,1;FBMD/iPad;FBSN/iPhone OS;FBSV/8.4.1;FBSS/2; FBCR/;FBID/tablet;FBLC/en_US;FBOP/1]",
        "Mozilla/5.0 (Windows NT 6.2; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/44.0.2403.155 Safari/537.36 OPR/31.0.1889.174",
        "Mozilla/5.0 (Windows NT 6.1; WOW64; Trident/7.0; NP02; rv:11.0) like Gecko",
        "Mozilla/5.0 (Windows NT 6.3; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/40.0.2214.111 Safari/537.36",
        "Mozilla/4.0 (compatible; MSIE 8.0; Windows NT 6.1; Win64; x64; Trident/4.0; .NET CLR 2.0.50727; SLCC2; .NET CLR 3.5.30729; .NET CLR 3.0.30729; Media Center PC 6.0; .NET4.0C; .NET4.0E)",
        "Mozilla/5.0 (X11; CrOS x86_64 6946.63.0) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.130 Safari/537.36",
        "Mozilla/5.0 (Macintosh; Intel Mac OS X 10.7; rv:37.0) Gecko/20100101 Firefox/37.0",
        "Mozilla/5.0 (Windows NT 6.3; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/40.0.2214.115 Safari/537.36",
        "Mozilla/5.0 (Windows NT 6.1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/42.0.0.9895 Safari/537.36",
        "Mozilla/5.0 (Linux; Android 4.4.4; Nexus 7 Build/KTU84P) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/45.0.2454.84 Safari/537.36",
        "Mozilla/5.0 (Linux; Android 4.2.2; QMV7B Build/JDQ39) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/34.0.1847.114 Safari/537.36",
        "Mozilla/5.0 (Windows NT 6.3; Win64; x64; Trident/7.0; Touch; MASMJS; rv:11.0) like Gecko",
        "Mozilla/5.0 (compatible; MSIE 10.0; AOL 9.7; AOLBuild 4343.1028; Windows NT 6.1; WOW64; Trident/7.0)",
        "Mozilla/5.0 (Linux; U; Android 4.0.3; en-us) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/31.0.1650.59 Mobile Safari/537.36",
        "Mozilla/5.0 (Windows NT 6.3; Trident/7.0; Touch; TNJB; rv:11.0) like Gecko",
        "Mozilla/5.0 (iPad; CPU OS 8_1_3 like Mac OS X) AppleWebKit/600.1.4 (KHTML, like Gecko) Mobile/12B466",
        "Mozilla/5.0 (compatible; MSIE 9.0; Windows NT 6.1; WOW64; Trident/5.0; Active Content Browser)",
        "Mozilla/4.0 (compatible; MSIE 7.0; Windows NT 6.1; WOW64; Trident/7.0; SLCC2; .NET CLR 2.0.50727; .NET CLR 3.5.30729; .NET CLR 3.0.30729; .NET4.0C; .NET4.0E)",
        "Mozilla/5.0 (Windows NT 5.1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/44.0.2403.130 Safari/537.36",
        "Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36",
        "Mozilla/4.0 (compatible; MSIE 7.0; Windows NT 6.1; Trident/6.0; SLCC2; .NET CLR 2.0.50727; .NET CLR 3.5.30729; .NET CLR 3.0.30729; Media Center PC 6.0; .NET4.0C; .NET4.0E; InfoPath.3)",
        "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_9_5) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.81 Safari/537.36",
        "Mozilla/5.0 (compatible; MSIE 10.0; Windows NT 6.2; Win64; x64; Trident/6.0; WebView/1.0)",
        "Mozilla/5.0 (Windows NT 6.3; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/44.0.2403.89 Safari/537.36",
        "Mozilla/5.0 (Windows NT 5.1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.130 Safari/537.36",
        "Mozilla/5.0 (Windows NT 6.1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/40.0.2214.91 Safari/537.36",
        "Mozilla/5.0 (iPad; U; CPU OS 5_0 like Mac OS X) AppleWebKit/534.46 (KHTML, like Gecko) Version/5.1 Mobile/9A334 Safari/7534.48.3",
        "Mozilla/5.0 (Windows NT 5.1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/42.0.2311.135 Safari/537.36",
        "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_10_2) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.130 Safari/537.36",
        "Mozilla/5.0 (Windows NT 6.1) AppleWebKit/537.36 (KHTML, like Gecko) coc_coc_browser/50.0.125 Chrome/44.0.2403.125 Safari/537.36",
        "Mozilla/5.0 (compatible; MSIE 10.0; Windows NT 6.1; WOW64; Trident/6.0; SLCC2; .NET CLR 2.0.50727; .NET4.0C; .NET4.0E)",
        "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_10_5) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.124 Safari/537.36",
        "Mozilla/5.0 (Windows NT 6.3; Win64; x64; Trident/7.0; MAARJS; rv:11.0) like Gecko",
        "Mozilla/5.0 (Linux; Android 5.0; SAMSUNG SM-N900T Build/LRX21V) AppleWebKit/537.36 (KHTML, like Gecko) SamsungBrowser/2.1 Chrome/34.0.1847.76 Mobile Safari/537.36",
        "Mozilla/5.0 (iPhone; CPU iPhone OS 8_4 like Mac OS X) AppleWebKit/600.1.4 (KHTML, like Gecko) GSA/7.0.55539 Mobile/12H143 Safari/600.1.4"
    };    
    srand(clock());
    int index = rand() % useragents.size();
    auto it = std::next(useragents.begin(), index);
    return *it;
}

size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* userp) {
    size_t totalSize = size * nmemb;
    userp->append((char*)contents, totalSize);
    return totalSize;
}

std::string random_string(int size) { 
    srand(clock());
    const char chars[] = "abcdefghijklmnopqrstuvwxyz0123456789";
    std::string result;
    int idkfuckit = rand() % size;
    for (int i = 0; i < idkfuckit; i++) { 
        int index = rand() % (sizeof(chars) - 1);
        result += chars[index];
    }
    return result;
}

std::string random_deviceId() {
    return random_string(8) + "-" + random_string(4) + "-" + random_string(4) + "-" + random_string(4) + "-" + random_string(4) + "-" + random_string(12);
}

std::string random_useragent(const std::string &filename) {
    srand(clock());
    std::ifstream file(filename);
    std::string line;
    int lineCount = 0;
    while (std::getline(file, line)) {
        ++lineCount;
    }

    int lineNumber = rand() % lineCount + 1;

    int currentLine = 1;
    
    file.clear(); 
    file.seekg(0); 
    while (std::getline(file, line)) {
        if (currentLine == lineNumber) {
            return line;
        }
        ++currentLine;
    }
    return "Mozilla/5.0 (Windows NT 6.1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/40.0.2214.115 Safari/537.36"; 
}
std::string get_random_element(const std::list<std::string>& my_list) {
    if (my_list.empty()) {
        throw std::runtime_error("[Error] List is empty! [✗]");
    }
    std::random_device rd;
    std::mt19937 gen(rd());  
    std::uniform_int_distribution<> distr(0, my_list.size() - 1);  
    int random_index = distr(gen);
    auto it = my_list.begin();
    std::advance(it, random_index);  
    return *it;  
}
void send(const std::string target, const std::string question, const std::string deviceId, const std::string useragent) {
    CURL* curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://ngl.link/api/submit");
        std::string postData = "username=" + target + "&question=" + question + "&deviceId=" + deviceId + "&gameslug=&referrer=";
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postData.c_str());

        std::map<std::string, std::string> headersMap = {
            {"Host", "ngl.link"},
            {"sec-ch-ua", "\"Google Chrome\";v=\"113\", \"Chromium\";v=\"113\", \"Not-A.Brand\";v=\"24\""},
            {"Accept", "*/*"},
            {"Content-Type", "application/x-www-form-urlencoded; charset=UTF-8"},
            {"X-Requested-With", "XMLHttpRequest"},
            {"sec-ch-ua-mobile", "?0"},
            {"User-Agent", useragent},
            {"sec-ch-ua-platform", "\"Windows\""},
            {"Origin", "https://ngl.link"},
            {"sec-fetch-site", "same-origin"},
            {"sec-fetch-mode", "cors"},
            {"sec-fetch-dest", "empty"},
            {"Referer", "https://ngl.link/" + target},
            {"Accept-Language", "tr-TR,tr;q=0.9,en-US;q=0.8,en;q=0.7"}
        };

        struct curl_slist* headers = NULL;
        for (const auto& header : headersMap) {
            std::string headerString = header.first + ": " + header.second;
            headers = curl_slist_append(headers, headerString.c_str());
        }

        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        std::string responseString;
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &responseString);

        res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            std::cerr << "[Error] " << curl_easy_strerror(res) << std::endl;
        } else {
            if (responseString.find("questionId") != std::string::npos) {
                //std::cout << "[questionId] " << responseString << std::endl; 
            } else {
                std::cerr << "[Error] Failed to send. NGL didn't return questionId! [✗]" << std::endl;
            }
        }

        curl_slist_free_all(headers);
        curl_easy_cleanup(curl);
    } else {
        std::cerr << "[Error] Couldn't initialize cURL. [✗]" << std::endl;
    }

    curl_global_cleanup();
}
void spam(std::string target, std::list<std::string> questions, const std::string useragents, const int iterations, const std::string method, bool log) {
    const std::string question = get_random_element(questions);
    if (method == "normal") { 
        for (int i = 0; i < iterations; ++i) {
                std::string deviceId = random_deviceId();
                std::string userAgent = random_useragent(useragents);
                send(target, question, deviceId, userAgent);
                if (log) {std::cout << "[Spam] " << i << "/" << iterations << " (" << (static_cast<double>(i)/iterations)*100 << "%)" << " [✔]" <<std::endl;}
        }        
    } else if (method == "thread") { 
        std::vector<std::thread> threads;
        if (log) {std::cout << "[Spam] " << "Starting threads, please wait... [✔]" << std::endl;}
        for (int i = 0; i < iterations; ++i) {
            threads.emplace_back([&, i]() {
                std::string deviceId = random_deviceId();
                std::string userAgent = random_useragent(useragents);
                send(target, question, deviceId, userAgent);
            });
        }
        if (log) {std::cout << "[Spam] " << "Started, finishing... [✔]" << std::endl;}

        int counter = 0;

        for (auto& th : threads) {
            if (th.joinable()) {
                ++counter;
                th.join();
                if (log) {std::cout << "[Spam] " << counter << "/" << iterations << " (" << (static_cast<double>(counter)/iterations)*100 << "%)" << " [✔]" <<std::endl;}
            }
        }
    }
}
