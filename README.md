# ngl-spam
ngl-spam is a tool to spam on **[ngl.link](https://ngl.link/)** service. It's very fast and effective!

This program uses *[nlohmann's json](https://github.com/nlohmann/json)* header to work with .json files.
## Usage
### Available Arguments
```bash
--ask <target> <question> Ask user a single question.
--load <config>           Run spammer using config file. 
--fuck <target>           Send 50 messages with random characters.
--create                  Create a sample .json config file.
--help                    Shows help message.
```

### Running with config

```json
{
    "method": "thread", 
    "question": ["hey!", "what's up!"],
    "target": ["target1", "target2"],
    "times": 50,
    "useragents": "useragents.txt"
}
```
***You can create it by running with `--create` argument!!!***

**method** - *thread (fastest), normal (it's just normal).*

**question** - *array of questions, you can specify multiple or one, but it must be in an array.*

**target** - *array of targets, multiple or one, must be in the array.*

**times** - *how many messages should be sent per user.*

**useragents** - *path to user agents file.*

## Compiling
Install cURL and curl-devel (for curl.h):

#### Debian:
```bash
sudo apt install curl libcurl4-openssl-dev
```
#### Fedora/Redhat:
```bash
sudo dnf install curl libcurl-devel
```
#### Arch:
```bash
sudo pacman -S curl
```
#### Make sure it's installed:
```bash
ls /usr/include/curl/curl.h
```
#### Compile
```bash
g++ main.cpp ngl.cpp -lcurl -o ngl
```
