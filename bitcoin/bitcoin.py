import requests
import sys
def main():
    if len(sys.argv) < 2:
        sys.exit("Missing command-line argument")
    try:
        response = requests.get("https://api.coindesk.com/v1/bpi/currentprice.json")
        o = response.json()
        bitcoin_price = o["bpi"]["USD"]["rate_float"] * float(sys.argv[1])
        print(f"${bitcoin_price:,.4f}")
    except requests.RequestException:
        pass
    except ValueError:
        sys.exit("Command-line argument is not a number")









if __name__ == "__main__":
    main()