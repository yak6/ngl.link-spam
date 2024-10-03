# ngl.link-tool
ngl.link-tool allows, among other things, to spam on **[ngl.link](https://ngl.link/)** service. It's very fast and effective. 

## Installation
Clone repository

```bash
git clone https://github.com/yak6/ngl-spam
```
After cloning, cd into it's directory and install it using:

```bash
sudo make install
```
Or if you didn't like it:
```bash
sudo make uninstall
```

## Usage
### You can run it with different arguments:

**--help** - Shows help message

**--create** - Create a sample .json config file.

**--load <config>** - Run using config file

**--ask <target> <question>** - Ask user a single question

**--fuck <target>** - Send 50 messages really fast!

## Running using config
***You can create it by running `--create` argument***

### Sample config:
```json
{
    "method": "thread", 
    "question": ["hey!", "what's up!"],
    "target": ["target1", "target2"],
    "times": 50,
    "useragents": "useragents.txt"
}
```
### Getting useragents file
```bash
curl https://raw.githubusercontent.com/yak6/ngl-spam/refs/heads/main/config/useragents.txt > useragents.txt
```
### Explanation of options

**method** - *thread (fastest), normal (it's just normal).*

**question** - *array of questions, you can specify multiple or one, but it must be in an array.*

**target** - *array of targets, multiple or one, must be in the array.*

**times** - *how many messages should be sent per user.*

**useragents** - *path to user agents file.*
#### This tool uses [nlohmann's json](https://github.com/nlohmann/json) header to work with .json files!
