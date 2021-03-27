import redis

if __name__ == '__main__':
    print("- - - Redis - - -")
    print("version: {0}".format(redis.__version__))
# String
    print("\n- - - String - - -")
    r = redis.Redis(host="localhost", port=6379, db=0)
    r.set(name="maria", value="This is designed by Apple in Cal.")
    print(r.get(name="maria").decode())

# HASH
    print("- - - HASH - - -")
    r.hmset(name="month", mapping={'ABC': '2', 'XYZ': '3'})
    print(r.hget(name="month", key="a").decode())
    print(r.hget(name="month", key="b").decode())
    r.hset(name="month", key="ABC", value="100")
    print(r.hgetall(name="month"))

# List
    print("\n- - - List - - -")
