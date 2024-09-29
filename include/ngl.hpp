#ifndef NGL_HPP
#define NGL_HPP

#include <iostream>
#include <string>
#include <curl/curl.h>
#include <time.h>
#include <list>


void send(std::string target, std::string question, std::string deviceId, std::string useragent);
void spam(std::string target, std::list<std::string> questions, const std::string useragents, const int iterations, const std::string method, bool log);
std::string fast_useragent();
std::string random_string(int size); 
std::string random_deviceId(); 
std::string random_useragent(const std::string &filename);

#endif // NGL_HPP
