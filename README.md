# ngl-spam
ngl-spam is a tool to spam on **[ngl.link](https://ngl.link/)** service. It's very fast and effective.

<h6>This program uses https://github.com/nlohmann/json header to work with .json files.</h6>

## Install 
Clone repository

```bash
git clone https://github.com/yak6/ngl-spam
```
Go to cloned repository directory

```bash
cd ngl-spam
```
Now, you can compile using:
```bash
make
```
Or install using:
```bash
sudo make install
```
Uninstall:
```bash
sudo make uninstall
```
### Get useragents file
```bash
curl https://raw.githubusercontent.com/yak6/ngl-spam/refs/heads/main/config/useragents.txt > useragents.txt
```

## Usage
### Available Arguments
```bash
--help                    Show this help message.
--create                  Create a sample .json config file.
--load <config>           Run spammer using config file.
--ask <target> <question> Ask user a single question.
--fuck <target>           Send 50 messages fast.
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

