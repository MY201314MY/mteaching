import json
import requests

url = 'https://api.bilibili.com/x/relation/stat?vmid=128505057'

if __name__ == '__main__':
    res = requests.get(url).text
    print(res)
    message = json.loads(res)
    print("Total fans:{0} now.".format(message["data"]["follower"]))
