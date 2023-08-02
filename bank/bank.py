def main():
    greeting = input("Greeting: ").strip().lower().split()
    if greeting[0] == "hello" or greeting[0] == "hello," or greeting[0] == "hello!":
        print("$0")
    elif greeting[0][0] == 'h':
        print("$20")
    else:
        print("$100")








main()